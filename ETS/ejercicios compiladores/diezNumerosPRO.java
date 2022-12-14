import java.util.Scanner;

class diezNumerosPRO {
	public static void main(String[] args) {
		int numero = 0;
		int totalNumeros = 0;
		float media = 0;
		int max = 0;
		int min = 0;
		int par = 0;
		int impar = 0;
		System.out.println(
				"El programa pide 10 numeros y muestra el numero mayor, el menor, la media y la suma de pares e impares");
		Scanner teclado = new Scanner(System.in);

		do {
			System.out.print("Introduce un numero: ");
			numero = teclado.nextInt();

			if (totalNumeros == 0) // en el perimer valor que se introduce declara que es el número máximo y minimo
			{
				max = numero;
				min = numero;
			}

			if ((numero % 2) == 0) // hago el modulo del número entre dos, si es 0 es par, si no es impar
			{
				par = par + 1;
			} else {
				impar = impar + 1;
			}

			if (numero >= max) // identifico si el numero actual es mayor o que el que se almacena como max, si
								// no es lo guardo en max
			{
				max = numero;
			} else if (numero <= min) // identifico si el numero actual es menor o que el que se almacena como min, si
										// no es lo guardo en min
			{
				min = numero;
			}

			media += numero;
			System.out.println("Numero " + numero + " registrado correctamente");
			totalNumeros++;
		} while (totalNumeros < 10);

		media = media / 10;

		System.out.println(("El numero mayor es: ") + max);
		System.out.println(("El numero menor es: ") + min);
		System.out.println(("La media de los numeros es: ") + media);
		System.out.println(("Hay un toral de: ") + par + " numeros pares");
		System.out.println(("Hay un toral de: ") + impar + " numeros impares");
	}

}