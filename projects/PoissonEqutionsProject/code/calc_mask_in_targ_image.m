function MaskTarg = calc_mask_in_targ_image(sourceMask, targImRows, targImCols, shift_in_target_image)
%This function calculates the mask image in the target image.
%It is actually needed only in cases the user clicked too close to the
%edges so that not all the mask can be seen. in this case this function
%recalculates the mask so that the whole mask can be seen.
%input parameters:
%   sourceMask - the mask image. this is a logical image. '1' inside the
%   mask and '0' outside the mask.
%   targImRows - number or rows in the target image.
%   targImCols - number or columns in the target image.
%   shift_in_target_image - The (x,y) location the user clicked to paste
%   the mask. note that this location is not necessarily the location the
%   mask will pe pasted. in case it is too close to the edges so that not
%   all the mask is seen, this location will be moved until the whole mask
%   can be seen.
%Output parameter:
%   MaskTarg - The recalculated mask to be used from now on. this is a
%   logical image (the same sizes as the target image) where '1' is inside
%   the recalculated mask and '0' is outside the recalculated mask.

[row, col] = find(sourceMask);

%clalc bounding box of mask in source image
start_bb = [min(col), min(row)];
end_bb   = [max(col), max(row)];
bb_size  = end_bb - start_bb;
%bb_size contains the width and the height of the bounding box that
%contains the masking.

%neighbors_rows and neighbors_cols are the minimum space in rows and
%columns from the mask to the target image edges.
% if their values are 0, then the mask will touch the image edges (only
% in case the user clicked too close to them)
% the minimum value allowed here is 1 (for both rows and cols) because in
% the blending calculations there should be at least 1 extra pixel to use
% for the calculations.
neighbors_rows = 1;
neighbors_cols = 1;

%if the mask is too big to place where the user clicked for pasting, then
%the position should be moved so that the whole mask will be fitted in the
%target image
if (bb_size(1) + shift_in_target_image(1) > targImCols)
    shift_in_target_image(1) = targImCols - bb_size(1) - neighbors_cols;
end

if (bb_size(2) + shift_in_target_image(2) > targImRows)
    shift_in_target_image(2) = targImRows - bb_size(2) - neighbors_rows;
end

%relocating source mask to mask in targ image 
%The following code is used to recalculate the mask in case the user
%clicked on the pasting location too close to one or more of the edges so
%that not all the mask can be seen. in this case the mask is moved so that
%the whole mask can be seen and in this case the mask image need to be
%recalculated.
MaskTarg = zeros(targImRows, targImCols);
par1 = [targImRows, targImCols];
par2 = row - start_bb(2) + shift_in_target_image(2);
par3 = col - start_bb(1) + shift_in_target_image(1);
indexes = sub2ind(par1, par2, par3);
indexes_int = uint32(indexes);
MaskTarg(indexes_int) = 1;
MaskTarg = logical(MaskTarg);
% try the command:
% b=MaskTarg(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
% if the marking of the area is pasted in a place where all the marking can
% be seen, then MaskTarg is the same as the parameter SourceMask but on the
% location the user chose to paste the masking in the target image.
% try also 
% figure; spy(MaskTarg);
% or
% figure; imshow(MaskTarg);
end