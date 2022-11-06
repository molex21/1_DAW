Algoritmo AprobadosSuspensos
	Definir a Como Entero;
	Definir stop como entero;
	Definir contador Como Entero;
	Definir aprobados Como Entero;
	Definir suspensos Como Entero;
	stop =1 ;
	Escribir ("Escribe las diez notas");
	
		Para contador<-1 Hasta  10 Con Paso 1 Hacer
			Leer a;
			Si a <= 0 o a > 10 Entonces
				Repetir
					Escribir ("Escribe un número positivo mayor que 0 y menor o igual a 10");
					Leer a;
				Hasta Que a>0 y a<=10
				Si a>=5 Entonces
					aprobados = aprobados+1;
				SiNo
					suspensos = suspensos+1;
				Fin Si
			SiNo

				Si a>=5 Entonces
					aprobados = aprobados+1;
				SiNo
					suspensos = suspensos+1;
				Fin Si
			Fin Si
			Fin Para
	
		Escribir ("El número de aprobados es: "), aprobados;
		Escribir ("El número de suspensos es: "), suspensos;
	
FinAlgoritmo
