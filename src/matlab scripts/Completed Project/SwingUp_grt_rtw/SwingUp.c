/*
 * SwingUp.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SwingUp".
 *
 * Model version              : 1.44
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed May 24 12:35:52 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SwingUp.h"
#include "rtwtypes.h"
#include <string.h>
#include <emmintrin.h>
#include <math.h>
#include "SwingUp_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_SwingUp_T SwingUp_B;

/* Continuous states */
X_SwingUp_T SwingUp_X;

/* Block states (default storage) */
DW_SwingUp_T SwingUp_DW;

/* Real-time model */
static RT_MODEL_SwingUp_T SwingUp_M_;
RT_MODEL_SwingUp_T *const SwingUp_M = &SwingUp_M_;

/* Forward declaration for local functions */
static real_T SwingUp_xnrm2(int32_T n, const real_T x[5], int32_T ix0);
static void SwingUp_trisolve(real_T A, real_T B[4]);
static real_T SwingUp_xnrm2_a(int32_T n, const real_T x[20], int32_T ix0);
static void SwingUp_xgemv(int32_T m, int32_T n, const real_T A[20], int32_T ia0,
  const real_T x[20], int32_T ix0, real_T y[4]);
static void SwingUp_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[4], real_T A[20], int32_T ia0);
static void EKFCorrector_correctStateAndSqr(real_T x[4], real_T S[16], real_T
  residue, const real_T Pxy[4], real_T Sy, const real_T H[4], real_T Rsqrt);
static void SwingUp_StateFcn(real_T x[4], real_T V_m);
static real_T SwingUp_xnrm2_d(int32_T n, const real_T x[32], int32_T ix0);
static void SwingUp_xgemv_m(int32_T m, int32_T n, const real_T A[32], int32_T
  ia0, const real_T x[32], int32_T ix0, real_T y[4]);
static void SwingUp_xgerc_n(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[4], real_T A[32], int32_T ia0);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SwingUp_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SwingUp_step();
  SwingUp_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SwingUp_step();
  SwingUp_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S8>/Correct' */
static real_T SwingUp_xnrm2(int32_T n, const real_T x[5], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S8>/Correct' */
static void SwingUp_trisolve(real_T A, real_T B[4])
{
  if (B[0] != 0.0) {
    B[0] /= A;
  }

  if (B[1] != 0.0) {
    B[1] /= A;
  }

  if (B[2] != 0.0) {
    B[2] /= A;
  }

  if (B[3] != 0.0) {
    B[3] /= A;
  }
}

/* Function for MATLAB Function: '<S8>/Correct' */
static real_T SwingUp_xnrm2_a(int32_T n, const real_T x[20], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S8>/Correct' */
static void SwingUp_xgemv(int32_T m, int32_T n, const real_T A[20], int32_T ia0,
  const real_T x[20], int32_T ix0, real_T y[4])
{
  int32_T b_iy;
  int32_T iyend;
  if ((m != 0) && (n != 0)) {
    int32_T b;
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    }

    b = (n - 1) * 5 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 5) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (iyend = b_iy; iyend < d; iyend++) {
        c += x[((ix0 + iyend) - b_iy) - 1] * A[iyend - 1];
      }

      iyend = div_nde_s32_floor(b_iy - ia0, 5);
      y[iyend] += c;
    }
  }
}

/* Function for MATLAB Function: '<S8>/Correct' */
static void SwingUp_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[4], real_T A[20], int32_T ia0)
{
  int32_T ijA;
  int32_T j;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 5;
    }
  }
}

/* Function for MATLAB Function: '<S8>/Correct' */
static void EKFCorrector_correctStateAndSqr(real_T x[4], real_T S[16], real_T
  residue, const real_T Pxy[4], real_T Sy, const real_T H[4], real_T Rsqrt)
{
  real_T b_A[20];
  real_T A[16];
  real_T y[16];
  real_T C[4];
  real_T K[4];
  real_T K_0;
  real_T K_idx_0;
  real_T K_idx_2;
  real_T s;
  int32_T aoffset;
  int32_T coffset;
  int32_T ii;
  int32_T j;
  int32_T lastv;
  C[0] = Pxy[0];
  C[1] = Pxy[1];
  C[2] = Pxy[2];
  C[3] = Pxy[3];
  SwingUp_trisolve(Sy, C);
  K[0] = C[0];
  K[1] = C[1];
  K[2] = C[2];
  K[3] = C[3];
  SwingUp_trisolve(Sy, K);
  x[0] += K[0] * residue;
  K_idx_0 = -K[0];
  x[1] += K[1] * residue;
  s = -K[1];
  x[2] += K[2] * residue;
  K_idx_2 = -K[2];
  K_0 = K[3];
  x[3] += K[3] * residue;
  for (j = 0; j < 4; j++) {
    real_T H_0;
    H_0 = H[j];
    coffset = j << 2;
    A[coffset] = K_idx_0 * H_0;
    A[coffset + 1] = s * H_0;
    A[coffset + 2] = K_idx_2 * H_0;
    A[coffset + 3] = -K_0 * H_0;
  }

  A[0]++;
  A[5]++;
  A[10]++;
  A[15]++;
  for (j = 0; j < 4; j++) {
    coffset = j << 2;
    for (ii = 0; ii < 4; ii++) {
      aoffset = ii << 2;
      y[coffset + ii] = ((S[aoffset + 1] * A[j + 4] + S[aoffset] * A[j]) +
                         S[aoffset + 2] * A[j + 8]) + S[aoffset + 3] * A[j + 12];
    }
  }

  for (j = 0; j < 4; j++) {
    coffset = j << 2;
    b_A[5 * j] = y[coffset];
    b_A[5 * j + 1] = y[coffset + 1];
    b_A[5 * j + 2] = y[coffset + 2];
    b_A[5 * j + 3] = y[coffset + 3];
    b_A[5 * j + 4] = K[j] * Rsqrt;
    K[j] = 0.0;
  }

  for (j = 0; j < 4; j++) {
    int32_T c;
    ii = j * 5 + j;
    K_idx_0 = b_A[ii];
    lastv = ii + 2;
    C[j] = 0.0;
    s = SwingUp_xnrm2_a(4 - j, b_A, ii + 2);
    if (s != 0.0) {
      s = rt_hypotd_snf(b_A[ii], s);
      if (b_A[ii] >= 0.0) {
        s = -s;
      }

      if (fabs(s) < 1.0020841800044864E-292) {
        __m128d tmp;
        int32_T scalarLB;
        int32_T vectorUB;
        coffset = 0;
        do {
          coffset++;
          c = (ii - j) + 5;
          scalarLB = (((((c - ii) - 1) / 2) << 1) + ii) + 2;
          vectorUB = scalarLB - 2;
          for (aoffset = lastv; aoffset <= vectorUB; aoffset += 2) {
            tmp = _mm_loadu_pd(&b_A[aoffset - 1]);
            _mm_storeu_pd(&b_A[aoffset - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (aoffset = scalarLB; aoffset <= c; aoffset++) {
            b_A[aoffset - 1] *= 9.9792015476736E+291;
          }

          s *= 9.9792015476736E+291;
          K_idx_0 *= 9.9792015476736E+291;
        } while ((fabs(s) < 1.0020841800044864E-292) && (coffset < 20));

        s = rt_hypotd_snf(K_idx_0, SwingUp_xnrm2_a(4 - j, b_A, ii + 2));
        if (K_idx_0 >= 0.0) {
          s = -s;
        }

        C[j] = (s - K_idx_0) / s;
        K_idx_0 = 1.0 / (K_idx_0 - s);
        c = (ii - j) + 5;
        scalarLB = (((((c - ii) - 1) / 2) << 1) + ii) + 2;
        vectorUB = scalarLB - 2;
        for (aoffset = lastv; aoffset <= vectorUB; aoffset += 2) {
          tmp = _mm_loadu_pd(&b_A[aoffset - 1]);
          _mm_storeu_pd(&b_A[aoffset - 1], _mm_mul_pd(tmp, _mm_set1_pd(K_idx_0)));
        }

        for (aoffset = scalarLB; aoffset <= c; aoffset++) {
          b_A[aoffset - 1] *= K_idx_0;
        }

        for (lastv = 0; lastv < coffset; lastv++) {
          s *= 1.0020841800044864E-292;
        }

        K_idx_0 = s;
      } else {
        int32_T scalarLB;
        int32_T vectorUB;
        C[j] = (s - b_A[ii]) / s;
        K_idx_0 = 1.0 / (b_A[ii] - s);
        aoffset = (ii - j) + 5;
        scalarLB = (((((aoffset - ii) - 1) / 2) << 1) + ii) + 2;
        vectorUB = scalarLB - 2;
        for (coffset = lastv; coffset <= vectorUB; coffset += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&b_A[coffset - 1]);
          _mm_storeu_pd(&b_A[coffset - 1], _mm_mul_pd(tmp, _mm_set1_pd(K_idx_0)));
        }

        for (coffset = scalarLB; coffset <= aoffset; coffset++) {
          b_A[coffset - 1] *= K_idx_0;
        }

        K_idx_0 = s;
      }
    }

    b_A[ii] = K_idx_0;
    if (j + 1 < 4) {
      s = b_A[ii];
      b_A[ii] = 1.0;
      if (C[j] != 0.0) {
        boolean_T exitg2;
        lastv = 5 - j;
        coffset = (ii - j) + 4;
        while ((lastv > 0) && (b_A[coffset] == 0.0)) {
          lastv--;
          coffset--;
        }

        coffset = 3 - j;
        exitg2 = false;
        while ((!exitg2) && (coffset > 0)) {
          int32_T exitg1;
          aoffset = ((coffset - 1) * 5 + ii) + 5;
          c = aoffset;
          do {
            exitg1 = 0;
            if (c + 1 <= aoffset + lastv) {
              if (b_A[c] != 0.0) {
                exitg1 = 1;
              } else {
                c++;
              }
            } else {
              coffset--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        coffset = 0;
      }

      if (lastv > 0) {
        SwingUp_xgemv(lastv, coffset, b_A, ii + 6, b_A, ii + 1, K);
        SwingUp_xgerc(lastv, coffset, -C[j], ii + 1, K, b_A, ii + 6);
      }

      b_A[ii] = s;
    }
  }

  for (j = 0; j < 4; j++) {
    for (ii = 0; ii <= j; ii++) {
      A[ii + (j << 2)] = b_A[5 * j + ii];
    }

    for (ii = j + 2; ii < 5; ii++) {
      A[(ii + (j << 2)) - 1] = 0.0;
    }
  }

  for (j = 0; j < 4; j++) {
    coffset = j << 2;
    S[coffset] = A[j];
    S[coffset + 1] = A[j + 4];
    S[coffset + 2] = A[j + 8];
    S[coffset + 3] = A[j + 12];
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S11>/Predict' */
static void SwingUp_StateFcn(real_T x[4], real_T V_m)
{
  real_T b_idx_1;
  real_T b_idx_2;
  real_T b_idx_2_tmp;
  real_T b_idx_3_tmp;
  real_T t10;
  real_T t11;
  real_T t13;
  real_T t14;
  real_T t2;
  real_T t21;
  real_T t27;
  real_T t3;
  real_T tau;
  tau = (V_m - 0.59210527395522783 * x[2]) * 0.3423289007525453 /
    2.3833700802778;
  t2 = cos(x[1]);
  t3 = sin(x[1]);
  t10 = x[2] * x[2];
  t11 = x[3] * x[3];
  t13 = t2 * t2;
  t14 = sin(x[1] * 2.0);
  t21 = t13 * 1.1781085197420069E-8;
  t27 = 1.0 / (((5.2669468615398539E-6 - t13 * 8.1415278832007172E-8) - t21) -
               t13 * 6.43137556988153E-7);
  b_idx_1 = x[3];
  b_idx_2_tmp = 0.216 * t2 * 2.4985232267774044E-5 * 0.016129;
  b_idx_2 = ((((((((((0.000750089811121891 * tau * -2.0 + 1.5785596422128089E-6 *
                      x[2] * 2.0) - 0.00010854070755905394 * tau * 2.0) + t14 *
                    8.1415278832007172E-8 * x[2] * x[3] * 2.0) + t14 *
                   1.1781085197420069E-8 * x[2] * x[3] * 2.0) +
                  2.2842328738431903E-7 * x[2] * 2.0) + 0.216 * t3 *
                 2.4985232267774044E-5 * 0.016129 * t11 * 2.0) - 2.11896 * t2 *
                t3 * 0.00085465124062247193 * 0.016129 * 2.0) - b_idx_2_tmp *
               t10 * t14) + 3.1485126190683703E-7 * t2 * x[3] * 2.0) +
             6.0154095650395485E-7 * t3 * t11 * 2.0) * t27 * -0.5;
  t10 *= t14;
  b_idx_3_tmp = 9.81 * t3 * 2.4985232267774044E-5 * 0.016129;
  tau = (((((((((((((((3.9367161244903178E-8 * x[3] * 2.0 - t10 *
                       1.0883616864925307E-8) - t10 * 1.1781085197420069E-8) -
                     t10 * 6.43137556988153E-7) + t10 * t21) - b_idx_3_tmp * 2.0)
                  + t2 * t3 * t11 * 6.43137556988153E-7 * 2.0) +
                 4.2613396480487069E-8 * x[3] * 2.0) + 2.3262946704968818E-6 *
                x[3] * 2.0) - 3.6521431227085935E-6 * t3 * 2.0) -
              4.2613396480487069E-8 * t13 * x[3] * 2.0) - 0.286789648100604 * t3
             * 0.016129 * 0.046655999999999996 * 2.0) - 0.0008019585756060926 *
            t2 * tau * 2.0) + b_idx_3_tmp * t13 * 2.0) + 1.6877171552094713E-6 *
          t2 * x[2] * 2.0) + b_idx_2_tmp * t14 * x[2] * x[3] * 2.0) * t27 * -0.5;
  x[0] += 0.002 * x[2];
  x[1] += 0.002 * b_idx_1;
  x[2] += 0.002 * b_idx_2;
  x[3] += 0.002 * tau;
}

/* Function for MATLAB Function: '<S11>/Predict' */
static real_T SwingUp_xnrm2_d(int32_T n, const real_T x[32], int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S11>/Predict' */
static void SwingUp_xgemv_m(int32_T m, int32_T n, const real_T A[32], int32_T
  ia0, const real_T x[32], int32_T ix0, real_T y[4])
{
  int32_T b_iy;
  int32_T iyend;
  if ((m != 0) && (n != 0)) {
    int32_T b;
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    }

    b = ((n - 1) << 3) + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 8) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (iyend = b_iy; iyend < d; iyend++) {
        c += x[((ix0 + iyend) - b_iy) - 1] * A[iyend - 1];
      }

      iyend = (b_iy - ia0) >> 3;
      y[iyend] += c;
    }
  }
}

/* Function for MATLAB Function: '<S11>/Predict' */
static void SwingUp_xgerc_n(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[4], real_T A[32], int32_T ia0)
{
  int32_T ijA;
  int32_T j;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 8;
    }
  }
}

/* Model step function */
void SwingUp_step(void)
{
  __m128d tmp_2;
  real_T A_0[32];
  real_T P_temp[16];
  real_T c_0[16];
  real_T tmp_0[16];
  real_T tmp_1[16];
  real_T A_tmp_0[8];
  real_T B[8];
  real_T K[8];
  real_T A[5];
  real_T rtb_DataStoreRead[4];
  real_T rtb_xNew_k[4];
  real_T tmp[4];
  real_T x[4];
  real_T epsilon;
  real_T rtb_DelayOneStep;
  real_T rtb_Sum_f;
  real_T t10;
  real_T t11;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t18;
  real_T t20;
  real_T t21;
  real_T t27;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t8;
  real_T t9;
  real_T tau;
  real_T tau_tmp;
  int32_T aoffset;
  int32_T c_tmp;
  int32_T coffset;
  int32_T j;
  int32_T lastc;
  int32_T r1;
  int8_T A_tmp[8];
  static const int8_T b[8] = { 1, 0, 0, 0, 0, 1, 0, 0 };

  static const int8_T a[8] = { 1, 0, 0, 1, 0, 0, 0, 0 };

  static const int8_T c_1[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  if (rtmIsMajorTimeStep(SwingUp_M)) {
    /* set solver stop time */
    if (!(SwingUp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SwingUp_M->solverInfo,
                            ((SwingUp_M->Timing.clockTickH0 + 1) *
        SwingUp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SwingUp_M->solverInfo,
                            ((SwingUp_M->Timing.clockTick0 + 1) *
        SwingUp_M->Timing.stepSize0 + SwingUp_M->Timing.clockTickH0 *
        SwingUp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SwingUp_M)) {
    SwingUp_M->Timing.t[0] = rtsiGetT(&SwingUp_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(SwingUp_M)) {
    real_T t23;
    real_T t24;
    real_T t25;
    real_T t26;
    real_T t27_tmp;
    real_T t30;
    real_T t37;
    real_T t4_tmp;
    real_T tau_tmp_0;
    real_T tmp_4;
    real_T tmp_5;
    real_T tmp_6;
    real_T tmp_7;
    real_T tmp_8;
    real_T tmp_9;
    real_T tmp_a;
    real_T tmp_b;
    real_T tmp_c;
    real_T tmp_d;
    real_T tmp_e;
    real_T tmp_f;
    real_T tmp_g;
    real_T tmp_h;
    real_T tmp_i;
    real_T tmp_j;
    real_T tmp_k;
    real_T tmp_l;
    real_T tmp_m;
    real_T tmp_n;
    real_T tmp_o;
    real_T tmp_p;
    real_T tmp_q;
    real_T tmp_r;
    real_T tmp_s;
    real_T tmp_t;
    real_T tmp_u;
    real_T tmp_v;
    real_T x_tmp;
    real_T x_tmp_0;
    real_T x_tmp_1;
    real_T x_tmp_2;
    real_T x_tmp_3;
    real_T x_tmp_4;
    real_T x_tmp_5;
    real_T x_tmp_6;
    real_T x_tmp_7;
    real_T x_tmp_8;
    real_T x_tmp_9;
    real_T x_tmp_a;
    real_T x_tmp_tmp;

    /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    SwingUp_B.DiscreteTimeIntegrator[0] =
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[0];
    SwingUp_B.DiscreteTimeIntegrator[1] =
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[1];
    SwingUp_B.DiscreteTimeIntegrator[2] =
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[2];
    SwingUp_B.DiscreteTimeIntegrator[3] =
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[3];

    /* Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    /* Constant: '<S2>/Enable1' */
    if (SwingUp_P.Enable1_Value) {
      /* MATLAB Function: '<S8>/Correct' incorporates:
       *  Constant: '<S2>/R1'
       *  DataStoreRead: '<S8>/Data Store ReadP'
       *  DataStoreRead: '<S8>/Data Store ReadX'
       */
      for (j = 0; j < 4; j++) {
        rtb_xNew_k[0] = SwingUp_DW.x[0];
        epsilon = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                       (SwingUp_DW.x[j]));
        rtb_xNew_k[j] = SwingUp_DW.x[j] + epsilon;
        rtb_DataStoreRead[j] = (rtb_xNew_k[0] - SwingUp_DW.x[0]) / epsilon;
      }

      for (r1 = 0; r1 < 4; r1++) {
        aoffset = r1 << 2;
        rtb_xNew_k[r1] = ((SwingUp_DW.P[aoffset + 1] * rtb_DataStoreRead[1] +
                           SwingUp_DW.P[aoffset] * rtb_DataStoreRead[0]) +
                          SwingUp_DW.P[aoffset + 2] * rtb_DataStoreRead[2]) +
          SwingUp_DW.P[aoffset + 3] * rtb_DataStoreRead[3];
      }

      A[0] = rtb_xNew_k[0];
      A[1] = rtb_xNew_k[1];
      A[2] = rtb_xNew_k[2];
      A[3] = rtb_xNew_k[3];
      A[4] = SwingUp_P.R1_Value;
      t3 = rtb_xNew_k[0];
      epsilon = SwingUp_xnrm2(4, A, 2);
      if (epsilon != 0.0) {
        epsilon = rt_hypotd_snf(rtb_xNew_k[0], epsilon);
        if (rtb_xNew_k[0] >= 0.0) {
          epsilon = -epsilon;
        }

        if (fabs(epsilon) < 1.0020841800044864E-292) {
          aoffset = 0;
          do {
            aoffset++;
            A[1] *= 9.9792015476736E+291;
            A[2] *= 9.9792015476736E+291;
            A[3] *= 9.9792015476736E+291;
            A[4] *= 9.9792015476736E+291;
            epsilon *= 9.9792015476736E+291;
            t3 *= 9.9792015476736E+291;
          } while ((fabs(epsilon) < 1.0020841800044864E-292) && (aoffset < 20));

          epsilon = rt_hypotd_snf(t3, SwingUp_xnrm2(4, A, 2));
          if (t3 >= 0.0) {
            epsilon = -epsilon;
          }

          for (lastc = 0; lastc < aoffset; lastc++) {
            epsilon *= 1.0020841800044864E-292;
          }

          t3 = epsilon;
        } else {
          t3 = epsilon;
        }
      }

      rtb_xNew_k[0] = SwingUp_DW.x[0];
      rtb_xNew_k[1] = SwingUp_DW.x[1];
      rtb_xNew_k[2] = SwingUp_DW.x[2];
      rtb_xNew_k[3] = SwingUp_DW.x[3];
      memcpy(&P_temp[0], &SwingUp_DW.P[0], sizeof(real_T) << 4U);
      for (lastc = 0; lastc < 4; lastc++) {
        tmp[lastc] = 0.0;
        for (j = 0; j < 4; j++) {
          r1 = (j << 2) + lastc;
          c_0[r1] = 0.0;
          c_0[r1] += SwingUp_DW.P[lastc] * SwingUp_DW.P[j];
          c_0[r1] += SwingUp_DW.P[lastc + 4] * SwingUp_DW.P[j + 4];
          c_0[r1] += SwingUp_DW.P[lastc + 8] * SwingUp_DW.P[j + 8];
          c_0[r1] += SwingUp_DW.P[lastc + 12] * SwingUp_DW.P[j + 12];
          tmp[lastc] += c_0[r1] * rtb_DataStoreRead[j];
        }
      }

      EKFCorrector_correctStateAndSqr(rtb_xNew_k, P_temp,
        SwingUp_B.DiscreteTimeIntegrator[0] - SwingUp_DW.x[0], tmp, t3,
        rtb_DataStoreRead, SwingUp_P.R1_Value);

      /* DataStoreWrite: '<S8>/Data Store WriteP' incorporates:
       *  MATLAB Function: '<S8>/Correct'
       */
      memcpy(&SwingUp_DW.P[0], &P_temp[0], sizeof(real_T) << 4U);

      /* DataStoreWrite: '<S8>/Data Store WriteX' */
      SwingUp_DW.x[0] = rtb_xNew_k[0];
      SwingUp_DW.x[1] = rtb_xNew_k[1];
      SwingUp_DW.x[2] = rtb_xNew_k[2];
      SwingUp_DW.x[3] = rtb_xNew_k[3];
    }

    /* End of Constant: '<S2>/Enable1' */
    /* End of Outputs for SubSystem: '<S2>/Correct1' */

    /* Outputs for Enabled SubSystem: '<S2>/Correct2' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    /* Constant: '<S2>/Enable2' */
    if (SwingUp_P.Enable2_Value) {
      /* MATLAB Function: '<S9>/Correct' incorporates:
       *  Constant: '<S2>/R2'
       *  DataStoreRead: '<S9>/Data Store ReadP'
       *  DataStoreRead: '<S9>/Data Store ReadX'
       */
      for (j = 0; j < 4; j++) {
        rtb_xNew_k[1] = SwingUp_DW.x[1];
        epsilon = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                       (SwingUp_DW.x[j]));
        rtb_xNew_k[j] = SwingUp_DW.x[j] + epsilon;
        rtb_DataStoreRead[j] = (rtb_xNew_k[1] - SwingUp_DW.x[1]) / epsilon;
      }

      for (r1 = 0; r1 < 4; r1++) {
        aoffset = r1 << 2;
        rtb_xNew_k[r1] = ((SwingUp_DW.P[aoffset + 1] * rtb_DataStoreRead[1] +
                           SwingUp_DW.P[aoffset] * rtb_DataStoreRead[0]) +
                          SwingUp_DW.P[aoffset + 2] * rtb_DataStoreRead[2]) +
          SwingUp_DW.P[aoffset + 3] * rtb_DataStoreRead[3];
      }

      A[0] = rtb_xNew_k[0];
      A[1] = rtb_xNew_k[1];
      A[2] = rtb_xNew_k[2];
      A[3] = rtb_xNew_k[3];
      A[4] = SwingUp_P.R2_Value;
      t3 = rtb_xNew_k[0];
      epsilon = SwingUp_xnrm2(4, A, 2);
      if (epsilon != 0.0) {
        epsilon = rt_hypotd_snf(rtb_xNew_k[0], epsilon);
        if (rtb_xNew_k[0] >= 0.0) {
          epsilon = -epsilon;
        }

        if (fabs(epsilon) < 1.0020841800044864E-292) {
          aoffset = 0;
          do {
            aoffset++;
            A[1] *= 9.9792015476736E+291;
            A[2] *= 9.9792015476736E+291;
            A[3] *= 9.9792015476736E+291;
            A[4] *= 9.9792015476736E+291;
            epsilon *= 9.9792015476736E+291;
            t3 *= 9.9792015476736E+291;
          } while ((fabs(epsilon) < 1.0020841800044864E-292) && (aoffset < 20));

          epsilon = rt_hypotd_snf(t3, SwingUp_xnrm2(4, A, 2));
          if (t3 >= 0.0) {
            epsilon = -epsilon;
          }

          for (lastc = 0; lastc < aoffset; lastc++) {
            epsilon *= 1.0020841800044864E-292;
          }

          t3 = epsilon;
        } else {
          t3 = epsilon;
        }
      }

      rtb_xNew_k[0] = SwingUp_DW.x[0];
      rtb_xNew_k[1] = SwingUp_DW.x[1];
      rtb_xNew_k[2] = SwingUp_DW.x[2];
      rtb_xNew_k[3] = SwingUp_DW.x[3];
      memcpy(&P_temp[0], &SwingUp_DW.P[0], sizeof(real_T) << 4U);
      for (lastc = 0; lastc < 4; lastc++) {
        tmp[lastc] = 0.0;
        for (j = 0; j < 4; j++) {
          r1 = (j << 2) + lastc;
          c_0[r1] = 0.0;
          c_0[r1] += SwingUp_DW.P[lastc] * SwingUp_DW.P[j];
          c_0[r1] += SwingUp_DW.P[lastc + 4] * SwingUp_DW.P[j + 4];
          c_0[r1] += SwingUp_DW.P[lastc + 8] * SwingUp_DW.P[j + 8];
          c_0[r1] += SwingUp_DW.P[lastc + 12] * SwingUp_DW.P[j + 12];
          tmp[lastc] += c_0[r1] * rtb_DataStoreRead[j];
        }
      }

      EKFCorrector_correctStateAndSqr(rtb_xNew_k, P_temp,
        SwingUp_B.DiscreteTimeIntegrator[1] - SwingUp_DW.x[1], tmp, t3,
        rtb_DataStoreRead, SwingUp_P.R2_Value);

      /* DataStoreWrite: '<S9>/Data Store WriteP' incorporates:
       *  MATLAB Function: '<S9>/Correct'
       */
      memcpy(&SwingUp_DW.P[0], &P_temp[0], sizeof(real_T) << 4U);

      /* DataStoreWrite: '<S9>/Data Store WriteX' */
      SwingUp_DW.x[0] = rtb_xNew_k[0];
      SwingUp_DW.x[1] = rtb_xNew_k[1];
      SwingUp_DW.x[2] = rtb_xNew_k[2];
      SwingUp_DW.x[3] = rtb_xNew_k[3];
    }

    /* End of Constant: '<S2>/Enable2' */
    /* End of Outputs for SubSystem: '<S2>/Correct2' */

    /* Delay: '<S1>/Delay One Step' */
    rtb_DelayOneStep = SwingUp_DW.DelayOneStep_DSTATE;

    /* MATLAB Function: '<S1>/EKF' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Delay: '<S1>/Delay One Step2'
     */
    tau_tmp = SwingUp_P.id_param[8] * SwingUp_P.id_param[10] *
      SwingUp_P.id_param[11] * SwingUp_P.id_param[13];
    tau_tmp_0 = SwingUp_P.id_param[8] * SwingUp_P.id_param[12];
    tau = (rtb_DelayOneStep - tau_tmp_0 * SwingUp_DW.DelayOneStep2_DSTATE[2]) *
      tau_tmp / SwingUp_P.id_param[9];
    epsilon = cos(SwingUp_DW.DelayOneStep2_DSTATE[1]);
    t3 = sin(SwingUp_DW.DelayOneStep2_DSTATE[1]);
    t4_tmp = SwingUp_P.id_param[4] * SwingUp_P.id_param[4];
    rtb_Sum_f = rt_powd_snf(SwingUp_P.id_param[4], 3.0);
    t7 = SwingUp_P.id_param[5] * SwingUp_P.id_param[5];
    t9 = SwingUp_P.id_param[6] * SwingUp_P.id_param[6];
    t8 = t9;
    t10 = SwingUp_DW.DelayOneStep2_DSTATE[2] * SwingUp_DW.DelayOneStep2_DSTATE[2];
    t11 = SwingUp_DW.DelayOneStep2_DSTATE[3] * SwingUp_DW.DelayOneStep2_DSTATE[3];
    t13 = epsilon * epsilon;
    t14 = sin(SwingUp_DW.DelayOneStep2_DSTATE[1] * 2.0);
    t15 = SwingUp_P.id_param[2] * SwingUp_P.id_param[5] * t4_tmp;
    t4 = SwingUp_P.id_param[3] * SwingUp_P.id_param[5];
    t16 = t4 * t4_tmp;
    t20 = t4_tmp * t7 * t8;
    t30 = t4_tmp * t4_tmp;
    t18 = t30 * t7;
    t21 = t13 * t18;
    t27_tmp = SwingUp_P.id_param[2] * SwingUp_P.id_param[3];
    t27 = 1.0 / ((((((((t27_tmp + t15) + t16) + t4 * t8) + t18) + t20) - t13 *
                   t16) - t21) - t13 * t20);
    x_tmp_2 = SwingUp_P.id_param[1] * SwingUp_P.id_param[3];
    x_tmp_3 = SwingUp_P.id_param[6] * SwingUp_P.id_param[7];
    x_tmp_4 = SwingUp_P.id_param[0] * SwingUp_P.id_param[4] *
      SwingUp_P.id_param[5] * SwingUp_P.id_param[6];
    x_tmp_tmp = SwingUp_P.id_param[3] * SwingUp_P.id_param[4];
    x_tmp_5 = x_tmp_tmp * SwingUp_P.id_param[5] * SwingUp_P.id_param[6];
    x_tmp_a = SwingUp_P.id_param[5] * t4_tmp;
    x[2] = ((((((((((x_tmp_2 * SwingUp_DW.DelayOneStep2_DSTATE[2] * 2.0 +
                     SwingUp_P.id_param[3] * tau * -2.0) - x_tmp_a * tau * 2.0)
                   + t14 * t16 * SwingUp_DW.DelayOneStep2_DSTATE[2] *
                   SwingUp_DW.DelayOneStep2_DSTATE[3] * 2.0) + t14 * t18 *
                  SwingUp_DW.DelayOneStep2_DSTATE[2] *
                  SwingUp_DW.DelayOneStep2_DSTATE[3] * 2.0) +
                 SwingUp_P.id_param[1] * SwingUp_P.id_param[5] * t4_tmp *
                 SwingUp_DW.DelayOneStep2_DSTATE[2] * 2.0) + SwingUp_P.id_param
                [6] * t3 * rtb_Sum_f * t7 * t11 * 2.0) - x_tmp_3 * epsilon * t3 *
               t4_tmp * t7 * 2.0) - SwingUp_P.id_param[6] * epsilon * rtb_Sum_f *
              t7 * t10 * t14) + x_tmp_4 * epsilon *
             SwingUp_DW.DelayOneStep2_DSTATE[3] * 2.0) + x_tmp_5 * t3 * t11 *
            2.0) * t27 * -0.5;
    x_tmp = t10 * t14;
    t5 = SwingUp_P.id_param[0] * SwingUp_P.id_param[5];
    x_tmp_0 = t5 * t4_tmp;
    x_tmp_1 = SwingUp_P.id_param[7] * t3 * rtb_Sum_f * t7;
    x_tmp_6 = SwingUp_P.id_param[4] * SwingUp_P.id_param[7];
    x_tmp_7 = SwingUp_P.id_param[0] * SwingUp_P.id_param[2];
    x_tmp_8 = SwingUp_P.id_param[2] * SwingUp_P.id_param[7] *
      SwingUp_P.id_param[4] * SwingUp_P.id_param[5];
    x_tmp_9 = SwingUp_P.id_param[1] * SwingUp_P.id_param[4] *
      SwingUp_P.id_param[5] * SwingUp_P.id_param[6];
    x[3] = (((((((((((((((x_tmp_7 * SwingUp_DW.DelayOneStep2_DSTATE[3] * 2.0 -
                          x_tmp * t15) - x_tmp * t18) - x_tmp * t20) + x_tmp *
                       t21) - x_tmp_1 * 2.0) + epsilon * t3 * t11 * t20 * 2.0) +
                    x_tmp_0 * SwingUp_DW.DelayOneStep2_DSTATE[3] * 2.0) + t5 *
                   t8 * SwingUp_DW.DelayOneStep2_DSTATE[3] * 2.0) - x_tmp_8 * t3
                  * 2.0) - x_tmp_0 * t13 * SwingUp_DW.DelayOneStep2_DSTATE[3] *
                 2.0) - x_tmp_6 * t3 * t7 * t8 * 2.0) - SwingUp_P.id_param[4] *
               SwingUp_P.id_param[5] * SwingUp_P.id_param[6] * epsilon * tau *
               2.0) + x_tmp_1 * t13 * 2.0) + x_tmp_9 * epsilon *
             SwingUp_DW.DelayOneStep2_DSTATE[2] * 2.0) + SwingUp_P.id_param[6] *
            epsilon * rtb_Sum_f * t7 * t14 * SwingUp_DW.DelayOneStep2_DSTATE[2] *
            SwingUp_DW.DelayOneStep2_DSTATE[3] * 2.0) * t27 * -0.5;

    /* Outputs for Atomic SubSystem: '<S2>/Output' */
    /* DataStoreRead: '<S10>/Data Store Read' */
    rtb_DataStoreRead[0] = SwingUp_DW.x[0];

    /* End of Outputs for SubSystem: '<S2>/Output' */

    /* MATLAB Function: '<S1>/EKF' incorporates:
     *  Constant: '<S1>/Constant3'
     *  Delay: '<S1>/Delay One Step2'
     */
    x_tmp = SwingUp_P.Ts * SwingUp_DW.DelayOneStep2_DSTATE[2] +
      SwingUp_DW.DelayOneStep2_DSTATE[0];
    x[0] = x_tmp;

    /* Outputs for Atomic SubSystem: '<S2>/Output' */
    /* DataStoreRead: '<S10>/Data Store Read' */
    rtb_DataStoreRead[1] = SwingUp_DW.x[1];

    /* End of Outputs for SubSystem: '<S2>/Output' */

    /* MATLAB Function: '<S1>/EKF' incorporates:
     *  Constant: '<S1>/Constant3'
     *  Delay: '<S1>/Delay One Step2'
     */
    t5 = SwingUp_P.Ts * SwingUp_DW.DelayOneStep2_DSTATE[3] +
      SwingUp_DW.DelayOneStep2_DSTATE[1];
    x[1] = t5;

    /* Outputs for Atomic SubSystem: '<S2>/Output' */
    /* DataStoreRead: '<S10>/Data Store Read' */
    rtb_DataStoreRead[2] = SwingUp_DW.x[2];

    /* End of Outputs for SubSystem: '<S2>/Output' */

    /* MATLAB Function: '<S1>/EKF' incorporates:
     *  Constant: '<S1>/Constant3'
     *  Delay: '<S1>/Delay One Step2'
     */
    x_tmp_0 = SwingUp_P.Ts * x[2] + SwingUp_DW.DelayOneStep2_DSTATE[2];
    x[2] = x_tmp_0;

    /* Outputs for Atomic SubSystem: '<S2>/Output' */
    /* DataStoreRead: '<S10>/Data Store Read' */
    rtb_DataStoreRead[3] = SwingUp_DW.x[3];

    /* End of Outputs for SubSystem: '<S2>/Output' */

    /* MATLAB Function: '<S1>/EKF' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/Constant3'
     *  Constant: '<S1>/Constant4'
     *  Constant: '<S1>/Constant5'
     *  Delay: '<S1>/Delay One Step1'
     *  Delay: '<S1>/Delay One Step2'
     *  ManualSwitch: '<Root>/Manual Switch'
     */
    x_tmp_1 = SwingUp_P.Ts * x[3] + SwingUp_DW.DelayOneStep2_DSTATE[3];
    x[3] = x_tmp_1;
    epsilon = cos(t5);
    t3 = sin(t5);
    t4 = SwingUp_P.id_param[8] * SwingUp_P.id_param[8];
    t8 = t7;
    t10 = t5 * 2.0;
    tau = x_tmp_0 * x_tmp_0;
    t13 = x_tmp_1 * x_tmp_1;
    t20 = 1.0 / SwingUp_P.id_param[9];
    t15 = cos(t10);
    t16 = cos(t5 * 3.0);
    t7 = epsilon * epsilon;
    t18 = sin(t10);
    t10 = t3 * t3;
    t11 = SwingUp_P.id_param[5] * t9;
    t21 = t4_tmp * t8 * t9;
    t23 = SwingUp_P.id_param[2] * x_tmp_a;
    t24 = SwingUp_P.id_param[3] * x_tmp_a;
    t25 = SwingUp_P.id_param[3] * t11;
    t26 = t3 * t3 - 1.0;
    t27 = t30 * t8;
    t30 = t7 * t27;
    t37 = 1.0 / ((((((((t27_tmp + t23) + t24) + t25) + t27) + t21) - t7 * t24) -
                  t30) - t7 * t21);
    c_0[0] = 1.0;
    c_0[1] = 0.0;
    c_0[2] = 0.0;
    c_0[3] = 0.0;
    c_0[4] = 0.0;
    c_0[5] = 1.0;
    t14 = SwingUp_P.id_param[6] * t3;
    tmp_4 = t14 * rtb_Sum_f * t8;
    tmp_5 = SwingUp_P.id_param[6] * epsilon;
    tmp_c = SwingUp_P.id_param[8] * rtb_DelayOneStep * SwingUp_P.id_param[10] *
      SwingUp_P.id_param[11] * SwingUp_P.id_param[13];
    tmp_d = SwingUp_P.id_param[10] * SwingUp_P.id_param[11] *
      SwingUp_P.id_param[12] * SwingUp_P.id_param[13];
    tmp_e = SwingUp_P.Ts * SwingUp_P.id_param[4] * SwingUp_P.id_param[5];
    t27_tmp = (((((((t27_tmp * 4.0 + t23 * 4.0) + t24 * 2.0) + t25 * 4.0) + t27 *
                  2.0) + t21 * 2.0) - t15 * t24 * 2.0) - t15 * t27 * 2.0) - t15 *
      t21 * 2.0;
    t25 = SwingUp_P.Ts * t18 * x_tmp_a * ((SwingUp_P.id_param[3] + x_tmp_a) +
      t11) * (t37 * t37);
    tmp_g = SwingUp_P.id_param[1] * x_tmp_a;
    t24 *= t18;
    tmp_h = t18 * t27;
    tmp_i = SwingUp_P.id_param[3] * SwingUp_P.id_param[10] * SwingUp_P.id_param
      [11] * SwingUp_P.id_param[12] * SwingUp_P.id_param[13] * t4 * t20;
    tmp_j = tmp_d * t4 * t20 * x_tmp_a;
    tmp_k = tmp_h * x_tmp_0;
    tmp_l = SwingUp_P.id_param[0] * SwingUp_P.id_param[6];
    tmp_m = SwingUp_P.id_param[3] * SwingUp_P.id_param[6];
    tmp_n = SwingUp_P.id_param[5] * rtb_Sum_f;
    tmp_r = tmp_4 * tau;
    t4_tmp = ((((x_tmp_2 * x_tmp_0 * 2.0 + tmp_g * x_tmp_0 * 2.0) + t24 *
                x_tmp_0 * x_tmp_1 * 2.0) + tmp_k * x_tmp_1 * 2.0) - x_tmp_3 *
              t4_tmp * t8 * t18) + tmp_4 * t13 * 2.0;
    x_tmp_4 = x_tmp_4 * epsilon * x_tmp_1 * 2.0;
    x_tmp_5 = x_tmp_5 * t3 * t13 * 2.0;
    x_tmp_3 = tmp_c * t20 * x_tmp_a * 2.0;
    tmp_s = SwingUp_P.id_param[3] * SwingUp_P.id_param[8] * rtb_DelayOneStep *
      SwingUp_P.id_param[10] * SwingUp_P.id_param[11] * SwingUp_P.id_param[13] *
      t20 * 2.0;
    tmp_t = tmp_i * x_tmp_0 * 2.0;
    tmp_u = tmp_j * x_tmp_0 * 2.0;
    tmp_v = -((((((((tmp_m * epsilon * t13 * 4.0 - tmp_5 * tau * x_tmp_a) +
                    tmp_5 * t13 * x_tmp_a * 4.0) - SwingUp_P.id_param[6] * tau *
                   t16 * x_tmp_a * 3.0) - tmp_l * t3 * x_tmp_1 * 4.0) +
                 x_tmp_tmp * t15 * x_tmp_0 * x_tmp_1 * 8.0) - x_tmp_6 *
                SwingUp_P.id_param[5] * SwingUp_P.id_param[6] * t15 * 4.0) +
               tmp_n * t15 * x_tmp_0 * x_tmp_1 * 8.0) * tmp_e) / t27_tmp;
    c_0[6] = ((((((((t10 - 1.0) * tmp_r * 2.0 + t4_tmp) + x_tmp_4) + x_tmp_5) -
                 x_tmp_3) - tmp_s) + tmp_t) + tmp_u) * t25 / 2.0 + tmp_v;
    tmp_7 = SwingUp_P.id_param[7] * SwingUp_P.id_param[9];
    tmp_6 = tmp_7 * epsilon;
    tmp_8 = SwingUp_P.id_param[2] * SwingUp_P.id_param[9];
    tmp_9 = SwingUp_P.id_param[4] * SwingUp_P.id_param[9];
    tmp_a = SwingUp_P.id_param[5] * SwingUp_P.id_param[9] * rtb_Sum_f * tau;
    tmp_b = SwingUp_P.id_param[6] * SwingUp_P.id_param[9];
    tmp_f = tau * t18;
    x_tmp_9 *= epsilon;
    tmp_o = SwingUp_P.id_param[0] * x_tmp_a;
    tmp_p = SwingUp_P.id_param[0] * t11;
    tmp_q = SwingUp_P.id_param[0] * t7 * x_tmp_a;
    tmp_f = ((((((((((((x_tmp_7 * x_tmp_1 * -2.0 - tmp_o * x_tmp_1 * 2.0) -
                       tmp_p * x_tmp_1 * 2.0) + tmp_f * t23) + tmp_f * t27) +
                    tmp_f * t21) - t13 * t18 * t21) + tmp_q * x_tmp_1 * 2.0) +
                 SwingUp_P.id_param[7] * t3 * rtb_Sum_f * t8 * 2.0) -
                rt_powd_snf(epsilon, 3.0) * t3 * tau * t27 * 2.0) -
               SwingUp_P.id_param[7] * rtb_Sum_f * t8 * (t3 - rt_powd_snf(t3,
      3.0)) * 2.0) + x_tmp_8 * t3 * 2.0) + x_tmp_6 * t3 * t8 * t9 * 2.0) -
      x_tmp_9 * x_tmp_0 * 2.0;
    rtb_DelayOneStep = tau_tmp * SwingUp_P.id_param[4] * SwingUp_P.id_param[5] *
      SwingUp_P.id_param[6] * epsilon * t20 * (rtb_DelayOneStep - tau_tmp_0 *
      x_tmp_0) * 2.0;
    tmp_c = ((((((((((((((tmp_6 * x_tmp_a * 3.0 + tmp_6 * t11 * 4.0) - tmp_7 *
                         t16 * x_tmp_a * 3.0) + tmp_8 * SwingUp_P.id_param[7] *
                        epsilon * 4.0) - cos(t5 * 4.0) * tmp_a * 2.0) -
                      SwingUp_P.id_param[0] * SwingUp_P.id_param[9] *
                      SwingUp_P.id_param[4] * t18 * x_tmp_1 * 4.0) + tmp_8 *
                     SwingUp_P.id_param[4] * tau * t15 * 4.0) +
                    SwingUp_P.id_param[1] * SwingUp_P.id_param[9] *
                    SwingUp_P.id_param[6] * t3 * x_tmp_0 * 4.0) + tmp_9 * tau *
                   t15 * t11 * 4.0) - tmp_9 * t13 * t15 * t11 * 4.0) + tmp_a *
                 t15 * 2.0) - tmp_b * epsilon * x_tmp_a * x_tmp_0 * x_tmp_1 *
                2.0) - tmp_b * t16 * x_tmp_a * x_tmp_0 * x_tmp_1 * 6.0) - tmp_c *
              SwingUp_P.id_param[6] * t3 * 4.0) + tmp_d * SwingUp_P.id_param[6] *
             t3 * t4 * x_tmp_0 * 4.0) * (tmp_e * t20) / t27_tmp;
    c_0[7] = (((t10 - 1.0) * tmp_4 * x_tmp_0 * x_tmp_1 * 4.0 + tmp_f) +
              rtb_DelayOneStep) * t25 * -0.5 + tmp_c;
    c_0[8] = SwingUp_P.Ts;
    c_0[9] = 0.0;
    tmp_5 = tmp_5 * rtb_Sum_f * t8 * t18;
    tmp_e = SwingUp_P.Ts * t37;
    t27_tmp = ((((((tmp_g * 2.0 + x_tmp_2 * 2.0) + t24 * x_tmp_1 * 2.0) + tmp_h *
                  x_tmp_1 * 2.0) - tmp_5 * x_tmp_0 * 2.0) + tmp_i * 2.0) + tmp_j
               * 2.0) * tmp_e * -0.5 + 1.0;
    c_0[10] = t27_tmp;
    tmp_5 = ((((((t18 * t23 * x_tmp_0 * -2.0 - tmp_k * 2.0) - t18 * t21 *
                 x_tmp_0 * 2.0) + t18 * t30 * x_tmp_0 * 2.0) + x_tmp_9 * 2.0) +
              tmp_5 * x_tmp_1 * 2.0) + tmp_d * SwingUp_P.id_param[4] *
             SwingUp_P.id_param[5] * SwingUp_P.id_param[6] * epsilon * t4 * t20 *
             2.0) * tmp_e * -0.5;
    c_0[11] = tmp_5;
    c_0[12] = 0.0;
    c_0[13] = SwingUp_P.Ts;
    t14 = ((((x_tmp_tmp * t18 * x_tmp_0 + tmp_l * epsilon) + tmp_m * t3 *
             x_tmp_1 * 2.0) + tmp_n * t18 * x_tmp_0) + t14 * x_tmp_a * x_tmp_1 *
           2.0) * (-SwingUp_P.Ts * SwingUp_P.id_param[4] * SwingUp_P.id_param[5]
                   * t37);
    c_0[14] = t14;
    tmp_d = (((((tmp_o * 2.0 + tmp_p * 2.0) + x_tmp_7 * 2.0) - tmp_q * 2.0) +
              epsilon * t3 * t21 * x_tmp_1 * 4.0) + tmp_4 * t7 * x_tmp_0 * 4.0) *
      tmp_e * -0.5 + 1.0;
    c_0[15] = tmp_d;
    tmp_0[0] = 1.0;
    tmp_0[1] = 0.0;
    tmp_0[2] = 0.0;
    tmp_0[3] = 0.0;
    tmp_0[4] = 0.0;
    tmp_0[5] = 1.0;
    tmp_0[6] = (((((((tmp_r * t26 * 2.0 + t4_tmp) + x_tmp_4) + x_tmp_5) -
                   x_tmp_3) - tmp_s) + tmp_t) + tmp_u) * t25 / 2.0 + tmp_v;
    tmp_0[7] = ((tmp_4 * t26 * x_tmp_0 * x_tmp_1 * 4.0 + tmp_f) +
                rtb_DelayOneStep) * t25 * -0.5 + tmp_c;
    tmp_0[8] = SwingUp_P.Ts;
    tmp_0[9] = 0.0;
    tmp_0[10] = t27_tmp;
    tmp_0[11] = tmp_5;
    tmp_0[12] = 0.0;
    tmp_0[13] = SwingUp_P.Ts;
    tmp_0[14] = t14;
    tmp_0[15] = tmp_d;
    for (lastc = 0; lastc < 4; lastc++) {
      for (j = 0; j < 4; j++) {
        r1 = j << 2;
        aoffset = lastc + r1;
        tmp_1[aoffset] = 0.0;
        tmp_1[aoffset] += SwingUp_DW.DelayOneStep1_DSTATE[r1] * c_0[lastc];
        tmp_1[aoffset] += SwingUp_DW.DelayOneStep1_DSTATE[r1 + 1] * c_0[lastc +
          4];
        tmp_1[aoffset] += SwingUp_DW.DelayOneStep1_DSTATE[r1 + 2] * c_0[lastc +
          8];
        tmp_1[aoffset] += SwingUp_DW.DelayOneStep1_DSTATE[r1 + 3] * c_0[lastc +
          12];
      }

      for (j = 0; j < 4; j++) {
        r1 = (j << 2) + lastc;
        P_temp[r1] = (((tmp_1[lastc + 4] * tmp_0[j + 4] + tmp_1[lastc] * tmp_0[j])
                       + tmp_1[lastc + 8] * tmp_0[j + 8]) + tmp_1[lastc + 12] *
                      tmp_0[j + 12]) + SwingUp_P.E[r1];
      }
    }

    for (lastc = 0; lastc < 8; lastc++) {
      K[lastc] = b[lastc];
      A_tmp[lastc] = a[lastc];
    }

    for (lastc = 0; lastc < 2; lastc++) {
      for (j = 0; j < 4; j++) {
        r1 = (j << 1) + lastc;
        A_tmp_0[r1] = 0.0;
        aoffset = j << 2;
        A_tmp_0[r1] += P_temp[aoffset] * (real_T)A_tmp[lastc];
        A_tmp_0[r1] += P_temp[aoffset + 1] * (real_T)A_tmp[lastc + 2];
        A_tmp_0[r1] += P_temp[aoffset + 2] * (real_T)A_tmp[lastc + 4];
        A_tmp_0[r1] += P_temp[aoffset + 3] * (real_T)A_tmp[lastc + 6];
      }

      for (j = 0; j < 2; j++) {
        r1 = j << 2;
        aoffset = (j << 1) + lastc;
        rtb_xNew_k[aoffset] = (((K[r1 + 1] * A_tmp_0[lastc + 2] + K[r1] *
          A_tmp_0[lastc]) + K[r1 + 2] * A_tmp_0[lastc + 4]) + K[r1 + 3] *
          A_tmp_0[lastc + 6]) + SwingUp_P.R[aoffset];
      }

      for (j = 0; j <= 2; j += 2) {
        __m128d tmp_3;
        r1 = lastc << 2;
        aoffset = j + r1;
        _mm_storeu_pd(&B[aoffset], _mm_set1_pd(0.0));
        tmp_2 = _mm_loadu_pd(&P_temp[j]);
        tmp_3 = _mm_loadu_pd(&B[aoffset]);
        _mm_storeu_pd(&B[aoffset], _mm_add_pd(tmp_3, _mm_mul_pd(_mm_set1_pd(K[r1]),
          tmp_2)));
        tmp_2 = _mm_loadu_pd(&P_temp[j + 4]);
        tmp_3 = _mm_loadu_pd(&B[aoffset]);
        _mm_storeu_pd(&B[aoffset], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(K[r1 + 1]),
          tmp_2), tmp_3));
        tmp_2 = _mm_loadu_pd(&P_temp[j + 8]);
        tmp_3 = _mm_loadu_pd(&B[aoffset]);
        _mm_storeu_pd(&B[aoffset], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(K[r1 + 2]),
          tmp_2), tmp_3));
        tmp_2 = _mm_loadu_pd(&P_temp[j + 12]);
        tmp_3 = _mm_loadu_pd(&B[aoffset]);
        _mm_storeu_pd(&B[aoffset], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(K[r1 + 3]),
          tmp_2), tmp_3));
      }
    }

    if (fabs(rtb_xNew_k[1]) > fabs(rtb_xNew_k[0])) {
      r1 = 1;
      aoffset = 0;
    } else {
      r1 = 0;
      aoffset = 1;
    }

    epsilon = rtb_xNew_k[aoffset] / rtb_xNew_k[r1];
    rtb_Sum_f = rtb_xNew_k[r1 + 2];
    t3 = rtb_xNew_k[aoffset + 2] - rtb_Sum_f * epsilon;
    rtb_DelayOneStep = SwingUp_B.DiscreteTimeIntegrator[0] - x_tmp;
    t8 = SwingUp_B.DiscreteTimeIntegrator[1] - t5;
    for (j = 0; j < 4; j++) {
      lastc = (r1 << 2) + j;
      K[lastc] = B[j] / rtb_xNew_k[r1];
      coffset = (aoffset << 2) + j;
      K[coffset] = (B[j + 4] - K[lastc] * rtb_Sum_f) / t3;
      K[lastc] -= K[coffset] * epsilon;
      t9 = K[j + 4];
      SwingUp_B.x_hat[j] = (t9 * t8 + K[j] * rtb_DelayOneStep) + x[j];
      for (lastc = 0; lastc < 4; lastc++) {
        coffset = lastc << 1;
        c_tmp = (lastc << 2) + j;
        c_0[c_tmp] = (real_T)c_1[c_tmp] - ((real_T)A_tmp[coffset + 1] * t9 +
          (real_T)A_tmp[coffset] * K[j]);
      }

      for (lastc = 0; lastc < 4; lastc++) {
        coffset = lastc << 2;
        c_tmp = j + coffset;
        SwingUp_B.P_new[c_tmp] = 0.0;
        SwingUp_B.P_new[c_tmp] += P_temp[coffset] * c_0[j];
        SwingUp_B.P_new[c_tmp] += P_temp[coffset + 1] * c_0[j + 4];
        SwingUp_B.P_new[c_tmp] += P_temp[coffset + 2] * c_0[j + 8];
        SwingUp_B.P_new[c_tmp] += P_temp[coffset + 3] * c_0[j + 12];
      }

      /* ManualSwitch: '<Root>/Manual Switch' */
      if (SwingUp_P.ManualSwitch_CurrentSetting == 1) {
        t9 = rtb_DataStoreRead[j];
      } else {
        t9 = SwingUp_B.x_hat[j];
      }

      x[j] = t9;
    }

    /* Trigonometry: '<S6>/Cos' incorporates:
     *  Trigonometry: '<S18>/Cos'
     *  Trigonometry: '<S19>/Cos'
     *  Trigonometry: '<S20>/Cos'
     *  Trigonometry: '<S22>/Cos'
     */
    epsilon = cos(x[1]);
    rtb_DelayOneStep = epsilon;

    /* Product: '<S6>/Product2' */
    t3 = rtb_DelayOneStep * x[3];

    /* Sum: '<S22>/Sum' incorporates:
     *  Constant: '<S22>/Constant'
     */
    t4 = rtb_DelayOneStep + SwingUp_P.Constant_Value;

    /* Math: '<S22>/Square' incorporates:
     *  Math: '<S17>/Square'
     */
    tau = x[3] * x[3];
    rtb_DelayOneStep = tau;

    /* Sum: '<S22>/Sum1' incorporates:
     *  Gain: '<S22>/Gain'
     *  Gain: '<S22>/Gain1'
     */
    rtb_DelayOneStep = SwingUp_P.g * SwingUp_P.m_p * SwingUp_P.l_p * t4 + 0.5 *
      SwingUp_P.Jp_prime * rtb_DelayOneStep;

    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_Sum_f = rtb_DelayOneStep - 2.0 * SwingUp_P.m_p * SwingUp_P.g *
      SwingUp_P.l_p;

    /* Trigonometry: '<S6>/Sin' incorporates:
     *  Trigonometry: '<S17>/Sin'
     *  Trigonometry: '<S18>/Sin'
     *  Trigonometry: '<S19>/Sin'
     *  Trigonometry: '<S20>/Sin'
     */
    t4 = sin(x[1]);
    t8 = t4;

    /* Math: '<S6>/Square' incorporates:
     *  Math: '<S20>/Square'
     */
    t10 = x[2] * x[2];
    t9 = t10;

    /* Signum: '<S6>/Sign' */
    if (rtIsNaN(t3)) {
      t14 = (rtNaN);
    } else if (t3 < 0.0) {
      t14 = -1.0;
    } else {
      t14 = (t3 > 0.0);
    }

    /* Sum: '<S6>/Sum1' incorporates:
     *  Gain: '<S6>/Gain1'
     *  Gain: '<S6>/Gain2'
     *  Gain: '<S6>/Kd'
     *  Gain: '<S6>/Kp'
     *  Product: '<S6>/Product'
     *  Product: '<S6>/Product1'
     *  Signum: '<S6>/Sign'
     *  Sum: '<S6>/Sum2'
     */
    t9 = (0.0 - 1.0 / SwingUp_P.l_p * SwingUp_P.m_p * SwingUp_P.r * 1000.0 *
          (t14 * rtb_Sum_f)) - ((SwingUp_P.Kp * x[0] + SwingUp_P.Kd * x[2]) +
      SwingUp_P.l_p / SwingUp_P.r * (t8 * t9));

    /* Gain: '<S19>/Gain1' incorporates:
     *  Math: '<S19>/Square'
     */
    t3 = 0.00085465124062247106 * SwingUp_P.m_p * (t8 * t8);

    /* Trigonometry: '<S19>/Cos' */
    t8 = epsilon;

    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S19>/Constant1'
     *  Gain: '<S16>/Gain'
     *  Gain: '<S16>/Gain1'
     *  Gain: '<S17>/Gain'
     *  Gain: '<S18>/Gain'
     *  Gain: '<S19>/Gain'
     *  Gain: '<S20>/Gain'
     *  Math: '<S19>/Square1'
     *  Math: '<S20>/Square1'
     *  Product: '<S16>/Product'
     *  Product: '<S16>/Product1'
     *  Product: '<S17>/Product'
     *  Product: '<S18>/Product'
     *  Product: '<S19>/Product'
     *  Product: '<S20>/Product'
     *  Product: '<S20>/Product1'
     *  Sum: '<S19>/Sum'
     *  Trigonometry: '<S16>/Sin'
     */
    t8 = ((((((SwingUp_P.m_p * 0.046655999999999996 + SwingUp_P.J_a) + t3) -
             6.4313755698815234E-7 / SwingUp_P.Jp_prime * (t8 * t8)) * t9 +
            SwingUp_P.l_p * SwingUp_P.m_p * SwingUp_P.r * t4 * tau) + sin
           (SwingUp_P.Gain1_Gain * x[1]) * (x[2] * x[3]) *
           (0.00085465124062247106 * SwingUp_P.m_p)) - 4.0298681124692695E-7 *
          SwingUp_P.r / SwingUp_P.Jp_prime * (epsilon * epsilon * t4) * t10) -
      SwingUp_P.g * 0.00085465124062247106 * 0.016129 * SwingUp_P.r /
      SwingUp_P.Jp_prime * (epsilon * t4);

    /* ManualSwitch: '<Root>/Manual Switch1' */
    if (SwingUp_P.ManualSwitch1_CurrentSetting == 1) {
      t14 = rtb_DataStoreRead[2];
    } else {
      t14 = SwingUp_B.x_hat[2];
    }

    /* Gain: '<S5>/Gain1' incorporates:
     *  Gain: '<S5>/Gain'
     *  ManualSwitch: '<Root>/Manual Switch1'
     *  Sum: '<S5>/Sum'
     */
    SwingUp_B.Gain1 = (SwingUp_P.K_g * SwingUp_P.k_m * SwingUp_P.c1_tau * t14 +
                       t8) * (1.0 / SwingUp_P.c1_tau);

    /* Sum: '<Root>/Sum1' incorporates:
     *  Abs: '<Root>/Abs1'
     *  Constant: '<Root>/Constant3'
     */
    SwingUp_B.alpha_minus_2pi = fabs(SwingUp_B.DiscreteTimeIntegrator[1]) -
      SwingUp_P.Constant3_Value;

    /* Abs: '<Root>/Abs' */
    SwingUp_B.Abs = fabs(SwingUp_B.alpha_minus_2pi);
  }

  for (j = 0; j <= 2; j += 2) {
    /* StateSpace: '<Root>/State-Space' */
    _mm_storeu_pd(&rtb_xNew_k[j], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&SwingUp_P.C_ob[j + 12]), _mm_set1_pd(SwingUp_X.StateSpace_CSTATE[3])),
      _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&SwingUp_P.C_ob[j + 8]), _mm_set1_pd
      (SwingUp_X.StateSpace_CSTATE[2])), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&SwingUp_P.C_ob[j + 4]), _mm_set1_pd(SwingUp_X.StateSpace_CSTATE[1])),
      _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&SwingUp_P.C_ob[j]), _mm_set1_pd
      (SwingUp_X.StateSpace_CSTATE[0])), _mm_set1_pd(0.0))))));
  }

  /* Switch: '<Root>/Switch' */
  if (SwingUp_B.Abs >= SwingUp_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' */
    SwingUp_B.voltage_no_sat = SwingUp_B.Gain1;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Gain: '<Root>/LQinf gain1'
     *  Sum: '<Root>/Sum'
     */
    SwingUp_B.voltage_no_sat = 0.0 - (((SwingUp_P.Kpp[0] * rtb_xNew_k[0] +
      SwingUp_P.Kpp[1] * rtb_xNew_k[1]) + SwingUp_P.Kpp[2] * rtb_xNew_k[2]) +
      SwingUp_P.Kpp[3] * rtb_xNew_k[3]);
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<Root>/Maximum voltage1' */
  if (SwingUp_B.voltage_no_sat > SwingUp_P.voltage_max) {
    /* Saturate: '<Root>/Maximum voltage1' */
    SwingUp_B.voltage_sat = SwingUp_P.voltage_max;
  } else if (SwingUp_B.voltage_no_sat < -SwingUp_P.voltage_max) {
    /* Saturate: '<Root>/Maximum voltage1' */
    SwingUp_B.voltage_sat = -SwingUp_P.voltage_max;
  } else {
    /* Saturate: '<Root>/Maximum voltage1' */
    SwingUp_B.voltage_sat = SwingUp_B.voltage_no_sat;
  }

  /* End of Saturate: '<Root>/Maximum voltage1' */
  if (rtmIsMajorTimeStep(SwingUp_M)) {
    /* Outputs for Atomic SubSystem: '<S2>/Predict' */
    /* MATLAB Function: '<S11>/Predict' incorporates:
     *  DataStoreRead: '<S11>/Data Store ReadX'
     */
    rtb_xNew_k[0] = SwingUp_DW.x[0];
    rtb_xNew_k[1] = SwingUp_DW.x[1];
    rtb_xNew_k[2] = SwingUp_DW.x[2];
    rtb_xNew_k[3] = SwingUp_DW.x[3];
    SwingUp_StateFcn(rtb_xNew_k, SwingUp_B.voltage_sat);
    for (j = 0; j < 4; j++) {
      x[0] = SwingUp_DW.x[0];
      x[1] = SwingUp_DW.x[1];
      x[2] = SwingUp_DW.x[2];
      x[3] = SwingUp_DW.x[3];
      epsilon = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                     (SwingUp_DW.x[j]));
      x[j] = SwingUp_DW.x[j] + epsilon;
      SwingUp_StateFcn(x, SwingUp_B.voltage_sat);
      r1 = j << 2;
      P_temp[r1] = (x[0] - rtb_xNew_k[0]) / epsilon;
      P_temp[r1 + 1] = (x[1] - rtb_xNew_k[1]) / epsilon;
      P_temp[r1 + 2] = (x[2] - rtb_xNew_k[2]) / epsilon;
      P_temp[r1 + 3] = (x[3] - rtb_xNew_k[3]) / epsilon;
    }

    /* DataStoreWrite: '<S11>/Data Store WriteX' incorporates:
     *  MATLAB Function: '<S11>/Predict'
     */
    SwingUp_StateFcn(SwingUp_DW.x, SwingUp_B.voltage_sat);

    /* MATLAB Function: '<S11>/Predict' incorporates:
     *  Constant: '<S2>/Q'
     *  DataStoreRead: '<S11>/Data Store ReadP'
     */
    for (lastc = 0; lastc < 4; lastc++) {
      coffset = lastc << 2;
      for (r1 = 0; r1 < 4; r1++) {
        aoffset = r1 << 2;
        c_0[coffset + r1] = ((SwingUp_DW.P[aoffset + 1] * P_temp[lastc + 4] +
                              SwingUp_DW.P[aoffset] * P_temp[lastc]) +
                             SwingUp_DW.P[aoffset + 2] * P_temp[lastc + 8]) +
          SwingUp_DW.P[aoffset + 3] * P_temp[lastc + 12];
      }
    }

    for (lastc = 0; lastc < 4; lastc++) {
      j = lastc << 3;
      r1 = lastc << 2;
      A_0[j] = c_0[r1];
      A_0[j + 4] = SwingUp_P.Q_Value[lastc];
      A_0[j + 1] = c_0[r1 + 1];
      A_0[j + 5] = SwingUp_P.Q_Value[lastc + 4];
      A_0[j + 2] = c_0[r1 + 2];
      A_0[j + 6] = SwingUp_P.Q_Value[lastc + 8];
      A_0[j + 3] = c_0[r1 + 3];
      A_0[j + 7] = SwingUp_P.Q_Value[lastc + 12];
      x[lastc] = 0.0;
    }

    for (j = 0; j < 4; j++) {
      int32_T c;
      r1 = (j << 3) + j;
      t3 = A_0[r1];
      lastc = r1 + 2;
      rtb_xNew_k[j] = 0.0;
      epsilon = SwingUp_xnrm2_d(7 - j, A_0, r1 + 2);
      if (epsilon != 0.0) {
        epsilon = rt_hypotd_snf(A_0[r1], epsilon);
        if (A_0[r1] >= 0.0) {
          epsilon = -epsilon;
        }

        if (fabs(epsilon) < 1.0020841800044864E-292) {
          int32_T vectorUB;
          aoffset = 0;
          do {
            aoffset++;
            c = (r1 - j) + 8;
            c_tmp = (((((c - r1) - 1) / 2) << 1) + r1) + 2;
            vectorUB = c_tmp - 2;
            for (coffset = lastc; coffset <= vectorUB; coffset += 2) {
              tmp_2 = _mm_loadu_pd(&A_0[coffset - 1]);
              _mm_storeu_pd(&A_0[coffset - 1], _mm_mul_pd(tmp_2, _mm_set1_pd
                (9.9792015476736E+291)));
            }

            for (coffset = c_tmp; coffset <= c; coffset++) {
              A_0[coffset - 1] *= 9.9792015476736E+291;
            }

            epsilon *= 9.9792015476736E+291;
            t3 *= 9.9792015476736E+291;
          } while ((fabs(epsilon) < 1.0020841800044864E-292) && (aoffset < 20));

          epsilon = rt_hypotd_snf(t3, SwingUp_xnrm2_d(7 - j, A_0, r1 + 2));
          if (t3 >= 0.0) {
            epsilon = -epsilon;
          }

          rtb_xNew_k[j] = (epsilon - t3) / epsilon;
          t3 = 1.0 / (t3 - epsilon);
          c = (r1 - j) + 8;
          c_tmp = (((((c - r1) - 1) / 2) << 1) + r1) + 2;
          vectorUB = c_tmp - 2;
          for (coffset = lastc; coffset <= vectorUB; coffset += 2) {
            tmp_2 = _mm_loadu_pd(&A_0[coffset - 1]);
            _mm_storeu_pd(&A_0[coffset - 1], _mm_mul_pd(tmp_2, _mm_set1_pd(t3)));
          }

          for (coffset = c_tmp; coffset <= c; coffset++) {
            A_0[coffset - 1] *= t3;
          }

          for (lastc = 0; lastc < aoffset; lastc++) {
            epsilon *= 1.0020841800044864E-292;
          }

          t3 = epsilon;
        } else {
          int32_T vectorUB;
          rtb_xNew_k[j] = (epsilon - A_0[r1]) / epsilon;
          t3 = 1.0 / (A_0[r1] - epsilon);
          coffset = (r1 - j) + 8;
          c_tmp = (((((coffset - r1) - 1) / 2) << 1) + r1) + 2;
          vectorUB = c_tmp - 2;
          for (aoffset = lastc; aoffset <= vectorUB; aoffset += 2) {
            tmp_2 = _mm_loadu_pd(&A_0[aoffset - 1]);
            _mm_storeu_pd(&A_0[aoffset - 1], _mm_mul_pd(tmp_2, _mm_set1_pd(t3)));
          }

          for (aoffset = c_tmp; aoffset <= coffset; aoffset++) {
            A_0[aoffset - 1] *= t3;
          }

          t3 = epsilon;
        }
      }

      A_0[r1] = t3;
      if (j + 1 < 4) {
        epsilon = A_0[r1];
        A_0[r1] = 1.0;
        if (rtb_xNew_k[j] != 0.0) {
          boolean_T exitg2;
          aoffset = 8 - j;
          lastc = (r1 - j) + 7;
          while ((aoffset > 0) && (A_0[lastc] == 0.0)) {
            aoffset--;
            lastc--;
          }

          lastc = 3 - j;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int32_T exitg1;
            coffset = (((lastc - 1) << 3) + r1) + 8;
            c = coffset;
            do {
              exitg1 = 0;
              if (c + 1 <= coffset + aoffset) {
                if (A_0[c] != 0.0) {
                  exitg1 = 1;
                } else {
                  c++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          aoffset = 0;
          lastc = 0;
        }

        if (aoffset > 0) {
          SwingUp_xgemv_m(aoffset, lastc, A_0, r1 + 9, A_0, r1 + 1, x);
          SwingUp_xgerc_n(aoffset, lastc, -rtb_xNew_k[j], r1 + 1, x, A_0, r1 + 9);
        }

        A_0[r1] = epsilon;
      }
    }

    for (r1 = 0; r1 < 4; r1++) {
      for (j = 0; j <= r1; j++) {
        P_temp[j + (r1 << 2)] = A_0[(r1 << 3) + j];
      }

      for (j = r1 + 2; j < 5; j++) {
        P_temp[(j + (r1 << 2)) - 1] = 0.0;
      }
    }

    /* DataStoreWrite: '<S11>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S11>/Predict'
     */
    for (lastc = 0; lastc < 4; lastc++) {
      /* MATLAB Function: '<S11>/Predict' */
      j = lastc << 2;
      SwingUp_DW.P[j] = P_temp[lastc];
      SwingUp_DW.P[j + 1] = P_temp[lastc + 4];
      SwingUp_DW.P[j + 2] = P_temp[lastc + 8];
      SwingUp_DW.P[j + 3] = P_temp[lastc + 12];
    }

    /* End of DataStoreWrite: '<S11>/Data Store WriteP' */
    /* End of Outputs for SubSystem: '<S2>/Predict' */
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S4>/Constant'
   */
  tau = SwingUp_P.id_param[8] * SwingUp_P.id_param[10] * SwingUp_P.id_param[11] *
    SwingUp_P.id_param[13] * (SwingUp_B.voltage_sat - SwingUp_P.id_param[8] *
    SwingUp_P.id_param[12] * SwingUp_B.DiscreteTimeIntegrator[2]) /
    SwingUp_P.id_param[9];
  epsilon = cos(SwingUp_B.DiscreteTimeIntegrator[1]);
  t3 = sin(SwingUp_B.DiscreteTimeIntegrator[1]);
  t4 = SwingUp_P.id_param[4] * SwingUp_P.id_param[4];
  t5 = rt_powd_snf(SwingUp_P.id_param[4], 3.0);
  t7 = SwingUp_P.id_param[5] * SwingUp_P.id_param[5];
  t8 = SwingUp_P.id_param[6] * SwingUp_P.id_param[6];
  t10 = SwingUp_B.DiscreteTimeIntegrator[2] * SwingUp_B.DiscreteTimeIntegrator[2];
  t11 = SwingUp_B.DiscreteTimeIntegrator[3] * SwingUp_B.DiscreteTimeIntegrator[3];
  t13 = epsilon * epsilon;
  t14 = sin(SwingUp_B.DiscreteTimeIntegrator[1] * 2.0);
  t15 = SwingUp_P.id_param[2] * SwingUp_P.id_param[5] * t4;
  t27 = SwingUp_P.id_param[3] * SwingUp_P.id_param[5];
  t16 = t27 * t4;
  t20 = t4 * t7 * t8;
  t18 = t4 * t4 * t7;
  t21 = t13 * t18;
  t27 = 1.0 / ((((((((SwingUp_P.id_param[2] * SwingUp_P.id_param[3] + t15) + t16)
                    + t27 * t8) + t18) + t20) - t13 * t16) - t21) - t13 * t20);
  SwingUp_B.x_dot[0] = SwingUp_B.DiscreteTimeIntegrator[2];
  SwingUp_B.x_dot[1] = SwingUp_B.DiscreteTimeIntegrator[3];
  SwingUp_B.x_dot[2] = ((((((((((SwingUp_P.id_param[1] * SwingUp_P.id_param[3] *
    SwingUp_B.DiscreteTimeIntegrator[2] * 2.0 + SwingUp_P.id_param[3] * tau *
    -2.0) - SwingUp_P.id_param[5] * t4 * tau * 2.0) + t14 * t16 *
    SwingUp_B.DiscreteTimeIntegrator[2] * SwingUp_B.DiscreteTimeIntegrator[3] *
    2.0) + t14 * t18 * SwingUp_B.DiscreteTimeIntegrator[2] *
    SwingUp_B.DiscreteTimeIntegrator[3] * 2.0) + SwingUp_P.id_param[1] *
    SwingUp_P.id_param[5] * t4 * SwingUp_B.DiscreteTimeIntegrator[2] * 2.0) +
    SwingUp_P.id_param[6] * t3 * t5 * t7 * t11 * 2.0) - SwingUp_P.id_param[6] *
    SwingUp_P.id_param[7] * epsilon * t3 * t4 * t7 * 2.0) - SwingUp_P.id_param[6]
    * epsilon * t5 * t7 * t10 * t14) + SwingUp_P.id_param[0] *
    SwingUp_P.id_param[4] * SwingUp_P.id_param[5] * SwingUp_P.id_param[6] *
    epsilon * SwingUp_B.DiscreteTimeIntegrator[3] * 2.0) + SwingUp_P.id_param[3]
                        * SwingUp_P.id_param[4] * SwingUp_P.id_param[5] *
                        SwingUp_P.id_param[6] * t3 * t11 * 2.0) * t27 * -0.5;
  t16 = SwingUp_P.id_param[7] * t3 * t5 * t7;
  t10 *= t14;
  tau_tmp = SwingUp_P.id_param[0] * SwingUp_P.id_param[5];
  t4 *= tau_tmp;
  SwingUp_B.x_dot[3] = (((((((((((((((SwingUp_P.id_param[0] *
    SwingUp_P.id_param[2] * SwingUp_B.DiscreteTimeIntegrator[3] * 2.0 - t10 *
    t15) - t10 * t18) - t10 * t20) + t10 * t21) - t16 * 2.0) + epsilon * t3 *
    t11 * t20 * 2.0) + t4 * SwingUp_B.DiscreteTimeIntegrator[3] * 2.0) + tau_tmp
    * t8 * SwingUp_B.DiscreteTimeIntegrator[3] * 2.0) - SwingUp_P.id_param[2] *
    SwingUp_P.id_param[7] * SwingUp_P.id_param[4] * SwingUp_P.id_param[5] * t3 *
    2.0) - t4 * t13 * SwingUp_B.DiscreteTimeIntegrator[3] * 2.0) -
    SwingUp_P.id_param[4] * SwingUp_P.id_param[7] * t3 * t7 * t8 * 2.0) -
    SwingUp_P.id_param[4] * SwingUp_P.id_param[5] * SwingUp_P.id_param[6] *
    epsilon * tau * 2.0) + t16 * t13 * 2.0) + SwingUp_P.id_param[1] *
    SwingUp_P.id_param[4] * SwingUp_P.id_param[5] * SwingUp_P.id_param[6] *
    epsilon * SwingUp_B.DiscreteTimeIntegrator[2] * 2.0) + SwingUp_P.id_param[6]
                        * epsilon * t5 * t7 * t14 *
                        SwingUp_B.DiscreteTimeIntegrator[2] *
                        SwingUp_B.DiscreteTimeIntegrator[3] * 2.0) * t27 * -0.5;

  /* SignalConversion generated from: '<Root>/State-Space' */
  SwingUp_B.TmpSignalConversionAtStateSpace[0] = SwingUp_B.voltage_sat;
  SwingUp_B.TmpSignalConversionAtStateSpace[1] =
    SwingUp_B.DiscreteTimeIntegrator[0];
  SwingUp_B.TmpSignalConversionAtStateSpace[2] = SwingUp_B.alpha_minus_2pi;
  if (rtmIsMajorTimeStep(SwingUp_M)) {
  }

  if (rtmIsMajorTimeStep(SwingUp_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(SwingUp_M->rtwLogInfo, (SwingUp_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SwingUp_M)) {
    if (rtmIsMajorTimeStep(SwingUp_M)) {
      /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[0] +=
        SwingUp_P.DiscreteTimeIntegrator_gainval * SwingUp_B.x_dot[0];
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[1] +=
        SwingUp_P.DiscreteTimeIntegrator_gainval * SwingUp_B.x_dot[1];
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[2] +=
        SwingUp_P.DiscreteTimeIntegrator_gainval * SwingUp_B.x_dot[2];
      SwingUp_DW.DiscreteTimeIntegrator_DSTATE[3] +=
        SwingUp_P.DiscreteTimeIntegrator_gainval * SwingUp_B.x_dot[3];

      /* Update for Delay: '<S1>/Delay One Step' */
      SwingUp_DW.DelayOneStep_DSTATE = SwingUp_B.voltage_sat;

      /* Update for Delay: '<S1>/Delay One Step1' */
      memcpy(&SwingUp_DW.DelayOneStep1_DSTATE[0], &SwingUp_B.P_new[0], sizeof
             (real_T) << 4U);

      /* Update for Delay: '<S1>/Delay One Step2' */
      SwingUp_DW.DelayOneStep2_DSTATE[0] = SwingUp_B.x_hat[0];
      SwingUp_DW.DelayOneStep2_DSTATE[1] = SwingUp_B.x_hat[1];
      SwingUp_DW.DelayOneStep2_DSTATE[2] = SwingUp_B.x_hat[2];
      SwingUp_DW.DelayOneStep2_DSTATE[3] = SwingUp_B.x_hat[3];
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SwingUp_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(SwingUp_M)!=-1) &&
          !((rtmGetTFinal(SwingUp_M)-(((SwingUp_M->Timing.clockTick1+
               SwingUp_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((SwingUp_M->Timing.clockTick1+SwingUp_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(SwingUp_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&SwingUp_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++SwingUp_M->Timing.clockTick0)) {
      ++SwingUp_M->Timing.clockTickH0;
    }

    SwingUp_M->Timing.t[0] = rtsiGetSolverStopTime(&SwingUp_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      SwingUp_M->Timing.clockTick1++;
      if (!SwingUp_M->Timing.clockTick1) {
        SwingUp_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SwingUp_derivatives(void)
{
  XDot_SwingUp_T *_rtXdot;
  int_T is;
  _rtXdot = ((XDot_SwingUp_T *) SwingUp_M->derivs);
  for (is = 0; is <= 2; is += 2) {
    __m128d tmp;

    /* Derivatives for StateSpace: '<Root>/State-Space' */
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_set1_pd(0.0));
    tmp = _mm_loadu_pd(&_rtXdot->StateSpace_CSTATE[is]);
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&SwingUp_P.A_ob[is]), _mm_set1_pd
       (SwingUp_X.StateSpace_CSTATE[0])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->StateSpace_CSTATE[is]);
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&SwingUp_P.A_ob[is + 4]), _mm_set1_pd
       (SwingUp_X.StateSpace_CSTATE[1])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->StateSpace_CSTATE[is]);
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&SwingUp_P.A_ob[is + 8]), _mm_set1_pd
       (SwingUp_X.StateSpace_CSTATE[2])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->StateSpace_CSTATE[is]);
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&SwingUp_P.A_ob[is + 12]), _mm_set1_pd
       (SwingUp_X.StateSpace_CSTATE[3])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->StateSpace_CSTATE[is]);
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&SwingUp_P.B_ob[is]), _mm_set1_pd
       (SwingUp_B.TmpSignalConversionAtStateSpace[0])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->StateSpace_CSTATE[is]);
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&SwingUp_P.B_ob[is + 4]), _mm_set1_pd
       (SwingUp_B.TmpSignalConversionAtStateSpace[1])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->StateSpace_CSTATE[is]);
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&SwingUp_P.B_ob[is + 8]), _mm_set1_pd
       (SwingUp_B.TmpSignalConversionAtStateSpace[2])), tmp));
  }
}

/* Model initialize function */
void SwingUp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SwingUp_M, 0,
                sizeof(RT_MODEL_SwingUp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SwingUp_M->solverInfo, &SwingUp_M->Timing.simTimeStep);
    rtsiSetTPtr(&SwingUp_M->solverInfo, &rtmGetTPtr(SwingUp_M));
    rtsiSetStepSizePtr(&SwingUp_M->solverInfo, &SwingUp_M->Timing.stepSize0);
    rtsiSetdXPtr(&SwingUp_M->solverInfo, &SwingUp_M->derivs);
    rtsiSetContStatesPtr(&SwingUp_M->solverInfo, (real_T **)
                         &SwingUp_M->contStates);
    rtsiSetNumContStatesPtr(&SwingUp_M->solverInfo,
      &SwingUp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SwingUp_M->solverInfo,
      &SwingUp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&SwingUp_M->solverInfo,
      &SwingUp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&SwingUp_M->solverInfo,
      &SwingUp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SwingUp_M->solverInfo, (&rtmGetErrorStatus(SwingUp_M)));
    rtsiSetRTModelPtr(&SwingUp_M->solverInfo, SwingUp_M);
  }

  rtsiSetSimTimeStep(&SwingUp_M->solverInfo, MAJOR_TIME_STEP);
  SwingUp_M->intgData.y = SwingUp_M->odeY;
  SwingUp_M->intgData.f[0] = SwingUp_M->odeF[0];
  SwingUp_M->intgData.f[1] = SwingUp_M->odeF[1];
  SwingUp_M->intgData.f[2] = SwingUp_M->odeF[2];
  SwingUp_M->contStates = ((X_SwingUp_T *) &SwingUp_X);
  rtsiSetSolverData(&SwingUp_M->solverInfo, (void *)&SwingUp_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&SwingUp_M->solverInfo, false);
  rtsiSetSolverName(&SwingUp_M->solverInfo,"ode3");
  rtmSetTPtr(SwingUp_M, &SwingUp_M->Timing.tArray[0]);
  rtmSetTFinal(SwingUp_M, 30.0);
  SwingUp_M->Timing.stepSize0 = 0.002;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    SwingUp_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(SwingUp_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(SwingUp_M->rtwLogInfo, (NULL));
    rtliSetLogT(SwingUp_M->rtwLogInfo, "tout");
    rtliSetLogX(SwingUp_M->rtwLogInfo, "");
    rtliSetLogXFinal(SwingUp_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(SwingUp_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(SwingUp_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(SwingUp_M->rtwLogInfo, 0);
    rtliSetLogDecimation(SwingUp_M->rtwLogInfo, 1);
    rtliSetLogY(SwingUp_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(SwingUp_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(SwingUp_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &SwingUp_B), 0,
                sizeof(B_SwingUp_T));

  /* states (continuous) */
  {
    (void) memset((void *)&SwingUp_X, 0,
                  sizeof(X_SwingUp_T));
  }

  /* states (dwork) */
  (void) memset((void *)&SwingUp_DW, 0,
                sizeof(DW_SwingUp_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(SwingUp_M->rtwLogInfo, 0.0, rtmGetTFinal
    (SwingUp_M), SwingUp_M->Timing.stepSize0, (&rtmGetErrorStatus(SwingUp_M)));

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - P' */
  memcpy(&SwingUp_DW.P[0], &SwingUp_P.DataStoreMemoryP_InitialValue[0], sizeof
         (real_T) << 4U);

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - x' */
  SwingUp_DW.x[0] = SwingUp_P.DataStoreMemoryx_InitialValue[0];
  SwingUp_DW.x[1] = SwingUp_P.DataStoreMemoryx_InitialValue[1];
  SwingUp_DW.x[2] = SwingUp_P.DataStoreMemoryx_InitialValue[2];
  SwingUp_DW.x[3] = SwingUp_P.DataStoreMemoryx_InitialValue[3];

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  SwingUp_DW.DiscreteTimeIntegrator_DSTATE[0] = SwingUp_P.x0_down[0];
  SwingUp_DW.DiscreteTimeIntegrator_DSTATE[1] = SwingUp_P.x0_down[1];
  SwingUp_DW.DiscreteTimeIntegrator_DSTATE[2] = SwingUp_P.x0_down[2];
  SwingUp_DW.DiscreteTimeIntegrator_DSTATE[3] = SwingUp_P.x0_down[3];

  /* InitializeConditions for Delay: '<S1>/Delay One Step' */
  SwingUp_DW.DelayOneStep_DSTATE = SwingUp_P.DelayOneStep_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay One Step1' */
  memcpy(&SwingUp_DW.DelayOneStep1_DSTATE[0], &SwingUp_P.P0[0], sizeof(real_T) <<
         4U);

  /* InitializeConditions for Delay: '<S1>/Delay One Step2' */
  SwingUp_DW.DelayOneStep2_DSTATE[0] = SwingUp_P.x0_KF[0];

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  SwingUp_X.StateSpace_CSTATE[0] = SwingUp_P.x0_ob[0];

  /* InitializeConditions for Delay: '<S1>/Delay One Step2' */
  SwingUp_DW.DelayOneStep2_DSTATE[1] = SwingUp_P.x0_KF[1];

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  SwingUp_X.StateSpace_CSTATE[1] = SwingUp_P.x0_ob[1];

  /* InitializeConditions for Delay: '<S1>/Delay One Step2' */
  SwingUp_DW.DelayOneStep2_DSTATE[2] = SwingUp_P.x0_KF[2];

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  SwingUp_X.StateSpace_CSTATE[2] = SwingUp_P.x0_ob[2];

  /* InitializeConditions for Delay: '<S1>/Delay One Step2' */
  SwingUp_DW.DelayOneStep2_DSTATE[3] = SwingUp_P.x0_KF[3];

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  SwingUp_X.StateSpace_CSTATE[3] = SwingUp_P.x0_ob[3];
}

/* Model terminate function */
void SwingUp_terminate(void)
{
  /* (no terminate code required) */
}
