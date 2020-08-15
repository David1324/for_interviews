% Process correlations calls CalculateCorrelations with several options
function [ValidX,ValidY]=ProcessCorrelations(GridX,GridY,FileNameList,ValidX,ValidY)
   
    % Load necessary files
    if exist('GridX')==0
        GridX = [];                              % file with x position, created by GenerateGrid.m
    end
    if exist('GridY')==0
        GridY = [];                              % file with y position, created by GenerateGrid.m
    end
    if exist('FileNameList')==0 || isempty(FileNameList)
        load('filenamelist.mat','FileNameList');  % file with the list of filenames to be processed
    end
    if exist('ValidX')==0
        ValidX = [];
    end
    if exist('ValidY')==0
        ValidY = [];
    end
    
    % Delete log file
    LogFileName='dic.log';
    delete(LogFileName);

    % Check for local cpcorr version
    CpCorrData=GetCpCorrData();    
    WriteToLogFile(LogFileName,'CORRSIZE',CpCorrData.CorrSize,'d');
    
    EmptyPrefix=''; % Empty prefix for correlation results (ValidX,ValidY)

    % List of manipulating functions (default: dummy (do nothing))
    ManipFuncPtrs=struct('Filter',@DummyFunc,'Resize',@DummyFunc,'Reduction',@DummyFunc,'Addition',@DummyFunc);
    ManipFuncPtrs.Filter=@(Input,FilterList)CustomFilterFunc(Input,FilterList); % Custom filter list

    % List of processing functions (single processing / multiprocessing)
    ProcFuncPtrs=struct('Init',@InitFunc,'Exit',@ExitFunc,'CollectData',@CollectDataFunc,'Cpcorr',@CpcorrFunc); % single processing
    if CpCorrData.Local==1
        ProcFuncPtrs.Cpcorr=@CpcorrLocalFunc;
    end
    
    % Single / multi processing
    ProcessingModeSelection = menu(sprintf('Processing mode'),'Single processing','Multi processing');
    if ProcessingModeSelection==2
        ProcFuncPtrs.Init=@InitMPFunc;
        ProcFuncPtrs.Exit=@ExitMPFunc;
        ProcFuncPtrs.CollectData=@CollectDataMPFunc;
        ProcFuncPtrs.Cpcorr=@CpcorrMPFunc;
        
        if CpCorrData.Local==1
            ProcFuncPtrs.Cpcorr=@CpcorrLocalMPFunc;
        end
        warning('multiprocessing');
    end
    
    DisplacementSelection = menu(sprintf('ImageCorrelation Main Menu'),'Small displacements','Large displacements (scalar)','Large displacements (vectorial)');
    switch DisplacementSelection
        case 1 % SMALL DISPLACEMENT
            MsgBox=msgbox('Define grid.');
            uiwait(MsgBox)
            drawnow
            [GridX,GridY]=GenerateGrid;
            
            OperationModeSelection = menu(sprintf('Operation mode'),'Full analysis','Resume');
            switch OperationModeSelection
                case 1 % Normal (full analysis)
                    [ValidX,ValidY]=CalculateCorrelations(GridX,GridY,FileNameList,ValidX,ValidY,[],[],ManipFuncPtrs,ProcFuncPtrs,EmptyPrefix,CpCorrData);
                case 2 % Resume
                    ResultsCorrX=dlmread('resultsimcorrx.txt','\t'); % file with x position
                    ResultsCorrY=dlmread('resultsimcorry.txt','\t'); % file with y position
                    
                    [GridXRows,GridXColumns]=size(GridX);
                    [ImageNumber,RasterNumber]=size(ResultsCorrX);
                    if GridXRows*GridXColumns<RasterNumber
                        ResultsCorrX(:,(GridXRows*GridXColumns+1):RasterNumber)=[];
                        ResultsCorrY(:,(GridXRows*GridXColumns+1):RasterNumber)=[];
                    end
                    
                    ResultsCorrX(ImageNumber,:)=[];
                    ResultsCorrY(ImageNumber,:)=[];
                    ValidX=ResultsCorrX';
                    ValidY=ResultsCorrY';
                    
                    save resultsimcorrx.txt ResultsCorrX -ascii -tabs
                    save resultsimcorry.txt ResultsCorrY -ascii -tabs
                    
                    [ValidX,ValidY]=CalculateCorrelations(GridX,GridY,FileNameList,ValidX,ValidY,[],[],ManipFuncPtrs,ProcFuncPtrs,EmptyPrefix,CpCorrData);
                otherwise
                    return
            end
        otherwise % LARGE DISPLACEMENT (scalar and vectorial displacement)
            % Choose resizing factor: the reduction factor should be at least the largest step in your experiment divided by the corrsize you choose in cpcorr.m but will be better off being a little bit higher
            ReductionFactor=5;
            Prompt={'Enter reduction factor - Image will be resized in the first run to track large displacement:'};
            DlgTitle='Reduction factor for large displacements';
            DefValue={num2str(ReductionFactor)};
            Answer=inputdlg(Prompt,DlgTitle,1,DefValue);
            ReductionFactor=str2double(cell2mat(Answer(1,1)));
            WriteToLogFile(LogFileName,'ReductionFactor',ReductionFactor,'d');

            % Choose a coarse (small) grid for reduced size images (the smaller the grid the faster this step)
            MsgBox=msgbox('Define coarse grid for reduced image size - use 50 to 100 markers per image.');
            uiwait(MsgBox)
            drawnow
            [GridXCoarse,GridYCoarse]=GenerateGrid;
            save gridxcoarse.dat GridXCoarse -ascii -tabs
            save gridycoarse.dat GridYCoarse -ascii -tabs

            % Choose a larger (finer) grid for large sized images
            MsgBox=msgbox('Define fine grid for detailed image analysis.');
            uiwait(MsgBox)
            drawnow
            [GridXFine,GridYFine]=GenerateGrid;
            save gridxfine.dat GridXFine -ascii -tabs
            save gridyfine.dat GridYFine -ascii -tabs
            
            % Only for vectorial displacement field: create association list between coarse and fine grid by smallest distance (next neighbour)
            NumOfFineGridPoints=size(GridXFine,1);
            FineGridNeighbors=zeros(NumOfFineGridPoints,1);
            if DisplacementSelection==3
                for CurrentFinePoint=1:NumOfFineGridPoints
                    Distance=(((GridXCoarse(:,1)-GridXFine(CurrentFinePoint,1)).^2+(GridYCoarse(:,1)-GridYFine(CurrentFinePoint,1)).^2).^(0.5));
                    [~,DistanceSortedIndices]=sort(Distance);
                    FineGridNeighbors(CurrentFinePoint,1)=DistanceSortedIndices(1,1);
                end
            end
    
            % Calculate correlations on coarse grid
            ManipFuncPtrs.Resize=@(Input)ResizeImageFunc(Input,ReductionFactor);         % Resizing on coarse grid
            ManipFuncPtrs.Reduction=@(Input)FactorReductionFunc(Input,ReductionFactor);  % Reduction on coarse grid
            [ValidX,ValidY]=CalculateCorrelations(GridXCoarse,GridYCoarse,FileNameList,[],[],[],[],ManipFuncPtrs,ProcFuncPtrs,EmptyPrefix,CpCorrData);

            % Calculate DisplX (displacement in x-direction) and DisplY (displacement in y-direction) 
            switch DisplacementSelection
                case 2 % Scalar displacement field
                    DisplX=diff((mean(ValidX)-mean(ValidX(:,1)))*ReductionFactor);
                    DisplY=diff((mean(ValidY)-mean(ValidY(:,1)))*ReductionFactor);
                    DisplX=[0 DisplX];
                    DisplY=[0 DisplY];
                    DisplX=repmat(DisplX,NumOfFineGridPoints,1);
                    DisplY=repmat(DisplY,NumOfFineGridPoints,1);
                case 3 % Vectorial displacement field
                    NumOfImages=size(FileNameList,1);
                    DisplX=ValidX(FineGridNeighbors,:)*ReductionFactor-repmat(GridXFine,1,NumOfImages-1);
                    DisplX=diff(DisplX,1,2);
                    DisplX=[zeros(NumOfFineGridPoints,1),DisplX];
                    DisplY=ValidY(FineGridNeighbors,:)*ReductionFactor-repmat(GridYFine,1,NumOfImages-1);
                    DisplY=diff(DisplY,1,2);
                    DisplY=[zeros(NumOfFineGridPoints,1),DisplY];
                otherwise
                    return
            end
            
            save displx.dat DisplX -ascii -tabs
            save disply.dat DisplY -ascii -tabs

            % Calculate correlations on fine grid (including previously calculNumOfFineGridPointsated displacements DisplX, DisplY)
            ManipFuncPtrs.Resize=@DummyFunc;
            ManipFuncPtrs.Reduction=@DummyFunc;
            ManipFuncPtrs.Addition=@AdditionFunc;
            [ValidX,ValidY]=CalculateCorrelations(GridXFine,GridYFine,FileNameList,[],[],DisplX,DisplY,ManipFuncPtrs,ProcFuncPtrs,EmptyPrefix,CpCorrData);
    end


