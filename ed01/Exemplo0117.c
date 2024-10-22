// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 double x = 0.0, v = 0.0;

 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite um valor para o lado de um cubo:");
    scanf ("%lf", &x);
    getchar();
    x = x/6;
    v = pow(x,3);

    printf ("\n Com o lado sendo 1/6 disso, o volume é: %lf", v );
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
