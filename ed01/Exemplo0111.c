// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 int x = 0;
 int area = 0;
 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite tamanho do lado do quadrado:");
    scanf ("%i", &x);
    getchar();
    area = x*x;
    printf ("\nSe o lado do quadrado é %i então 1/4 da área do quadrado é %lf ", x,(double) area/4);
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
