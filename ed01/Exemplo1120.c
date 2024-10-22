// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 double r = 0.0, v = 0.0;

 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite um valor para o raio de uma esfera: ");
    scanf ("%lf", &r);
    getchar();
    r = r*3/8;
    v = (4*(pow(r,3)*(M_PI))/3);


    printf ("\n Com o raio sendo 3/8, o volume é: %lf", v);
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
