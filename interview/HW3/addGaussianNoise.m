function [ noisyIm ] = addGaussianNoise( im, s )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here


a = randn(size(im));
b=s*a;
c=round(b);

noisyIm = double(im)+c;
noisyIm(noisyIm<0)=0;
noisyIm(noisyIm>255)=255;

noisyIm = uint8(noisyIm);

end

