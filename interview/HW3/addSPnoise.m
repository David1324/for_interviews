function [ noisyIm ] = addSPnoise( im, p )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

%this function adds salt and paper noise

msize=numel(im);

salt = round(msize*p/2);
pepper = salt;

noisyIm = im;
noisyIm(randperm(msize,salt))=255;
noisyIm(randperm(msize,pepper))=0;

end

