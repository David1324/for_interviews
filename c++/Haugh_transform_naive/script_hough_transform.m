clear;
close all;
clc;

rows = 40;
cols = 40;
img = zeros(rows,cols);
for i=1:min(rows,cols)
   img(i,cols-i+1)=255; 
end
figure;
imshow(img);

dtheta = 15;
[theta, map] = my_hough(img, dtheta);
theta
