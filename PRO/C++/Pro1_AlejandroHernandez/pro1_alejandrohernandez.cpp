#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif

struct usuario
{
    int nif;
    string nombre;
    string apellidos;
};

struct cita
{
    usuario paciente;
    string motivo;
    int tiempo;
    int posicion = 0;
};

struct cola
{
    cita citas[15];
    int longActual = 0;
};

// funcion para mostrar la cola
void mostrarCola(cola *mostrarCola)
{
    int longitudMostrar = mostrarCola->longActual;

    if (longitudMostrar > 0)
    {
        cout << "######################-----Cola en tiempo real-----######################" << endl
             << endl;
        for (int i = 0; i < longitudMostrar; i++)
        {
            if (i == 0)
            {
                cout << "[ " << mostrarCola->citas[i].posicion << ". " << mostrarCola->citas[i].paciente.nif << " ]";
            }
            else
            {
                cout << " - [ " << mostrarCola->citas[i].posicion << ". " << mostrarCola->citas[i].paciente.nif << " ]";
            }
        }
        cout << endl
             << endl
             << "#########################################################################" << endl;
    }
    else
    {
        cout << "######################-----Cola en tiempo real-----######################" << endl
             << endl;
        cout << "-------------------------------Cola vacia-------------------------------" << endl;
        cout << endl
             << "#########################################################################" << endl;
    }
};

int llenarUsuario(usuario *usuarioActual) // funcion encargada de cargar los datos del usuario
{
    cout << "\nIntroduce el NIF del paciente: ", cin >> usuarioActual->nif;
    cin.ignore(); // error al pulsar el enter salta la inserción del dato siguiente
    cout << "Introduce el nombre del paciente: ", getline(cin, usuarioActual->nombre);
    cout << "Introduce el apellido del paciente: ", getline(cin, usuarioActual->apellidos);
};

int llenarCita(cola *cola1, int posicion) // funcion que llena la cita actual, primero llama a otra que se envarga de cargar los datos del usuario
{
    llenarUsuario(&cola1->citas[posicion].paciente);
    cout << "Introduce el motivo: ", getline(cin, cola1->citas[posicion].motivo);
    cola1->citas[posicion].posicion = posicion + 1;
};

// funcion para cargar una variable auxiliar
cita cargarAux(cita *citaModificar, int posicionNueva)
{
    // coio la cita que recibe la función y le cambio la posición por la nueva sopición que desea que tenga
    cita auxiliar;
    auxiliar.paciente.nif = citaModificar->paciente.nif;
    auxiliar.paciente.nombre = citaModificar->paciente.nif;
    auxiliar.paciente.apellidos = citaModificar->paciente.apellidos;
    auxiliar.motivo = citaModificar->motivo;
    auxiliar.motivo = citaModificar->motivo;
    auxiliar.posicion = posicionNueva + 1;
    return (auxiliar);
}

// funcion intercambiar posiciones de la cola
int moverPosiciones(cola *cola1, int pos1, int pos2)
{
    if (cola1->longActual > 1) // si la cola tiene al menos dos elementos
    {
        if (pos1 <= cola1->longActual && pos2 <= cola1->longActual) // comprobación que los elementos a intercambiar son válidos
        {
            cita aux1;
            cita aux2;

            aux1 = cargarAux(&cola1->citas[pos2 - 1], pos1 - 1); // llamo a la funcion de cargar cita auziliar para almacenar cada una de las citas con su posición correspondiente
            aux2 = cargarAux(&cola1->citas[pos1 - 1], pos2 - 1);

            cola1->citas[pos2 - 1] = aux2; // sobreescribo las citas auxiliares en la posición que corresponde
            cola1->citas[pos1 - 1] = aux1;
            return (0);
        }
        else
        {
            return (2);
        }
    }
    else
    {
        return (1);
    }
};

// funcion colar a un amigo
int colarAmigo(cola *cola1)
{
    int opcion; // variable para almacenar la opcion que elija el usuario
    int longitud = cola1->longActual;
    do
    {
        cout << endl
             << "1. Crear cita nueva para amigo" << endl;
        cout << "2. Colar a un amigo con cita" << endl;
        cout << "Elija una opcion: ", cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            if (longitud >= 15) // si la cola está llena
            {
                return (1);
            }
            else // si la cola no está llena creo una cita nueva y la pongo en la primera posicon
            {
                int posAmigo;
                llenarCita(cola1, longitud);
                cola1->longActual = longitud + 1;
                posAmigo = longitud + 1;
                while (posAmigo != 1) // mientras no se llegue al principio de la cola
                {
                    moverPosiciones(cola1, posAmigo - 1, posAmigo); // mueve el amigo un ouesto hacia alante
                    posAmigo--;                                     // decrementa la variable contador que determina la posicion del amigo
                }

                return (0);
            }
            break;
        }
        case 2:
        {
            int numAmigo;
            int longitud = cola1->longActual;
            cout << endl
                 << "Escriba la posicion de su amigo: ",
                cin >> numAmigo;
            if (numAmigo <= longitud) // si la posición es menor o igual a la longitud maxima existe el amigo que se desea colar
            {
                while (numAmigo != 1) // mientras no se llegue al principio de la cola
                {
                    moverPosiciones(cola1, numAmigo - 1, numAmigo); // mueve el amigo un ouesto hacia alante
                    numAmigo--;                                     // decrementa la variable contador que determina la posicion del amigo
                }
                return (0);
            }
            else
            {
                return (3);
            }

            break;
        }
        default:
        {
            cout << endl
                 << "Opcion no valida, pruebe otra vez: " << endl;
            break;
        }
        }
    } while (opcion != 1 || opcion != 2);
};

// FUNCIONES PRINCIPALES A LAS QUE EL .h TIENE ACCESO
int cargarCita(cola *cola)
{
    int longitud = cola->longActual;

    if (longitud < 15)
    {
        llenarCita(cola, longitud);
        cola->longActual = longitud + 1;
        return (0);
    }
    else
    {
        return (1);
    }
};

int eliminarCita(cola *cola)
{
    int longitud = cola->longActual;

    if (longitud > 0) // si existen citas par eliminar se procede a eliminar
    {
        cita citaAux; // declaración de cita auxiliar
        int numcita;  // variable que almacena el numero de cita que se desea eliminar
        int longitudCola = cola->longActual;

        cout << "Escriba el numero de la cita que deasea eliminar: ", cin >> numcita;
        if (numcita<=longitudCola)//si la cita existe
        {
                    
        for (int i = numcita; i < longitudCola; i++) // se realizan las siquientes fucnionalidades desde la cita posterir a la que se quiere eliminar hasta la última cita registrada
        {
            citaAux = cargarAux(&cola->citas[i], numcita - 1); // llamo a la fucnion de cargar una cita auxiliar y como parametros le paso la cita que deseo copiar con la nueva posición que debe tener
            cola->citas[numcita - 1] = citaAux;                // se introduce la cita auziliar en la posición de la que se quería eliminar
        }

        cola->longActual = longitudCola - 1; // establezco la longitud a la total menos uno para no mostrar la ultima
        return (0);
        }
        else
        {
            return(2);
        }
    }
    else // si no existen citas se informa al usuario
    {
        return (1);
    }
};

int moverCita(cola *cola)
{
    int opcion; // variable para almacenar la opcion que elija el usuario
    int mover_posiciones;
    int colar_amigo;
    do
    {
        cout << endl
             << "1. Intercambiar cita" << endl;
        cout << "2. Colar a un amigo" << endl;
        cout << "Elija una opcion: ", cin >> opcion;

        switch (opcion)
        {
        case 1:
            int pos1;
            int pos2;
            cout << endl
                 << "Elija la posicion1 que desea intercambiar: ",
                cin >> pos1;
            cout << endl
                 << "Elija la posicion2 que desea intercambiar: ",
                cin >> pos2;
            mover_posiciones = moverPosiciones(cola, pos1, pos2);
            if (mover_posiciones == 0)
            {
                return (0);
                break;
            }
            else if (mover_posiciones == 1)
            {
                return (1);

                break;
            }
            else if (mover_posiciones == 2)
            {
                return (2);
                break;
            }

        case 2:
            colar_amigo = colarAmigo(cola);
            if (colar_amigo == 0)
            {
                return (0);
                break;
            }
            else if (colar_amigo == 1)
            {
                return (2);

                break;
            }
            else if (colar_amigo == 3)
            {
                return (3);
                break;
            }
            break;

        default:
            cout << endl
                 << "Opcion no valida, pruebe otra vez: " << endl;
            break;
        }

    } while (opcion != 1 || opcion != 2);
};

/*hay espacio?

esta llena o vacía

introducir datos en un nodo ausiliar

donde se quiere colar

mover todo para atrás y dejar el hueco
mater nodo uauxiliar

array-> tipo de dato que lo contenga, posicion y longitud
*/