#include "io.h"

/**
 printIntArray - Mostrar arranjo com valores inteiros.
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
void printIntArray ( int n, int array [ ] )
{
// definir dado local
 int x = 0;

// mostrar valores no arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // mostrar valor
 IO_printf ( "%2d: %d\n", x, array [ x ] );
 } // fim repetir
} // printIntArray ( )
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
// definir dado
 int array [ ] = { 1, 2, 3, 4, 5 };
// identificar
 IO_id ( "EXEMPLO0801 - Method01 - v0.0" );
// executar o metodo auxiliar
 printIntArray ( 5, array );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 readIntArray - Ler arranjo com valores inteiros.
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
void readIntArray ( int n, int array [ ] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 chars text = IO_new_chars ( STR_SIZE );
// ler e guardar valores em arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // ler valor
 strcpy ( text, STR_EMPTY );
 y = IO_readint ( IO_concat (
 IO_concat ( text, IO_toString_d ( x ) ), " : " ) );
 // guardar valor
 array [ x ] = y;
 } // fim repetir
} // readIntArray ( )
/**
 Method02.
*/
void method02 ( )
{
// definir dados
 int n = 5; // quantidade de valores
 int array [ n ];
// identificar
 IO_id ( "EXEMPLO0810 - Method02 - v0.0" );
// ler dados
 readIntArray ( n, array );
// mostrar dados
 IO_printf ( "\n" );
 printIntArray (n, array );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
 fprintIntArray - Gravar arranjo com valores inteiros.
 @param fileName - nome do arquivo
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
void fprintIntArray ( chars fileName, int n, int array [ ] )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
 int x = 0;
// gravar quantidade de dados
 IO_fprintf ( arquivo, "%d\n", n );
// gravar valores no arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // gravar valor
 IO_fprintf ( arquivo, "%d\n", array [ x ] );
 } // fim repetir

// fechar arquivo
 fclose ( arquivo );
} // fprintIntArray ( )
/**
 Method03.
*/
void method03 ( )
{
// definir dados
 int n = 5; // quantidade de valores
 int array [ n ];
// identificar
 IO_id ( "EXEMPLO0810 - Method03 - v0.0" );
// ler dados
 readIntArray ( n, array );
// mostrar dados
 IO_printf ( "\n" );
 fprintIntArray ( "ARRAY1.TXT", n, array );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )


int main()
{
    int x = 0;
   do
    {
        printf ("\n");
        printf ("0\n");
        printf ("1\n");
        printf ("2\n");
        printf ("3\n");
        printf ("4\n");
        printf ("5\n");
        printf ("6\n");
        printf ("7\n");
        printf ("8\n");
        printf ("9\n");
        printf ("10\n");
        x = IO_readint("Entre com sua opcao\n");
        switch (x)
        {
        case 1:
        method01();
            break;
        case 2:
        method02();
            break;
        case 3:
        method03();
            break;
        /*case 4:
        
            break;
        case 5:
        
            break;
        case 6:
        
            break;
        case 7:
        
            break;
        case 8:
        
            break;
        case 9:
        
            break;
        case 10:
            break;
        default:
            break;
       */ } 
    } while (x != 0);
}
