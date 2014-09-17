function [processor, pmsm, inverter, disc, adc, hall] = hwNovi1F28069Drv8312
% Copyright 2013 The MathWorks, Inc.
    
    % Processor attributes
    processor = struct;
    processor.Description = 'Texas Instruments F28069 Control Card';
    processor.TsClock = 1/90e6;

    % Motor attibutes
    pmsm = pmsmBLY171D;

    %% Inverter attributes
    inverter.Description = 'Texas Instruments DRV8312 Kit';
    inverter.BusVoltage = pmsm.VoltageMax;
    inverter.CurrentMax = 2;

    %% ADC attributes
    adc = adcTexasInstrumentsF28069_DRV8312Kit;

    %% Hall sensor
    hall = hallNovi1;
    
    %% Disc load
    disc = discNone;
    
end