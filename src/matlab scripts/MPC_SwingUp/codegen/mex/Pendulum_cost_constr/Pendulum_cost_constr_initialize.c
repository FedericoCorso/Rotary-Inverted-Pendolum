/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Pendulum_cost_constr_initialize.c
 *
 * Code generation for function 'Pendulum_cost_constr_initialize'
 *
 */

/* Include files */
#include "Pendulum_cost_constr_initialize.h"
#include "Pendulum_cost_constr_data.h"
#include "_coder_Pendulum_cost_constr_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void Pendulum_cost_constr_once(void);

/* Function Definitions */
static void Pendulum_cost_constr_once(void)
{
  mex_InitInfAndNan();
}

void Pendulum_cost_constr_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    Pendulum_cost_constr_once();
  }
}

/* End of code generation (Pendulum_cost_constr_initialize.c) */
