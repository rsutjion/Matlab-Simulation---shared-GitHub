#ifndef __c1_EVdemo_6_h__
#define __c1_EVdemo_6_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_EVdemo_6InstanceStruct
#define typedef_SFc1_EVdemo_6InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_Stop;
  uint8_T c1_tp_Accel;
  uint8_T c1_tp_Decel;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_EVdemo_6;
  uint8_T c1_is_c1_EVdemo_6;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_EVdemo_6InstanceStruct;

#endif                                 /*typedef_SFc1_EVdemo_6InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_EVdemo_6_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_EVdemo_6_get_check_sum(mxArray *plhs[]);
extern void c1_EVdemo_6_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
