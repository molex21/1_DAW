import java.util.Scanner;

class factorial {
	public static void main(String[] args) {
		int numero;
		long fact = 1;

		do {
			System.out.println("Escribe un numero mayor que 0");
			Scanner teclado = new Scanner(System.in);
			numero = teclado.nextInt();

		} while (numero <= 0);

		for (int i = 1; i <= numero; i++) {
			fact = fact * i;
		}
		System.out.println(("El factorial de " + numero + " es: ") + fact);
	}

}