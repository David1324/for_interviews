function WriteToLogFile(LogFileName,ParamaterName,ParameterValue,Format)

    LogFileId=fopen(LogFileName,'a');
    
    if (Format=='d')
        ParameterValueStr=sprintf('%d',ParameterValue);
    elseif (Format=='f')
        ParameterValueStr=sprintf('%f',ParameterValue);
    elseif (Format=='s')
        ParameterValueStr=ParameterValue;
    else    
        ParameterValueStr='Invalid format';
    end
    
    fprintf(LogFileId,'%s: %s\n',ParamaterName,ParameterValueStr);
    fclose(LogFileId);
end

