clc;
close all;
clear;
load('ecg.mat');

G = 2000;
Fs = 250;

ecg_mv = ecg/G;
t = (1:1:length(ecg))*(1/Fs);
ecg_final = (ecg_mv - mean(ecg_mv))/std(ecg_mv);
%% Transformada de Fourier
F = fft(ecg_final);
F = abs(F);
plot(F);
%% Como tenemos espejada la función. Eliminamos una parte
F = F(1:ceil(end/2));
plot(F);

%% Ajustar la magnitud
F = F/max(F);
plot(F);

%% Vector de frecuencia
L = length(F);
f = (1:1:L)*((Fs/2)/L);

figure;
plot(f,F)
xlabel('Frecuencia (Hz)');
ylabel('Mgnitud Normalizada');
title('ECG en Frecuencia');