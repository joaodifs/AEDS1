/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: Jo�o Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para defini��es pr�prias
#include <locale.h> // para o portugu�s

void comparar( )
{
    float x = 0.0, y = 0.0, z = 0.0;
    x = IO_readfloat("Digite um valor real: ");
    y = IO_readfloat("Digite um valor real: ");
    z = IO_readfloat("Digite um valor real: ");
    if(x==y || x==z || y==z){
        IO_printf("\nN�meros repetidos.");
        }else{
        if(x!=y && x!=z && y!=z){
            if(y>z){
                if(x>z && x<y){
                    IO_printf("\n %0.2f est� entre %0.2f e %0.2f", x, y, z);
                }else{
                    IO_printf("\n %0.2f n�o est� entre %0.2f e %0.2f", x, y, z);
                }
            }
            if(y<z){
                if(x>y && x<z){
                    IO_printf("\n %0.2f est� entre %0.2f e %0.2f", x, y, z);
                }else{
                    IO_printf("\n %0.2f n�o est� entre %0.2f e %0.2f", x, y, z);
                }
            }
        }
    }
}



int main()
{
    setlocale(LC_ALL, "Portuguese");

    comparar( );

    IO_pause ( "\nApertar ENTER para terminar" );

}
