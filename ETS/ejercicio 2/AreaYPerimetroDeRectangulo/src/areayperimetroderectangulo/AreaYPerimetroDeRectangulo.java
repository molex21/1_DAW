package areayperimetroderectangulo;

/**
 *
 * @author alejandro
 */

import java.util.Scanner;
public class AreaYPerimetroDeRectangulo {

    public static void main(String[] args) {
        int lado1;
        int lado2;
        int area;
        int perimetro;
        System.out.println("Calculare el area y el perimetro de un rectangulo.");
        System.out.println("Introduce el valor del primer lado:");
        Scanner lad1 = new Scanner(System.in);
        lado1 = lad1.nextInt();
        System.out.println("Introduce el valor del segundo lado:");
        Scanner lad2 = new Scanner(System.in);
        lado2 = lad2.nextInt();

        if (lado1 == lado2) {
          System.out.println("Eso es un cuadrado.");
        }else{
          area = lado1 * lado2;
          perimetro = (lado1*2) + (lado2*2);
          System.out.println("Para el rectangulo de lados "+ lado1+ " y "+ lado2+ ":") ;
          System.out.println("El area es "+ area+ " y el perimetro es "+ perimetro+ ".") ;
        }
    }
}


