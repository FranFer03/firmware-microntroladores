clc;
close all;
clear;

%% Cargar la señal

load('ecg.mat');
plot(ecg);

%% Ajustar amplitud
G = 2000; %1mV
ecg_mv = ecg/G; %Amplitud ajustada
figure;
plot(ecg_mv);
xlim([0 1000]);
ylabel('Amplitud (mV)');
title('ECG Dominio del Tiempo');

%% Ajustar el vector de tiempo
Fs = 250;
t = (1:1:length(ecg))*(1/Fs);

figure;
plot(t,ecg_mv);
xlim([0 4]);
xlabel('Tiempo (s)');
ylabel('Amplitud (mV)');
title('ECG Dominio del Tiempo');

%% Centralizar la señal en cero
ecg_final = (ecg_mv - mean(ecg_mv))/std(ecg_mv);

figure;
plot(t,ecg_final);
xlim([0 4]);
xlabel('Tiempo (s)');
ylabel('Amplitud (mV)');
title('ECG Dominio del Tiempo');
