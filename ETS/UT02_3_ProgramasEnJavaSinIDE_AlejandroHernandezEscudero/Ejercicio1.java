import java.util.Scanner;

public class Ejercicio1{
	public static void main (String args[]){
		//crear el objeto scanner
		Scanner teclado = new Scanner(System.in);
		String nombre = "";
		int num1 = 0;
		int num2 = 0;
		int resultado = 0;

		System.out.println("Hola, introduce tu nombre: ");
		nombre = teclado.nextLine();
		System.out.println("Introduce el primer sumando: ");
		num1 = teclado.nextInt();
		System.out.println("Introduce el segundo sumando: ");
		num2 = teclado.nextInt();

		resultado = num1 + num2;

		System.out.println("Hola "+nombre+" el resultado de la suma de los dos numeros es "+resultado);

}


}