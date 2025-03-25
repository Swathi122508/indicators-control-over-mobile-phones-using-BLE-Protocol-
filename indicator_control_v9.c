/*
 * File: indicator_control_v9.c
 *
 * Code generated for Simulink model 'indicator_control_v9'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Mar 25 12:50:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "indicator_control_v9.h"
#include "indicator_control_v9_private.h"

/* Block states (auto storage) */
DW_indicator_control_v9_T indicator_control_v9_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_indicator_control_v9_T indicator_control_v9_Y;

/* Real-time model */
RT_MODEL_indicator_control_v9_T indicator_control_v9_M_;
RT_MODEL_indicator_control_v9_T *const indicator_control_v9_M =
  &indicator_control_v9_M_;

/* Model step function */
void indicator_control_v9_step(void)
{
  /* MATLAB Function: '<Root>/Indicator_Logic' incorporates:
   *  UnitDelay: '<Root>/Debounce_Hazard'
   *  UnitDelay: '<Root>/Debounce_Left'
   *  UnitDelay: '<Root>/Debounce_Right'
   */
  /* MATLAB Function 'Indicator_Logic': '<S1>:1' */
  /*  Indicator Control Logic */
  /*  Declare persistent variables to maintain state across time steps */
  /*  Initialize if empty, set as logical type */
  /*  Indicator logic */
  if (indicator_control_v9_DW.Debounce_Left_DSTATE == 1.0) {
    /* '<S1>:1:15' */
    /* '<S1>:1:16' */
    indicator_control_v9_DW.left_state = !indicator_control_v9_DW.left_state;

    /*  Toggle left indicator */
    /* '<S1>:1:17' */
    indicator_control_v9_DW.right_state = false;

    /*  Turn off right indicator */
  } else {
    if (indicator_control_v9_DW.Debounce_Right_DSTATE == 1.0) {
      /* '<S1>:1:18' */
      /* '<S1>:1:19' */
      indicator_control_v9_DW.right_state = !indicator_control_v9_DW.right_state;

      /*  Toggle right indicator */
      /* '<S1>:1:20' */
      indicator_control_v9_DW.left_state = false;

      /*  Turn off left indicator */
    }
  }

  /*  Hazard logic (both buttons pressed) */
  if (indicator_control_v9_DW.Debounce_Hazard_DSTATE == 1.0) {
    /* '<S1>:1:24' */
    /* '<S1>:1:25' */
    indicator_control_v9_DW.hazard_active =
      !indicator_control_v9_DW.hazard_active;

    /*  Toggle hazard state */
    /* '<S1>:1:26' */
    indicator_control_v9_DW.left_state = indicator_control_v9_DW.hazard_active;

    /*  Both indicators ON/OFF */
    /* '<S1>:1:27' */
    indicator_control_v9_DW.right_state = indicator_control_v9_DW.hazard_active;
  }

  /* Outport: '<Root>/Left_PWM' incorporates:
   *  MATLAB Function: '<Root>/Indicator_Logic'
   */
  /*  Assign output values, convert logical to double for PWM */
  /* '<S1>:1:31' */
  /*  Left LED PWM value */
  /* '<S1>:1:32' */
  /*  Right LED PWM value */
  /* '<S1>:1:33' */
  indicator_control_v9_Y.Left_PWM = indicator_control_v9_DW.left_state;

  /* Outport: '<Root>/Right_PWM' incorporates:
   *  MATLAB Function: '<Root>/Indicator_Logic'
   */
  indicator_control_v9_Y.Right_PWM = indicator_control_v9_DW.right_state;

  /* ManualSwitch: '<Root>/Left_Button' */
  if (indicator_control_v9_P.Left_Button_CurrentSetting == 1) {
    /* Update for UnitDelay: '<Root>/Debounce_Left' incorporates:
     *  Constant: '<Root>/Constant'
     */
    indicator_control_v9_DW.Debounce_Left_DSTATE =
      indicator_control_v9_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<Root>/Debounce_Left' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    indicator_control_v9_DW.Debounce_Left_DSTATE =
      indicator_control_v9_P.Constant5_Value;
  }

  /* End of ManualSwitch: '<Root>/Left_Button' */

  /* ManualSwitch: '<Root>/Right_Button' */
  if (indicator_control_v9_P.Right_Button_CurrentSetting == 1) {
    /* Update for UnitDelay: '<Root>/Debounce_Right' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    indicator_control_v9_DW.Debounce_Right_DSTATE =
      indicator_control_v9_P.Constant1_Value;
  } else {
    /* Update for UnitDelay: '<Root>/Debounce_Right' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    indicator_control_v9_DW.Debounce_Right_DSTATE =
      indicator_control_v9_P.Constant2_Value;
  }

  /* End of ManualSwitch: '<Root>/Right_Button' */

  /* ManualSwitch: '<Root>/Hazard_Button' */
  if (indicator_control_v9_P.Hazard_Button_CurrentSetting == 1) {
    /* Update for UnitDelay: '<Root>/Debounce_Hazard' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    indicator_control_v9_DW.Debounce_Hazard_DSTATE =
      indicator_control_v9_P.Constant3_Value;
  } else {
    /* Update for UnitDelay: '<Root>/Debounce_Hazard' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    indicator_control_v9_DW.Debounce_Hazard_DSTATE =
      indicator_control_v9_P.Constant4_Value;
  }

  /* End of ManualSwitch: '<Root>/Hazard_Button' */
}

/* Model initialize function */
void indicator_control_v9_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(indicator_control_v9_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&indicator_control_v9_DW, 0,
                sizeof(DW_indicator_control_v9_T));

  /* external outputs */
  (void) memset((void *)&indicator_control_v9_Y, 0,
                sizeof(ExtY_indicator_control_v9_T));

  /* InitializeConditions for UnitDelay: '<Root>/Debounce_Left' */
  indicator_control_v9_DW.Debounce_Left_DSTATE =
    indicator_control_v9_P.Debounce_Left_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Debounce_Right' */
  indicator_control_v9_DW.Debounce_Right_DSTATE =
    indicator_control_v9_P.Debounce_Right_InitialCondition;

  /* InitializeConditions for UnitDelay: '<Root>/Debounce_Hazard' */
  indicator_control_v9_DW.Debounce_Hazard_DSTATE =
    indicator_control_v9_P.Debounce_Hazard_InitialConditio;

  /* InitializeConditions for MATLAB Function: '<Root>/Indicator_Logic' */
  indicator_control_v9_DW.left_state = false;
  indicator_control_v9_DW.right_state = false;
  indicator_control_v9_DW.hazard_active = false;
}

/* Model terminate function */
void indicator_control_v9_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
