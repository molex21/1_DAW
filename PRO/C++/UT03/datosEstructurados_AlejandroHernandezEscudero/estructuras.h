#include <iostream>
using namespace std;

// Declaración de dato estructurado persona
struct hijo
{
    int dni;
    string nombre;
    string fechaNacimiento;
};

// Declaración de dato estructurado persona
struct persona
{
    string nif;
    string nombre;
    string apellido1;
    string apellido2;
    string email;
};

// Declaración de dato estructurado familia
struct familia
{
    persona Responsable1;
    persona Responsable2;
    hijo descendiente[5];
};