import java.util.Scanner;

class notaMediaETS {
	public static void main(String[] args) {
		float uno, dos, tres = 0;
		Scanner teclado = new Scanner(System.in);

		do {
			System.out.print("Escribe la nota de la primera evaluacion: ");
			uno = teclado.nextFloat();
		} while (uno < 0);

		do {
			System.out.print("Escribe la nota de la segunda evaluacion: ");
			dos = teclado.nextFloat();
		} while (dos < 0);

		do {
			System.out.print("Escribe la nota de la tercera evaluacion: ");
			tres = teclado.nextFloat();
		} while (tres < 0);

		System.out.println(("La nota media es: ") + ((uno+dos+3)/2));
	}

}