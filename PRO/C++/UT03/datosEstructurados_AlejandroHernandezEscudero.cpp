/*
Se debe realizar una aplicación que contenga un dato estructurado denominado persona con los siguiente campos : 
Nif, nombre, apellido1 , apellido2  y correo electrónico. Se crearán tres variables de dicho tipo y la aplicación 
debe leer por consola los datos de las tres persona y  mostrar en pantalla el registro guardado de cada uno de ellos.
*/

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    struct persona
    {
        string nif[7];
        string apellido1;
        string apellido2;
        string email;
    };
    
}