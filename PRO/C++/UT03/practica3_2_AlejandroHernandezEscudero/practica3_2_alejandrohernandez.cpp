#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
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

void buscarEnFichero(string nombreFicheroEntrada)
{

    ifstream fichero(nombreFicheroEntrada.c_str());
    int posicion;
    string linea;
    int coincidencia;
    string busqueda;
    int contador = 0;
    int numcoincidencia = 0;
    cout << "Escribe la cadena a buscar: ";
    cin.ignore();
    getline(cin, busqueda);

    if (fichero.fail())
    {
        cout << "Fichero no encontrado";
    }
/* WHILE PREUBAS
    while (!fichero.eof()) // mientras el fichero no se acabe
    {
        
        numcoincidencia = 0;
        while (getline(fichero, linea)) // leer cada linea
        {
const string t(busqueda);

cout<<posicion<<endl;
cout<<linea.find(busqueda, posicion)<<endl;
            while ((linea.find(busqueda)) <= linea.size())
            {
                numcoincidencia++;
                cout<<linea.find(busqueda)<<endl;
                cout<<linea.size()<<endl;
                //posicion += t.size();
            }
            cout << "Se encontraron: " << numcoincidencia << " coincidencia/s en la linea " << contador << endl;
        }
    }*/
    while (!fichero.eof())//mientras el fichero no se acabe
    {
        numcoincidencia = 0;
        while (getline(fichero, linea))//leer cada linea
        {
            contador++;
            numcoincidencia++;//aumentar el contador de coincidencias
            if (linea.find(busqueda)!= 4294967295)//si existen coincidencias las muestro
            {
                cout << "Se encontraron: " << numcoincidencia << " coincidencia/s en la linea " << contador << endl;
                numcoincidencia = 0;
            }
        }
    }
};

void generarFichero(string nombreFicheroEntrada, string nombreFicheroSalida)
{
    ofstream salida(nombreFicheroSalida);
    ifstream fichero(nombreFicheroEntrada.c_str());
    string linea;
    if (salida.is_open())
    {
        if (fichero.is_open())
        {
            while (getline(fichero, linea))
            {
                linea.erase(remove_if(linea.begin(), linea.end(), ::isspace), linea.end());//eliminar el caracter si es iun espacio
                salida << linea;
            }
            fichero.close(); 
        }
        else
        {
            cout << "No se puede abrir el fichero de entrada";
        }
        salida.close(); 
    }
    else
    {
        cout << "No se puede generar el fichero";
    }
};
