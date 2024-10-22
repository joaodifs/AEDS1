/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: João Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para definições próprias
#include <locale.h> // para o português

void comparar( )
{
    float x = 0.0, y = 0.0, z = 0.0;
    x = IO_readfloat("Digite um valor real: ");
    y = IO_readfloat("Digite um valor real: ");
    z = IO_readfloat("Digite um valor real: ");
    if(x==y || x==z || y==z){
        IO_printf("\nNúmeros repetidos.");
        }else{
        if(x!=y && x!=z && y!=z){
            if(y>z){
                if(x>z && x<y){
                    IO_printf("\n %0.2f está entre %0.2f e %0.2f", x, y, z);
                }else{
                    IO_printf("\n %0.2f não está entre %0.2f e %0.2f", x, y, z);
                }
            }
            if(y<z){
                if(x>y && x<z){
                    IO_printf("\n %0.2f está entre %0.2f e %0.2f", x, y, z);
                }else{
                    IO_printf("\n %0.2f não está entre %0.2f e %0.2f", x, y, z);
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
