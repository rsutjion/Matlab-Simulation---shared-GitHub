function pmsm = pmsmBLY171D(thetaInit)
% Returns structure of motor parameters

% Copyright 2013 The MathWorks, Inc.

if nargin < 1
    thetaInit = 0;
end

pmsm.Name = 'BLY171D-24V-4000 Anaheim Automation';
pmsm.Description = sprintf([...
    'Phase A leads B leads C for counterclockwise rotation\n',...
    '-----------------------------------------------------\n',...
    'Phase A = Yellow\n',...
    'Phase B = Red\n',...
    'Phase C = Black']);
pmsm.DocLink  = 'http://www.anaheimautomation.com/manuals/brushless/L010228%20-%20BLY17%20Series%20Product%20Sheet.pdf';

pmsm.RatedPower = 30;                   % W
pmsm.RatedVoltage = 24;                 % V
pmsm.RatedSpeed = 4000 * 2*pi/60;       % rad/sec (1 rad/sec = 2*pi/60 RPM)
pmsm.RatedTorque = 8.85 * 7.06154e-3;   % N m
                                        % (1 oz-in = 7.06154e-3 N m)
pmsm.NoLoadSpeed = 5300 * 2*pi/60;      % rad/sec (1 rad/sec = 2*pi/60 RPM)
pmsm.NoLoadCurrent = 0.2;               % A
pmsm.StallTorque = 11 * 7.06154e-3;     % N m
                                        % (1 oz-in = 7.06154e-3 N m)
pmsm.CurrentMax = 5.4;                  % A
pmsm.VoltageMax = pmsm.RatedVoltage;    % V
pmsm.PolePairs = 4;

% pmsm.StatorPhaseResistance = 1.8/2;     % Ohms
pmsm.StatorPhaseResistance = 1.7113/2;    % Ohms (from DC Step Test on 9/19/12)
% pmsm.InductanceLd = (2.1e-3)/2;         % Henries
pmsm.InductanceLd = (2.43e-3)/2;          % Henries (from DC Step Test on 9/19/12)

pmsm.InductanceLq = pmsm.InductanceLd;  % Henries

% pmsm.TorqueConstant = 5.0 * 7.06154e-3; % N m / A_peak
% pmsm.TorqueConstant = 0.0404;           % N m / A_peak - from lab data on 9/4/12
%                                         % (1 oz-in = 7.06154e-3 N m)
pmsm.TorqueConstant = 0.0301;           % N m / A_peak as calculated by Vinay on 11/26/12

% pmsm.Inertia = 0.00034 * 0.007061552;   % Kg m^2
                                        % (1 oz-in-sec^2 = 0.007061552 Kg m^2)
pmsm.Inertia = 3.2177e-06;              % Kg m^2 - from lab coastdown data on 9/4/12

% pmsm.ViscousDamping = 1.301336e-5;      % N m s
pmsm.ViscousDamping = 1.33363e-5;      % N m s - from lab data on 9/4/12

% pmsm.StaticFriction = 0.0074;           % N m
pmsm.StaticFriction = 0.002130661;        % N m - from lab data on 9/4/12

pmsm.ThetaInit = thetaInit;               % Radians

pmsm.VelocityInit = 0;                    % Rad/sec
