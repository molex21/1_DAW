Algoritmo DiasAFecha
	Definir dias Como Entero;
	Definir semanas Como Entero;
	Definir meses Como Entero;
	Definir anios Como Entero;
	
	Repetir
		Escribir ("Introduce una cantidad de días");
		Leer dias;
	Hasta Que dias>0
	
	anios<-trunc (dias / 365);
	dias<-dias mod 365;
	
	meses<-trunc (dias/30);
	dias<-dias mod 30;
	
	semanas<-trunc (dias/7)
	dias<-dias mod 7;
	
	Escribir ("La conversión son "),anios,(" años "),meses,(" meses "),semanas,(" semanas y "),dias,(" días. "), ;
FinAlgoritmo
