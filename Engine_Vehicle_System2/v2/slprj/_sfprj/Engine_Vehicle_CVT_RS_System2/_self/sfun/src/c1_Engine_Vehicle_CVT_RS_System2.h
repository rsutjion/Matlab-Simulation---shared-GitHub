#ifndef __c1_Engine_Vehicle_CVT_RS_System2_h__
#define __c1_Engine_Vehicle_CVT_RS_System2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_Engine_Vehicle_CVT_RS_System2InstanceStruct
#define typedef_SFc1_Engine_Vehicle_CVT_RS_System2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Engine_Vehicle_CVT_RS_System2;
  boolean_T c1_dataWrittenToVector[1];
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  real_T *c1_Engine_RPM;
  real_T *c1_RPM_Clutch_THLD;
  real_T *c1_RPM_Clutch_Hist_THLD;
  real_T *c1_ClutchON;
} SFc1_Engine_Vehicle_CVT_RS_System2InstanceStruct;

#endif                                 /*typedef_SFc1_Engine_Vehicle_CVT_RS_System2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Engine_Vehicle_CVT_RS_System2_get_check_sum(mxArray *plhs[]);
extern void c1_Engine_Vehicle_CVT_RS_System2_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
