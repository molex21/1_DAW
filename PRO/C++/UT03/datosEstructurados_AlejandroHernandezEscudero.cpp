/************************************************************************************************************************************************
 Se debe realizar una aplicación que contenga un dato estructurado denominado "Familia" con los siguiente  tipos estructurados
 , Responsable1 y Responsable2, ambos del tipo persona ( Nif, nombre, apellido1 , apellido2, correo electrónico)
 y  un array de al menos 5 elementos  de otro tipo denominado descendientes que tendrá como mínimo el dni y el nombre, y fecha de nacimiento .
 Se crearán una variables de dicho tipo y la aplicación debe leerá por consola los datos de los dos responsables y al menos tres descendientes.
 Se debe  mostrar en pantalla el registro guardado de cada uno de ellos.


 QUITAR COMMENT


**************************************************************************************************************************************************/

#include <stdio.h>
#include <conio.h>
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

// Funcion para introducir los datos de cada familia
int familiasInputs(familia familiaActual)
{

    string respuesta; // Almacena la respuesta de si quiere introducir hijos
    int numHijos;     // almacena la respuesta de cuantos hijos desea intoducir

    cout << "Escribe los datos del Responsable1: \n";
    cout << "\nNIF: "; cin >> familiaActual.Responsable1.nif;
   // cout << "\nNIF: ", getline(cin, familiaActual.Responsable1.nif);
    //cout << "\nNombre: ", getline(cin, familiaActual.Responsable1.nombre);
   // cout << "\nApellido1: ", getline(cin, familiaActual.Responsable1.apellido1);
   // cout << "\nApellido2: ", getline(cin, familiaActual.Responsable1.apellido2);
    //cout << "\nEmail: ", getline(cin, familiaActual.Responsable1.email);
    cout << "\n\n";
    cout << "Escribe los datos del Responsable2: \n";
    cout << "\nNIF: ", getline(cin, familiaActual.Responsable2.nif);
    cout << "\nNombre: ", getline(cin, familiaActual.Responsable2.nombre);
    cout << "\nApellido1: ", getline(cin, familiaActual.Responsable2.apellido1);
    cout << "\nApellido2: ", getline(cin, familiaActual.Responsable2.apellido2);
    cout << "\nEmail: ", getline(cin, familiaActual.Responsable2.email);
    cout << "\n";
    cout << "\nDesea introducir hijos? (si / no): ", cin >> respuesta;

    if (respuesta == "si")
    {
        // Si se desea introducir hijos se pide el número y se rellena cada posición con dni y nombre
        cout << "\nCuantos hijos desea introducir? (Min 3 Max 5): ", cin >> numHijos;
        while ((numHijos < 3)||(numHijos>=6))
        {
            cout << "\nNumero no valido. Cuantos hijos desea introducir? (Min 3 Max 5): ", cin >> numHijos;
        }

        for (int i = 0; i < numHijos; i++)
        {
            cout << "\nIntroduce los datos del hijo " << i + 1 << ":\n";
            cout << "\nDNI: ", cin >> familiaActual.descendiente[i].dni;
            cout << "\nNombre: ", getline(cin, familiaActual.descendiente[i].nombre);
            cout << "\nFecha de nacimiento: (DD/MM/AAAA): ", cin >> familiaActual.descendiente[i].fechaNacimiento;
        }
    }else{
        cout<<"\nvalor no reconocido, omitiendo paso...\n";
    }
    return(0);
};

// Funcion para introducir los datos de cada familia
int familiasDisplay(familia familiaActualDisplay, char letraFamilia)
{
    cout << "\nCargando datos de la familia " << letraFamilia;
    //cout << "\nCargando datos de la familia :" << familiaActualDisplay;

    cout << "\nCargando datos del Representante1 :";
    cout << "\nNIF: " << familiaActualDisplay.Responsable1.nif;
    cout << "\nNombre: " << familiaActualDisplay.Responsable1.nombre;
    cout << "\nApellido1: " << familiaActualDisplay.Responsable1.apellido1;
    cout << "\nApellido2: " << familiaActualDisplay.Responsable1.apellido2;
    cout << "\nEmail: " << familiaActualDisplay.Responsable1.email;
    // Se comprueba si existen hijos y si lo hace se muestran los datos de cada uno, si no existen se muestra un mensaje
    if (!familiaActualDisplay.descendiente[0].dni)
    {
        cout << "\nSin hijos: ";
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {

            if (familiaActualDisplay.descendiente[i].dni)
            {
                cout << "\n\nDatos del hijo " << i + 1 << ": ";
                cout << "\nDNI: " << familiaActualDisplay.descendiente[i].dni;
                cout << "\nNombre: " << familiaActualDisplay.descendiente[i].nombre;
                cout << "\nNombre: " << familiaActualDisplay.descendiente[i].fechaNacimiento;
            }
        }
    }
};


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
            int fam = familiasInputs(a);
cout >> fam;
            break;
        case 2:
            familiasInputs(b);
            break;
        default:
            familiasInputs(c);
            break;
        }
    }

    /*     COMENTADOOOO
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
            }*/

    // Bucle que permite mostrar individualmente los datos de cada pesona hasta que el usuario salga dal programa
    while (!salir)
    {
        cout << "\n\nEscribe a, b o c dependiendo de la persona de la que desees ver la informacion y cualquier otra cosa para salir del programa: ", cin >> valor;
        switch (valor)
        {
        case 'a':
            familiasDisplay(a, valor);
            break;

        case 'b':
            familiasDisplay(b, valor);
            break;

        case 'c':
            familiasDisplay(c, valor);
            break;

        default:
            salir = true;
            cout << "\nSaliendo...\n";
            break;
        }
    }
}