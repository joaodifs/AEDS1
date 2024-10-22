/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: João Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para definições próprias
#include <locale.h> // para o português

void intervalo( )
{
    int x = 0;
    x = IO_readint("Digite um valor inteiro: ");
    if (x > 19 && x < 26)
    {
        IO_printf("O número %d está nos intervalos [10:25] e [20:40].", x);
    }else{
        if ((x>9 && x<26) || (x>20 && x<41))
        {
        IO_printf("O número %d está no intervalo [10:25] ou [20:40].", x);
            }else{
            IO_printf("O número %d não está no intervalo [10:25] ou [20:40].", x);
            }
        }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    intervalo( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
