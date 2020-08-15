clear;
close all;
clc;

% delta = 1;
% x = -100:delta:100;
% 
% mean = 10;
% variance = 20;
% sqr_variance = variance^2;
% 
% coeff = 1/sqrt(2*pi*sqr_variance);
% x_minus_mean = x-mean;
% sqr_x_minus_mean = x_minus_mean.^2;
% e_power = -sqr_x_minus_mean/(2*sqr_variance);
% y = coeff*exp(e_power);
% 
% plot(x,y, 'LineWidth', 2);




nbins=1000;
n = 10^6;
x = randn(n,1);
sort_x = sort(x);
[counts,centers] = hist(x, nbins);


mean_val = 0;
std_val = 1;



% figure;
% x1 = rand(n,1);
% hist(x1, nbins);

mean_x = mean(x)
std_x = std(x)
std_x1 = sqrt(sum((x-mean_x).^2)/n)
min_x = min(x)
max_x = max(x)

new_x = x;
for i=1:n
    current_x = new_x(i);
    left_limit = mean_val-std_val;
    right_limit = mean_val+std_val;
    if (current_x < left_limit)
        nominator = abs(current_x - left_limit);
        denominator = abs(min_x-left_limit);
        factor = nominator/denominator;
        new_current_x = left_limit + factor * std_val;
        new_x(i) = new_current_x;
    elseif (current_x > right_limit)
        nominator = abs(current_x - right_limit);
        denominator = abs(max_x-right_limit);
        factor = nominator/denominator;
        new_current_x = right_limit - factor * std_val;
        new_x(i) = new_current_x;       
    end
end



% new_x = x;
% for i=1:n
%     current_x = new_x(i);
%     left_limit = mean_val-std_val;
%     right_limit = mean_val+std_val;
%     if (current_x < left_limit)
%         j=0;
%         sub_sum=0;
%         while (new_x(j)<current_x)
%             sub_sum = sub_sum + new_x(j);
%         end
%         new_x(A<9 & A>2)
%         
%         new_x(i) = new_current_x;
%     elseif (current_x > right_limit)
% 
%         new_x(i) = new_current_x;       
%     end
% end

figure('units','normalized','outerposition',[0 0 1 1]);
subplot(1,2,1);
hist(x, nbins);
grid on;
hold on;
x_vals = [min(x), max(x)];
max_counts = max(counts);
y_vals = [0 max_counts];
x_vals1 = [mean_val,mean_val];
plot(x_vals1,y_vals,'LineWidth',2);

x_vals2 = [mean_val+std_val,mean_val+std_val];
plot(x_vals2,y_vals,'LineWidth',2);

x_vals3 = [mean_val-std_val,mean_val-std_val];
plot(x_vals3,y_vals,'LineWidth',2);


subplot(1,2,2);
hist(new_x, nbins);
grid on;


