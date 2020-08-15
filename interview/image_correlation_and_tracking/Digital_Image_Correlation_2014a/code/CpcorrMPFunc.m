function [InputCorrX,InputCorrY,CorrCoef] = CpcorrMPFunc(InputPointsX,InputPointsY,BasePointsX,BasePointsY,DisplX,DisplY,CurrentImage,Input,Base,AdditionFunc,CporrData)
    spmd
        [InputCorrX,InputCorrY,CorrCoef]=CpcorrFunc(InputPointsX,InputPointsY,BasePointsX,BasePointsY,DisplX,DisplY,CurrentImage,Input,Base,AdditionFunc,CporrData);
    end             


