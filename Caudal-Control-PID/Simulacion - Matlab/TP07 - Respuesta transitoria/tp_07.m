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

%Informacion de respuesta a un escalon
stepinfo(FTLC);


