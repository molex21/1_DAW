#include <stdio.h>
#include <conio.h>


int resta(int res1, int res2)
{
    int r;
    r = res1 - res2;
    return (r);
}

int suma(int sum1, int sum2)
{
    int s;
    s = sum1 + sum2;
    return (s);
}

int misFunciones(int num1, int num2)
{
    int Suma = suma(num1, num2);
    printf("La suma de %d + %d es %d ", num1, num2, Suma);
    printf("\n");
    int Resta = resta(num1, num2);
    printf("La resta de %d - %d es %d ", num1, num2, Resta);
    printf("\n");
    getch();
}
