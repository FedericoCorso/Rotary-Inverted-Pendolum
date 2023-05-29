/*
 * SwingUp.h
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

#ifndef RTW_HEADER_SwingUp_h_
#define RTW_HEADER_SwingUp_h_
#ifndef SwingUp_COMMON_INCLUDES_
#define SwingUp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* SwingUp_COMMON_INCLUDES_ */

#include "SwingUp_types.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DiscreteTimeIntegrator[4];    /* '<S4>/Discrete-Time Integrator' */
  real_T Gain1;                        /* '<S5>/Gain1' */
  real_T alpha_minus_2pi;              /* '<Root>/Sum1' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T voltage_no_sat;               /* '<Root>/Switch' */
  real_T voltage_sat;                  /* '<Root>/Maximum voltage1' */
  real_T TmpSignalConversionAtStateSpace[3];
  real_T x_dot[4];                     /* '<S4>/MATLAB Function' */
  real_T x_hat[4];                     /* '<S1>/EKF' */
  real_T P_new[16];                    /* '<S1>/EKF' */
} B_SwingUp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<S4>/Discrete-Time Integrator' */
  real_T DelayOneStep_DSTATE;          /* '<S1>/Delay One Step' */
  real_T DelayOneStep1_DSTATE[16];     /* '<S1>/Delay One Step1' */
  real_T DelayOneStep2_DSTATE[4];      /* '<S1>/Delay One Step2' */
  real_T P[16];                        /* '<S2>/DataStoreMemory - P' */
  real_T x[4];                         /* '<S2>/DataStoreMemory - x' */
} DW_SwingUp_T;

/* Continuous states (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[4];         /* '<Root>/State-Space' */
} X_SwingUp_T;

/* State derivatives (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[4];         /* '<Root>/State-Space' */
} XDot_SwingUp_T;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE[4];      /* '<Root>/State-Space' */
} XDis_SwingUp_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_SwingUp_T_ {
  real_T A_ob[16];                     /* Variable: A_ob
                                        * Referenced by: '<Root>/State-Space'
                                        */
  real_T B_ob[12];                     /* Variable: B_ob
                                        * Referenced by: '<Root>/State-Space'
                                        */
  real_T C_ob[16];                     /* Variable: C_ob
                                        * Referenced by: '<Root>/State-Space'
                                        */
  real_T E[16];                        /* Variable: E
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T J_a;                          /* Variable: J_a
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Jp_prime;                     /* Variable: Jp_prime
                                        * Referenced by:
                                        *   '<S18>/Gain'
                                        *   '<S19>/Gain'
                                        *   '<S20>/Gain'
                                        *   '<S22>/Gain1'
                                        */
  real_T K_g;                          /* Variable: K_g
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S6>/Kd'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S6>/Kp'
                                        */
  real_T Kpp[4];                       /* Variable: Kpp
                                        * Referenced by: '<Root>/LQinf gain1'
                                        */
  real_T P0[16];                       /* Variable: P0
                                        * Referenced by: '<S1>/Delay One Step1'
                                        */
  real_T R[4];                         /* Variable: R
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T c1_tau;                       /* Variable: c1_tau
                                        * Referenced by:
                                        *   '<S5>/Gain'
                                        *   '<S5>/Gain1'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S6>/Constant'
                                        *   '<S18>/Gain'
                                        *   '<S22>/Gain'
                                        */
  real_T id_param[14];                 /* Variable: id_param
                                        * Referenced by:
                                        *   '<S1>/Constant2'
                                        *   '<S4>/Constant'
                                        */
  real_T k_m;                          /* Variable: k_m
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T l_p;                          /* Variable: l_p
                                        * Referenced by:
                                        *   '<S6>/Constant'
                                        *   '<S6>/Gain1'
                                        *   '<S6>/Gain2'
                                        *   '<S17>/Gain'
                                        *   '<S22>/Gain'
                                        */
  real_T m_p;                          /* Variable: m_p
                                        * Referenced by:
                                        *   '<S6>/Constant'
                                        *   '<S6>/Gain1'
                                        *   '<S16>/Gain'
                                        *   '<S17>/Gain'
                                        *   '<S19>/Constant1'
                                        *   '<S19>/Gain1'
                                        *   '<S22>/Gain'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by:
                                        *   '<S6>/Gain1'
                                        *   '<S6>/Gain2'
                                        *   '<S17>/Gain'
                                        *   '<S18>/Gain'
                                        *   '<S20>/Gain'
                                        */
  real_T voltage_max;                  /* Variable: voltage_max
                                        * Referenced by: '<Root>/Maximum voltage1'
                                        */
  real_T x0_KF[4];                     /* Variable: x0_KF
                                        * Referenced by: '<S1>/Delay One Step2'
                                        */
  real_T x0_down[4];                   /* Variable: x0_down
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  real_T x0_ob[4];                     /* Variable: x0_ob
                                        * Referenced by: '<Root>/State-Space'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S4>/Discrete-Time Integrator'
                            */
  real_T R2_Value;                     /* Expression: p.R{2}
                                        * Referenced by: '<S2>/R2'
                                        */
  real_T MeasurementFcn2Inputs_Value;  /* Expression: 1
                                        * Referenced by: '<S2>/MeasurementFcn2Inputs'
                                        */
  real_T R1_Value;                     /* Expression: p.R{1}
                                        * Referenced by: '<S2>/R1'
                                        */
  real_T MeasurementFcn1Inputs_Value;  /* Expression: 0
                                        * Referenced by: '<S2>/MeasurementFcn1Inputs'
                                        */
  real_T DelayOneStep_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S1>/Delay One Step'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Constant3_Value;              /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.26
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Q_Value[16];                  /* Expression: p.Q
                                        * Referenced by: '<S2>/Q'
                                        */
  real_T DataStoreMemoryP_InitialValue[16];/* Expression: p.InitialCovariance
                                            * Referenced by: '<S2>/DataStoreMemory - P'
                                            */
  real_T DataStoreMemoryx_InitialValue[4];/* Expression: p.InitialState
                                           * Referenced by: '<S2>/DataStoreMemory - x'
                                           */
  boolean_T yBlockOrdering_Y0;         /* Computed Parameter: yBlockOrdering_Y0
                                        * Referenced by: '<S8>/yBlockOrdering'
                                        */
  boolean_T yBlockOrdering_Y0_n;      /* Computed Parameter: yBlockOrdering_Y0_n
                                       * Referenced by: '<S9>/yBlockOrdering'
                                       */
  boolean_T BlockOrdering_Value;       /* Expression: true()
                                        * Referenced by: '<S2>/BlockOrdering'
                                        */
  boolean_T Enable1_Value;             /* Expression: true()
                                        * Referenced by: '<S2>/Enable1'
                                        */
  boolean_T Enable2_Value;             /* Expression: true()
                                        * Referenced by: '<S2>/Enable2'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_SwingUp_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_SwingUp_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_SwingUp_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

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
extern P_SwingUp_T SwingUp_P;

/* Block signals (default storage) */
extern B_SwingUp_T SwingUp_B;

/* Continuous states (default storage) */
extern X_SwingUp_T SwingUp_X;

/* Block states (default storage) */
extern DW_SwingUp_T SwingUp_DW;

/* Model entry point functions */
extern void SwingUp_initialize(void);
extern void SwingUp_step(void);
extern void SwingUp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SwingUp_T *const SwingUp_M;

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
 * '<Root>' : 'SwingUp'
 * '<S1>'   : 'SwingUp/EKF'
 * '<S2>'   : 'SwingUp/Extended Kalman Filter'
 * '<S3>'   : 'SwingUp/Linearizing Torque'
 * '<S4>'   : 'SwingUp/Pendulum NL Model'
 * '<S5>'   : 'SwingUp/Torque_Voltage Conversion'
 * '<S6>'   : 'SwingUp/energy control'
 * '<S7>'   : 'SwingUp/EKF/EKF'
 * '<S8>'   : 'SwingUp/Extended Kalman Filter/Correct1'
 * '<S9>'   : 'SwingUp/Extended Kalman Filter/Correct2'
 * '<S10>'  : 'SwingUp/Extended Kalman Filter/Output'
 * '<S11>'  : 'SwingUp/Extended Kalman Filter/Predict'
 * '<S12>'  : 'SwingUp/Extended Kalman Filter/Correct1/Correct'
 * '<S13>'  : 'SwingUp/Extended Kalman Filter/Correct2/Correct'
 * '<S14>'  : 'SwingUp/Extended Kalman Filter/Output/MATLAB Function'
 * '<S15>'  : 'SwingUp/Extended Kalman Filter/Predict/Predict'
 * '<S16>'  : 'SwingUp/Linearizing Torque/alpha_dot*theta_dot'
 * '<S17>'  : 'SwingUp/Linearizing Torque/alpha_dot^2'
 * '<S18>'  : 'SwingUp/Linearizing Torque/gravity compensation'
 * '<S19>'  : 'SwingUp/Linearizing Torque/theta_ddot_d'
 * '<S20>'  : 'SwingUp/Linearizing Torque/theta_dot^2 coeff'
 * '<S21>'  : 'SwingUp/Pendulum NL Model/MATLAB Function'
 * '<S22>'  : 'SwingUp/energy control/Subsystem'
 */
#endif                                 /* RTW_HEADER_SwingUp_h_ */
