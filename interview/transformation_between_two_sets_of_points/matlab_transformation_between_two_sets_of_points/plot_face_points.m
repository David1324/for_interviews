function plot_face_points( face_points )

    num_points = size(face_points,1);
    %rand_rotation_matrix = rand(3,3);
    angle = 90;
    rotation_matrix = [cosd(angle) sind(angle) 0 ; -sind(angle) cosd(angle) 0 ; 0 0 1];

    %rotation_matrix = orth(rand_rotation_matrix); % random rotation matrix


    if det(rotation_matrix) < 0
        V(:,3) = -V(:,3);
        rotation_matrix = V*U';
    end

    %random_translation = rand(3,1); % random translation
    random_translation = [500;500;0];

    for i=1:num_points
       num_as_string = num2str(i, '%02i');
       values(i,:) = num_as_string; 
    end

    bool_show_numbers = 1;
    %bool_show_original_points = 1; %red
    bool_show_final_points = 1; %blue
    bool_show_estimated_points = 1; %greed
    
        % face_points = rand(num_points,3);
    face_points_transposed = face_points';

    rotaion_result = rotation_matrix*face_points_transposed;
    translation_result = repmat(random_translation, 1, num_points);

    rotate_and_translate = rotaion_result + translation_result;
    rotate_and_translate_transposed = rotate_and_translate';

    min_value = -30;
    max_value = 30;
    intentional_error = min_value + (max_value-min_value)*rand(num_points,3);
    intentional_error(:,3) = zeros(num_points,1);
    rotate_and_translate_transposed = rotate_and_translate_transposed + intentional_error;

    figure('position',[100 100 1000 500]);
    uicontrol('Style', 'pushbutton', 'String', 'Show/hide face numbers',...
    'Position', [10 10 200 40],'Callback', @show_numbers);

    uicontrol('Style', 'pushbutton', 'String', 'Show/hide final (blue) points',...
    'Position', [250 10 200 40],'Callback', @show_final_points);

    uicontrol('Style', 'pushbutton', 'String', 'Show/hide estimated (green) points',...
    'Position', [500 10 200 40],'Callback', @show_estimated_points);

    function show_numbers(source,callbackdata)
        bool_show_numbers = 1-bool_show_numbers;
        hold off;
        plot_points;
    end

    function show_final_points(source,callbackdata)
        bool_show_final_points = 1-bool_show_final_points;
        hold off;
        plot_points;
    end

    function show_estimated_points(source,callbackdata)
        bool_show_estimated_points = 1-bool_show_estimated_points;
        hold off;
        plot_points;
    end

    plot_points;
    
    function plot_points()
        plot(face_points(:,1) , face_points(:,2), 'r.', 'MarkerSize', 20);
        axis equal;

        hold on;
        if (bool_show_numbers==1)
            text(face_points(:,1),25+face_points(:,2),values,'HorizontalAlignment','center','color','r','Fontsize',8,'FontWeight','bold');
        end

        if (bool_show_final_points==1)
            plot(rotate_and_translate_transposed(:,1) , rotate_and_translate_transposed(:,2), 'b.', 'MarkerSize', 20);       
            if (bool_show_numbers==1)
                text(rotate_and_translate_transposed(:,1),25+rotate_and_translate_transposed(:,2),values,'HorizontalAlignment','center','color','b','Fontsize',8,'FontWeight','bold');
            end
        end
        [ret_R, ret_t] = rigid_transform_3D(face_points, rotate_and_translate_transposed);

        A2 = (ret_R*face_points') + repmat(ret_t, 1, num_points);
        A2 = A2';

        if (bool_show_estimated_points==1)
            plot(A2(:,1) , A2(:,2), 'g.', 'MarkerSize', 20);       
            if (bool_show_numbers==1)
                text(A2(:,1),25+A2(:,2),values,'HorizontalAlignment','center','color','g','Fontsize',8,'FontWeight','bold');
            end
        end

        % Find the error
        err = A2 - rotate_and_translate_transposed;
        square_error = err .* err;
        sum_square_errors = sum(square_error(:));
        rmse = sqrt(sum_square_errors/num_points);

        %disp(sprintf('RMSE: %f', rmse));
        fprintf('RMSE: %f\n', rmse);
        disp('If RMSE is near zero, the function is correct!');       
    end


end

