/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Pendulum_cost_constr_terminate.c
 *
 * Code generation for function 'Pendulum_cost_constr_terminate'
 *
 */

/* Include files */
#include "Pendulum_cost_constr_terminate.h"
#include "Pendulum_cost_constr_data.h"
#include "_coder_Pendulum_cost_constr_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Pendulum_cost_constr_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Pendulum_cost_constr_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Pendulum_cost_constr_terminate.c) */
