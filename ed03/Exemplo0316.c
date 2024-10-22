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
 IO_id ( "EXEMPLO0316 - Method11" );
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
 IO_id ( "EXEMPLO0316 - Method12" );
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

/**
 Method13 - mostrar e contar letrar minusculas de tras para frente
*/
void method13 ( )
{
// definir dado
 char palavra[80] = "0";
 int x = 0, quantidade = 0;
 int tamanho = 0;
 //limpar a tela
 system("cls");
// identificar
 IO_id ( "EXEMPLO0316 - Method13" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Palavra digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Letras minúsculas digitadas: ");

 for( x=tamanho ; x>=0 ; x=x-1 )
 {
    if((palavra[x] >='a') && (palavra[x] <= 'z'))
    {
        IO_printf("%c", palavra[x]);
        quantidade=quantidade+1;
    }
 }
 IO_printf(" (%d)", quantidade);
// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method13 ( )

/**
 Method14 - contar e mostrar letras
*/
void method14 ( )
{
// definir dado
 char palavra[80] = "0"; // cadeia de caracteres
 int x = 0;
 int tamanho = 0;
 int quantidade = 0;
 //limpar a tela
 system("cls");
// identificar
 IO_id ( "EXEMPLO0316 - Method14" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma cadeia de caracteres: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Cadeia de caracteres digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras
 IO_printf("Letras digitadas: ");

 for( x=0 ; x<tamanho ; x=x+1 )
 {
    if(((palavra[x] >='a') && (palavra[x] <= 'z')) || (palavra[x] >='A') && (palavra[x] <= 'Z'))
    {
        quantidade = quantidade +1;
        IO_printf("%c", palavra[x]);
    }
 }
 IO_printf(" (%d)", quantidade);

// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method14 ( )

/**
 Method15 - mostrar e contar letrar digitos de tras para frente
*/
void method15 ( )
{
// definir dado
 char palavra[80] = "0";
 int x = 0, quantidade = 0;
 int tamanho = 0;
 //limpar a tela
 system("cls");
// identificar
 IO_id ( "EXEMPLO0316 - Method15" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma cadeia de caracteres: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Cadeia de caracteres digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Dígitos: ");

 for( x=tamanho ; x>=0 ; x=x-1 )
 {
    if((palavra[x] >='0') && (palavra[x] <= '9'))
    {
        IO_printf("%c", palavra[x]);
        quantidade=quantidade+1;
    }
 }
 IO_printf(" (%d)", quantidade);
// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method15 ( )

/**
 Method16 - mostrar e contar letrar digitos de tras para frente
*/
void method16 ( )
{
// definir dado
 char palavra[80] = "0";
 int x = 0, quantidade = 0;
 int tamanho = 0;
 //limpar a tela
 system("cls");
// identificar
 IO_id ( "EXEMPLO0316 - Method16" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma cadeia de caracteres: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Cadeia de caracteres digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Diferente de dígito e letra: ");

 for( x=0 ; x<tamanho ; x=x+1 )
 {
    if(!(((palavra[x] >='0') && (palavra[x] <= '9'))                                                    // não pode ser digito
          ||                                                                                           // ou
       (((palavra[x] >='a') && (palavra[x] <= 'z')) || ((palavra[x] >='A') && (palavra[x] <= 'Z'))))) // não pode ser letra
    {
        IO_printf("%c", palavra[x]);
        quantidade=quantidade+1;
    }
 }
 IO_printf(" (%d)", quantidade);
// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method16 ( )

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
 IO_id ( "EXEMPLO0316 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "11 - mostrar as letras minúsculas." );
 IO_println ( "12 - contar e mostrar as letras minúsculas." );
 IO_println ( "13 - contar e mostrar as letras minúsculas de tras para frente." );
 IO_println ( "14 - contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas. " );
 IO_println ( "15 - contar e mostrar todos os dígitos, percorrendo do fim para o início da cadeia de caracteres. " );
 IO_println ( "16 - contar e mostrar tudo o que não for dígito e também não for letra. " );

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
 method12 ( ); // mostrar e contar letras minusculas
 break;
 case 13:
 method13 ( ); // mostrar e contar letras minusculas de tras para frente
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
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,11, 12, 13, 14, 15, 16] (",
 IO_concat ( IO_toString_d ( x ), ")\n Apertar ENTER para retornar" ) ) );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
