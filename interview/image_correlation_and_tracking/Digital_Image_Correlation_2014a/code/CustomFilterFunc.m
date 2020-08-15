function [Output]=CustomFilterFunc(Input,FilterList)
    NumOfFilters=size(FilterList,1);
    for Filter=1:NumOfFilters
        TempOutput=eval(FilterList{Filter,1}); 
        Input=TempOutput;
    end
    Output=Input;
