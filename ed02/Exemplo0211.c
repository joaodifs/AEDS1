/*
 Exemplo0210 - v0.0. - __ / __ / _____
 Author: Jo�o Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para defini��es pr�prias
#include <locale.h> // para o portugu�s

void parOuImpar( ){
int x = 0;
x = IO_readint("Digite um valor inteiro: ");
if (x%2 == 0){
IO_printf("O n�mero %d � par.", x);


}else{
    IO_printf("O n�mero %d � �mpar.", x);
}
}

//if(x == 0)
 //   IO_printf("O valor %d � par", x);
//}else{
  //  if
//}

int main(){
setlocale(LC_ALL, "Portuguese");

parOuImpar( );

IO_pause ( "\nApertar ENTER para terminar" );

}
