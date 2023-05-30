/*
 * Copy_of_SwingUp.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Copy_of_SwingUp".
 *
 * Model version              : 1.110
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue May 30 09:49:49 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_of_SwingUp.h"
#include "rtwtypes.h"
#include <string.h>
#include "Copy_of_SwingUp_private.h"
#include <math.h>
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_Copy_of_SwingUp_T Copy_of_SwingUp_B;

/* Continuous states */
X_Copy_of_SwingUp_T Copy_of_SwingUp_X;

/* Block states (default storage) */
DW_Copy_of_SwingUp_T Copy_of_SwingUp_DW;

/* Real-time model */
static RT_MODEL_Copy_of_SwingUp_T Copy_of_SwingUp_M_;
RT_MODEL_Copy_of_SwingUp_T *const Copy_of_SwingUp_M = &Copy_of_SwingUp_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Copy_of_SwingUp_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
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

/* Model step function */
void Copy_of_SwingUp_step(void)
{
  __m128d tmp_1;
  real_T P_temp[16];
  real_T c[16];
  real_T tmp[16];
  real_T tmp_0[16];
  real_T A_tmp_0[8];
  real_T B[8];
  real_T K[8];
  real_T A[4];
  real_T x[4];
  real_T b_x;
  real_T rtb_Abs;
  real_T rtb_ManualSwitch;
  real_T rtb_ManualSwitch_tmp;
  real_T rtb_Referencetheta;
  real_T rtb_Referencetheta_tmp;
  real_T t10;
  real_T t11;
  real_T t13;
  real_T t15;
  real_T t16;
  real_T t16_tmp;
  real_T t18;
  real_T t2;
  real_T t20;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t27;
  real_T t27_tmp;
  real_T t29;
  real_T t3;
  real_T t30;
  real_T t32;
  real_T t37;
  real_T t38;
  real_T t5;
  real_T t7;
  real_T tau;
  real_T tau_tmp;
  real_T tau_tmp_0;
  real_T tmp_3;
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
  real_T x_tmp_b;
  real_T x_tmp_c;
  real_T x_tmp_tmp;
  int32_T A_tmp_tmp;
  int32_T i;
  int32_T r1;
  int32_T r2;
  int8_T A_tmp[8];
  static const int8_T b[8] = { 1, 0, 0, 0, 0, 1, 0, 0 };

  static const int8_T a[8] = { 1, 0, 0, 1, 0, 0, 0, 0 };

  static const int8_T c_0[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  real_T t15_tmp;
  real_T t16_tmp_0;
  real_T t18_tmp;
  real_T t20_tmp;
  real_T x_tmp_d;
  real_T x_tmp_e;
  real_T x_tmp_tmp_0;
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
    /* set solver stop time */
    if (!(Copy_of_SwingUp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Copy_of_SwingUp_M->solverInfo,
                            ((Copy_of_SwingUp_M->Timing.clockTickH0 + 1) *
        Copy_of_SwingUp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Copy_of_SwingUp_M->solverInfo,
                            ((Copy_of_SwingUp_M->Timing.clockTick0 + 1) *
        Copy_of_SwingUp_M->Timing.stepSize0 +
        Copy_of_SwingUp_M->Timing.clockTickH0 *
        Copy_of_SwingUp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Copy_of_SwingUp_M)) {
    Copy_of_SwingUp_M->Timing.t[0] = rtsiGetT(&Copy_of_SwingUp_M->solverInfo);
  }

  /* Integrator: '<S4>/Integrator' */
  Copy_of_SwingUp_B.Integrator[0] = Copy_of_SwingUp_X.Integrator_CSTATE[0];
  Copy_of_SwingUp_B.Integrator[1] = Copy_of_SwingUp_X.Integrator_CSTATE[1];
  Copy_of_SwingUp_B.Integrator[2] = Copy_of_SwingUp_X.Integrator_CSTATE[2];
  Copy_of_SwingUp_B.Integrator[3] = Copy_of_SwingUp_X.Integrator_CSTATE[3];

  /* Product: '<S6>/Divide2' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Math: '<S6>/Mod1'
   */
  rtb_Referencetheta = rt_modd_snf(Copy_of_SwingUp_B.Integrator[1],
    Copy_of_SwingUp_P.Constant2_Value) / Copy_of_SwingUp_P.Constant2_Value;

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant8'
   *  RelationalOperator: '<S13>/Compare'
   */
  if (rtb_Referencetheta <= Copy_of_SwingUp_P.CompareToConstant4_const) {
    tau = Copy_of_SwingUp_P.Constant1_Value_k;
  } else {
    tau = Copy_of_SwingUp_P.Constant8_Value;
  }

  /* Sum: '<S6>/Sum5' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Gain: '<S6>/Gain2'
   *  Product: '<S6>/Divide1'
   *  Sum: '<S6>/Sum2'
   *  Sum: '<S6>/Sum6'
   *  Switch: '<S6>/Switch5'
   */
  Copy_of_SwingUp_B.signaltobefedtotheobserverforLQ =
    Copy_of_SwingUp_B.Integrator[1] - ((Copy_of_SwingUp_B.Integrator[1] /
    Copy_of_SwingUp_P.Constant2_Value - rtb_Referencetheta) + tau) *
    Copy_of_SwingUp_P.Gain2_Gain;

  /* Abs: '<Root>/Abs' */
  rtb_Abs = fabs(Copy_of_SwingUp_B.signaltobefedtotheobserverforLQ);

  /* Relay: '<Root>/Relay1' */
  if (rtsiIsModeUpdateTimeStep(&Copy_of_SwingUp_M->solverInfo)) {
    Copy_of_SwingUp_DW.Relay1_Mode = ((rtb_Abs >= Copy_of_SwingUp_P.Relay1_OnVal)
      || ((!(rtb_Abs <= Copy_of_SwingUp_P.Relay1_OffVal)) &&
          Copy_of_SwingUp_DW.Relay1_Mode));
  }

  if (Copy_of_SwingUp_DW.Relay1_Mode) {
    /* Relay: '<Root>/Relay1' */
    Copy_of_SwingUp_B.Relay1 = Copy_of_SwingUp_P.Relay1_YOn;
  } else {
    /* Relay: '<Root>/Relay1' */
    Copy_of_SwingUp_B.Relay1 = Copy_of_SwingUp_P.Relay1_YOff;
  }

  /* End of Relay: '<Root>/Relay1' */
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
  }

  /* Product: '<S5>/Divide2' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Math: '<S5>/Mod1'
   */
  rtb_ManualSwitch = rt_modd_snf(Copy_of_SwingUp_B.Integrator[0],
    Copy_of_SwingUp_P.Constant2_Value_h) / Copy_of_SwingUp_P.Constant2_Value_h;

  /* Switch: '<S5>/Switch5' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant8'
   *  RelationalOperator: '<S12>/Compare'
   */
  if (rtb_ManualSwitch <= Copy_of_SwingUp_P.CompareToConstant4_const_p) {
    tau = Copy_of_SwingUp_P.Constant1_Value_b;
  } else {
    tau = Copy_of_SwingUp_P.Constant8_Value_n;
  }

  /* Sum: '<S5>/Sum5' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Gain: '<S5>/Gain2'
   *  Product: '<S5>/Divide1'
   *  Sum: '<S5>/Sum2'
   *  Sum: '<S5>/Sum6'
   *  Switch: '<S5>/Switch5'
   */
  Copy_of_SwingUp_B.signaltobefedtotheobserverfor_j =
    Copy_of_SwingUp_B.Integrator[0] - ((Copy_of_SwingUp_B.Integrator[0] /
    Copy_of_SwingUp_P.Constant2_Value_h - rtb_ManualSwitch) + tau) *
    Copy_of_SwingUp_P.Gain2_Gain_e;
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
    /* Delay: '<S9>/Delay One Step' */
    Copy_of_SwingUp_B.DelayOneStep = Copy_of_SwingUp_DW.DelayOneStep_DSTATE;

    /* Delay: '<S9>/Delay One Step3' */
    memcpy(&Copy_of_SwingUp_B.DelayOneStep3[0],
           &Copy_of_SwingUp_DW.DelayOneStep3_DSTATE[0], sizeof(real_T) << 4U);

    /* Delay: '<S9>/Delay One Step1' */
    Copy_of_SwingUp_B.DelayOneStep1[0] =
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[0];
    Copy_of_SwingUp_B.DelayOneStep1[1] =
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[1];
    Copy_of_SwingUp_B.DelayOneStep1[2] =
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[2];
    Copy_of_SwingUp_B.DelayOneStep1[3] =
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[3];
  }

  /* MATLAB Function: '<S9>/EKF' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   *  Delay: '<S9>/Delay One Step3'
   *  MATLAB Function: '<S4>/MATLAB Function'
   */
  tau_tmp = Copy_of_SwingUp_P.id_param[8] * Copy_of_SwingUp_P.id_param[10] *
    Copy_of_SwingUp_P.id_param[11] * Copy_of_SwingUp_P.id_param[13];
  tau_tmp_0 = Copy_of_SwingUp_P.id_param[8] * Copy_of_SwingUp_P.id_param[12];
  tau = (Copy_of_SwingUp_B.DelayOneStep - tau_tmp_0 *
         Copy_of_SwingUp_B.DelayOneStep1[2]) * tau_tmp /
    Copy_of_SwingUp_P.id_param[9];
  t2 = cos(Copy_of_SwingUp_B.DelayOneStep1[1]);
  t3 = sin(Copy_of_SwingUp_B.DelayOneStep1[1]);
  rtb_Referencetheta_tmp = Copy_of_SwingUp_P.id_param[4] *
    Copy_of_SwingUp_P.id_param[4];
  rtb_Abs = rt_powd_snf(Copy_of_SwingUp_P.id_param[4], 3.0);
  rtb_ManualSwitch = Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param
    [5];
  rtb_ManualSwitch_tmp = Copy_of_SwingUp_P.id_param[6] *
    Copy_of_SwingUp_P.id_param[6];
  t10 = Copy_of_SwingUp_B.DelayOneStep1[2] * Copy_of_SwingUp_B.DelayOneStep1[2];
  t11 = Copy_of_SwingUp_B.DelayOneStep1[3] * Copy_of_SwingUp_B.DelayOneStep1[3];
  t13 = t2 * t2;
  rtb_Referencetheta = sin(Copy_of_SwingUp_B.DelayOneStep1[1] * 2.0);
  t15_tmp = Copy_of_SwingUp_P.id_param[2] * Copy_of_SwingUp_P.id_param[5] *
    rtb_Referencetheta_tmp;
  t16_tmp = Copy_of_SwingUp_P.id_param[3] * Copy_of_SwingUp_P.id_param[5];
  t16_tmp_0 = t16_tmp * rtb_Referencetheta_tmp;
  t20_tmp = rtb_Referencetheta_tmp * rtb_ManualSwitch * rtb_ManualSwitch_tmp;
  t18_tmp = rtb_Referencetheta_tmp * rtb_Referencetheta_tmp * rtb_ManualSwitch;
  t21 = t13 * t18_tmp;
  t27_tmp = Copy_of_SwingUp_P.id_param[2] * Copy_of_SwingUp_P.id_param[3];
  t16_tmp *= rtb_ManualSwitch_tmp;
  t27 = 1.0 / ((((((((t27_tmp + t15_tmp) + t16_tmp_0) + t16_tmp) + t18_tmp) +
                  t20_tmp) - t13 * t16_tmp_0) - t21) - t13 * t20_tmp);
  x_tmp_3 = Copy_of_SwingUp_P.id_param[6] * t2 * rtb_Abs * rtb_ManualSwitch;
  x_tmp_4 = Copy_of_SwingUp_P.id_param[1] * Copy_of_SwingUp_P.id_param[3];
  x_tmp_5 = Copy_of_SwingUp_P.id_param[6] * Copy_of_SwingUp_P.id_param[7];
  x_tmp_6 = Copy_of_SwingUp_P.id_param[0] * Copy_of_SwingUp_P.id_param[4] *
    Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[6];
  x_tmp_tmp = Copy_of_SwingUp_P.id_param[3] * Copy_of_SwingUp_P.id_param[4];
  x_tmp_7 = x_tmp_tmp * Copy_of_SwingUp_P.id_param[5] *
    Copy_of_SwingUp_P.id_param[6];
  x_tmp_d = Copy_of_SwingUp_P.id_param[5] * rtb_Referencetheta_tmp;
  x_tmp_e = Copy_of_SwingUp_P.id_param[1] * Copy_of_SwingUp_P.id_param[5] *
    rtb_Referencetheta_tmp;
  x[2] = ((((((((((x_tmp_4 * Copy_of_SwingUp_B.DelayOneStep1[2] * 2.0 +
                   Copy_of_SwingUp_P.id_param[3] * tau * -2.0) - x_tmp_d * tau *
                  2.0) + rtb_Referencetheta * t16_tmp_0 *
                 Copy_of_SwingUp_B.DelayOneStep1[2] *
                 Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0) + rtb_Referencetheta *
                t18_tmp * Copy_of_SwingUp_B.DelayOneStep1[2] *
                Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0) + x_tmp_e *
               Copy_of_SwingUp_B.DelayOneStep1[2] * 2.0) +
              Copy_of_SwingUp_P.id_param[6] * t3 * rtb_Abs * rtb_ManualSwitch *
              t11 * 2.0) - x_tmp_5 * t2 * t3 * rtb_Referencetheta_tmp *
             rtb_ManualSwitch * 2.0) - x_tmp_3 * t10 * rtb_Referencetheta) +
           x_tmp_6 * t2 * Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0) + x_tmp_7 *
          t3 * t11 * 2.0) * t27 * -0.5;
  x_tmp = t10 * rtb_Referencetheta;
  x_tmp_0 = Copy_of_SwingUp_P.id_param[0] * Copy_of_SwingUp_P.id_param[5];
  x_tmp_tmp_0 = x_tmp_0 * rtb_Referencetheta_tmp;
  x_tmp_2 = Copy_of_SwingUp_P.id_param[7] * t3 * rtb_Abs * rtb_ManualSwitch;
  x_tmp_8 = Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[7];
  x_tmp_9 = Copy_of_SwingUp_P.id_param[0] * Copy_of_SwingUp_P.id_param[2];
  x_tmp_a = Copy_of_SwingUp_P.id_param[2] * Copy_of_SwingUp_P.id_param[7] *
    Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[5];
  x_tmp_b = Copy_of_SwingUp_P.id_param[1] * Copy_of_SwingUp_P.id_param[4] *
    Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[6];
  x_tmp_c = Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[5] *
    Copy_of_SwingUp_P.id_param[6];
  x_tmp_0 *= rtb_ManualSwitch_tmp;
  x[3] = (((((((((((((((x_tmp_9 * Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0 -
                        x_tmp * t15_tmp) - x_tmp * t18_tmp) - x_tmp * t20_tmp) +
                     x_tmp * t21) - x_tmp_2 * 2.0) + t2 * t3 * t11 * t20_tmp *
                   2.0) + x_tmp_tmp_0 * Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0)
                 + x_tmp_0 * Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0) - x_tmp_a
                * t3 * 2.0) - x_tmp_tmp_0 * t13 *
               Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0) - x_tmp_8 * t3 *
              rtb_ManualSwitch * rtb_ManualSwitch_tmp * 2.0) - x_tmp_c * t2 *
             tau * 2.0) + x_tmp_2 * t13 * 2.0) + x_tmp_b * t2 *
           Copy_of_SwingUp_B.DelayOneStep1[2] * 2.0) + x_tmp_3 *
          rtb_Referencetheta * Copy_of_SwingUp_B.DelayOneStep1[2] *
          Copy_of_SwingUp_B.DelayOneStep1[3] * 2.0) * t27 * -0.5;
  x_tmp_3 = Copy_of_SwingUp_P.Ts * Copy_of_SwingUp_B.DelayOneStep1[2] +
    Copy_of_SwingUp_B.DelayOneStep1[0];
  x[0] = x_tmp_3;
  x_tmp = Copy_of_SwingUp_P.Ts * Copy_of_SwingUp_B.DelayOneStep1[3] +
    Copy_of_SwingUp_B.DelayOneStep1[1];
  x[1] = x_tmp;
  x_tmp_1 = Copy_of_SwingUp_P.Ts * x[2] + Copy_of_SwingUp_B.DelayOneStep1[2];
  x[2] = x_tmp_1;
  x_tmp_2 = Copy_of_SwingUp_P.Ts * x[3] + Copy_of_SwingUp_B.DelayOneStep1[3];
  x[3] = x_tmp_2;
  t2 = cos(x_tmp);
  t3 = sin(x_tmp);
  rtb_Referencetheta = Copy_of_SwingUp_P.id_param[8] *
    Copy_of_SwingUp_P.id_param[8];
  t5 = rtb_Referencetheta_tmp;
  t10 = x_tmp * 2.0;
  t7 = x_tmp_1 * x_tmp_1;
  t13 = x_tmp_2 * x_tmp_2;
  t20 = 1.0 / Copy_of_SwingUp_P.id_param[9];
  t15 = cos(t10);
  t16 = cos(x_tmp * 3.0);
  t11 = t2 * t2;
  t18 = sin(t10);
  t10 = t3 * t3;
  t21 = Copy_of_SwingUp_P.id_param[5] * t5;
  t22 = Copy_of_SwingUp_P.id_param[5] * rtb_ManualSwitch_tmp;
  t29 = t5 * rtb_ManualSwitch * rtb_ManualSwitch_tmp;
  t23 = Copy_of_SwingUp_P.id_param[2] * t21;
  t24 = Copy_of_SwingUp_P.id_param[3] * t21;
  t25 = Copy_of_SwingUp_P.id_param[3] * t22;
  t27 = t5 * t5 * rtb_ManualSwitch;
  t32 = (Copy_of_SwingUp_P.id_param[3] + t21) + t22;
  t30 = t11 * t27;
  t37 = 1.0 / ((((((((t27_tmp + t23) + t24) + t25) + t27) + t29) - t11 * t24) -
                t30) - t11 * t29);
  t38 = t37 * t37;
  b_x = cos(x_tmp * 4.0);
  c[0] = 1.0;
  c[1] = 0.0;
  c[2] = 0.0;
  c[3] = 0.0;
  c[4] = 0.0;
  c[5] = 1.0;
  tau = Copy_of_SwingUp_P.id_param[6] * t3;
  tmp_3 = tau * rtb_Abs * rtb_ManualSwitch;
  tmp_4 = Copy_of_SwingUp_P.id_param[6] * t2;
  tmp_b = Copy_of_SwingUp_P.id_param[8] * Copy_of_SwingUp_B.DelayOneStep *
    Copy_of_SwingUp_P.id_param[10] * Copy_of_SwingUp_P.id_param[11] *
    Copy_of_SwingUp_P.id_param[13];
  tmp_c = Copy_of_SwingUp_P.id_param[10] * Copy_of_SwingUp_P.id_param[11] *
    Copy_of_SwingUp_P.id_param[12] * Copy_of_SwingUp_P.id_param[13];
  tmp_d = Copy_of_SwingUp_P.Ts * Copy_of_SwingUp_P.id_param[4] *
    Copy_of_SwingUp_P.id_param[5];
  tmp_e = (((((((t27_tmp * 4.0 + t23 * 4.0) + t24 * 2.0) + t25 * 4.0) + t27 *
              2.0) + t29 * 2.0) - t15 * t24 * 2.0) - t15 * t27 * 2.0) - t15 *
    t29 * 2.0;
  tmp_g = Copy_of_SwingUp_P.Ts * t18 * t21 * t32 * t38;
  tmp_h = Copy_of_SwingUp_P.id_param[1] * t21;
  tmp_i = t18 * t24;
  tmp_j = t18 * t27;
  tmp_k = Copy_of_SwingUp_P.id_param[3] * Copy_of_SwingUp_P.id_param[10] *
    Copy_of_SwingUp_P.id_param[11] * Copy_of_SwingUp_P.id_param[12] *
    Copy_of_SwingUp_P.id_param[13] * rtb_Referencetheta * t20;
  tmp_l = tmp_c * rtb_Referencetheta * t20 * t21;
  tmp_m = tmp_j * x_tmp_1;
  tmp_o = Copy_of_SwingUp_P.id_param[0] * Copy_of_SwingUp_P.id_param[6];
  tmp_p = Copy_of_SwingUp_P.id_param[3] * Copy_of_SwingUp_P.id_param[6];
  tmp_q = Copy_of_SwingUp_P.id_param[5] * rtb_Abs;
  c[6] = ((((((((((((x_tmp_4 * x_tmp_1 * 2.0 + tmp_h * x_tmp_1 * 2.0) + tmp_i *
                    x_tmp_1 * x_tmp_2 * 2.0) + tmp_m * x_tmp_2 * 2.0) - x_tmp_5 *
                  t5 * rtb_ManualSwitch * t18) + tmp_3 * t13 * 2.0) + tmp_3 * t7
                * (t10 - 1.0) * 2.0) + x_tmp_6 * t2 * x_tmp_2 * 2.0) + x_tmp_7 *
              t3 * t13 * 2.0) - tmp_b * t20 * t21 * 2.0) -
            Copy_of_SwingUp_P.id_param[3] * Copy_of_SwingUp_P.id_param[8] *
            Copy_of_SwingUp_B.DelayOneStep * Copy_of_SwingUp_P.id_param[10] *
            Copy_of_SwingUp_P.id_param[11] * Copy_of_SwingUp_P.id_param[13] *
            t20 * 2.0) + tmp_k * x_tmp_1 * 2.0) + tmp_l * x_tmp_1 * 2.0) * tmp_g
    / 2.0 + -((((((((tmp_p * t2 * t13 * 4.0 - tmp_4 * t7 * t21) + tmp_4 * t13 *
                    t21 * 4.0) - Copy_of_SwingUp_P.id_param[6] * t7 * t16 * t21 *
                   3.0) - tmp_o * t3 * x_tmp_2 * 4.0) + x_tmp_tmp * t15 *
                 x_tmp_1 * x_tmp_2 * 8.0) - x_tmp_8 *
                Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[6] *
                t15 * 4.0) + tmp_q * t15 * x_tmp_1 * x_tmp_2 * 8.0) * tmp_d) /
    tmp_e;
  tmp_6 = Copy_of_SwingUp_P.id_param[7] * Copy_of_SwingUp_P.id_param[9];
  tmp_5 = tmp_6 * t2;
  tmp_7 = Copy_of_SwingUp_P.id_param[2] * Copy_of_SwingUp_P.id_param[9];
  tmp_8 = Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[9];
  tmp_9 = Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[9] *
    rtb_Abs * t7;
  tmp_a = Copy_of_SwingUp_P.id_param[6] * Copy_of_SwingUp_P.id_param[9];
  tmp_f = t7 * t18;
  tmp_n = x_tmp_b * t2;
  tmp_r = Copy_of_SwingUp_P.id_param[0] * t21;
  tmp_s = Copy_of_SwingUp_P.id_param[0] * t22;
  tmp_t = Copy_of_SwingUp_P.id_param[0] * t11 * t21;
  c[7] = (((((((((((((((x_tmp_9 * x_tmp_2 * -2.0 - tmp_r * x_tmp_2 * 2.0) -
                       tmp_s * x_tmp_2 * 2.0) + tmp_f * t23) + tmp_f * t27) +
                    tmp_f * t29) - t13 * t18 * t29) + tmp_t * x_tmp_2 * 2.0) +
                 Copy_of_SwingUp_P.id_param[7] * t3 * rtb_Abs * rtb_ManualSwitch
                 * 2.0) - rt_powd_snf(t2, 3.0) * t3 * t7 * t27 * 2.0) -
               Copy_of_SwingUp_P.id_param[7] * rtb_Abs * rtb_ManualSwitch * (t3
    - rt_powd_snf(t3, 3.0)) * 2.0) + x_tmp_a * t3 * 2.0) + x_tmp_8 * t3 *
             rtb_ManualSwitch * rtb_ManualSwitch_tmp * 2.0) - tmp_n * x_tmp_1 *
            2.0) + (t10 - 1.0) * tmp_3 * x_tmp_1 * x_tmp_2 * 4.0) + tau_tmp *
          Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[5] *
          Copy_of_SwingUp_P.id_param[6] * t2 * t20 *
          (Copy_of_SwingUp_B.DelayOneStep - tau_tmp_0 * x_tmp_1) * 2.0) * tmp_g *
    -0.5 + ((((((((((((((tmp_5 * t21 * 3.0 + tmp_5 * t22 * 4.0) - tmp_6 * t16 *
                        t21 * 3.0) + tmp_7 * Copy_of_SwingUp_P.id_param[7] * t2 *
                       4.0) - tmp_9 * b_x * 2.0) - Copy_of_SwingUp_P.id_param[0]
                     * Copy_of_SwingUp_P.id_param[9] *
                     Copy_of_SwingUp_P.id_param[4] * t18 * x_tmp_2 * 4.0) +
                    tmp_7 * Copy_of_SwingUp_P.id_param[4] * t7 * t15 * 4.0) +
                   Copy_of_SwingUp_P.id_param[1] * Copy_of_SwingUp_P.id_param[9]
                   * Copy_of_SwingUp_P.id_param[6] * t3 * x_tmp_1 * 4.0) + tmp_8
                  * t7 * t15 * t22 * 4.0) - tmp_8 * t13 * t15 * t22 * 4.0) +
                tmp_9 * t15 * 2.0) - tmp_a * t2 * t21 * x_tmp_1 * x_tmp_2 * 2.0)
              - tmp_a * t16 * t21 * x_tmp_1 * x_tmp_2 * 6.0) - tmp_b *
             Copy_of_SwingUp_P.id_param[6] * t3 * 4.0) + tmp_c *
            Copy_of_SwingUp_P.id_param[6] * t3 * rtb_Referencetheta * x_tmp_1 *
            4.0) * (tmp_d * t20) / tmp_e;
  c[8] = Copy_of_SwingUp_P.Ts;
  c[9] = 0.0;
  tmp_4 = tmp_4 * rtb_Abs * rtb_ManualSwitch * t18;
  tmp_b = Copy_of_SwingUp_P.Ts * t37;
  tmp_d = ((((((tmp_h * 2.0 + x_tmp_4 * 2.0) + tmp_i * x_tmp_2 * 2.0) + tmp_j *
              x_tmp_2 * 2.0) - tmp_4 * x_tmp_1 * 2.0) + tmp_k * 2.0) + tmp_l *
           2.0) * tmp_b * -0.5 + 1.0;
  c[10] = tmp_d;
  tmp_4 = ((((((t18 * t23 * x_tmp_1 * -2.0 - tmp_m * 2.0) - t18 * t29 * x_tmp_1 *
               2.0) + t18 * t30 * x_tmp_1 * 2.0) + tmp_n * 2.0) + tmp_4 *
            x_tmp_2 * 2.0) + tmp_c * Copy_of_SwingUp_P.id_param[4] *
           Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[6] * t2 *
           rtb_Referencetheta * t20 * 2.0) * tmp_b * -0.5;
  c[11] = tmp_4;
  c[12] = 0.0;
  c[13] = Copy_of_SwingUp_P.Ts;
  tau = ((((x_tmp_tmp * t18 * x_tmp_1 + tmp_o * t2) + tmp_p * t3 * x_tmp_2 * 2.0)
          + tmp_q * t18 * x_tmp_1) + tau * t21 * x_tmp_2 * 2.0) *
    (-Copy_of_SwingUp_P.Ts * Copy_of_SwingUp_P.id_param[4] *
     Copy_of_SwingUp_P.id_param[5] * t37);
  c[14] = tau;
  tmp_3 = (((((tmp_r * 2.0 + tmp_s * 2.0) + x_tmp_9 * 2.0) - tmp_t * 2.0) + t2 *
            t3 * t29 * x_tmp_2 * 4.0) + tmp_3 * t11 * x_tmp_1 * 4.0) * tmp_b *
    -0.5 + 1.0;
  c[15] = tmp_3;
  tmp[0] = 1.0;
  tmp[1] = 0.0;
  tmp[2] = 0.0;
  tmp[3] = 0.0;
  tmp[4] = 0.0;
  tmp[5] = 1.0;
  tmp[6] = ((((((((((((Copy_of_SwingUp_P.id_param[1] *
                       Copy_of_SwingUp_P.id_param[3] * x_tmp_1 * 2.0 +
                       Copy_of_SwingUp_P.id_param[1] * t21 * x_tmp_1 * 2.0) +
                      t18 * t24 * x_tmp_1 * x_tmp_2 * 2.0) + t18 * t27 * x_tmp_1
                     * x_tmp_2 * 2.0) - Copy_of_SwingUp_P.id_param[6] *
                    Copy_of_SwingUp_P.id_param[7] * t5 * rtb_ManualSwitch * t18)
                   + Copy_of_SwingUp_P.id_param[6] * t3 * rtb_Abs *
                   rtb_ManualSwitch * t13 * 2.0) + Copy_of_SwingUp_P.id_param[6]
                  * t3 * rtb_Abs * rtb_ManualSwitch * t7 * (t10 - 1.0) * 2.0) +
                 Copy_of_SwingUp_P.id_param[0] * Copy_of_SwingUp_P.id_param[4] *
                 Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[6] *
                 t2 * x_tmp_2 * 2.0) + Copy_of_SwingUp_P.id_param[3] *
                Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[5] *
                Copy_of_SwingUp_P.id_param[6] * t3 * t13 * 2.0) -
               Copy_of_SwingUp_P.id_param[8] * Copy_of_SwingUp_B.DelayOneStep *
               Copy_of_SwingUp_P.id_param[10] * Copy_of_SwingUp_P.id_param[11] *
               Copy_of_SwingUp_P.id_param[13] * t20 * t21 * 2.0) -
              Copy_of_SwingUp_P.id_param[3] * Copy_of_SwingUp_P.id_param[8] *
              Copy_of_SwingUp_B.DelayOneStep * Copy_of_SwingUp_P.id_param[10] *
              Copy_of_SwingUp_P.id_param[11] * Copy_of_SwingUp_P.id_param[13] *
              t20 * 2.0) + Copy_of_SwingUp_P.id_param[3] *
             Copy_of_SwingUp_P.id_param[10] * Copy_of_SwingUp_P.id_param[11] *
             Copy_of_SwingUp_P.id_param[12] * Copy_of_SwingUp_P.id_param[13] *
             rtb_Referencetheta * t20 * x_tmp_1 * 2.0) +
            Copy_of_SwingUp_P.id_param[10] * Copy_of_SwingUp_P.id_param[11] *
            Copy_of_SwingUp_P.id_param[12] * Copy_of_SwingUp_P.id_param[13] *
            rtb_Referencetheta * t20 * t21 * x_tmp_1 * 2.0) *
    (Copy_of_SwingUp_P.Ts * t18 * t21 * t32 * t38) / 2.0 +
    -((((((((Copy_of_SwingUp_P.id_param[3] * Copy_of_SwingUp_P.id_param[6] * t2 *
             t13 * 4.0 - Copy_of_SwingUp_P.id_param[6] * t2 * t7 * t21) +
            Copy_of_SwingUp_P.id_param[6] * t2 * t13 * t21 * 4.0) -
           Copy_of_SwingUp_P.id_param[6] * t7 * t16 * t21 * 3.0) -
          Copy_of_SwingUp_P.id_param[0] * Copy_of_SwingUp_P.id_param[6] * t3 *
          x_tmp_2 * 4.0) + Copy_of_SwingUp_P.id_param[3] *
         Copy_of_SwingUp_P.id_param[4] * t15 * x_tmp_1 * x_tmp_2 * 8.0) -
        Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[7] *
        Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[6] * t15 *
        4.0) + Copy_of_SwingUp_P.id_param[5] * rtb_Abs * t15 * x_tmp_1 * x_tmp_2
       * 8.0) * (Copy_of_SwingUp_P.Ts * Copy_of_SwingUp_P.id_param[4] *
                 Copy_of_SwingUp_P.id_param[5])) / ((((((((t27_tmp * 4.0 + t23 *
    4.0) + t24 * 2.0) + t25 * 4.0) + t27 * 2.0) + t29 * 2.0) - t15 * t24 * 2.0)
    - t15 * t27 * 2.0) - t15 * t29 * 2.0);
  tmp[7] = ((((((((((((((Copy_of_SwingUp_P.id_param[7] *
    Copy_of_SwingUp_P.id_param[9] * t2 * t21 * 3.0 + Copy_of_SwingUp_P.id_param
    [7] * Copy_of_SwingUp_P.id_param[9] * t2 * t22 * 4.0) -
                        Copy_of_SwingUp_P.id_param[7] *
                        Copy_of_SwingUp_P.id_param[9] * t16 * t21 * 3.0) +
                       Copy_of_SwingUp_P.id_param[2] *
                       Copy_of_SwingUp_P.id_param[9] *
                       Copy_of_SwingUp_P.id_param[7] * t2 * 4.0) -
                      Copy_of_SwingUp_P.id_param[5] *
                      Copy_of_SwingUp_P.id_param[9] * rtb_Abs * t7 * b_x * 2.0)
                     - Copy_of_SwingUp_P.id_param[0] *
                     Copy_of_SwingUp_P.id_param[9] * Copy_of_SwingUp_P.id_param
                     [4] * t18 * x_tmp_2 * 4.0) + Copy_of_SwingUp_P.id_param[2] *
                    Copy_of_SwingUp_P.id_param[9] * Copy_of_SwingUp_P.id_param[4]
                    * t7 * t15 * 4.0) + Copy_of_SwingUp_P.id_param[1] *
                   Copy_of_SwingUp_P.id_param[9] * Copy_of_SwingUp_P.id_param[6]
                   * t3 * x_tmp_1 * 4.0) + Copy_of_SwingUp_P.id_param[4] *
                  Copy_of_SwingUp_P.id_param[9] * t7 * t15 * t22 * 4.0) -
                 Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[9] *
                 t13 * t15 * t22 * 4.0) + Copy_of_SwingUp_P.id_param[5] *
                Copy_of_SwingUp_P.id_param[9] * rtb_Abs * t7 * t15 * 2.0) -
               Copy_of_SwingUp_P.id_param[6] * Copy_of_SwingUp_P.id_param[9] *
               t2 * t21 * x_tmp_1 * x_tmp_2 * 2.0) - Copy_of_SwingUp_P.id_param
              [6] * Copy_of_SwingUp_P.id_param[9] * t16 * t21 * x_tmp_1 *
              x_tmp_2 * 6.0) - Copy_of_SwingUp_P.id_param[8] *
             Copy_of_SwingUp_B.DelayOneStep * Copy_of_SwingUp_P.id_param[10] *
             Copy_of_SwingUp_P.id_param[11] * Copy_of_SwingUp_P.id_param[13] *
             Copy_of_SwingUp_P.id_param[6] * t3 * 4.0) +
            Copy_of_SwingUp_P.id_param[10] * Copy_of_SwingUp_P.id_param[11] *
            Copy_of_SwingUp_P.id_param[12] * Copy_of_SwingUp_P.id_param[13] *
            Copy_of_SwingUp_P.id_param[6] * t3 * rtb_Referencetheta * x_tmp_1 *
            4.0) * (Copy_of_SwingUp_P.Ts * Copy_of_SwingUp_P.id_param[4] *
                    Copy_of_SwingUp_P.id_param[5] * t20) / ((((((((t27_tmp * 4.0
    + t23 * 4.0) + t24 * 2.0) + t25 * 4.0) + t27 * 2.0) + t29 * 2.0) - t15 * t24
    * 2.0) - t15 * t27 * 2.0) - t15 * t29 * 2.0) +
    (((((((((((((((Copy_of_SwingUp_P.id_param[0] * Copy_of_SwingUp_P.id_param[2]
                   * x_tmp_2 * -2.0 - Copy_of_SwingUp_P.id_param[0] * t21 *
                   x_tmp_2 * 2.0) - Copy_of_SwingUp_P.id_param[0] * t22 *
                  x_tmp_2 * 2.0) + t7 * t18 * t23) + t7 * t18 * t27) + t7 * t18 *
               t29) - t13 * t18 * t29) + Copy_of_SwingUp_P.id_param[0] * t11 *
             t21 * x_tmp_2 * 2.0) + Copy_of_SwingUp_P.id_param[7] * t3 * rtb_Abs
            * rtb_ManualSwitch * 2.0) - rt_powd_snf(t2, 3.0) * t3 * t7 * t27 *
           2.0) - Copy_of_SwingUp_P.id_param[7] * rtb_Abs * rtb_ManualSwitch *
          (t3 - rt_powd_snf(t3, 3.0)) * 2.0) + Copy_of_SwingUp_P.id_param[2] *
         Copy_of_SwingUp_P.id_param[7] * Copy_of_SwingUp_P.id_param[4] *
         Copy_of_SwingUp_P.id_param[5] * t3 * 2.0) + Copy_of_SwingUp_P.id_param
        [4] * Copy_of_SwingUp_P.id_param[7] * t3 * rtb_ManualSwitch *
        rtb_ManualSwitch_tmp * 2.0) - Copy_of_SwingUp_P.id_param[1] *
       Copy_of_SwingUp_P.id_param[4] * Copy_of_SwingUp_P.id_param[5] *
       Copy_of_SwingUp_P.id_param[6] * t2 * x_tmp_1 * 2.0) +
      Copy_of_SwingUp_P.id_param[6] * t3 * rtb_Abs * rtb_ManualSwitch * (t10 -
       1.0) * x_tmp_1 * x_tmp_2 * 4.0) + Copy_of_SwingUp_P.id_param[8] *
     Copy_of_SwingUp_P.id_param[10] * Copy_of_SwingUp_P.id_param[11] *
     Copy_of_SwingUp_P.id_param[13] * Copy_of_SwingUp_P.id_param[4] *
     Copy_of_SwingUp_P.id_param[5] * Copy_of_SwingUp_P.id_param[6] * t2 * t20 *
     (Copy_of_SwingUp_B.DelayOneStep - Copy_of_SwingUp_P.id_param[8] *
      Copy_of_SwingUp_P.id_param[12] * x_tmp_1) * 2.0) * (Copy_of_SwingUp_P.Ts *
    t18 * t21 * t32 * t38) * -0.5;
  tmp[8] = Copy_of_SwingUp_P.Ts;
  tmp[9] = 0.0;
  tmp[10] = tmp_d;
  tmp[11] = tmp_4;
  tmp[12] = 0.0;
  tmp[13] = Copy_of_SwingUp_P.Ts;
  tmp[14] = tau;
  tmp[15] = tmp_3;
  for (i = 0; i < 4; i++) {
    for (r1 = 0; r1 < 4; r1++) {
      r2 = r1 << 2;
      A_tmp_tmp = i + r2;
      tmp_0[A_tmp_tmp] = 0.0;
      tmp_0[A_tmp_tmp] += Copy_of_SwingUp_B.DelayOneStep3[r2] * c[i];
      tmp_0[A_tmp_tmp] += Copy_of_SwingUp_B.DelayOneStep3[r2 + 1] * c[i + 4];
      tmp_0[A_tmp_tmp] += Copy_of_SwingUp_B.DelayOneStep3[r2 + 2] * c[i + 8];
      tmp_0[A_tmp_tmp] += Copy_of_SwingUp_B.DelayOneStep3[r2 + 3] * c[i + 12];
    }

    for (r1 = 0; r1 < 4; r1++) {
      r2 = (r1 << 2) + i;
      P_temp[r2] = (((tmp_0[i + 4] * tmp[r1 + 4] + tmp_0[i] * tmp[r1]) + tmp_0[i
                     + 8] * tmp[r1 + 8]) + tmp_0[i + 12] * tmp[r1 + 12]) +
        Copy_of_SwingUp_P.E[r2];
    }
  }

  for (i = 0; i < 8; i++) {
    K[i] = b[i];
    A_tmp[i] = a[i];
  }

  for (i = 0; i < 2; i++) {
    for (r1 = 0; r1 < 4; r1++) {
      r2 = (r1 << 1) + i;
      A_tmp_0[r2] = 0.0;
      A_tmp_tmp = r1 << 2;
      A_tmp_0[r2] += P_temp[A_tmp_tmp] * (real_T)A_tmp[i];
      A_tmp_0[r2] += P_temp[A_tmp_tmp + 1] * (real_T)A_tmp[i + 2];
      A_tmp_0[r2] += P_temp[A_tmp_tmp + 2] * (real_T)A_tmp[i + 4];
      A_tmp_0[r2] += P_temp[A_tmp_tmp + 3] * (real_T)A_tmp[i + 6];
    }

    for (r1 = 0; r1 < 2; r1++) {
      r2 = r1 << 2;
      A_tmp_tmp = (r1 << 1) + i;
      A[A_tmp_tmp] = (((K[r2 + 1] * A_tmp_0[i + 2] + K[r2] * A_tmp_0[i]) + K[r2
                       + 2] * A_tmp_0[i + 4]) + K[r2 + 3] * A_tmp_0[i + 6]) +
        Copy_of_SwingUp_P.R[A_tmp_tmp];
    }

    for (r1 = 0; r1 <= 2; r1 += 2) {
      __m128d tmp_2;
      r2 = i << 2;
      A_tmp_tmp = r1 + r2;
      _mm_storeu_pd(&B[A_tmp_tmp], _mm_set1_pd(0.0));
      tmp_1 = _mm_loadu_pd(&P_temp[r1]);
      tmp_2 = _mm_loadu_pd(&B[A_tmp_tmp]);
      _mm_storeu_pd(&B[A_tmp_tmp], _mm_add_pd(tmp_2, _mm_mul_pd(_mm_set1_pd(K[r2]),
        tmp_1)));
      tmp_1 = _mm_loadu_pd(&P_temp[r1 + 4]);
      tmp_2 = _mm_loadu_pd(&B[A_tmp_tmp]);
      _mm_storeu_pd(&B[A_tmp_tmp], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(K[r2 + 1]),
        tmp_1), tmp_2));
      tmp_1 = _mm_loadu_pd(&P_temp[r1 + 8]);
      tmp_2 = _mm_loadu_pd(&B[A_tmp_tmp]);
      _mm_storeu_pd(&B[A_tmp_tmp], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(K[r2 + 2]),
        tmp_1), tmp_2));
      tmp_1 = _mm_loadu_pd(&P_temp[r1 + 12]);
      tmp_2 = _mm_loadu_pd(&B[A_tmp_tmp]);
      _mm_storeu_pd(&B[A_tmp_tmp], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(K[r2 + 3]),
        tmp_1), tmp_2));
    }
  }

  if (fabs(A[1]) > fabs(A[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  t2 = A[r2] / A[r1];
  x_tmp_tmp = A[r1 + 2];
  t3 = A[r2 + 2] - x_tmp_tmp * t2;
  t5 = Copy_of_SwingUp_B.Integrator[0] - x_tmp_3;
  t13 = Copy_of_SwingUp_B.Integrator[1] - x_tmp;
  for (A_tmp_tmp = 0; A_tmp_tmp < 4; A_tmp_tmp++) {
    int32_T K_tmp;
    int32_T c_tmp;
    i = (r1 << 2) + A_tmp_tmp;
    K[i] = B[A_tmp_tmp] / A[r1];
    K_tmp = (r2 << 2) + A_tmp_tmp;
    K[K_tmp] = (B[A_tmp_tmp + 4] - K[i] * x_tmp_tmp) / t3;
    K[i] -= K[K_tmp] * t2;
    t11 = K[A_tmp_tmp + 4];
    Copy_of_SwingUp_B.x_hat[A_tmp_tmp] = (t11 * t13 + K[A_tmp_tmp] * t5) +
      x[A_tmp_tmp];
    for (i = 0; i < 4; i++) {
      K_tmp = i << 1;
      c_tmp = (i << 2) + A_tmp_tmp;
      c[c_tmp] = (real_T)c_0[c_tmp] - ((real_T)A_tmp[K_tmp + 1] * t11 + (real_T)
        A_tmp[K_tmp] * K[A_tmp_tmp]);
    }

    for (i = 0; i < 4; i++) {
      K_tmp = i << 2;
      c_tmp = A_tmp_tmp + K_tmp;
      Copy_of_SwingUp_B.P_new[c_tmp] = 0.0;
      Copy_of_SwingUp_B.P_new[c_tmp] += P_temp[K_tmp] * c[A_tmp_tmp];
      Copy_of_SwingUp_B.P_new[c_tmp] += P_temp[K_tmp + 1] * c[A_tmp_tmp + 4];
      Copy_of_SwingUp_B.P_new[c_tmp] += P_temp[K_tmp + 2] * c[A_tmp_tmp + 8];
      Copy_of_SwingUp_B.P_new[c_tmp] += P_temp[K_tmp + 3] * c[A_tmp_tmp + 12];
    }
  }

  /* End of MATLAB Function: '<S9>/EKF' */

  /* Trigonometry: '<S23>/Cos' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function'
   */
  t2 = cos(Copy_of_SwingUp_B.Integrator[1]);

  /* Sum: '<S23>/Sum1' incorporates:
   *  Constant: '<S23>/Constant'
   *  Gain: '<S23>/Gain'
   *  Gain: '<S23>/Gain1'
   *  Math: '<S23>/Square'
   *  Sum: '<S23>/Sum'
   *  Trigonometry: '<S23>/Cos'
   */
  Copy_of_SwingUp_B.Sum1 = Copy_of_SwingUp_P.g * Copy_of_SwingUp_P.m_p *
    Copy_of_SwingUp_P.l_p * (t2 + Copy_of_SwingUp_P.Constant_Value_g) + 0.5 *
    Copy_of_SwingUp_P.Jp_prime * (Copy_of_SwingUp_B.x_hat[3] *
    Copy_of_SwingUp_B.x_hat[3]);

  /* Sum: '<S17>/Sum' incorporates:
   *  Constant: '<S17>/Energy in Upright position '
   */
  Copy_of_SwingUp_B.Sum = Copy_of_SwingUp_B.Sum1 - 2.0 * Copy_of_SwingUp_P.m_p *
    Copy_of_SwingUp_P.g * Copy_of_SwingUp_P.l_p;

  /* Trigonometry: '<S17>/Sin' incorporates:
   *  Switch: '<Root>/Switch'
   *  Switch: '<S7>/Switch'
   *  Trigonometry: '<S14>/Sin'
   */
  t3 = sin(Copy_of_SwingUp_B.Integrator[1]);

  /* Math: '<S17>/Square' incorporates:
   *  Math: '<S22>/Square'
   *  Switch: '<Root>/Switch'
   */
  t11 = Copy_of_SwingUp_B.x_hat[2] * Copy_of_SwingUp_B.x_hat[2];

  /* Gain: '<S17>/Gain2' incorporates:
   *  Gain: '<S14>/Gain'
   *  Switch: '<Root>/Switch'
   *  Switch: '<S7>/Switch'
   */
  rtb_Referencetheta = Copy_of_SwingUp_P.l_p / Copy_of_SwingUp_P.r;

  /* Sum: '<S17>/Sum1' incorporates:
   *  Gain: '<S17>/Gain1'
   *  Gain: '<S17>/Gain2'
   *  Gain: '<S17>/Kd'
   *  Gain: '<S17>/Kp'
   *  Math: '<S17>/Square'
   *  Product: '<S17>/Product'
   *  Product: '<S17>/Product1'
   *  Product: '<S17>/Product2'
   *  Sum: '<S17>/Sum2'
   *  Trigonometry: '<S17>/Sin'
   *  Trigonometry: '<S23>/Cos'
   */
  Copy_of_SwingUp_B.desiredaccelerationsignal = (0.0 - t2 *
    Copy_of_SwingUp_B.x_hat[3] * Copy_of_SwingUp_B.Sum *
    Copy_of_SwingUp_P.Gain1_Gain_b) - (t11 * t3 * rtb_Referencetheta +
    (Copy_of_SwingUp_P.Kp_Gain * Copy_of_SwingUp_B.Integrator[0] +
     Copy_of_SwingUp_P.Kd_Gain * Copy_of_SwingUp_B.x_hat[2]));

  /* Relay: '<S7>/Relay' */
  if (rtsiIsModeUpdateTimeStep(&Copy_of_SwingUp_M->solverInfo)) {
    Copy_of_SwingUp_DW.Relay_Mode = ((Copy_of_SwingUp_B.Integrator[1] >=
      Copy_of_SwingUp_P.Relay_OnVal) || ((!(Copy_of_SwingUp_B.Integrator[1] <=
      Copy_of_SwingUp_P.Relay_OffVal)) && Copy_of_SwingUp_DW.Relay_Mode));
  }

  if (Copy_of_SwingUp_DW.Relay_Mode) {
    t5 = Copy_of_SwingUp_P.Relay_YOn;
  } else {
    t5 = Copy_of_SwingUp_P.Relay_YOff;
  }

  /* End of Relay: '<S7>/Relay' */

  /* Outputs for Enabled SubSystem: '<Root>/Hold Theta Value uprigth' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
    /* ManualSwitch: '<S7>/Manual Switch' */
    if (Copy_of_SwingUp_P.ManualSwitch_CurrentSetting_g == 1) {
      /* ManualSwitch: '<S7>/Manual Switch' incorporates:
       *  Constant: '<S7>/Constant'
       */
      Copy_of_SwingUp_B.ManualSwitch = Copy_of_SwingUp_P.Constant_Value;
    } else {
      /* ManualSwitch: '<S7>/Manual Switch' */
      Copy_of_SwingUp_B.ManualSwitch = t5;
    }

    /* End of ManualSwitch: '<S7>/Manual Switch' */

    /* Logic: '<Root>/NOT' */
    Copy_of_SwingUp_B.NOT = !(Copy_of_SwingUp_B.Relay1 != 0.0);
    if (rtsiIsModeUpdateTimeStep(&Copy_of_SwingUp_M->solverInfo)) {
      Copy_of_SwingUp_DW.HoldThetaValueuprigth_MODE = (Copy_of_SwingUp_B.Relay1 >
        0.0);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Hold Theta Value uprigth' */

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Clock: '<Root>/Clock'
   *  Constant: '<Root>/Constant'
   *  Constant: '<S1>/Constant'
   *  Logic: '<Root>/AND'
   *  Logic: '<Root>/NOT1'
   *  RelationalOperator: '<S1>/Compare'
   */
  if (Copy_of_SwingUp_P.ManualSwitch1_CurrentSetting_m == 1) {
    t13 = ((!(Copy_of_SwingUp_M->Timing.t[0] >=
              Copy_of_SwingUp_P.CompareToConstant4_const_g)) ||
           (!Copy_of_SwingUp_B.NOT));
  } else {
    t13 = Copy_of_SwingUp_P.Constant_Value_j;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Outputs for Enabled SubSystem: '<Root>/Hold Theta Value uprigth' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (Copy_of_SwingUp_DW.HoldThetaValueuprigth_MODE) {
    /* SignalConversion generated from: '<S3>/In1' */
    Copy_of_SwingUp_B.In1 = Copy_of_SwingUp_B.signaltobefedtotheobserverfor_j;
  }

  /* End of Outputs for SubSystem: '<Root>/Hold Theta Value uprigth' */
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
    /* Delay: '<Root>/Delay One Step' */
    Copy_of_SwingUp_B.DelayOneStep_j = Copy_of_SwingUp_DW.DelayOneStep_DSTATE_b;
  }

  for (r1 = 0; r1 <= 2; r1 += 2) {
    /* Outputs for Atomic SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
    /* StateSpace: '<S8>/Observer//KF' */
    _mm_storeu_pd(&Copy_of_SwingUp_B.x_est[r1], _mm_set1_pd(0.0));

    /* StateSpace: '<S8>/Observer//KF' */
    tmp_1 = _mm_loadu_pd(&Copy_of_SwingUp_B.x_est[r1]);

    /* StateSpace: '<S8>/Observer//KF' */
    _mm_storeu_pd(&Copy_of_SwingUp_B.x_est[r1], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.C_kf[r1]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[0])), tmp_1));

    /* StateSpace: '<S8>/Observer//KF' */
    tmp_1 = _mm_loadu_pd(&Copy_of_SwingUp_B.x_est[r1]);

    /* StateSpace: '<S8>/Observer//KF' */
    _mm_storeu_pd(&Copy_of_SwingUp_B.x_est[r1], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.C_kf[r1 + 4]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[1])), tmp_1));

    /* StateSpace: '<S8>/Observer//KF' */
    tmp_1 = _mm_loadu_pd(&Copy_of_SwingUp_B.x_est[r1]);

    /* StateSpace: '<S8>/Observer//KF' */
    _mm_storeu_pd(&Copy_of_SwingUp_B.x_est[r1], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.C_kf[r1 + 8]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[2])), tmp_1));

    /* StateSpace: '<S8>/Observer//KF' */
    tmp_1 = _mm_loadu_pd(&Copy_of_SwingUp_B.x_est[r1]);

    /* StateSpace: '<S8>/Observer//KF' */
    _mm_storeu_pd(&Copy_of_SwingUp_B.x_est[r1], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.C_kf[r1 + 12]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[3])), tmp_1));

    /* End of Outputs for SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
  }

  /* Sum: '<S8>/Sum1' */
  Copy_of_SwingUp_B.error = Copy_of_SwingUp_B.signaltobefedtotheobserverfor_j -
    Copy_of_SwingUp_B.In1;
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
  }

  /* Integrator: '<S8>/Integrator' */
  /* Limited  Integrator  */
  if (Copy_of_SwingUp_X.Integrator_CSTATE_b >=
      Copy_of_SwingUp_P.Integrator_UpperSat) {
    Copy_of_SwingUp_X.Integrator_CSTATE_b =
      Copy_of_SwingUp_P.Integrator_UpperSat;
  } else if (Copy_of_SwingUp_X.Integrator_CSTATE_b <=
             Copy_of_SwingUp_P.Integrator_LowerSat) {
    Copy_of_SwingUp_X.Integrator_CSTATE_b =
      Copy_of_SwingUp_P.Integrator_LowerSat;
  }

  /* ManualSwitch: '<S8>/Manual Switch1' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Gain: '<S8>/Gain'
   */
  if (Copy_of_SwingUp_P.ManualSwitch1_CurrentSetting == 1) {
    tau = Copy_of_SwingUp_P.Gain_Gain * Copy_of_SwingUp_B.In1;
  } else {
    tau = Copy_of_SwingUp_P.Constant1_Value;
  }

  /* Sum: '<S8>/Sum2' incorporates:
   *  ManualSwitch: '<S8>/Manual Switch1'
   */
  Copy_of_SwingUp_B.Sum2 = tau - Copy_of_SwingUp_B.error;

  /* SignalConversion generated from: '<S8>/Observer//KF' */
  Copy_of_SwingUp_B.TmpSignalConversionAtObserverKF[0] =
    Copy_of_SwingUp_B.DelayOneStep_j;
  Copy_of_SwingUp_B.TmpSignalConversionAtObserverKF[1] = Copy_of_SwingUp_B.error;
  Copy_of_SwingUp_B.TmpSignalConversionAtObserverKF[2] =
    Copy_of_SwingUp_B.signaltobefedtotheobserverforLQ;

  /* End of Outputs for SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */

  /* Switch: '<Root>/Switch' incorporates:
   *  ManualSwitch: '<S8>/Manual Switch2'
   *  SignalConversion generated from: '<S8>/LQinf gain1'
   */
  if (t13 > Copy_of_SwingUp_P.Switch_Threshold_j) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S14>/Tunable small parameter,  angle from the vertical'
     *  Gain: '<S14>/Gain'
     *  Gain: '<S14>/derivative gain to be tuned1'
     *  Gain: '<S14>/gain '
     *  Gain: '<S14>/gain 1'
     *  Gain: '<S14>/proportional gain to be tuned'
     *  Math: '<S14>/Square'
     *  Product: '<S14>/Divide'
     *  Product: '<S14>/Divide1'
     *  Product: '<S14>/Product'
     *  Product: '<S14>/Product1'
     *  Signum: '<S14>/Sign'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S14>/Sum1'
     *  Sum: '<S14>/Sum2'
     *  Sum: '<S14>/Sum4'
     *  Trigonometry: '<S17>/Sin'
     *  Trigonometry: '<S23>/Cos'
     */
    if (Copy_of_SwingUp_B.ManualSwitch > Copy_of_SwingUp_P.Switch_Threshold) {
      rtb_Referencetheta = Copy_of_SwingUp_B.desiredaccelerationsignal;
    } else {
      if (rtIsNaN(Copy_of_SwingUp_B.x_hat[2])) {
        /* Signum: '<S14>/Sign' */
        tau = (rtNaN);
      } else if (Copy_of_SwingUp_B.x_hat[2] < 0.0) {
        /* Signum: '<S14>/Sign' */
        tau = -1.0;
      } else {
        /* Signum: '<S14>/Sign' */
        tau = (Copy_of_SwingUp_B.x_hat[2] > 0.0);
      }

      rtb_Referencetheta = (0.0 - Copy_of_SwingUp_B.x_hat[2] *
                            Copy_of_SwingUp_B.x_hat[2] * t3 * rtb_Referencetheta)
        - (((Copy_of_SwingUp_B.Integrator[1] -
             Copy_of_SwingUp_P.Tunablesmallparameteranglefromt * tau) *
            Copy_of_SwingUp_P.proportionalgaintobetuned_Gain +
            Copy_of_SwingUp_P.derivativegaintobetuned1_Gain *
            Copy_of_SwingUp_B.x_hat[3]) / (Copy_of_SwingUp_P.m_p *
            Copy_of_SwingUp_P.l_p * Copy_of_SwingUp_P.r /
            Copy_of_SwingUp_P.Jp_prime * t2) + Copy_of_SwingUp_P.g /
           Copy_of_SwingUp_P.r * (t3 / t2));
    }

    /* Math: '<S21>/Square1' incorporates:
     *  Math: '<S22>/Square1'
     *  Trigonometry: '<S23>/Cos'
     */
    t13 = t2 * t2;

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<S21>/Constant1'
     *  Gain: '<S16>/Gain'
     *  Gain: '<S16>/Torque - Voltage proportionality parameter'
     *  Gain: '<S18>/Gain'
     *  Gain: '<S18>/Gain1'
     *  Gain: '<S19>/Gain'
     *  Gain: '<S20>/Gain'
     *  Gain: '<S21>/Gain'
     *  Gain: '<S21>/Gain1'
     *  Gain: '<S22>/Gain'
     *  Math: '<S19>/Square'
     *  Math: '<S21>/Square'
     *  Math: '<S21>/Square1'
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Product: '<S19>/Product'
     *  Product: '<S20>/Product'
     *  Product: '<S21>/Product'
     *  Product: '<S22>/Product'
     *  Product: '<S22>/Product1'
     *  Sum: '<S15>/Add'
     *  Sum: '<S16>/Sum'
     *  Sum: '<S21>/Sum'
     *  Trigonometry: '<S17>/Sin'
     *  Trigonometry: '<S18>/Sin'
     *  Trigonometry: '<S23>/Cos'
     */
    Copy_of_SwingUp_B.voltage_no_sat = ((((((((Copy_of_SwingUp_P.m_p *
      0.046655999999999996 + Copy_of_SwingUp_P.J_a) + 0.00085465124062247106 *
      Copy_of_SwingUp_P.m_p * (t3 * t3)) - 6.4313755698815234E-7 /
      Copy_of_SwingUp_P.Jp_prime * t13) * rtb_Referencetheta +
      Copy_of_SwingUp_P.l_p * Copy_of_SwingUp_P.m_p * Copy_of_SwingUp_P.r * t3 *
      (Copy_of_SwingUp_B.x_hat[3] * Copy_of_SwingUp_B.x_hat[3])) + sin
      (Copy_of_SwingUp_P.Gain1_Gain * Copy_of_SwingUp_B.Integrator[1]) *
      (Copy_of_SwingUp_B.x_hat[2] * Copy_of_SwingUp_B.x_hat[3]) *
      (0.00085465124062247106 * Copy_of_SwingUp_P.m_p)) - 4.0298681124692695E-7 *
      Copy_of_SwingUp_P.r / Copy_of_SwingUp_P.Jp_prime * (t13 * t3) * t11) -
      Copy_of_SwingUp_P.g * 0.00085465124062247106 * 0.016129 *
      Copy_of_SwingUp_P.r / Copy_of_SwingUp_P.Jp_prime * (t2 * t3)) +
      Copy_of_SwingUp_P.K_g * Copy_of_SwingUp_P.k_m * Copy_of_SwingUp_P.c1_tau *
      Copy_of_SwingUp_B.x_hat[2]) * (1.0 / Copy_of_SwingUp_P.c1_tau);
  } else {
    /* Outputs for Atomic SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
    if (Copy_of_SwingUp_P.ManualSwitch2_CurrentSetting == 1) {
      /* SignalConversion generated from: '<S8>/LQinf gain1' incorporates:
       *  ManualSwitch: '<S8>/Manual Switch2'
       */
      t13 = Copy_of_SwingUp_B.x_hat[2];
      t11 = Copy_of_SwingUp_B.x_hat[3];
    } else {
      /* SignalConversion generated from: '<S8>/LQinf gain1' incorporates:
       *  ManualSwitch: '<S8>/Manual Switch2'
       */
      t13 = Copy_of_SwingUp_B.x_est[2];
      t11 = Copy_of_SwingUp_B.x_est[3];
    }

    /* ManualSwitch: '<S8>/Manual Switch' incorporates:
     *  Constant: '<S8>/Constant'
     *  Gain: '<S8>/Gain3'
     *  Integrator: '<S8>/Integrator'
     */
    if (Copy_of_SwingUp_P.ManualSwitch_CurrentSetting == 1) {
      tau = Copy_of_SwingUp_P.K_lq_en_alpha_eta *
        Copy_of_SwingUp_X.Integrator_CSTATE_b;
    } else {
      tau = Copy_of_SwingUp_P.Constant_Value_c;
    }

    /* Switch: '<Root>/Switch' incorporates:
     *  Gain: '<S8>/LQinf gain1'
     *  ManualSwitch: '<S8>/Manual Switch'
     *  SignalConversion generated from: '<S8>/LQinf gain1'
     *  Sum: '<S8>/Sum'
     */
    Copy_of_SwingUp_B.voltage_no_sat = (0.0 - tau) -
      (((Copy_of_SwingUp_P.K_lq_en_alpha_x[0] * Copy_of_SwingUp_B.error +
         Copy_of_SwingUp_P.K_lq_en_alpha_x[1] *
         Copy_of_SwingUp_B.signaltobefedtotheobserverforLQ) +
        Copy_of_SwingUp_P.K_lq_en_alpha_x[2] * t13) +
       Copy_of_SwingUp_P.K_lq_en_alpha_x[3] * t11);

    /* End of Outputs for SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
  }

  /* Saturate: '<Root>/Maximum voltage1' */
  if (Copy_of_SwingUp_B.voltage_no_sat > Copy_of_SwingUp_P.voltage_max) {
    /* Saturate: '<Root>/Maximum voltage1' */
    Copy_of_SwingUp_B.voltage_sat = Copy_of_SwingUp_P.voltage_max;
  } else if (Copy_of_SwingUp_B.voltage_no_sat < -Copy_of_SwingUp_P.voltage_max)
  {
    /* Saturate: '<Root>/Maximum voltage1' */
    Copy_of_SwingUp_B.voltage_sat = -Copy_of_SwingUp_P.voltage_max;
  } else {
    /* Saturate: '<Root>/Maximum voltage1' */
    Copy_of_SwingUp_B.voltage_sat = Copy_of_SwingUp_B.voltage_no_sat;
  }

  /* End of Saturate: '<Root>/Maximum voltage1' */
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S4>/Constant'
   *  Trigonometry: '<S17>/Sin'
   */
  tau = (Copy_of_SwingUp_B.voltage_sat - tau_tmp_0 *
         Copy_of_SwingUp_B.Integrator[2]) * tau_tmp /
    Copy_of_SwingUp_P.id_param[9];
  t10 = Copy_of_SwingUp_B.Integrator[2] * Copy_of_SwingUp_B.Integrator[2];
  t11 = Copy_of_SwingUp_B.Integrator[3] * Copy_of_SwingUp_B.Integrator[3];
  t13 = t2 * t2;
  rtb_Referencetheta = sin(Copy_of_SwingUp_B.Integrator[1] * 2.0);
  t21 = t13 * t18_tmp;
  t27 = 1.0 / ((((((((t27_tmp + t15_tmp) + t16_tmp_0) + t16_tmp) + t18_tmp) +
                  t20_tmp) - t13 * t16_tmp_0) - t21) - t13 * t20_tmp);
  Copy_of_SwingUp_B.x_dot[0] = Copy_of_SwingUp_B.Integrator[2];
  Copy_of_SwingUp_B.x_dot[1] = Copy_of_SwingUp_B.Integrator[3];
  tau_tmp = Copy_of_SwingUp_P.id_param[6] * t2 * rtb_Abs * rtb_ManualSwitch;
  Copy_of_SwingUp_B.x_dot[2] = ((((((((((x_tmp_4 * Copy_of_SwingUp_B.Integrator
    [2] * 2.0 + Copy_of_SwingUp_P.id_param[3] * tau * -2.0) - x_tmp_d * tau *
    2.0) + rtb_Referencetheta * t16_tmp_0 * Copy_of_SwingUp_B.Integrator[2] *
    Copy_of_SwingUp_B.Integrator[3] * 2.0) + rtb_Referencetheta * t18_tmp *
    Copy_of_SwingUp_B.Integrator[2] * Copy_of_SwingUp_B.Integrator[3] * 2.0) +
    x_tmp_e * Copy_of_SwingUp_B.Integrator[2] * 2.0) +
    Copy_of_SwingUp_P.id_param[6] * t3 * rtb_Abs * rtb_ManualSwitch * t11 * 2.0)
    - x_tmp_5 * t2 * t3 * rtb_Referencetheta_tmp * rtb_ManualSwitch * 2.0) -
    tau_tmp * t10 * rtb_Referencetheta) + x_tmp_6 * t2 *
    Copy_of_SwingUp_B.Integrator[3] * 2.0) + x_tmp_7 * t3 * t11 * 2.0) * t27 *
    -0.5;
  x_tmp_4 = t10 * rtb_Referencetheta;
  rtb_Abs = Copy_of_SwingUp_P.id_param[7] * t3 * rtb_Abs * rtb_ManualSwitch;
  Copy_of_SwingUp_B.x_dot[3] = (((((((((((((((x_tmp_9 *
    Copy_of_SwingUp_B.Integrator[3] * 2.0 - x_tmp_4 * t15_tmp) - x_tmp_4 *
    t18_tmp) - x_tmp_4 * t20_tmp) + x_tmp_4 * t21) - rtb_Abs * 2.0) + t2 * t3 *
    t11 * t20_tmp * 2.0) + x_tmp_tmp_0 * Copy_of_SwingUp_B.Integrator[3] * 2.0)
    + x_tmp_0 * Copy_of_SwingUp_B.Integrator[3] * 2.0) - x_tmp_a * t3 * 2.0) -
    x_tmp_tmp_0 * t13 * Copy_of_SwingUp_B.Integrator[3] * 2.0) - x_tmp_8 * t3 *
    rtb_ManualSwitch * rtb_ManualSwitch_tmp * 2.0) - x_tmp_c * t2 * tau * 2.0) +
    rtb_Abs * t13 * 2.0) + x_tmp_b * t2 * Copy_of_SwingUp_B.Integrator[2] * 2.0)
    + tau_tmp * rtb_Referencetheta * Copy_of_SwingUp_B.Integrator[2] *
    Copy_of_SwingUp_B.Integrator[3] * 2.0) * t27 * -0.5;
  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
  }

  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Copy_of_SwingUp_M->rtwLogInfo,
                        (Copy_of_SwingUp_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
    if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
      /* Update for Delay: '<S9>/Delay One Step' */
      Copy_of_SwingUp_DW.DelayOneStep_DSTATE = Copy_of_SwingUp_B.voltage_sat;

      /* Update for Delay: '<S9>/Delay One Step3' */
      memcpy(&Copy_of_SwingUp_DW.DelayOneStep3_DSTATE[0],
             &Copy_of_SwingUp_B.P_new[0], sizeof(real_T) << 4U);

      /* Update for Delay: '<S9>/Delay One Step1' */
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[0] = Copy_of_SwingUp_B.x_hat[0];
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[1] = Copy_of_SwingUp_B.x_hat[1];
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[2] = Copy_of_SwingUp_B.x_hat[2];
      Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[3] = Copy_of_SwingUp_B.x_hat[3];

      /* Update for Delay: '<Root>/Delay One Step' */
      Copy_of_SwingUp_DW.DelayOneStep_DSTATE_b = Copy_of_SwingUp_B.voltage_sat;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Copy_of_SwingUp_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Copy_of_SwingUp_M)!=-1) &&
          !((rtmGetTFinal(Copy_of_SwingUp_M)-
             (((Copy_of_SwingUp_M->Timing.clockTick1+
                Copy_of_SwingUp_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((Copy_of_SwingUp_M->Timing.clockTick1+
               Copy_of_SwingUp_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(Copy_of_SwingUp_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Copy_of_SwingUp_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Copy_of_SwingUp_M->Timing.clockTick0)) {
      ++Copy_of_SwingUp_M->Timing.clockTickH0;
    }

    Copy_of_SwingUp_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Copy_of_SwingUp_M->solverInfo);

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
      Copy_of_SwingUp_M->Timing.clockTick1++;
      if (!Copy_of_SwingUp_M->Timing.clockTick1) {
        Copy_of_SwingUp_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Copy_of_SwingUp_derivatives(void)
{
  XDot_Copy_of_SwingUp_T *_rtXdot;
  int32_T i;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_Copy_of_SwingUp_T *) Copy_of_SwingUp_M->derivs);
  for (i = 0; i <= 2; i += 2) {
    __m128d tmp;

    /* Derivatives for Integrator: '<S4>/Integrator' */
    tmp = _mm_loadu_pd(&Copy_of_SwingUp_B.x_dot[i]);
    _mm_storeu_pd(&_rtXdot->Integrator_CSTATE[i], tmp);

    /* Derivatives for Atomic SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
    /* Derivatives for StateSpace: '<S8>/Observer//KF' incorporates:
     *  Integrator: '<S4>/Integrator'
     */
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_set1_pd(0.0));
    tmp = _mm_loadu_pd(&_rtXdot->ObserverKF_CSTATE[i]);
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.A_kf[i]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[0])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->ObserverKF_CSTATE[i]);
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.A_kf[i + 4]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[1])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->ObserverKF_CSTATE[i]);
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.A_kf[i + 8]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[2])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->ObserverKF_CSTATE[i]);
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.A_kf[i + 12]), _mm_set1_pd
       (Copy_of_SwingUp_X.ObserverKF_CSTATE[3])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->ObserverKF_CSTATE[i]);
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.B_kf[i]), _mm_set1_pd
       (Copy_of_SwingUp_B.TmpSignalConversionAtObserverKF[0])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->ObserverKF_CSTATE[i]);
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.B_kf[i + 4]), _mm_set1_pd
       (Copy_of_SwingUp_B.TmpSignalConversionAtObserverKF[1])), tmp));
    tmp = _mm_loadu_pd(&_rtXdot->ObserverKF_CSTATE[i]);
    _mm_storeu_pd(&_rtXdot->ObserverKF_CSTATE[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&Copy_of_SwingUp_P.B_kf[i + 8]), _mm_set1_pd
       (Copy_of_SwingUp_B.TmpSignalConversionAtObserverKF[2])), tmp));

    /* End of Derivatives for SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
  }

  /* Derivatives for Atomic SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
  /* Derivatives for Integrator: '<S8>/Integrator' */
  lsat = (Copy_of_SwingUp_X.Integrator_CSTATE_b <=
          Copy_of_SwingUp_P.Integrator_LowerSat);
  usat = (Copy_of_SwingUp_X.Integrator_CSTATE_b >=
          Copy_of_SwingUp_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Copy_of_SwingUp_B.Sum2 > 0.0)) || (usat &&
       (Copy_of_SwingUp_B.Sum2 < 0.0))) {
    _rtXdot->Integrator_CSTATE_b = Copy_of_SwingUp_B.Sum2;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_b = 0.0;
  }

  /* End of Derivatives for Integrator: '<S8>/Integrator' */
  /* End of Derivatives for SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
}

/* Model initialize function */
void Copy_of_SwingUp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Copy_of_SwingUp_M, 0,
                sizeof(RT_MODEL_Copy_of_SwingUp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Copy_of_SwingUp_M->solverInfo,
                          &Copy_of_SwingUp_M->Timing.simTimeStep);
    rtsiSetTPtr(&Copy_of_SwingUp_M->solverInfo, &rtmGetTPtr(Copy_of_SwingUp_M));
    rtsiSetStepSizePtr(&Copy_of_SwingUp_M->solverInfo,
                       &Copy_of_SwingUp_M->Timing.stepSize0);
    rtsiSetdXPtr(&Copy_of_SwingUp_M->solverInfo, &Copy_of_SwingUp_M->derivs);
    rtsiSetContStatesPtr(&Copy_of_SwingUp_M->solverInfo, (real_T **)
                         &Copy_of_SwingUp_M->contStates);
    rtsiSetNumContStatesPtr(&Copy_of_SwingUp_M->solverInfo,
      &Copy_of_SwingUp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Copy_of_SwingUp_M->solverInfo,
      &Copy_of_SwingUp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Copy_of_SwingUp_M->solverInfo,
      &Copy_of_SwingUp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Copy_of_SwingUp_M->solverInfo,
      &Copy_of_SwingUp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Copy_of_SwingUp_M->solverInfo, (&rtmGetErrorStatus
      (Copy_of_SwingUp_M)));
    rtsiSetRTModelPtr(&Copy_of_SwingUp_M->solverInfo, Copy_of_SwingUp_M);
  }

  rtsiSetSimTimeStep(&Copy_of_SwingUp_M->solverInfo, MAJOR_TIME_STEP);
  Copy_of_SwingUp_M->intgData.f[0] = Copy_of_SwingUp_M->odeF[0];
  Copy_of_SwingUp_M->contStates = ((X_Copy_of_SwingUp_T *) &Copy_of_SwingUp_X);
  rtsiSetSolverData(&Copy_of_SwingUp_M->solverInfo, (void *)
                    &Copy_of_SwingUp_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Copy_of_SwingUp_M->solverInfo, false);
  rtsiSetSolverName(&Copy_of_SwingUp_M->solverInfo,"ode1");
  rtmSetTPtr(Copy_of_SwingUp_M, &Copy_of_SwingUp_M->Timing.tArray[0]);
  rtmSetTFinal(Copy_of_SwingUp_M, 10.0);
  Copy_of_SwingUp_M->Timing.stepSize0 = 0.002;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Copy_of_SwingUp_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Copy_of_SwingUp_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Copy_of_SwingUp_M->rtwLogInfo, (NULL));
    rtliSetLogT(Copy_of_SwingUp_M->rtwLogInfo, "tout");
    rtliSetLogX(Copy_of_SwingUp_M->rtwLogInfo, "");
    rtliSetLogXFinal(Copy_of_SwingUp_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Copy_of_SwingUp_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Copy_of_SwingUp_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Copy_of_SwingUp_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Copy_of_SwingUp_M->rtwLogInfo, 1);
    rtliSetLogY(Copy_of_SwingUp_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Copy_of_SwingUp_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Copy_of_SwingUp_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Copy_of_SwingUp_B), 0,
                sizeof(B_Copy_of_SwingUp_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Copy_of_SwingUp_X, 0,
                  sizeof(X_Copy_of_SwingUp_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Copy_of_SwingUp_DW, 0,
                sizeof(DW_Copy_of_SwingUp_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Copy_of_SwingUp_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Copy_of_SwingUp_M), Copy_of_SwingUp_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Copy_of_SwingUp_M)));

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Copy_of_SwingUp_X.Integrator_CSTATE[0] = Copy_of_SwingUp_P.x0_down[0];
  Copy_of_SwingUp_X.Integrator_CSTATE[1] = Copy_of_SwingUp_P.x0_down[1];
  Copy_of_SwingUp_X.Integrator_CSTATE[2] = Copy_of_SwingUp_P.x0_down[2];
  Copy_of_SwingUp_X.Integrator_CSTATE[3] = Copy_of_SwingUp_P.x0_down[3];

  /* InitializeConditions for Delay: '<S9>/Delay One Step' */
  Copy_of_SwingUp_DW.DelayOneStep_DSTATE =
    Copy_of_SwingUp_P.DelayOneStep_InitialCondition;

  /* InitializeConditions for Delay: '<S9>/Delay One Step3' */
  memcpy(&Copy_of_SwingUp_DW.DelayOneStep3_DSTATE[0], &Copy_of_SwingUp_P.P0[0],
         sizeof(real_T) << 4U);

  /* InitializeConditions for Delay: '<S9>/Delay One Step1' */
  Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[0] = Copy_of_SwingUp_P.x0_KF[0];
  Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[1] = Copy_of_SwingUp_P.x0_KF[1];
  Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[2] = Copy_of_SwingUp_P.x0_KF[2];
  Copy_of_SwingUp_DW.DelayOneStep1_DSTATE[3] = Copy_of_SwingUp_P.x0_KF[3];

  /* InitializeConditions for Delay: '<Root>/Delay One Step' */
  Copy_of_SwingUp_DW.DelayOneStep_DSTATE_b =
    Copy_of_SwingUp_P.DelayOneStep_InitialCondition_h;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Hold Theta Value uprigth' */
  /* SystemInitialize for SignalConversion generated from: '<S3>/In1' incorporates:
   *  Outport: '<S3>/theta ref'
   */
  Copy_of_SwingUp_B.In1 = Copy_of_SwingUp_P.thetaref_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Hold Theta Value uprigth' */
  /* InitializeConditions for StateSpace: '<S8>/Observer//KF' */
  Copy_of_SwingUp_X.ObserverKF_CSTATE[0] = Copy_of_SwingUp_P.x0_ob[0];
  Copy_of_SwingUp_X.ObserverKF_CSTATE[1] = Copy_of_SwingUp_P.x0_ob[1];
  Copy_of_SwingUp_X.ObserverKF_CSTATE[2] = Copy_of_SwingUp_P.x0_ob[2];
  Copy_of_SwingUp_X.ObserverKF_CSTATE[3] = Copy_of_SwingUp_P.x0_ob[3];

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  Copy_of_SwingUp_X.Integrator_CSTATE_b = Copy_of_SwingUp_P.Integrator_IC;

  /* End of SystemInitialize for SubSystem: '<Root>/Tracking//Stabilizing LQ//PP Controller' */
}

/* Model terminate function */
void Copy_of_SwingUp_terminate(void)
{
  /* (no terminate code required) */
}
