/*Hacer un programa que permita introducir 10 de números , y
a la salida debe imprimir el número mayor, el número menor, cantidad
 de pares, cantidad de impares y la media total de los números introducidos.*/

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif
int main()
{
    // Inicializo las variables que usaré durante la ejecucion
    int numero;
    int totalNumeros = 0;
    float media;
    int max;
    int min;
    int par = 0;
    int impar = 0;

    cout << "Escribe diez numeros a continuacion: \n";

    // Mientras que no se introduzcan 10 numeros se repetirá el bucle
    while (totalNumeros < 10)
    {
        cout << "Introduce un numero: \n";
        cin >> numero; // obtengo un valor y lo meto en la variabel numero

        if (totalNumeros == 0) // en el perimer valor que se introduce declara que es el número máximo y minimo
        {
            max = numero;
            min = numero;
        }

        totalNumeros = totalNumeros + 1; // incremento en uno la cuenta de los números para después acabar el bucle

        if ((numero % 2) == 0) // hago el modulo del número entre dos, si es 0 es par, si no es impar
        {
            par = par + 1;
        }
        else
        {
            impar = impar + 1;
        }

        if (numero >= max) // identifico si el numero actual es mayor o que el que se almacena como max, si no es lo guardo en max
        {
            max = numero;
        }
        else if (numero <= min) // identifico si el numero actual es menor o que el que se almacena como min, si no es lo guardo en min
        {
            min = numero;
        }

        media += numero; // almaceno la suma de todos los valores para efectuar la media más adelante

        cout << "El numero " << numero << " se ha registrado correctamente.\n";
    }
    media = media / 10;
    cout << "\nEl numero mayor es " << max << ".\n";
    cout << "El numero menor es " << min << ".\n";
    cout << "El la media de los numeros es " << media << ".\n";
    cout << "Hay un total de " << par << " numeros pares.\n";
    cout << "Hay un total de " << impar << " numeros impares.\n";
    
}