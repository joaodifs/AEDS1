// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 double c = 0.0, h = 0.0, L = 0.0, v = 0.0;

 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite um valor para o comprimento, altura e largura de um paralelepípedo: ");
    scanf ("%lf %lf %lf", &c, &h, &L);
    getchar();
    c = c*6;
    L = L*6;
    h = h*6;
    v = c*h*L;

    printf ("\n Com os lados sendo 6x maior, o volume é: %lf", v );
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
