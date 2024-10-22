// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 int b = 0;
 int h = 0;
 double hPor5 = 0;
 double area = 0;
 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite dois valores para a base e altura de un triângulo:");
    scanf ("%i %i", &b, &h);
    hPor5 = (double)h/5;
    area = (double)(b*hPor5)/2;
    getchar();
     printf ("\n h/5 = %lf . Area com h/5 = %lf", hPor5, area );
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
