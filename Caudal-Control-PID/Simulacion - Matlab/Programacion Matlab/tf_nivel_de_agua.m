clc
clear all
close all
D = 19/100; %m
A = pi*D^2/4;%m2
Ho = 13/100; %m
a2 = 0.2;
k1 = 4.0703e-04;
k2 = 6.63e-05;
g = 9.8;
num = k1/A;
den = [1 (k2*a2*sqrt(2*g)/(2*A*sqrt(Ho)))];
G = tf(num/den(2),den/den(2))