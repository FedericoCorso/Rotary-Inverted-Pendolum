/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Pendulum_cost_constr_GN_api.c
 *
 * Code generation for function '_coder_Pendulum_cost_constr_GN_api'
 *
 */

/* Include files */
#include "_coder_Pendulum_cost_constr_GN_api.h"
#include "Pendulum_cost_constr_GN.h"
#include "Pendulum_cost_constr_GN_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[1500];

static const mxArray *b_emlrt_marshallOut(const real_T u[6004]);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z0,
                                   const char_T *identifier))[4];

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4];

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ts,
                                 const char_T *identifier);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *U,
                                 const char_T *identifier))[1500];

static const mxArray *emlrt_marshallOut(const real_T u[13505]);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q,
                                   const char_T *identifier))[16];

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16];

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *parameters,
                                   const char_T *identifier))[14];

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[14];

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[1500];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16];

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[14];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[1500]
{
  real_T(*y)[1500];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const real_T u[6004])
{
  static const int32_T i = 0;
  static const int32_T i1 = 6004;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z0,
                                   const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(z0), &thisId);
  emlrtDestroyArray(&z0);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ts,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(Ts), &thisId);
  emlrtDestroyArray(&Ts);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *U,
                                 const char_T *identifier))[1500]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[1500];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(U), &thisId);
  emlrtDestroyArray(&U);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[13505])
{
  static const int32_T i = 0;
  static const int32_T i1 = 13505;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q,
                                   const char_T *identifier))[16]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[16];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(Q), &thisId);
  emlrtDestroyArray(&Q);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16]
{
  real_T(*y)[16];
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *parameters,
                                   const char_T *identifier))[14]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[14];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(parameters), &thisId);
  emlrtDestroyArray(&parameters);
  return y;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[14]
{
  real_T(*y)[14];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[1500]
{
  static const int32_T dims = 1500;
  real_T(*ret)[1500];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  ret = (real_T(*)[1500])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims = 4;
  real_T(*ret)[4];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16]
{
  static const int32_T dims[2] = {4, 4};
  real_T(*ret)[16];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  ret = (real_T(*)[16])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[14]
{
  static const int32_T dims = 14;
  real_T(*ret)[14];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  ret = (real_T(*)[14])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void Pendulum_cost_constr_GN_api(const mxArray *const prhs[11], int32_T nlhs,
                                 const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*F)[13505];
  real_T(*zsim)[6004];
  real_T(*U)[1500];
  real_T(*Q)[16];
  real_T(*parameters)[14];
  real_T(*z0)[4];
  real_T Qf;
  real_T R;
  real_T Ts;
  real_T alpha;
  real_T beta;
  real_T usat;
  real_T xsat;
  st.tls = emlrtRootTLSGlobal;
  F = (real_T(*)[13505])mxMalloc(sizeof(real_T[13505]));
  zsim = (real_T(*)[6004])mxMalloc(sizeof(real_T[6004]));
  /* Marshall function inputs */
  U = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "U");
  z0 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "z0");
  Ts = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Ts");
  Q = g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Q");
  R = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "R");
  Qf = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Qf");
  usat = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "usat");
  xsat = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "xsat");
  alpha = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "alpha");
  beta = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "beta");
  parameters = i_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "parameters");
  /* Invoke the target function */
  Pendulum_cost_constr_GN(&st, *U, *z0, Ts, *Q, R, Qf, usat, xsat, alpha, beta,
                          *parameters, *F, *zsim);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*F);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*zsim);
  }
}

/* End of code generation (_coder_Pendulum_cost_constr_GN_api.c) */
