// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 double r = 0.0, a = 0.0;

 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite um valor para o raio de um círculo: ");
    scanf ("%lf", &r);
    getchar();
    r = r/2;
    a = pow(r,2)*(M_PI);


    printf ("\n Com os lados sendo metade, a área é: %lf", a);
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
