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
 int area = 0;
 int perimetro = 0;
 // identificar
    printf ( "1391532_AED1\n\n");

 // acoes
    printf ("Digite dois valores diferentes para os lados de um retângulo:");
    scanf ("%i %i", &x, &y);
    getchar();
    area = x*y;
    perimetro = 4*x+4*y;
     printf ("\nUm retângulo com o dobro do tamanho dos lados teria %i de área e %i de perímetro", area*4, perimetro );
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );
    return (0);
}
