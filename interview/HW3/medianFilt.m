function [ cleanIm ] = medianFilt( im, winSize )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

height = winSize(1);
width = winSize(2);
paddedIm = padarray(im,[height-1 width-1],'circular', 'both');

[rows,cols] = size(im);

cleanIm = im;
for i=1:rows
   for j=1:cols
        subIm = paddedIm(i:i+height-1,j:j+width-1);
        cleanIm(i,j) = median(subIm(:));
   end
end


end

