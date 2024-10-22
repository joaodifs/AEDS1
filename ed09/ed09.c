#include "io.h"



void printIntMatrix ( int rows, int columns, int matrix[ ][columns] )
{
// definir dado inicial
 int x = 0;
 int y = 0;

 for ( x=0; x<rows; x=x+1 )
 {
 for ( y=0; y<columns; y=y+1 )
 {

 IO_printf ( "%3d\t", matrix [ x ][ y ] );
 }
 IO_printf ( "\n" );
 }
}
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{

 int matrix [ ][3] = {
 {1, 2, 3},
 {4, 5, 6},
 {7, 8, 9}
 };

 IO_id ( "EXEMPLO0910 - Method01 - v0.0" );

 printIntMatrix ( 3, 3, matrix );

 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

void readIntMatrix ( int rows, int columns, int matrix[ ][columns] )
{

 int x = 0;
 int y = 0;
 int z = 0;
 chars text = IO_new_chars ( STR_SIZE );

 for ( x=0; x<rows; x=x+1 )
 {
 for ( y=0; y<columns; y=y+1 )
 {

 strcpy ( text, STR_EMPTY );
 z = IO_readint ( IO_concat (
 IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ),
 IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );

 matrix [ x ][ y ] = z;
 }
 }
}
/**
 Method02.
*/
void method02 ( )
{

 int n = 2;
 int matrix [ n ][ n ];

 IO_id ( "EXEMPLO0910 - Method02 - v0.0" );

 readIntMatrix ( n, n, matrix );

 IO_printf ( "\n" );
 printIntMatrix ( n, n, matrix );

 IO_pause ( "Apertar ENTER para continuar" );
}

void fprintIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
 int x = 0;




 int y = 0;

 IO_fprintf ( arquivo, "%d\n", rows );



 IO_fprintf ( arquivo, "%d\n", columns );

 for ( x=0; x<rows; x=x+1 )
 {
 for ( y=0; y<columns; y=y+1 )
 {

 IO_fprintf ( arquivo, "%d\n", matrix [ x ][ y ] );
 }
 }
// fechar arquivo
 fclose ( arquivo );
} // fprintIntMatrix ( )

/**
 Method03.
*/
void method03 ( )
{

 int rows = 0;
 int columns = 0;

 IO_id ( "EXEMPLO0910 - Method03 - v0.0" );

 rows = IO_readint ( "\nrows = " );
 columns = IO_readint ( "\ncolumns = " );
 IO_printf ( "\n" );
 if ( rows <= 0 || columns <= 0 )
 {
 IO_println ( "\nERRO: Valor invalido." );
 }
 else
 {

 int matrix [ rows ][ columns ];

 readIntMatrix ( rows, columns, matrix );

 IO_printf ( "\n" );
 printIntMatrix ( rows, columns, matrix );

 IO_printf ( "\n" );
 fprintIntMatrix( "MATRIX1.TXT", rows, columns, matrix );
 }

 IO_pause ( "Apertar ENTER para continuar" );
}

int freadMatrixRows ( chars fileName )
{
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 ints array = NULL;
//
 IO_fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
 IO_println ( "ERRO: Valor invalido." );
 n = 0;
 } // fim se
// retornar dado lido
 return ( n );
} // freadMatrixRows ( )
/**
 freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros.
 @return quantidade de colunas da matriz
 @param fileName - nome do arquivo
*/
int freadMatrixColumns ( chars fileName )
{
// definir dados locais
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
 IO_fscanf ( arquivo, "%d", &n );
 IO_fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
 IO_println ( "ERRO: Valor invalido." );
 n = 0;
 } // fim se
// retornar dado lido
 return ( n );
} // freadMatrixColumns ( )
/**
 freadIntMatrix - Ler arranjo bidimensional com valores inteiros.
 @param fileName - nome do arquivo
 @param rows - quantidade de valores
 @param columns - quantidade de valores
 @param matrix - grupo de valores inteiros
*/
void freadIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 int z = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
 IO_fscanf ( arquivo, "%d", &x );
 IO_fscanf ( arquivo, "%d", &y );
 if ( rows <= 0 || rows > x ||
 columns <= 0 || columns > y )
 {
 IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
 // ler e guardar valores em arranjo
 x = 0;
 while ( ! feof ( arquivo ) && x < rows )
 {
 y = 0;
 while ( ! feof ( arquivo ) && y < columns )
 {
 // ler valor
 IO_fscanf ( arquivo, "%d", &z );
 // guardar valor
 matrix [ x ][ y ] = z;
 // passar ao proximo
 y = y+1;
 }
 // passar ao proximo
 x = x+1;
 }
 } // fim se
// fechar arquivo
 fclose ( arquivo );
} // freadIntMatrix ( )
/**
 Method04.
*/
void method04 ( )
{
// definir dados
 int rows = 0;
 int columns = 0;
// identificar
 IO_id ( "EXEMPLO0910 - Method04 - v0.0" );
// ler dados
 rows = freadMatrixRows ( "MATRIX1.TXT" );
 columns = freadMatrixColumns ( "MATRIX1.TXT" );

 if ( rows <= 0 || columns <= 0 )
 {
 IO_println ( "\nERRO: Valor invalido." );
 }
 else
 {
 // definir armazenador
 int matrix [ rows ][ columns ];
 // ler dados
 freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix );
 // mostrar dados
 IO_printf ( "\n" );
 printIntMatrix ( rows, columns, matrix );
 } // fim se
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 (

void copyIntMatrix ( int rows, int columns,
 int matrix2[ ][columns], int matrix1[ ][columns] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 if ( rows <= 0 || columns <= 0 )
 {
 IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
 // copiar valores em matriz
 for ( x = 0; x < rows; x = x + 1 )
 {
 for ( y = 0; y < columns; y = y + 1 )
 {
 // copiar valor
 matrix2 [ x ][ y ] = matrix1 [ x ][ y ];
 }
 }
 } // fim se
} // copyIntMatrix ( )
/**
 Method05.
*/
void method05 ( )
{
// definir dados
 int rows = 0;
 int columns = 0;
// identificar
 IO_id ( "EXEMPLO0910 - Method05 - v0.0" );
// ler dados
 rows = freadMatrixRows ( "MATRIX1.TXT" );
 columns = freadMatrixColumns ( "MATRIX1.TXT" );

 if ( rows <= 0 || columns <= 0 )
 {
 IO_println ( "\nERRO: Valor invalido." );
 }
 else
 {
 // definir armazenadores
 int matrix [ rows ][ columns ];
 int other [ rows ][ columns ];
 // ler dados
 freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix );
 // copiar dados
 copyIntMatrix ( rows, columns, other, matrix );
 // mostrar dados
 IO_printf ( "\nOriginal\n" );
 printIntMatrix ( rows, columns, matrix );
 // mostrar dados
 IO_printf ( "\nCopia\n" );
 printIntMatrix ( rows, columns, other );
 } // fim se
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 (

void transposeIntMatrix ( int rows, int columns,
 int matrix2[ ][rows] , int matrix1[ ][columns] )
{
// definir dados locais
 int x = 0;
 int y = 0;
// percorrer a matriz
 for ( x = 0; x<rows; x=x+1 )
 {
 for ( y = 0; y<columns; y=y+1 )
 {
 matrix2[ y ][ x ] = matrix1 [ x ][ y ];
 }
 }
} // transposeIntMatrix ( )
/**
 Method06.
*/
void method06 ( )
{
// definir dados
 int matrix1 [ ][2] = { {1, 0} ,
 {0, 1} };
 int matrix2 [ ][2] = { {0, 0} ,
 {0, 0} };
 int matrix3 [ ][3] = { {1, 2, 3} ,
 {4, 5, 6} };
 int matrix4 [ ][3] = { {1, 2, 3} ,
 {4, 5, 6} ,
 {7, 8, 9} };
// identificar
 IO_id ( "EXEMPLO0910 - Method06 - v0.0" );
// testar dados
 IO_println ( "\nMatrix1 " );
 printIntMatrix( 2, 2, matrix1 );
 transposeIntMatrix ( 2, 2, matrix2, matrix1 );
 IO_println ( "\nMatrix2" );
 printIntMatrix( 2, 2, matrix2 );
 IO_println ( "\nMatrix3" );
 printIntMatrix( 2, 3, matrix3 );
 transposeIntMatrix ( 2, 3, matrix4, matrix3 );
 IO_println ( "\nMatrix4" );
 printIntMatrix( 3, 2, matrix4 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

bool isIdentity ( int rows, int columns, int matrix[ ][columns] )
{
// definir dados locais
 bool result = false;
 int x = 0;
 int y = 0;
// testar condicao de existencia
 if ( rows <= 0 || columns <= 0 ||
 rows != columns )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // testar valores na matriz
 x = 0;
 result = true;
 while ( x<rows && result )
 {
 y = 0;
 while ( y<columns && result )
 {
 // testar valor
 if ( x == y )
 {
 result = result && ( matrix [ x ][ y ] == 1 );
 }
 else
 {
 result = result && ( matrix [ x ][ y ] == 0 );
 } // fim se
 // passar ao proximo
 y = y + 1;
 }
 // passar ao proximo
 x = x + 1;
 }
 } // fim se
// retornar resposta
 return ( result );
} // isIdentity ( )
/**
 Method07.
*/
void method07 ( )
{
// definir dados
 int matrix1 [ ][2] = { {0, 0} ,
 {0, 0} };
 int matrix2 [ ][3] = { {1, 2, 3} ,
 {4, 5, 6} };
 int matrix3 [ ][2] = { {1, 0} ,
 {0, 1} };
// identificar
 IO_id ( "EXEMPLO0910 - Method07 - v0.0" );
// testar dados
 IO_println ( "\nMatrix1" );
 printIntMatrix( 2, 2, matrix1 );
 IO_printf ( "isIdentity (matrix1) = %d", isIdentity (2, 2, matrix1) );
 IO_println ( "\nMatrix2" );
 printIntMatrix( 2, 3, matrix2 );
 IO_printf ( "isIdentity (matrix2) = %d", isIdentity (2, 3, matrix2) );
 IO_println ( "\nMatrix3" );
 printIntMatrix( 2, 2, matrix3 );
 IO_printf ( "isIdentity (matrix3) = %d", isIdentity (2, 2, matrix3) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

bool isEqual ( int rows, int columns,
 int matrix1[ ][columns], int matrix2[ ][columns] )
{
// definir dados locais
 bool result = true;
 int x = 0;
 int y = 0;
// mostrar valores na matriz
 x = 0;
 while ( x<rows && result )
 {
 y = 0;
 while ( y<columns && result )
 {
 // testar valor
 result = result &&
 ( matrix1 [ x ][ y ] == matrix2 [ x ][ y ] );
 // passar ao proximo
 y = y + 1;
 }
 // passar ao proximo
 x = x + 1;
 }
// retornar resposta
 return ( result );
} // isEqual ( )
/**
 Method09.
*/
void method08 ( )
{
// definir dados
 int matrix1 [ ][2] = { {0, 0} ,
 {0, 0} };
 int matrix2 [ ][2] = { {1, 2} ,
 {3, 4} };
 int matrix3 [ ][2] = { {1, 0} ,
 {0, 1} };
// identificar
 IO_id ( "EXEMPLO0910 - Method08 - v0.0" );
// testar dados
 IO_println ( "\nMatrix1" );
 printIntMatrix( 2, 2, matrix1 );
 IO_println ( "\nMatrix2" );
 printIntMatrix( 2, 2, matrix2 );
 IO_printf ( "isEqual (matrix1, matrix2) = %d",
 isEqual (2, 2, matrix1, matrix2) );
 copyIntMatrix ( 2, 2, matrix1, matrix3 );
 copyIntMatrix ( 2, 2, matrix2, matrix3 );
 IO_println ( "\nMatrix1" );
 printIntMatrix( 2, 2, matrix1 );
 IO_println ( "\nMatrix3" );
 printIntMatrix( 2, 2, matrix2 );
 IO_printf ( "isEqual (matrix1, matrix2) = %d",
 isEqual (2, 2, matrix1, matrix2) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 (

void addIntMatrix ( int rows, int columns,
 int matrix3[ ][columns],
 int matrix1[ ][columns], int k, int matrix2[ ][columns] )
{
// definir dados locais
 int x = 0;
 int y = 0;
// mostrar valores na matriz
 for ( x=0; x<rows; x=x+1 )
 {
 for ( y = 0; y < columns; y = y + 1 )
 {
 // somar valores
 matrix3 [ x ][ y ] = matrix1 [ x ][ y ] + k * matrix2 [ x ][ y ];
 }
 }
} // addIntMatrix ( )
/**
 Method09.
*/
void method09 ( )
{
// definir dados
 int matrix1 [ ][2] = { {1, 2},
 {3, 4} };
 int matrix2 [ ][2] = { {1, 0},
 {0, 1} };
 int matrix3 [ ][2] = { {0, 0},
 {0, 0} };
// identificar
 IO_id ( "EXEMPLO0910 - Method09 - v0.0" );
// testar dados
 IO_println ( "\nMatrix1" );
 printIntMatrix( 2, 2, matrix1 );
 IO_println ( "\nMatrix2" );
 printIntMatrix( 2, 2, matrix2 );
// soamr matrizes
 addIntMatrix ( 2, 2, matrix3, matrix1, (-2), matrix2 );
 IO_println ( "\nMatrix3" );
 printIntMatrix( 2, 2, matrix3 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 (

void mulIntMatrix ( int rows3, int columns3,
 int matrix3[ ][columns3],
 int rows1, int columns1,
 int matrix1[ ][columns1],
 int rows2, int columns2,
 int matrix2[ ][columns2] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 int z = 0;
 int soma = 0;
 if ( rows1 <= 0 || columns1 <= 0 ||
 rows2 <= 0 || columns2 <= 0 ||
 rows3 <= 0 || columns3 <= 0 ||
 columns1 != rows2 ||
 rows1 != rows3 ||
 columns2 != columns3 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // percorrer valores na matriz resultante
 for ( x=0; x<rows3; x=x+1 )
 {
 for ( y = 0; y < columns3; y = y + 1 )
 {
 // somar valores
 soma = 0;
 for ( z = 0; z < columns1; z = z + 1 ) // ou (z < rows2)
 {
 soma = soma + matrix1 [ x ][ z ] * matrix2 [ z ][ y ];
 }
 // guardar a soma
 matrix3 [ x ][ y ] = soma;
 }
 }
 } // fim se
} // mulIntMatrix ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "EXEMPLO0910 - Method10 - v0.0" );
// definir dados
 int matrix1 [ ][2] = { {1, 2},
 {3, 4} };
 int matrix2 [ ][2] = { {1, 0},
 {0, 1} };
 int matrix3 [ ][2] = { {0, 0},
 {0, 0} };
// identificar
 IO_id ( "EXEMPLO0910 - Method09 - v0.0" );
// testar produto
 IO_println ( "\nMatrix1" );
 printIntMatrix( 2, 2, matrix1 );
 IO_println ( "\nMatrix2" );
 printIntMatrix( 2, 2, matrix2 );
// multiplicar matrizes
 mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2 );
 IO_println ( "\nMatrix3 = Matrix1 * Matrix2" );
 printIntMatrix( 2, 2, matrix3 );
// outro teste
 IO_println ( "\nMatrix2" );
 printIntMatrix( 2, 2, matrix2 );
 IO_println ( "\nMatrix1" );
 printIntMatrix( 2, 2, matrix1 );
// multiplicar matrizes
 mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1 );
 IO_println ( "\nMatrix3 = Matrix2 * Matrix1" );
 printIntMatrix( 2, 2, matrix3 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 (

void method11 ( )
{
   int col,lin = 0;
   int x,y =0;


do{

   printf ("Inisira a quantidade de colunas:");
   scanf("%d", &col);
   getchar ( );
   printf ("Inisira a quantidade de linhas:");
   scanf("%d", &lin);
   getchar ( );
}while (col < 0 && lin < 0);

  int matrix [lin][col];

for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   printf("\ninsira o valor:");
   scanf("%d", &matrix[x][y]);
}
}
//mosrtrar resultados
printf("\nsua matriz ficou assim:\n");

  for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   printf(" [%d]",matrix[x][y]);
}
   printf("\n");
}
}

void method12 ( )
{
   int col,lin = 0;
   int x,y =0;

FILE*arquivo = fopen ("matrix.txt", "wt");

do{

   printf ("Inisira a quantidade de colunas:");
   scanf("%d", &col);
   getchar ( );
   printf ("Inisira a quantidade de linhas:");
   scanf("%d", &lin);
   getchar ( );
}while (col < 0 && lin < 0);

  int matrix [lin][col];

for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   printf("\ninsira o valor:");
   scanf("%d", &matrix[x][y]);
}
}
//mosrtrar resultados
printf("\nsua matriz ficou assim:\n");

  for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   fprintf(arquivo," [%d]",matrix[x][y]);
}
   fprintf(arquivo,"\n");
}
          fclose(arquivo);
}

void method13 ( )
{
int col,lin = 0;
   int x,y =0;


do{

   printf ("Inisira a quantidade de colunas:");
   scanf("%d", &col);
   getchar ( );
   printf ("Inisira a quantidade de linhas:");
   scanf("%d", &lin);
   getchar ( );
}while (col < 0 && lin < 0);

  int matrix [lin][col];

for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   printf("\ninsira o valor:");
   scanf("%d", &matrix[x][y]);
}
}
//mosrtrar resultados
printf("\nsua matriz ficou assim:\n");

  for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
  if (x == y)
   printf(" [%d]",matrix[x][y]);
   else
   printf(" [ ]");
}
   printf("\n");
}
}void method14 ( )
{
int col,lin = 0;
   int x,y =0;
   int a = 0;


do{

   printf ("Inisira a quantidade de colunas:");
   scanf("%d", &col);
   getchar ( );
   printf ("Inisira a quantidade de linhas:");
   scanf("%d", &lin);
   getchar ( );
}while (col < 0 && lin < 0);

  int matrix [lin][col];

for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   printf("\ninsira o valor:");
   scanf("%d", &matrix[x][y]);
}
}
//mosrtrar resultados
printf("\nsua matriz ficou assim:\n");
if (col < lin)
a = col;
else
a = lin;

  for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
  if (x + y - 1 == a )
   printf(" [%d]",matrix[x][y]);
   else
   printf(" [ ]");
}
   printf("\n");
}
}

void method15 ( )
{
        int col,lin = 0;
           int x,y =0;


        do{

           printf ("Inisira a quantidade de colunas:");
           scanf("%d", &col);
           getchar ( );
           printf ("Inisira a quantidade de linhas:");
           scanf("%d", &lin);
           getchar ( );
        }while (col < 0 && lin < 0);

          int matrix [lin][col];

        for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
           printf("\ninsira o valor:");
           scanf("%d", &matrix[x][y]);
        }
        }
        //mosrtrar resultados
        printf("\nsua matriz ficou assim:\n");

          for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
        if (x == y || y > x)
           printf(" [%d]",matrix[x][y]);
           else
           printf(" [ ]");
        }
           printf("\n");
        }
}


void method16 ( )
{
        int col,lin = 0;
           int x,y =0;


        do{

           printf ("Inisira a quantidade de colunas:");
           scanf("%d", &col);
           getchar ( );
           printf ("Inisira a quantidade de linhas:");
           scanf("%d", &lin);
           getchar ( );
        }while (col < 0 && lin < 0);

          int matrix [lin][col];

        for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
           printf("\ninsira o valor:");
           scanf("%d", &matrix[x][y]);
        }
        }
        //mosrtrar resultados
        printf("\nsua matriz ficou assim:\n");

          for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
        if (x == y || y < x)
           printf(" [%d]",matrix[x][y]);
           else
           printf(" [ ]");
        }
           printf("\n");
        }
}

void method17 ( )
{
int col,lin = 0;
   int x,y =0;
   int a;

do{

   printf ("Inisira a quantidade de colunas:");
   scanf("%d", &col);
   getchar ( );
   printf ("Inisira a quantidade de linhas:");
   scanf("%d", &lin);
   getchar ( );
}while (col < 0 && lin < 0);

  int matrix [lin][col];

for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   printf("\ninsira o valor:");
   scanf("%d", &matrix[x][y]);
}
}
if (col < lin)
a = col;
else
a = lin;
//mosrtrar resultados
printf("\nsua matriz ficou assim:\n");

  for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   if (x + y - 1 >= a  )
   printf(" [%d]",matrix[x][y]);
   else
   printf(" [ ]");
}
   printf("\n");
}}

void method18 ( )
{
int col,lin = 0;
   int x,y =0;
   int a;

do{

   printf ("Inisira a quantidade de colunas:");
   scanf("%d", &col);
   getchar ( );
   printf ("Inisira a quantidade de linhas:");
   scanf("%d", &lin);
   getchar ( );
}while (col < 0 && lin < 0);

  int matrix [lin][col];

for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   printf("\ninsira o valor:");
   scanf("%d", &matrix[x][y]);
}
}
if (col < lin)
a = col;
else
a = lin;
//mosrtrar resultados
printf("\nsua matriz ficou assim:\n");

  for (y = 1; y <=col; y= y +1)
{
for (x = 1; x <=lin; x= x +1)
{
   if (x + y - 1 <= a  )
   printf(" [%d]",matrix[x][y]);
   else
   printf(" [ ]");
}
   printf("\n");
}}

void method19 ( )
{
        int col,lin = 0;
        int x,y =0;
        int k = 0;

        do{

           printf ("Inisira a quantidade de colunas:");
           scanf("%d", &col);
           getchar ( );
           printf ("Inisira a quantidade de linhas:");
           scanf("%d", &lin);
           getchar ( );
        }while (col < 0 && lin < 0);

          int matrix [lin][col];

        for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
           printf("\ninsira o valor:");
           scanf("%d", &matrix[x][y]);
        }
        }
        //mosrtrar resultados
        printf("\nsua matriz ficou assim:\n");

          for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
        if (y > x){
           printf(" [%d]",matrix[x][y]);
            if (matrix[x][y] != 0)
            k = k +1;
          } else
           printf(" [ ]");
        }
           printf("\n");
        }
        if ( k == 0 )
        printf("\nos valores abaixo da diagonal sao zeros.\n");
        else
        printf("\nos valores abaixo da diagonal sao diferentes zeros.\n");
}


void method20 ( )
{
        int col,lin = 0;
        int x,y =0;
        int k = 0;

        do{

           printf ("Inisira a quantidade de colunas:");
           scanf("%d", &col);
           getchar ( );
           printf ("Inisira a quantidade de linhas:");
           scanf("%d", &lin);
           getchar ( );
        }while (col < 0 && lin < 0);

          int matrix [lin][col];

        for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
           printf("\ninsira o valor:");
           scanf("%d", &matrix[x][y]);
        }
        }
        //mosrtrar resultados
        printf("\nsua matriz ficou assim:\n");

          for (y = 1; y <=col; y= y +1)
        {
        for (x = 1; x <=lin; x= x +1)
        {
        if (y < x){
           printf(" [%d]",matrix[x][y]);
            if (matrix[x][y] != 0)
            k = k +1;
          } else
           printf(" [ ]");
        }
           printf("\n");
        }
        if ( k == 0 )
        printf("\nos valores acima da diagonal sao zeros.\n");
        else
        printf("\nos valores acima da diagonal sao diferentes zeros.\n");
}


int main ( void )
{
    int opcao = 0;

    printf("escolha o metodo\n");
    printf ("metodo 1 = 1\n");
    printf ("metodo 2 = 2\n");
    printf ("metodo 3 = 3\n");
    printf ("metodo 4 = 4\n");
    printf ("metodo 5 = 5\n");
    printf ("metodo 6 = 6\n");
    printf ("metodo 7 = 7\n");
    printf ("metodo 8 = 8\n");
    printf ("metodo 9 = 9\n");
    printf ("metodo 10 = 10\n");
    printf ("metodo 11 = 11\n");
    printf ("metodo 12 = 12\n");
    printf ("metodo 13 = 13\n");
    printf ("metodo 14 = 14\n");
    printf ("metodo 15 = 15\n");
    printf ("metodo 16 = 16\n");
    printf ("metodo 17 = 17\n");
    printf ("metodo 18 = 18\n");
    printf ("metodo 19 = 19\n");
    printf ("metodo 20 = 20\n");
    printf ( "Qual a sua opcao? " );
    scanf  ( "%d", &opcao );
    getchar( );

    switch ( opcao )
    {
         case 0: break;
         case 1: method01 ( ) ; break;
         case 2: method02 ( ) ; break;
         case 3: method03 ( ) ; break;
         case 4: method04 ( ) ; break;
         case 5: method05 ( ) ; break;
         case 6: method06 ( ) ; break;
         case 7: method07 ( ) ; break;
         case 8: method08 ( ) ; break;
         case 9: method09 ( ) ; break;
         //Exercicios
         case 10:method10 ( ) ; break;
         case 11:method11 ( ) ; break;
         case 12:method12 ( ) ; break;
         case 13:method13 ( ) ; break;
         case 14:method14 ( ) ; break;
         case 15:method15 ( ) ; break;
         case 16:method16 ( ) ; break;
         case 17:method17 ( ) ; break;
         case 18:method18 ( ) ; break;
         case 19:method19 ( ) ; break;
         case 20:method20 ( ) ; break;

    }


}
