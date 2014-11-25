#ifndef __c1_untitled1_h__
#define __c1_untitled1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_untitled1InstanceStruct
#define typedef_SFc1_untitled1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_ENGINE_STOP;
  uint8_T c1_tp_ENGINE_StartRequest;
  uint8_T c1_tp_ENGINE_Run;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_untitled1;
  uint8_T c1_is_c1_untitled1;
  real_T c1_IntialTimer;
  real_T c1_StartRequest;
  real_T c1_Run;
  real_T c1_STOP;
  boolean_T c1_dataWrittenToVector[4];
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  real_T *c1_time;
  real_T *c1_EngineMode;
  real_T *c1_TorqueOut;
  real_T *c1_Engine_RPM;
  real_T *c1_ThrottleRequested;
  real_T *c1_doEngineStarter;
} SFc1_untitled1InstanceStruct;

#endif                                 /*typedef_SFc1_untitled1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_untitled1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_untitled1_get_check_sum(mxArray *plhs[]);
extern void c1_untitled1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
