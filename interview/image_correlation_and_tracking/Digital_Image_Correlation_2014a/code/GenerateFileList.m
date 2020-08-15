% Construct a list of 9999 or less filenames
% Programmed by Rob, changed by Chris. Automatic filelist generation and image time aquisition added by Chris, revised by Melanie
% Last revision: 02/11/14
function [FileNameList]=GenerateFileList

    % Possible image extensions
    ImageExtensions = {'tif','bmp','jpg','jpeg','png'};

    FileNameListMode = menu(sprintf('How do you want to create the filenamelist?'),'Manually','Automatically','Cancel');
    switch FileNameListMode
        case 1 
            [FileNameBase,PathNameBase,FileNameList]=GenerateFileListManually(ImageExtensions);
        case 2
            [FileNameBase,PathNameBase,FileNameList]=GenerateFileListAutomatically(ImageExtensions);
        otherwise
            return
    end	
    [FileNameBase,PathNameBase,FileNameList]=ExtractImageTime(FileNameBase,PathNameBase,FileNameList);

% Generate file list automatically (string and number part)
function [FirstImageName,ImageFolder,FileNameList]=GenerateFileListAutomatically(ImageExtensions)

    % Build image string from possible image extensions
    ImageString = [];
    NumOfExtensions = size(ImageExtensions,2);
    for Extension=1:NumOfExtensions
        ImageString = sprintf('%s*.%s;',ImageString,ImageExtensions{Extension});
    end

    drawnow
    [FirstImageName,ImageFolder]=uigetfile(ImageString,'Open First Image');
    if ~isempty(FirstImageName)
        cd(ImageFolder);
    end

    if ~isempty(FirstImageName)

        % Get the number of image name
        Letters=isletter(FirstImageName);
        PointPosition=strfind(FirstImageName,'.');
        FirstImageNameSize=size(FirstImageName);
        Counter=PointPosition-1;
        CounterPos=1;
        LettersTest=0;
        while LettersTest==0
            LettersTest=Letters(Counter);
            if LettersTest==1
                break
            end
            NumberPos(CounterPos)=Counter;
            Counter=Counter-1;
            CounterPos=CounterPos+1;
            if Counter==0
                break
            end
        end

        % Get the string (prefix) of image name
        MinNumberPos=min(NumberPos);
        MaxNumberPos=max(NumberPos);
        ImageFileName=FirstImageName(1:MinNumberPos-1);
        ImageFileNumber=FirstImageName(MinNumberPos:MaxNumberPos);
        ImageExtensionName = FirstImageName(MaxNumberPos+1:FirstImageNameSize(1,2));
        FileNameList(1,:)=FirstImageName;
 
        NumOfDigits = MaxNumberPos-MinNumberPos+1;
        FormatString = sprintf('%%0%dd',NumOfDigits);

        % Get image list
        ExistingFileList=dir;
        ExistingFileList=arrayfun(@(x) getfield(x, 'name'),ExistingFileList,'UniformOutput',false);
        ImageFileNumber=str2num(ImageFileNumber);
        Number=ImageFileNumber+1;
        NumberString=sprintf(FormatString,Number);  
        Counter=1;
        NextFileName=[ImageFileName NumberString ImageExtensionName];
        while find(strcmp(ExistingFileList,NextFileName))
            FileNameList(Counter+1,:)=NextFileName;
            Counter=Counter+1;
            Number=Number+1;
            NumberString=sprintf(FormatString,Number);     
            NextFileName=[ImageFileName NumberString ImageExtensionName];
        end
    end
    [FileNameBase,PathNameBase] = uiputfile('filenamelist.mat','Save as "filenamelist" in image directory (recommended)');
    cd(PathNameBase)
    save(FileNameBase,'FileNameList');

% Generate file list manually (string and number part separately)
function [FileNameBase,PathNameBase,FileNameList]=GenerateFileListManually(ImageExtensions)

    % Prompt user for images to be used for analysis  
    Prompt = {'Enter number of first image (i.e. "3" for PIC00003):','Enter number of last image (i.e. "100" for PIC00100):'};
    DlgTitle = 'Input images to be used for the analysis';
    DefValues = {'1','100'};
    Answer = inputdlg(Prompt,DlgTitle,1,DefValues);
    StartFileNumber = str2num(cell2mat(Answer(1,1)));
    EndFileNumber = str2num(cell2mat(Answer(2,1)));

    MaxFileNumber=10000;
    if  EndFileNumber >= MaxFileNumber
        menu('!!! ERROR - Code will only work properly for 9999 or less picture files !!!','Restart');
        return
    end

    % Choose prefix (string name) of images
    DefValue = 'PIC1';
    Prompt = {'Enter image name (fix leading letters + numbers):'};
    DlgTitle = 'Input images to be used for the analysis';
    Answer = inputdlg(Prompt,DlgTitle,1,{DefValue});
    Prefix = cell2mat(Answer(1,1));

    % Choose image extension
    ImageExtensionNumber = menu(sprintf('Choose image extension'),ImageExtensions);
    ImageExtension=ImageExtensions{ImageExtensionNumber};
    ImageExtension=sprintf('.%s',ImageExtension);
    ImageExtensionLength=size(ImageExtension,2);
    
    % Choose number of digits in number
    DefValue = '4';
    Prompt = {'Enter number of digits for image number:'};
    DlgTitle = 'Input images to be used for the analysis';
    Answer = inputdlg(Prompt,DlgTitle,1,{DefValue});
    NumOfDigits = str2num(cell2mat(Answer(1,1)));
    FormatString = sprintf('%%0%dd',NumOfDigits);

    % Create the list (name + number + image file extension)
    NumOfFiles = EndFileNumber-StartFileNumber+1;
    Numbers=(StartFileNumber:EndFileNumber)';
    for FileCount=1:NumOfFiles
        NumbersString(FileCount,:)=sprintf(FormatString,Numbers(FileCount));     
    end
    NumbersStringLength=size(NumbersString,2);
    PrefixLength = size(Prefix,2);
    FileNameList = zeros(NumOfFiles,PrefixLength+NumbersStringLength+ImageExtensionLength);
    NumbersStringStart = PrefixLength+1;
    NumbersStringEnd = NumbersStringStart+NumbersStringLength-1;
    ImageExtensionStart = NumbersStringEnd+1; 
    ImageExtensionEnd = ImageExtensionStart+ImageExtensionLength-1;
    for FileCount=1:NumOfFiles
        FileNameList(FileCount,1:PrefixLength)=Prefix;
        FileNameList(FileCount,NumbersStringStart:NumbersStringEnd)=NumbersString(FileCount,:);
        FileNameList(FileCount,ImageExtensionStart:ImageExtensionEnd)=ImageExtension;
    end
    FileNameList = char(FileNameList);

    % Save results
    [FileNameBase,PathNameBase] = uiputfile('filenamelist.mat','Save as "filenamelist" in image directory (recommended)');
    cd(PathNameBase)
    save(FileNameBase,'FileNameList');

% Extract the time from images?
function [FileNameBase,PathNameBase,FileNameList]=ExtractImageTime(FileNameBase,PathNameBase,FileNameList)

    ExtractTime = menu(sprintf('Do you also want to extract the time from images to match stress and strain?'),'Yes','No');
    if ExtractTime==1

        % Loop through all images to get all image capture times
        [NumOfFiles,~]=size(FileNameList);
        WaitBar=waitbar(0,'Extracting the image capture times...');
        Seconds = zeros(1,NumOfFiles);
        for File=1:NumOfFiles
            waitbar(File/NumOfFiles);
            Info=imfinfo(FileNameList(File,:));
            Time=datevec(Info.FileModDate,13);
            Seconds(File)=Time(1,4)*3600+Time(1,5)*60+Time(1,6);
        end
        close(WaitBar)

        % Configure and then save image number vs. image capture time text file
        CaptureTimes=[(1:NumOfFiles)' Seconds'];
        save timeimage.txt CaptureTimes -ascii -tabs

    end