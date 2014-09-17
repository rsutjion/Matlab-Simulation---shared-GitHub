function p = createParameter(value, range, dataType, docUnits, description)

%     % Fully specify fixed point numeric types based on range
%     if ~dataType.isfloat
%         dataType =  numerictype(fi(range,dataType));
%     end

    % Cast value to numerictype
    [castValue,strType] = castToNumericType(value, range, dataType);

    % Create real parameter type
    p = Simulink.Parameter;
    p.Value = double(castValue);
    p.Min = double(min(range));
    p.Max = double(max(range));
    p.DataType = strType;
    p.DocUnits = docUnits;
    p.Description = description;

    p.CoderInfo.StorageClass = 'ExportedGlobal';

   
end

function [castValue, strType] = castToNumericType(value, range, type)

    if type.issingle
        strType = 'single';
        castValue = single(value);
    elseif type.isdouble
        strType = 'double';
        castValue = double(value);
    elseif type.isboolean
        strType = 'boolean';
        castValue = boolean(value);
    elseif type.isfixed
        if ~type.isscalingunspecified
            if     ( type.SignednessBool && type.WordLength==16 && type.FractionLength == 0)
                strType = 'int16';
                castValue = int16(value);
            elseif (~type.SignednessBool && type.WordLength==16 && type.FractionLength == 0)
                strType = 'uint16';
                castValue = uint16(value);
            end
        else
            type =  numerictype(fi(range,type));
            strType = ['fixdt('...
                num2str(type.SignednessBool) ',' ...
                num2str(type.WordLength)     ',' ...
                num2str(type.FractionLength) ')'];
            castValue = fi(value, type);
        end
    else
        error('Unknown data type')
    end
    
end

