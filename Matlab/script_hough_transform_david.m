clear;
close all;
clc;

x1 = 6;
y1 = 8;

x2 = -9;
y2 = -2;

% syms x1 y1 x2 y2;

slope = (y2-y1)/(x2-x1);
y_intersect = (x2*y1 - x1*y2)/(x2-x1);



x0 = 0;
y0 = 0;
perpendicular_slope = (x1-x2)/(y2-y1);
%slope*perpendicular_slope = -1

syms x;
line = slope*x+y_intersect;
perpendicular_line = perpendicular_slope*x;
eq = line-perpendicular_line;
x_sol = solve(eq,x);
x_closest_to_origin = double(x_sol);
y_closest_to_origin = slope*x_closest_to_origin+y_intersect;

point_closest_to_origin = [x_closest_to_origin y_closest_to_origin];
distance_from_origin = norm(point_closest_to_origin)

% nominator = (y2-y1)*x0 - (x2-x1)*y0 + x2*y1 -y2*x1;
% denominator = sqrt((y2-y1)^2+(x2-x1)^2);
% distance_from_origin1 = nominator/denominator



figure;
plot([x1 x2], [y1 y2]);
grid on;


delta = 1;
theta_values = -90 : delta : 90;
r_values1 = x1*cosd(theta_values)+y1*sind(theta_values);
r_values2 = x2*cosd(theta_values)+y2*sind(theta_values);

figure;
plot(theta_values, r_values1);
hold on;
plot(theta_values, r_values2);
xlabel('theta');
ylabel('r');
grid on;

syms theta;
r1 = x1*cos(theta)+y1*sin(theta);
r2 = x2*cos(theta)+y2*sin(theta);
eq = r1-r2;
theta_sol = solve(eq,theta);
theta_rad = double(theta_sol);
theta_deg = rad2deg(theta_rad);
dist = x1*cosd(theta_deg)+y1*sind(theta_deg)
a=5;