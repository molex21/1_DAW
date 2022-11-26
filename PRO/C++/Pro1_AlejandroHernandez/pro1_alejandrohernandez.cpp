#include <stdio.h>
#include <iostream>
using namespace std;

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
      for (int i = 0; i < longitudMostrar; i++)
      {
        if (i==0)
        {
            cout<<"[ " << mostrarCola->citas[i].posicion << ". " << mostrarCola->citas[i].paciente.nif << " ]";
        }else
        {
            cout<<" - [ " << mostrarCola->citas[i].posicion << ". " << mostrarCola->citas[i].paciente.nif << " ]";
        }
        
        
      }
        
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
    cout << endl <<"posicionAFTER"<<cola1->citas[posicion].posicion << endl;
};

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

int eliminarCita(){};

int moverCita(){};

/*hay espacio?

esta llena o vacía

introducir datos en un nodo ausiliar

donde se quiere colar

mover todo para atrás y dejar el hueco
mater nodo uauxiliar

array-> tipo de dato que lo contenga, posicion y longitud
*/