close all;

barbara = readImage('barbarasmall.tif');
lena = readImage('lena.tif');

%%%%%%%%%%%%%%%%%%%% a %%%%%%%%%%%%%%%%%%%%

barbaraSP = addSPnoise(barbara,0.03);
lenaSP = addSPnoise(lena,0.03);

showImage(barbaraSP);
showImage(lenaSP);
pause;
close all;

lenaNLM1 = nlMeans(lenaSP,5,100,5,1,20);
showImage(lenaNLM1);
disp('option 1');
tmp = lenaSP-lenaNLM1;
disp(sum(tmp(:)));
pause;
close all;

lenaNLM2 = nlMeans(lenaSP,5,100,5,2,1000);
showImage(lenaNLM2);
disp('option 2');
tmp = lenaSP-lenaNLM2;
disp(sum(tmp(:)));
pause;
close all;

lenaNLM3 = nlMeans(lenaSP,5,100,5,3,0);
showImage(lenaNLM3);
disp('option 3');
tmp = lenaSP-lenaNLM3;
disp(sum(tmp(:)));
pause;
close all;

%%%%%%%%%%%%%%%%%%%% b %%%%%%%%%%%%%%%%%%%%



