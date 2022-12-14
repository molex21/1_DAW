import java.util.Scanner;

public class calcularAreaTrianguloIsosceles {
    public static void main(String args[]) {
	  double base;
	  double lado; 
        double altura;   
	  double Area;   
	  Scanner teclado = new Scanner(System.in);
        System.out.println("Ingresa la longitud de los lados iguales del triangulo isosceles: ");
        lado = teclado.nextInt();
	  System.out.println("Ingresa la longitud de la base del triangulo: ");
        base = teclado.nextInt();
	  altura = Math.sqrt(lado*lado-base*base);
	  Area = (base * altura) /2;
 	  System.out.println("El area del triangulo es de " + Area);

    }

}