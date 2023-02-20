%I=imread('cameraman.tif')
%imshow(I);
%[l,c] = size(I);
%figure,imshow(I)
%I1=255-I
%figure,imshow(I)
%I2 = im2bw(I,0.2)
%figure,imshow(I2)

%I3 = im2bw(I,0.5)
%figure,imshow(I3)

%I4 = im2bw(I,0.8)
%figure,imshow(I4)

%imhist(I)
%figure,imshow(I)
%imhist(I1)
%figure,imshow(I1)

%Morphologie with square
se = strel('square',3) ;
se1 = strel('square',5) ;
se2 = strel('square',9) ;
I5 = imerode (I, se) ; 
I6 = imerode (I, se1) ; 
I7 = imerode (I, se2) ; 
%figure,imshow(I5);
%figure,imshow(I6);
%figure,imshow(I7);

%Morphologie with Line
se = strel('line',3,4) ;
se1 = strel('line',5,6) ;
se2 = strel('line',9,10) ;
I5 = imerode (I, se) ; 
I6 = imerode (I, se1) ; 
I7 = imerode (I, se2) ; 
%figure,imshow(I5);
%figure,imshow(I6);
%figure,imshow(I7);

%Algorithme des composantes connexes
A=imread('coins.png')
B=imread('rice.png')
%imshow(A)
figure
%imshow(B)
Im = im2bw(A,0.5) ;
[L,num] = bwlabel(Im,4) ;
RGB = label2rgb(L) ;
%figure,imshow(RGB)
Im1 = im2bw(B,0.5) ;
[L,num] = bwlabel(Im1,4) ;
RGB = label2rgb(L) ;
%figure,imshow(RGB)

%Images couleurs 
%1. Conversion d’une image RGB

C=imread('C:\Users\bouje\OneDrive\Bureau\Fleurs.jpg')
imshow(C)

RGB = rgb2gray(C) ;
%figure
%imshow(RGB)

RGB = rgb2ntsc(C) ;
%figure
%imshow(RGB)

RGB = rgb2hsv(C) ;
%figure
%imshow(RGB)

%Morphologie with square
se = strel('square',3) ;
se1 = strel('square',5) ;
se2 = strel('square',9) ;
I5 = imerode (C, se) ; 
I6 = imerode (C, se1) ; 
I7 = imerode (C, se2) ; 
%figure,imshow(I5);
%figure,imshow(I6);
%figure,imshow(I7);

%3. Ajout d’un bruit synthétique 
IN1 = imnoise(C, 'salt & pepper', 0.2);
IN2 = imnoise(C, 'salt & pepper', 0.4);
IN3 = imnoise(C, 'salt & pepper', 0.6);
IN4 = imnoise(C, 'salt & pepper', 0.8);
figure,imshow(IN1);
figure,imshow(IN2);
figure,imshow(IN3);
figure,imshow(IN4);

%4. Detection de contours

