Algoritmo TablasDeMultiplicar
	Definir a Como Entero;
	Definir resultado Como Entero;
	Definir contador Como Entero;

	stop =1 ;
	Escribir ("Escribe Un n�mero y te mostrar� su tabla de multiplicar");

	Leer a;
		Para contador<-0 Hasta  10 Con Paso 1 Hacer
			
			Si a <= 0 Entonces
				Repetir
					Escribir ("Escribe un n�mero positivo mayor que 0");
					Leer a;
				Hasta Que a>0 
			SiNo
			Fin Si
			resultado = a * contador;
			Escribir a, ('x'), contador, (' = '), resultado;
		Fin Para
		
FinAlgoritmo
