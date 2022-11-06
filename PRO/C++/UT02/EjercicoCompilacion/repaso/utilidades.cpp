

#include <string.h>  


        
        int division(int a, int b)
        {
            return (a / b);
        }



        int longitud(char *cadena)
        {
            int len = 0;
            for(int i=0; ; i++)
            {
                if(cadena[ i ] == '\0')
                break;
                
                len ++;
            }
            return len;
        }


        int es_palindroma(char *cadena)
        {
        int i;
        char invertida[50];

        /* Halla la cadena invertida */
        for(i=0; i < longitud(cadena); i++)
                invertida[ i ] = cadena[longitud(cadena)-i-1];

        /* Coloca caracter de fin de cadena */
        invertida[ i ] = '\0';

        /* Realiza la comparacion */
        if(!strcmp(cadena, invertida))
            return 1; /* es un palindromo */
                
        return 0;  /* no es un palindromo */
        }
        





