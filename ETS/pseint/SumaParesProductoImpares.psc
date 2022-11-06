Algoritmo SumaParesProductoImpares
	Definir numTotal Como Entero;
	Definir num Como Entero;
	Definir pares Como Entero;
	Definir impares Como Entero;
	impares<-1;
	pares<-0;
	Escribir ("Escribe la cantidad de números que vas a comprobar")
	Leer numtotal;
	
	Para contador<-1 Hasta numtotal Con Paso 1 Hacer
		Repetir
			Escribir ("Introduce un número mayor que 0:");
			Leer num;
		Hasta Que num>0
			Si num%2=0 Entonces
				pares=pares+num;
			SiNo
				impares=impares*num;
			Fin Si
		
		
	Fin Para
	Escribir ("La suma de los pares es: "),pares,(" y la resta de los impares es: "),impares,;
	
FinAlgoritmo
