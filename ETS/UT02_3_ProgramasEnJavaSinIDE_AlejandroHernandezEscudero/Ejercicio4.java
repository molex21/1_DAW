import java.util.Scanner;

public class Ejercicio4 {
    public static void main(String args[]) {
	  int base;
	  int altura;    
	  double Area;   
	  Scanner teclado = new Scanner(System.in);
        System.out.println("Ingresa la longitrud de la base del triangulo: ");
        base = teclado.nextInt();
	  System.out.println("Ingresa la longitrud de la altura del triangulo: ");
        altura = teclado.nextInt();
	  Area = (base * altura) /2;
 	  System.out.println("El area del triangulo es de " + Area);
    }

}