import java.util.Scanner;

public class Ejercicio10 {
    public static void main(String args[]) {
	int radio;
	double volumen;
	Scanner teclado = new Scanner(System.in);
      System.out.println("Ingresa el radio de la esfera: ");
	radio = teclado.nextInt();
	volumen = (((float)4/3)*Math.PI) * Math.pow(radio,3);
	System.out.println("El volumen de la esfera es de " + volumen);


    }

}