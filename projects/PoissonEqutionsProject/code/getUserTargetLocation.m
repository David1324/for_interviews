function [targetLocation, button] = getUserTargetLocation(targetImg)
	% This function is called when the user clicks on the target image to
	% decide where to paste the patch copied from the source image.
    % input parameter:
    %   targetImg - the target image (RGB image) the user clicks on with
    %   the mouse
    % output parameters:
    %   targetLocation - the location (x,y) the user clicked
    %   button - this is a number indicating which button the user clicked.
    %   the button options: 1 for left click, 2 for middle click, and 3 for
    %   right click
    imshow(targetImg);
	[x, y , button] = ginput(1);
	targetLocation = [x, y];    
end

