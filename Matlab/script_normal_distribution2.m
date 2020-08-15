clear;
close all;
clc;

delta = 1;
x = 1:delta:10^6;

mean = 0.5*10^6;
variance = 200000;
sqr_variance = variance^2;

coeff = 1/sqrt(2*pi*sqr_variance);
x_minus_mean = x-mean;
sqr_x_minus_mean = x_minus_mean.^2;
e_power = -sqr_x_minus_mean/(2*sqr_variance);
y = coeff*exp(e_power);

plot(x,y, 'LineWidth', 2);
grid on;