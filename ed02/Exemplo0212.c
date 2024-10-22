/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: João Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para definições próprias
#include <locale.h> // para o português

void parOuImpar( )
{
    int x = 0;
    x = IO_readint("Digite um valor inteiro: ");
    if (x%2 == 0 && x > -30)
    {
        IO_printf("O número %d é par e maior do que -30.", x);
    }else{
        if ((x%2 == 1 || x%2 == -1) && x < 30)
        {
            IO_printf("O número %d é ímpar e menor do que 30.", x);
    }else{
        IO_printf("O seu número não é par maior do que -30 e nem é ímpar e menor do que 30.");
    }
}
}

int main()
{
    IO_id("EXEMPLO");
    setlocale(LC_ALL, "Portuguese");

    parOuImpar( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
