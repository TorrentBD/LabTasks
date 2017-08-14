im =imread('rgb.png');

g = rgb2gray(im);

h=zeros(1,255);
[rows cols] = size(g);
x=0;

for i=0:255
    x=0;
    for m=1:rows
        for n=1:cols
            if(g(m,n)==i)
                x=x+1;
            end
        end
    end
    h(1,i+1)=x;
end

subplot(411);
imshow(im);
title('Original Image');

subplot(412);
imshow(g);
title('Converted Gray Image');

subplot(413);
imhist(g);
title('Hist. of Converted Gray Image(Using imhist)');

subplot(414);
%bar(t,h);
stem(h);
title('Hist. of Converted Gray Image(without imhist)');

