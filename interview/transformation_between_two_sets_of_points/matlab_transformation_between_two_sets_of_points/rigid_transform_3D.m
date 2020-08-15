% This function finds the optimal Rigid/Euclidean transform in 3D space
% It expects as input a Nx3 matrix of 3D points.
% It returns R, t

% expects row data
function [R,t] = rigid_transform_3D(setPoints_A, setPoints_B)
    if nargin ~= 2
	    error('Missing parameters');
    end

    centroid_A = mean(setPoints_A);
    centroid_B = mean(setPoints_B);

    num_points = size(setPoints_A,1);
    centroid_A_repeated = repmat(centroid_A, num_points, 1);
    centroid_B_repeated = repmat(centroid_B, num_points, 1);
    diff_B = setPoints_B - centroid_B_repeated;
    diff_A = setPoints_A-centroid_A_repeated;
    diff_A_transpose = diff_A';

    H = diff_A_transpose * diff_B;

%     [U,S,V] = svd(H);
    [U,S,V] = svdsim(H);

    R = V*U';
    
    diff_USV_H = H - U*S*V';
    
    max_diff = max(max(abs(diff_USV_H)));

    if det(R) < 0
        printf('Reflection detected\n');
        V(:,3) = -V(:,3);
        R = V*U';
    end

    t = -R*centroid_A' + centroid_B';
end


