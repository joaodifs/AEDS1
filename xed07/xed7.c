#include "io.h"

/**
 writeInts - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeInts ( char* fileName, int x )
{
// definir dados
 FILE* arquiv;
 arquiv = fopen ( fileName, "wt" );
 int y = 0;
// repetir para a quantidade de dados
 for ( y = 2; y <= x; y = y + 2 )
 {
 // gravar valor
 fprintf ( arquiv, "%d\n", y );
 } // fim repetir
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquiv );
} // fim writeInts ( )
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
// identificar
 IO_id ( "EXEMPLO0701 - Method01 - v0.0" );
// executar o metodo auxiliar
 writeInts ( "DADOS1.TXT", 20 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 readInts - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void readInts ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 int x = 0;
// tentar ler o primeiro
 fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados
 while ( ! feof ( arquivo ) )
 {
 // mostrar valor
 printf ( "%d\n", x );
 // tentar ler o proximo
 fscanf ( arquivo, "%d", &x );
 } // fim repetir
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // fim readInts ( )
/**
 Method02.
*/
void method02 ( )
{
 IO_id ( "EXEMPLO0702 - Method02 - v0.0" );
// executar o metodo auxiliar
 readInts ( "DADOS1.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
 writeDoubles - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeDoubles ( chars fileName, int x )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 int y = 0;
// gravar quantidade de valores
 fprintf ( arquivo, "%d\n", x );
// repetir para a quantidade de dados
 for ( y = 1; y <= x; y = y + 1 )
 {
 // gravar valor
 fprintf ( arquivo, "%lf\n", (0.1*y) );
 } // fim repetir
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // fim writeDoubles ( )
/**
 Method03.
*/
void method03 ( )
{
// identificar
 IO_id ( "EXEMPLO0710 - Method03 - v0.0" );
// executar o metodo auxiliar
 writeDoubles ( "DADOS2.TXT", 10 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )
int main()
{
    int x = 0;
  do
    {
        system("cls");
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
         system("cls");
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
        */default:
            break;
        }
    } while (x != 0);
}
