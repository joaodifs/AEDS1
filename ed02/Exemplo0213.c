/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: Jo�o Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para defini��es pr�prias
#include <locale.h> // para o portugu�s

void intervalo( )
{
    int x = 0;
    x = IO_readint("Digite um valor inteiro: ");
    if (x > 25 && x < 40){
        IO_printf("O n�mero %d est� no intervalo aberto entre 25 e 40.", x);
    }else{
        IO_printf("O n�mero %d n�o est� no intervalo aberto entre 25 e 40.", x);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    intervalo( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
