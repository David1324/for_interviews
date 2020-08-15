function distMap = creatDistMap( p,im )
%CREATDISTMAP Summary of this function goes here
%   Detailed explanation goes here

im = double(im);
p = double(p);
patchSq = p.^2;
imSq = im.^2;
patchSqSum = sum(patchSq(:));
onesPatch = ones (size(p,1), size(p,2));
imPatchesSqSum = conv2(double(imSq),double(onesPatch),'same');
%%imPatchesSum = conv2(double(im),double(onesPatch),'same');
patchMulti = conv2(double(im),rot90(p,2),'same');
distMap = imPatchesSqSum + patchSqSum - 2*patchMulti;





end

