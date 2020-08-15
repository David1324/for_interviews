function [MaskTargLogical, target_image_with_gradient_source_patch, TargImPaste_Source] = paste_source_into_targ(SourceIm, TargIm, SourceMaskLogical, shift_in_target_image)
%This function first calculates the gradient of the source image and then
%pastes the part of the image that is in the mask into the target image.
%input parameters:
%   SourceIm - the RGB source image.
%   TargIm - the RGB target image.
%   SourceMaskLogical - the mask image from the source image. this image is
%   logical ('1' inside the mask and '0' outside the mask).
%   shift_in_target_image - the location the user chose with the mouse in
%   the target image (for pasting the mask)
%output parameters:
%   MaskTargLogical - The recalculated mask to be used from now on. this is a
%   logical image (the same sizes as the target image) where '1' is inside
%   the recalculated mask and '0' is outside the recalculated mask.
%   target_image_with_gradient_source_patch - the target image
%   (only the part inside the masking (the part that was copied from the
%   source image) is the gradient of the image). the rest of the target
%   image in unchanged.
%   TargImPaste_Source - this parameter can be deleted and not used. it can
%   be used for checking. this is the real patch of the source image pasted
%   into the target image (no gradeint is calculated here). for the
%   blending calculatios we need to use the gradeint of the source image.


%Moved mask in Targ Image
[TargImRows, TargImCols, ~] = size(TargIm);
MaskTargLogical = calc_mask_in_targ_image(SourceMaskLogical, TargImRows, TargImCols, shift_in_target_image);


%% Pasting gradient of source into target image
%to see the image (red for example): figure; imshow(uint8(TargIm_R))
TargIm_R = double(TargIm(:, :, 1));
TargIm_G = double(TargIm(:, :, 2));
TargIm_B = double(TargIm(:, :, 3));

%Calulating the gradient of the image.
%h is the mask 3x3 matrix used for calculating the gradient. by
%multiplying all the pixels with this mask we're actually calculating the
%difference of every pixel with its 4-connected neighbors
h = [0 -1 0; -1 4 -1; 0 -1 0];
gradientSource = imfilter(double(SourceIm), h, 'replicate');
%to see the gradient image use: figure; imshow(uint8(gradientSource))
gradientSource_R = gradientSource(:, :, 1);
gradientSource_G = gradientSource(:, :, 2);
gradientSource_B = gradientSource(:, :, 3);


%only the part inside the masking (the part that was copied from the source
%image) is the gradient image. the rest of the image (the target image) is
%still the same.
TargIm_R(MaskTargLogical(:)) = gradientSource_R(SourceMaskLogical(:));
TargIm_G(MaskTargLogical(:)) = gradientSource_G(SourceMaskLogical(:));
TargIm_B(MaskTargLogical(:)) = gradientSource_B(SourceMaskLogical(:));

target_image_with_gradient_source_patch = cat(3, TargIm_R, TargIm_G, TargIm_B);



%The following code is not necessary (can be deleted from the function
%together with the output parameter TargImPaste_Source). it is used just to
%show the actual image pasted on the target image (and not the gradient).
%for the blending calculations only the gradient patch is used
TargImPasteR_Source = double(TargIm(:, :, 1));
TargImPasteG_Source = double(TargIm(:, :, 2));
TargImPasteB_Source = double(TargIm(:, :, 3));

%the real patch from the source image
VR_Source = SourceIm(:, :, 1);
VG_Source = SourceIm(:, :, 2);
VB_Source = SourceIm(:, :, 3);

TargImPasteR_Source(MaskTargLogical(:)) = VR_Source(SourceMaskLogical(:));
TargImPasteG_Source(MaskTargLogical(:)) = VG_Source(SourceMaskLogical(:));
TargImPasteB_Source(MaskTargLogical(:)) = VB_Source(SourceMaskLogical(:));

TargImPaste_Source = cat(3, TargImPasteR_Source, TargImPasteG_Source, TargImPasteB_Source);
