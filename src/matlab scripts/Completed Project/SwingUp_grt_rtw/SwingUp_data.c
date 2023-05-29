/*
 * SwingUp_data.c
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

/* Block parameters (default storage) */
P_SwingUp_T SwingUp_P = {
  /* Variable: A_ob
   * Referenced by: '<Root>/State-Space'
   */
  { -72.97655571220362, 15.833011873197488, -811.91459552048627,
    1219.9575728556772, 1.4913893491808197, -89.984855342780776,
    17.586971179196439, -2001.7292558273798, 1.0, 0.0, -16.516438440699947,
    -15.426308706494137, 0.0, 1.0, -0.0694941867778583, -0.52215050431323717 },

  /* Variable: B_ob
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, 0.0, 27.220834936533798, 25.424186000338189, 72.97655571220362,
    -15.833011873197488, 811.91459552048627, -1219.9575728556772,
    -1.4913893491808197, 89.984855342780776, -11.139904429067457,
    2050.1698421699703 },

  /* Variable: C_ob
   * Referenced by: '<Root>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Variable: E
   * Referenced by: '<S1>/Constant4'
   */
  { 0.01, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 2000.0, 0.0, 0.0, 0.0,
    0.0, 2000.0 },

  /* Variable: J_a
   * Referenced by: '<S19>/Constant1'
   */
  0.00010027221223893214,

  /* Variable: Jp_prime
   * Referenced by:
   *   '<S18>/Gain'
   *   '<S19>/Gain'
   *   '<S20>/Gain'
   *   '<S22>/Gain1'
   */
  0.00085863051868094486,

  /* Variable: K_g
   * Referenced by: '<S5>/Gain'
   */
  70.0,

  /* Variable: Kd
   * Referenced by: '<S6>/Kd'
   */
  2.0,

  /* Variable: Kp
   * Referenced by: '<S6>/Kp'
   */
  100.0,

  /* Variable: Kpp
   * Referenced by: '<Root>/LQinf gain1'
   */
  { -22.485952918903955, 56.699124849244541, -6.6979520343272165,
    8.0272484551409971 },

  /* Variable: P0
   * Referenced by: '<S1>/Delay One Step1'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Variable: R
   * Referenced by: '<S1>/Constant5'
   */
  { 0.001, 0.0, 0.0, 0.001 },

  /* Variable: Ts
   * Referenced by: '<S1>/Constant3'
   */
  0.002,

  /* Variable: c1_tau
   * Referenced by:
   *   '<S5>/Gain'
   *   '<S5>/Gain1'
   */
  0.14363228924676441,

  /* Variable: g
   * Referenced by:
   *   '<S6>/Constant'
   *   '<S18>/Gain'
   *   '<S22>/Gain'
   */
  9.81,

  /* Variable: id_param
   * Referenced by:
   *   '<S1>/Constant2'
   *   '<S4>/Constant'
   */
  { 0.0003926028993067168, 0.002104494180305947, 0.00010027221223893214,
    0.000750089811121891, 0.029234418766626285, 0.127, 0.216, 9.81, 70.0,
    2.3833700802778, 0.93393533431031961, 0.70774626692785614,
    0.00845864677078897, 0.0073986269738176179 },

  /* Variable: k_m
   * Referenced by: '<S5>/Gain'
   */
  0.00845864677078897,

  /* Variable: l_p
   * Referenced by:
   *   '<S6>/Constant'
   *   '<S6>/Gain1'
   *   '<S6>/Gain2'
   *   '<S17>/Gain'
   *   '<S22>/Gain'
   */
  0.029234418766626285,

  /* Variable: m_p
   * Referenced by:
   *   '<S6>/Constant'
   *   '<S6>/Gain1'
   *   '<S16>/Gain'
   *   '<S17>/Gain'
   *   '<S19>/Constant1'
   *   '<S19>/Gain1'
   *   '<S22>/Gain'
   */
  0.127,

  /* Variable: r
   * Referenced by:
   *   '<S6>/Gain1'
   *   '<S6>/Gain2'
   *   '<S17>/Gain'
   *   '<S18>/Gain'
   *   '<S20>/Gain'
   */
  0.216,

  /* Variable: voltage_max
   * Referenced by: '<Root>/Maximum voltage1'
   */
  10.0,

  /* Variable: x0_KF
   * Referenced by: '<S1>/Delay One Step2'
   */
  { 0.0, 3.1415926535897931, 0.0, 0.0 },

  /* Variable: x0_down
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  { 0.0, 3.1415926535897931, 0.0, 0.0 },

  /* Variable: x0_ob
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: p.R{2}
   * Referenced by: '<S2>/R2'
   */
  0.031622776601683791,

  /* Expression: 1
   * Referenced by: '<S2>/MeasurementFcn2Inputs'
   */
  1.0,

  /* Expression: p.R{1}
   * Referenced by: '<S2>/R1'
   */
  0.031622776601683791,

  /* Expression: 0
   * Referenced by: '<S2>/MeasurementFcn1Inputs'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay One Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S22>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S16>/Gain1'
   */
  2.0,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Constant3'
   */
  6.2831853071795862,

  /* Expression: 0.26
   * Referenced by: '<Root>/Switch'
   */
  0.26,

  /* Expression: p.Q
   * Referenced by: '<S2>/Q'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 },

  /* Expression: p.InitialCovariance
   * Referenced by: '<S2>/DataStoreMemory - P'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Expression: p.InitialState
   * Referenced by: '<S2>/DataStoreMemory - x'
   */
  { 0.0, 3.1415926535897931, 0.0, 0.0 },

  /* Computed Parameter: yBlockOrdering_Y0
   * Referenced by: '<S8>/yBlockOrdering'
   */
  false,

  /* Computed Parameter: yBlockOrdering_Y0_n
   * Referenced by: '<S9>/yBlockOrdering'
   */
  false,

  /* Expression: true()
   * Referenced by: '<S2>/BlockOrdering'
   */
  true,

  /* Expression: true()
   * Referenced by: '<S2>/Enable1'
   */
  true,

  /* Expression: true()
   * Referenced by: '<S2>/Enable2'
   */
  true,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};
