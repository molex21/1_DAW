Algoritmo DistanciaMaxMin
	Definir a Como Entero;
	Definir max Como Entero;
	Definir min Como Entero;
	Definir distancia Como Entero;
	Definir contador Como Entero;
	contador<-0;
	min =0;
	Repetir
		Escribir ('Escribe un número');
		Leer a;
		Si contador = 0 Entonces
			min<-a;
		SiNo
		Fin Si
		
		contador= contador+1
		Si max<a Entonces
			max<-a;
		SiNo
			Si min>=a Entonces
				min<-a; 
			SiNo
			Fin Si
		Fin Si
	Hasta Que contador = 5
	
		distancia = max - min
	Escribir ('La distancia entre el máximo y el mínimo es: '), distancia;
FinAlgoritmo

