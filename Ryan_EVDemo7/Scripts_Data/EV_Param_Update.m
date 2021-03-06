%% EV_Param_Update.m
% this script is called by the EV_Opti_demo.mdl start callback so that the 
% model uses the latest parameter sets generated by the Design Optimization
% input variables
%
% Copyright 2013 The MathWorks, Inc.

% update the number of strings (discretized)
numStrings = round(Opti_numStrings);
disp(['Number of strings: ' num2str(numStrings)])
% update the effective capacity based on the number of strings
EV_Param.Battery_Det.Rated_Capacity = 28.5*numStrings; %A*hr
EV_Param.Battery_Det.DP = fliplr([1500 1500 1600 1450 1325 1125 925 675 425 175 ])./8*EV_Param.Battery_Det.Rated_Capacity; % 8 comes from the 8Ahr rated batter data used (normalize and rescale to the rated capacity
EV_Param.Battery_Det.CP = fliplr([25 100 200 250 375 550 750 950 1125 1150])./8*EV_Param.Battery_Det.Rated_Capacity;

% update the number of  cells in a string (discretized)
numSeriesCells = round(Opti_numSeriesCells);
disp(['Number of cells in a string: ' num2str(numSeriesCells)])
% update the nominal string volage and charge deficit
EV_Param.Battery_Det.Nominal_Voltage = numSeriesCells*cellVolts;
BatteryParams(idx).Qe_init = EV_Param.Battery_Det.Rated_Capacity*(1-EV_Param.Battery_Det.Initial_SOC/100); %Ampere*hours

% update the total number of cells, battery pack mass and total vehicle
% mass
total_cells = numSeriesCells*numStrings;
disp(['Total Number of cells: ' num2str(total_cells)])
EV_Param.BatteryMass = BatteryParams(1).cell_mass*total_cells;
disp(['Total Battery Pack Mass: ' num2str(EV_Param.BatteryMass)])
EV_Param.Vehicle.Mass = 1300+EV_Param.BatteryMass;

% update the driveline gear ratio
EV_Param.Vehicle.Engine_Vehicle_Gear_Ratio = Opti_Vehicle_Gear_Ratio;
disp(['Driveline gear ratio: ' num2str(Opti_Vehicle_Gear_Ratio)])