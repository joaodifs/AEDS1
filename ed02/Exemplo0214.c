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
    if (x > 14 && x < 46){
        IO_printf("O n�mero %d est� no intervalo fechado entre 15 e 45.", x);
    }else{
        IO_printf("O n�mero %d n�o est� no intervalo fechado entre 15 e 45.", x);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    intervalo( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
