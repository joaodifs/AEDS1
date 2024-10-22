#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s_ac
{
    int a;
    char c;
};
void method_01()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 0, y = 0, z = 0;
    for (x = 3; x < 7; x = x + 1)
    {
        z = array[x];
        for (y = x; y < 10; y = y + 1)
        {
            array[y] = array[y + 1];
        }
        array[y - 1] = z;
    }
    for (x = 0; x < 10; x = x + 1)
    {
        printf("%d ", array[x]);
    }
}
void method_02()
{
    int array[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int x = 0, y = 0, z = 0;
    for (x = 0; x < 3; x = x + 1)
    {
        z = array[2 - x][2 - x];
        for (y = 2; y >= 0; y = y - 1)
        {
            array[y][x] = array[x][y];
            if (x == y)
            {
                array[x][y] = z;
            }
        }
    }
    for (x = 0; x < 3; x = x + 1)
    {
        for (y = 0; y < 3; y = y + 1)
        {
            printf("%d\t", array[x][y]);
        }
        printf("\n");
    }
}
char *substring(int start, int end, char *source)
{
    char *destiny = NULL;
    int x = 0, y = 0;
    destiny = malloc(strlen(source) * sizeof(char));
    destiny[y] = '\0';
    for (x = start; x < end; x = x + 1)
    {
        destiny[y] = source[x];
        y = y + 1;
    }
    return (destiny);
}
int f04(int x, char *s)
{
    int result = 0;
    if (0 <= x && x < strlen(s))
    {
        result = (s[x] == '0' || s[x] == '1') && f04(x + 1, s);
    }
    else
    {
        result = 1;
    }
    return (result);
}
int f05(char *s1, char *s2)
{
    int result = 0;
    int x = 0, y = 0, z = 0;
    for (x = 0; x < strlen(s1); x = x + 1)
    {
        for (y = 1; y < strlen(s2); y = y + 1)
        {
            if (s1[x] == s2[y])
            {
                z = z + 1;
                y = strlen(s2);
            }
        }
    }
    result = (z == strlen(s1));
    return (result);
}
void method_06()
{
    struct s_ac s[5];
    int x = 0, y = 0;
    for (x = 0; x < 5; x = x + 1)
    {
        s[x].a = x;
        s[x].c = (char)('A' + x);
    }
    while (x > 0)
    {
        y = 5;
        while (y > 0)
        {
            if (x - 1 == s[y - 1].a)
            {
                printf("%d%c", s[y - 1].a, s[y - 1].c);
                y = 0;
            }
            y = y - 2;
        }
        x = x - 1;
    }
}
int f07(char *s)
{
    int achar = 0;
    int x = 0, y = 0, z = 0;
    for (x = 0; x < strlen(s); x = x + 1)
    {
        if (s[x] == '-')
        {
            if (0 <= x && x < strlen(s) && ((s[x - 1] == s[x + 1] && s[x + 1] == 'r') || (s[x - 1] == 'i')))
                achar = 1;
        }
    }
    return (achar);
}

void method08(void)
{
}

//
//-------------------------------------------------f9()
//
double calcmatrix(int n, int matrix[][n])
{
    int x, y = 0;
    double soma1 = 0.0, soma2 = 0.0;
    double razao = 0.0;

    for (x = 0; x < n; ++x)
    {
        for (y = 0; y < n; ++y)
        {
            if (x + y > n - 1)
            {
                soma1 = soma1 + matrix[x][y];
            }
            if (x < y)
            {
                soma2 = soma2 + matrix[x][y];
            }
        }
    }
    razao = (soma1 / soma2);
    return (razao);
} // end calcmatrix()
void method09(void)
{
    int n;
    int x, y;
    double razao = 0.0;
    printf("\ntamanho = ");
    scanf("%d", &n);
    printf("matriz quadrada, row = column");
    int matrix[n][n];

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            scanf("%d", &matrix[x][y]);
        }
    }

    razao = calcmatrix(n, matrix);
    printf("razao = %lf", razao);

} // end method09( )
//
//-------------------------------------------------f10()
//
void troca(int *x, int *y)
{
    int control = 0;
    if (*x > *y)
    {
        control = *x;
        *x = *y;
        *y = control;
    }
} // end troca( )
void method10(void)
{
    int x = 10;
    int y = 5;

    troca(&x, &y);

    printf("\nvalor x: %d", x);
    printf("\nvalor y: %d", y);

} // end method10( )

int main()
{
    int x = 0;
    printf("Opcoes\n");
    printf("1 - Questao 01\n");
    printf("2 - Questao 02\n");
    printf("3 - Questao 03\n");
    printf("4 - Questao 04\n");
    printf("5 - Questao 05\n");
    printf("6 - Questao 06\n");
    printf("7 - Questao 07\n");
    printf("8 - Questao 08\n");
    printf("9 - Questao 09\n");
    printf("10 - Questao 10\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        method_01();
        break;
    case 2:
        method_02();
        break;
    case 3:
        printf("%s", substring(4, 6, "abcde"));
        break;
    case 4:
        printf("%d", f04(3, "01lO"));
        break;
    case 5:
        printf("%d", f05("aroma", "amora"));
        break;
    case 6:
        method_06();
        break;
    case 7:
        printf("%d", f07("super-homem"));
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
        printf("Valor invalido");
        break;
    }
}
