/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: Jo�o Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para defini��es pr�prias
#include <locale.h> // para o portugu�s

void parImpar( )
{
    int x = 0;
    int y = 0;
    x = IO_readint("Digite um valor inteiro: ");
    y = IO_readint("Digite um valor inteiro: ");
    IO_printf("\nO n�mero %d � par e negativo e o n�mero %d � �mpar e positivo?", x, y);
    if ((x%2 == 0 && x < 0) && (y%2 == 1)){
        IO_printf(" SIM");
        }else{
        IO_printf(" N�O");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    parImpar( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
