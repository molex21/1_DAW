/*
Realizar un programa en c++ que pida dos numero de entrada y muestre el resultado despues de llamar a la función divide que recibe dos parámetros tipo string,  float divide(string a, string b) . Como sabemos dos strings no se pueden dividir matemáticamente, debemos convertirlos a float.  (Conversión de tipos).

Además se debe validar las siguientes excepciones:

El divisor no puede ser menor o igual que cero.

El dividendo no puede ser  menor o igual a cero.

Esta parte se debe hacer con el control de excepciones Try - throw - Catch.

Como la función divide recibe dos string, podemos hacer el control de excepciones con dos catch, utilizando  , int n  y  const char &e .

El programa debe mostrar al final el resultado de la división.

*/

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif

float divide(string dividendo, string divisor)
{
    // hago la conversión de tipos
       
    float dividendo1 = stof(dividendo);
    float divisor1 = stof(divisor);
    float resultadodiv;

    try
    {
        if (divisor1 <= 0)
        {
            throw 0;
        }
        if (dividendo1 <= 0)
        {
            throw '0';
        }
    }
    catch (int error1)
    {
        cout << "El divisor debe ser mayor que 0." <<"\nNum error "<<error1;
       // cout << error1;
         exit(0);
    }
    catch (const char &error2)
    {
        cout << "El dividendo debe ser mayor que 0." <<"\nNum error "<<error2;
         exit(0);
    }

    // realizo la division
    resultadodiv = dividendo1 / divisor1;

    return (resultadodiv);
}

int main()
{
    string dividendo;
    string divisor;
    float resultado;

    cout << "Introduce un numero como string: ";
    cin >> dividendo;
    cout << "Introduce otro numero como string: ";
    cin >> divisor;
    resultado = divide(dividendo, divisor);

    cout << resultado;
}
