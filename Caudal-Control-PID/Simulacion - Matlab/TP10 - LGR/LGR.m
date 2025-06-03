%Script created by CHL
%5fh year, Control System, UTN-FRT
%*******************************************************************
%Cargar los vectores K, Vp, Vf, tp (ganancia, tensión de pico, tensión régimen permanente y tiempo de pico) 
%de las columnas (5), (7) y (2) respectivamente.

K=[];
Vp=[];
Vf=[];
tp=[];

K = [ 0.1 1 2 4 7.7];
Vp = [3.99 1.12 0.64 0.41 0.27];
Vf = [3.97 0.82 0.43 0.23 0.14];
tp = [2.17 0.52 0.35 0.25 0.21];

%G1 Transfer Function
R11=1.8e3;
C11=12e-9;
num_G1=[1];
den_G1=[R11*C11 1];
G1=tf(num_G1, den_G1);

%G2 Transfer Function
R21=10e3;
R22=56e3;
num_G2=[R21+R22];
den_G2=[R21];
G2=tf(num_G2, den_G2);

%G3 Transfer Function
R31=270e3;
R32=390e3;
C31=1.5e-9;
C32=1.2e-9;
num_G3=1;
den_G3=[C31*C32*R31*R32 C31*(R31+R32) 1];
G3=tf(num_G3, den_G3);

%FTD Transfer Function
FTD=G1*G2*G3;

n=length(K);

%Plot root locus in green color
rlocus(FTD,'g');

%Resize axis scale
axis([-5e4 1e4 -2e4 2e4]);
hold on;


%Plot of complex conjugate poles 
%Assuming a second order system
for i=1:length(K)
       Mp=(Vp(i) - Vf(i)) / Vf(i);
       dseta(i)=abs(log(Mp)) / sqrt(pi^2 + (log(Mp))^2);
       omega_d(i)=pi / ( tp(i) / 1e3);
       omega_n(i)=omega_d(i) / sqrt(1 - dseta(i)^2);
       sigma(i)=dseta(i) * omega_n(i);
       
       %Positive imaginary part poles 
        plot(-sigma(i), +omega_d(i), 'rX');
        
        %Negative imaginary part poles 
        plot(-sigma(i), -omega_d(i), 'rX');
end