import java.util.Scanner;

public class Ejercicio6 {
    public static void main(String args[]) {
	  
	  double lado; 
        double altura;   
	  double Area;   
	  Scanner teclado = new Scanner(System.in);
        System.out.println("Ingresa el lado de un triangulo equilatero: ");
        lado = teclado.nextInt();
	  altura = Math.sqrt(lado*lado-(lado/2)*(lado/2));
	  Area = (lado * altura) /2;
 	  System.out.println("El area del triangulo es de " + Area);
    }

}