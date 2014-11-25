#ifndef __c3_Engine_Vehicle_CVT_Wit_System1_trial1_h__
#define __c3_Engine_Vehicle_CVT_Wit_System1_trial1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_Engine_Vehicle_CVT_Wit_System1_trial1InstanceStruct
#define typedef_SFc3_Engine_Vehicle_CVT_Wit_System1_trial1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_Engine_Vehicle_CVT_Wit_System1_trial1;
  boolean_T c3_dataWrittenToVector[1];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T *c3_Engine_RPM;
  real_T *c3_RPM_Clutch_THLD;
  real_T *c3_RPM_Clutch_Hist_THLD;
  real_T *c3_ClutchON;
} SFc3_Engine_Vehicle_CVT_Wit_System1_trial1InstanceStruct;

#endif                                 /*typedef_SFc3_Engine_Vehicle_CVT_Wit_System1_trial1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_Engine_Vehicle_CVT_Wit_System1_trial1_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_Engine_Vehicle_CVT_Wit_System1_trial1_get_check_sum(mxArray
  *plhs[]);
extern void c3_Engine_Vehicle_CVT_Wit_System1_trial1_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
