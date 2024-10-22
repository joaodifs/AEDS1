// dependencias
#include "io.h" // para definicoes proprias
#include <locale.h> // para o portugues

/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )
/**
 Method11 - mostrar letrar minusculas
*/
void method11 ( )
{
// definir dado
 char palavra[80] = "0";
 int x = 0;
 int tamanho = 0;
 char minuscula[80] = "0";
 //limpar a tela
 system("cls");
// identificar
 IO_id ( "EXEMPLO0311 - Method11" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Palavra digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Letras minúsculas digitadas: ");

 for( x=0 ; x<tamanho ; x=x+1 )
 {
    if((palavra[x] >='a') && (palavra[x] <= 'z'))
    {
        IO_printf("%c", palavra[x]);
    }
 }

// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method11 ( )

/**
 Method12 - mostrar e contar letrar minusculas
*/
void method12 ( )
{
// definir dado
 char palavra[80] = "0";
 int x = 0, quantidade = 0;
 int tamanho = 0;
 //limpar a tela
 system("cls");
// identificar
 IO_id ( "EXEMPLO0312 - Method12" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Palavra digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Letras minúsculas digitadas: ");

 for( x=0 ; x<tamanho ; x=x+1 )
 {
    if((palavra[x] >='a') && (palavra[x] <= 'z'))
    {
        IO_printf("%c", palavra[x]);
        quantidade=quantidade+1;
    }
 }
 IO_printf("(%d)", quantidade);
// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method12 ( )

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
    setlocale(LC_ALL,"Portuguese"); //
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
     system("cls");
 // identificar
 IO_id ( "EXEMPLO0312 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "11 - mostrar as letras minúsculas." );
 IO_println ( "12 - mostrar e contar as letras minúsculas." );

 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0:
 method00 ( );
 break;
 case 11:
 method11 ( ); // mostrar letras minusculas
 break;
 case 12:
 method12 ( ); // mostrar letras minusculas
 break;
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,11, 12] (",
 IO_concat ( IO_toString_d ( x ), ")\n Apertar ENTER para retornar" ) ) );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
