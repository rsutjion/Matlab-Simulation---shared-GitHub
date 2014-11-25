/* Include files */

#include <stddef.h>
#include "blas.h"
#include "untitled1_sfun.h"
#include "c2_untitled1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_ENGINE_Run               ((uint8_T)1U)
#define c2_IN_ENGINE_STOP              ((uint8_T)2U)
#define c2_IN_ENGINE_StartRequest      ((uint8_T)3U)
#define c2_const_StartRequest          (2.0)
#define c2_const_Run                   (3.0)
#define c2_const_STOP                  (1.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance);
static void initialize_params_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance);
static void enable_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance);
static void disable_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance);
static void set_sim_state_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_untitled1
  (SFc2_untitled1InstanceStruct *chartInstance);
static void finalize_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance);
static void sf_gateway_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance);
static void mdl_start_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance);
static void c2_chartstep_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance);
static void initSimStructsc2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_nargout, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_c_emlrt_marshallIn(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_b_tp_ENGINE_STOP, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_g_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_b_dataWrittenToVector, const char_T *c2_identifier,
  boolean_T c2_y[3]);
static void c2_h_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y[3]);
static const mxArray *c2_i_emlrt_marshallIn(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_j_emlrt_marshallIn(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_updateDataWrittenToVector(SFc2_untitled1InstanceStruct
  *chartInstance, uint32_T c2_vectorIndex);
static void c2_errorIfDataNotWrittenToFcn(SFc2_untitled1InstanceStruct
  *chartInstance, uint32_T c2_vectorIndex, uint32_T c2_dataNumber, uint32_T
  c2_ssIdOfSourceObject, int32_T c2_offsetInSourceObject, int32_T
  c2_lengthInSourceObject);
static void init_dsm_address_info(SFc2_untitled1InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_untitled1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_ENGINE_Run = 0U;
  chartInstance->c2_tp_ENGINE_STOP = 0U;
  chartInstance->c2_temporalCounter_i1 = 0.0;
  chartInstance->c2_tp_ENGINE_StartRequest = 0U;
  chartInstance->c2_temporalCounter_i1 = 0.0;
  chartInstance->c2_is_active_c2_untitled1 = 0U;
  chartInstance->c2_is_c2_untitled1 = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_StartRequest = 2.0;
  chartInstance->c2_Run = 3.0;
  chartInstance->c2_STOP = 1.0;
  chartInstance->c2_presentTime = 0.0;
  chartInstance->c2_elapsedTime = 0.0;
  chartInstance->c2_previousTime = 0.0;
}

static void initialize_params_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_presentTime = _sfTime_;
  chartInstance->c2_previousTime = chartInstance->c2_presentTime;
}

static void disable_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_presentTime = _sfTime_;
  chartInstance->c2_elapsedTime = chartInstance->c2_presentTime -
    chartInstance->c2_previousTime;
  chartInstance->c2_previousTime = chartInstance->c2_presentTime;
  chartInstance->c2_temporalCounter_i1 += chartInstance->c2_elapsedTime;
}

static void c2_update_debugger_state_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_untitled1 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_untitled1 == c2_IN_ENGINE_STOP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_untitled1 == c2_IN_ENGINE_StartRequest) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_untitled1 == c2_IN_ENGINE_Run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  int32_T c2_i0;
  boolean_T c2_h_u[3];
  const mxArray *c2_i_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(8, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_EngineMode;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *chartInstance->c2_TorqueOut;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *chartInstance->c2_doEngineStarter;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_untitled1;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_c2_untitled1;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = chartInstance->c2_previousTime;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_h_u[c2_i0] = chartInstance->c2_dataWrittenToVector[c2_i0];
  }

  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_h_u, 11, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T c2_bv0[3];
  int32_T c2_i1;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_EngineMode = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "EngineMode");
  *chartInstance->c2_TorqueOut = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "TorqueOut");
  *chartInstance->c2_doEngineStarter = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)), "doEngineStarter");
  chartInstance->c2_is_active_c2_untitled1 = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "is_active_c2_untitled1");
  chartInstance->c2_is_c2_untitled1 = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 4)), "is_c2_untitled1");
  chartInstance->c2_temporalCounter_i1 = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 5)), "temporalCounter_i1");
  chartInstance->c2_previousTime = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 6)), "previousTime");
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 7)),
                        "dataWrittenToVector", c2_bv0);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    chartInstance->c2_dataWrittenToVector[c2_i1] = c2_bv0[c2_i1];
  }

  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_untitled1(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_untitled1
  (SFc2_untitled1InstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_untitled1 == c2_IN_ENGINE_Run) {
      chartInstance->c2_tp_ENGINE_Run = 1U;
    } else {
      chartInstance->c2_tp_ENGINE_Run = 0U;
    }

    if (chartInstance->c2_is_c2_untitled1 == c2_IN_ENGINE_STOP) {
      chartInstance->c2_tp_ENGINE_STOP = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0.0;
      }
    } else {
      chartInstance->c2_tp_ENGINE_STOP = 0U;
    }

    if (chartInstance->c2_is_c2_untitled1 == c2_IN_ENGINE_StartRequest) {
      chartInstance->c2_tp_ENGINE_StartRequest = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0.0;
      }
    } else {
      chartInstance->c2_tp_ENGINE_StartRequest = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance)
{
  c2_set_sim_state_side_effects_c2_untitled1(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_presentTime = _sfTime_;
  chartInstance->c2_elapsedTime = chartInstance->c2_presentTime -
    chartInstance->c2_previousTime;
  chartInstance->c2_previousTime = chartInstance->c2_presentTime;
  chartInstance->c2_temporalCounter_i1 += chartInstance->c2_elapsedTime;
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EngineMode, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_TorqueOut, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_Engine_RPM, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_ThrottleRequested, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_doEngineStarter, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_StartRequest, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_Run, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_STOP, 7U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_untitled1(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitled1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_untitled1(SFc2_untitled1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint32_T c2_b_debug_family_var_map[3];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 1.0;
  boolean_T c2_out;
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 0.0;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 1.0;
  boolean_T c2_b_out;
  real_T c2_e_nargin = 0.0;
  real_T c2_e_nargout = 0.0;
  real_T c2_f_nargin = 0.0;
  real_T c2_f_nargout = 1.0;
  boolean_T c2_c_out;
  real_T c2_g_nargin = 0.0;
  real_T c2_g_nargout = 0.0;
  real_T c2_h_nargin = 0.0;
  real_T c2_h_nargout = 1.0;
  boolean_T c2_d_out;
  real_T c2_i_nargin = 0.0;
  real_T c2_i_nargout = 0.0;
  real_T c2_j_nargin = 0.0;
  real_T c2_j_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_untitled1 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_untitled1 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_untitled1 = c2_IN_ENGINE_STOP;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0.0;
    chartInstance->c2_tp_ENGINE_STOP = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    *chartInstance->c2_EngineMode = c2_const_STOP;
    c2_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EngineMode, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c2_is_c2_untitled1) {
     case c2_IN_ENGINE_Run:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_e_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      guard5 = false;
      if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
            *chartInstance->c2_ThrottleRequested, 0.1, -1, 2U,
            *chartInstance->c2_ThrottleRequested < 0.1))) {
        if (CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
              *chartInstance->c2_Engine_RPM, 800.0, -1, 2U,
              *chartInstance->c2_Engine_RPM < 800.0))) {
          CV_EML_MCDC(3, 0, 0, true);
          CV_EML_IF(3, 0, 0, true);
          c2_out = true;
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }

      if (guard5 == true) {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c2_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c2_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_ENGINE_Run = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_untitled1 = c2_IN_ENGINE_STOP;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0.0;
        chartInstance->c2_tp_ENGINE_STOP = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
          c2_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
          c2_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U,
          c2_sf_marshallOut, c2_sf_marshallIn);
        *chartInstance->c2_EngineMode = c2_const_STOP;
        c2_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EngineMode, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c2_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_ENGINE_STOP:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_f_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
            *chartInstance->c2_Engine_RPM, 800.0, -1, 2U,
            *chartInstance->c2_Engine_RPM < 800.0))) {
        if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1,
              *chartInstance->c2_ThrottleRequested, 0.1, -1, 4U,
              *chartInstance->c2_ThrottleRequested > 0.1))) {
          if (CV_EML_COND(1, 0, 2, chartInstance->c2_temporalCounter_i1 +
                          (_sfTime_ - chartInstance->c2_previousTime) >= 2.0)) {
            CV_EML_MCDC(1, 0, 0, true);
            CV_EML_IF(1, 0, 0, true);
            c2_b_out = true;
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
        c2_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c2_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_ENGINE_STOP = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_untitled1 = c2_IN_ENGINE_StartRequest;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0.0;
        chartInstance->c2_tp_ENGINE_StartRequest = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_b_debug_family_names,
          c2_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_sf_marshallOut,
          c2_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U,
          c2_sf_marshallOut, c2_sf_marshallIn);
        *chartInstance->c2_EngineMode = c2_const_StartRequest;
        c2_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EngineMode, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c2_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_ENGINE_StartRequest:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_g_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_out, 2U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      c2_c_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
        *chartInstance->c2_Engine_RPM, 800.0, -1, 4U,
        *chartInstance->c2_Engine_RPM > 800.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c2_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_ENGINE_StartRequest = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_untitled1 = c2_IN_ENGINE_Run;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_ENGINE_Run = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_d_debug_family_names,
          c2_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_g_nargin, 0U, c2_sf_marshallOut,
          c2_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_g_nargout, 1U,
          c2_sf_marshallOut, c2_sf_marshallIn);
        *chartInstance->c2_EngineMode = c2_const_Run;
        c2_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EngineMode, 0U);
        *chartInstance->c2_doEngineStarter = 0.0;
        c2_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c2_doEngineStarter, 4U);
        *chartInstance->c2_TorqueOut = 0.0;
        c2_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c2_TorqueOut, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c2_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_h_debug_family_names,
          c2_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_h_nargin, 0U, c2_sf_marshallOut,
          c2_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_h_nargout, 1U,
          c2_sf_marshallOut, c2_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_out, 2U, c2_b_sf_marshallOut,
          c2_b_sf_marshallIn);
        guard1 = false;
        guard2 = false;
        if (CV_EML_COND(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0,
              *chartInstance->c2_Engine_RPM, 800.0, -1, 2U,
              *chartInstance->c2_Engine_RPM < 800.0))) {
          if (CV_EML_COND(4, 0, 1, CV_RELATIONAL_EVAL(5U, 4U, 1,
                *chartInstance->c2_doEngineStarter, 0.0, -1, 0U,
                *chartInstance->c2_doEngineStarter == 0.0))) {
            if (CV_EML_COND(4, 0, 2, chartInstance->c2_temporalCounter_i1 +
                            (_sfTime_ - chartInstance->c2_previousTime) >= 5.0))
            {
              CV_EML_MCDC(4, 0, 0, true);
              CV_EML_IF(4, 0, 0, true);
              c2_d_out = true;
            } else {
              guard1 = true;
            }
          } else {
            guard2 = true;
          }
        } else {
          c2_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 26U, 24, 15);
          guard2 = true;
        }

        if (guard2 == true) {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(4, 0, 0, false);
          CV_EML_IF(4, 0, 0, false);
          c2_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c2_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_ENGINE_StartRequest = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_untitled1 = c2_IN_ENGINE_STOP;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          chartInstance->c2_temporalCounter_i1 = 0.0;
          chartInstance->c2_tp_ENGINE_STOP = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
            c2_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i_nargin, 0U,
            c2_sf_marshallOut, c2_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i_nargout, 1U,
            c2_sf_marshallOut, c2_sf_marshallIn);
          *chartInstance->c2_EngineMode = c2_const_STOP;
          c2_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EngineMode, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c2_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_c_debug_family_names,
            c2_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_j_nargin, 0U,
            c2_sf_marshallOut, c2_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_j_nargout, 1U,
            c2_sf_marshallOut, c2_sf_marshallIn);
          if (CV_EML_IF(2, 1, 0, chartInstance->c2_temporalCounter_i1 +
                        (_sfTime_ - chartInstance->c2_previousTime) < 1.0)) {
            *chartInstance->c2_doEngineStarter = 1.0;
            c2_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c2_doEngineStarter, 4U);
          } else {
            *chartInstance->c2_doEngineStarter = 0.0;
            c2_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c2_doEngineStarter, 4U);
          }

          c2_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U, 4U, 141, 15);
          if (CV_EML_IF(2, 1, 1, *chartInstance->c2_doEngineStarter != 0.0)) {
            *chartInstance->c2_TorqueOut = 10.0;
            c2_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c2_TorqueOut, 1U);
          } else {
            *chartInstance->c2_TorqueOut = 0.0;
            c2_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c2_TorqueOut, 1U);
          }

          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c2_is_c2_untitled1 = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_untitled1(SFc2_untitled1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_nargout, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static boolean_T c2_c_emlrt_marshallIn(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sf_internal_predicateOutput;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_sf_internal_predicateOutput = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_sf_internal_predicateOutput), &c2_thisId);
  sf_mex_destroy(&c2_sf_internal_predicateOutput);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_untitled1_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i2;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i2, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_b_tp_ENGINE_STOP, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_ENGINE_STOP),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_ENGINE_STOP);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_ENGINE_STOP;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc2_untitled1InstanceStruct *)chartInstanceVoid;
  c2_b_tp_ENGINE_STOP = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_ENGINE_STOP),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_ENGINE_STOP);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_g_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_b_dataWrittenToVector, const char_T *c2_identifier,
  boolean_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dataWrittenToVector),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_dataWrittenToVector);
}

static void c2_h_emlrt_marshallIn(SFc2_untitled1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y[3])
{
  boolean_T c2_bv1[3];
  int32_T c2_i3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_bv1, 1, 11, 0U, 1, 0U, 1, 3);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_y[c2_i3] = c2_bv1[c2_i3];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_i_emlrt_marshallIn(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_j_emlrt_marshallIn(SFc2_untitled1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_updateDataWrittenToVector(SFc2_untitled1InstanceStruct
  *chartInstance, uint32_T c2_vectorIndex)
{
  chartInstance->c2_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0U,
    (int32_T)c2_vectorIndex, 0, 2, 1, 0)] = true;
}

static void c2_errorIfDataNotWrittenToFcn(SFc2_untitled1InstanceStruct
  *chartInstance, uint32_T c2_vectorIndex, uint32_T c2_dataNumber, uint32_T
  c2_ssIdOfSourceObject, int32_T c2_offsetInSourceObject, int32_T
  c2_lengthInSourceObject)
{
  (void)c2_ssIdOfSourceObject;
  (void)c2_offsetInSourceObject;
  (void)c2_lengthInSourceObject;
  if (!chartInstance->c2_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c2_vectorIndex, 0, 2, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c2_dataNumber);
  }
}

static void init_dsm_address_info(SFc2_untitled1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_untitled1InstanceStruct *chartInstance)
{
  chartInstance->c2_EngineMode = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_TorqueOut = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_Engine_RPM = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_ThrottleRequested = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_doEngineStarter = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c2_untitled1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2927330474U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1295284661U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(555320224U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1737080648U);
}

mxArray* sf_c2_untitled1_get_post_codegen_info(void);
mxArray *sf_c2_untitled1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aFs7AQ2j88PwhXKuF631KC");
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
    mxArray* mxPostCodegenInfo = sf_c2_untitled1_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_untitled1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_untitled1_jit_fallback_info(void)
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

mxArray *sf_c2_untitled1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_untitled1_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_untitled1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[10],T\"EngineMode\",},{M[1],M[11],T\"TorqueOut\",},{M[1],M[16],T\"doEngineStarter\",},{M[8],M[0],T\"is_active_c2_untitled1\",},{M[9],M[0],T\"is_c2_untitled1\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[4 3],M[1]}}},{M[13],M[0],T\"previousTime\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_untitled1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_untitled1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_untitled1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitled1MachineNumber_,
           2,
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
        init_script_number_translation(_untitled1MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_untitled1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _untitled1MachineNumber_,
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
        _SFD_CV_INIT_EML(2,1,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,1,0,62,78,104,137);
        _SFD_CV_INIT_EML_IF(2,1,1,138,156,177,204);
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
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_EngineMode);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_TorqueOut);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_Engine_RPM);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_ThrottleRequested);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_doEngineStarter);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c2_StartRequest);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c2_Run);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c2_STOP);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _untitled1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "RKnSpllrm7sShSODZFOToB";
}

static void sf_opaque_initialize_c2_untitled1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_untitled1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_untitled1((SFc2_untitled1InstanceStruct*)
    chartInstanceVar);
  initialize_c2_untitled1((SFc2_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_untitled1(void *chartInstanceVar)
{
  enable_c2_untitled1((SFc2_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_untitled1(void *chartInstanceVar)
{
  disable_c2_untitled1((SFc2_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_untitled1(void *chartInstanceVar)
{
  sf_gateway_c2_untitled1((SFc2_untitled1InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_untitled1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_untitled1((SFc2_untitled1InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_untitled1(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_untitled1((SFc2_untitled1InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_untitled1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_untitled1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled1_optimization_info();
    }

    finalize_c2_untitled1((SFc2_untitled1InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_untitled1((SFc2_untitled1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_untitled1(SimStruct *S)
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
    initialize_params_c2_untitled1((SFc2_untitled1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_untitled1(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3483092201U));
  ssSetChecksum1(S,(707175507U));
  ssSetChecksum2(S,(26381166U));
  ssSetChecksum3(S,(254752594U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_untitled1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_untitled1(SimStruct *S)
{
  SFc2_untitled1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_untitled1InstanceStruct *)utMalloc(sizeof
    (SFc2_untitled1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_untitled1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_untitled1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_untitled1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_untitled1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_untitled1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_untitled1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_untitled1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_untitled1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_untitled1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_untitled1;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_untitled1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_untitled1;
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

void c2_untitled1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_untitled1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_untitled1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_untitled1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_untitled1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
