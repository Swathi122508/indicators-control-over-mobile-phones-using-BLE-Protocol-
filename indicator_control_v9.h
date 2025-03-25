/*
 * File: indicator_control_v9.h
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

#ifndef RTW_HEADER_indicator_control_v9_h_
#define RTW_HEADER_indicator_control_v9_h_
#include <stddef.h>
#include <string.h>
#ifndef indicator_control_v9_COMMON_INCLUDES_
# define indicator_control_v9_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* indicator_control_v9_COMMON_INCLUDES_ */

#include "indicator_control_v9_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Debounce_Left_DSTATE;         /* '<Root>/Debounce_Left' */
  real_T Debounce_Right_DSTATE;        /* '<Root>/Debounce_Right' */
  real_T Debounce_Hazard_DSTATE;       /* '<Root>/Debounce_Hazard' */
  boolean_T left_state;                /* '<Root>/Indicator_Logic' */
  boolean_T right_state;               /* '<Root>/Indicator_Logic' */
  boolean_T hazard_active;             /* '<Root>/Indicator_Logic' */
} DW_indicator_control_v9_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Left_PWM;                     /* '<Root>/Left_PWM' */
  real_T Right_PWM;                    /* '<Root>/Right_PWM' */
} ExtY_indicator_control_v9_T;

/* Parameters (auto storage) */
struct P_indicator_control_v9_T_ {
  real_T Debounce_Left_InitialCondition;/* Expression: 0
                                         * Referenced by: '<Root>/Debounce_Left'
                                         */
  real_T Debounce_Right_InitialCondition;/* Expression: 0
                                          * Referenced by: '<Root>/Debounce_Right'
                                          */
  real_T Debounce_Hazard_InitialConditio;/* Expression: 0
                                          * Referenced by: '<Root>/Debounce_Hazard'
                                          */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  uint8_T Hazard_Button_CurrentSetting;/* Computed Parameter: Hazard_Button_CurrentSetting
                                        * Referenced by: '<Root>/Hazard_Button'
                                        */
  uint8_T Left_Button_CurrentSetting;  /* Computed Parameter: Left_Button_CurrentSetting
                                        * Referenced by: '<Root>/Left_Button'
                                        */
  uint8_T Right_Button_CurrentSetting; /* Computed Parameter: Right_Button_CurrentSetting
                                        * Referenced by: '<Root>/Right_Button'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_indicator_control_v9_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_indicator_control_v9_T indicator_control_v9_P;

/* Block states (auto storage) */
extern DW_indicator_control_v9_T indicator_control_v9_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_indicator_control_v9_T indicator_control_v9_Y;

/* Model entry point functions */
extern void indicator_control_v9_initialize(void);
extern void indicator_control_v9_step(void);
extern void indicator_control_v9_terminate(void);

/* Real-time Model object */
extern RT_MODEL_indicator_control_v9_T *const indicator_control_v9_M;

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
 * '<Root>' : 'indicator_control_v9'
 * '<S1>'   : 'indicator_control_v9/Indicator_Logic'
 */
#endif                                 /* RTW_HEADER_indicator_control_v9_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
