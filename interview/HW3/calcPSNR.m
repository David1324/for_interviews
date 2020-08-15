function  PSNRval= calcPSNR (noisyIm,im)
%CALCPSNR Summary of this function goes here
%   Detailed explanation goes here

differenceMatrix = noisyIm-im;
differenceMatrix = (differenceMatrix.^2);
MSE = sum(differenceMatrix(:))/(size(im,1)*size(im,2));
PSNRval = 10*(log((255^2)/MSE)/log(10));

end

