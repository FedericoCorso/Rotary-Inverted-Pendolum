/*
 * Simulink_Horizontal_Control.c
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
#include "Simulink_Horizontal_Control_dt.h"

/* Block signals (default storage) */
B_Simulink_Horizontal_Control_T Simulink_Horizontal_Control_B;

/* Continuous states */
X_Simulink_Horizontal_Control_T Simulink_Horizontal_Control_X;

/* Block states (default storage) */
DW_Simulink_Horizontal_Contro_T Simulink_Horizontal_Control_DW;

/* Real-time model */
RT_MODEL_Simulink_Horizontal__T Simulink_Horizontal_Control_M_;
RT_MODEL_Simulink_Horizontal__T *const Simulink_Horizontal_Control_M =
  &Simulink_Horizontal_Control_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Simulink_Horizontal_Control_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Simulink_Horizontal_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_theta;
  real_T rtb_alpha;
  int_T iy;
  real_T temp;
  real_T rtb_Internal;
  real_T u2;
  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
    /* set solver stop time */
    if (!(Simulink_Horizontal_Control_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Simulink_Horizontal_Control_M->solverInfo,
                            ((Simulink_Horizontal_Control_M->Timing.clockTickH0
        + 1) * Simulink_Horizontal_Control_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Simulink_Horizontal_Control_M->solverInfo,
                            ((Simulink_Horizontal_Control_M->Timing.clockTick0 +
        1) * Simulink_Horizontal_Control_M->Timing.stepSize0 +
        Simulink_Horizontal_Control_M->Timing.clockTickH0 *
        Simulink_Horizontal_Control_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Simulink_Horizontal_Control_M)) {
    Simulink_Horizontal_Control_M->Timing.t[0] = rtsiGetT
      (&Simulink_Horizontal_Control_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/Encoders' */

    /* S-Function Block: Simulink_Horizontal_Control/Encoders (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Simulink_Horizontal_Control_DW.Encoders_Task, 1,
         &Simulink_Horizontal_Control_DW.Encoders_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
      } else {
        rtb_theta = Simulink_Horizontal_Control_DW.Encoders_Buffer[0];
        rtb_alpha = Simulink_Horizontal_Control_DW.Encoders_Buffer[1];
      }
    }

    /* Sum: '<S6>/Add' incorporates:
     *  Constant: '<S6>/Offset'
     *  Gain: '<S6>/Gain1'
     */
    Simulink_Horizontal_Control_B.alpharad =
      Simulink_Horizontal_Control_P.Gain1_Gain * rtb_alpha +
      Simulink_Horizontal_Control_P.Offset_Value;
  }

  /* StateSpace: '<S5>/State-Space' */
  for (iy = 0; iy < 4; iy++) {
    Simulink_Horizontal_Control_B.StateSpace[iy] = 0.0;
    Simulink_Horizontal_Control_B.StateSpace[iy] +=
      Simulink_Horizontal_Control_P.C[iy] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[0];
    Simulink_Horizontal_Control_B.StateSpace[iy] +=
      Simulink_Horizontal_Control_P.C[iy + 4] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[1];
    Simulink_Horizontal_Control_B.StateSpace[iy] +=
      Simulink_Horizontal_Control_P.C[iy + 8] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[2];
    Simulink_Horizontal_Control_B.StateSpace[iy] +=
      Simulink_Horizontal_Control_P.C[iy + 12] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[3];
  }

  /* End of StateSpace: '<S5>/State-Space' */

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S5>/Offset'
   */
  Simulink_Horizontal_Control_B.Sum = Simulink_Horizontal_Control_B.StateSpace[1]
    + Simulink_Horizontal_Control_P.Offset_Value_d;
  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
  }

  /* SignalGenerator: '<Root>/Reference theta [rad]' */
  temp = Simulink_Horizontal_Control_P.Referencethetarad_Frequency *
    Simulink_Horizontal_Control_M->Timing.t[0];

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  if (Simulink_Horizontal_Control_P.ManualSwitch_CurrentSetting == 1) {
    /* SignalGenerator: '<Root>/Reference theta [rad]' */
    if (temp - floor(temp) >= 0.5) {
      rtb_Internal = Simulink_Horizontal_Control_P.Referencethetarad_Amplitude;
    } else {
      rtb_Internal = -Simulink_Horizontal_Control_P.Referencethetarad_Amplitude;
    }
  } else {
    rtb_Internal = sin(Simulink_Horizontal_Control_P.SineWave_Freq *
                       Simulink_Horizontal_Control_M->Timing.t[0] +
                       Simulink_Horizontal_Control_P.SineWave_Phase) *
      Simulink_Horizontal_Control_P.SineWave_Amp +
      Simulink_Horizontal_Control_P.SineWave_Bias;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Saturate: '<Root>/Maximum theta' incorporates:
   *  Switch: '<S1>/Switch'
   *  Switch: '<S1>/Switch1'
   *  Switch: '<S2>/Switch'
   *  Switch: '<S2>/Switch1'
   */
  temp = -Simulink_Horizontal_Control_P.theta_max * 3.1415926535897931 / 180.0;
  u2 = Simulink_Horizontal_Control_P.theta_max * 3.1415926535897931 / 180.0;
  if (rtb_Internal > u2) {
    Simulink_Horizontal_Control_B.Referencetheta = u2;
  } else if (rtb_Internal < temp) {
    Simulink_Horizontal_Control_B.Referencetheta = temp;
  } else {
    Simulink_Horizontal_Control_B.Referencetheta = rtb_Internal;
  }

  /* End of Saturate: '<Root>/Maximum theta' */
  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
    /* Gain: '<S6>/Gain' */
    Simulink_Horizontal_Control_B.thetarad =
      Simulink_Horizontal_Control_P.Gain_Gain * rtb_theta;
  }

  /* Sum: '<Root>/Sum' */
  Simulink_Horizontal_Control_B.error =
    Simulink_Horizontal_Control_B.Referencetheta -
    Simulink_Horizontal_Control_B.thetarad;
  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
  }

  /* Sum: '<Root>/Sum1' */
  Simulink_Horizontal_Control_B.error_a =
    Simulink_Horizontal_Control_B.Referencetheta -
    Simulink_Horizontal_Control_B.StateSpace[0];
  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
    /* Gain: '<S1>/Gain' */
    Simulink_Horizontal_Control_B.Gain =
      Simulink_Horizontal_Control_P.Gain_Gain_g *
      Simulink_Horizontal_Control_B.thetarad;
  }

  /* StateSpace: '<S3>/Internal' */
  Simulink_Horizontal_Control_B.Internal = 0.0;
  Simulink_Horizontal_Control_B.Internal +=
    Simulink_Horizontal_Control_P.Internal_C[0] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[0];
  Simulink_Horizontal_Control_B.Internal +=
    Simulink_Horizontal_Control_P.Internal_C[1] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[1];
  Simulink_Horizontal_Control_B.Internal +=
    Simulink_Horizontal_Control_P.Internal_C[2] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[2];
  Simulink_Horizontal_Control_B.Internal +=
    Simulink_Horizontal_Control_P.Internal_C[3] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[3];

  /* Switch: '<S1>/Switch1' */
  if (Simulink_Horizontal_Control_B.Gain > temp) {
    /* Switch: '<S1>/Switch' */
    if (Simulink_Horizontal_Control_B.thetarad > temp) {
      /* Saturate: '<Root>/Maximum voltage' */
      if (Simulink_Horizontal_Control_B.Internal >
          Simulink_Horizontal_Control_P.voltage_max) {
        Simulink_Horizontal_Control_B.Switch1 =
          Simulink_Horizontal_Control_P.voltage_max;
      } else if (Simulink_Horizontal_Control_B.Internal <
                 -Simulink_Horizontal_Control_P.voltage_max) {
        Simulink_Horizontal_Control_B.Switch1 =
          -Simulink_Horizontal_Control_P.voltage_max;
      } else {
        Simulink_Horizontal_Control_B.Switch1 =
          Simulink_Horizontal_Control_B.Internal;
      }

      /* End of Saturate: '<Root>/Maximum voltage' */
    } else {
      Simulink_Horizontal_Control_B.Switch1 = 0.0;
    }
  } else {
    Simulink_Horizontal_Control_B.Switch1 = 0.0;
  }

  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
  }

  /* Gain: '<Root>/Gain2' */
  Simulink_Horizontal_Control_B.Gain2 = Simulink_Horizontal_Control_P.Gain2_Gain
    * Simulink_Horizontal_Control_B.Switch1;
  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/Voltage' */

    /* S-Function Block: Simulink_Horizontal_Control/Voltage (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog
        (Simulink_Horizontal_Control_DW.HILInitialize_Card,
         &Simulink_Horizontal_Control_P.Voltage_channels, 1,
         &Simulink_Horizontal_Control_B.Gain2);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
      }
    }
  }

  /* StateSpace: '<S4>/Internal' */
  rtb_Internal = ((Simulink_Horizontal_Control_P.Internal_C_n[0] *
                   Simulink_Horizontal_Control_X.Internal_CSTATE_e[0] +
                   Simulink_Horizontal_Control_P.Internal_C_n[1] *
                   Simulink_Horizontal_Control_X.Internal_CSTATE_e[1]) +
                  Simulink_Horizontal_Control_P.Internal_C_n[2] *
                  Simulink_Horizontal_Control_X.Internal_CSTATE_e[2]) +
    Simulink_Horizontal_Control_P.Internal_C_n[3] *
    Simulink_Horizontal_Control_X.Internal_CSTATE_e[3];

  /* Switch: '<S2>/Switch1' incorporates:
   *  Gain: '<S2>/Gain'
   */
  if (Simulink_Horizontal_Control_P.Gain_Gain_m *
      Simulink_Horizontal_Control_B.StateSpace[0] > temp) {
    /* Switch: '<S2>/Switch' */
    if (Simulink_Horizontal_Control_B.StateSpace[0] > temp) {
      /* Saturate: '<Root>/Maximum voltage1' */
      if (rtb_Internal > Simulink_Horizontal_Control_P.voltage_max) {
        Simulink_Horizontal_Control_B.Switch1_m =
          Simulink_Horizontal_Control_P.voltage_max;
      } else if (rtb_Internal < -Simulink_Horizontal_Control_P.voltage_max) {
        Simulink_Horizontal_Control_B.Switch1_m =
          -Simulink_Horizontal_Control_P.voltage_max;
      } else {
        Simulink_Horizontal_Control_B.Switch1_m = rtb_Internal;
      }

      /* End of Saturate: '<Root>/Maximum voltage1' */
    } else {
      Simulink_Horizontal_Control_B.Switch1_m = 0.0;
    }
  } else {
    Simulink_Horizontal_Control_B.Switch1_m = 0.0;
  }

  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)Simulink_Horizontal_Control_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (real_T)
                      (((Simulink_Horizontal_Control_M->Timing.clockTick1+
                         Simulink_Horizontal_Control_M->Timing.clockTickH1*
                         4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Simulink_Horizontal_Control_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Simulink_Horizontal_Control_M)!=-1) &&
          !((rtmGetTFinal(Simulink_Horizontal_Control_M)-
             (((Simulink_Horizontal_Control_M->Timing.clockTick1+
                Simulink_Horizontal_Control_M->Timing.clockTickH1* 4294967296.0))
              * 0.002)) > (((Simulink_Horizontal_Control_M->Timing.clockTick1+
                             Simulink_Horizontal_Control_M->Timing.clockTickH1*
                             4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Simulink_Horizontal_Control_M)) {
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Simulink_Horizontal_Control_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Simulink_Horizontal_Control_M->Timing.clockTick0)) {
      ++Simulink_Horizontal_Control_M->Timing.clockTickH0;
    }

    Simulink_Horizontal_Control_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Simulink_Horizontal_Control_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Simulink_Horizontal_Control_M->Timing.clockTick1++;
      if (!Simulink_Horizontal_Control_M->Timing.clockTick1) {
        Simulink_Horizontal_Control_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Simulink_Horizontal_Control_derivatives(void)
{
  int_T is;
  XDot_Simulink_Horizontal_Cont_T *_rtXdot;
  _rtXdot = ((XDot_Simulink_Horizontal_Cont_T *)
             Simulink_Horizontal_Control_M->derivs);
  for (is = 0; is < 4; is++) {
    /* Derivatives for StateSpace: '<S5>/State-Space' */
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
    _rtXdot->StateSpace_CSTATE[is] += Simulink_Horizontal_Control_P.A[is] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[0];
    _rtXdot->StateSpace_CSTATE[is] += Simulink_Horizontal_Control_P.A[is + 4] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[1];
    _rtXdot->StateSpace_CSTATE[is] += Simulink_Horizontal_Control_P.A[is + 8] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[2];
    _rtXdot->StateSpace_CSTATE[is] += Simulink_Horizontal_Control_P.A[is + 12] *
      Simulink_Horizontal_Control_X.StateSpace_CSTATE[3];
    _rtXdot->StateSpace_CSTATE[is] += Simulink_Horizontal_Control_P.B[is] *
      Simulink_Horizontal_Control_B.Switch1_m;

    /* Derivatives for StateSpace: '<S3>/Internal' */
    _rtXdot->Internal_CSTATE[is] = 0.0;

    /* Derivatives for StateSpace: '<S4>/Internal' */
    _rtXdot->Internal_CSTATE_e[is] = 0.0;
  }

  /* Derivatives for StateSpace: '<S3>/Internal' */
  _rtXdot->Internal_CSTATE[0] += Simulink_Horizontal_Control_P.Internal_A[0] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[0];
  _rtXdot->Internal_CSTATE[0] += Simulink_Horizontal_Control_P.Internal_A[1] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[1];
  _rtXdot->Internal_CSTATE[1] += Simulink_Horizontal_Control_P.Internal_A[2] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[0];
  _rtXdot->Internal_CSTATE[1] += Simulink_Horizontal_Control_P.Internal_A[3] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[1];
  _rtXdot->Internal_CSTATE[1] += Simulink_Horizontal_Control_P.Internal_A[4] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[2];
  _rtXdot->Internal_CSTATE[1] += Simulink_Horizontal_Control_P.Internal_A[5] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[3];
  _rtXdot->Internal_CSTATE[2] += Simulink_Horizontal_Control_P.Internal_A[6] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[2];
  _rtXdot->Internal_CSTATE[2] += Simulink_Horizontal_Control_P.Internal_A[7] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[3];
  _rtXdot->Internal_CSTATE[3] += Simulink_Horizontal_Control_P.Internal_A[8] *
    Simulink_Horizontal_Control_X.Internal_CSTATE[3];
  _rtXdot->Internal_CSTATE[3] += Simulink_Horizontal_Control_P.Internal_B *
    Simulink_Horizontal_Control_B.error;

  /* Derivatives for StateSpace: '<S4>/Internal' */
  _rtXdot->Internal_CSTATE_e[0] += Simulink_Horizontal_Control_P.Internal_A_p[0]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[0];
  _rtXdot->Internal_CSTATE_e[0] += Simulink_Horizontal_Control_P.Internal_A_p[1]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[1];
  _rtXdot->Internal_CSTATE_e[1] += Simulink_Horizontal_Control_P.Internal_A_p[2]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[0];
  _rtXdot->Internal_CSTATE_e[1] += Simulink_Horizontal_Control_P.Internal_A_p[3]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[1];
  _rtXdot->Internal_CSTATE_e[1] += Simulink_Horizontal_Control_P.Internal_A_p[4]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[2];
  _rtXdot->Internal_CSTATE_e[1] += Simulink_Horizontal_Control_P.Internal_A_p[5]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[3];
  _rtXdot->Internal_CSTATE_e[2] += Simulink_Horizontal_Control_P.Internal_A_p[6]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[2];
  _rtXdot->Internal_CSTATE_e[2] += Simulink_Horizontal_Control_P.Internal_A_p[7]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[3];
  _rtXdot->Internal_CSTATE_e[3] += Simulink_Horizontal_Control_P.Internal_A_p[8]
    * Simulink_Horizontal_Control_X.Internal_CSTATE_e[3];
  _rtXdot->Internal_CSTATE_e[3] += Simulink_Horizontal_Control_P.Internal_B_n *
    Simulink_Horizontal_Control_B.error_a;
}

/* Model initialize function */
void Simulink_Horizontal_Control_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Simulink_Horizontal_Control_M, 0,
                sizeof(RT_MODEL_Simulink_Horizontal__T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Simulink_Horizontal_Control_M->solverInfo,
                          &Simulink_Horizontal_Control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Simulink_Horizontal_Control_M->solverInfo, &rtmGetTPtr
                (Simulink_Horizontal_Control_M));
    rtsiSetStepSizePtr(&Simulink_Horizontal_Control_M->solverInfo,
                       &Simulink_Horizontal_Control_M->Timing.stepSize0);
    rtsiSetdXPtr(&Simulink_Horizontal_Control_M->solverInfo,
                 &Simulink_Horizontal_Control_M->derivs);
    rtsiSetContStatesPtr(&Simulink_Horizontal_Control_M->solverInfo, (real_T **)
                         &Simulink_Horizontal_Control_M->contStates);
    rtsiSetNumContStatesPtr(&Simulink_Horizontal_Control_M->solverInfo,
      &Simulink_Horizontal_Control_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Simulink_Horizontal_Control_M->solverInfo,
      &Simulink_Horizontal_Control_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&Simulink_Horizontal_Control_M->solverInfo,
       &Simulink_Horizontal_Control_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Simulink_Horizontal_Control_M->solverInfo,
      &Simulink_Horizontal_Control_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Simulink_Horizontal_Control_M->solverInfo,
                          (&rtmGetErrorStatus(Simulink_Horizontal_Control_M)));
    rtsiSetRTModelPtr(&Simulink_Horizontal_Control_M->solverInfo,
                      Simulink_Horizontal_Control_M);
  }

  rtsiSetSimTimeStep(&Simulink_Horizontal_Control_M->solverInfo, MAJOR_TIME_STEP);
  Simulink_Horizontal_Control_M->intgData.f[0] =
    Simulink_Horizontal_Control_M->odeF[0];
  Simulink_Horizontal_Control_M->contStates = ((X_Simulink_Horizontal_Control_T *)
    &Simulink_Horizontal_Control_X);
  rtsiSetSolverData(&Simulink_Horizontal_Control_M->solverInfo, (void *)
                    &Simulink_Horizontal_Control_M->intgData);
  rtsiSetSolverName(&Simulink_Horizontal_Control_M->solverInfo,"ode1");
  rtmSetTPtr(Simulink_Horizontal_Control_M,
             &Simulink_Horizontal_Control_M->Timing.tArray[0]);
  rtmSetTFinal(Simulink_Horizontal_Control_M, -1);
  Simulink_Horizontal_Control_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Simulink_Horizontal_Control_M->Sizes.checksums[0] = (3830886438U);
  Simulink_Horizontal_Control_M->Sizes.checksums[1] = (629539251U);
  Simulink_Horizontal_Control_M->Sizes.checksums[2] = (4123486669U);
  Simulink_Horizontal_Control_M->Sizes.checksums[3] = (3817867681U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Simulink_Horizontal_Control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Simulink_Horizontal_Control_M->extModeInfo,
      &Simulink_Horizontal_Control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Simulink_Horizontal_Control_M->extModeInfo,
                        Simulink_Horizontal_Control_M->Sizes.checksums);
    rteiSetTPtr(Simulink_Horizontal_Control_M->extModeInfo, rtmGetTPtr
                (Simulink_Horizontal_Control_M));
  }

  /* block I/O */
  {
    Simulink_Horizontal_Control_B.alpharad = 0.0;
    Simulink_Horizontal_Control_B.StateSpace[0] = 0.0;
    Simulink_Horizontal_Control_B.StateSpace[1] = 0.0;
    Simulink_Horizontal_Control_B.StateSpace[2] = 0.0;
    Simulink_Horizontal_Control_B.StateSpace[3] = 0.0;
    Simulink_Horizontal_Control_B.Sum = 0.0;
    Simulink_Horizontal_Control_B.Referencetheta = 0.0;
    Simulink_Horizontal_Control_B.thetarad = 0.0;
    Simulink_Horizontal_Control_B.error = 0.0;
    Simulink_Horizontal_Control_B.error_a = 0.0;
    Simulink_Horizontal_Control_B.Internal = 0.0;
    Simulink_Horizontal_Control_B.Gain = 0.0;
    Simulink_Horizontal_Control_B.Switch1 = 0.0;
    Simulink_Horizontal_Control_B.Gain2 = 0.0;
    Simulink_Horizontal_Control_B.Switch1_m = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&Simulink_Horizontal_Control_X, 0,
                  sizeof(X_Simulink_Horizontal_Control_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Simulink_Horizontal_Control_DW, 0,
                sizeof(DW_Simulink_Horizontal_Contro_T));
  Simulink_Horizontal_Control_DW.HILInitialize_AOVoltages[0] = 0.0;
  Simulink_Horizontal_Control_DW.HILInitialize_AOVoltages[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Simulink_Horizontal_Control_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Simulink_Horizontal_Control/HIL Initialize (hil_initialize_block) */
  {
    static const t_uint analog_input_channels[2U] = {
      0
      , 1
    };

    static const t_double analog_input_minimums[2U] = {
      -10.0
      , -10.0
    };

    static const t_double analog_input_maximums[2U] = {
      10.0
      , 10.0
    };

    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    static const t_double analog_output_minimums[2U] = {
      -10.0
      , -10.0
    };

    static const t_double analog_output_maximums[2U] = {
      10.0
      , 10.0
    };

    static const t_double initial_analog_outputs[2U] = {
      0.0
      , 0.0
    };

    static const t_uint encoder_input_channels[2U] = {
      0
      , 1
    };

    static const t_encoder_quadrature_mode encoder_quadrature[2U] = {
      ENCODER_QUADRATURE_4X
      , ENCODER_QUADRATURE_4X
    };

    static const t_int32 initial_encoder_counts[2U] = {
      0
      , 0
    };

    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &Simulink_Horizontal_Control_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Simulink_Horizontal_Control_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (Simulink_Horizontal_Control_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_input_ranges
        (Simulink_Horizontal_Control_DW.HILInitialize_Card,
         analog_input_channels, 2U,
         analog_input_minimums, analog_input_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges
        (Simulink_Horizontal_Control_DW.HILInitialize_Card,
         analog_output_channels, 2U,
         analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog
        (Simulink_Horizontal_Control_DW.HILInitialize_Card,
         analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (Simulink_Horizontal_Control_DW.HILInitialize_Card,
         encoder_input_channels, 2U, (t_encoder_quadrature_mode *)
         encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts
        (Simulink_Horizontal_Control_DW.HILInitialize_Card,
         encoder_input_channels, 2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/Encoders' */

  /* S-Function Block: Simulink_Horizontal_Control/Encoders (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (Simulink_Horizontal_Control_DW.HILInitialize_Card,
       Simulink_Horizontal_Control_P.Encoders_samples_in_buffer,
       Simulink_Horizontal_Control_P.Encoders_channels, 2,
       &Simulink_Horizontal_Control_DW.Encoders_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
    }
  }

  /* InitializeConditions for StateSpace: '<S5>/State-Space' */
  Simulink_Horizontal_Control_X.StateSpace_CSTATE[0] =
    Simulink_Horizontal_Control_P.StateSpace_InitialCondition;

  /* InitializeConditions for StateSpace: '<S3>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE[0] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition;

  /* InitializeConditions for StateSpace: '<S4>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE_e[0] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition_j;

  /* InitializeConditions for StateSpace: '<S5>/State-Space' */
  Simulink_Horizontal_Control_X.StateSpace_CSTATE[1] =
    Simulink_Horizontal_Control_P.StateSpace_InitialCondition;

  /* InitializeConditions for StateSpace: '<S3>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE[1] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition;

  /* InitializeConditions for StateSpace: '<S4>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE_e[1] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition_j;

  /* InitializeConditions for StateSpace: '<S5>/State-Space' */
  Simulink_Horizontal_Control_X.StateSpace_CSTATE[2] =
    Simulink_Horizontal_Control_P.StateSpace_InitialCondition;

  /* InitializeConditions for StateSpace: '<S3>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE[2] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition;

  /* InitializeConditions for StateSpace: '<S4>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE_e[2] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition_j;

  /* InitializeConditions for StateSpace: '<S5>/State-Space' */
  Simulink_Horizontal_Control_X.StateSpace_CSTATE[3] =
    Simulink_Horizontal_Control_P.StateSpace_InitialCondition;

  /* InitializeConditions for StateSpace: '<S3>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE[3] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition;

  /* InitializeConditions for StateSpace: '<S4>/Internal' */
  Simulink_Horizontal_Control_X.Internal_CSTATE_e[3] =
    Simulink_Horizontal_Control_P.Internal_InitialCondition_j;
}

/* Model terminate function */
void Simulink_Horizontal_Control_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Simulink_Horizontal_Control/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(Simulink_Horizontal_Control_DW.HILInitialize_Card);
    hil_monitor_stop_all(Simulink_Horizontal_Control_DW.HILInitialize_Card);
    is_switching = false;
    if ((Simulink_Horizontal_Control_P.HILInitialize_AOTerminate &&
         !is_switching) || (Simulink_Horizontal_Control_P.HILInitialize_AOExit &&
         is_switching)) {
      Simulink_Horizontal_Control_DW.HILInitialize_AOVoltages[0] =
        Simulink_Horizontal_Control_P.HILInitialize_AOFinal;
      Simulink_Horizontal_Control_DW.HILInitialize_AOVoltages[1] =
        Simulink_Horizontal_Control_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog
        (Simulink_Horizontal_Control_DW.HILInitialize_Card,
         analog_output_channels, num_final_analog_outputs,
         &Simulink_Horizontal_Control_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Simulink_Horizontal_Control_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Simulink_Horizontal_Control_DW.HILInitialize_Card);
    hil_monitor_delete_all(Simulink_Horizontal_Control_DW.HILInitialize_Card);
    hil_close(Simulink_Horizontal_Control_DW.HILInitialize_Card);
    Simulink_Horizontal_Control_DW.HILInitialize_Card = NULL;
  }
}
