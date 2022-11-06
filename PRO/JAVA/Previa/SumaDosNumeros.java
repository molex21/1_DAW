
/* Ejeplo 2 Java*/
/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SumaDosNumeros {
	public static void main(String[] args) throws IOException {
		System.out.println("Bienvenidos a Java");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Por favor introduzca un nombre");
		String nombre = br.readLine();
		System.out.println("Bienvenido " + nombre + ". Por favor Ingrese su edad");
		String entrada = br.readLine();
		int edad = Integer.parseInt(entrada);
		System.out.println("Gracias " + nombre + " en 10 años tendrás " + (edad + 10) + " años.");
	}
}*/
/*
public class SumaDosNumeros {
	public static void main(String[] args) {
		System.out.println("Bienvenidos a Java");
		System.out.println("Por favor introduzca un nombre");
		String nombre = System.console().readLine();
		System.out.println("Bienvenido " + nombre + ". Por favor Ingrese su edad");
		String entrada = System.console().readLine();
		int edad = Integer.parseInt(entrada);
		System.out.println("Gracias " + nombre + " en 10 años tendrás " + (edad + 10) + " años.");
	}
}
 */
import java.util.Scanner;

public class SumaDosNumeros {
	public static void main(String[] args) {

		System.out.println("Bienvenidos a Java");
		System.out.println("Por favor introduzca un nombre");
		Scanner in = new Scanner(System.in);
		String nombre = in.nextLine();
		System.out.println("Bienvenido " + nombre + ". Por favor Ingrese su edad");
		int edad = in.nextInt();
		
		System.out.println("Gracias " + nombre + " en 10 años tendrás " + (edad + 10) + " años.");
	}
}