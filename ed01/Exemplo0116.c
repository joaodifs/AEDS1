// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 double x = 0.0, h = 0.0, p = 0.0, a = 0.0;

 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite um valor para o lado de um triângulo equilátero:");
    scanf ("%lf", &x);
    getchar();
    x = x/2;
    p = x+x+x;
    h = (x*(sqrt(3)))/2;
    a = (h*x)/2;
    printf ("\n Com o lado sendo metade disso, a altura é: %lf // a área é: %lf // o perímetro é: %lf", h, a, p );
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
