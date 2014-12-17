#ifndef __c3_Engine_Vehicle_CVT_RS_System2_h__
#define __c3_Engine_Vehicle_CVT_RS_System2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct
#define typedef_SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_ENGINE_STOP;
  uint8_T c3_tp_ENGINE_StartRequest;
  uint8_T c3_tp_ENGINE_Run;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_Engine_Vehicle_CVT_RS_System2;
  uint8_T c3_is_c3_Engine_Vehicle_CVT_RS_System2;
  real_T c3_StartRequest;
  real_T c3_Run;
  real_T c3_STOP;
  real_T c3_temporalCounter_i1;
  real_T c3_presentTime;
  real_T c3_elapsedTime;
  real_T c3_previousTime;
  boolean_T c3_dataWrittenToVector[3];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T *c3_EngineMode;
  real_T *c3_TorqueOut;
  real_T *c3_Engine_RPM;
  real_T *c3_ThrottleRequested;
  real_T *c3_doEngineStarter;
} SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct;

#endif                                 /*typedef_SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Engine_Vehicle_CVT_RS_System2_get_check_sum(mxArray *plhs[]);
extern void c3_Engine_Vehicle_CVT_RS_System2_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
