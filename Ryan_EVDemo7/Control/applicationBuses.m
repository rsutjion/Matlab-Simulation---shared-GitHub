function applicationBuses() 
% APPLICATIONBUSES initializes a set of bus objects in the MATLAB base workspace 

% Bus object: POSITION_ISR_STRUCT 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'position_cap';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'DT_HALL_POSITION';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).SamplingMode = 'Sample based';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'timer_cap';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'uint32';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).SamplingMode = 'Sample based';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'timer_delta';
elems(3).Dimensions = 1;
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'uint32';
elems(3).SampleTime = -1;
elems(3).Complexity = 'real';
elems(3).SamplingMode = 'Sample based';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

elems(4) = Simulink.BusElement;
elems(4).Name = 'direction';
elems(4).Dimensions = 1;
elems(4).DimensionsMode = 'Fixed';
elems(4).DataType = 'int16';
elems(4).SampleTime = -1;
elems(4).Complexity = 'real';
elems(4).SamplingMode = 'Sample based';
elems(4).Min = [];
elems(4).Max = [];
elems(4).DocUnits = '';
elems(4).Description = '';

elems(5) = Simulink.BusElement;
elems(5).Name = 'position_delta';
elems(5).Dimensions = 1;
elems(5).DimensionsMode = 'Fixed';
elems(5).DataType = 'DT_HALL_POSITION';
elems(5).SampleTime = -1;
elems(5).Complexity = 'real';
elems(5).SamplingMode = 'Sample based';
elems(5).Min = [];
elems(5).Max = [];
elems(5).DocUnits = '';
elems(5).Description = '';

POSITION_ISR_STRUCT = Simulink.Bus;
POSITION_ISR_STRUCT.HeaderFile = '';
POSITION_ISR_STRUCT.Description = '';
POSITION_ISR_STRUCT.DataScope = 'Auto';
POSITION_ISR_STRUCT.Alignment = -1;
POSITION_ISR_STRUCT.Elements = elems;
assignin('base','POSITION_ISR_STRUCT', POSITION_ISR_STRUCT)

% Bus object: POSITION_SENSOR_STRUCT 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'timer_capture';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'uint32';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).SamplingMode = 'Sample based';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'timer_overflow';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'boolean';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).SamplingMode = 'Sample based';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'timer';
elems(3).Dimensions = 1;
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'uint32';
elems(3).SampleTime = -1;
elems(3).Complexity = 'real';
elems(3).SamplingMode = 'Sample based';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

elems(4) = Simulink.BusElement;
elems(4).Name = 'hall_abc_state';
elems(4).Dimensions = 1;
elems(4).DimensionsMode = 'Fixed';
elems(4).DataType = 'uint16';
elems(4).SampleTime = -1;
elems(4).Complexity = 'real';
elems(4).SamplingMode = 'Sample based';
elems(4).Min = [];
elems(4).Max = [];
elems(4).DocUnits = '';
elems(4).Description = '';

POSITION_SENSOR_STRUCT = Simulink.Bus;
POSITION_SENSOR_STRUCT.HeaderFile = '';
POSITION_SENSOR_STRUCT.Description = '';
POSITION_SENSOR_STRUCT.DataScope = 'Auto';
POSITION_SENSOR_STRUCT.Alignment = -1;
POSITION_SENSOR_STRUCT.Elements = elems;
assignin('base','POSITION_SENSOR_STRUCT', POSITION_SENSOR_STRUCT)

% Bus object: SENSORS_STRUCT 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'position_sensor';
elems(1).Dimensions = [1 1];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'Bus: POSITION_SENSOR_STRUCT';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).SamplingMode = 'Sample based';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'adc_phase_currents';
elems(2).Dimensions = [2 1];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'int16';
elems(2).SampleTime = -1;
elems(2).Complexity = 'real';
elems(2).SamplingMode = 'Sample based';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

SENSORS_STRUCT = Simulink.Bus;
SENSORS_STRUCT.HeaderFile = '';
SENSORS_STRUCT.Description = '';
SENSORS_STRUCT.DataScope = 'Auto';
SENSORS_STRUCT.Alignment = -1;
SENSORS_STRUCT.Elements = elems;
assignin('base','SENSORS_STRUCT', SENSORS_STRUCT)

