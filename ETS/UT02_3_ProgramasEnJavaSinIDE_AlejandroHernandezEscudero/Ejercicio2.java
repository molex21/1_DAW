import java.util.Scanner;

public class Ejercicio2{
	public static void main (String args[]){
		
		Scanner teclado = new Scanner(System.in);
		String nombre = "";
		String operacion = "";
		float num1 = 0;
		float num2 = 0;
		int opcion = 0;
		float resultado = 0;

		System.out.println("Hola, introduce tu nombre: ");
		nombre = teclado.nextLine();
		System.out.println("Introduce el primer numero: ");
		num1 = teclado.nextInt();
		System.out.println("Introduce el segundo numero: ");
		num2 = teclado.nextInt();

		do {
			System.out.println("\nOpcion 1 -> Sumar");
			System.out.println("Opcion 2 -> Restar");
			System.out.println("Opcion 3 -> Multiplicar");
			System.out.println("Opcion 4 -> Dividir");
      		System.out.println("Elige una opción:");
			opcion = teclado.nextInt();
			switch (opcion) {

    				case 1:
             		resultado= num1 + num2;
				operacion= "suma";
				break;

    				case 2:
             		resultado= num1 - num2;
				operacion= "resta";
				break;
    				
				case 3:
             		resultado= num1 * num2;
				operacion= "multiplicacion";
				break;

    				case 4:
             		resultado= num1 / num2;
				operacion= "division";
				break;

    				default:
             		System.out.println("Opcion no valida, prueba otra vez");
				break;

			}

    		} while(opcion <1 || opcion >4);
		
		System.out.println("Hola "+nombre+" el resultado de la "+operacion+ " de los dos numeros es "+resultado);

}

}