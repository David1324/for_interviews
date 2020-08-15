function [theta, map] = my_hough(image, dtheta)
    % angle map
    theta = 0 : dtheta : 180;
    N = length(theta);

    % coordinates of edge points
    [y, x] = find(image);
    P = length(x);

    % sine, cosine map
    s = sind(theta);
    c = cosd(theta);

    % the shifting value to get positive r values
    [h, w] = size(image);
    d = norm([h, w]) + 1;

    % get all r values
    points = [x,y];
    A = [s;c];
    PA = points*A;
    rho_float = PA+d;
    rho = floor(rho_float);

    % create the two dimensional histogram
    P1 = [P,1];
    n_series = 1:N;
    repma_s_P1 = repmat(n_series, P1);
    sparse_map = sparse(rho, repma_s_P1, 1);
    map = full(sparse_map);
    max_val = max(map(:))
end