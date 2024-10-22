// FUNCAO BOOL PARA COLOCAR DO IF (MINUSCULA){cont+1}
// 999999_AED1
#include <stdio.h>
#include <stdlib.h>
#include "io.h"
void method00 ( )
{
    // nao fazer nada
}
void method11 ( )
{

}

// retornar se o caracter esta entre A e K
bool A_K(char c)
{
    bool teste = false;
    if(c>='A' && c<'K')
    {
        teste = true;
    }
    return(teste);
}

// mostrar e contar quantos caracteres digitados estao entre A e K
void method12 ( )
{
    // definir dados
    char s[80];
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 12" );
    // acoes
    IO_printf("Digite uma palavra: ");
    scanf("%s", s);
    getchar( );
    tamanho = strlen(s);
    printf("Maiusculas menores que K: ");
    for(x=0;x<tamanho;x=x+1)
    {
        if(A_K(s[x]))
        {
            printf("%c",s[x]);
            quant=quant+1;
        }
    }
    IO_printf("(%d)", quant);
    IO_pause ( "\nApertar ENTER para continuar" );
}

void contar_AK(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    printf("Maiusculas menores que K: ");
    tamanho = strlen(c);
    for(x=0;x<tamanho;x=x+1)
    {
        if(c[x]>='A' && c[x]<'K')
        {
            quant=quant+1;
        }
    }
        printf("%d", quant);
}

void method13( )
{
    // definir dados
    char s[80];
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 13" );
    // acoes
    IO_printf("Digite uma palavra: ");
    scanf("%s", s);
    getchar( );
    contar_AK(s);
    IO_pause ( "\nApertar ENTER para continuar" );
}

// mostrar maiusculas menores que K
void mostrar_AK(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    printf("Maiusculas menoreS que K: ");
    tamanho = strlen(c);
    for(x=0;x<tamanho;x=x+1)
    {
        if(c[x]>='A' && c[x]<'K')
        {
            printf("%c",c[x]);
        }
    }
}

void method14( )
{
    // definir dados
    char s[80];
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 14" );
    // acoes
    IO_printf("Digite uma palavra: ");
    scanf("%s", s);
    getchar( );
    mostrar_AK(s);
    IO_pause ( "\nApertar ENTER para continuar" );
}

// contar maiusculas menores que K e minusculas menores que k
void contar_kK(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    printf("Letras menores que 'K' ou 'k': ");
    tamanho = strlen(c);
    for(x=0;x<tamanho;x=x+1)
    {
        if(c[x]>='A' && c[x]<'K' || c[x]>='a' && c[x]<'k')
        {
            quant=quant+1;
        }
    }
    printf("%d",quant);
}

void method15( )
{
    // definir dados
    char s[80];
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 15" );
    // acoes
    IO_printf("Digite uma palavra: ");
    scanf("%s", s);
    getchar( );
    contar_kK(s);
    IO_pause ( "\nApertar ENTER para continuar" );
}

// mostrar maiusculas menores que K e minusculas menores que k
void mostrar_kK(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    printf("Letras menores que 'K' ou 'k': ");
    tamanho = strlen(c);
    for(x=0;x<tamanho;x=x+1)
    {
        if(c[x]>='A' && c[x]<'K' || c[x]>='a' && c[x]<'k')
        {
            printf("%c", c[x]);
        }
    }
}

void method16( )
{
    // definir dados
    char s[80];
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 16" );
    // acoes
    IO_printf("Digite uma palavra: ");
    scanf("%s", s);
    getchar( );
    mostrar_kK(s);
    IO_pause ( "\nApertar ENTER para continuar" );
}

// mostrar maiusculas menores que K e minusculas menores que k
void contar_pares(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    int restoCX = 0;
    tamanho = strlen(c);
    for(x=0;x<tamanho;x=x+1)
    {
        if(c[x]>='0' && c[x]<='9')
        {
            restoCX = (int)c[x]%2;
            if(restoCX==0)
            {
                quant=quant+1;
            }
        }
    }
    printf("Quantidade de digitos pares: %d",quant);
}

void method17( )
{
    // definir dados
    char s[80];
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 17" );
    // acoes
    IO_printf("Digite cadeia de caracteres: ");
    scanf("%s", s);
    getchar( );
    contar_pares(s);
    IO_pause ( "\nApertar ENTER para continuar" );
}

bool alfanum(char c)
{
    bool teste = false;
     if(c>='0' && c<='9' || c>='a' && c<='z'|| c>='A' && c<='Z')
        {
                teste = true;
        }
        return(teste);
}

// mostrar nao alfanumericos
void mostrar_naoAlfanum(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    tamanho = strlen(c);
    printf("Simbolos nao alfanumericos: ");
    for(x=0;x<tamanho;x=x+1)
    {
        if(!(alfanum(c[x])))
        {
                printf("%c",c[x]);
        }
    }
}

void method18( )
{
    // definir dados
    char s[80];
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 18" );
    // acoes
    IO_printf("Digite cadeia de caracteres: ");
    scanf("%s", s);
    getchar( );
    mostrar_naoAlfanum(s);
    IO_pause ( "\nApertar ENTER para continuar" );
}

// mostrar alfanumericos
void mostrar_alfanum(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    tamanho = strlen(c);
    printf("Simbolos alfanumericos: ");
    for(x=0;x<tamanho;x=x+1)
    {
        if(alfanum(c[x]))
        {
                printf("%c",c[x]);
        }
    }
}

void method19( )
{
    // definir dados
    char s[80];
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 19" );
    // acoes
    IO_printf("Digite cadeia de caracteres: ");
    scanf("%s", s);
    getchar( );
    mostrar_alfanum(s);
    IO_pause ( "\nApertar ENTER para continuar" );
}

// mostrar alfanumericos
int contar_alfanum(char c[])
{
    int tamanho = 0;
    int x = 0;
    int quant = 0;
    tamanho = strlen(c);
    for(x=0;x<tamanho;x=x+1)
    {
        if(alfanum(c[x]))
        {
                quant=quant+1;
        }
    }
    printf("Quantidade de simbolos alfanumericos: %d\n",quant);
    return(quant);
}

void method20( )
{
    // definir dados
    char s[80];
    int x = 0;
    int y = 0;
    int quant = 0;
    // limpar a tela
    system("cls");
    // identificao
    IO_id ( "METODO 20" );
    // acoes
    while(x<=0)
    {
    IO_printf("\nQuantas cadeias de caracteres deseja escrever? ");
    scanf("%d", &x);
    }
    while(y<x)
    {
    IO_printf("\nDigite a %d. cadeia de caracteres: ",y+1);
    scanf("%s", s);
    getchar( );
    quant = quant + contar_alfanum(s);
    y=y+1;
    }
    IO_printf("\nQuantidade total de simbolos alfanumericos: %d",quant);
    IO_pause ( "\nApertar ENTER para continuar" );
}


int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
     system("cls");
 // identificar
 IO_id ( "EXERCICIOS 1 AO 10 (exemplo0411 ao exemplo0420)" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "11  " );
 IO_println ( "12 - contar e mostrar maiusculas menores que K." );
 IO_println ( "13 - mostrar a quantidade de letras maiusculas menores que K." );
 IO_println ( "14 - mostrar as letras maiusculas menores que K." );
 IO_println ( "15 - mostrar a quantidade de letras (tanto maiusculas, quanto minusculas) menores que 'K' e 'k'." );
 IO_println ( "16 - mostrar as letras (tanto maiusculas, quanto minusculas) menores que 'K' e 'k'." );
 IO_println ( "17 - mostrar a quantidade de digitos pares." );
 IO_println ( "18 - mostrar todos os simbolos nao alfanumericos (letras e digitos)" );
 IO_println ( "19 - mostrar todos os simbolos alfanumericos (letras e digitos)" );
 IO_println ( "20 - mostrar e contar a quantidade de simbolos alfanumericos (letras e digitos) em cada palavra, e calcular o total de todas as palavras" );

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
 IO_pause ( IO_concat ( "Valor diferente das opcoes [11, 12, 13, 14, 15, 16, 17, 18, 19, 20] (",
 IO_concat ( IO_toString_d ( x ), ")\n Apertar ENTER para retornar" ) ) );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
