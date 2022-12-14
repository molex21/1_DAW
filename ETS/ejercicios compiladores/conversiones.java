import java.util.Scanner;

class conversiones {
	public static void main(String[] args) {
		int dist = 0;
		int opcion = 0;

		do {
			System.out.println(
					"Escribe 1 para convertir de millas marinas a metros o 2 para comvertir centimetros a pulgadas");
			Scanner teclado = new Scanner(System.in);
			opcion = teclado.nextInt();

		} while (opcion != 1 && opcion != 2);

		if (opcion == 1) {
			System.out.println(
					"Escribe una distancia en millas marinas y te devolvere el resultado en metros");
			Scanner teclado = new Scanner(System.in);
			dist = teclado.nextInt();
			System.out.println(
					dist + " millas marinas son " + dist*1852 + " metros.");
		}else {
			System.out.println(
					"Escribe una distancia en centimetros y te devolvere el resultado en pulgadas");
			Scanner teclado = new Scanner(System.in);
			dist = teclado.nextInt();
			System.out.println(
					dist + " centimetros son " + (double)dist*0.393 + " pulgadas.");
		}

	}
}