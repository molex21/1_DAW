/*
Se debe realizar la creación y gestión de una cola (estructura fifo). Dicha cola gestionará las
citas medicas en una consulta donde se atenderá por orden de llegada, cada una de ellas debe
contener la siguiente información, el usuario (nif, nombre y apellidos) que asiste a
consulta, el motivo de la consulta y el tiempo asignado según el motivo.
El funcionamiento será el siguiente:

1. Se deben cargar las citas según llegue el usuario con los datos nombrados anteriormente.
2. Se añadirá a la cola, en la posición que le corresponda, osea al final de ella (siempre).
3. La cola se debe auto-gestionar según el tiempo asignado a cada cita. (Máximo=30
segundos , mínimo=15 segundos ). Es decir, cuando se cumpla el tiempo de consulta, se
cogerá automáticamente al siguiente de la cola y se reordenará esta.
4. Los elementos de la cola siempre deben estar visibles en pantalla, así como el dato de la
persona que esta en consulta. Cuando se inicie el programa la consulta y la cola se mostrarán
vacías.
5. De la cola se podrán eliminar elementos de cualquier posición, con lo cual cada vez que
ocurra debe reordenarse esta.
6. El encargado de las citas podrá mover los elementos de la cola según los siguientes criterios:
a. Intercambiar posiciones entre dos elementos.
 b. “Colar a un amigo” en la posición que estime.
*/

#include <stdio.h>
#include <iostream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif
#include "pro1_alejandrohernandez.h"

time_t tiempo_inicio = 0;
bool citacumplida = false;
bool salir = false;  // variable para salir del programa
int opcion;          // variable para guardar la seleccioón del usuario en el menú
cita citaEnCurso;    // variable que almacena la cita en consulta actual
cita previoUrgencia; // variable que almacena la cita en consulta antes de la entrada de una urgencia
cola colaMedico;     // variable que almacena la cola
int cargar_cita;     // variable que recoge el resultado de la funcion de cargar cita
int eliminar_cita;   // variable que recoge el resultado de de la funcion de eliminar cita
int mover_cita;      // variable que recoge el resultado de de la funcion de mover cita

int main()
{

    system("cls");
    cout << "#####-----Proyecto1 Alejandro Hernandez Escudero-----#####" << endl
         << endl;
    do
    {

        citacumplida = timer(&citaEnCurso.tiempo);

        if (citacumplida)
        {
            citaEnCurso.posicion = 0;
        }

        // funcion para mostrar la cita en curso si contiene algun elemento
        citaEnCurso = mostrarCitaEnCurso(&colaMedico, &citaEnCurso, &previoUrgencia);

        // funcion para mostrar la cola si contiene algun elemento
        mostrarCola(&colaMedico);

        // mostrar menu
        cout << endl
             << "#####-----MENU-----#####" << endl;
        cout << "1. Cargar cita" << endl;
        cout << "2. Eliminar cita" << endl;
        cout << "3. Mover cita" << endl;
        cout << "4. Urgencia" << endl;
        cout << "5. Refrescar" << endl;
        cout << "6. Salir" << endl;
        cout << "########################" << endl
             << endl;
        cout << "Elija una opcion: ", cin >> opcion; // obtener la opcion

        switch (opcion)
        {
        case 1:
            system("cls");
            mostrarCola(&colaMedico);
            cout << endl
                 << "+++++++++  CARGAR CITA  +++++++++" << endl;
            cargar_cita = cargarCita(&colaMedico);
            system("cls");

            // mensajes al usuario dependiendo de si la fuccionalidad se ha realizado o no
            if (cargar_cita == 0)
            {
                cout << "++++Cita creada correctamente+++" << endl
                     << endl;
            }
            else
            {
                cout << "++++Error al crear la cita, cola llena++++" << endl
                     << endl;
            }
            break;

        case 2:
            system("cls");
            mostrarCola(&colaMedico);
            cout << endl
                 << "+++++++++  ELIMINAR CITA  +++++++++" << endl;
            eliminar_cita = eliminarCita(&colaMedico);
            system("cls");

            // mensajes al usuario dependiendo de si la fuccionalidad se ha realizado o no
            if (eliminar_cita == 0)
            {
                cout << "++++Cita eliminada correctamente+++" << endl
                     << endl;
            }
            else if (eliminar_cita == 2)
            {
                cout << "++++Error al eliminar la cita, la posicion elegida no existe++++" << endl
                     << endl;
            }
            else
            {
                cout << "++++Error al eliminar la cita, cola vacia++++" << endl
                     << endl;
            }
            break;

        case 3:
            system("cls");

            mostrarCola(&colaMedico);
            cout << endl
                 << "+++++++++  MOVER CITA  +++++++++" << endl;
            mover_cita = moverCita(&colaMedico);
            system("cls");
            if (mover_cita == 0)
            {
                cout << "++++Operacion realizada correctamente+++" << endl
                     << endl;
            }
            else if (mover_cita == 1)
            {
                cout << "++++Error al intercambiar la cita, la cola no posee suficientes elementos para intercambiarla++++" << endl
                     << endl;
            }
            else if (mover_cita == 2)
            {
                cout << "++++Error al intercambiar la cita, alguna de las posiciones para intercambiar no es valida++++" << endl
                     << endl;
            }
            else if (mover_cita == 3)
            {
                cout << "++++Error al colar amigo, la posicion elegida no existe++++" << endl
                     << endl;
            }
            else
            {
                cout << "++++Error al colar amigo, la cola se encuentra llena++++" << endl
                     << endl;
            }

            break;

        case 4:
            previoUrgencia = entradaUrgencia(&citaEnCurso);
            break;

        case 5:

            break;

        case 6:
            cout << "Saliendo..." << endl;
            salir = true;
            break;

        default:
            cout << endl
                 << "La opcion seleccionada no se encuentra, pruebe otra vez." << endl;
            break;
        }
    } while (salir == false);
}
