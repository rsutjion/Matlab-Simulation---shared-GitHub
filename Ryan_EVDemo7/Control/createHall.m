function hall = createHall(...
          name,...
          description,...
          docLink,...
          positiveDirectionStates,...
          positionInFirstState,...
          tsTimer,...
          velocityMagnitudeMinMax)
        
% Copyright 2012-2013 The MathWorks, Inc.
if nargin < 1
    name = 'Default';
end

if nargin < 2
    description = '';
end

if nargin < 3
    docLink = '';
end

if nargin < 4
    positiveDirectionStates = [
        bin2dec('101')
        bin2dec('100')
        bin2dec('110')
        bin2dec('010')
        bin2dec('011')
        bin2dec('001')];
end

if nargin < 5
    positionInFirstState = 0;
end

if nargin < 6
    tsTimer = 1/50e6;
end

if nargin < 7
    velocityMagnitudeMinMax = [50 500];
end

angleAtStartOfPositiveDirectionStates = positionInFirstState;

hall.Name        = name;
hall.Description = description;
hall.DocLink     = docLink;

%% Create helper table describing states and positions
numStates = size(positiveDirectionStates,1);

columnState                      = 1;
columnCenterPosition             = 2;
columnNextStatePositiveDirection = 3;
columnNextStateNegativeDirection = 4;
columnPositionPositiveDirection  = 5;
columnPositionNegativeDirection  = 6;
numRows = 6;

tmpTable = zeros(numStates,numRows);

% Populate first column with states
for ii = 1:numStates
    tmpTable(ii,columnState) = positiveDirectionStates(ii);
end

% Specify centered angular position for each state
tmpTable(1,columnCenterPosition) = angleAtStartOfPositiveDirectionStates + 2*pi/12;
for ii = 2:numStates
    tmpTable(ii,columnCenterPosition) = ...
        tmpTable(ii-1,columnCenterPosition) + 2*pi/6;
end
tmpTable(:,columnCenterPosition) = mod(tmpTable(:,columnCenterPosition),2*pi);

% Specify next states
for ii = 1:numStates
    if ii < 6
        iNext = ii + 1;
    else
        iNext = 1;
    end
    if ii > 1
        iPrev = ii - 1;
    else
        iPrev = numStates;
    end
    
    % Positive direction next states
    tmpTable(ii,columnNextStatePositiveDirection) = ...
        tmpTable(iNext, columnState);
    
    % Negative direction next states
    tmpTable(ii,columnNextStateNegativeDirection) = ...
        tmpTable(iPrev, columnState);

    % Position if entered state from positive direction
    tmpTable(ii,columnPositionPositiveDirection) = ...
        averageAngle(tmpTable(iPrev,columnCenterPosition),...
                     tmpTable(ii,   columnCenterPosition));
        
    % Position if entered state from negative direction
    tmpTable(ii,columnPositionNegativeDirection) = ...
        averageAngle(tmpTable(ii,   columnCenterPosition),...
                     tmpTable(iNext,columnCenterPosition));
    
end

%%
for ii = 1:numStates
    if ii < 6
        iNext = ii + 1;
    else
        iNext = 1;
    end
    
    curState  = tmpTable(ii,   columnState);
    nextState = tmpTable(iNext,columnState);
    
    % Hall A
    curStateA  = bitand(curState, bin2dec('100')) * 2^-2;
    nextStateA = bitand(nextState,bin2dec('100')) * 2^-2;
    if (curStateA == 0) && (nextStateA == 1)
        hall.A_RisingEdge = tmpTable(iNext,columnPositionPositiveDirection);
    end
    
    if (curStateA == 1) && (nextStateA == 0)
        hall.A_FallingEdge = tmpTable(iNext,columnPositionPositiveDirection);
    end

    % Hall B
    curStateB  = bitand(curState, bin2dec('010')) * 2^-1;
    nextStateB = bitand(nextState,bin2dec('010')) * 2^-1;
    if (curStateB == 0) && (nextStateB == 1)
        hall.B_RisingEdge = tmpTable(iNext,columnPositionPositiveDirection);
    end
    
    if (curStateB == 1) && (nextStateB == 0)
        hall.B_FallingEdge = tmpTable(iNext,columnPositionPositiveDirection);
    end

    % Hall C
    curStateC  = bitand(curState, bin2dec('001'));
    nextStateC = bitand(nextState,bin2dec('001'));
    if (curStateC == 0) && (nextStateC == 1)
        hall.C_RisingEdge = tmpTable(iNext,columnPositionPositiveDirection);
    end
    
    if (curStateC == 1) && (nextStateC == 0)
        hall.C_FallingEdge = tmpTable(iNext,columnPositionPositiveDirection);
    end

end

%% Sort table based on integer value of state
[~, iSort] = sort(positiveDirectionStates);
tmpTable = tmpTable(iSort,:);

%% Extract sorted arrays
hall.PositiveDirectionStates    = positiveDirectionStates;
hall.PositionCenter             = tmpTable(:,columnCenterPosition);
hall.NextStatePositiveDirection = tmpTable(:,columnNextStatePositiveDirection);
hall.NextStateNegativeDirection = tmpTable(:,columnNextStateNegativeDirection);
hall.PositionPositiveDirection  = tmpTable(:,columnPositionPositiveDirection);
hall.PositionNegativeDirection  = tmpTable(:,columnPositionNegativeDirection);

%% Set default timer and range information
hall = setHallTimerAndRange(hall,...
        tsTimer,...
        velocityMagnitudeMinMax);

end

function angle = averageAngle(angle1, angle2)

    %Average from 1 moving to 2
    if angle1 < angle2
        angle = (angle1 + angle2)/2;
    else
        angle = (angle1 + angle2 + 2*pi)/2;
        angle = mod(angle,2*pi);
    end
end


