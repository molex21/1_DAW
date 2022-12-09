import java.util.Scanner;

public class Ejercicio8 {
    public static void main(String args[]) {
	  int base; 
        int altura;   
	  int perimetro;   
	  Scanner teclado = new Scanner(System.in);
        System.out.println("Ingresa la longitud de la altura del rectangulo: ");
        altura = teclado.nextInt();
	  System.out.println("Ingresa la longitud de la base del rectangulo: ");
        base = teclado.nextInt();
	  perimetro = base * 2 + altura * 2;
 	  System.out.println("El perimetro del rectangulo es de " + perimetro);
    }
    

}