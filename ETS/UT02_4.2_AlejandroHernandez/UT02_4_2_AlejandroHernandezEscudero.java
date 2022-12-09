
public class UT02_4_2_AlejandroHernandezEscudero{
	public static void main (String args[]){
			
		int num1 = 0;
		int num2 = 1;
		int res = 0;
		System.out.println("#####  SUCESION DE FIBONACCI HASTA EL 34  #####");

		System.out.print(num1+", ");
		System.out.print(num2);
		while (res < 34) {
			res = num1+num2;
			num1 = num2;
			num2 = res;
			System.out.print(", "+res);
			
		}
	
}
}