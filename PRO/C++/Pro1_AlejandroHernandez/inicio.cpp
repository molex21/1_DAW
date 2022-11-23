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
#include <conio.h>
#include <iostream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif
#include "pro1_alejandrohernandez.h"


int main()
{
    
}