function cleanIm = meanFilt(im, maskSize, maskSTD)
%MEANFILT Summary of this function goes here
%   Detailed explanation goes here

height = maskSize(1);
width = maskSize(2);

[y,x] = meshgrid((0:height-1)-floor(height/2),(0:width-1)-floor(width/2));

sigma = maskSTD;
mask = exp(-((x.^2+y.^2)/(2*sigma^2)));


mask = mask/sum(mask(:));

paddedIm = padarray(im,[height-1 width-1],'circular', 'both');

cleanIm = uint8(conv2(double(paddedIm), double(mask)));

cleanIm = cleanIm(1:size(im,1), 1:size(im,2));


end

