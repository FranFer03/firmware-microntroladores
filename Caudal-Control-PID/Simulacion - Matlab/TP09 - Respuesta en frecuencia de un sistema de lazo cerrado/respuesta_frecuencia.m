%Script created by CHL
%5fh year, Control System, UTN-FRT
%*******************************************************************
%Cargar los vectores mag, fase y frec obtenidos de las
%columnas (5), (7) y (2) respectivamente.

mag=[];
fase=[];
frec=[];

mag=[0.95 1.16 1.08 1.29 1.37 1.34 1.22 0.97 0.20];
fase=[-5.14 -28.75 -41.31 -54.86 -72.24 -83.71 -99.98 -122.48 -189.45];
frec=[102 497 652 747 865 953 1052 1198 2990];

R11 =1.8e3; 
C11 =12e-9;
R21 = 10e3;
R22 = 56e3;
R31 = 270e3;
R32 = 390e3;
C31 = 1.5e-9;
C32 = 1.2e-9;

%Bloque de filtro pasa bajo RC
num_G1 = 1;
den_G1 = [R11*C11 1]; 
G1= tf(num_G1,den_G1);

%Bloque amplificador no inversor
num_G2= R21+R22;
den_G2= R21;
G2= tf(num_G2, den_G2);

%Filtro pasa bajo de 2do orden. Configuración Sallen Key.
num_G3=1/(C31*C32*R31*R32) ;
den_G3= [1 (1/(R32*C32))+(1/(R31*C32)) 1/(C31*C32*R31*R32)];
G3= tf(num_G3, den_G3);

%Funcion de transferencia directa
FTD=G1*G2*G3;

%Funcion de transferencia de lazo abierto
FTLA=FTD;

%Funcion de transferencia de lazo cerrado
FTLC = feedback(FTLA,1);

%It plots bode response 
sys=FTLC;

subplot(2,2,1);
semilogx(frec,mag2db(mag),'-g');hold on;
semilogx(frec,mag2db(mag),'dr','LineWidth',2);
title('Respuesta en frecuencia');
ylabel('ganancia [dB]'); grid on;
freq2=logspace(log10(min(frec)),log10(max(frec)),200);
[amp2,fase2]=bode(sys,freq2.*2*pi);
semilogx(freq2,mag2db(reshape(amp2,1,length(freq2))),':b','LineWidth',2);
%legend('datos de laboratorio','gráfica teórica');
subplot(2,2,3);
semilogx(frec,fase,'-g'); hold on;
semilogx(frec,fase,'*r','LineWidth',2);
xlabel('frecuencia [Hz]'); ylabel('fase [grados]'); grid on;
semilogx(freq2,reshape(fase2,1,length(freq2)),':b','LineWidth',2);


%Figure 2
%It plots Nyquist response 

w = linspace(-100000*pi,100000*pi,10000);
[re,im] = nyquist(sys,w);
%Here re and im are the real and imaginary parts of the frequency response
%Create a Nyquist plot showing the response

re = squeeze(re);
im = squeeze(im);
re2=mag.*cosd(fase);
im2=mag.*sind(fase);

subplot(2,2,[2 4]);
plot(re,im,'b',-1,0,'+r',re2,im2,'g:',re2,im2,'*r','LineWidth',2);
title('Gráfica de Nyquist');
xlabel('Eje real');
ylabel('Eje imaginario');

