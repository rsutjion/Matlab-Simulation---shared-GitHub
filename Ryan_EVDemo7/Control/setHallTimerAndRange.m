function hall = setHallTimerAndRange(...
          hall, ...
          tsTimer,...
          velocityMagnitudeMinMax)
% Copyright 2013 The MathWorks, Inc.
      
    %% Calculate ranges
    Ts = tsTimer;
    Vmin = min(velocityMagnitudeMinMax);
    Vmax = max(velocityMagnitudeMinMax);

    timerDeltaMax = pi / (Ts * Vmin);
    timerDeltaMin = pi / (Ts * Vmax);

    hall.TsTimer              = tsTimer;
    hall.VelocityMagnitudeMax = Vmax;
    hall.VelocityMagnitudeMin = Vmin;
    hall.TimerDeltaMax        = timerDeltaMax;
    hall.TimerDeltaMin        = timerDeltaMin;

end

