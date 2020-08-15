function blendMaskWithTargetImage(SourceIm, SourceMask, TargIm)
% This function blends the mask from source image into the target image.
% input parameters:
%   SourceIm - The source RGB image the mask was selected from
%   SourceMask - A logical matrix indicating the mask ('1' inside the mask
%   and '0' outside the mask)
%   TargIm - The target RGB image to paste the mask in


    %adding a button for the user to surround the object automatically in
    %case the mask the user defined was not accurate enough.
    uicontrol('Style', 'pushbutton', 'String', 'Use active contour',...
    'Position', [10 10 120 40],'Callback', @use_active_contour);

    %adding a button for the user to move to the target image (he should
    %click it only after the mask is complete and he's ready to paste)
    uicontrol('Style', 'pushbutton', 'String', 'Move to target image',...
    'Position', [150 10 120 40],'Callback', @move_to_target_image);
 
    old_hpolyCountour = 0;
    hpolyCountour = 0;
    active_contour_used = false;
 
    function use_active_contour(source,callbackdata)
    %this function is called when the user clicks on the 'Use active
    %contour' button. in this case the mask surrounding the object will try
    %to segment the object more accurately (the user can always manually
    %change the mask in case the contour was not accurate enough)

        active_contour_used = true;
        if (old_hpolyCountour ~= 0)
            %we call here to createMask in case the user decided
            %to change the mask with the mouse. so we want the mask to be
            %updated           
            BW_contour = createMask(old_hpolyCountour);
            SourceMask = BW_contour;          
            
            %we delete the impoly mask since it is not relevant anymore.
            %there will be a different impoly that should surround the
            %object more accuratly.
            delete(old_hpolyCountour);
            
            %here we draw the old mask in red
            [SrcBoundry, ~] = bwboundaries(SourceMask, 8);
            for k = 1:length(SrcBoundry)
                boundary = SrcBoundry{k};
                plot(boundary(:,2), boundary(:,1), 'r', 'LineWidth', 2)
            end
        end
        
        %here we call the acitvecontour so that the mask should surround
        %the object more accurately
        SourceImGrayScale = rgb2gray(SourceIm);
        bw = activecontour(SourceImGrayScale, SourceMask, 100, 'edge');
        B2 = bwboundaries(bw,8,'noholes');
        t=length(B2);
        tol=6;

        for k = 1:t
            boundary = B2{k};
            %dpsimplify is a function that I dowloaded from the link:
            %http://www.mathworks.com/matlabcentral/fileexchange/21132-line-simplification/content/dpsimplify.m
            %this function simplies the mask so that it will be a polygon
            %with less edges (so the user can easily change the polygon
            %manually with the mouse if he wants)
            simplify_poly = dpsimplify(boundary,tol);
            simplify_poly1 = [simplify_poly(:,2) simplify_poly(:,1)];
            hpolyCountour = impoly(gca , simplify_poly1);
            BW_contour = createMask(hpolyCountour);
            SourceMask = BW_contour;
        end
    
        old_hpolyCountour = hpolyCountour;
    end %end of function use_active_contour



    function move_to_target_image(source,callbackdata)
    %this function is an event that is called when the user clicks on the
    %button 'Move to target image'. he can do it after he made sure that
    %the mask he marked looks ok.
    
    
        if (active_contour_used == true)
            BW_contour = createMask(hpolyCountour);
            SourceMask = BW_contour;
        end
    
        originalTargIm = TargIm;
        old_shift_in_target_image = [0 0];
        figure;
        %this is an "infinity" loop (until a break command is called) in which
        %the user can click over and over with the left click of the mouse
        %where to paste the masking from the source image (and each time he can
        %see the pasting in his left click location) until he's satisfied with
        %the location and then he clicks the right click of the mouse to
        %determine the final location to do the blending calculations.
        while(1)

            [shift_in_target_image, button] = getUserTargetLocation(TargIm);
            if (button==3) %right button
                shift_in_target_image = old_shift_in_target_image;
                break;
            end
            TargIm = originalTargIm;
            old_shift_in_target_image = shift_in_target_image;

            [TargImRows, TargImCols, ~] = size(TargIm);
            MaskTargLogical = calc_mask_in_targ_image(SourceMask, TargImRows, TargImCols, shift_in_target_image);

            TargImPasteR_Source = uint8(TargIm(:, :, 1));
            TargImPasteG_Source = uint8(TargIm(:, :, 2));
            TargImPasteB_Source = uint8(TargIm(:, :, 3));

            %the real patch from the source image
            VR_Source = SourceIm(:, :, 1);
            VG_Source = SourceIm(:, :, 2);
            VB_Source = SourceIm(:, :, 3);

            %the following 3 lines actually "paste" the actual part of the
            %image inside the mask in source image into the location the user
            %clicked in the target image.
            %it is done separatelly on R, G, and B images and eventually
            %concatenated to a single RGB image.
            %the pasting is done like a regular copy-paste (the actual part of
            %the source image is pasted) . no blending calculations are done
            %here.
            TargImPasteR_Source(MaskTargLogical(:)) = VR_Source(SourceMask(:));
            TargImPasteG_Source(MaskTargLogical(:)) = VG_Source(SourceMask(:));
            TargImPasteB_Source(MaskTargLogical(:)) = VB_Source(SourceMask(:));

            TargImPaste_Source = cat(3, TargImPasteR_Source, TargImPasteG_Source, TargImPasteB_Source);

            %imagesc(uint8(TargImPaste_Source)), axis image, title('Target image with patch of the source image inserted');
            %imshow(TargImPaste_Source);
            TargIm=TargImPaste_Source;
        end %end of while(1)

        %% paste gradeint of source into Target image
        [MaskTarg, target_image_with_gradient_source_patch, TargImPaste_Source] = paste_source_into_targ(SourceIm, TargIm, SourceMask, shift_in_target_image);
    % 	figure, imagesc(uint8(TargImPaste_Source)), axis image, title('Target image with patch of the source image inserted');
    % 	figure, imagesc(uint8(target_image_with_gradient_source_patch)), axis image, title('Target image with gradient of source inserted');

        %% Solve POisson equations in target image wihtihn masked area
        TargFilled = PoissonColorImageBlending(target_image_with_gradient_source_patch, MaskTarg);

        %% Show the results
        figure;
        imshow(uint8(TargFilled));
    end %end of function move_to_target_image
end	
