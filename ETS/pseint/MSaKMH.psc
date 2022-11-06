Algoritmo MSaKMH
	Definir vel Como Entero;
	Definir res Como Real;

	Repetir
		Escribir ("Introduce una velocidad positiva, mayor que 0 en m/s:");
		Leer vel;
	Hasta Que vel>0;
	
	res <- (vel * 3.6);
		
	Escribir num,(" m/s son "),res,(" km/h.");
	
FinAlgoritmo