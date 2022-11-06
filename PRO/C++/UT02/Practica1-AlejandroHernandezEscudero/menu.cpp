#ifdef _WIN32
#include <windows.h>
#endif
#include <conio.h>
#include <stdio.h>

#include "misFunciones.h"

int edad50()
{
    int edad;
    int edad50;

    printf("Escribe tu edad: ");
    scanf("%d", &edad);

    edad50 = edad + 50;
    printf("Tu edad dentro de 50 anyos sera ");
    printf("%d", edad50);
    printf("\n");
}
int main()
{

    int opcion;
    int decision;
    system("cls");
    do
    {
        // Escribo el textp del menú
        printf("\n");
        printf("-------MENU-------\n");
        printf("Elija una opcion:\n\n");
        printf("#################\n\n");
        printf("Opcion '1' Calcular edad en 2050.\n");
        printf("Opcion '2' Contar numeros impares.\n");
        printf("Opcion '3' Sumar y restar dos numeros.\n");
        printf("Opcion '4' Factorial.\n");
        printf("Opcion '5' Salir.\n\n");
        printf("#################\n\n");
        printf("Escribe una opcion: ");
        scanf("%d", &opcion); // Se pide la opción

        // Ejecución del menú
        switch (opcion)
        {
        case 1:
            system("cls");
            edad50();
            getch();

            break;
        case 2:
            system("cls");

            // Declaro la variable que usare durante el codigo
            int num;

            // Inicio el bucle que pedira un numero hasta que sea mayor que 1
            do
            {
                printf("Escribe un numero mayor que 1, mostrare los impares: ");
                scanf("%d", &num); // Leo el numero introducido

                for (int i = 1; i <= num; i++)
                {
                    if (i == 1)
                    {
                        printf("\nLos numeros impares son %d", i);
                    }
                    else if (i % 2 == 0)
                    {
                    }
                    else if (i == num || i == (num - 1))
                    {
                        printf(", %d.", i);
                    }
                    else
                    {
                        printf(", %d", i);
                    }
                }

            } while (num < 1);

            printf("\n");
            getch();
            system("cls");
            break;

        case 3:
            system("cls");
            int num1;
            int num2;
            printf("\n");
            printf("Introduzca el primer numero: ");
            scanf("%d", &num1);
            printf("\n");
            printf("Introduzca el segundo numero: ");
            scanf("%d", &num2);
            printf("\n");
            misFunciones(num1, num2);

            break;
        case 4:
            system("cls");
            system("factorial");
            getch();
            system("cls");

            break;
        case 5:
        system("cls");
         printf("Escribe 1 si deseas salir del programa, y cualquier otra cosa si no.\n");
         scanf("%d", &decision);
         if (decision == 1)
         {
            printf("Hasta la proxima");
            getch();
            return 0 ;
         }else
         {
            opcion=0;
            printf("Volviendo al menu...");
            getch();
            system("cls");
         }
                
            break;

        default:
            system("cls");
            printf("Opcion no valida.\n");
            getch();

            break;
        }
    } while (opcion != 5);






}
