% this is the main class to run from
% In this class we define the source and target images to work on. When
% running this class, the source image appears in a window, the user then
% creates the mask by clicking as much clicks as he wants with the left
% click of the mouse. To close the mask the user clicks on the right click
% and then a line from the last point of the mask will be connected to the
% first point of the mask.  Then the user needs to put the mouse inside the
% mask and click the right click and choose "Create Mask". If the mask that
% the user drew is not accurate enough (not exactly surrounding the object)
% the user can click on the button “Use active contour” to make a new mask
% inside the mask he drew that will surround the object better. He can
% click on this better as many times as he want until he’s satisfied with
% the mask. The user can always manually fix the mask. 
% After the user finishes with the mask and he’s ready to paste it in the
% target image, he clicks on the button “Move to target image”. Then the
% target image appears and the user can choose with the left click of the
% mouse where to locate the patch. He can do it as many times as he wants
% and each time he'll see the patch in the different location he clicked
% (not blended yet). Only when the user is satisfied with the location he
% then clicks on the right click in order to do the blending equations. And
% this is it. After that the patch should be blended in the target image.

clc;
close all;

folder_name = 'images/';

option = 5;

switch option
    case 1
        [sourceImage, mask] = getUserMask(strcat(folder_name,'01_GreatWhiteShark.jpg')); 
        %tarImg is an RGB matrix image of the target image (the image in
        %which the mask should be pasted)
        tarImg = imread(strcat(folder_name,'01_beach.jpg'));        
    case 2
        [sourceImage, mask] = getUserMask(strcat(folder_name,'02_me_lookingright.jpg'));
        %tarImg is an RGB matrix image of the target image (the image in
        %which the mask should be pasted)
        tarImg = imread(strcat(folder_name,'02_harrypottercast.jpg'));
    case 3
        [sourceImage, mask] = getUserMask(strcat(folder_name,'03_bear.jpg'));
        %tarImg is an RGB matrix image of the target image (the image in
        %which the mask should be pasted)
        tarImg = imread(strcat(folder_name,'03_swimming.jpg'));   
    case 4
        [sourceImage, mask] = getUserMask(strcat(folder_name,'04_sun.jpg'));
        %tarImg is an RGB matrix image of the target image (the image in
        %which the mask should be pasted)
        tarImg = imread(strcat(folder_name,'04_OL.jpg')); 
    case 5
        [sourceImage, mask] = getUserMask(strcat(folder_name,'05_tatoo.jpg'));
        %tarImg is an RGB matrix image of the target image (the image in
        %which the mask should be pasted)
        tarImg = imread(strcat(folder_name,'05_bodybuilding.jpg'));
    case 7
        [sourceImage, mask] = getUserMask(strcat(folder_name,'07_couple.jpg'));
        %tarImg is an RGB matrix image of the target image (the image in
        %which the mask should be pasted)
        tarImg = imread(strcat(folder_name,'07_beautiful_view.jpg'));
end





blendMaskWithTargetImage(sourceImage, mask, tarImg);

