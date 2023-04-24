/*
 * Simulink_Horizontal_Control_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulink_Horizontal_Control".
 *
 * Model version              : 1.74
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Mar 28 17:08:52 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Simulink_Horizontal_Control.h"
#include "Simulink_Horizontal_Control_private.h"

/* Block parameters (default storage) */
P_Simulink_Horizontal_Control_T Simulink_Horizontal_Control_P = {
  /* Variable: A
   * Referenced by: '<S5>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.4470667501289833, -48.44058634259045, 1.0,
    0.0, -16.516438440699947, 15.426308706494137, 0.0, 1.0, 0.0694941867778583,
    -0.52215050431323717 },

  /* Variable: B
   * Referenced by: '<S5>/State-Space'
   */
  { 0.0, 0.0, 27.220834936533798, -25.424186000338189 },

  /* Variable: C
   * Referenced by: '<S5>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Variable: theta_max
   * Referenced by:
   *   '<Root>/Maximum theta'
   *   '<S1>/Switch'
   *   '<S1>/Switch1'
   *   '<S2>/Switch'
   *   '<S2>/Switch1'
   */
  90.0,

  /* Variable: voltage_max
   * Referenced by:
   *   '<Root>/Maximum voltage'
   *   '<Root>/Maximum voltage1'
   */
  10.0,

  /* Mask Parameter: Encoders_clock
   * Referenced by: '<Root>/Encoders'
   */
  0,

  /* Mask Parameter: Encoders_channels
   * Referenced by: '<Root>/Encoders'
   */
  { 0U, 1U },

  /* Mask Parameter: Voltage_channels
   * Referenced by: '<Root>/Voltage'
   */
  0U,

  /* Mask Parameter: Encoders_samples_in_buffer
   * Referenced by: '<Root>/Encoders'
   */
  500U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 2*pi/4096
   * Referenced by: '<S6>/Gain1'
   */
  0.0015339807878856412,

  /* Expression: pi
   * Referenced by: '<S6>/Offset'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S5>/State-Space'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<S5>/Offset'
   */
  3.1415926535897931,

  /* Expression: pi/6
   * Referenced by: '<Root>/Reference theta [rad]'
   */
  0.52359877559829882,

  /* Expression: 0.5
   * Referenced by: '<Root>/Reference theta [rad]'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Sine Wave'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 2*pi/4096
   * Referenced by: '<S6>/Gain'
   */
  0.0015339807878856412,

  /* Computed Parameter: Internal_A
   * Referenced by: '<S3>/Internal'
   */
  { -0.2289342151015718, 6.50894910626306, -6.50894910626306,
    -0.2289342151015718, -3.1496589678408182, 0.59013000194891962,
    -44.729192782951287, 5.3372290129954214, -58.6172163612614 },

  /* Computed Parameter: Internal_B
   * Referenced by: '<S3>/Internal'
   */
  64.0,

  /* Computed Parameter: Internal_C
   * Referenced by: '<S3>/Internal'
   */
  { 2.3255460716786343, 8.2378403619461178, -77.416185379448407,
    14.504939771358995 },

  /* Expression: 0.0
   * Referenced by: '<S3>/Internal'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Computed Parameter: Internal_A_p
   * Referenced by: '<S4>/Internal'
   */
  { -0.2289342151015718, 6.50894910626306, -6.50894910626306,
    -0.2289342151015718, -3.1496589678408182, 0.59013000194891962,
    -44.729192782951287, 5.3372290129954214, -58.6172163612614 },

  /* Computed Parameter: Internal_B_n
   * Referenced by: '<S4>/Internal'
   */
  64.0,

  /* Computed Parameter: Internal_C_n
   * Referenced by: '<S4>/Internal'
   */
  { 2.3255460716786343, 8.2378403619461178, -77.416185379448407,
    14.504939771358995 },

  /* Expression: 0.0
   * Referenced by: '<S4>/Internal'
   */
  0.0,

  /* Computed Parameter: ToHostFile_Decimation
   * Referenced by: '<Root>/To Host File'
   */
  1U,

  /* Computed Parameter: ToHostFile_BitRate
   * Referenced by: '<Root>/To Host File'
   */
  2000000U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: Encoders_Active
   * Referenced by: '<Root>/Encoders'
   */
  1,

  /* Computed Parameter: Voltage_Active
   * Referenced by: '<Root>/Voltage'
   */
  0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 50U, 56U, 45U, 77U, 97U, 114U, 45U, 50U, 48U, 50U,
    51U, 95U, 49U, 55U, 45U, 48U, 56U, 45U, 53U, 49U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 50U, 56U, 95U, 77U, 97U, 114U, 95U, 50U, 48U, 50U,
    51U, 95U, 49U, 55U, 95U, 48U, 56U, 95U, 53U, 49U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  2U
};
