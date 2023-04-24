/*
 * Simulink_Horizontal_Control_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_uint64),
  sizeof(t_task),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_uint64",
  "t_task",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Simulink_Horizontal_Control_B.alpharad), 0, 0, 15 }
  ,

  { (char_T *)(&Simulink_Horizontal_Control_DW.HILInitialize_AOVoltages[0]), 0,
    0, 2 },

  { (char_T *)(&Simulink_Horizontal_Control_DW.ToHostFile_PointsWritten), 14, 0,
    1 },

  { (char_T *)(&Simulink_Horizontal_Control_DW.Encoders_Task), 15, 0, 1 },

  { (char_T *)(&Simulink_Horizontal_Control_DW.HILInitialize_Card), 16, 0, 1 },

  { (char_T *)
    (&Simulink_Horizontal_Control_DW.Alpharealvssimulated_PWORK.LoggedData[0]),
    11, 0, 15 },

  { (char_T *)(&Simulink_Horizontal_Control_DW.Encoders_Buffer[0]), 6, 0, 2 },

  { (char_T *)(&Simulink_Horizontal_Control_DW.ToHostFile_SamplesCount), 7, 0, 2
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Simulink_Horizontal_Control_P.A[0]), 0, 0, 38 },

  { (char_T *)(&Simulink_Horizontal_Control_P.Encoders_clock), 6, 0, 1 },

  { (char_T *)(&Simulink_Horizontal_Control_P.Encoders_channels[0]), 7, 0, 4 },

  { (char_T *)(&Simulink_Horizontal_Control_P.HILInitialize_OOTerminate), 0, 0,
    48 },

  { (char_T *)(&Simulink_Horizontal_Control_P.ToHostFile_Decimation), 7, 0, 2 },

  { (char_T *)(&Simulink_Horizontal_Control_P.HILInitialize_Active), 8, 0, 10 },

  { (char_T *)(&Simulink_Horizontal_Control_P.ManualSwitch_CurrentSetting), 3, 0,
    58 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] Simulink_Horizontal_Control_dt.h */
