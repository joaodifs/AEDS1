/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: Jo�o Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para defini��es pr�prias
#include <locale.h> // para o portugu�s

void parOuImpar( )
{
    int x = 0;
    x = IO_readint("Digite um valor inteiro: ");
    if (x%2 == 0 && x > -30)
    {
        IO_printf("O n�mero %d � par e maior do que -30.", x);
    }else{
        if ((x%2 == 1 || x%2 == -1) && x < 30)
        {
            IO_printf("O n�mero %d � �mpar e menor do que 30.", x);
    }else{
        IO_printf("O seu n�mero n�o � par maior do que -30 e nem � �mpar e menor do que 30.");
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
