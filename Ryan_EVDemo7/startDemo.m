%% Configure EV Optimizatoin Demo
% This script opens and configures the model for exploration and opmization

% Copyright 2013 The MathWorks, Inc.


%% Path Definitions
Model_HomeDir = pwd;
% addpath(pwd);
% addpath([pwd '/Images']);
% addpath([pwd '/Scripts_Data']);
% addpath([pwd '/Control']);
% addpath([pwd '/Library']);
% addpath([pwd '/OptiScripts']);
addpath('Images');
addpath('Scripts_Data');
addpath('Control');
addpath('Library');
addpath('OptiScripts');

%% load drive cycle and model parameter data

EV_Model_PARAM
load UrbanCycle1
load UrbanCycle2
load UrbanCycle3
load UrbanCycle4 % FTP75
ftp75startind = find(UrbanCycle4.SpdKph>0,1)-1;
load UrbanCycle5
load UrbanCycle6 % US06
% setup drive cycle 6 (US06) to run repetatively at a 10ms sample rate
UrbanCycle6Rep.signals.values = interp1(UrbanCycle6.time,UrbanCycle6.SpdKph,0:.01:(UrbanCycle6.time(end)-.01),'linear')';
UrbanCycle6Rep.time = [];


FTP_0260.time = [0; 1; 1.01; 20; 35; (UrbanCycle4.time(ftp75startind:end)-UrbanCycle4.time(ftp75startind)+50)];
FTP_0260.signals.values = [0; 0; 130; 130; 0; UrbanCycle4.SpdKph(ftp75startind:end)];

US06_0260.time = [0; 1; 1.01; 20; 35; (UrbanCycle6.time+50)];
US06_0260.signals.values = [0; 0; 130; 130; 0; UrbanCycle6.SpdKph];

Drive_Cycle_Num = 8;


%% define tracking constraints
% time vector
US06_tracking_cnst_t = US06_0260.time;

%US06_tracking_cnst_lb = [0; 0; 0; 0; 0;min(min(UrbanCycle6.SpdKph.*0.9,110),UrbanCycle6.SpdKph-2)];
US06_tracking_cnst_lb = [-5; -5; -5; -5; -5;(min(UrbanCycle6.SpdKph-5,110))];
for i=1:length(US06_tracking_cnst_lb)-1
    US06_tracking_mat_t(i,:) = US06_tracking_cnst_t(i:i+1);
    US06_tracking_mat_lb(i,:) = US06_tracking_cnst_lb(i:i+1);
end


% add to workspace
% assignin('base','decimation',1)
% Pbatt = 21e3;
% Vbatt =100;
% Ts = 6e-5;   % time step
% Drive_Cycle_Num = 4;
% Stop_Time =eval(['UrbanCycle' num2str(Drive_Cycle_Num) '.time(end)']);
% decfactor = 100;
%% variant control
EV_MODE = 1;

SYSYEM_PMSM_CNTRL = Simulink.Variant('EV_MODE==1');
MEANVALUE_PMSM_CNTRL = Simulink.Variant('EV_MODE==2');
DETAILED_PMSM_CNTRL = Simulink.Variant('EV_MODE==3');

SYSTEM_PMSM = Simulink.Variant('EV_MODE==1');
% MEANVALUE_PMSM = Simulink.Variant('EV_MODE==2');
DETAILED_PMSM = Simulink.Variant('EV_MODE==3');
% DETALIED_HYDQ_PMSM = Simulink.Variant('EV_MODE==4');


SYSTEM_DCDC = Simulink.Variant('EV_MODE==1');
%MEANVALUE_DCDC = Simulink.Variant('EV_MODE==2');
DETALIED_DCDC = Simulink.Variant('EV_MODE==3');

BATT_MODE = 6;
CELLS_BATT = Simulink.Variant('BATT_MODE==1');
GENERIC_1_BATT = Simulink.Variant('BATT_MODE ==2');
GENERIC_2_BATT = Simulink.Variant('BATT_MODE ==3');
PREDEF_BATT = Simulink.Variant('BATT_MODE ==4');
GENERIC_RC_BATT = Simulink.Variant('BATT_MODE==5');
ETHERM_LUMPED = Simulink.Variant('BATT_MODE==6');

VEHICLE_MODE = 1;
SYSTEM_VEHICLE = Simulink.Variant('VEHICLE_MODE ==1');
%MEANVALUE_VEHICLE = Simulink.Variant('EV_MODE==2'); % not yet defined
DETALIED_VEHICLE = Simulink.Variant('VEHICLE_MODE ==3');

%% initialize the optimization parameters
opti_init

%% Open models
% EVdemo_6




% 
% % from Oak Creek National Labs
% PirusMotorSpeed = [0,1930,2962,5024,6032,8000,11000,12000,13000];
% PirusMotorTorque =[200,200,191,107, 80, 53, 34, 31, 26];