/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: João Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para definições próprias
#include <locale.h> // para o português

void parImpar( )
{
    int x = 0;
    int y = 0;
    x = IO_readint("Digite um valor inteiro: ");
    y = IO_readint("Digite um valor inteiro: ");
    IO_printf("O número %d é ímpar e o número %d é par?", x, y);
    if (( x%2 == 1 || x%2 == -1 ) && y%2 == 0 ){
        IO_printf(" SIM");
        }else{
        IO_printf(" NÃO");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    parImpar( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
