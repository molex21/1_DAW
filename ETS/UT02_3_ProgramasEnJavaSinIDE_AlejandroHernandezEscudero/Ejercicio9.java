import java.util.Scanner;

public class Ejercicio9 {
    public static void main(String args[]) {
	  int lado;    
	  int perimetro;   
	  Scanner teclado = new Scanner(System.in);
        System.out.println("Ingresa la longitud del lado del cuadrado: ");
        lado = teclado.nextInt();
	  perimetro = lado * 4;
 	  System.out.println("El perimetro del cuadrado es de " + perimetro);

    }

}