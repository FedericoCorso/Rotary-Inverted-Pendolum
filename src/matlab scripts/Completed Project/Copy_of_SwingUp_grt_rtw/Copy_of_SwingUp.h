/*
 * Copy_of_SwingUp.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Copy_of_SwingUp".
 *
 * Model version              : 1.110
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon May 29 18:17:01 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_of_SwingUp_h_
#define RTW_HEADER_Copy_of_SwingUp_h_
#ifndef Copy_of_SwingUp_COMMON_INCLUDES_
#define Copy_of_SwingUp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Copy_of_SwingUp_COMMON_INCLUDES_ */

#include "Copy_of_SwingUp_types.h"
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
  real_T Integrator[4];                /* '<S4>/Integrator' */
  real_T signaltobefedtotheobserverforLQ;/* '<S6>/Sum5' */
  real_T Relay1;                       /* '<Root>/Relay1' */
  real_T signaltobefedtotheobserverfor_j;/* '<S5>/Sum5' */
  real_T DelayOneStep;                 /* '<S9>/Delay One Step' */
  real_T DelayOneStep3[16];            /* '<S9>/Delay One Step3' */
  real_T DelayOneStep1[4];             /* '<S9>/Delay One Step1' */
  real_T Sum1;                         /* '<S23>/Sum1' */
  real_T Sum;                          /* '<S17>/Sum' */
  real_T desiredaccelerationsignal;    /* '<S17>/Sum1' */
  real_T ManualSwitch;                 /* '<S7>/Manual Switch' */
  real_T DelayOneStep_j;               /* '<Root>/Delay One Step' */
  real_T voltage_no_sat;               /* '<Root>/Switch' */
  real_T voltage_sat;                  /* '<Root>/Maximum voltage1' */
  real_T x_est[4];                     /* '<S8>/Observer//KF' */
  real_T error;                        /* '<S8>/Sum1' */
  real_T Sum2;                         /* '<S8>/Sum2' */
  real_T TmpSignalConversionAtObserverKF[3];
  real_T x_dot[4];                     /* '<S4>/MATLAB Function' */
  real_T In1;                          /* '<S3>/In1' */
  real_T x_hat[4];                     /* '<S9>/EKF' */
  real_T P_new[16];                    /* '<S9>/EKF' */
  boolean_T NOT;                       /* '<Root>/NOT' */
} B_Copy_of_SwingUp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayOneStep_DSTATE;          /* '<S9>/Delay One Step' */
  real_T DelayOneStep3_DSTATE[16];     /* '<S9>/Delay One Step3' */
  real_T DelayOneStep1_DSTATE[4];      /* '<S9>/Delay One Step1' */
  real_T DelayOneStep_DSTATE_b;        /* '<Root>/Delay One Step' */
  boolean_T Relay1_Mode;               /* '<Root>/Relay1' */
  boolean_T Relay_Mode;                /* '<S7>/Relay' */
  boolean_T HoldThetaValueuprigth_MODE;/* '<Root>/Hold Theta Value uprigth' */
} DW_Copy_of_SwingUp_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S4>/Integrator' */
  real_T ObserverKF_CSTATE[4];         /* '<S8>/Observer//KF' */
  real_T Integrator_CSTATE_b;          /* '<S8>/Integrator' */
} X_Copy_of_SwingUp_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S4>/Integrator' */
  real_T ObserverKF_CSTATE[4];         /* '<S8>/Observer//KF' */
  real_T Integrator_CSTATE_b;          /* '<S8>/Integrator' */
} XDot_Copy_of_SwingUp_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<S4>/Integrator' */
  boolean_T ObserverKF_CSTATE[4];      /* '<S8>/Observer//KF' */
  boolean_T Integrator_CSTATE_b;       /* '<S8>/Integrator' */
} XDis_Copy_of_SwingUp_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_Copy_of_SwingUp_T_ {
  real_T A_kf[16];                     /* Variable: A_kf
                                        * Referenced by: '<S8>/Observer//KF'
                                        */
  real_T B_kf[12];                     /* Variable: B_kf
                                        * Referenced by: '<S8>/Observer//KF'
                                        */
  real_T C_kf[16];                     /* Variable: C_kf
                                        * Referenced by: '<S8>/Observer//KF'
                                        */
  real_T E[16];                        /* Variable: E
                                        * Referenced by: '<S9>/Constant4'
                                        */
  real_T J_a;                          /* Variable: J_a
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Jp_prime;                     /* Variable: Jp_prime
                                        * Referenced by:
                                        *   '<S14>/gain '
                                        *   '<S20>/Gain'
                                        *   '<S21>/Gain'
                                        *   '<S22>/Gain'
                                        *   '<S23>/Gain1'
                                        */
  real_T K_g;                          /* Variable: K_g
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T K_lq_en_alpha_eta;            /* Variable: K_lq_en_alpha_eta
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T K_lq_en_alpha_x[4];           /* Variable: K_lq_en_alpha_x
                                        * Referenced by: '<S8>/LQinf gain1'
                                        */
  real_T P0[16];                       /* Variable: P0
                                        * Referenced by: '<S9>/Delay One Step3'
                                        */
  real_T R[4];                         /* Variable: R
                                        * Referenced by: '<S9>/Constant5'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T c1_tau;                       /* Variable: c1_tau
                                        * Referenced by:
                                        *   '<S16>/Gain'
                                        *   '<S16>/Torque - Voltage proportionality parameter'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S14>/gain 1'
                                        *   '<S17>/Energy in Upright position '
                                        *   '<S20>/Gain'
                                        *   '<S23>/Gain'
                                        */
  real_T id_param[14];                 /* Variable: id_param
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S9>/Constant2'
                                        */
  real_T k_m;                          /* Variable: k_m
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T l_p;                          /* Variable: l_p
                                        * Referenced by:
                                        *   '<S14>/Gain'
                                        *   '<S14>/gain '
                                        *   '<S17>/Energy in Upright position '
                                        *   '<S17>/Gain2'
                                        *   '<S19>/Gain'
                                        *   '<S23>/Gain'
                                        */
  real_T m_p;                          /* Variable: m_p
                                        * Referenced by:
                                        *   '<S14>/gain '
                                        *   '<S17>/Energy in Upright position '
                                        *   '<S18>/Gain'
                                        *   '<S19>/Gain'
                                        *   '<S21>/Constant1'
                                        *   '<S21>/Gain1'
                                        *   '<S23>/Gain'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by:
                                        *   '<S14>/Gain'
                                        *   '<S14>/gain '
                                        *   '<S14>/gain 1'
                                        *   '<S17>/Gain2'
                                        *   '<S19>/Gain'
                                        *   '<S20>/Gain'
                                        *   '<S22>/Gain'
                                        */
  real_T voltage_max;                  /* Variable: voltage_max
                                        * Referenced by: '<Root>/Maximum voltage1'
                                        */
  real_T x0_KF[4];                     /* Variable: x0_KF
                                        * Referenced by: '<S9>/Delay One Step1'
                                        */
  real_T x0_down[4];                   /* Variable: x0_down
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T x0_ob[4];                     /* Variable: x0_ob
                                        * Referenced by: '<S8>/Observer//KF'
                                        */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S13>/Constant'
                                      */
  real_T CompareToConstant4_const_p;
                                   /* Mask Parameter: CompareToConstant4_const_p
                                    * Referenced by: '<S12>/Constant'
                                    */
  real_T CompareToConstant4_const_g;
                                   /* Mask Parameter: CompareToConstant4_const_g
                                    * Referenced by: '<S1>/Constant'
                                    */
  real_T thetaref_Y0;                  /* Computed Parameter: thetaref_Y0
                                        * Referenced by: '<S3>/theta ref'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T proportionalgaintobetuned_Gain;/* Expression: 1
                                         * Referenced by: '<S14>/proportional gain to be tuned'
                                         */
  real_T derivativegaintobetuned1_Gain;/* Expression: 1
                                        * Referenced by: '<S14>/derivative gain to be tuned1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -3
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant8'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Relay1_OnVal;                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Relay1'
                                        */
  real_T Relay1_OffVal;                /* Expression: 0.3
                                        * Referenced by: '<Root>/Relay1'
                                        */
  real_T Relay1_YOn;                   /* Expression: 1
                                        * Referenced by: '<Root>/Relay1'
                                        */
  real_T Relay1_YOff;                  /* Expression: 0
                                        * Referenced by: '<Root>/Relay1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 2*pi
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant8_Value_n;            /* Expression: 1
                                        * Referenced by: '<S5>/Constant8'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 2*pi
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T DelayOneStep_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S9>/Delay One Step'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 400
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Kp_Gain;                      /* Expression: 100
                                        * Referenced by: '<S17>/Kp'
                                        */
  real_T Kd_Gain;                      /* Expression: 2
                                        * Referenced by: '<S17>/Kd'
                                        */
  real_T Relay_OnVal;                  /* Expression: 0.6
                                        * Referenced by: '<S7>/Relay'
                                        */
  real_T Relay_OffVal;                 /* Expression: 0.5
                                        * Referenced by: '<S7>/Relay'
                                        */
  real_T Relay_YOn;                    /* Expression: 1
                                        * Referenced by: '<S7>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: 0
                                        * Referenced by: '<S7>/Relay'
                                        */
  real_T Tunablesmallparameteranglefromt;/* Expression: 0.3
                                          * Referenced by: '<S14>/Tunable small parameter,  angle from the vertical'
                                          */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DelayOneStep_InitialCondition_h;/* Expression: 0.0
                                          * Referenced by: '<Root>/Delay One Step'
                                          */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<S8>/Manual Switch2'
                              */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S8>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S8>/Manual Switch1'
                              */
  uint8_T ManualSwitch_CurrentSetting_g;
                            /* Computed Parameter: ManualSwitch_CurrentSetting_g
                             * Referenced by: '<S7>/Manual Switch'
                             */
  uint8_T ManualSwitch1_CurrentSetting_m;
                           /* Computed Parameter: ManualSwitch1_CurrentSetting_m
                            * Referenced by: '<Root>/Manual Switch1'
                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_SwingUp_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Copy_of_SwingUp_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Copy_of_SwingUp_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][9];
  ODE1_IntgData intgData;

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
extern P_Copy_of_SwingUp_T Copy_of_SwingUp_P;

/* Block signals (default storage) */
extern B_Copy_of_SwingUp_T Copy_of_SwingUp_B;

/* Continuous states (default storage) */
extern X_Copy_of_SwingUp_T Copy_of_SwingUp_X;

/* Block states (default storage) */
extern DW_Copy_of_SwingUp_T Copy_of_SwingUp_DW;

/* Model entry point functions */
extern void Copy_of_SwingUp_initialize(void);
extern void Copy_of_SwingUp_step(void);
extern void Copy_of_SwingUp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_SwingUp_T *const Copy_of_SwingUp_M;

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
 * '<Root>' : 'Copy_of_SwingUp'
 * '<S1>'   : 'Copy_of_SwingUp/Compare To Constant4'
 * '<S2>'   : 'Copy_of_SwingUp/EKF'
 * '<S3>'   : 'Copy_of_SwingUp/Hold Theta Value uprigth'
 * '<S4>'   : 'Copy_of_SwingUp/Pendulum NL Model1'
 * '<S5>'   : 'Copy_of_SwingUp/Rescaling Theta'
 * '<S6>'   : 'Copy_of_SwingUp/Rescaling alpha'
 * '<S7>'   : 'Copy_of_SwingUp/Subsystem'
 * '<S8>'   : 'Copy_of_SwingUp/Tracking//Stabilizing LQ//PP Controller'
 * '<S9>'   : 'Copy_of_SwingUp/EKF/EKF'
 * '<S10>'  : 'Copy_of_SwingUp/EKF/EKF/EKF'
 * '<S11>'  : 'Copy_of_SwingUp/Pendulum NL Model1/MATLAB Function'
 * '<S12>'  : 'Copy_of_SwingUp/Rescaling Theta/Compare To Constant4'
 * '<S13>'  : 'Copy_of_SwingUp/Rescaling alpha/Compare To Constant4'
 * '<S14>'  : 'Copy_of_SwingUp/Subsystem/Inclination based controller'
 * '<S15>'  : 'Copy_of_SwingUp/Subsystem/Linearizing Torque'
 * '<S16>'  : 'Copy_of_SwingUp/Subsystem/Torque_Voltage Conversion'
 * '<S17>'  : 'Copy_of_SwingUp/Subsystem/energy control'
 * '<S18>'  : 'Copy_of_SwingUp/Subsystem/Linearizing Torque/alpha_dot*theta_dot coefficient'
 * '<S19>'  : 'Copy_of_SwingUp/Subsystem/Linearizing Torque/alpha_dot^2 coefficient'
 * '<S20>'  : 'Copy_of_SwingUp/Subsystem/Linearizing Torque/gravity compensation'
 * '<S21>'  : 'Copy_of_SwingUp/Subsystem/Linearizing Torque/theta_ddot_d coefficient'
 * '<S22>'  : 'Copy_of_SwingUp/Subsystem/Linearizing Torque/theta_dot^2 coeff coefficient'
 * '<S23>'  : 'Copy_of_SwingUp/Subsystem/energy control/Total Energy  of Pendulum'
 */
#endif                                 /* RTW_HEADER_Copy_of_SwingUp_h_ */
