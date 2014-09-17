function [ OutData] = Ideal_Alternator_Trigger( InData)
%Ideal_Alternator_Trigger Summary of this function goes here
%   Detailed explanation goes here

Engine_Mode = InData(1);
CurCounter = InData(2);

%Check for rising trigger
Counter = CurCounter;
AltTorque = 0;

if Engine_Mode > 0
    Counter = Counter+1;
    if Counter < 3
        AltTorque = 10;
    else
        AltTorque =0;
    end
else
    Counter =0;
    AltTorque =0;
end

SumCounter = Counter;

OutData(1) = AltTorque;
OutData(2) = SumCounter;


end

