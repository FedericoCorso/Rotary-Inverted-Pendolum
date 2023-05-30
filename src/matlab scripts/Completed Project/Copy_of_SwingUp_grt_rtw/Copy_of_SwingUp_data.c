/*
 * Copy_of_SwingUp_data.c
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

/* Block parameters (default storage) */
P_Copy_of_SwingUp_T Copy_of_SwingUp_P = {
  /* Variable: A_kf
   * Referenced by: '<S8>/Observer//KF'
   */
  { -66.197337592042743, 3.3672651614224081, -702.38222680475747,
    380.87176408231448, 6.7345303228447388, -95.014066040468748,
    330.38662473701231, -1810.067594429361, 1.0, 0.0, -16.516438440699947,
    -15.426308706494137, 0.0, 1.0, -0.0694941867778583, -0.52215050431323717 },

  /* Variable: B_kf
   * Referenced by: '<S8>/Observer//KF'
   */
  { 0.0, 0.0, 27.220834936533798, 25.424186000338189, 66.197337592042743,
    -3.3672651614224081, 702.38222680475747, -380.87176408231448,
    -6.7345303228447388, 95.014066040468748, -323.9395579868833,
    1858.5081807719514 },

  /* Variable: C_kf
   * Referenced by: '<S8>/Observer//KF'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Variable: E
   * Referenced by: '<S9>/Constant4'
   */
  { 9.0, 0.0, 0.0, 0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 7500.0, 0.0, 0.0, 0.0, 0.0,
    3700.0 },

  /* Variable: J_a
   * Referenced by: '<S21>/Constant1'
   */
  0.00010027221223893214,

  /* Variable: Jp_prime
   * Referenced by:
   *   '<S14>/gain '
   *   '<S20>/Gain'
   *   '<S21>/Gain'
   *   '<S22>/Gain'
   *   '<S23>/Gain1'
   */
  0.00085863051868094486,

  /* Variable: K_g
   * Referenced by: '<S16>/Gain'
   */
  70.0,

  /* Variable: K_lq_en_alpha_eta
   * Referenced by: '<S8>/Gain3'
   */
  16.894389627343923,

  /* Variable: K_lq_en_alpha_x
   * Referenced by: '<S8>/LQinf gain1'
   */
  { -13.875211645820437, 45.557933054969219, -5.3167839574367921,
    6.7077912271208033 },

  /* Variable: P0
   * Referenced by: '<S9>/Delay One Step3'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Variable: R
   * Referenced by: '<S9>/Constant5'
   */
  { 0.003, 0.0, 0.0, 0.0015 },

  /* Variable: Ts
   * Referenced by: '<S9>/Constant3'
   */
  0.002,

  /* Variable: c1_tau
   * Referenced by:
   *   '<S16>/Gain'
   *   '<S16>/Torque - Voltage proportionality parameter'
   */
  0.14363228924676441,

  /* Variable: g
   * Referenced by:
   *   '<S14>/gain 1'
   *   '<S17>/Energy in Upright position '
   *   '<S20>/Gain'
   *   '<S23>/Gain'
   */
  9.81,

  /* Variable: id_param
   * Referenced by:
   *   '<S4>/Constant'
   *   '<S9>/Constant2'
   */
  { 0.0003926028993067168, 0.002104494180305947, 0.00010027221223893214,
    0.000750089811121891, 0.029234418766626285, 0.127, 0.216, 9.81, 70.0,
    2.3833700802778, 0.93393533431031961, 0.70774626692785614,
    0.00845864677078897, 0.0073986269738176179 },

  /* Variable: k_m
   * Referenced by: '<S16>/Gain'
   */
  0.00845864677078897,

  /* Variable: l_p
   * Referenced by:
   *   '<S14>/Gain'
   *   '<S14>/gain '
   *   '<S17>/Energy in Upright position '
   *   '<S17>/Gain2'
   *   '<S19>/Gain'
   *   '<S23>/Gain'
   */
  0.029234418766626285,

  /* Variable: m_p
   * Referenced by:
   *   '<S14>/gain '
   *   '<S17>/Energy in Upright position '
   *   '<S18>/Gain'
   *   '<S19>/Gain'
   *   '<S21>/Constant1'
   *   '<S21>/Gain1'
   *   '<S23>/Gain'
   */
  0.127,

  /* Variable: r
   * Referenced by:
   *   '<S14>/Gain'
   *   '<S14>/gain '
   *   '<S14>/gain 1'
   *   '<S17>/Gain2'
   *   '<S19>/Gain'
   *   '<S20>/Gain'
   *   '<S22>/Gain'
   */
  0.216,

  /* Variable: voltage_max
   * Referenced by: '<Root>/Maximum voltage1'
   */
  10.0,

  /* Variable: x0_KF
   * Referenced by: '<S9>/Delay One Step1'
   */
  { 0.0, 3.1415926535897931, 0.0, 0.0 },

  /* Variable: x0_down
   * Referenced by: '<S4>/Integrator'
   */
  { 0.0, 3.1415926535897931, 0.0, 0.0 },

  /* Variable: x0_ob
   * Referenced by: '<S8>/Observer//KF'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S13>/Constant'
   */
  0.5,

  /* Mask Parameter: CompareToConstant4_const_p
   * Referenced by: '<S12>/Constant'
   */
  0.5,

  /* Mask Parameter: CompareToConstant4_const_g
   * Referenced by: '<S1>/Constant'
   */
  5.0,

  /* Computed Parameter: thetaref_Y0
   * Referenced by: '<S3>/theta ref'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S14>/proportional gain to be tuned'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S14>/derivative gain to be tuned1'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S18>/Gain1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S7>/Switch'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S8>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S8>/Integrator'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S8>/Integrator'
   */
  -3.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S6>/Constant2'
   */
  6.2831853071795862,

  /* Expression: 1
   * Referenced by: '<S6>/Constant8'
   */
  1.0,

  /* Expression: 2*pi
   * Referenced by: '<S6>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 0.5
   * Referenced by: '<Root>/Relay1'
   */
  0.5,

  /* Expression: 0.3
   * Referenced by: '<Root>/Relay1'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<Root>/Relay1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Relay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant1'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S5>/Constant2'
   */
  6.2831853071795862,

  /* Expression: 1
   * Referenced by: '<S5>/Constant8'
   */
  1.0,

  /* Expression: 2*pi
   * Referenced by: '<S5>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 0.0
   * Referenced by: '<S9>/Delay One Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant'
   */
  1.0,

  /* Expression: 400
   * Referenced by: '<S17>/Gain1'
   */
  400.0,

  /* Expression: 100
   * Referenced by: '<S17>/Kp'
   */
  100.0,

  /* Expression: 2
   * Referenced by: '<S17>/Kd'
   */
  2.0,

  /* Expression: 0.6
   * Referenced by: '<S7>/Relay'
   */
  0.6,

  /* Expression: 0.5
   * Referenced by: '<S7>/Relay'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S7>/Relay'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Relay'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S14>/Tunable small parameter,  angle from the vertical'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay One Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<S8>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S8>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S8>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting_g
   * Referenced by: '<S7>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting_m
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};
