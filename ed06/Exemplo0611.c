/*
 Exemplo06 . - __ / __ / _____
 Author: Joao Gabriel Dias Freire
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

void method11a (int x)
{
    if( x > 1)
    {
    int result = 0;
    method11a(x-1);
    result = x*2+5; // impares maiores que 7
    printf("Valor: %d\n",result);
    }
    else
    {
    printf("Valor: 7\n");
    }
}
/**
 Method11 - impares depois do 7
*/
void method11 ( )
{
 system("cls"); // limpar tela
//dados

// identificar
 IO_id ( "EXEMPLO0611 - Method11 " );
//acoes
method11a(5);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

void method12a (int x)
{
    if( x > 0)
    {
    int result = 0;
    result = x*7; // multiplos de 7
    printf("Valor: %d\n",result);
    method12a(x-1);
    }
}
/**
 Method12 - multiplos de 7 decrescente
*/
void method12 ( )
{
 system("cls"); // limpar tela
//dados

// identificar
 IO_id ( "EXEMPLO0612 - Method12 " );
method12a(5);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method12 ( )

void method13a (int x)
{
    if( x > 0)
    {
    int result = 0;
    result = x*7; // multiplos de 7
    method13a(x-1);
    printf("Valor: %d\n",result);
    }
    else // x = 0
    {
    printf("Valor: 1\n");
    }
}

/**
 Method13.
*/
void method13 ( )
{
 system("cls"); // limpar tela
//dados

// identificar
 IO_id ( "EXEMPLO0613 - Method13 " );
 // acoes
method13a(5);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

void method14a (int x)
{
    if( x > 1)
    {
    int result = 0;
    result = pow(7,x-1); // multiplos de 7
    printf("Valor: 1/%d\n",result);
    method14a(x-1);
    }
}

/**
 Method14.
*/
void method14 ( )
{
 system("cls"); // limpar tela
//dados

// identificar
 IO_id ( "EXEMPLO0614 - Method14 " );
 // acoes
method14a(5);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method14 ( )

void method15a (int x, char palavra[])
{
    if( x >= 0)
    {
    method15a(x-1, palavra);
        if(palavra[x]!='\0')
        {
        printf("%d - %c\n",x, palavra[x]);
        }
    }
}

/**
 Method15.
*/
void method15 ( )
{
 system("cls"); // limpar tela
//dados
char palavra[80] = "0";
int tamanho = 0;
// identificar
 IO_id ( "EXEMPLO0615 - Method15 " );
//acoes - LER CADA CARACTER PELO SEU VETOR
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 getchar();
 tamanho = strlen(palavra);
 method15a(tamanho, palavra);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method15 ( )

int method16a (int x)
{
    int soma = 1;
    if( x > 1)
    {
    int result = 0;
    result = x*2+5; // impares maiores que 7
    soma = method16a(x-1) + result;
    printf("Valor: %d\n",result);
    }
    else
    {
    printf("Valor: 7\n");
    soma = soma + 7;
    }
    return(soma);
}

/**
 Method16.
*/
void method16 ( )
{
 system("cls"); // limpar tela
// definir dado

// identificar
 IO_id ( "EXEMPLO0616 - Method16 " );
//acoes
printf("Soma: %d\n",method16a(5));
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method16 ( )

double method17a (int x)
{
    double soma = 0.00;
    if( x > 1)
    {
    int result = 0;
    result = x*2+5; // impares maiores que 7
    soma = method17a(x-1) + pow(result,-1);
    printf("Valor: 1/%d\n",result);
    }
    else
    {
    printf("Valor: 1/7\n");
    soma = soma + pow(7,-1);
    }
    return(soma);
}

/**
 Method17.
*/
void method17 ( )
{
 system("cls"); // limpar tela
// definir dado

// identificar
 IO_id ( "EXEMPLO0617 - Method17 " );
//acoes
printf("Soma: %lf\n",method17a(5));
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method17 ( )

int fibonacci(int x) {
  int y;

  if (x == 1) {
    return(1);
  }

  if (x == 2) {
    return(1);
  }

  y = fibonacci(x-1) + fibonacci(x-2);
  return(y);
}

/**
 Method18.
*/
void method18 ( )
{
 system("cls"); // limpar tela
// definir dado

// identificar
 IO_id ( "EXEMPLO0618 - Method18 " );
//acoes
for (int i = 1; i <= 10; i++)
{
    printf("%d ", fibonacci(i));
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method18 ( )

int method19a(int x, char palavra[])
{
    int soma = 0;
    if(x>=0)
    {
        soma = method19a(x-1,palavra);
        if((palavra[x] == '0' || palavra[x] == '2' || palavra[x] == '4' || palavra[x] == '6' || palavra[x] == '8'))
        {
            soma = soma +1;
        }
    }
    return(soma);
}

/**
 Method19.
*/
void method19 ( )
{
 system("cls"); // limpar tela
//dados
char palavra[80] = "0";
int tamanho = 0;
// identificar
 IO_id ( "EXEMPLO0619 - Method19 " );
//acoes - LER CADA CARACTER PELO SEU VETOR
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 getchar();
 tamanho = strlen(palavra);
printf("Quantidade de digitos pares: %d\n", method19a(tamanho,palavra));
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method19 ( )

int method20a(int x, char palavra[])
{
    int soma = 0;
    if(x>=0)
    {
        soma = method20a(x-1,palavra);
        if(palavra[x] >= 'A' && palavra[x] <= 'Z')
        {
            soma = soma +1;
        }
    }
    return(soma);
}

/**
 Method20.
*/
void method20 ( )
{
 system("cls"); // limpar tela
 // definir dados
char palavra[80] = "0";
int tamanho = 0;
// identificar
 IO_id ( "EXEMPLO0620 - Method20" );
//acoes
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 getchar();
 tamanho = strlen(palavra);
printf("Quantidade de maiusculas: %d\n", method20a(tamanho,palavra));
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
 IO_println ( " 0 - Encerrar" );
 IO_println ( " 11 - Mostrar valores impares em ordem crescente comecando no valor 7." );
 IO_println ( " 12 - Mostrar multiplos de 7 em ordem decrescente encerrando no valor 7." );
 IO_println ( " 13 - Mostrar valores da sequencia: 1 7 14 21 28 35" );
 IO_println ( " 14 - Mostrar essa quantidade em valores decrescentes da sequencia: 1/2401 1/343 1/49 1/7 1." );
 IO_println ( " 15 - Mostrar cada simbolo separadamente, um por linha" );
 IO_println ( " 16 - Calcular a soma dos primeiros valores ímpares positivos começando no valor 7." );
 IO_println ( " 17 - Calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos começando no valor 7.");
 IO_println ( " 18 - Calcular certo termo par da série de Fibonacci começando em 1.");
 IO_println ( " 19 - Calcular a quantidade de digitos com valores pares em uma cadeia de caracteres." );
 IO_println ( " 20 - Calcular a quantidade de maiusculas em uma cadeia de caracteres." );
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
 while ( x != 0 ); // fim do while
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
