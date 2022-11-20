#include "estructuras.h"

// Funcion para introducir los datos de cada familia
void familiasInputs(familia *familiaActual)
{
    string respuesta; // Almacena la respuesta de si quiere introducir hijos
    int numHijos;     // almacena la respuesta de cuantos hijos desea intoducir

    cout << "Escribe los datos del Responsable1: \n";
    cout << "\nNIF: ", getline(cin, familiaActual->Responsable1.nif);
    cout << "\nNombre: ", getline(cin, familiaActual->Responsable1.nombre);
    cout << "\nApellido1: ", getline(cin, familiaActual->Responsable1.apellido1);
    cout << "\nApellido2: ", getline(cin, familiaActual->Responsable1.apellido2);
    cout << "\nEmail: ", getline(cin, familiaActual->Responsable1.email);
    cout << "\n\n";
    cout << "Escribe los datos del Responsable2: \n";
    cout << "\nNIF: ", getline(cin, familiaActual->Responsable2.nif);
    cout << "\nNombre: ", getline(cin, familiaActual->Responsable2.nombre);
    cout << "\nApellido1: ", getline(cin, familiaActual->Responsable2.apellido1);
    cout << "\nApellido2: ", getline(cin, familiaActual->Responsable2.apellido2);
    cout << "\nEmail: ", getline(cin, familiaActual->Responsable2.email);
    cout << "\n";
    cout << "\nDesea introducir hijos? (si / no): ", cin >> respuesta;

    if (respuesta == "si")
    {
        // Si se desea introducir hijos se pide el número y se rellena cada posición con dni y nombre
        cout << "\nCuantos hijos desea introducir? (Min 3 Max 5): ", cin >> numHijos;
        while ((numHijos < 3) || (numHijos >= 6))
        {
            cout << "\nNumero no valido. Cuantos hijos desea introducir? (Min 3 Max 5): ", cin >> numHijos;
        }

        for (int i = 0; i < numHijos; i++)
        {
            cout << "\nIntroduce los datos del hijo " << i + 1 << ":\n";
            cout << "\nDNI: ", cin >> familiaActual->descendiente[i].dni;
            cin.ignore(); //error al pulsar el enter salta la inserción del dato siguiente
            cout << "\nNombre: ", getline(cin, familiaActual->descendiente[i].nombre);
            cout << "\nFecha de nacimiento: (DD/MM/AAAA): ", cin >> familiaActual->descendiente[i].fechaNacimiento;
        }
    }
    else if (respuesta == "no")
    {
        cout << "\nNo desea introdicir hijos, omitiendo paso...\n";
        cin.ignore();
    }
    else
    {
        cout << "\nValor no reconocido, omitiendo paso...\n";
        cin.ignore();
    }
};

// Funcion para introducir los datos de cada familia
void familiasDisplay(familia *familiaActualDisplay, char *letraFamilia)
{
    
    cout << "\nCargando datos de la familia " << letraFamilia;
    
    //DATOS DEL REPRESENTANTE 1
    cout << "\n\n\nCargando datos del Representante1 :";
    cout << "\nNIF: " << familiaActualDisplay->Responsable1.nif;
    cout << "\nNombre: " << familiaActualDisplay->Responsable1.nombre;
    cout << "\nApellido1: " << familiaActualDisplay->Responsable1.apellido1;
    cout << "\nApellido2: " << familiaActualDisplay->Responsable1.apellido2;
    cout << "\nEmail: " << familiaActualDisplay->Responsable1.email;
    
     //DATOS DEL REPRESENTANTE 2
    cout << "\n\nCargando datos del Representante2 :";
    cout << "\nNIF: " << familiaActualDisplay->Responsable2.nif;
    cout << "\nNombre: " << familiaActualDisplay->Responsable2.nombre;
    cout << "\nApellido1: " << familiaActualDisplay->Responsable2.apellido1;
    cout << "\nApellido2: " << familiaActualDisplay->Responsable2.apellido2;
    cout << "\nEmail: " << familiaActualDisplay->Responsable2.email;


    // Se comprueba si existen hijos y si lo hace se muestran los datos de cada uno, si no existen se muestra un mensaje
    if (!familiaActualDisplay->descendiente[0].dni)
    {
        cout << "\n\nSin hijos ";
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (familiaActualDisplay->descendiente[i].dni)
            {
                cout << "\n\nDatos del hijo " << i + 1 << ": ";
                cout << "\nDNI: " << familiaActualDisplay->descendiente[i].dni;
                cout << "\nNombre: " << familiaActualDisplay->descendiente[i].nombre;
                cout << "\nNombre: " << familiaActualDisplay->descendiente[i].fechaNacimiento;
            }
        }
    }

    
};