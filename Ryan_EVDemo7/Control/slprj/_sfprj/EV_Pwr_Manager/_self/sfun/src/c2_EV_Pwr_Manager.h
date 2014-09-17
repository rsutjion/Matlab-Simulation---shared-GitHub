#ifndef __c2_EV_Pwr_Manager_h__
#define __c2_EV_Pwr_Manager_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_EV_Pwr_ManagerInstanceStruct
#define typedef_SFc2_EV_Pwr_ManagerInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_Stop;
  uint8_T c2_tp_Decel;
  uint8_T c2_tp_Accel;
  uint8_T c2_tp_Coast;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_EV_Pwr_Manager;
  uint8_T c2_is_c2_EV_Pwr_Manager;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_EV_Pwr_ManagerInstanceStruct;

#endif                                 /*typedef_SFc2_EV_Pwr_ManagerInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_EV_Pwr_Manager_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_EV_Pwr_Manager_get_check_sum(mxArray *plhs[]);
extern void c2_EV_Pwr_Manager_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
