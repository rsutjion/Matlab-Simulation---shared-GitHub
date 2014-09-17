function adc = adcTexasInstrumentsF28069_DRV8312Kit()
% Returns structure of analog to digital converter parameters

adc.Description = 'Texas Instruments F28335 Connected to DRV8312-C2-KIT';

% Hardware ADC sensor measures negative current then goes through an
% inverting amplifier

adc.VoltsPerAmp = (-1) * (1/5.1470);    % Based on hardware tests 2012/08/31
                                        % Note inversion due to measuring negative leg of bridge
adc.BiasVolts       = 1.65;             % V
adc.Bits            = 12;
adc.MaxDriverUnits  = (2^adc.Bits -1);  
adc.MinDriverUnits  = 0;

adc.DriverUnitsPerVolt = adc.MaxDriverUnits / 3.3;
adc.AmpsPerDriverUnit  = (1/adc.DriverUnitsPerVolt) * (1/adc.VoltsPerAmp);
adc.ZeroOffsetDriverUnits = adc.DriverUnitsPerVolt * adc.BiasVolts;
