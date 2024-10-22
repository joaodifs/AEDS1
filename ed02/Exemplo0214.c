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
    if (x > 14 && x < 46){
        IO_printf("O número %d está no intervalo fechado entre 15 e 45.", x);
    }else{
        IO_printf("O número %d não está no intervalo fechado entre 15 e 45.", x);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    intervalo( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
