function cleanIm = nlMeans( im,nSize,nSearch,std,option,K )
%NLMEANS Summary of this function goes here
%   Detailed explanation goes here

[rows,cols] = size(im);
halfSize = floor(nSize/2);
halfSearch = floor(nSearch/2);
cleanIm = im;
for i=halfSize+1:rows-halfSize
   for j=halfSize+1:cols-halfSize
       p = im(i-halfSize:i+halfSize, j-halfSize:j+halfSize);
       y1 = i-halfSearch;
       if y1<1
           y1=1;
       end
       y2 = i+halfSearch;
       if y2>rows
           y2 = rows;
       end
       x1 = j-halfSearch;
       if x1<1
           x1=1;
       end
       x2 = j+halfSearch;
       if x2>cols
           x2 = cols;
       end
       piece = im(y1:y2, x1:x2);
       if nSearch==0
           piece = im;
       end
       distMap = creatDistMap(p,piece);
       weights = exp((-(distMap.^2))/std);
       
       
       switch option
           case 1
               
               sorted = sort(distMap(:));
               Kth = sorted(K);
               weights(distMap>=Kth)=0;          

           case 2
               
               weights(distMap>=K)=0;       
       
       end
       tmp = weights.*double(piece);
       cleanIm(i,j) = sum(tmp(:))/sum(weights(:));
               
       
   end
end

end

