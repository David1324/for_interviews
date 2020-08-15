function target_grayscale_image_blended = PoissonGrayImageBlending(target_image_with_gradient_patch, MaskTarg, neighborsMatrix, boundary)
% This function is the heart of the the project. here we actually do the
% poisson calculations for blending the patch in the target image.
% input parameters:
%   target_image_with_gradient_patch - Target image with the gradient of
%   source image within the masked area
%   neighborsMatrix - neighbors matrix that is explained in the following
%   way:
%   If there are N pixels in the mask cutted from source image to
%   target image then neighborsMatrix is an NxN matrix in which each
%   column has at most 4 values of 1 (the rest are 0) which indicates the
%   other neighbors of the pixel that are INSIDE the patch. we use here
%   4-conn neighbors that's why there are at mose 4 1's in a column.
%   boundary - a matrix with 2 columns containing the (x,y) coordinates of
%   the pixels around the mask (the boundary of the mask) that the user
%   marked.
%output:
%   target_grayscale_image_blended - the grayscale target image with the
%   blended patch in it

%% parameters for the cgs command in order to solve the equations
max_iter = 400;
tolerance = 1e-7;

% b=MaskTarg(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
% use also figure; 
% figure; spy(MaskTarg);
[row_mask, col_mask] = find(MaskTarg);
%boundary = TargBoundry{1};

%number_of_neighbors_outside_the_patch is a column vector in which its
%length is the number of pixels in the boundary.
%its meaning:
%assume for example that number_of_neighbors_outside_the_patch(4)=2 then it
%means that the 4th pixel of the boundary has 2 neighbors pixels (4-conn
%neighbors) that are outsize the patch (the pixels are part of the target
%image but not part of the patch)
number_of_neighbors_outside_the_patch  = zeros(size(boundary, 1), 1);
%sum_of_neighbors_outside_the_patch is a column vector in which its length
%is the number of pixels in the boundary.
%its meaning:
%assume for example that sum_of_neighbors_outside_the_patch(4)=380 and also
%assume as before that number_of_neighbors_outside_the_patch(4)=2 then it
%means that the 4th pixel in the boundary has 2 neighbors pixels that are
%outside the patch the their sum are 380 (for example 2 pixels of grayscale
%values 200 and 140).
sum_of_neighbors_outside_the_patch = zeros(size(boundary, 1), 1);
for k = 1:size(boundary, 1),
    %Calc Neighbour outside - at most 4 but unlikely - usually 1 for 4
    %connected
    [xy_pos] = boundary(k, :);
    
    neighbors_inside_binary_mask_in_3x3_square = MaskTarg(xy_pos(1)-1:xy_pos(1)+1, xy_pos(2)-1:xy_pos(2)+1);
    neighbors_outside_binary_mask_in_3x3_square = ~neighbors_inside_binary_mask_in_3x3_square;
    neighbors_outside_binary_mask_in_3x3_square_in_4_directions = neighbors_outside_binary_mask_in_3x3_square & [0 1 0;1 1 1; 0 1 0];    
    %number_of_neighbors_outside_the_patch(k) count the num of pixels around (xy_pos(1), xy_pos(2)) in 4
    %directions. should always be between 1 to 3. not 0 to 4 because there
    %should always be pixels inside and outside the patch around the point
    %(xy_pos(1) xy_pos(2)) since the point is in the boundary
    % try
    % b=number_of_neighbors_outside_the_patch(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
    number_of_neighbors_outside_the_patch(k) = sum(sum(neighbors_outside_binary_mask_in_3x3_square_in_4_directions));
    
    
    k_neighborhood = target_image_with_gradient_patch(xy_pos(1)-1:xy_pos(1)+1, xy_pos(2)-1:xy_pos(2)+1);
     
    % try
    % b=sum_of_neighbors_outside_the_patch(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]    
    sum_of_neighbors_outside_the_patch(k) = sum(k_neighborhood(neighbors_outside_binary_mask_in_3x3_square_in_4_directions));
end

%can be also col_mask instead of row_mask. it doesn't matter. gives the same result.
num_of_pixels_in_mask = size(row_mask, 1); 


A = [row_mask, col_mask];
B = boundary;
% Determine which rows of A are also in B as well as their corresponding locations in B.
% boundary_list_idx is the indexes to (x,y) row in B (and 0 for all pixels that
% are not in B, meaning they are the interior of the mask and not in the
% outline)
% boundary_and_interior_list_idx is a single column with N elements in which N is the
% number of pixels in the mask.
% if boundary_and_interior_list_idx(k)=0 then the corresponding pixel is in the interior
% mask (not on the boundary).
% if for example boundary_and_interior_list_idx(3)=28 then it means that A(3,:)=B(28,:).
% meaning that the (x,y) coordinate A(3,:) is in the boundray and it can be
% found in B(28,:).
% B is only the boundary coordinates of the mask.
% A is all the coordinates in the boundary and also in the interrior of the
% mask.
% is_boundary is 1 in all indexes that on the boundary and 0 in all indexes
% that are in the interior of the mask (not on the boundary).
% if is_boundary(k)=0 then boundary_list_idx(k)=0
% try
% b=is_boundary(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
% and
% b=boundary_list_idx(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
[is_boundary, boundary_and_interior_list_idx] = ismember(A, B, 'rows');

% try
% c=full(A1_sparse); b=c(:) ; x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
sparse_4_in_diagonal = spdiags(ones(num_of_pixels_in_mask, 1)*4,0,num_of_pixels_in_mask,num_of_pixels_in_mask);
%A1_sparse = sparse(diag(ones(1, num_of_hole_pixels)*4));


sparse_neighborsMatrix = sparse(neighborsMatrix);
%A_sparse is the sparse matrix that will be used for solving the poisson
%equations.
A_sparse = sparse_4_in_diagonal - sparse_neighborsMatrix;

indexes_of_the_mask_and_inside_in_targ_image = sub2ind(size(target_image_with_gradient_patch), row_mask, col_mask);


%mask_pixels contains all the pixels values in the mask (boundary+interior)
mask_pixels = target_image_with_gradient_patch(indexes_of_the_mask_and_inside_in_targ_image);
%list_boundary_only should contain only the indexes of
%the coordinates that are in the boundary of the mask (not the indexes of
%the coordinates that are in the interior of the mask)
list_boundary_only = boundary_and_interior_list_idx;
list_boundary_only(list_boundary_only==0) = [];%remove zero entries


sum_of_neighbors_outside_the_mask = sum_of_neighbors_outside_the_patch(list_boundary_only);
pixels_values_on_the_boundary_only = mask_pixels(is_boundary);
poisson_values = pixels_values_on_the_boundary_only + sum_of_neighbors_outside_the_mask;
%b is the vector used for the poisson equations
b = mask_pixels;
b(is_boundary) = poisson_values;

%Starting point
% b=average_boundary_vector(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
average_boundary_vector = sum_of_neighbors_outside_the_patch./number_of_neighbors_outside_the_patch;
mean_value = mean(average_boundary_vector);
column_ones = ones(num_of_pixels_in_mask, 1);
column_mean = mean_value*column_ones;
%Solve using conjagant gradient descent
%A2_sparse = sparse(A2);
X = cgs(A_sparse, b, tolerance, max_iter, [], [], column_mean);

X_non_negative = max(X, 0);
target_image_rows_and_cols = size(target_image_with_gradient_patch);
target_image_indexes = sub2ind(target_image_rows_and_cols, row_mask, col_mask);

target_grayscale_image_blended = target_image_with_gradient_patch;
%fill in mask with result, clipp with zero from below to prevent small
%negative numbers

% b=X_non_negative(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]
target_grayscale_image_blended(target_image_indexes) = X_non_negative;

end

