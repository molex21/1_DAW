Algoritmo MxMinDeN
	Definir numTotal Como Entero;
	Definir num Como Entero;
	Definir max Como Entero;
	Definir min Como Entero;
	
	Escribir ("Escribe la cantidad de números que vas a comprobar")
	Leer numtotal;
	
	Para contador<-1 Hasta numtotal Con Paso 1 Hacer
			Escribir ("Introduce un número mayor que 0:");
			Leer num;
		Si contador = 1 Entonces
			max<-num;
			min<-num;
		Fin Si
		Si max<num Entonces
			max<-num;
		SiNo
			Si min>num Entonces
				min<-num;
			Fin Si
		Fin Si
		
		
	Fin Para
	Escribir ("El número mayor es: "),max,(" y el menor es: "),min,;
	
FinAlgoritmo
