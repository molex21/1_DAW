import java.util.Scanner;

class operacionesConDecimales {
	public static void main(String[] args) {
		float numero;
		float numero2;
		int opcion = 0;
		Scanner teclado = new Scanner(System.in);

		System.out.print("Escribe un numero decimal: ");
		numero = teclado.nextFloat();

		System.out.print("Escribe otro numero decimal: ");
		numero2 = teclado.nextFloat();

		do {
			System.out.println("1. Sumar ");
			System.out.println("2. Restar ");
			System.out.println("3. Multiplicar ");
			System.out.println("4. Division ");			
			System.out.println("0. Salir ");
			System.out.print("Elige una opcion: ");
			opcion = teclado.nextInt();

		} while (numero <= 0);

		
		System.out.println(("El factorial de " + numero + " es: ") + );
	}

}