/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Engine_Vehicle_CVT_RS_System1_SpeedTrack_sfun.h"
#include "c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Engine_Vehicle_CVT_RS_System1_SpeedTrack_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void initialize_params_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void enable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void disable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedT
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void set_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_Engine_Vehicle_CVT_RS_System1_S
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void finalize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void sf_gateway_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void mdl_start_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void initSimStructsc3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static boolean_T c3_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_b_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_c_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_b_is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack,
   const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
   boolean_T c3_y[1]);
static void c3_h_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[1]);
static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   uint32_T c3_vectorIndex);
static void init_dsm_address_info
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack = 0U;
}

static void initialize_params_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedT
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  boolean_T c3_c_u[1];
  const mxArray *c3_d_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(3, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_ClutchON;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal =
    chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_u[0] = chartInstance->c3_dataWrittenToVector[0];
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_c_u, 11, 0U, 1U, 0U, 1, 1), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[1];
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_ClutchON = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "ClutchON");
  chartInstance->c3_is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack =
    c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
                        "dataWrittenToVector", c3_bv0);
  chartInstance->c3_dataWrittenToVector[0] = c3_bv0[0];
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedT(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_Engine_Vehicle_CVT_RS_System1_S
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  c3_set_sim_state_side_effects_c3_Engine_Vehicle_CVT_RS_System1_S(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Engine_RPM, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_RPM_Clutch_THLD, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_RPM_Clutch_Hist_THLD, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ClutchON, 3U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_out = CV_EML_IF(1, 0, 0, *chartInstance->c3_Engine_RPM <
                     *chartInstance->c3_RPM_Clutch_THLD -
                     *chartInstance->c3_RPM_Clutch_Hist_THLD);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    *chartInstance->c3_ClutchON = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ClutchON, 3U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    c3_b_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
      *chartInstance->c3_Engine_RPM, *chartInstance->c3_RPM_Clutch_THLD, -1, 4U,
      *chartInstance->c3_Engine_RPM > *chartInstance->c3_RPM_Clutch_THLD));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_b_sf_marshallIn);
      *chartInstance->c3_ClutchON = 1.0;
      c3_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ClutchON, 3U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Engine_Vehicle_CVT_RS_System1_SpeedTrackMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
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
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *)
    chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_c_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray
  *sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_get_eml_resolved_functions_info
  (void)
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
  SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
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
  SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *)
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

static uint8_T c3_e_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_b_is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack,
   const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_g_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
   boolean_T c3_y[1])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_h_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[1])
{
  boolean_T c3_bv1[1];
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 1);
  c3_y[0] = c3_bv1[0];
  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
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
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
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
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance,
   uint32_T c3_vectorIndex)
{
  chartInstance->c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0U,
    (int32_T)c3_vectorIndex, 0, 0, 1, 0)] = true;
}

static void init_dsm_address_info
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance)
{
  chartInstance->c3_Engine_RPM = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_RPM_Clutch_THLD = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_RPM_Clutch_Hist_THLD = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c3_ClutchON = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3746402259U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(284860823U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2002822346U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1747109451U);
}

mxArray* sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_get_post_codegen_info
  (void);
mxArray *sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TCZPPqBKYZYQqqSv2Yl1LH");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_jit_fallback_info(void)
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

mxArray
  *sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_get_post_codegen_info
  (void)
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

static const mxArray
  *sf_get_sim_state_info_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[13],T\"ClutchON\",},{M[8],M[0],T\"is_active_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct
                     *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Engine_Vehicle_CVT_RS_System1_SpeedTrackMachineNumber_,
           3,
           0,
           5,
           0,
           4,
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
          (_Engine_Vehicle_CVT_RS_System1_SpeedTrackMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Engine_Vehicle_CVT_RS_System1_SpeedTrackMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Engine_Vehicle_CVT_RS_System1_SpeedTrackMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Engine_RPM");
          _SFD_SET_DATA_PROPS(1,1,1,0,"RPM_Clutch_THLD");
          _SFD_SET_DATA_PROPS(2,1,1,0,"RPM_Clutch_Hist_THLD");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ClutchON");
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,30,1,30);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,2,30,-1,4);
        _SFD_CV_INIT_EML(3,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,52,1,48);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_Engine_RPM);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_RPM_Clutch_THLD);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_RPM_Clutch_Hist_THLD);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_ClutchON);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Engine_Vehicle_CVT_RS_System1_SpeedTrackMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "AHKIRmrPu2umHOl1P0aBVC";
}

static void sf_opaque_initialize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInstanceVar);
  initialize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(void
  *chartInstanceVar)
{
  enable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(void
  *chartInstanceVar)
{
  disable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(void
  *chartInstanceVar)
{
  sf_gateway_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Engine_Vehicle_CVT_RS_System1_SpeedTrack_optimization_info();
    }

    finalize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
      ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
       chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
    ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SimStruct *S)
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
    initialize_params_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
      ((SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_Engine_Vehicle_CVT_RS_System1_SpeedTrack_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1592899985U));
  ssSetChecksum1(S,(3723427659U));
  ssSetChecksum2(S,(534687391U));
  ssSetChecksum3(S,(1735957033U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(SimStruct *S)
{
  SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct *)
    utMalloc(sizeof(SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_Engine_Vehicle_CVT_RS_System1_SpeedTrackInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack;
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

void c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Engine_Vehicle_CVT_RS_System1_SpeedTrack_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
