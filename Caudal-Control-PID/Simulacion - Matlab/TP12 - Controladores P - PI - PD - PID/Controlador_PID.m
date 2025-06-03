%Componentes utilizados
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

%Función de transferencia directa
FTD = G1*G2*G3
%%Funcion de transferencia de lazo abierto
FTLA=FTD;

%%Funcion de transferencia de lazo cerrado
FTLC=feedback(FTLA,1);

[num_la, den_la]=tfdata(FTLA,'v');

%Encontramos constantes por el método 1 de Ziegler-Nichols
pasos = 1000; %Suficientes pasos para lograr buena precisión
S = stepinfo(FTD);
ts= S.SettlingTime; %Encontramos el tiempo de asentamiento
t= linspace(0,ts*1.5,pasos); %Hacemos el tiempo 50% mayor a ts
dt= ts*1.5/(pasos-1); %Definimos el delta de tiempo = t(n) - t(n-1) 
y = step(FTD,t);
dy = diff(y/dt); %Derivamos la salida
[m,p] = max(dy); %Hallamos el máximo y la ubicación
yi=y(p); %Obtenemos el valor máximo para el punto p
ti=t(p); %Obtenemos el tiempo
L = ti-yi/m
T = (y(end)-yi)/m+ti-L
K = y(end)

Kp1=1.2*T/(L*K);
Ki1 = Kp1/(2*L)
Kd1 = Kp1*0.5*L
PID1 = pid(Kp1,Ki1,Kd1)

%Encontramos constantes por el método 2 de Ziegler-Nichols
[gm,~,wc]=margin(FTD); %Hallamos el margen de ganancia y la frecuencia 
Ku=gm
Pu=2*pi()/wc

Kp2=0.6*Ku;
Ki2 = Kp2/(0.5*Pu)
Kd2 = Kp2*0.125*Pu
PID2= pid(Kp2,Ki2,Kd2)

%Encontramos los valores promedios de las constantes
Kp = (Kp1+Kp2)/2;
Ki = (Ki1+Ki2)/2;
Kd = (Kd1+Kd2)/2;

%Encontramos los valores para el control proporcional
%Elegimos un valor para R1
R61 = 10e3;

%Calculamos R2
R62 = R61*Kp


%Encontramos los valores para el control integral
%Elegimos un valor para C1 de 10 nF
C72=10e-9;

%Calculamos R2
R71 = 1/(C72*Ki)

%Encontramos los valores para el control derivativo
%Elegimos un valor para C1 de 10 nF
C81 = 10e-9;

%Calculamos R2
R82 = Kd/C81

Kp = R62/R61
Ki = 1/(C72*R71);
kd = C81*R82

PID3 = pid(Kp,Ki,Kd)

step(feedback(G1*G2*G3,1));
hold on
step(feedback(PID1*G1*G2*G3,1));
step(feedback(PID2*G1*G2*G3,1));
step(feedback(PID3*G1*G2*G3,1));
legend('G1*G2*G3','PID1','PID2','PID3');

