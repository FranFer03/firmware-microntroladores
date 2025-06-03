polo_deseado = [-29.5,37.2];
polo_1 = [-1,0];
polo_2 = [-12,0];
ang_polo_1 = 90 + atand(abs((polo_deseado(1)-polo_1(1)))/(polo_deseado(2)-polo_1(2)));
ang_polo_2 = 90 + atand(abs((polo_deseado(1)-polo_2(1)))/(polo_deseado(2)-polo_2(2)));
angulo_deficiencia = 180 - ang_polo_1 - ang_polo_2;
disp(angulo_deficiencia);