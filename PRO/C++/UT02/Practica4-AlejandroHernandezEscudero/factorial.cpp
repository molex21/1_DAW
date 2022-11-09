#include <stdio.h>
#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#endif
int main()
{
    int numero;
    int fact = 1;
    do
    {
        printf("Escribe un numero mayor que 1 para realizar el factorial: ");
        scanf("%d", &numero);
  
        
    } while (numero < 1);

    for (int i = 1; i <= numero; i++)
    {
        fact = fact * i;
    }

    printf("El factorial de %d es %d", numero , fact);
    
    return (fact);
    system("cls");
}