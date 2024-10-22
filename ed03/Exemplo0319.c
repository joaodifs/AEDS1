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
 IO_id ( "EXEMPLO0319 - Method11" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Palavra digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Letras min�sculas digitadas: ");

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
 IO_id ( "EXEMPLO0319 - Method12" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Palavra digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Letras min�sculas digitadas: ");

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
 IO_id ( "EXEMPLO0319 - Method13" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Palavra digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Letras min�sculas digitadas: ");

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
 IO_id ( "EXEMPLO0319 - Method14" );
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
 IO_id ( "EXEMPLO0319 - Method15" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma cadeia de caracteres: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Cadeia de caracteres digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("D�gitos: ");

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
 IO_id ( "EXEMPLO0319 - Method16" );
 // ler a palavra e mostrar
 IO_printf("\nDigite uma cadeia de caracteres: ");
 scanf("%s", palavra);
 tamanho = strlen(palavra);
 IO_printf("Cadeia de caracteres digitada: %s (%d)\n\n", palavra, tamanho);

 //para mostrar so as letras minusculas
 IO_printf("Diferente de d�gito e letra: ");

 for( x=0 ; x<tamanho ; x=x+1 )
 {
    if(!(((palavra[x] >='0') && (palavra[x] <= '9'))                                                    // n�o pode ser digito
          ||                                                                                           // ou
       (((palavra[x] >='a') && (palavra[x] <= 'z')) || ((palavra[x] >='A') && (palavra[x] <= 'Z'))))) // n�o pode ser letra
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

/**
 Method17 - contar e mostrar valores que estiverem dentro de um intervalo x e m�ltiplos de 5.
*/
void method17 ( )
{
// definir dado
int a = 1, b = 0, n = 0, x = 0, i = 0, restox = 0, quant = 0; // 'a' e 'b' = limites // n = quantidade a ser testada
 //limpar a tela                                       // x = numeros a serem testados // quant = quantidade de numeros que respeitam as condi��es
 system("cls");
// identificar
 IO_id ( "EXEMPLO0319 - Method17" );
 // ler valores
IO_printf("Digite os limites A e B do intervalo (A<B)");
while(!(a<b))
{
IO_printf("\n A = ");
scanf("%d", &a);
IO_printf(" B = ");
scanf("%d", &b);
}
IO_printf("\nDigite a quantidade de valores inteiros a serem testados (N)");
while(n<1)
{
IO_printf("\n N = ");
scanf("%d", &n);
}
IO_printf("\n-----------------------------------------------");
IO_printf("\nLimites: %d e %d", a, b);
IO_printf("\nQuantidade de valores a serem testados: %d", n);
IO_printf("\n-----------------------------------------------\n");
for(i=0;i<n;i=i+1)
{
IO_printf("\n %d� n�mero inteiro = ", i+1);
scanf("%d", &x);
restox = x%5;
if( (x>=a && x<=b) && restox == 0 )
{
IO_printf(" est� entre %d e %d e n�mero � m�ltiplo de 5\n", a, b);
quant=quant+1;
}
}
IO_printf("\n\n Quantidade de n�meros digitados que est�o no intervalo e s�o m�ltiplos de 5: %d", quant);
// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method17 ( )

/**
 Method18 - contar e mostrar valores que estiverem dentro de um intervalo x e m�ltiplos de 5 e n�o multiplos de 3.
*/
void method18 ( )
{
// definir dado
int a = 1, b = 0, n = 0, x = 0, i = 0, restox5 = 0, restox3 = 0, quant = 0; // 'a' e 'b' = limites // n = quantidade a ser testada
 //limpar a tela                                       // x = numeros a serem testados // quant = quantidade de numeros que respeitam as condi��es
 system("cls");
// identificar
 IO_id ( "EXEMPLO0319 - Method18" );
 // ler valores
IO_printf("Digite os limites A e B do intervalo (A<B)");
while(!(a<b))
{
IO_printf("\n A = ");
scanf("%d", &a);
IO_printf(" B = ");
scanf("%d", &b);
}
IO_printf("\nDigite a quantidade de valores inteiros a serem testados (N)");
while(n<1)
{
IO_printf("\n N = ");
scanf("%d", &n);
}
IO_printf("\n-----------------------------------------------");
IO_printf("\nLimites: %d e %d", a, b);
IO_printf("\nQuantidade de valores a serem testados: %d", n);
IO_printf("\n-----------------------------------------------\n");
for(i=0;i<n;i=i+1)
{
IO_printf("\n %d� n�mero inteiro = ", i+1);
scanf("%d", &x);
restox5 = x%5;
restox3 = x%3;
if( (x>=a && x<=b) && restox5 == 0 && restox3!= 0)
{
IO_printf(" est� entre %d e %d e n�mero � m�ltiplo de 5 e n�o de 3\n", a, b);
quant=quant+1;
}
}
IO_printf("\n\n Quantidade de n�meros digitados que est�o no intervalo e s�o m�ltiplos de 5 e n�o de 3: %d", quant);
// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method18 ( )

/**
 Method19 - contar e mostrar valores que estiverem dentro de um intervalo x que e parte inteira � �mpar
*/
void method19 ( )
{
// definir dado
int n = 0, i = 0, restox2 = 0, quant = 0; // 'a' e 'b' = limites // n = quantidade a ser testada
double a=1.00, b=0.00, x=0.00;                       // x = numeros a serem testados // quant = quantidade de numeros que respeitam as condi��es
 //limpar a tela
 system("cls");
// identificar
 IO_id ( "EXEMPLO0319 - Method19" );
 // ler valores
IO_printf("Digite os limites A e B do intervalo (A<B)");
while(!(a<b))
{
IO_printf("\n A = ");
scanf("%lf", &a);
IO_printf(" B = ");
scanf("%lf", &b);
}
IO_printf("\nDigite a quantidade de valores inteiros a serem testados (N)");
while(n<1)
{
IO_printf("\n N = ");
scanf("%d", &n);
}
IO_printf("\n-----------------------------------------------");
IO_printf("\nLimites: %.3lf e %.3lf", a, b);
IO_printf("\nQuantidade de valores a serem testados: %d", n);
IO_printf("\n-----------------------------------------------\n");
for(i=0;i<n;i=i+1)
{
IO_printf("\n %d� n�mero real = ", i+1);
scanf("%lf", &x);
restox2 = (int)x%2;
if( (x>=a && x<=b) && restox2 != 0 )
{
IO_printf(" est� entre %.3lf e %.3lf e sua parte inteira � �mpar\n", a, b);
quant=quant+1;
}
}
IO_printf("\n\n Quantidade de n�meros digitados que est�o no intervalo e parte inteira � �mpar: %d", quant);

// encerrar
 getchar();
 IO_pause ( "\nApertar ENTER para continuar" );
} // fim method19 ( )

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
    setlocale(LC_ALL,"Portuguese"); //
// definir dado
 int x = 0;
// repetir at� desejar parar
 do
 {
     system("cls");
 // identificar
 IO_id ( "EXEMPLO0319 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "11 - mostrar as letras min�sculas." );
 IO_println ( "12 - contar e mostrar as letras min�sculas." );
 IO_println ( "13 - contar e mostrar as letras min�sculas de tras para frente." );
 IO_println ( "14 - contar e mostrar todos s�mbolos que forem letras, ou mai�sculas ou min�sculas. " );
 IO_println ( "15 - contar e mostrar todos os d�gitos, percorrendo do fim para o in�cio da cadeia de caracteres. " );
 IO_println ( "16 - contar e mostrar tudo o que n�o for d�gito e tamb�m n�o for letra. " );
 IO_println ( "17 - contar e mostrar valores que estiverem dentro de um intervalo x e m�ltiplos de 5. " );
 IO_println ( "18 - contar e mostrar valores que estiverem dentro de um intervalo x, m�ltiplos de 5 e n�o m�ltiplos de 3. " );
 IO_println ( "19 - contar e mostrar valores que estiverem dentro de um intervalo x que e parte inteira � �mpar. " );


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
 case 17:
 method17 ( );
 break;
 case 18:
 method18 ( );
 break;
 case 19:
 method19 ( );
 break;
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,11, 12, 13, 14, 15, 16, 17, 18, 19] (",
 IO_concat ( IO_toString_d ( x ), ")\n Apertar ENTER para retornar" ) ) );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
