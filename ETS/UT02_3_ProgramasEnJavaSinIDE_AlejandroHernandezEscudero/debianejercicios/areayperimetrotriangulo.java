import java.util.Scanner;

public class areayperimetrotriangulo{
	public static void main (String args[]){
		//crear el objeto scanner
		Scanner teclado = new Scanner(System.in);
		double lado1, lado2, lado3, perimetro, area, s;

do {
	System.out.println("Introduce el primer lado: ");
		lado1 = teclado.nextDouble();
		System.out.println("Introduce el segundo lado: ");
		lado2 = teclado.nextDouble();
		System.out.println("Introduce el tercer lado: ");
		lado3 = teclado.nextDouble();
		if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
			System.out.println("No se permiten numers negativos o 0, prueva otra vez");
		 }
} while (lado1 <= 0 || lado2 <= 0 || lado3 <= 0);

		perimetro = lado1 + lado2 + lado3;
		s = perimetro /2;
		area = (Math.sqrt( s * (s-lado1) * (s-lado2) * (s-lado3)));


		System.out.println("El area del triangulo es "+area+" y el perimetro "+perimetro);

}


}