clear;
clc;
close all;



num_points = 33; % number of points
points = zeros(num_points,2);


points(1,:) = [45,35];      %REyebrowEnd
points(2,:) = [83,43];      %REyebrowMid
points(3,:) = [177,16];     %ROrbitalUpper
points(4,:) = [276,9];      %LOrbitalUpper
points(5,:) = [367,35];     %LEyebrowMid
points(6,:) = [415,31];     %LEyebrowEnd
points(7,:) = [228,107];    %NoseBridge
points(8,:) = [235,203];    %NoseTip
points(9,:) = [292,219];    %LNostrilBulge
points(10,:) = [329,229];   %LNostrilBase
points(11,:) = [190,220];   %RNostrilBulge
points(12,:) = [152,234];   %RNostrilBase
points(13,:) = [331,65];    %LEyelidUpper
points(14,:) = [321,127];   %LEyelidLower
points(15,:) = [121,74];    %REyelidUpper
points(16,:) = [141,131];   %REyelidLower
points(17,:) = [42,185];    %ROrbitalLower
points(18,:) = [5,168];     %REar
points(19,:) = [426,181];   %LOrbitalLower
points(20,:) = [458,171];   %LEar
points(21,:) = [86,299];    %Rpuffer
points(22,:) = [135,307];   %RMouthCorner
points(23,:) = [162,290];   %RLipUpperBend
points(24,:) = [242,281];   %LipUpper
points(25,:) = [306,289];   %LLipUpperBend
points(26,:) = [344,306];   %LMouthCorner
points(27,:) = [394,298];   %Lpuffer
points(28,:) = [173,330];   %RLipLowerBend
points(29,:) = [242,348];   %LipLower
points(30,:) = [302,335];   %LLipLowerBend
points(31,:) = [174,430];   %RJawEnd
points(32,:) = [247,420];   %mpChin
points(33,:) = [311,431];   %LJawEnd

points_x = points(:,1);
points_y = points(:,2);

face_points = zeros(num_points,2);
face_points(:,1) = points_x;
face_points(:,2) = 450-points_y;
face_points(:,3) = zeros(num_points,1);

shuffled_face_points=zeros(num_points,3);
shuffled_face_points(1,:)=face_points(11,:);
shuffled_face_points(2,:)=face_points(13,:);
shuffled_face_points(3,:)=face_points(5,:);
shuffled_face_points(4,:)=face_points(6,:);
shuffled_face_points(5,:)=face_points(12,:);
shuffled_face_points(6,:)=face_points(4,:);
shuffled_face_points(7,:)=face_points(14,:);
shuffled_face_points(8,:)=face_points(3,:);
shuffled_face_points(9,:)=face_points(7,:);
shuffled_face_points(10,:)=face_points(1,:);
shuffled_face_points(11,:)=face_points(10,:);
shuffled_face_points(12,:)=face_points(8,:);
shuffled_face_points(13,:)=face_points(15,:);
shuffled_face_points(14,:)=face_points(9,:);
shuffled_face_points(15,:)=face_points(2,:);
shuffled_face_points(16,:)=face_points(22,:);
shuffled_face_points(17,:)=face_points(20,:);
shuffled_face_points(18,:)=face_points(25,:);
shuffled_face_points(19,:)=face_points(19,:);
shuffled_face_points(20,:)=face_points(23,:);
shuffled_face_points(21,:)=face_points(21,:);
shuffled_face_points(22,:)=face_points(26,:);
shuffled_face_points(23,:)=face_points(18,:);
shuffled_face_points(24,:)=face_points(24,:);
shuffled_face_points(25,:)=face_points(16,:);
shuffled_face_points(26,:)=face_points(33,:);
shuffled_face_points(27,:)=face_points(27,:);
shuffled_face_points(28,:)=face_points(32,:);
shuffled_face_points(29,:)=face_points(17,:);
shuffled_face_points(30,:)=face_points(29,:);
shuffled_face_points(31,:)=face_points(31,:);
shuffled_face_points(32,:)=face_points(28,:);
shuffled_face_points(33,:)=face_points(30,:);

plot_face_points( face_points );
%plot_face_points( shuffled_face_points );

