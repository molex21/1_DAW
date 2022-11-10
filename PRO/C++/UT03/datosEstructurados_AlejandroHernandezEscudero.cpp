/*
 Se debe realizar una aplicación que contenga un dato estructurado denominado persona con los siguiente campos :
  Nif, nombre, apellido1 , apellido2, correo electrónico y un array de otro tipo denominado descencientes que tendrá como
  mínimo el dni y el nombre. Se crearán una variables de dicho tipo y la aplicación debe leerá por consola los datos de la
  personas y al menos tres descendientes.Se debe   mostrar en pantalla el registro guardado de cada uno de ellos.
*/


/*
Falta hacer una funcion para automatizar la toma de valores para las personas y solucionar valores incorrectos por tipo de variable.
*/ 

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

// Declaración de dato estructurado persona
struct hijo
{
    int dni;
    string nombre;
};

// Declaración de dato estructurado persona
struct persona
{
    char nif[9];
    char apellido1[20];
    char apellido2[20];
    string email;
    hijo descendiente[3]{NULL};
};

/*
void personasInputs(int opcion) {
   char seleccionado;
   if (opcion == 1)
   {
    seleccionado = 'a';

   }
   else if (opcion == 2)
   {
    seleccionado = 'b';
   }
   else
   {
    seleccionado = 'c';
   }
cout << "NIF: ", cin >> seleccionado.nif;


}
*/

int main()
{
    persona a, b, c;
    string respuesta;   // almacena la respuesta de si quiere introducir hijos
    int numHijos;       // almacena la respuesta de cuantos hijos desea intoducir
    char valor;         // almacena la respuesta de que persona se desea mostrar
    bool salir = false; // Variable usada para salir del bucle que permite ver los datos de cada persona

    // Bucle que pide los datos de las 3 personas dependiendo del contador se introducen en cada persona
    for (int i = 1; i <= 3; i++)
    {

        cout << "\nIntroduce los datos de la persona " << i << ":\n";
        if (i == 1)
        {
            cout << "NIF: ", cin >> a.nif;
            cout << "Apellido1: ", cin >> a.apellido1;
            cout << "Apellido2: ", cin >> a.apellido2;
            cout << "Email: ", cin >> a.email;
            cout << "\nDesea introducir hijos? (si / no): ", cin >> respuesta;
            if (respuesta == "si")
            {
                // Si se desea introducir hijos se pide el número y se rellena cada posición con dni y nombre
                cout << "\nCuantos hijos desea introducir? (maximo 3): ", cin >> numHijos;
                while (4 > numHijos <= 0)
                {
                    cout << "\nNumero no valido. Cuantos hijos desea introducir? (maximo 3): ", cin >> numHijos;
                }

                for (int i = 0; i < numHijos; i++)
                {
                    cout << "\nIntroduce los datos del hijo " << i + 1 << ":\n";
                    cout << "DNI: ", cin >> a.descendiente[i].dni;
                    cout << "Email: ", cin >> a.descendiente[i].nombre;
                }
            }
        }
        else if (i == 2)
        {
            cout << "NIF: ", cin >> b.nif;
            cout << "Apellido1: ", cin >> b.apellido1;
            cout << "Apellido2: ", cin >> b.apellido2;
            cout << "Email: ", cin >> b.email;
            cout << "\nDesea introducir hijos? (si / no): ", cin >> respuesta;
            if (respuesta == "si")
            {
                cout << "\nCuantos hijos desea introducir? (maximo 3): ", cin >> numHijos;
                while (4 > numHijos <= 0)
                {
                    cout << "\nNumero no valido. Cuantos hijos desea introducir? (maximo 3): ", cin >> numHijos;
                }

                for (int i = 0; i < numHijos; i++)
                {
                    cout << "\nIntroduce los datos del hijo " << i + 1 << ":\n";
                    cout << "DNI: ", cin >> b.descendiente[i].dni;
                    cout << "Email: ", cin >> b.descendiente[i].nombre;
                }
            }
        }
        else
        {
            cout << "NIF: ", cin >> c.nif;
            cout << "Apellido1: ", cin >> c.apellido1;
            cout << "Apellido2: ", cin >> c.apellido2;
            cout << "Email: ", cin >> c.email;
            cout << "\nDesea introducir hijos? (si / no): ", cin >> respuesta;
            if (respuesta == "si")
            {
                cout << "\nCuantos hijos desea introducir? (maximo 3): ", cin >> numHijos;
                while (4 > numHijos <= 0)
                {
                    cout << "\nNumero no valido. Cuantos hijos desea introducir? (maximo 3): ", cin >> numHijos;
                }

                for (int i = 0; i < numHijos; i++)
                {
                    cout << "\nIntroduce los datos del hijo " << i + 1 << ":\n";
                    cout << "DNI: ", cin >> c.descendiente[i].dni;
                    cout << "Email: ", cin >> c.descendiente[i].nombre;
                }
            }
        }
    }

    // Bucle que permite mostrar individualmente los datos de cada pesona hasta que el usuario salga dal programa
    while (!salir)
    {
        cout << "\nEscribe a, b o c dependiendo de la persona de la que desees ver la informacion y cualquier otra cosa para salir del programa: ", cin >> valor;
        switch (valor)
        {
        case 'a':
            cout << "NIF: " << a.nif;
            cout << "\nApellido1: " << a.apellido1;
            cout << "\nApellido2: " << a.apellido2;
            cout << "\nEmail: " << a.email;
            for (int i = 0; i < 3; i++)
            {
                // Se comprueba si existen hijos y si lo hace se muestran los datos de cada uno, si no existen se muestra un mensaje
                if (a.descendiente[i].dni)
                {
                    cout << "\n\nDatos del hijo " << i + 1 << " son: ";
                    cout << "\nDNI: " << a.descendiente[i].dni;
                    cout << "\nNomnbre: " << a.descendiente[i].nombre;
                }
                else
                {
                    cout << "\nSin hijos: ";
                }
            }
            break;

        case 'b':
            cout << "NIF: " << b.nif;
            cout << "\nApellido1: " << b.apellido1;
            cout << "\nApellido2: " << b.apellido2;
            cout << "\nEmail: " << b.email;
            for (int i = 0; i < 3; i++)
            {
                if (b.descendiente[i].dni)
                {
                    cout << "\n\nDatos del hijo " << i + 1 << " : ";
                    cout << "\nDNI: " << b.descendiente[i].dni;
                    cout << "\nNomnbre: " << b.descendiente[i].nombre;
                }
                else
                {
                    cout << "\nSin hijos: ";
                }
            }
            break;

        case 'c':
            cout << "NIF: " << c.nif;
            cout << "\nApellido1: " << c.apellido1;
            cout << "\nApellido2: " << c.apellido2;
            cout << "\nEmail: " << c.email;
            for (int i = 0; i < 3; i++)
            {
                if (c.descendiente[i].dni)
                {
                    cout << "\n\nDatos del hijo " << i + 1 << " son: ";
                    cout << "\nDNI: " << c.descendiente[i].dni;
                    cout << "\nNomnbre: " << c.descendiente[i].nombre;
                }
                else
                {
                    cout << "\nSin hijos: ";
                }
            }
            break;

        default:
            salir = true;
            break;
        }
    }
}