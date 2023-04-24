/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Pendulum_cost_constr_GN_mex.c
 *
 * Code generation for function '_coder_Pendulum_cost_constr_GN_mex'
 *
 */

/* Include files */
#include "_coder_Pendulum_cost_constr_GN_mex.h"
#include "Pendulum_cost_constr_GN_data.h"
#include "Pendulum_cost_constr_GN_initialize.h"
#include "Pendulum_cost_constr_GN_terminate.h"
#include "_coder_Pendulum_cost_constr_GN_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Pendulum_cost_constr_GN_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                         int32_T nrhs, const mxArray *prhs[11])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 11) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 11, 4,
                        23, "Pendulum_cost_constr_GN");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "Pendulum_cost_constr_GN");
  }
  /* Call the function. */
  Pendulum_cost_constr_GN_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Pendulum_cost_constr_GN_atexit);
  /* Module initialization. */
  Pendulum_cost_constr_GN_initialize();
  /* Dispatch the entry-point. */
  Pendulum_cost_constr_GN_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  Pendulum_cost_constr_GN_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Pendulum_cost_constr_GN_mex.c) */
