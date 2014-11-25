#ifndef __c2_untitled1_h__
#define __c2_untitled1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_untitled1InstanceStruct
#define typedef_SFc2_untitled1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_ENGINE_STOP;
  uint8_T c2_tp_ENGINE_StartRequest;
  uint8_T c2_tp_ENGINE_Run;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_untitled1;
  uint8_T c2_is_c2_untitled1;
  real_T c2_StartRequest;
  real_T c2_Run;
  real_T c2_STOP;
  real_T c2_temporalCounter_i1;
  real_T c2_presentTime;
  real_T c2_elapsedTime;
  real_T c2_previousTime;
  boolean_T c2_dataWrittenToVector[3];
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  real_T *c2_EngineMode;
  real_T *c2_TorqueOut;
  real_T *c2_Engine_RPM;
  real_T *c2_ThrottleRequested;
  real_T *c2_doEngineStarter;
} SFc2_untitled1InstanceStruct;

#endif                                 /*typedef_SFc2_untitled1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_untitled1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_untitled1_get_check_sum(mxArray *plhs[]);
extern void c2_untitled1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
