%%Componentes
R11=1.8e3;
C11=12e-9;
R21=10e3;
R22=56e3;
R31=270e3;
R32=390e3;
C31=1.5e-9;
C32=1.2e-9;

%%Calculo de G1
tao=1/(R11*C11);
num_G1= tao;
den_G1= [1 tao];
G1 = tf(num_G1,den_G1);

%%Calculo de G2
num_G2= R21+R22;
den_G2= R21;
G2=tf(num_G2,den_G2);

%%Calculo de G3
num_G3=1/(R31*R32*C31*C32);
den_G3=[1 (R32*C31+R31*C31)/(R31*R32*C31*C32) 1/(R31*R32*C31*C32)];
G3=tf(num_G3,den_G3);

%%Funcion de transferencia directa
FTD=G1*G2*G3;

%%Funcion de transferencia de lazo abierto
FTLA=FTD;

%%Funcion de transferencia de lazo cerrado
FTLC=feedback(FTLA,1);

%%Info de FTLC tras recibir una señal escalon
stepinfo(FTLC)
%%-------------------------------------------
%Para una sobreelongación del 10% tenemos
Mp=0.1;
dseta = abs(log(Mp))/sqrt(pi^2+(log(Mp))^2);

%Frecuencia natural del sistema
[omega_n, ~]=damp(FTLC);
omega_n=min(omega_n);

%%Atenuacion del sistema
sigma=dseta*omega_n;

%%Anulamos el segundo polo (Metodo analitico)
[~,p,~]=zpkdata(FTLA,'v');
z_c=p(2);

%%Centroide
p_c=(-sigma*2+p(3));

%%Valor k para el polo deseado
p_de=-dseta*omega_n+1j*omega_n*sqrt(1-dseta^2);
s=p_de;
k_c=abs(polyval(denG3,s)/polyval(numG3,s)*(s-p_c)/(s-z_c));

%%Polos dominantes de LC
p_lc=pole(FTLC);
p_do=min(p_lc);

%%Elegimos un valor inicial arbitrario de C41
C41=10e-9;

%Calculamos C42
C42=C41/k_c;
C42=round63(C42,'E12');

%Calculamos R41
R41=-1/(C41*z_c);
R41=round63(R41,'E12');

%Calculamos R42
R42=-1/(C42*p_c);
R42=round63(R42,'E12');

%
[num_la, den_la]=tfdata(FTLA,'v');
[num_ca, den_ca]=zp2tf(-1/(R41*C41),-1/(R42*C42),C41/C42);

