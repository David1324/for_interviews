function targetImageWithBlendedPatch = PoissonColorImageBlending(target_image_with_gradient_patch, MaskTarg)
%This function splits color image into 3 colors and pastes source into target image
%seperately
%Input:
%   target_image_with_gradient_patch - Target image with the gradient of
%   source image within the masked area
%   MaskTarg    - Mask area for source to be pasted into. this is a logical
%   image with the same sizes of the target image ('1' inside the mask and
%   '0' outside the mask).
%Output:
%   targetImageWithBlendedPatch  - Target image with the blended pixels (masked area solved
%   by Poisson equations)

TargImPasteR = target_image_with_gradient_patch(:, :, 1);
TargImPasteG = target_image_with_gradient_patch(:, :, 2);
TargImPasteB = target_image_with_gradient_patch(:, :, 3);

% if there are 1752 pixels in the mask cutted from source image to
% target image then neighborsMatrix is a 1752x1752 matrix in which each
% column has at most 4 values of 1 (the rest are 0) which indicate the
% other neighbors of the pixel that are INSIDE the patch.
neighborsMatrix = buildNeighborsMatrix( MaskTarg );

TargBoundry  = bwboundaries( MaskTarg, 8);
boundary = TargBoundry{1};


TargFilledR = PoissonGrayImageBlending(TargImPasteR, MaskTarg, neighborsMatrix, boundary);
TargFilledG = PoissonGrayImageBlending(TargImPasteG, MaskTarg, neighborsMatrix, boundary);
TargFilledB = PoissonGrayImageBlending(TargImPasteB, MaskTarg, neighborsMatrix, boundary);

targetImageWithBlendedPatch = cat(3, TargFilledR, TargFilledG, TargFilledB);