function [FilterList]=GetCustomFilter()
    CustomFilterFile='CustomFilter.cfg';
    if exist(CustomFilterFile,'file')
        FileID=fopen(CustomFilterFile);
        FileContent=textscan(FileID,'%[^\n]');
        FilterList=FileContent{1,1};
    else
        FileID=fopen(CustomFilterFile,'w');
        FilterList=[];
    end
    fclose(FileID);
