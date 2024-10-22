// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 int x = 0;
 int y = 0;
 int areaPor3 = 0;
 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite dois valores diferentes para os lados de um retângulo:");
    scanf ("%i %i", &x, &y);
    getchar();
    areaPor3 = x*y/3;
     printf ("\n1/3 da área deste retângulo seria de %i", areaPor3);
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
