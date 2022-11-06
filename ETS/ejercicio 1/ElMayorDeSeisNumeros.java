import java.util.Scanner;

class ElMayorDeSeisNumeros {
    public static void main(String[] args) {
		int a;
		int max = 0;
		int contador =0;

do {
			System.out.println("Escribe un numero");
			Scanner uno = new Scanner(System.in);
			a = uno.nextInt();
			contador = contador+1;
			if (a<0) {
			}else if (max<a) {
				max = a;
			} else {
			}
		} while (contador!=6);
		System.out.println(("El numero mayor es: ")+max);
	}


}

