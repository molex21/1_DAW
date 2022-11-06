#include <iostream>   /* Funciones de flujo de entrada-salida estándar cin y cout */
using namespace std;  /* Este nombre de espacio lo debemos meter porque muchas librerias en c++ tienen varios espacios de nombres ,
                        en este caso solo tiene uno pero aún asi hay que especificarlo  */

#ifdef _WIN32
   #include<windows.h>
#endif

int main()
{
   int fact=1;
   int a=0; 
    system("cls");  

    printf("Este programa va a calcular el factorial del número introducido\n");

    cout << "Introduzce un numero entero positivo :" ;   cin >> a ;

    for (int i = a; i > 1; i--) {
        fact = fact * i;
        }

    cout << "El factorial de " << a << " es " << fact << "\n";

    return fact;    
}