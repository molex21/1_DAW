import java.util.Scanner;

public class TablasDeMultiplicar {

	 public static void main(String[] args) {
		int a;
		int contador;
		int resultado;
		int stop;
		stop = 1;
		System.out.println(("Escribe Un numero y te mostrare su tabla de multiplicar"));
		Scanner num = new Scanner(System.in);

		a = num.nextInt();
		for (contador=0;contador<=10;contador++) {
			if (a<=0) {
				do {
					System.out.println(("Escribe un numero positivo mayor que 0"));
					Scanner num2 = new Scanner(System.in);
					a = num2.nextInt();
				} while (a<=0);
			} else {
			}
			resultado = a*contador;
			System.out.println(a+("x")+contador+(" = ")+resultado);
		}
	}


}

