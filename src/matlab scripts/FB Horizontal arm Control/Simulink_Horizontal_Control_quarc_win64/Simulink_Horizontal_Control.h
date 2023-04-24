/*
 * Simulink_Horizontal_Control.h
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

#ifndef RTW_HEADER_Simulink_Horizontal_Control_h_
#define RTW_HEADER_Simulink_Horizontal_Control_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef Simulink_Horizontal_Control_COMMON_INCLUDES_
# define Simulink_Horizontal_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                        /* Simulink_Horizontal_Control_COMMON_INCLUDES_ */

#include "Simulink_Horizontal_Control_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T alpharad;                     /* '<S6>/Add' */
  real_T StateSpace[4];                /* '<S5>/State-Space' */
  real_T Sum;                          /* '<S5>/Sum' */
  real_T Referencetheta;               /* '<Root>/Maximum theta' */
  real_T thetarad;                     /* '<S6>/Gain' */
  real_T error;                        /* '<Root>/Sum' */
  real_T error_a;                      /* '<Root>/Sum1' */
  real_T Internal;                     /* '<S3>/Internal' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Switch1;                      /* '<S1>/Switch1' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Switch1_m;                    /* '<S2>/Switch1' */
} B_Simulink_Horizontal_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  t_uint64 ToHostFile_PointsWritten;   /* '<Root>/To Host File' */
  t_task Encoders_Task;                /* '<Root>/Encoders' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  struct {
    void *LoggedData[2];
  } Alpharealvssimulated_PWORK;        /* '<Root>/Alpha real vs simulated' */

  struct {
    void *LoggedData;
  } Error_PWORK;                       /* '<Root>/Error' */

  struct {
    void *LoggedData;
  } Error1_PWORK;                      /* '<Root>/Error1' */

  struct {
    void *LoggedData;
  } Inputvoltage_PWORK;                /* '<Root>/Input voltage' */

  struct {
    void *LoggedData[2];
  } Realoutput_PWORK;                  /* '<Root>/Real output' */

  struct {
    void *LoggedData[2];
  } ReferecnevsRealTheta_PWORK;        /* '<Root>/Referecne vs Real Theta' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Thetarealvssimulated_PWORK;        /* '<Root>/Theta real vs simulated' */

  void *ToHostFile_PWORK[2];           /* '<Root>/To Host File' */
  void *Voltage_PWORK;                 /* '<Root>/Voltage' */
  int32_T Encoders_Buffer[2];          /* '<Root>/Encoders' */
  uint32_T ToHostFile_SamplesCount;    /* '<Root>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<Root>/To Host File' */
} DW_Simulink_Horizontal_Contro_T;

/* Continuous states (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[4];         /* '<S5>/State-Space' */
  real_T Internal_CSTATE[4];           /* '<S3>/Internal' */
  real_T Internal_CSTATE_e[4];         /* '<S4>/Internal' */
} X_Simulink_Horizontal_Control_T;

/* State derivatives (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[4];         /* '<S5>/State-Space' */
  real_T Internal_CSTATE[4];           /* '<S3>/Internal' */
  real_T Internal_CSTATE_e[4];         /* '<S4>/Internal' */
} XDot_Simulink_Horizontal_Cont_T;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE[4];      /* '<S5>/State-Space' */
  boolean_T Internal_CSTATE[4];        /* '<S3>/Internal' */
  boolean_T Internal_CSTATE_e[4];      /* '<S4>/Internal' */
} XDis_Simulink_Horizontal_Cont_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_Simulink_Horizontal_Control_T_ {
  real_T A[16];                        /* Variable: A
                                        * Referenced by: '<S5>/State-Space'
                                        */
  real_T B[4];                         /* Variable: B
                                        * Referenced by: '<S5>/State-Space'
                                        */
  real_T C[16];                        /* Variable: C
                                        * Referenced by: '<S5>/State-Space'
                                        */
  real_T theta_max;                    /* Variable: theta_max
                                        * Referenced by:
                                        *   '<Root>/Maximum theta'
                                        *   '<S1>/Switch'
                                        *   '<S1>/Switch1'
                                        *   '<S2>/Switch'
                                        *   '<S2>/Switch1'
                                        */
  real_T voltage_max;                  /* Variable: voltage_max
                                        * Referenced by:
                                        *   '<Root>/Maximum voltage'
                                        *   '<Root>/Maximum voltage1'
                                        */
  int32_T Encoders_clock;              /* Mask Parameter: Encoders_clock
                                        * Referenced by: '<Root>/Encoders'
                                        */
  uint32_T Encoders_channels[2];       /* Mask Parameter: Encoders_channels
                                        * Referenced by: '<Root>/Encoders'
                                        */
  uint32_T Voltage_channels;           /* Mask Parameter: Voltage_channels
                                        * Referenced by: '<Root>/Voltage'
                                        */
  uint32_T Encoders_samples_in_buffer;
                                   /* Mask Parameter: Encoders_samples_in_buffer
                                    * Referenced by: '<Root>/Encoders'
                                    */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2*pi/4096
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Offset_Value;                 /* Expression: pi
                                        * Referenced by: '<S6>/Offset'
                                        */
  real_T StateSpace_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S5>/State-Space'
                                        */
  real_T Offset_Value_d;               /* Expression: pi
                                        * Referenced by: '<S5>/Offset'
                                        */
  real_T Referencethetarad_Amplitude;  /* Expression: pi/6
                                        * Referenced by: '<Root>/Reference theta [rad]'
                                        */
  real_T Referencethetarad_Frequency;  /* Expression: 0.5
                                        * Referenced by: '<Root>/Reference theta [rad]'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: pi
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Gain_Gain;                    /* Expression: 2*pi/4096
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Internal_A[9];                /* Computed Parameter: Internal_A
                                        * Referenced by: '<S3>/Internal'
                                        */
  real_T Internal_B;                   /* Computed Parameter: Internal_B
                                        * Referenced by: '<S3>/Internal'
                                        */
  real_T Internal_C[4];                /* Computed Parameter: Internal_C
                                        * Referenced by: '<S3>/Internal'
                                        */
  real_T Internal_InitialCondition;    /* Expression: 0.0
                                        * Referenced by: '<S3>/Internal'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Internal_A_p[9];              /* Computed Parameter: Internal_A_p
                                        * Referenced by: '<S4>/Internal'
                                        */
  real_T Internal_B_n;                 /* Computed Parameter: Internal_B_n
                                        * Referenced by: '<S4>/Internal'
                                        */
  real_T Internal_C_n[4];              /* Computed Parameter: Internal_C_n
                                        * Referenced by: '<S4>/Internal'
                                        */
  real_T Internal_InitialCondition_j;  /* Expression: 0.0
                                        * Referenced by: '<S4>/Internal'
                                        */
  uint32_T ToHostFile_Decimation;   /* Computed Parameter: ToHostFile_Decimation
                                     * Referenced by: '<Root>/To Host File'
                                     */
  uint32_T ToHostFile_BitRate;         /* Computed Parameter: ToHostFile_BitRate
                                        * Referenced by: '<Root>/To Host File'
                                        */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T Encoders_Active;           /* Computed Parameter: Encoders_Active
                                        * Referenced by: '<Root>/Encoders'
                                        */
  boolean_T Voltage_Active;            /* Computed Parameter: Voltage_Active
                                        * Referenced by: '<Root>/Voltage'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ToHostFile_file_name[30];    /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File'
                                        */
  uint8_T ToHostFile_VarName[26];      /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat;    /* Computed Parameter: ToHostFile_FileFormat
                                     * Referenced by: '<Root>/To Host File'
                                     */
};

/* Real-time Model Data Structure */
struct tag_RTM_Simulink_Horizontal_C_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Simulink_Horizontal_Control_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][12];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Simulink_Horizontal_Control_T Simulink_Horizontal_Control_P;

/* Block signals (default storage) */
extern B_Simulink_Horizontal_Control_T Simulink_Horizontal_Control_B;

/* Continuous states (default storage) */
extern X_Simulink_Horizontal_Control_T Simulink_Horizontal_Control_X;

/* Block states (default storage) */
extern DW_Simulink_Horizontal_Contro_T Simulink_Horizontal_Control_DW;

/* Model entry point functions */
extern void Simulink_Horizontal_Control_initialize(void);
extern void Simulink_Horizontal_Control_step(void);
extern void Simulink_Horizontal_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Simulink_Horizontal__T *const Simulink_Horizontal_Control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Simulink_Horizontal_Control'
 * '<S1>'   : 'Simulink_Horizontal_Control/Control for theta max'
 * '<S2>'   : 'Simulink_Horizontal_Control/Control for theta max1'
 * '<S3>'   : 'Simulink_Horizontal_Control/Fede'
 * '<S4>'   : 'Simulink_Horizontal_Control/Fede1'
 * '<S5>'   : 'Simulink_Horizontal_Control/Models'
 * '<S6>'   : 'Simulink_Horizontal_Control/Subsystem'
 * '<S7>'   : 'Simulink_Horizontal_Control/Fede/IO Delay'
 * '<S8>'   : 'Simulink_Horizontal_Control/Fede/Input Delay'
 * '<S9>'   : 'Simulink_Horizontal_Control/Fede/Output Delay'
 * '<S10>'  : 'Simulink_Horizontal_Control/Fede1/IO Delay'
 * '<S11>'  : 'Simulink_Horizontal_Control/Fede1/Input Delay'
 * '<S12>'  : 'Simulink_Horizontal_Control/Fede1/Output Delay'
 */
#endif                           /* RTW_HEADER_Simulink_Horizontal_Control_h_ */
