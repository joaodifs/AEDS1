/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: João Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para definições próprias
#include <locale.h> // para o português

void comparar( )
{
    int x = 0;
    int y = 0;
    x = IO_readint("Digite um valor inteiro: ");
    y = IO_readint("Digite um valor inteiro: ");
    if(x>y){
            IO_printf("\n %d > %d", x, y);
        }else{
            if(x<y){
                IO_printf("\n %d < %d", x, y);
            }else{
                IO_printf("\n %d = %d", x, y);
            }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    comparar( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
