/************************************************************************************************************************************************
 Se debe realizar una aplicación que contenga un dato estructurado denominado "Familia" con los siguiente  tipos estructurados
 , Responsable1 y Responsable2, ambos del tipo persona ( Nif, nombre, apellido1 , apellido2, correo electrónico)
 y  un array de al menos 5 elementos  de otro tipo denominado descendientes que tendrá como mínimo el dni y el nombre, y fecha de nacimiento .
 Se crearán una variables de dicho tipo y la aplicación debe leerá por consola los datos de los dos responsables y al menos tres descendientes.
 Se debe  mostrar en pantalla el registro guardado de cada uno de ellos.

**************************************************************************************************************************************************/
#include "misfunciones.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;



familia a, b, c;

bool salir = false; // Variable usada para salir del bucle que permite ver los datos de cada persona
char valor;         // Almacena la respuesta de que persona se desea mostrar

int main()
{
    // Bucle que pide los datos de las 3 personas dependiendo del contador se introducen en cada persona
    for (int i = 1; i <= 3; i++)
    {
        cout << "\nIntroduce los datos de la familia " << i << ":\n";
        switch (i) // cada ciclo del bucle se llama a la fución responsable de almacenar los inputs de los datos de las familias
        {
        case 1:
            familiasInputs(&a);
            break;
        case 2:
            familiasInputs(&b);
            break;
        default:
            familiasInputs(&c);
            break;
        }
    }

    // Bucle que permite mostrar individualmente los datos de cada pesona hasta que el usuario salga dal programa
    while (!salir)
    {
        cout << "\n\nEscribe a, b o c dependiendo de la persona de la que desees ver la informacion y cualquier otra cosa para salir del programa: ", cin >> valor;
        switch (valor)
        {
        case 'a':
            familiasDisplay(&a, &valor);
            break;

        case 'b':
            familiasDisplay(&b, &valor);
            break;

        case 'c':
            familiasDisplay(&c, &valor);
            break;

        default:
            salir = true;
            cout << "\nSaliendo...\n";
            break;
        }
    }
}