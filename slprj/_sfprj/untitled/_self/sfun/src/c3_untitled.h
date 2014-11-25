#ifndef __c3_untitled_h__
#define __c3_untitled_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_untitledInstanceStruct
#define typedef_SFc3_untitledInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_System_Initialization;
  uint8_T c3_tp_ON;
  uint8_T c3_tp_FailState;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_untitled;
  uint8_T c3_is_c3_untitled;
  real_T c3_GREEN;
  real_T c3_ORANGE;
  real_T c3_RED;
  real_T c3_temporalCounter_i1;
  real_T c3_presentTime;
  real_T c3_elapsedTime;
  real_T c3_previousTime;
  boolean_T c3_dataWrittenToVector[2];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T (*c3_sensors)[3];
  real_T *c3_partsFed;
  real_T *c3_Light;
  real_T *c3_Alarm;
} SFc3_untitledInstanceStruct;

#endif                                 /*typedef_SFc3_untitledInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_untitled_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_untitled_get_check_sum(mxArray *plhs[]);
extern void c3_untitled_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
