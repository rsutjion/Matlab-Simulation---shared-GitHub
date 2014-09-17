% Copyright 2013 The MathWorks, Inc.

%disp('DEFINING PARAMETERS...');
% load bus objects
EV_Bus_Def;

% PREDEFINED LI-ION BATTERY PARAMS
EV_Param.Battery_Det.Nominal_Voltage = 200;
EV_Param.Battery_Det.Rated_Capacity = 8.1;      % Ampere-hours
EV_Param.Battery_Det.Initial_SOC = 75.75;       % Percent
EV_Param.Battery_Det.Series_Resistance = 0.2/10;   % Ohm

% GENERIC BATTERY PARAMS
% EV_Param.Battery_Sys.Nominal_Voltage = 217;
% EV_Param.Battery_Sys.Internal_Resistance = 0.24691;% Ohm
% EV_Param.Battery_Sys.Rated_Capacity = 6.9;     % Ampere-hours
% EV_Param.Battery_Sys.Initial_Charge = 6.9;    % Ampere-hours
% EV_Param.Battery_Sys.Expn_Voltage = 215.0342;       % V
% EV_Param.Battery_Sys.Expn_Charge = 2.3438;
% Leaf specs
EV_Param.Battery_Sys.Nominal_Voltage = 365;
EV_Param.Battery_Sys.Internal_Resistance = 0.15;
EV_Param.Battery_Sys.Rated_Capacity = 57; %A*hr
EV_Param.Battery_Sys.Initial_Charge =EV_Param.Battery_Sys.Rated_Capacity*.948; %A*hr
EV_Param.Battery_Sys.Expn_Voltage = 350;
EV_Param.Battery_Sys.Expn_Charge = 6; %A*hr


EV_Param.Battery_Sys.C1.Capacitance = 2500;
EV_Param.Battery_Sys.C1.Initial_Voltage = 19;
EV_Param.Battery_Sys.C1.Series_Resistance = 1e-6;
EV_Param.Battery_Sys.R2 = 0.3;
EV_Param.Battery_Sys.R1 = 1.8;
EV_Param.Battery_Sys.Maximum_Capacity = EV_Param.Battery_Sys.Rated_Capacity;    % Ampere-hours

% Battery Model Parameters - 50Ah
EV_Param.Battery_Cell.NominalCap = 50; %(Ah)
    
% Battery Block Initial Conditions
% Initial State of Charge (% of full charge)
% Initial Electrolyte Temperature (°C, typically same as ambient temp)
EV_Param.Battery_Cell.SOC_init = 0.8;
EV_Param.Battery_Cell.theta_init = 25;
    
% Battery Block Thermal Parameters
EV_Param.Battery_Cell.Ctheta = 400; %(J/°C) Thermal Capacitance
EV_Param.Battery_Cell.Area = 0.01; % (m^2) Surface area of battery exposed to air
EV_Param.Battery_Cell.Rtheta = 20;  %(W/m^2/K) Convective heat transfer coefficient
    
% Battery Block Capacity Parameters
% Charge/discharge cycles at ranges of current/temp
EV_Param.Battery_Cell.Kc = 1.2; %()
EV_Param.Battery_Cell.Costar = 1.8e+005; %(As)
EV_Param.Battery_Cell.Kt_Temps = [25 40 60 75]; % Temperature breakpoints for Kt LUT
EV_Param.Battery_Cell.Kt = [0.80,1.10,1.20,1.12;]; %() LUT output values
EV_Param.Battery_Cell.delta = 0.73; %()
EV_Param.Battery_Cell.Istar = 15; %(A) Nominal Current (=cap/disch_t)
EV_Param.Battery_Cell.theta_f = -40; %(°C) Electrolyte Freezing Temp
    
% Battery Block Parasitic Branch Parameters
% End of charge cycle at ranges of current/temp
EV_Param.Battery_Cell.Ep = 1.95; %(V) Parasitic emf
EV_Param.Battery_Cell.Gpo = 2.0e-011; %(s)
EV_Param.Battery_Cell.Vpo = 0.12; %(V)
EV_Param.Battery_Cell.Ap = 2.0; %()
EV_Param.Battery_Cell.Taup = 3; % (s)
    
% Battery Block Main Branch Parameters
EV_Param.Battery_Cell.Emo = 2.18*10; % (V) [max o.c. volts per cell]
EV_Param.Battery_Cell.Ke = 0.0006; %(V/°C)
EV_Param.Battery_Cell.Ao = -0.6; % ()
EV_Param.Battery_Cell.Roo = 0.0042; % (Ohm)
EV_Param.Battery_Cell.R10 = 0.0010; %(Ohm)
EV_Param.Battery_Cell.A21 = -10.0; %()
EV_Param.Battery_Cell.A22 = -8.75; %()
EV_Param.Battery_Cell.R20 = 0.11; %(Ohm)
EV_Param.Battery_Cell.Tau1 = 100; %(s)
    
% Battery Block Number Of Cells Parameters
EV_Param.Battery_Cell.ns = 6; %() Number of cells in series in each parallel branch
    
% Compute initial extracted charge
EV_Param.Battery_Cell.Qe_init = (1-EV_Param.Battery_Cell.SOC_init)*EV_Param.Battery_Cell.Kc*EV_Param.Battery_Cell.Costar*interp1([EV_Param.Battery_Cell.theta_f EV_Param.Battery_Cell.Kt_Temps],[0 EV_Param.Battery_Cell.Kt],EV_Param.Battery_Cell.theta_init,'spline');



% intitialize parameters for the electro thermal model
Li_Batt_LumpedCells_PARAM
numStrings = 3;
numSeriesCells = 96;
total_cells = numSeriesCells*numStrings;
EV_Param.BatteryMass = BatteryParams(1).cell_mass*total_cells;

cellVolts = 3.8;
EV_Param.Battery_Det.Rated_Capacity = 28.5*numStrings; %A*hr
EV_Param.Battery_Det.Initial_SOC = 94.8; % %
EV_Param.Battery_Det.Nominal_Voltage = numSeriesCells*cellVolts;

EV_Param.Battery_Det.DP = 1.5.*fliplr([1500 1500 1600 1450 1325 1125 925 675 425 175 ])./8*EV_Param.Battery_Det.Rated_Capacity; % 8 comes from the 8Ahr rated batter data used (normalize and rescale to the rated capacity
EV_Param.Battery_Det.SOC = 10:10:100; % vector of SOC values [%]
EV_Param.Battery_Det.CP = fliplr([25 100 200 250 375 550 750 950 1125 1150])./8*EV_Param.Battery_Det.Rated_Capacity;

BatteryParams(idx).Qe_init = EV_Param.Battery_Det.Rated_Capacity*(1-EV_Param.Battery_Det.Initial_SOC/100); %Ampere*hours

EV_Param.Battery_Det.PowerRegTs = 4e-5;
EV_Param.Battery_Det.ChargePowerPISat = 60e3;
EV_Param.Battery_Det.DischargePowerPISat = 120e3;
EV_Param.Battery_Det.PowerKp = .02;
EV_Param.Battery_Det.PowerKi = .25;
EV_Param.Battery_Det.ChargePowerKi = 0.25;
EV_Param.Battery_Det.ChargePowerKp = 0.02;
% EV_Param.Battery_Det.PowerKi = .5
% EV_Param.Battery_Det.PowerKi = .25

EV_Param.Control.Pwr_Cntrl_TS = 0.001;



% ULTRACAPACITOR PARAMETERS
EV_Param.UltraCapacitor.Nominal_Capacitance = 1000; % Farad
EV_Param.UltraCapacitor.Rate_C_V = 0.2;          % Farad/Volt
EV_Param.UltraCapacitor.Series_R = 30/3;            % Ohm
EV_Param.UltraCapacitor.Self_Discharge_R = 500;  % Ohm
EV_Param.UltraCapacitor.Initial_Voltage = 217;     % Volt


% MOTOR PARAMETERS
EV_Param.Motor.Stator_Resistance = 0.0065*14;        % Ampere-hours
EV_Param.Motor.Stator_Resistance = 0.0065*14;
EV_Param.Motor.TorqSpdLUT.SpeedRPM = [0   1200 2000 3000 4000 5000 6000  6500 10000];
EV_Param.Motor.TorqSpdLUT.TorqueNm = [400 400  225  150  100  80   70    0    0];
EV_Param.Motor.Damping = 1e-5; %N*m/(rad/s)
EV_Param.Motor.TorqueControl_TimeConst = 0.02*2/1.5;
EV_Param.Motor.Shaft_Inertia = 0.2;
EV_Param.Motor.Series_Resistance = 0.01; %CHG
EV_Param.Motor.Inductances = [0.001597972349731   0.002057052250467];
EV_Param.Motor.Efficiency = 91;
%Motor max rpm = 10390;
% these are scaled up from the Prius (Leaf is 80kW nominal)
EV_Param.Motor.TorqSpdLUT.TorqueNm = [200,200,191,107, 80, 53, 34, 31, 26]*280./200;
EV_Param.Motor.TorqSpdLUT.SpeedRPM = [0,1930,2962,5024,6032,8000,11000,12000,13000];
EV_Param.Motor.TorqueControl_TimeConst = 0.0267;


% DC-DC CONVERTER PARAMETERS
%EV_Param.DCDCConv.Output_Voltage = 500;      % Volts
EV_Param.DCDCConv.Output_Voltage = 650;
EV_Param.DCDCConv.Resistance_Losses = 1000/40^2;      % Ohm
% EV_Param.DCDCConv.Kp = 0.01;
% EV_Param.DCDCConv.Ki = 10;
EV_Param.DCDCConv.Ki = 20;
EV_Param.DCDCConv.Kp = 2;
EV_Param.DCDCConv.MinVin = 20;
EV_Param.DCDCConv.Mean_Boost.Kp = 0.001;
EV_Param.DCDCConv.Mean_Boost.Ki = 1;
EV_Param.DCDCConv.EPower2Heat = 0.1;      % Watts/Watts
EV_Param.DCDCConv.Thermal_Mass = 0.1*10;    % kg
EV_Param.DCDCConv.Thermal_Mass = 40/5.3; % prius DCDC converter is 5.3kW/kg
EV_Param.DCDCConv.Specific_Heat = 100;   % J/kg/K
EV_Param.DCDCConv.Initial_Temperature = 21;     % C
EV_Param.DCDCConv.Air_Temperature = 293.15;     % K
EV_Param.DCDCConv.Convection.Area = 20;     % cm^2
EV_Param.DCDCConv.Convection.Area = 10*100; % cm^2
%EV_Param.DCDCConv.Convection.HT_Coefficient = 100; % W/(m^2*K)
EV_Param.DCDCConv.Convection.HT_Coefficient = 1000;
%EV_Param.DCDCConv.PWM_Carrier_TS = 1/2e3; %[s]
EV_Param.DCDCConv.PWM_Carrier_TS = 5e-5; %[s]
EV_Param.DCDCConv.Control_TS = 1/1e3;





%% CONTROLLER PARAMETERS
EV_Param.Control.Mode_Logic_TS = 0.1;
% EV_Param.Control.Mot.Kp = 500;
% EV_Param.Control.Mot.Ki = 300;
% EV_Param.Control.Veh_Spd.Kp = 0.02;
% EV_Param.Control.Veh_Spd.Ki = 0.04;

EV_Param.Control.Veh_Spd.Sat = 4;
EV_Param.Control.Veh_Spd.Ts = 1e-2;
EV_Param.Control.Veh_Spd.Kp = .09;
EV_Param.Control.Veh_Spd.Ki = .125;
EV_Param.Control.Veh_Spd.Kff = .02;
EV_Param.Control.Veh_Brake.Ki = 1;
EV_Param.Control.Veh_Brake.Kp = .5;
EV_Param.Control.Veh_Brake.Sat = 8;


%% PMSM control parameters
% Create hardware assembly
[processor, pmsm, inverter, disc, adc, hall] = hwNovi1F28069Drv8312;
% Create configuration set
applicationConfigSetProduction
% Create numeric types
applicationDataTypesFloat
% Create data
applicationData
% Set variants
sinCosVariant = sinCosEnum.Float;
hallElectricalVelocityVariant = hallElectricalVelocityEnum.Division;



%% Cooling & Environmental parameters
EV_Param.Evniro.T_ambient = 21; % deg C
EV_Param.Evniro.Air_Temperature = 20 + 273.15;% deg K



%% VEHICLE PARAMETERS
%EV_Param.Vehicle.Mass = 600*2;         % kg
EV_Param.Vehicle.Tire_Radius = 0.3;    % m
EV_Param.Vehicle.Wheel_Inertia = 0.1;  % kg*m^2
EV_Param.Vehicle.Aero_Drag_Coeff = 0.26;
EV_Param.Vehicle.Engine_Vehicle_Gear_Ratio = 1.3;
EV_Param.Vehicle.Distance_CG_FrontAxle = 1.35;
EV_Param.Vehicle.Distance_CG_RearAxle = 1.35;
EV_Param.Vehicle.Distance_CG_Ground = 0.5;
EV_Param.Vehicle.Frontal_Area = 2.16;
EV_Param.Vehicle.Tire.Rated_Vertical_Load = 3000;  % N
EV_Param.Vehicle.Tire.Rated_Peak_Long_Force = 3500;  % N
EV_Param.Vehicle.Tire.Slip_At_Peak_Force = 6;  % Percent
%EV_Param.Vehicle.Tire.Relaxation_Length = 0.2*0.09;  % Percent
%EV_Param.Vehicle.Tire.Relaxation_Length = 0.2;
EV_Param.Vehicle.Tire.Relaxation_Length = 0.25;
EV_Param.Vehicle.Trans.Inertia = 0.5;
EV_Param.Vehicle.Trans.Friction = 0.1*0.001;

%% Leaf Specs:
EV_Param.Vehicle.Engine_Vehicle_Gear_Ratio = 7.9377;
EV_Param.Vehicle.Mass = 1300+EV_Param.BatteryMass;
EV_Param.Vehicle.Tire_Radius = 0.3162;
EV_Param.Vehicle.Frontal_Area = 6.9/3.28084/3.28084;
EV_Param.Vehicle.Aero_Drag_Coeff = 0.28;






%% braking table
% columns: percent braking output
% rows: percent available motor regen power
decel_cmd_vec = linspace(0,5,11);
regen_pwr_vec = 0:10:100;
brake_cmd_table = [0 10 20 30 40 50 60 70 80 90 100;...
                   0 10 20 30 40 50 60 70 80 90 100;...
                   0  9 18 27 34 45 54 63 72 81 90;...
                   0  8 16 24 30 40 48 56 64 72 80;...
                   0  7 14 21 26 35 42 49 56 63 70;...
                   0  6 12 18 22 30 36 42 48 54 60;...
                   0  5 10 15 18 25 30 35 40 45 50;...
                   0  4  8 12 14 20 24 28 32 36 40;...
                   0  3  6  9 10 15 18 21 24 27 30;...
                   0  2  4  6  6 10 12 14 16 18 20;...
                   0  1  2  3  4  5  6  7  8  9 10];
for i=1:11
brake_cmd_table2(i,:) = 100-(regen_pwr_vec./10+i).^1.7;
end
brake_cmd_table2(find(brake_cmd_table2<0)) = 0; 
brake_cmd_table2=fliplr(brake_cmd_table2'); 
brake_cmd_table2(:,1)=0;
%surf(decel_cmd_vec,regen_pwr_vec,brake_cmd_table2)

car_model = {'Leaf'; 'Volt'; 'Focus'; 'Tesla S 85kWh'; 'Spark EV'; 'BMW i3'};
prod_car_mass = [1500; 1715; 1674; 2100; 1356; 1195]; % kg
prod_batt_mass = [294; 190; 300; 601; 254; 230]; % kg
prod_battmass_ratio = prod_batt_mass./prod_car_mass;
% 
% bar(prod_battmass_ratio.*100)
% prod_modesl = {'Leaf 24kWh', 'Volt 17kWh', 'Focus 23kWh', 'Tesla S 85kWh', 'Spark EV 21kWh', 'BMW i3 22kWh'};
% set(gca,'XTickLabel',prod_modesl)
% ylabel('Battery Mass / Total Vehicle Mass [%]')
% grid on
