ecu = [1 1 10];
ceros = roots(ecu);
alpha = angle(ceros(1));
amatiguamiento = abs(cos(alpha))
frecu_dinamica = imag(ceros(1))*sqrt(1-(cos(alpha)*cos(alpha)))