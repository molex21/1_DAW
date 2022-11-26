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

bool salir = false; // variable para salir del programa
int opcion;         // variable para guardar la seleccioón del usuario en el menú
cita citaEnCurso;
cola colaMedico;
int cargar_cita;


int main()
{

    cout << "#####-----Proyecto1 Alejandro Hernandez Escudero-----#####" << endl << endl;
    do
    {
        
        mostrarCola(&colaMedico);
         
        //mostrar menu
        cout << endl << "#####-----MENU-----#####" << endl;
        cout << "1. Cargar cita" << endl;
        cout << "2. Eliminar cita" << endl;
        cout << "3. Mover cita" << endl;
        cout << "4. Salir" << endl;
        cout << "########################" << endl << endl;
        cout << "Elija una opcion: ", cin >> opcion;  //obtener la opcion

        switch (opcion)
        {
        case 1:
            cargar_cita=cargarCita(&colaMedico);
            system("cls");
            if (cargar_cita == 0)
            {
                cout<<"Cita creada correctamente"<< endl ;
            }
            else
            {
                cout<<"Error en la creación de cita"<< endl ;
            }
            
            break;

        case 2:
            eliminarCita();
            system("cls");
            break;

        case 3:
            moverCita();
            system("cls");
            break;

        case 4:
            cout << "Saliendo..."<< endl;
            salir = true;
            break;

        default:
            cout << "La opcion seleccionada no se encuentra, pruebe otra vez."<< endl;
            break;
        }




    } while (salir == false);
}

