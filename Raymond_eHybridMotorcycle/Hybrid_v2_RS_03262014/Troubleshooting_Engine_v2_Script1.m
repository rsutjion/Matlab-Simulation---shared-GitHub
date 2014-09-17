%% Script for Troubleshooting_Engine_v2

%Ideal Torque Sensor Input
N = 200;
t = [1 0.25*N...
    0.25*N+1 0.5*N...
    0.5*N+1 0.75*N...
    0.75*N+1 N];
TorqueDyno.time = t;
TorqueInput = [100 100 ...
    125 125 ...
    150 150 ...
    175 175];
TorqueDyno.signals.values  =TorqueInput;
TorqueDyno.signals.dimensions = [2];

%% 12 Mode steady State Engine Calibration

SpeedMax = 7000;
TransitionTime = 20;% [second]

SpeedNormal = [ 0.25 0.5 0.75];
ThrottleNormal = [ 0.25 0.5 0.75 1];

SpeedMatrix = SpeedNormal * SpeedMax;

n=1;
for i = 1: length(SpeedNormal)
    for x = 1 : length(ThrottleNormal)
        Throttle = ThrottleNormal(x);
        Speed = SpeedMatrix(i);
        
        Troubleshooting_Engine_v2;
        OutputData(n).Throttle = Throttle;
        OutputData(n).Speed = Engine_Speed.Data;
        OutputData(n).Torque = Engine_Torque.Data;
        
        figure (10)
        plot(OutputData(n).Speed,OutputData(n).Torque)
        hold on
    n=n+1
    end
end

