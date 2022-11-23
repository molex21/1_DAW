#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

struct returnTwoInt
{
    int one;
    int two;
};

int contarLineas(string nombreFicheroEntrada)
{
    string linea;
    int contador = 0;

    ifstream fichero(nombreFicheroEntrada.c_str());
    if (fichero.fail())
    {
        cout << "Fichero no encontrado";
    }

    while (!fichero.eof())
    {
        if (getline(fichero, linea))
        {
            contador++;
        };
    }

    return (contador);
};

returnTwoInt buscarEnFichero(string nombreFicheroEntrada)
{
    returnTwoInt twoInt;
    return (twoInt);
};

void generarFichero(string nombreFicheroEntrada, string nombreFicheroSalida){};
