/* Include files */

#include "System_HybridMotorcycle_v1_Wit_sfun.h"
#include "System_HybridMotorcycle_v1_Wit_sfun_debug_macros.h"
#include "c1_System_HybridMotorcycle_v1_Wit.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _System_HybridMotorcycle_v1_WitMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void System_HybridMotorcycle_v1_Wit_initializer(void)
{
}

void System_HybridMotorcycle_v1_Wit_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_System_HybridMotorcycle_v1_Wit_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_System_HybridMotorcycle_v1_Wit_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_System_HybridMotorcycle_v1_Wit_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2844386985U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3883178598U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4062860530U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3082862437U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(848754436U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3181262464U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1042581501U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1108158615U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_System_HybridMotorcycle_v1_Wit_get_check_sum(mxArray
            *plhs[]);
          sf_c1_System_HybridMotorcycle_v1_Wit_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1530711999U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(157665202U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(403337779U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3711554292U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_System_HybridMotorcycle_v1_Wit_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "seONsks7Yq7kD6F6ImUaNB") == 0) {
          extern mxArray
            *sf_c1_System_HybridMotorcycle_v1_Wit_get_autoinheritance_info(void);
          plhs[0] =
            sf_c1_System_HybridMotorcycle_v1_Wit_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_System_HybridMotorcycle_v1_Wit_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_System_HybridMotorcycle_v1_Wit_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_System_HybridMotorcycle_v1_Wit_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_System_HybridMotorcycle_v1_Wit_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "j12iCTrlGwye0QUu9yRBHF") == 0) {
          extern mxArray
            *sf_c1_System_HybridMotorcycle_v1_Wit_third_party_uses_info(void);
          plhs[0] = sf_c1_System_HybridMotorcycle_v1_Wit_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void System_HybridMotorcycle_v1_Wit_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _System_HybridMotorcycle_v1_WitMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"System_HybridMotorcycle_v1_Wit","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _System_HybridMotorcycle_v1_WitMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _System_HybridMotorcycle_v1_WitMachineNumber_,0);
}

void System_HybridMotorcycle_v1_Wit_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_System_HybridMotorcycle_v1_Wit_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "System_HybridMotorcycle_v1_Wit", "System_HybridMotorcycle_v1_Wit");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_System_HybridMotorcycle_v1_Wit_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
