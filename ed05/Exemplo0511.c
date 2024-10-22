/*
 Exemplo0501 . - __ / __ / _____
 Author: ________________________
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )

/**
 Method11 - mostrar n multiplos de 7 em ordem crescente
*/
void method11 ( )
{
 system("cls"); // limpar tela
//dados
int quant7 = 0;
int y = 0;
int multiplos7 = 0;
// identificar
 IO_id ( "EXEMPLO0511 - Method11 " );
quant7 = IO_readint("Digite a quantidade de multiplos de 7 desejada: ");
for(y=1; y<=quant7; y=y+1)
{
    multiplos7 = 7*y;
    printf("%d: %d\n",y, multiplos7);
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 Method12 - mostrar n multiplos de 7 pares
*/
void method12 ( )
{
 system("cls"); // limpar tela
//dados
int quant = 0;
int y = 0;
int multiplos = 0;
// identificar
 IO_id ( "EXEMPLO0512 - Method12 " );
quant = IO_readint("Digite a quantidade de multiplos de 7 desejada: ");
for(y=1; y<=quant; y=y+1)
{
    multiplos = 14*y;
    printf("%d: %d\n",y, multiplos);
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method12 ( )

/**
 Method13.
*/
void method13 ( )
{
 system("cls"); // limpar tela
//dados
int quant = 0;
int y = 0;
int multiplos = 0;
// identificar
 IO_id ( "EXEMPLO0513 - Method13 " );
 // acoes
 quant = IO_readint("Digite a quantidade de multiplos de 7 desejada: ");
for(y=quant; y>0; y=y-1)
{
    multiplos = 14*y-7;
    printf("%d: %d\n",y, multiplos);
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
 Method14.
*/
void method14 ( )
{
 system("cls"); // limpar tela
//dados
int quant7 = 0;
int y = 0;
int multiplos7 = 0;
// identificar
 IO_id ( "EXEMPLO0514 - Method14 " );
 // acoes
quant7 = IO_readint("Digite a quantidade de multiplos de 7 desejada: ");
for(y=1; y<=quant7; y=y+1)
{
    multiplos7 = 7*y;
    printf("%d: 1/%d\n",y, multiplos7);
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method14 ( )

/**
 Method15.
*/
void method15 ( )
{
 system("cls"); // limpar tela
//dados
int quant = 0;
int x = 0;
int max = 0;
int pot = 0;
int result = 0;
// identificar
 IO_id ( "EXEMPLO0515 - Method15 " );
//acoes
x = IO_readint("Digite o numero: ");
max = IO_readint("Digite a potencia maxima desejada: ");
for(pot=0; pot<=max; pot=pot+1)
{
    result = pow(x, pot);
    printf("%d: 1/%d\n",pot, result);
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method15 ( )
/**

/**
 Method16.
*/
void method16 ( )
{
 system("cls"); // limpar tela
// definir dado
int quant = 0;
int y = 0;
int num = 7;
int soma = 0;
// identificar
 IO_id ( "EXEMPLO0516 - Method16 " );
//acoes
quant = IO_readint("Digite a quantidade: ");
while(y<quant)
{
    if(!(num%3==0))
    {
        soma = soma+num;
        y=y+1;
    }
    num=num+2;
}
printf("Soma: %d",soma);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method16 ( )

/**
 Method17.
*/
void method17 ( )
{
 system("cls"); // limpar tela
// definir dado
int quant = 0;
int y = 0;
int num = 7;
double soma = 0.00;
double inv = 0.00;
// identificar
 IO_id ( "EXEMPLO0517 - Method17 " );
//acoes
quant = IO_readint("Digite a quantidade: ");
while(y<quant)
{
    if(!(num%3==0))
    {
        inv = pow(num,-1);
        soma = soma+inv;
        y=y+1;
    }
    num=num+2;
}
printf("Soma: %lf",soma);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method17 ( )

/**
 Method18.
*/
void method18 ( )
{
 system("cls"); // limpar tela
// definir dado
int quant = 0;
int y = 0;
int num = 7;
int soma = 0;
// identificar
 IO_id ( "EXEMPLO0518 - Method18 " );
//acoes
quant = IO_readint("Digite a quantidade: ");
while(y<quant)
{
    soma = soma+num;
    y=y+1;
    num=num+1;
}
printf("Soma: %d",soma);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method18 ( )

/**
 Method19.
*/
void method19 ( )
{
 system("cls"); // limpar tela
// definir dado
int quant = 0;
int y = 0;
int quad = 0;
int num = 7;
int soma = 0;
// identificar
 IO_id ( "EXEMPLO0519 - Method19 " );
quant = IO_readint("Digite a quantidade: ");
while(y<quant)
{
    quad = pow(num, 2);
    soma = soma+quad;
    y=y+1;
    num=num+1;
}
printf("Soma: %d",soma);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method19 ( )


/**
 Method20.
*/
void method20 ( )
{
 system("cls"); // limpar tela
 // definir dado
int quant = 0;
int y = 0;
double inv = 0;
int num = 7;
double soma = 0;
// identificar
 IO_id ( "EXEMPLO0520 - Method20" );
quant = IO_readint("Digite a quantidade: ");
while(y<quant)
{
    inv = pow(num, -1);
    soma = soma+inv;
    y=y+1;
    num=num+1;
}
printf("Soma: %lf",soma);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method20 ( )

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 system("cls"); // limpar tela
 // identificar
 IO_id ( "Ex. 11 ao 20" );

 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - Fechar programa." );
 IO_println ( " 11 - Mostrar os multiplos de 7." );
 IO_println ( " 12 - Mostrar os multiplos pares de 7." );
 IO_println ( " 13 - Mostrar os multiplos impares de 7." );
 IO_println ( " 14 - Mostrar os numeros cujo denominador sao multiplos de 7" );
 IO_println ( " 15 - Mostrar os numeros com o denominador x aumentando seu expoente em 1 n vezes." );
 IO_println ( " 16 - Calcular a soma dos primeiros valores impares comecando no valor 7 e nao multiplos de 3." );
 IO_println ( " 17 - Calcular a soma dos inversos (1/x) dos primeiros valores impares positivos, comecando no valor 7 e nao multiplos de 3." );
 IO_println ( " 18 - Calcular a soma dos primeiros numeros naturais comecando no valor 7.");
 IO_println ( " 19 - Calcular a soma dos quadrados dos primeiros numeros naturais comecando no valor 7." );
 IO_println ( " 20 - Calcular a soma dos inversos (1/x) dos primeiros numeros naturais começando no valor 7." );
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );

 // testar valor
 switch ( x )
 {
 case 0:
 method00 ( );
 break;
 case 11:
 method11 ( );
 break;
 case 12:
 method12 ( );
 break;
 case 13:
 method13 ( );
 break;
 case 14:
 method14 ( );
 break;
 case 15:
 method15 ( );
 break;
 case 16:
 method16 ( );
 break;
 case 17:
 method17 ( );
 break;
 case 18:
 method18 ( );
 break;
 case 19:
 method19 ( );
 break;
 case 20:
 method20 ( );
 break;
 default:
 IO_println ( "ERRO: Valor invalido." );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
