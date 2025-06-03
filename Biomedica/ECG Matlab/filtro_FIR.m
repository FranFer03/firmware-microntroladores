clc; 
clear; 
close all;
load('ecg.mat')

Fs = 250;
G = 2000;

ecg = ecg/G;
ecg = (ecg - mean(ecg))/std(ecg);
t = (1:1:length(ecg))*(1/Fs);

F = fft(ecg);
F = abs(F);
F = F(1:ceil(end/2));
F = F/max(F);
L = length(F);
f = (1:1:L)*((Fs/2)/L);

%% Filtrado FIR

% Caracteristicas del filtro
orden = 200;
limi = 59;
lims = 61;

% Normalizar
limi_n = limi/(Fs/2);
lims_n = lims/(Fs/2);

% Crear filtro
a = 1;
b = fir1(orden,[limi_n lims_n],'stop');

% Filtrar señal
ecg_limpio = filtfilt(b,a,ecg);

figure;
F = fft(ecg_limpio);
F = abs(F);
F = F(1:ceil(end/2));
F = F/max(F);
plot(f,F)
xlabel('Frecuencia (Hz)');
ylabel('Magnitud Normalizada CON filtro FIR');
title('ECG en Frecuencia');

