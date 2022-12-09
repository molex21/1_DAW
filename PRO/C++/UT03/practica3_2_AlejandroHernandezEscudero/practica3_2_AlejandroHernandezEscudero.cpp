/*
 En esta práctica debemos leer un fichero de texto denominado entrada.txt que contendrá al menos 10 líneas.
 Mostraremos un menú con cuatro opciones:
 la primera debe contar el numero de líneas leídas y mostrarlo en  pantalla,
 la segunda nos pedirá una subcadena que deberemos buscar en el fichero y mostrar el numero de veces que aparece en él y el número de línea donde se encontró cada ocurrencia.
 La tercera opción debe generar un nuevo fichero denominado salida.txt que contendrá el mismo contenido del fichero entrada.txt  pero sin espacios en blanco, se mostrará por pantalla.
 Por ultimo la opción salir .
*/

#include <stdio.h>
#include <iostream>
using namespace std;
#include "practica3_2_alejandrohernandez.h"

int opcion;
string nombreFicheroEntrada = "entrada.txt";
string nombreFicheroSalida = "salida.txt";
int numeroLineasFichero;

int main()
{
    cout << "#####-----Practica 3.2 Alejandro Hernandez Escudero-----#####" << endl;

    do // mostrar menú hasta que se seleccione salir
    {

        cout << endl
             << "---------------MENU---------------" << endl;
        cout << "1. Contar el numero de lineas leidas y mostrarlo en  pantalla" << endl;
        cout << "2. Buscar una subcadena en el fichero y mostrar el numero de veces que aparece y el numero de la linea de cada ocurrencia" << endl;
        cout << "3. Generar un fichero 'salida.txt' con el contenido de 'entrada.txt' sim espacios en blanco y mostrarlo por pantalla" << endl;
        cout << "4. Salir" << endl;
        cout << endl
             << "Elige lo que deseas hacer con el fichero: ";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            numeroLineasFichero = contarLineas(nombreFicheroEntrada);
            cout << endl
                 << "En el fichero " << nombreFicheroEntrada << " hay " << numeroLineasFichero << " lineas" << endl;
            break;
        case 2:
            buscarEnFichero(nombreFicheroEntrada);
            break;
        case 3:
            generarFichero(nombreFicheroEntrada, nombreFicheroSalida);
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion no esxistente, prueba otra vez" << endl;
            break;
        }

    } while (opcion != 4);
}