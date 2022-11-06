
#include <conio.h>
#include <stdio.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int max;
    int min;
    printf("Escribe el primer numero.\n");
    scanf("%d", &num1);
    
    printf("Escribe el segundo numero.\n");
    scanf("%d", &num2);
    if (num1 == num2)
    {
        printf("Los numeros son iguales, escribe un numero diferente\n");
        scanf("%d", &num2);
        return 0;
    }
    else
    {
        printf("Escribe el tercer numero.\n");
        scanf("%d", &num3);
        
    }
}
