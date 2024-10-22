// dependencias
#include "io.h" // para definicoes proprias
#include <locale.h> // para o portugues
int main ( )
{
    setlocale(LC_ALL,"Portuguese");
// definir dado
    int n = 0, i = 0, restox2 = 0, quant = 0; // 'a' e 'b' = limites // n = quantidade a ser testada
    double a=1.00, b=0.00, x=0.00;            // x = numeros a serem testados // quant = quantidade de numeros que respeitam as condições
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
    for(i=0; i<n; i=i+1)
    {
        IO_printf("\n %d° número real = ", i+1);
        scanf("%lf", &x);
        restox2 = (int)x%2;
        if( (x>=a && x<=b) && restox2 != 0 )
        {
            IO_printf(" está entre %.3lf e %.3lf e sua parte inteira é ímpar\n", a, b);
            quant=quant+1;
        }
    }
    IO_printf("\n\n Quantidade de números digitados que estão no intervalo e parte inteira é ímpar: %d", quant);

    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // fim main( )
