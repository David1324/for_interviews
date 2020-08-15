%given n coordinates, find if the points are clockwise or counter-clockwise

clear;
close all;
clc;

points =    [4 5 0;
            6 8 0;
            5 2 0];
        
num_of_points = size(points,1);

angles = zeros(1,num_of_points);

for i=1:num_of_points
   index1 = i;
   index2 = mod(i+1,num_of_points);
   if index2==0 
       index2=3;
   end
   index3 = mod(i+2,num_of_points);
   if index3==0 
       index3=3;
   end
   point1 = points(index1 , :); 
   point2 = points(index2 , :);
   point3 = points(index3 , :);
   vec1 = point2-point1;
   vec2 = point3-point1;
   unit_vec1 = vec1/norm(vec1);
   unit_vec2 = vec2/norm(vec2);
   vec3 = cross(unit_vec1, unit_vec2);
   norm_vec3_with_sign = vec3(3);
   current_angle = asind(norm_vec3_with_sign);
   angles(i) = current_angle;
end

abs_angles = abs(angles)
sum_abs_angles = sum(abs_angles)

% angles
% sum_angles = sum(angles)

points_x = points(: , 1);
points_y = points(: , 2);

points_x_full = [points_x ; points_x(1)];
points_y_full = [points_y ; points_y(1)];

plot(points_x_full, points_y_full);
hold on;
scatter(points_x_full,points_y_full);
grid on;
axis equal;