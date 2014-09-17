%% Create numeric types for fixed point data
% Copyright 2013 The MathWorks, Inc.

%% Specify I/O data interface
DT_MOTOR_ON      = numerictype('uint16');
DT_COMMAND_VALUE = numerictype('single');
DT_PWM_COMPARE   = numerictype('uint16');
DT_ERROR         = numerictype('uint16');
DT_HALL_POSITION = numerictype('single');

%% Specify intermediate data types
DT_PRECISION_LO           = numerictype('single');
DT_PRECISION_LO_UNSIGNED  = numerictype('single');
DT_PRECISION_HI           = numerictype('single');
DT_PRECISION_HI_UNSIGNED  = numerictype('single');

%% Load buses
applicationBuses
