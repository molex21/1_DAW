#include <stdio.h>   /* Funciones de entrada-salida */
#include <iostream>  /* Funciones de flujo de entrada-salida estándar cin y cout */
using namespace std; /* Este nombre de espacio lo debemos meter porque muchas librerias en c++ tienen varios espacios de nombres ,
                        en este caso solo tiene uno pero aún asi hay que especificarlo  */
#include <stdlib.h>
#include <conio.h>

#ifdef _WIN32           
   #include<windows.h>
#endif

/* El #ifdef es un comando del pre-procesador, y es una forma común de excluir o incluir partes del código 
  fuente que se entrega finalmente al compilador, de manera condicional. En este caso, el símbolo _WIN32 está 
  definido solamente en Windows y con la construcción utilizada el compilador verá, por ejmplo, la instrucción
   #include<windows.h> solo si es Windows.  En una compilación para linux, es como si esa línea del fuente no existiera.*/

#include "cabecera.hpp"
#include <utilidades.hpp>


int resta(int a  ,int b);

int suma(int a, int b) 
{
     return (a + b);
}



int  main()
{
    int opcion;
    int a=0,b=0,resultado=0;

  do {
      system("cls");  

      printf("Mi primer programa en C++\n");
      printf("\n\n\n");
      printf("\n                              MENU\n");
      printf("\n Ejecutar Factorial (Programa ejecutable en cpp).................................1\n");  //  Ejecutamos cualquier fichero ejecutable del sistema con system("nombrePrograma.exe");
      printf("\n Ejecutar suma (Definida en el bloque de declaraciones)..........................2\n");  //  Nombre de la función suma(int a , intb), definida en el propio fichero.
      printf("\n Ejecutar resta (Definida en fichero funciones.cpp)..............................3\n");  /*  Nombre de la función resta(int a , intb), definida en el fichero funciones.cpp sin la función main() y declarada, 
                                                                                                             en el fichero de inicio.cpp. Se compilan ambos por separado con opcion -c del compilador, generando dos ficheros objetos ".o",
                                                                                                             luego se linkan con  g++ -o  inicio inicio.o funciones.o  */
      printf("\n Ejecutar multiplicacion (Definida en  cabecera.h ).............................4\n");   // Nombre de la función multiplica(int a , int b), definida en el  fichero cabecera.hpp ;
      printf("\n Ejecutar division (Definida en utilidades.cpp y declarada en utilidades.h ).....5\n");   /* Nombre de la funcion division, declarada en el  espacio de nombres f_matematicas del fichero utilidades.hpp
                                                                                                             y definida en el fichero utilidades.cpp. Ambas se guardan en directorio C:\MinGW\include y la referenciamos 
                                                                                                               en inicio con #include<utilidades.hpp> y using namespace f_matematicas; */
      printf("\n Salir...........................................................................6\n");   // sale del programa.
      printf("\n"); 

      cout << "\n Selecciona una opcion: "; cin >> opcion;

      

     /* Aquí evaluamos elección realizada por el usuario, utilizo un switch-case porque son varias opciones */
     switch (opcion) {

                case 1: {
                        int a = system("factorial.exe");
                        system("cls");
                        cout << " Vuelve la funcion con el valor " << a << "\n"; 
                        break;
                    }
                case 2: {
                        
                        system("cls"); 
                       cout << "\n  introduce un numero: "; cin >> a;
                       cout <<"\n  introduce un numero: "; cin >> b ;
                        resultado = suma(a,b);
                        cout << "\n El resultado de sumar " << a  << " y " << b  << " es : " << resultado << "\n";
                       
                        break;
                    }
                case 3: {
                       
                        system("cls"); 
                        cout << ("\n introduce un numero: "); cin >> a;
                        cout << ("\n introduce un numero: "); cin >> b;
                        resultado = resta(a,b);
                        cout << "\n El resultado de restar " << a  << " menos " << b << " es " << resultado << endl;
                       
                    break;}
                case 4: {
                   
                        system("cls"); 
                        cout <<  ("\n introduce un numero: "); cin >> a;
                        cout << ("\n introduce un numero: "); cin >> b;
                        resultado = multiplica(a,b);
                       cout << "\n El resultado de Multiplicar" << a << " mas "  << b << " es: " << resultado << endl;
                       
                    break;}
                case 5: {
                     system("cls"); 
                     cout <<  ("\n introduce un numero: "); cin >> a;
                        cout << ("\n introduce un numero: "); cin >> b;
                        resultado =division(a,b);
                     cout << "\n El resultado de dividir " <<   a  << " por " << b << " es " << resultado << "\n";
                     break;    }
                default: {break;}
                }
               
         getch();
  } while (opcion != 6);
      
     

}