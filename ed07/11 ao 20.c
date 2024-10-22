#include <stdio.h>
#include <math.h>
#include "io.h"
#include <string.h>

void method00()
{
}

int funcao01(int n)
{
    n = 2 * n - 1;
    int poten = 3 * n;
    return (poten);
}
void method01()
{
    int x = 0;
    x = IO_readint("Entre com um numero inteiro: ");
    printf("{ ");
    for (int i = 1; i <= x; i++)
    {
        int y = funcao01(i);
        printf("%i, ", y);
    }
    printf("}");
}

int funcao02(int n)
{
    n = n * 2;
    int poten = 3 * n;
    return (poten);
}
void method02()
{
    int x = 0;
    x = IO_readint("Entre com um numero inteiro: ");
    printf("{ ");
    for (int i = x; i > 0; i = i - 1)
    {
        int y = funcao02(i);
        printf("%i, ", y);
    }
    printf("}");
}

int funcao03(int n)
{
    int poten = 0;
    poten = pow(5, n);
    return (poten);
}
void method03()
{
    int x = 0;
    x = IO_readint("Entre com um numero inteiro: ");
    printf("{ ");
    for (int i = 0; i < x; i++)
    {
        int y = funcao03(i);
        printf("%i, ", y);
    }
    printf("}");
}

int funcao04(int n)
{
    int poten = 0;
    poten = pow(3, n);
    return (poten);
}
void method04()
{
    int x = 0;
    x = IO_readint("Entre com um numero inteiro: ");
    printf("{ ");
    for (int i = x - 1; i >= 0; i = i - 1)
    {
        int y = funcao04(i);
        printf("1/%i, ", y);
    }
    printf("}");
}

int funcao05(int n, int m)
{
    int poten = 0;
    if (n > 0)
    {
        n = 2 * n - 1;
        poten = pow(m, n);
        return (poten);
    }
    else
    {
        poten = pow(m, n);
        return (poten);
    }
}
void method05()
{
    int x = 0;
    x = IO_readint("Entre com um numero inteiro: ");
    printf("{ ");
    for (int i = 0; i < x; i++)
    {
        int y = funcao05(i, x);
        printf("1/%i, ", y);
    }
    printf("}");
}

void method06()
{
    int x = 0;
    double soma = 0;
    FILE *arquivo = fopen("RESULTADO06.TXT", "wt");
    x = IO_readint("Entre com um numero inteiro: ");
    for (int i = 0; i < x; i++)
    {
        double y = funcao05(i, x);
        soma = 1 / y;
        fprintf(arquivo, "1/%lf = %.30lf\n ", y, soma);
        printf("(1/%lf = %lf)\n", y, soma);
        if (i < x - 1)
        {
            printf(" + ");
        }
    }
    printf(" = %lf", soma);
    fclose(arquivo);
}

int funcao07(int n)
{
    int poten = 0;
    poten = pow(3, n);
    return (poten);
}
void method07()
{
    int x = 0;
    double soma = 0;
    double soma2 = 0;
    FILE *arquivo = fopen("RESULTADO07.TXT", "wt");
    x = IO_readint("Entre com um numero inteiro: ");
    printf("{ ");
    for (int i = x - 1; i >= 0; i = i - 1)
    {
        int y = funcao04(i);
        printf("1/%i, ", y);
        soma = 1.0 / y;
        soma2 = soma2 + soma;
        fprintf(arquivo, "1/%i + 1/%lf = %lf\n ", y, soma, soma2);
    }
    printf("}");
    fclose(arquivo);
}


int fibo (int n){
    int f1 = 0;
    int f2 = 1;
    int f3;
    FILE *arquivo = fopen("RESULTADO08.TXT", "wt");
    for (int x = 0;x < n; x++) {
            f3 = f2 + f1;
            if (f3 % 2 == 0){
            printf("%i - %i\n ", x+1, f3);
            fprintf(arquivo, "%i\n", f3);
            } else {
                x = x - 1;
            }
            f1 = f2;
            f2 = f3;
        }
    fclose(arquivo);
}
void method08()
{
    int f1 = 0;
    int f2 = 1;
    int f3;
    int x = 0;
    x = IO_readint("Entre com um numero inteiro positivo: ");
    int y = fibo (x);

}

int maiuscula (char str [80], int x){
    FILE *arquivo = fopen("RESULTADO09.TXT", "wt");
    char str2 [80];
    int contador = 0;
    for (int i = 0; i<x; i++){
        if (str [i] >= 'A' && str[i] <= 'Z'){
            str2 [contador] = str [i];
            contador ++;
        }
    }
    printf("Antes: %s  -  Depois: %s\n", str, str2);
    fprintf(arquivo, "Antes: %s  -  Depois: %s\n", str, str2);
    fclose(arquivo);
    return (0);
}

void method09()
{
    int x;
    char str [80]= "/0"
    printf ("Entre com uma cadeia de caracteres: ");
    gets (str);
    x = strlen(str);
    int y = maiuscula (str, x);
}


int sete (char str [80], int x){
    FILE *arquivo = fopen("RESULTADO09.TXT", "wt");
    char str2 [80];
    int contador = 0;
    for (int i = 0; i<x; i++){
        if (str [i] >= '7' && str [i] <= '9'){
            str2 [contador] = str [i];
            contador ++;
        }
    }
    printf("Antes: %s  -  Depois: %s\n", str, str2);
    fprintf(arquivo, "Antes: %s  -  Depois: %s\n", str, str2);
    fclose(arquivo);
    return (0);
}
void method10()
{
    int x;
    char str [80];
    printf ("Entre com uma cadeia de caracteres: ");
    gets (str);
    x = strlen(str);
    int y = sete (str, x);
}

int main(int argc, char *argv[])
{
    int x = 0;
    do
    {
        IO_println("Opcoes");
        IO_println("0 - parar");
        IO_println("1 - ");
        IO_println("2 - ");
        IO_println("3 - ");
        IO_println("4 - ");
        IO_println("5 - ");
        IO_println("6 - ");
        IO_println("7 - ");
        IO_println("8 - ");
        IO_println("9 - ");
        IO_println("10 - ");
        x = IO_readint("Entrar com uma opcao: ");

        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        }
    } while (x != 0);
    IO_pause("Apertar ENTER para terminar");
    return (0);
}

