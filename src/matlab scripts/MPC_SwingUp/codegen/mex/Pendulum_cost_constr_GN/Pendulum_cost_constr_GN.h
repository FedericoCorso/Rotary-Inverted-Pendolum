/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Pendulum_cost_constr_GN.h
 *
 * Code generation for function 'Pendulum_cost_constr_GN'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Pendulum_cost_constr_GN(const emlrtStack *sp, const real_T U[1500],
                             const real_T z0[4], real_T Ts, const real_T Q[16],
                             real_T R, real_T Qf, real_T usat, real_T xsat,
                             real_T alpha, real_T beta,
                             const real_T parameters[14], real_T F[13505],
                             real_T zsim[6004]);

/* End of code generation (Pendulum_cost_constr_GN.h) */
