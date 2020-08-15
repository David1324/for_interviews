function neighborsMatrix = buildNeighborsMatrix( maskMatrix )
% This function builds the neighbors matrix in the following way:
% If there are N pixels in the mask cutted from source image to
% target image then neighborsMatrix is an NxN matrix in which each
% column has at most 4 values of 1 (the rest are 0) which indicates the
% other neighbors of the pixel that are INSIDE the patch. we use here
% 4-conn neighbors that's why there are at mose 4 1's in a column.
% input parameter:
%   maskMatrix - A binary mask matrix for building the neighbors matrix ('1'
%   inside the mask and '0' outside the mask)
%Output:
%   neighbors - if N is the number of pixels in the mask the neighbors is
%   an NxN matrix as explained above.

%defining a constant
NUM_OF_NEIGHBORS = 4;

[height, width]      = size(maskMatrix);
[row_mask, col_mask] = find(maskMatrix);

% neighborsMatrix is initialized to sparsed zeros matrix.
% We use 'sparse' command and not 'zeros' command so we can use large sizes
% of maskes (zeros command won't work for too big matrixes).
neighborsMatrix = sparse(length(row_mask), length(row_mask));

% Convert to indexes
mask_indexes_in_linear_column = sub2ind([height, width], row_mask, col_mask);

for k = 1:size(row_mask, 1),
    %4 connected neighborhood
    connected_4 = [row_mask(k), col_mask(k)-1;%left
                   row_mask(k), col_mask(k)+1;%right
                   row_mask(k)-1, col_mask(k);%top
                   row_mask(k)+1, col_mask(k)];%bottom


    ind_neighbors = sub2ind([height, width], min(connected_4(:, 1),height), min(connected_4(:, 2),width));
    
    for neighbor_idx = 1:NUM_OF_NEIGHBORS,
        %the find command can also be replaced with binary search (user
        %defined function) since the mask_indexes_in_linear_column is
        %sorted. it is likely to be faster using the binary search (O(logn)
        %instead of O(n)).
        currentNeibourValue = ind_neighbors(neighbor_idx);
        neighbor_pixel_index = mask_indexes_in_linear_column==currentNeibourValue;
        %here we fill the neghborsMatrix in '1' in case there's a 4-conn
        %neighbor INSIDE the patch. note that if neighbor_pixel_index is a
        %column of zeros, the following command does nothing.
        neighborsMatrix(k, neighbor_pixel_index) = 1;
    end 
end

%try
% b=neighbors(:); x=unique(b); y = zeros(size(x)); for i = 1:length(x) y(i) = sum(b==x(i)); end; [double(x) y]

end
