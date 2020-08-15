function [InputCorrX,InputCorrY,CorrCoef] = CpcorrLocalMPFunc(InputPointsX,InputPointsY,BasePointsX,BasePointsY,DisplX,DisplY,CurrentImage,Input,Base,AdditionFunc,CporrData)
    spmd
        [InputCorrX,InputCorrY,CorrCoef]=CpcorrLocalFunc(InputPointsX,InputPointsY,BasePointsX,BasePointsY,DisplX,DisplY,CurrentImage,Input,Base,AdditionFunc,CporrData);
    end             


