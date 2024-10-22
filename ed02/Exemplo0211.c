/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: João Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para definições próprias
#include <locale.h> // para o português

void parOuImpar( ){
int x = 0;
x = IO_readint("Digite um valor inteiro: ");
if (x%2 == 0){
IO_printf("O número %d é par.", x);


}else{
    IO_printf("O número %d é ímpar.", x);
}
}

//if(x == 0)
 //   IO_printf("O valor %d é par", x);
//}else{
  //  if
//}

int main(){
setlocale(LC_ALL, "Portuguese");

parOuImpar( );

IO_pause ( "\nApertar ENTER para terminar" );

}
