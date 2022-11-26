import java.util.Scanner;

public class Ejercicio3 {
    public static void main(String args[]) {
        Scanner teclado = new Scanner(System.in);
		int radio = 0;
		float resultado = 0;

		System.out.println("Escribe el radio del circulo: ");
		radio = teclado.nextInt();

        resultado =  3.1416 * Math.pow(radio,2);



    }

}