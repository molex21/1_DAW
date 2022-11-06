Algoritmo ElMayorDeSeisNumeros
	Definir a Como Entero;
	Definir max Como Entero;
	Definir contador Como Entero;
	contador<-0;
	Repetir
		Escribir ('Escribe un número');
		Leer a;
		contador = contador+1
		Si a<0 Entonces
			
		FinSi
		Si max<a Entonces
			max<-a;
			
		SiNo
		Fin Si
	Hasta Que contador = 6
	
		Escribir ('El número mayor es: '), max;
	
	
FinAlgoritmo
