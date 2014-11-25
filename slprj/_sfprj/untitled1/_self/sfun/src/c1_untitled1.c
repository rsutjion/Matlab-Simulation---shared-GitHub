/* Include files */

#include <stddef.h>
#include "blas.h"
#include "untitled1_sfun.h"
#include "c1_untitled1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_ENGINE_Run               ((uint8_T)1U)
#define c1_IN_ENGINE_STOP              ((uint8_T)2U)
#define c1_IN_ENGINE_StartRequest      ((uint8_T)3U)
#define c1_const_StartRequest          (2.0)
#define c1_const_Run                   (3.0)
#define c1_const_STOP                  (1.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void initialize_params_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static void enable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void disable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static void set_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_untitled1
  (SFc1_untitled1InstanceStruct *chartInstance);
static void finalize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void sf_gateway_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void mdl_start_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void c1_chartstep_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static void initSimStructsc1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_b_tp_ENGINE_STOP, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_g_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier,
  boolean_T c1_y[4]);
static void c1_h_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[4]);
static const mxArray *c1_i_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_j_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_untitled1InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn(SFc1_untitled1InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber, uint32_T
  c1_ssIdOfSourceObject, int32_T c1_offsetInSourceObject, int32_T
  c1_lengthInSourceObject);
static void init_dsm_address_info(SFc1_untitled1InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_untitled1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_ENGINE_Run = 0U;
  chartInstance->c1_tp_ENGINE_STOP = 0U;
  chartInstance->c1_tp_ENGINE_StartRequest = 0U;
  chartInstance->c1_is_active_c1_untitled1 = 0U;
  chartInstance->c1_is_c1_untitled1 = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_StartRequest = 2.0;
  chartInstance->c1_Run = 3.0;
  chartInstance->c1_STOP = 1.0;
}

static void initialize_params_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_untitled1 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_untitled1 == c1_IN_ENGINE_STOP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_untitled1 == c1_IN_ENGINE_StartRequest) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_untitled1 == c1_IN_ENGINE_Run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  int32_T c1_i0;
  boolean_T c1_g_u[4];
  const mxArray *c1_h_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(7, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_EngineMode;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *chartInstance->c1_TorqueOut;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *chartInstance->c1_doEngineStarter;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_IntialTimer;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_is_active_c1_untitled1;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_c1_untitled1;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_g_u[c1_i0] = chartInstance->c1_dataWrittenToVector[c1_i0];
  }

  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_g_u, 11, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T c1_bv0[4];
  int32_T c1_i1;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_EngineMode = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "EngineMode");
  *chartInstance->c1_TorqueOut = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "TorqueOut");
  *chartInstance->c1_doEngineStarter = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "doEngineStarter");
  chartInstance->c1_IntialTimer = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "IntialTimer");
  chartInstance->c1_is_active_c1_untitled1 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 4)), "is_active_c1_untitled1");
  chartInstance->c1_is_c1_untitled1 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 5)), "is_c1_untitled1");
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
                        "dataWrittenToVector", c1_bv0);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    chartInstance->c1_dataWrittenToVector[c1_i1] = c1_bv0[c1_i1];
  }

  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_untitled1(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_untitled1
  (SFc1_untitled1InstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_untitled1 == c1_IN_ENGINE_Run) {
      chartInstance->c1_tp_ENGINE_Run = 1U;
    } else {
      chartInstance->c1_tp_ENGINE_Run = 0U;
    }

    if (chartInstance->c1_is_c1_untitled1 == c1_IN_ENGINE_STOP) {
      chartInstance->c1_tp_ENGINE_STOP = 1U;
    } else {
      chartInstance->c1_tp_ENGINE_STOP = 0U;
    }

    if (chartInstance->c1_is_c1_untitled1 == c1_IN_ENGINE_StartRequest) {
      chartInstance->c1_tp_ENGINE_StartRequest = 1U;
    } else {
      chartInstance->c1_tp_ENGINE_StartRequest = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  c1_set_sim_state_side_effects_c1_untitled1(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_time, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_EngineMode, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_TorqueOut, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_Engine_RPM, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_ThrottleRequested, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_IntialTimer, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_doEngineStarter, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_StartRequest, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_Run, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_STOP, 9U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_untitled1(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitled1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_untitled1 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_untitled1 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_untitled1 = c1_IN_ENGINE_STOP;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_ENGINE_STOP = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    *chartInstance->c1_EngineMode = c1_const_STOP;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c1_EngineMode, 1U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c1_is_c1_untitled1) {
     case c1_IN_ENGINE_Run:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_g_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
            *chartInstance->c1_ThrottleRequested, 0.1, -1, 2U,
            *chartInstance->c1_ThrottleRequested < 0.1))) {
        if (CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
              *chartInstance->c1_Engine_RPM, 800.0, -1, 2U,
              *chartInstance->c1_Engine_RPM < 800.0))) {
          CV_EML_MCDC(3, 0, 0, true);
          CV_EML_IF(3, 0, 0, true);
          c1_out = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c1_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ENGINE_Run = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_untitled1 = c1_IN_ENGINE_STOP;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ENGINE_STOP = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *chartInstance->c1_EngineMode = c1_const_STOP;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c1_EngineMode, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_ENGINE_STOP:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_e_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
            *chartInstance->c1_Engine_RPM, 800.0, -1, 2U,
            *chartInstance->c1_Engine_RPM < 800.0))) {
        if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1,
              *chartInstance->c1_ThrottleRequested, 0.1, -1, 4U,
              *chartInstance->c1_ThrottleRequested > 0.1))) {
          CV_EML_MCDC(1, 0, 0, true);
          CV_EML_IF(1, 0, 0, true);
          c1_b_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c1_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ENGINE_STOP = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_untitled1 = c1_IN_ENGINE_StartRequest;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ENGINE_StartRequest = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *chartInstance->c1_EngineMode = c1_const_StartRequest;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c1_EngineMode, 1U);
        chartInstance->c1_IntialTimer = *chartInstance->c1_time;
        c1_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_IntialTimer, 5U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_ENGINE_StartRequest:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_f_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_c_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
        *chartInstance->c1_Engine_RPM, 800.0, -1, 4U,
        *chartInstance->c1_Engine_RPM > 800.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ENGINE_StartRequest = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_untitled1 = c1_IN_ENGINE_Run;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ENGINE_Run = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *chartInstance->c1_EngineMode = c1_const_Run;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c1_EngineMode, 1U);
        *chartInstance->c1_doEngineStarter = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c1_doEngineStarter, 6U);
        *chartInstance->c1_TorqueOut = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c1_TorqueOut, 2U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 4U, 92, 11);
        if (CV_EML_IF(2, 1, 0, *chartInstance->c1_time -
                      chartInstance->c1_IntialTimer < 1.0)) {
          *chartInstance->c1_doEngineStarter = 1.0;
          c1_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c1_doEngineStarter, 6U);
        }

        c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 6U, 4U, 146, 15);
        if (CV_EML_IF(2, 1, 1, *chartInstance->c1_doEngineStarter != 0.0)) {
          *chartInstance->c1_TorqueOut = 5.0;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c1_TorqueOut, 2U);
        } else {
          *chartInstance->c1_TorqueOut = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c1_TorqueOut, 2U);
        }

        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c1_is_c1_untitled1 = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sf_internal_predicateOutput;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_sf_internal_predicateOutput = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_sf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_sf_internal_predicateOutput);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_untitled1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i2;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i2, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_b_tp_ENGINE_STOP, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_ENGINE_STOP),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_ENGINE_STOP);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_ENGINE_STOP;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_b_tp_ENGINE_STOP = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_ENGINE_STOP),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_ENGINE_STOP);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_g_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier,
  boolean_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_dataWrittenToVector),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_dataWrittenToVector);
}

static void c1_h_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[4])
{
  boolean_T c1_bv1[4];
  int32_T c1_i3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    c1_y[c1_i3] = c1_bv1[c1_i3];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_i_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_j_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_untitled1InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  chartInstance->c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0U,
    (int32_T)c1_vectorIndex, 0, 3, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn(SFc1_untitled1InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber, uint32_T
  c1_ssIdOfSourceObject, int32_T c1_offsetInSourceObject, int32_T
  c1_lengthInSourceObject)
{
  (void)c1_ssIdOfSourceObject;
  (void)c1_offsetInSourceObject;
  (void)c1_lengthInSourceObject;
  if (!chartInstance->c1_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c1_vectorIndex, 0, 3, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c1_dataNumber);
  }
}

static void init_dsm_address_info(SFc1_untitled1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_untitled1InstanceStruct *chartInstance)
{
  chartInstance->c1_time = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_EngineMode = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_TorqueOut = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_Engine_RPM = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_ThrottleRequested = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_doEngineStarter = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c1_untitled1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2336362507U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1175901509U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(975664843U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(42802704U);
}

mxArray* sf_c1_untitled1_get_post_codegen_info(void);
mxArray *sf_c1_untitled1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Y7nZlmX9ytBXMVnZuPlntB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_untitled1_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_untitled1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_untitled1_jit_fallback_info(void)
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

mxArray *sf_c1_untitled1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_untitled1_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_untitled1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[10],T\"EngineMode\",},{M[1],M[11],T\"TorqueOut\",},{M[1],M[16],T\"doEngineStarter\",},{M[3],M[15],T\"IntialTimer\",},{M[8],M[0],T\"is_active_c1_untitled1\",},{M[9],M[0],T\"is_c1_untitled1\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_untitled1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_untitled1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_untitled1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitled1MachineNumber_,
           1,
           3,
           4,
           0,
           10,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"time");
          _SFD_SET_DATA_PROPS(1,2,0,1,"EngineMode");
          _SFD_SET_DATA_PROPS(2,2,0,1,"TorqueOut");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Engine_RPM");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ThrottleRequested");
          _SFD_SET_DATA_PROPS(5,0,0,0,"IntialTimer");
          _SFD_SET_DATA_PROPS(6,2,0,1,"doEngineStarter");
          _SFD_SET_DATA_PROPS(7,7,0,0,"StartRequest");
          _SFD_SET_DATA_PROPS(8,7,0,0,"Run");
          _SFD_SET_DATA_PROPS(9,7,0,0,"STOP");
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
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,1,0,82,107,-1,142);
        _SFD_CV_INIT_EML_IF(2,1,1,143,161,181,208);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,48,1,48);

        {
          static int condStart[] = { 1, 25 };

          static int condEnd[] = { 17, 48 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,48,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,17,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,25,48,-1,4);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,17,-1,4);
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
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c1_time);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_EngineMode);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c1_TorqueOut);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c1_Engine_RPM);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_ThrottleRequested);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_IntialTimer);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_doEngineStarter);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_StartRequest);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c1_Run);
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c1_STOP);
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
  return "buugO2HlOEFWM6JnDvIKC";
}

static void sf_opaque_initialize_c1_untitled1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_untitled1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_untitled1((SFc1_untitled1InstanceStruct*)
    chartInstanceVar);
  initialize_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_untitled1(void *chartInstanceVar)
{
  enable_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_untitled1(void *chartInstanceVar)
{
  disable_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_untitled1(void *chartInstanceVar)
{
  sf_gateway_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_untitled1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_untitled1((SFc1_untitled1InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_untitled1(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_untitled1((SFc1_untitled1InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_untitled1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_untitled1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled1_optimization_info();
    }

    finalize_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_untitled1(SimStruct *S)
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
    initialize_params_c1_untitled1((SFc1_untitled1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_untitled1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3618347798U));
  ssSetChecksum1(S,(1742620198U));
  ssSetChecksum2(S,(802379764U));
  ssSetChecksum3(S,(3274885254U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_untitled1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_untitled1(SimStruct *S)
{
  SFc1_untitled1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_untitled1InstanceStruct *)utMalloc(sizeof
    (SFc1_untitled1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_untitled1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_untitled1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_untitled1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_untitled1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_untitled1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_untitled1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_untitled1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_untitled1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_untitled1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_untitled1;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_untitled1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_untitled1;
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

void c1_untitled1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_untitled1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_untitled1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_untitled1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_untitled1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
