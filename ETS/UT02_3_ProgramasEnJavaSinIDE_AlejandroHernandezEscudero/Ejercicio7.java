import java.util.Scanner;

public class Ejercicio7 {
    public static void main(String args[]) {
	  int base; 
        int altura;   
	  int Area;   
	  Scanner teclado = new Scanner(System.in);
        System.out.println("Ingresa la longitud de la altura del resctangulo: ");
        altura = teclado.nextInt();
	  System.out.println("Ingresa la longitud de la base del resctangulo: ");
        base = teclado.nextInt();
	  Area = base * altura;
 	  System.out.println("El area del rectangulo es de " + Area);
    }

}