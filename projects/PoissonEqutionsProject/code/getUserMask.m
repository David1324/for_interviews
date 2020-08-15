function [sourceImage, mask] = getUserMask(sourceImagePath)
%Input:
%   sourceImagePath - path of the image to mark the mask with roipoly
%Output:
%   sourceImage - RGB matrix image (meaning 3*M*N for M*N image) of the source image in the input path
%   mask - logical matrix in which the values '1' are inside the mask
%   the user marked, and the values '0' are outside the mask the user
%   marked.
	sourceImage = imread(sourceImagePath);
    %roipoly is used for the user to mark the mask he wants to
    %copy-paste to the destination image
    mask = roipoly(sourceImage);
    
    %here we draw the above mask in red lines
    axis image
    hold on
    [SrcBoundry, ~] = bwboundaries(mask, 8);
    for k = 1:length(SrcBoundry)
        boundary = SrcBoundry{k};
        plot(boundary(:,2), boundary(:,1), 'r', 'LineWidth', 2)
    end
end