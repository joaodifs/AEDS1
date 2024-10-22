/*
 Exercicios lista 1 ao 10.
 Autor: Joao Gabriel Dias Freire
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
 exercicio00 - nao faz nada.
*/
void exercicio00 ( )
{
// nao faz nada
} // fim method00 ( )

/**
 exercicio01
*/
void exercicio01 ( )
{
 system("cls"); // limpar tela
//dados
int quant = 0;
int x = 0;
int resto = 0;
// identificar
 IO_id ( "EXERCICIO 1 - exercicio01 " );
//acoes
printf("Digite a quantidade: ");
scanf("%d", &quant);
while(quant>0)
{
    printf("Digite o numero para ver seus divisores: ");
    scanf("%d", &x);
    printf("Os divisores de %d sao: ",x);
    if(x>0)
    {
        for(int i=1; i<=x/2; i=i+1)
        {
            resto = x%i;
            if(resto==0)
            {
                printf("%d, ",i);
            }
        }
            printf("%d.\n ",x);
    }
    if(x<0)
    {
        for(int i=-1; i>=x/2; i=i-1)
        {
            resto = x%i;
            if(resto==0)
            {
                printf("%d, ",i);
            }
        }
        printf("%d.\n ",x);
    }
    getchar();
    quant=quant-1;
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio01 ( )

/**
 exercicio02
*/
void exercicio02 ( )
{
 system("cls"); // limpar tela
//dados
int quant = 0;
int x = 0;
int resto = 0;
int cont = 0;
// identificar
 IO_id ( "EXERCICIO 2 - exercicio02 " );
//acoes
printf("Digite a quantidade: ");
scanf("%d", &quant);
while(quant>0)
{
    printf("Digite o numero para saber se e primo: ");
    scanf("%d", &x);
    printf("%d e um numero primo?: ",x);
    cont = 0;
    if(x>0)
    {
        for(int i=2; i<=x/2; i=i+1)
        {
            resto = x%i;
            if(resto==0)
            {
                cont = cont+1;
            }
        }
    }
    if(x<0)
    {
        for(int i=-2; i>=x/2; i=i-1)
        {
            resto = x%i;
            if(resto==0)
            {
                cont = cont+1;
            }
        }
    }
    if(cont==0)
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
    getchar();
    quant=quant-1;
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio02 ( )

/**
 exercicio03.
*/
void exercicio03 ( )
{
 system("cls"); // limpar tela
//dados
char palavra[80] = "0";
int tamanho = 0;
int x = 0;
// identificar
 IO_id ( "EXERCICIO 3 - exercicio03 " );
 // acoes
 IO_printf("\nDigite alguns caracteres: ");
 scanf("%s", palavra);
 getchar();
 tamanho = strlen(palavra);
 x=tamanho;
 while(x>=0)
 {
     if(palavra[x]=='+' || palavra[x]=='-' || palavra[x]=='*' || palavra[x]=='/' || palavra[x]=='%')
     {
         printf("''%c'' = Aritmetico\n", palavra[x]);
     }
     else
     {
         if(palavra[x]=='|' || palavra[x]=='&' || palavra[x]=='!')
         {
             printf("''%c'' = Operador Logico\n", palavra[x]);
         }
         else
         {
             if(palavra[x]== '.' || palavra[x]==':' || palavra[x]==',' || palavra[x]==';' || palavra[x]=='_')
             {
                 printf("''%c'' = Separador\n", palavra[x]);
             }
             else
             {
                 if(palavra[x]=='<' || palavra[x]=='=' || palavra[x]=='>')
                 {
                     printf("''%c'' = Relacional\n", palavra[x]);
                 }
                 else
                 {
                     printf("''%c'' = Tipo nao identificado\n", palavra[x]);
                 }
            }
         }
      }

     x=x-1;
 }

// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio03 ( )

/**
 exercicio04.
*/
void exercicio04 ( )
{
 system("cls"); // limpar tela
//dados
char palavra[80] = "0";
int tamanho = 0;
int x = 0;
int operador=0,minuscula=0,maiuscula=0,digito=0,separador=0;
// identificar
 IO_id ( "EXERCICIO 4 - exercicio04 " );
 // acoes
 IO_printf("\nDigite alguns caracteres: ");
 scanf("%s", palavra);
 getchar();
 tamanho = strlen(palavra);
 x=tamanho;
 while(x>=0)
 {
    if(palavra[x]>='A' && palavra[x]<='Z')
    {
        maiuscula = maiuscula +1;
    }
    else
    {
        if(palavra[x]>='a' && palavra[x]<='z')
        {
            minuscula = minuscula +1;
        }
        else
        {
         if(palavra[x]=='+' || palavra[x]=='-' || palavra[x]=='*' || palavra[x]=='/' ||
            palavra[x]=='%' || palavra[x]=='|' || palavra[x]=='&' || palavra[x]=='!' ||
            palavra[x]=='<' || palavra[x]=='=' || palavra[x]=='>')
         {
             operador = operador +1;
         }
         else
         {
            if(palavra[x]== '.' || palavra[x]==':' || palavra[x]==',' || palavra[x]==';' || palavra[x]=='_')
            {
                separador = separador + 1;
            }
            else
            {
                if(palavra[x]>='0' && palavra[x]<='9')
                {
                    digito = digito +1;
                }
            }
        }
    }
    }
    x=x-1;
}
printf("Maiusculas: %d\nMinusculas: %d\nDigitos: %d\nOperadores: %d\nSeparadores: %d",maiuscula,minuscula,digito,operador,separador);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio04 ( )

/**
 exercicio05.
*/
void exercicio05 ( )
{
 system("cls"); // limpar tela
//dados
int n = 0;
double x = 0.00;
double media = 0.00;
double soma1 = 0.00;
int quant1 = 0;
double soma2 = 0.00;
int quant2 = 0;
double soma3 = 0.00;
int quant3 = 0;
// identificar
 IO_id ( "EXERCICIO5 - exercicio05 " );
//acoes
IO_printf("\n Quantidade = ");
scanf("%d", &n);
while(n>0)
{
    IO_printf("\nDigite o numero(real): ");
    scanf("%lf", &x);
    getchar();
    if(x<-23.75)
    {
        soma1 = soma1 + x;
        quant1 = quant1 + 1;
    }
    else
    {
        if(x>65.25)
        {
            soma2 = soma2 + x;
            quant2 = quant2 + 1;
        }
        else
        {
            soma3 = soma3 + x;
            quant3 = quant3 + 1;
        }
    }
    n=n-1;
}
media = soma1/quant1;
IO_printf("\nMedia dos menores que -23.75: %lf",media);
media = 0;
media = soma2/quant2;
IO_printf("\nMedia dos maiores que 65.25: %lf",media);
media = 0;
media = soma3/quant3;
IO_printf("\nMedia dos numeros entre estes dois: %lf",media);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio05 ( )

/**
 exercicio06.
*/
void exercicio06 ( )
{
 system("cls"); // limpar tela
// definir dado
int a=0,b=0,x=0;
double soma = 0.00;
// identificar
 IO_id ( "EXERCICIO 6 - exercicio06 " );
//acoes
do
{
printf("Digite um numero para o intervalo menor: ");
scanf("%d",&a);
getchar();
printf("Digite um numero para o intervalo maior: ");
scanf("%d",&b);
getchar();
} while(a>b);
do
{
    printf("Digite um valor: ");
    scanf("%d",&x);
    getchar();
    if(x%2!=0)
    {
        if(x>a && x<b)
        {
            soma = soma + pow(x,-3);
        }
    }
}while(x!=-1);
printf("Soma dos cubos inversos dos numeros impares do intervalo: %lf",soma);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio06 ( )

/**
 exercicio07.
*/
void exercicio07 ( )
{
 system("cls"); // limpar tela
// definir dado
double a=0,b=0,x=0;
double porcent = 0.00;
double quantdentro=0,quantmeA=0,quantmaB=0,quantT=0;
// identificar
 IO_id ( "EXERCICIO 7 - exercicio07 " );
//acoes
do
{
printf("Digite um numero para o intervalo menor: ");
scanf("%lf",&a);
getchar();
printf("Digite um numero para o intervalo maior: ");
scanf("%lf",&b);
getchar();
} while(a>b);

do
{
    printf("Digite um valor: ");
    scanf("%lf",&x);
    getchar();
    if(x!=0)
    {
        if(x>a && x<b)
        {
            quantdentro = quantdentro + 1;
        }
        else
        {
            if(x<=a)
            {
                quantmeA = quantmeA + 1;
            }
            else
            {
                quantmaB = quantmaB + 1;
            }
        }
    }
}while(x!=0);
quantT=quantdentro+quantmeA+quantmaB;
printf("\nDentro: %lf // Fora: %lf\n",quantdentro,quantmeA+quantmaB);
porcent=quantmeA/quantT*100;
printf("Porcentagem dos numeros abaixo do intervalo: %lf%\n",porcent);
porcent=quantmaB/quantT*100;
printf("Porcentagem dos numeros abaixo do intervalo: %lf%\n",porcent);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio07 ( )

/**
 exercicio08.
*/
void exercicio08 ( )
{
 system("cls"); // limpar tela
// definir dado
float x = 0.0;
float y = 0.0;
float z = 0.0;
// identificar
 IO_id ( "EXERCICIO 8 - exercicio08 " );
//acoes
IO_printf("\nDigite um numero: ");
scanf("%d", &x);
getchar();
IO_printf("\nDigite um numero: ");
scanf("%d", &y);
getchar();
IO_printf("\nDigite um numero: ");
scanf("%d", &z);
if(x>y && y>z)
{
    printf("Valores em ordem decrescente.");
}
else
{
    if(x<y && y<z)
    {
        printf("Valores em ordem Crescente.");
    }
    else
    {
        printf("Valores sem ordem crescente ou decrescente.");
    }
}
getchar();
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio08 ( )


/**
 exercicio09.
*/
void exercicio09 ( )
{
 system("cls"); // limpar tela
//dados
char a ='0';
char b = '0';
char c = '0';
// identificar
 IO_id ( "EXERCICIO 9 - exercicio09 " );
//acoes
IO_printf("\nDigite uma letra: ");
scanf("%c", &a);
getchar();
IO_printf("\nDigite uma letra: ");
scanf("%c", &b);
getchar();
IO_printf("\nDigite uma letra: ");
scanf("%c", &c);
getchar();
if(a>b && b>c)
{
    printf("Letras com valores em ordem decrescente.");
}
else
{
    if(a<b && b<c)
    {
        printf("Letras com valores em ordem crescente.");
    }
    else
    {
        printf("Letras com valores sem ordem crescente ou decrescente.");
    }
}
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio09 ( )

/**
 .
*/
void exercicio10 ( )
{
 system("cls"); // limpar tela
 // definir dados
char palavra1[80] = "0";
int tamanho1 = 0;
char palavra2[80] = "0";
int tamanho2 = 0;
char palavra3[80] = "0";
int tamanho3 = 0;
int maior = 0, menor = 10000;
// identificar
 IO_id ( "EXERCICIO 10 - exercicio10" );
//acoes
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra1);
 getchar();
 tamanho1 = strlen(palavra1);
 IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra2);
 getchar();
 tamanho2 = strlen(palavra2);
  IO_printf("\nDigite uma palavra: ");
 scanf("%s", palavra3);
 getchar();
 tamanho3 = strlen(palavra3);
 if(tamanho1>maior)
 {
     maior=tamanho1;
     if(tamanho2>maior)
     {
         maior = tamanho2;
         if (tamanho3>maior)
         {
             maior = tamanho3;
         }
     }
 }
  if(tamanho1<menor)
 {
     menor=tamanho1;
     if(tamanho2<menor)
     {
         menor = tamanho2;
         if (tamanho3<menor)
         {
             menor = tamanho3;
         }
     }
 }
 if(strcmp(palavra1,palavra2) < 0 && strcmp(palavra2,palavra3) < 0)
 {
    printf("Cadeias em ordem crescente");
 }
 else
 {
     if(strcmp(palavra1,palavra2)>0 && strcmp(palavra2,palavra3) >0)
     {
         printf("Cadeias em ordem decrescente");
     }
     else
     {
         printf("Cadeias sem ordem crescente ou decrescente.\n");
         if(tamanho1==menor)
         {
             printf("Menor cadeia: %s\n",palavra1);
         }
         else
         {
             if(tamanho2==menor)
             {
                 printf("Menor cadeia: %s\n",palavra2);
             }
             else
             {
                 printf("Menor cadeia: %s\n",palavra3);
             }
         }
         if(tamanho1==maior)
         {
             printf("Maior cadeia: %s\n",palavra1);
         }
         else
         {
             if(tamanho2==maior)
             {
                 printf("Maior cadeia: %s\n",palavra2);
             }
             else
             {
                 printf("Maior cadeia: %s\n",palavra3);
             }
         }

     }

 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim exercicio10 ( )

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
 IO_id ( "Ex. 1 ao 10" );

 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - Encerrar" );
 IO_println ( " 1 - Mostrar divisores." );
 IO_println ( " 2 - Falar se e primo." );
 IO_println ( " 3 - Falar qual o tipo de caractere." );
 IO_println ( " 4 - Contar tipo de caracteres." );
 IO_println ( " 5 - Media dos numeros em determinados intervalos." );
 IO_println ( " 6 - Mostrar soma dos cubos inversos dos impares em um intervalo" );
 IO_println ( " 7 - Contar valores dentro e fora de um intervalo, mostrar porcentagens dos de fora." );
 IO_println ( " 8 - Comparar numeros reais" );
 IO_println ( " 9 - Comparar caracteres" );
 IO_println ( " 10 - Comparar cadeias de caracteres ");
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );

 // testar valor
 switch ( x )
 {
 case 0:
 exercicio00 ( );
 break;
 case 1:
 exercicio01 ( );
 break;
 case 2:
 exercicio02 ( );
 break;
 case 3:
 exercicio03 ( );
 break;
 case 4:
 exercicio04 ( );
 break;
 case 5:
 exercicio05 ( );
 break;
 case 6:
 exercicio06 ( );
 break;
 case 7:
 exercicio07 ( );
 break;
 case 8:
 exercicio08 ( );
 break;
 case 9:
 exercicio09 ( );
 break;
 case 10:
 exercicio10 ( );
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
