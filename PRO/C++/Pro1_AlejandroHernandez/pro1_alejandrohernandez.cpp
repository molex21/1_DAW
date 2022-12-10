#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <time.h>
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
    time_t tiempo;
    int posicion = 0;
};

struct cola
{
    cita citas[15];
    int longActual = 0;
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
    auxiliar.tiempo = citaModificar->tiempo;
    auxiliar.posicion = posicionNueva + 1;
    return (auxiliar);
}

// funcion para mostrar la cita actual en pantalla
cita mostrarCitaEnCurso(cola *cola, cita *citaEnCurso, cita *previoUrgencia)
{
    int longitudCola = cola->longActual;
    int numcita = 1;
    cita CitaEnCurso;
    cita citaAux;

    if (citaEnCurso->posicion != 1 && previoUrgencia->paciente.nif) // si existia alguien en la consulta antes de la entrada de una urgencia tiene preferencia de entrada
    {
        CitaEnCurso.motivo = previoUrgencia->motivo;
        CitaEnCurso.paciente = previoUrgencia->paciente;
        CitaEnCurso.posicion = previoUrgencia->posicion;
        CitaEnCurso.tiempo = (previoUrgencia->tiempo + time(NULL) + 5); // le dejo el timepo que le quedaba de consulta más 5 segundos para que continue la consulta
        previoUrgencia->paciente.nif = NULL;                            // establezco la variable auxiliar a vacía para que no entre más en el if
                                                                        // mostrar por pantalla la cita en consulta
        cout << "###-----Cita en consulta-----###" << endl
             << endl;

        cout << "[ NIF: " << CitaEnCurso.paciente.nif << " -> Motivo: " << CitaEnCurso.motivo << " ]";

        cout << endl
             << endl
             << "################################" << endl
             << endl
             << endl;

        return CitaEnCurso;
    }
    else
    {
        // entra cuando hay 1 y se recarga
        if (longitudCola > 0 && citaEnCurso->posicion != 1) // Si la cola esta llena y la cita está terminada (posición = 0) -> pasa la primera posicion de la cola a cita en curso
                                                            // Uso la posición como "booleano" para determianr si la cita que se encuentra en curso se ha terminado o no, siendo 1 que está en curso y todo lo demás que no lo está
        {
            CitaEnCurso = cargarAux(&cola->citas[0], 0);          // paso a la funcion la posicion 0 porque dentro de la funcion se suma 1 a la posición
            CitaEnCurso.tiempo = time(NULL) + CitaEnCurso.tiempo; // le establezco el tienpo con el timer a la cita en curso

            for (int i = numcita; i <= longitudCola; i++) // se realizan las siquientes fucnionalidades desde la cita posterir a la que se quiere eliminar hasta la última cita registrada
            {
                citaAux = cargarAux(&cola->citas[i], i - 1); // llamo a la fucnion de cargar una cita auxiliar y como parametros le paso la cita que deseo copiar con la nueva posición que debe tener
                cola->citas[i - 1] = citaAux;                // se introduce la cita auxiliar en la posición de la que se quería eliminar
            }

            cola->longActual = longitudCola - 1; // establezco la longitud a la total menos uno para no mostrar la ultima

            // mostrar por pantalla la cita en consulta
            cout << "###-----Cita en consulta-----###" << endl
                 << endl;

            cout << "[ NIF: " << CitaEnCurso.paciente.nif << " -> Motivo: " << CitaEnCurso.motivo << " ]";

            cout << endl
                 << endl
                 << "################################" << endl
                 << endl
                 << endl;

            return CitaEnCurso;
        }
        else if (longitudCola > 0 && citaEnCurso->posicion == 1) // si la cola está llena y la cita está en curso -> muestra cita en curso
        {
            CitaEnCurso = *citaEnCurso;
            cout << "###-----Cita en consulta-----###" << endl
                 << endl;

            cout << "[ NIF: " << CitaEnCurso.paciente.nif << " -> Motivo: " << CitaEnCurso.motivo << " ]";

            cout << endl
                 << endl
                 << "################################" << endl
                 << endl
                 << endl;
            return CitaEnCurso;
        }
        else if (longitudCola == 0 && citaEnCurso->posicion == 1) // la cola está vacía pero la cita actual está en curso -> muestra cita en curso
        {
            CitaEnCurso = *citaEnCurso;
            cout << "###-----Cita en consulta-----###" << endl
                 << endl;

            cout << "[ NIF: " << CitaEnCurso.paciente.nif << " -> Motivo: " << CitaEnCurso.motivo << " ]";

            cout << endl
                 << endl
                 << "################################" << endl
                 << endl
                 << endl;
            return CitaEnCurso;
        }

        else // muestra cita vacia
        {
            cout << "###-----Cita en consulta-----###" << endl
                 << endl;
            cout << "No hay ninguna cita en consulta" << endl;
            cout << endl
                 << "#################################" << endl
                 << endl
                 << endl;
        }
    }
};

// funcion para seleccionar el motivo de la consulta
string motivoConsulta()
{
    int opcion;
    bool salir = false;
    string motivo;

    do
    {
        cout << endl
             << "----Elija un motivo de consulta----" << endl;
        cout << "1. Fractura (30s)" << endl;
        cout << "2. Dolor (20s)" << endl;
        cout << "3. Resfriado (10s)" << endl;
        cout << "4. Revision (15s)" << endl;
        cout << "5. Urgencia (30s)" << endl;
        cout << "6. Otro (15s)" << endl;
        cout << "########################" << endl
             << endl;
        cout << "Elija una opcion: ", cin >> opcion; // obtener la opcion

        switch (opcion)
        {
        case 1:
            return ("1");
            break;

        case 2:
            return ("2");
            break;

        case 3:
            return ("3");
            break;

        case 4:
            return ("4");
            break;

        case 5:
            return ("5");
            break;

        case 6:
            cout << endl
                 << "Escriba una breve descripcion del motivo de consulta: ",
                cin >> motivo;
            motivo = "6" + motivo; // para que no de fallo la conversion de string a entero añado un 6 al principio que luego quito al introducir el motivo
            return (motivo);
            break;

        default:
            cout << endl
                 << "Opcion no valida: " << endl;
        }
        salir == true;
    } while (salir == false);
}

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

int llenarCita(cola *cola1, int posicion, string MotivoConsulta) // funcion que llena la cita actual, primero llama a otra que se encarga de cargar los datos del usuario
{
    int tiempoConsulta = 0;
    llenarUsuario(&cola1->citas[posicion].paciente);

    // para controlar si quiero que el usuario introduzca el motivo le paso "x" a la funcion, si no le paso directamente el motivo que me interese
    if (MotivoConsulta == "x")
    {
        MotivoConsulta = motivoConsulta();
    }
    else
    {
        MotivoConsulta = "5"; // entra una urgencia
    }

    switch (stoi(MotivoConsulta)) // convierto el string a entero si se trata de un número
    {
    case 1:
        MotivoConsulta = "Fractura";
        tiempoConsulta = 30;
        break;

    case 2:
        MotivoConsulta = "Dolor";
        tiempoConsulta = 20;
        break;

    case 3:
        MotivoConsulta = "Resfriado";
        tiempoConsulta = 10;
        break;

    case 4:
        MotivoConsulta = "Revision";
        tiempoConsulta = 15;
        break;

    case 5:
        MotivoConsulta = "Urgencia";
        tiempoConsulta = 30;
        break;

    default:
        MotivoConsulta.erase(0, 1); // elimino el 6 del motivo
        tiempoConsulta = 15;
        break;
    }

    cola1->citas[posicion].motivo = MotivoConsulta;
    cola1->citas[posicion].tiempo = tiempoConsulta;
    cola1->citas[posicion].posicion = posicion + 1;
};

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
                llenarCita(cola1, longitud, "x");
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

// FUNCIONES PRINCIPALES
int cargarCita(cola *cola)
{
    int longitud = cola->longActual;

    if (longitud < 15)
    {
        llenarCita(cola, longitud, "x");
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
        if (numcita <= longitudCola) // si la cita existe
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
            return (2);
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

cita entradaUrgencia(cita *citaEnCurso)
{
    cita auxiliarCopiaCitaEnCurso;

    // cargo la cita auxiliar con los datos de la cita en curso
    auxiliarCopiaCitaEnCurso.motivo = citaEnCurso->motivo;
    auxiliarCopiaCitaEnCurso.paciente = citaEnCurso->paciente;
    auxiliarCopiaCitaEnCurso.posicion = citaEnCurso->posicion;
    auxiliarCopiaCitaEnCurso.tiempo = (citaEnCurso->tiempo - time(NULL)); // guardo el tiempo que le quedaba

    cout << "\nIntroduce el NIF del paciente: ", cin >> citaEnCurso->paciente.nif;
    cin.ignore(); // error al pulsar el enter salta la inserción del dato siguiente
    cout << "Introduce el nombre del paciente: ", getline(cin, citaEnCurso->paciente.nombre);
    cout << "Introduce el apellido del paciente: ", getline(cin, citaEnCurso->paciente.apellidos);
    citaEnCurso->motivo = "5";
    citaEnCurso->tiempo = time(NULL) + 30;
    citaEnCurso->posicion = 1;

    return auxiliarCopiaCitaEnCurso;
}

bool timer(time_t *objetivo)
{
    bool citaCumplida = false; // variable booleana para saber si la cita en curso terminó
    time_t tiempo_actual;      // variable para almacenar el valor del timepo actual

    // timer pasra contar los segundos
    if (*objetivo == 0)
    {
        *objetivo = time(NULL); // cargo el tiempo actual si e tiempo está en 0
    }
    tiempo_actual = time(NULL);

    if (*objetivo <= tiempo_actual) // si el timpo de cita es menor al timempo actual significa que ha terminado y cambio el valor de la cita enc urso para que se cambie por otra
    {
        citaCumplida = true;
        return (citaCumplida);
    }
    return (citaCumplida);
}
