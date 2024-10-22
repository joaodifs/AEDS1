// 1391532_AED1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ( void )
{
    setlocale(LC_ALL, "Portuguese_Brazil");
 // dados/resultados
 int x = 0;
 int area3 = 0;
 int perimetro3 = 0;
 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite tamanho do lado do quadrado:");
    scanf ("%i", &x);
    getchar();
    area3 = x*3*x*3;
    perimetro3 =x*4*3;
    printf ("\nUm quadrado com o lado 3x maior teria %i de área e %i de perímetro", area3, perimetro3);
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
