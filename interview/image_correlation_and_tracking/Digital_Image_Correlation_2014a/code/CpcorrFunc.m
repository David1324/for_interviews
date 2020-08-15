function [InputCorrX,InputCorrY,CorrCoef] = CpcorrFunc(InputPointsX,InputPointsY,BasePointsX,BasePointsY,DisplX,DisplY,CurrentImage,Input,Base,AdditionFunc,CporrData)
    % Process all markers and images by cpcorr.m (provided by matlab image processing toolbox)
    InputPoints=[AdditionFunc(InputPointsX,DisplX(:,CurrentImage)) AdditionFunc(InputPointsY,DisplY(:,CurrentImage))];
    BasePoints=[BasePointsX,BasePointsY];
    InputCorr=feval(CporrData.FunctionFileName,round(InputPoints),round(BasePoints),Input,Base); 
    InputCorrX=InputCorr(:,1); % results from cpcorr for the x-direction
    InputCorrY=InputCorr(:,2); % results from cpcorr for the y-direction 
    CorrCoef=0;


