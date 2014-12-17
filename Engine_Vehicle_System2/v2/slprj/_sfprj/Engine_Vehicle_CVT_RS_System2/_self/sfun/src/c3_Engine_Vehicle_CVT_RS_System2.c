/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Engine_Vehicle_CVT_RS_System2_sfun.h"
#include "c3_Engine_Vehicle_CVT_RS_System2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Engine_Vehicle_CVT_RS_System2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_ENGINE_Run               ((uint8_T)1U)
#define c3_IN_ENGINE_STOP              ((uint8_T)2U)
#define c3_IN_ENGINE_StartRequest      ((uint8_T)3U)
#define c3_const_StartRequest          (2.0)
#define c3_const_Run                   (3.0)
#define c3_const_STOP                  (1.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void initialize_params_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void enable_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void disable_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void set_sim_state_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void finalize_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void sf_gateway_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void mdl_start_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void c3_chartstep_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void initSimStructsc3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_e_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_b_tp_ENGINE_STOP, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_g_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier, boolean_T
   c3_y[3]);
static void c3_h_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[3]);
static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber, uint32_T c3_ssIdOfSourceObject,
   int32_T c3_offsetInSourceObject, int32_T c3_lengthInSourceObject);
static void init_dsm_address_info
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_ENGINE_Run = 0U;
  chartInstance->c3_tp_ENGINE_STOP = 0U;
  chartInstance->c3_temporalCounter_i1 = 0.0;
  chartInstance->c3_tp_ENGINE_StartRequest = 0U;
  chartInstance->c3_temporalCounter_i1 = 0.0;
  chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System2 = 0U;
  chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_StartRequest = 2.0;
  chartInstance->c3_Run = 3.0;
  chartInstance->c3_STOP = 1.0;
  chartInstance->c3_presentTime = 0.0;
  chartInstance->c3_elapsedTime = 0.0;
  chartInstance->c3_previousTime = 0.0;
}

static void initialize_params_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTime = _sfTime_;
  chartInstance->c3_previousTime = chartInstance->c3_presentTime;
}

static void disable_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTime = _sfTime_;
  chartInstance->c3_elapsedTime = chartInstance->c3_presentTime -
    chartInstance->c3_previousTime;
  chartInstance->c3_previousTime = chartInstance->c3_presentTime;
  chartInstance->c3_temporalCounter_i1 += chartInstance->c3_elapsedTime;
}

static void c3_update_debugger_state_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System2 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 == c3_IN_ENGINE_STOP)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 ==
      c3_IN_ENGINE_StartRequest) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 == c3_IN_ENGINE_Run)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  int32_T c3_i0;
  boolean_T c3_h_u[3];
  const mxArray *c3_i_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(8, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_EngineMode;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_TorqueOut;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *chartInstance->c3_doEngineStarter;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal =
    chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System2;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_previousTime;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    c3_h_u[c3_i0] = chartInstance->c3_dataWrittenToVector[c3_i0];
  }

  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_h_u, 11, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[3];
  int32_T c3_i1;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_EngineMode = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "EngineMode");
  *chartInstance->c3_TorqueOut = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "TorqueOut");
  *chartInstance->c3_doEngineStarter = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "doEngineStarter");
  chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System2 =
    c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "is_active_c3_Engine_Vehicle_CVT_RS_System2");
  chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
     "is_c3_Engine_Vehicle_CVT_RS_System2");
  chartInstance->c3_temporalCounter_i1 = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 5)), "temporalCounter_i1");
  chartInstance->c3_previousTime = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "previousTime");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)),
                        "dataWrittenToVector", c3_bv0);
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    chartInstance->c3_dataWrittenToVector[c3_i1] = c3_bv0[c3_i1];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_Engine_Vehicle_CVT_RS_System2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 ==
        c3_IN_ENGINE_Run) {
      chartInstance->c3_tp_ENGINE_Run = 1U;
    } else {
      chartInstance->c3_tp_ENGINE_Run = 0U;
    }

    if (chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 ==
        c3_IN_ENGINE_STOP) {
      chartInstance->c3_tp_ENGINE_STOP = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0.0;
      }
    } else {
      chartInstance->c3_tp_ENGINE_STOP = 0U;
    }

    if (chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 ==
        c3_IN_ENGINE_StartRequest) {
      chartInstance->c3_tp_ENGINE_StartRequest = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0.0;
      }
    } else {
      chartInstance->c3_tp_ENGINE_StartRequest = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  c3_set_sim_state_side_effects_c3_Engine_Vehicle_CVT_RS_System2(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTime = _sfTime_;
  chartInstance->c3_elapsedTime = chartInstance->c3_presentTime -
    chartInstance->c3_previousTime;
  chartInstance->c3_previousTime = chartInstance->c3_presentTime;
  chartInstance->c3_temporalCounter_i1 += chartInstance->c3_elapsedTime;
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_EngineMode, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_TorqueOut, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Engine_RPM, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ThrottleRequested, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_doEngineStarter, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_StartRequest, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_Run, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_STOP, 7U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_Engine_Vehicle_CVT_RS_System2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Engine_Vehicle_CVT_RS_System2MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void mdl_start_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chartstep_c3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System2 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System2 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 = c3_IN_ENGINE_STOP;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i1 = 0.0;
    chartInstance->c3_tp_ENGINE_STOP = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_EngineMode = c3_const_STOP;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_EngineMode, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2) {
     case c3_IN_ENGINE_Run:
      CV_CHART_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_e_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard5 = false;
      if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
            *chartInstance->c3_ThrottleRequested, 0.1, -1, 2U,
            *chartInstance->c3_ThrottleRequested < 0.1))) {
        if (CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
              *chartInstance->c3_Engine_RPM, 800.0, -1, 2U,
              *chartInstance->c3_Engine_RPM < 800.0))) {
          CV_EML_MCDC(3, 0, 0, true);
          CV_EML_IF(3, 0, 0, true);
          c3_out = true;
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }

      if (guard5 == true) {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c3_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_ENGINE_Run = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 =
          c3_IN_ENGINE_STOP;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0.0;
        chartInstance->c3_tp_ENGINE_STOP = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_EngineMode = c3_const_STOP;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_EngineMode, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_ENGINE_STOP:
      CV_CHART_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
            *chartInstance->c3_Engine_RPM, 800.0, -1, 2U,
            *chartInstance->c3_Engine_RPM < 800.0))) {
        if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1,
              *chartInstance->c3_ThrottleRequested, 0.1, -1, 4U,
              *chartInstance->c3_ThrottleRequested > 0.1))) {
          if (CV_EML_COND(1, 0, 2, chartInstance->c3_temporalCounter_i1 +
                          (_sfTime_ - chartInstance->c3_previousTime) >= 2.0)) {
            CV_EML_MCDC(1, 0, 0, true);
            CV_EML_IF(1, 0, 0, true);
            c3_b_out = true;
          } else {
            guard3 = true;
          }
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c3_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_ENGINE_STOP = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 =
          c3_IN_ENGINE_StartRequest;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0.0;
        chartInstance->c3_tp_ENGINE_StartRequest = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_EngineMode = c3_const_StartRequest;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_EngineMode, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_ENGINE_StartRequest:
      CV_CHART_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_c_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
        *chartInstance->c3_Engine_RPM, 800.0, -1, 4U,
        *chartInstance->c3_Engine_RPM > 800.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_ENGINE_StartRequest = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 = c3_IN_ENGINE_Run;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_ENGINE_Run = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_EngineMode = c3_const_Run;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_EngineMode, 0U);
        *chartInstance->c3_doEngineStarter = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_doEngineStarter, 4U);
        *chartInstance->c3_TorqueOut = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_TorqueOut, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_f_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard1 = false;
        guard2 = false;
        if (CV_EML_COND(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0,
              *chartInstance->c3_Engine_RPM, 800.0, -1, 2U,
              *chartInstance->c3_Engine_RPM < 800.0))) {
          if (CV_EML_COND(4, 0, 1, CV_RELATIONAL_EVAL(5U, 4U, 1,
                *chartInstance->c3_doEngineStarter, 0.0, -1, 0U,
                *chartInstance->c3_doEngineStarter == 0.0))) {
            if (CV_EML_COND(4, 0, 2, chartInstance->c3_temporalCounter_i1 +
                            (_sfTime_ - chartInstance->c3_previousTime) >= 5.0))
            {
              CV_EML_MCDC(4, 0, 0, true);
              CV_EML_IF(4, 0, 0, true);
              c3_d_out = true;
            } else {
              guard1 = true;
            }
          } else {
            guard2 = true;
          }
        } else {
          c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 26U, 24, 15);
          guard2 = true;
        }

        if (guard2 == true) {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(4, 0, 0, false);
          CV_EML_IF(4, 0, 0, false);
          c3_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_ENGINE_StartRequest = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 =
            c3_IN_ENGINE_STOP;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
          chartInstance->c3_temporalCounter_i1 = 0.0;
          chartInstance->c3_tp_ENGINE_STOP = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_EngineMode = c3_const_STOP;
          c3_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_EngineMode, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          if (CV_EML_IF(2, 1, 0, chartInstance->c3_temporalCounter_i1 +
                        (_sfTime_ - chartInstance->c3_previousTime) < 1.0)) {
            *chartInstance->c3_doEngineStarter = 1.0;
            c3_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c3_doEngineStarter, 4U);
            *chartInstance->c3_TorqueOut = 5.0;
            c3_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c3_TorqueOut, 1U);
          } else {
            *chartInstance->c3_doEngineStarter = 0.0;
            c3_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c3_doEngineStarter, 4U);
            *chartInstance->c3_TorqueOut = 0.0;
            c3_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c3_TorqueOut, 1U);
          }

          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      chartInstance->c3_is_c3_Engine_Vehicle_CVT_RS_System2 =
        c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_Engine_Vehicle_CVT_RS_System2
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray
  *sf_c3_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i2, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_e_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_b_tp_ENGINE_STOP, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_ENGINE_STOP),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_ENGINE_STOP);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_ENGINE_STOP;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
    chartInstanceVoid;
  c3_b_tp_ENGINE_STOP = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_ENGINE_STOP),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_ENGINE_STOP);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_g_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier, boolean_T
   c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_h_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[3])
{
  boolean_T c3_bv1[3];
  int32_T c3_i3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 3);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_y[c3_i3] = c3_bv1[c3_i3];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex)
{
  chartInstance->c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0U,
    (int32_T)c3_vectorIndex, 0, 2, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber, uint32_T c3_ssIdOfSourceObject,
   int32_T c3_offsetInSourceObject, int32_T c3_lengthInSourceObject)
{
  (void)c3_ssIdOfSourceObject;
  (void)c3_offsetInSourceObject;
  (void)c3_lengthInSourceObject;
  if (!chartInstance->c3_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c3_vectorIndex, 0, 2, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c3_dataNumber);
  }
}

static void init_dsm_address_info
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance)
{
  chartInstance->c3_EngineMode = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_TorqueOut = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_Engine_RPM = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_ThrottleRequested = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_doEngineStarter = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_Engine_Vehicle_CVT_RS_System2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4014179864U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(728548485U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2400741867U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3649987861U);
}

mxArray* sf_c3_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info(void);
mxArray *sf_c3_Engine_Vehicle_CVT_RS_System2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7opRodR3K0lOrnpKN1yOQD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Engine_Vehicle_CVT_RS_System2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Engine_Vehicle_CVT_RS_System2_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_Engine_Vehicle_CVT_RS_System2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_Engine_Vehicle_CVT_RS_System2
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[10],T\"EngineMode\",},{M[1],M[11],T\"TorqueOut\",},{M[1],M[16],T\"doEngineStarter\",},{M[8],M[0],T\"is_active_c3_Engine_Vehicle_CVT_RS_System2\",},{M[9],M[0],T\"is_c3_Engine_Vehicle_CVT_RS_System2\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[4 3],M[1]}}},{M[13],M[0],T\"previousTime\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Engine_Vehicle_CVT_RS_System2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Engine_Vehicle_CVT_RS_System2MachineNumber_,
           3,
           3,
           5,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_Engine_Vehicle_CVT_RS_System2MachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Engine_Vehicle_CVT_RS_System2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Engine_Vehicle_CVT_RS_System2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"EngineMode");
          _SFD_SET_DATA_PROPS(1,2,0,1,"TorqueOut");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Engine_RPM");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ThrottleRequested");
          _SFD_SET_DATA_PROPS(4,2,0,1,"doEngineStarter");
          _SFD_SET_DATA_PROPS(5,7,0,0,"StartRequest");
          _SFD_SET_DATA_PROPS(6,7,0,0,"Run");
          _SFD_SET_DATA_PROPS(7,7,0,0,"STOP");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,1,0,62,78,128,180);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,48,1,48);

        {
          static int condStart[] = { 1, 32 };

          static int condEnd[] = { 23, 48 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,48,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,23,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,1,32,48,-1,2);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,62,1,48);

        {
          static int condStart[] = { 1, 24, 50 };

          static int condEnd[] = { 16, 43, 62 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,62,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,16,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,1,24,43,-1,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,67,1,48);

        {
          static int condStart[] = { 1, 25, 55 };

          static int condEnd[] = { 17, 48, 67 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,67,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,17,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,25,48,-1,4);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,17,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_EngineMode);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_TorqueOut);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_Engine_RPM);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_ThrottleRequested);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_doEngineStarter);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c3_StartRequest);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c3_Run);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c3_STOP);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Engine_Vehicle_CVT_RS_System2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "lmpsj9PAuGSEZKfeJJw1D";
}

static void sf_opaque_initialize_c3_Engine_Vehicle_CVT_RS_System2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*) chartInstanceVar);
  initialize_c3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Engine_Vehicle_CVT_RS_System2(void
  *chartInstanceVar)
{
  enable_c3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Engine_Vehicle_CVT_RS_System2(void
  *chartInstanceVar)
{
  disable_c3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Engine_Vehicle_CVT_RS_System2(void
  *chartInstanceVar)
{
  sf_gateway_c3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Engine_Vehicle_CVT_RS_System2
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Engine_Vehicle_CVT_RS_System2(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*)chartInfo->chartInstance,
     st);
}

static void sf_opaque_terminate_c3_Engine_Vehicle_CVT_RS_System2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Engine_Vehicle_CVT_RS_System2_optimization_info();
    }

    finalize_c3_Engine_Vehicle_CVT_RS_System2
      ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Engine_Vehicle_CVT_RS_System2
    ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Engine_Vehicle_CVT_RS_System2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_Engine_Vehicle_CVT_RS_System2
      ((SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Engine_Vehicle_CVT_RS_System2(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Engine_Vehicle_CVT_RS_System2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1187348491U));
  ssSetChecksum1(S,(3821555038U));
  ssSetChecksum2(S,(3476142534U));
  ssSetChecksum3(S,(990275596U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Engine_Vehicle_CVT_RS_System2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_Engine_Vehicle_CVT_RS_System2(SimStruct *S)
{
  SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct *)utMalloc
    (sizeof(SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_Engine_Vehicle_CVT_RS_System2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Engine_Vehicle_CVT_RS_System2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_Engine_Vehicle_CVT_RS_System2_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Engine_Vehicle_CVT_RS_System2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Engine_Vehicle_CVT_RS_System2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Engine_Vehicle_CVT_RS_System2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Engine_Vehicle_CVT_RS_System2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
