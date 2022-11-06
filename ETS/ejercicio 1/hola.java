import java.util.Scanner;

class hola {
    public static void main(String[] args) {
		String Alumnado;
        	System.out.println("Indique su nombre"); 
		Scanner uno = new Scanner(System.in);
		Alumnado = uno.nextLine();
		System.out.println("Hola " + Alumnado + ", encantado de conocerte");
    }
}