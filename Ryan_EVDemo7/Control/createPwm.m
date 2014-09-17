function pwm = createPwm(period, timePerCount)
% Copyright 2013 The MathWorks, Inc.

if nargin < 1
    period = 1/25e3;
end

if nargin < 2
    timePerCount = 1/50e6;
end

% Counter is an up/down counter so max is half of counts per period
countsPerPeriod = period / timePerCount;
counterMax      = round( countsPerPeriod / 2);
countsPerPeriod = counterMax * 2;

% Calculate actual achieved period
pwm.Period          = countsPerPeriod * timePerCount;
pwm.TimePerCount    = timePerCount;
pwm.CounterMax      = counterMax;
pwm.CountsPerPeriod = countsPerPeriod;

