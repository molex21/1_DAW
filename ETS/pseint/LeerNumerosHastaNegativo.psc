Algoritmo LeerNumerosHastaNegativo
	Definir a Como Entero;
	Definir contador Como Entero;
	Definir NumerosTotales Como Entero;
	Definir stop Como Entero;
	stop = 0;
	NumerosTotales=0;
	
	Repetir
		Escribir ('Escribe un número');
		Leer a;
		NumerosTotales= NumerosTotales+1
		Si a<1  y NumerosTotales >= 3 Entonces
			stop = 1
		SiNo
		Fin Si
	Hasta Que stop = 1
	
	Escribir ('Se han introducido '), NumerosTotales , (' números.');
	
FinAlgoritmo