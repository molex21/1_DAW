import java.util.Scanner;

public class Ejercicio3 {
	public static void main (String [] args){
        int Radio;  
	  double Area;   
        System.out.println("Ingresa la longitrud del radio: ");
        Scanner teclado = new Scanner(System.in);
        Radio = teclado.nextInt();
        Area = Math.PI * Math.pow(Radio, 2) ; 
        System.out.println("El area del circulo es de " + Area);
               
     }


}