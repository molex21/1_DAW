import java.util.Scanner;

public class PrimeraImplementacion_Alejandro_Hernandez_Escudero {
	public static void main(String[] args) {
		// Declaro las variables que necesito usar
		int edad;
		int resta;
		String nombre;
		String dni;
		String apellido;
		String decision;
		// Comienzo a pedir los valores de nombre y edad
		System.out.println("Por favor introduzca un nombre.");
		Scanner uno = new Scanner(System.in);
		nombre = uno.nextLine();
		System.out.println("Por favor introduzca su edad.");
		edad = uno.nextInt();
		if (edad < 18) {
			resta = 18 - edad;
			System.out.println("Hola " + nombre + " ,acceso no permitido, vuelva cuando seas mayor de edad, dentro de "
					+ resta + " años.");

		} else {
			System.out.println("¿Desea registrarse como socio? [Si/No]");
			Scanner dos = new Scanner(System.in);
			decision = dos.nextLine();
			System.out.println(decision);
			if (decision.equals("Si")) {
				System.out.println("Por favor introduzca su DNI.");
				Scanner tres = new Scanner(System.in);
				dni = tres.nextLine();
				System.out.println("Por favor introduzca su apellido.");
				apellido = tres.nextLine();
				System.out.println("Gracias por afiliarse Sr/a " + apellido + ". Bienvenido/a al Casino Las Vegas.");


			} else if (decision.equals("No")) {
				System.out.println("Lo sentimos, pero no puede entrar al casino si no esta afiliado.");

			} else{
				System.out.println("Valor no aceptado, repita el proceso");

			}

		}
	}
}