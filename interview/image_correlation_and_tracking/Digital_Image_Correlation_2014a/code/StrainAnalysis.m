% Strain Analysis
% Programmed by Chris
% Revised by Melanie
% Last revision: 02/09/14
function [XI,YI,ZI,Eps]=StrainAnalysis(ValidX,ValidY,Direction,Mode,Type)

    switch Direction
        case 'x' % x-direction
            Valid=ValidX;
        case 'y' % y-direction
            Valid=ValidY;
        otherwise % invalid
            return
    end
    
    % Get displacement depending on direction
    Displ=GetMeanDisplacement(Valid);
    XI=[];
    YI=[];
    ZI=[];
    Eps=[];
    
    % mode is either gui (with visualization) or silent (without visualization)
    switch Mode
        case 'silent'
            switch Type
                case 'FullStrain2D'
                    [XI,YI,ZI,Eps]=GetFullStrain2D(ValidX,ValidY,Displ);
                case 'AverageStrain1D'
                    [XI,YI,Eps]=GetAverageStrain1D(Valid,Displ);
                otherwise % Cancel
            end        
            return
    end

    Selection = menu(sprintf('How do you want to visualize your data?'),'Average strain 1D','Local strain 1D','Full strain 2D','Strain between 2 points 1D','Go Back');
    switch Selection
        case 1 % Average strain 1D
            AverageStrain1D(Valid,Displ,Direction);
        case 2 % Local strain 1D
            LocalStrain1D(ValidX,ValidY,Direction);
        case 3 % Full strain 2D
            FullStrain2D(ValidX,ValidY,Displ,Direction);
        case 4 % Strain between 2 points 1D
            Strain2Points1D(ValidX,ValidY,Displ,Direction);
        otherwise % Cancel
            return
    end
    
 % Create grid based on ValidX,ValidY
 function [XI,YI]=CreateGrid(ValidX,ValidY)
 
    GridSizeX=10*round(min(min(ValidX))/10):10:10*round(max(max(ValidX))/10);
    GridSizeY=10*round(min(min(ValidY))/10):10:10*round(max(max(ValidY))/10);
    [XI,YI]=meshgrid(GridSizeX,GridSizeY);
    
% Calculate and plot averaged strain (in x- or y-direction) by curve fitting for each image 
function AverageStrain1D(Valid,Displ,Direction)
    
    VideoSelection = menu(sprintf('Do you want to create a video?'),'Yes','No');
    if VideoSelection==1
        mkdir('videostrain');
        cd('videostrain');
        VideoStr='Vid';
    end

    StrainFigure=figure;
    [X,Y,Eps]=GetAverageStrain1D(Valid,Displ);
    NumOfImages=size(X,2);
    for CurrentImage=1:NumOfImages;
        
        % Plot displacement over position
        XData=X(:,CurrentImage);
        YData=Y(:,CurrentImage);
        plot(XData,YData,'o');

        hold on
        Beta=Eps(:,2:3);
        YDataPredicted=Line(Beta(CurrentImage,:),XData);
        plot(XData,YDataPredicted,'r');

        hold off
        axis([min(min(X)) max(max(X)) min(min(Y)) max(max(Y))]);
        XLabel=sprintf('%s-position [pixel]',Direction);
        xlabel(XLabel);
        YLabel=sprintf('%s-displacement [pixel]',Direction);
        ylabel(YLabel);

        Title=sprintf('Displacement in %s-direction versus %s-position',Direction,Direction);
        title([Title,sprintf(' (current image #: %1g, ',CurrentImage),sprintf('strain: %1g)',Beta(1))]);
        drawnow
        if VideoSelection==1
            Number=CurrentImage+10000;
            NumberStr=num2str(Number);
			VideoFileExtension='jpg';
            VideoName=[VideoStr NumberStr '.' VideoFileExtension];
            saveas(StrainFigure,VideoName,VideoFileExtension);
        end
    end
    plot(Eps(:,1),Eps(:,2));
    hold on
    plot(Eps(:,1),Eps(:,2),'.');
    xlabel('image');
    YLabel=sprintf('Mean strain in %s-direction',Direction);
    ylabel(YLabel);
    Title=sprintf('Mean strain in %s-direction vs. image #',Direction);
    title(Title);

    % Save fit data
    if VideoSelection==1
        cd('..');
    end
    FileName=sprintf('strain%sfit.dat',Direction);
    save(FileName,'Eps','-ASCII','-tabs');
    
% Calculate averaged strain (in x- or y-direction) by curve fitting for each image 
function [X,Y,Eps]=GetAverageStrain1D(Valid,Displ)   
    
    NumOfImages=size(Valid,2);
    Eps=zeros(NumOfImages,3);
    for CurrentImage=1:NumOfImages;
        if CurrentImage==1
            Beta(1)=0;
            Beta(2)=0;
        end
        XData=Valid(:,CurrentImage);
        YData=Displ(:,CurrentImage);
        [Beta]=lsqcurvefit(@Line,[Beta(1) Beta(2)],XData,YData);
        Eps(CurrentImage,:)=[CurrentImage Beta];
    end
    X=Valid;
    Y=Displ;
    
% Calculate and plot the local resolved strain (for defined regions, e.g. 20) (in x- or y-direction) by the gradient for each image
function LocalStrain1D(ValidX,ValidY,Direction)

    SelectionFigure=figure;
    SizeValidX=size(ValidX);
    NumOfImages=SizeValidX(1,2);
    SelectedImage=SelectImage(NumOfImages);
    
    % Plot markers in the selected region
    plot(ValidX(:,SelectedImage),ValidY(:,SelectedImage),'+b');
    title(sprintf('Define the region of interest.\n Pick (single click) a point in the LOWER LEFT region of the gage section.\n  Do the same for a point in the UPPER RIGHT portion of the gage section.'));
    Labels={'x-position [pixel]','y-position [pixel]'};
    switch Direction
        case 'x' % x-direction
            xlabel(Labels{1,1});
            ylabel(Labels{1,2});
        case 'y' % y-direction
            xlabel(Labels{1,2});
            ylabel(Labels{1,1});
    end
    hold on
    [X(1,1),Y(1,1)]=ginput(1);
    plot(X(1,1),Y(1,1),'+b');
    plot([min(ValidX(:,SelectedImage)); max(ValidX(:,SelectedImage))], [Y(1,1); Y(1,1)],'-r');
    plot([X(1,1),X(1,1)], [min(ValidY(:,SelectedImage)),max(ValidY(:,SelectedImage))],'-r');

    [X(2,1),Y(2,1)]=ginput(1);
    hold on
    plot(X(2,1),Y(2,1),'+b');
    plot([min(ValidX(:,SelectedImage)); max(ValidX(:,SelectedImage))], [Y(2,1); Y(2,1)],'-r');
    plot([X(2,1),X(2,1)], [min(ValidY(:,SelectedImage)),max(ValidY(:,SelectedImage))],'-r');

    XMin = min(X);
    XMax = max(X);
    YMin = min(Y);
    YMax = max(Y);

    LowerLine=[XMin YMin; XMax YMin];
    UpperLine=[XMin YMax; XMax YMax];
    LeftLine=[XMin YMin; XMin YMax];
    RightLine=[XMax YMin; XMax YMax];

    plot(LowerLine(:,1),LowerLine(:,2),'-g');
    plot(UpperLine(:,1),UpperLine(:,2),'-g');
    plot(LeftLine(:,1),LeftLine(:,2),'-g');
    plot(RightLine(:,1),RightLine(:,2),'-g');

    SelectedPoints=find(ValidX(:,SelectedImage)>XMin & ValidX(:,SelectedImage)<XMax & ValidY(:,SelectedImage)<YMax & ValidY(:,SelectedImage)>YMin);

    ValidXNew=ValidX(SelectedPoints,:);
    ValidYNew=ValidY(SelectedPoints,:);

    hold on
    plot(ValidXNew(:,SelectedImage),ValidYNew(:,SelectedImage),'+g');
    title('Red dots represent your new raster.');
    hold off
    drawnow

    % Apply grid?
    GridSelection = menu(sprintf('Do you want to use the green highlighted markers?'),'Yes','No');

    if GridSelection==2
        return
    end

    % Choose number of area parts
    Prompt={'Into how many area parts do you want to split the markers?'};
    DlgTitle='Divide markers';
    DefaultSplitValue=10;
    DefValue={num2str(DefaultSplitValue)};
    Answer=inputdlg(Prompt,DlgTitle,1,DefValue);
    SelectedSplitValue=str2num(cell2mat(Answer(1,1)));

    if SelectedSplitValue<1
        SelectedSplitValue=DefaultSplitValue;
    end

    hold on
    
    % Plot area parts
    PosX=zeros(1,SelectedSplitValue);
    MarkerDisplacementX=zeros(NumOfImages,SelectedSplitValue);
    MarkerDisplacementY=zeros(NumOfImages,SelectedSplitValue);
    for CurrentValue=1:SelectedSplitValue
        PosX(CurrentValue)=XMin+((XMax-XMin)/SelectedSplitValue)*CurrentValue;
        plot([PosX(CurrentValue);PosX(CurrentValue)],[YMin; YMax],'-m');
        SelectedMarkers=find(ValidXNew(:,SelectedImage)>(XMin+((XMax-XMin)/SelectedSplitValue)*(CurrentValue-1)) & ValidXNew(:,SelectedImage)<(XMin+((XMax-XMin)/SelectedSplitValue)*(CurrentValue)));
        ValidXPlot=ValidXNew(SelectedMarkers,:);
        ValidYPlot=ValidYNew(SelectedMarkers,:);
        plot(ValidXPlot(:,SelectedImage),ValidYPlot(:,SelectedImage),'+r');
        drawnow
        ValidYLocal=ValidYPlot;
        MarkerDisplacementY(:,CurrentValue)=mean(ValidYLocal)';
        ValidXLocal=ValidXPlot;
        MarkerDisplacementX(:,CurrentValue)=mean(ValidXLocal)';
        plot(ValidXLocal(:,SelectedImage),ValidYLocal(:,SelectedImage),'xg');
        drawnow
    end

    hold off

   	% Save marker displacement
    save('markerdisplacementx.txt','MarkerDisplacementX','-ASCII','-tabs');
    save('markerdisplacementy.txt','MarkerDisplacementY','-ASCII','-tabs');

    % Get gradient in x and y direction   
    SizeMDX=size(MarkerDisplacementX);
    MValidXFirst=ones(SizeMDX(1,1),1)*MarkerDisplacementX(1,:);
    MDX=MarkerDisplacementX-MValidXFirst;
    MValidYFirst=ones(SizeMDX(1,1),1)*MarkerDisplacementY(1,:);
    MDY=MarkerDisplacementY-MValidYFirst;
    
    GradMDX=gradient(MDX);
    GradMDY=gradient(MDY);
    GradMarkerDisplacementX=gradient(MarkerDisplacementX);
    GradMarkerDisplacementY=gradient(MarkerDisplacementY);
    GradientX=GradMDX./GradMarkerDisplacementX;
    GradientY=GradMDY./GradMarkerDisplacementY;

    % Save gradient
    save('gradientx.txt','GradientX','-ASCII','-tabs');
    save('gradienty.txt','GradientY','-ASCII','-tabs');

    % Check displacement?
    Title=sprintf('Do you want to check the displacement in %s-direction?',Direction);
    CheckDisplacement = menu(sprintf(Title),'Yes','No');
    if CheckDisplacement==1
        DisplacementFigure=figure;
        for CurrentImage=1:NumOfImages
            switch(Direction)
                case 'x'
                    plot(MarkerDisplacementX(CurrentImage,:),MDX(CurrentImage,:),'.r');
                    axis([min(min(MarkerDisplacementX)) max(max(MarkerDisplacementX)) min(min(MDX)) max(max(MDX))]);
                case 'y'
                    plot(MarkerDisplacementY(CurrentImage,:),MDY(CurrentImage,:),'.r');
                    axis([min(min(MarkerDisplacementY)) max(max(MarkerDisplacementY)) min(min(MDY)) max(max(MDY))]);
            end
            Title=sprintf('Displacement in %s-direction',Direction);
            title([Title,sprintf(' (current image #: %1g)',CurrentImage)]);
            XLabel=sprintf('%s-position [pixel]',Direction);
            xlabel(XLabel);
            YLabel=sprintf('local %s-displacement',Direction);
            ylabel(YLabel);
            drawnow
        end
    end

    % Check strain?
    Title=sprintf('Do you want to check the local strain in %s-direction?',Direction);
    CheckStrain = menu(sprintf(Title),'Yes','No');
    VideoSelection = menu(sprintf('Do you want to create a video?'),'Yes','No');
    if VideoSelection==1
        mkdir('videolocalstrain');
        cd('videolocalstrain');
        VideoStr='Vid';
    end
    if CheckStrain==1
        StrainFigure=figure;
        for CurrentImage=1:NumOfImages
            switch(Direction)
                case 'x'
                    plot(MarkerDisplacementX(CurrentImage,:),GradientX(CurrentImage,:),'.-b');
                    axis([min(min(MarkerDisplacementX)) max(max(MarkerDisplacementX)) min(min(GradientX)) max(max(GradientX))]);
                case 'y'
                    plot(MarkerDisplacementY(CurrentImage,:),GradientY(CurrentImage,:),'.-b');
                    axis([min(min(MarkerDisplacementY)) max(max(MarkerDisplacementY)) min(min(GradientY)) max(max(GradientY))]);
            end
            Title=sprintf('Gradient of displacement in %s-direction',Direction);
            title([Title,sprintf(' (current image #: %1g)',CurrentImage)]);
            XLabel=sprintf('%s-position [pixel]',Direction);
            xlabel(XLabel);
            YLabel=sprintf('local %s-displacement gradient',Direction);
            ylabel(YLabel);
            drawnow

            if VideoSelection==1
                Number=CurrentImage+10000;
                NumberStr=num2str(Number);
                VideoName=[VideoStr NumberStr '.jpg'];
                saveas(StrainFigure,VideoName,'jpg');
            end
        end
        if VideoSelection==1
            cd('..');
        end
    end
    
% Calculate and plot the strain (in x- or y-direction) by the gradient for each image
function FullStrain2D(ValidX,ValidY,Displ,Direction)

    StrainFigure=figure;
    SizeValidX=size(ValidX);
    NumOfImages=SizeValidX(1,2);    
    DisplColor=[-7 1];
    StrainColor=[-0.005 0.03];
    [XI,YI,ZI,EpsXX]=GetFullStrain2D(ValidX,ValidY,Displ);
    
    Labels={'x-position [pixel]','y-position [pixel]'};
    switch Direction
        case 'x' % x-direction
            XLabel=(Labels{1,1});
            YLabel=(Labels{1,2});
        case 'y' % y-direction
            XLabel=(Labels{1,2});
            YLabel=(Labels{1,1});
    end

    for CurrentImage=1:NumOfImages         
        subplot(2,1,1);
        CurrentZI=ZI(CurrentImage,:,:);
        CurrentZI=reshape(CurrentZI,size(XI,1),size(XI,2));
        pcolor(XI,YI,CurrentZI);
        axis('equal');
        shading('interp');
        caxis(DisplColor);
        ColorBar=colorbar;
        set(ColorBar,'PlotBoxAspectRatio',[2.0 10 8.0]);
        set(ColorBar,'FontSize', 12);
        Title=sprintf('Raw displacement in %s-direction',Direction);
        title([Title,sprintf(' (current image #: %1g)',CurrentImage)]);
        xlabel(XLabel);
        ylabel(YLabel);
        ZLabel=sprintf('%s-displacement [pixel]',Direction);
        zlabel(ZLabel);

        subplot(2,1,2);
        CurrentEpsXX=EpsXX(CurrentImage,:,:);
        CurrentEpsXX=reshape(CurrentEpsXX,size(XI,1),size(XI,2));
        pcolor(XI,YI,CurrentEpsXX);
        axis('equal');
        shading('interp');
        caxis(StrainColor);
        ColorBar = colorbar;
        set(ColorBar,'PlotBoxAspectRatio',[2.0 10 8.0]);
        set(ColorBar,'FontSize',12);
        Title=sprintf('Raw strain in %s-direction',Direction);
        title([Title,sprintf(' (current image #: %1g)',CurrentImage)]);
        xlabel(XLabel);
        ylabel(YLabel);
        ZLabel=sprintf('%s-strain',Direction);
        zlabel(ZLabel);
        drawnow
    end

% Calculate the strain by the gradient for each image
function [XI,YI,ZI,EpsXX]=GetFullStrain2D(ValidX,ValidY,Displ)

    SizeValidX=size(ValidX);
    NumOfImages=SizeValidX(1,2);
    [XI,YI]=CreateGrid(ValidX,ValidY);
    DiffValidX=(max(max(ValidX))-min(min(ValidX)));
    DiffValidY=(max(max(ValidY))-min(min(ValidY)));
    ZI=[];
    EpsXX=[];

    for CurrentImage=1:NumOfImages
        %CurrentZI=griddata(ValidX(:,CurrentImage),ValidY(:,CurrentImage),Displ(:,CurrentImage),XI,YI,'cubic');'nearest'
        CurrentZI=griddata(ValidX(:,CurrentImage),ValidY(:,CurrentImage),Displ(:,CurrentImage),XI,YI,'v4');
        ZISize=size(CurrentZI);
        CurrentEpsXX=gradient(CurrentZI,(DiffValidX/ZISize(1,1)),(DiffValidY/ZISize(1,2)));
        ZI(CurrentImage,:,:)=CurrentZI;
        EpsXX(CurrentImage,:,:)=CurrentEpsXX;
    end    
    
% Calculate and plot strain (in x- or y-direction) between 2 points for each image 
function Strain2Points1D(ValidX,ValidY,Displ,Direction)

    DisplacementFigure=figure;
    SizeValidX=size(ValidX);
    NumOfImages=SizeValidX(1,2);
    SelectedImage=SelectImage(NumOfImages);
    
    [XI,YI]=CreateGrid(ValidX,ValidY);
    ZI=griddata(ValidX(:,SelectedImage),ValidY(:,SelectedImage),Displ(:,SelectedImage),XI,YI,'cubic');
    pcolor(XI,YI,ZI);
    axis('equal');
    caxis([min(min(ZI)) max(max(ZI))]);
    colorbar;
    shading('interp');
    hold on
    plot3(ValidX(:,SelectedImage),ValidY(:,SelectedImage),abs(Displ(:,SelectedImage)),'o','MarkerEdgeColor','k','MarkerFaceColor','g');
    axis([min(min(XI))-10 max(max(XI))+10 min(min(YI))-10 max(max(YI))+10]);
    drawnow

    % Get 2 points
    title('Click on the two points for strain measurement');
    Labels={'x-position [pixel]','y-position [pixel]'};
    switch Direction
        case 'x' % x-direction
            xlabel(Labels{1,1});
            ylabel(Labels{1,2});
        case 'y' % y-direction
            xlabel(Labels{1,2});
            ylabel(Labels{1,1});
    end
  
    ZLabel=sprintf('%s-displacement [pixel]',Direction);
    zlabel(ZLabel);
    [Points]=ginput(2);

    % Find points at given positions (smallest distance)
    RelativePos1=abs(ValidX(:,SelectedImage)-Points(1,1))+abs(ValidY(:,SelectedImage)-Points(1,2));
    SelectedPoint1=find(RelativePos1==min(RelativePos1));
    RelativePos2=abs(ValidX(:,SelectedImage)-Points(2,1))+abs(ValidY(:,SelectedImage)-Points(2,2));
    SelectedPoint2=find(RelativePos2==min(RelativePos2));

    % Update figure
    plot3(ValidX(SelectedPoint1,SelectedImage),ValidY(SelectedPoint1,SelectedImage),abs(Displ(SelectedPoint1,SelectedImage)),'+','MarkerEdgeColor','k','MarkerFaceColor','r');
    plot3(ValidX(SelectedPoint2,SelectedImage),ValidY(SelectedPoint2,SelectedImage),abs(Displ(SelectedPoint2,SelectedImage)),'+','MarkerEdgeColor','k','MarkerFaceColor','r');
    hold off
    axis([min(min(XI))-10 max(max(XI))+10 min(min(YI))-10 max(max(YI))+10]);
    drawnow

    % Calculate and plot strain
    StrainFigure=figure;
    Epsilon1D=(Displ(SelectedPoint1,:)-Displ(SelectedPoint2,:))/(ValidX(SelectedPoint1,1)-ValidX(SelectedPoint2,1));
    EpsilonSize=size(Epsilon1D);
    plot(1:EpsilonSize(1,2),Epsilon1D,'.');
    title('True strain versus image #');
    xlabel('image');
    YLabel = sprintf('true strain in %s-direction',Direction);
    ylabel(YLabel);
    drawnow

    % Save epsilon data
    EpsilonData = [(1:NumOfImages)' Epsilon1D'];
    FileName=sprintf('strain%s2p.dat',Direction);
    save(FileName,'EpsilonData','-ASCII','-tabs');