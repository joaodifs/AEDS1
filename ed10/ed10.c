#include <stdio.h>
#include <math.h>
#include "io.h"
#include <string.h>
#ifndef __IO_REFS__
#define __IO_REFS__

#define null NULL

#define addr(p) (&p)
#define ref *
#define deref (*(p))

#define var &
#endif

typedef struct m_int
{
    int x;
    int y;
    int rows;
    int columns;
    int **data;
} m_INTS;

typedef m_INTS *
    ref_M_INTS;

typedef struct s_a_int
{
    int x;
    int tamanho;
    ints data;
} array_INT;

typedef array_INT *
    ref_array_INT;

ref_array_INT array_new()
{
    int n = IO_readint("Qual o tamanho desejado do arranjo? ");
    ref_array_INT copia;
    bool OK = true;
    if (n > 0)
    {
        copia = (ref_array_INT)malloc(1 * sizeof(array_INT));
    }
    else
    {
        printf("Tamanho invalido de arranjo. ");
    }
    if (copia)
    {
        copia->x = 0;
        copia->tamanho = n;
        copia->data = (ints)malloc(n * sizeof(int));
    }
    else
    {
        printf("Erro na alocacao.");
    }
    return (copia);
}

ref_array_INT gerarRandomINT(int inf, int sup, ref_array_INT copia)
{
    int x = 0;
    srand(time(null));
    for (int i = 0; i < copia->tamanho; i++)
    {
        x = rand() % (sup + 1);
        if (x < inf)
        {
            x = x + inf;
        }
        copia->data[i] = x;
    }
    return (copia);
}

ref_array_INT array_rand(ref_array_INT copia)
{
    int tamanho = copia->tamanho;
    FILE *arquivo = fopen("DADOS1.txt", "wt");
    int sup = IO_readint("\nEntre com o limite superior: ");
    int inf = IO_readint("\nAgora com o inferior: ");
    fprintf(arquivo, "%d\n", copia->tamanho);
    copia = gerarRandomINT(inf, sup, copia);
    for (copia->x = 0; copia->x < copia->tamanho; copia->x = copia->x + 1)
    {
        printf("%d - %d\n", copia->x + 1, copia->data[copia->x]);
        fprintf(arquivo, "%d\n", copia->data[copia->x]);
    }
    printf("\n");
    fclose(arquivo);
}

ref_array_INT array_newscan(int n, ref_array_INT copia)
{
    bool OK = true;
    if (n > 0)
    {
        copia = (ref_array_INT)malloc(1 * sizeof(array_INT));
    }
    else
    {
        printf("Tamanho invalido de arranjo. ");
    }
    if (copia)
    {
        copia->x = 0;
        copia->tamanho = n;
        copia->data = (ints)malloc(n * sizeof(int));
    }
    else
    {
        printf("Erro na alocacao.");
    }
    return (copia);
}

ref_array_INT array_fscanf(chars fileName)
{
    FILE *arquivo = fopen(fileName, "r");
    int tamanho;
    fscanf(arquivo, "%d", &tamanho);
    ref_array_INT copia;
    copia = array_newscan(tamanho, copia);
    if (copia && copia->data)
    {
        if (tamanho > 0)
        {
            copia->tamanho = tamanho;
            for (copia->x = 0; copia->x < tamanho; copia->x = copia->x + 1)
            {
                fscanf(arquivo, "%d", &copia->data[copia->x]);
            }
            printf("\n");
        }
    }
    fclose(arquivo);
    return (copia);
}

ref_array_INT array_procura(ref_array_INT copia)
{
    int x = 0;
    bool teste = false;
    copia = array_fscanf("DADOS1.txt");
    x = IO_readint("\nEntre com o valor inteiro que deseja procurar: ");
    printf("\n");
    for (int i = 0; i < copia->tamanho; i++)
    {
        if (x == copia->data[i])
        {
            if (teste)
            {
                printf("e na posicao %d\n", i);
            }
            else
            {
                printf("Foi encontrado o valor %d na posicao %d do arranjo\n", copia->data[i], i);
                teste = true;
            }
        }
    }
    if (!teste)
    {
        printf("O valor desejado nao foi encontrado no arranjo.\n");
    }
    return (copia);
}

void array_print(ref_array_INT copia)
{
    for (copia->x = 0; copia->x < copia->tamanho; copia->x = copia->x + 1)
    {
        printf("[%d] ", copia->data[copia->x]);
    }
}

void array_comp()
{
    int tamanho = 0;
    int contador = 0;
    ref_array_INT arranjo1;
    ref_array_INT arranjo2;
    arranjo1 = array_fscanf("DADOS1.txt");
    arranjo2 = array_fscanf("DADOS2.txt");
    if (arranjo1->tamanho == arranjo2->tamanho)
    {
        tamanho = arranjo1->tamanho;
        printf("PRIMEIRO ARRANJO: ");
        for (int x = 0; x < tamanho; x++)
        {
            printf("[%d]", arranjo1->data[x]);
        }
        printf("\n");
        printf("SEGUNDO ARRANJO: ");
        for (int x = 0; x < tamanho; x++)
        {
            printf("[%d]", arranjo2->data[x]);
        }
        printf("\n");
        for (int x = 0; x < tamanho; x++)
        {
            if (arranjo1->data[x] == arranjo2->data[x])
            {
                contador = contador + 1;
            }
        }
        if (contador > 0)
        {
            printf("Os dois arranjos tem o mesmo tamanho e %d valores iguais\n", contador);
        }
        else
        {
            printf("Os arranjos nao tem nenhum valor igual porem tem o mesmo tamanho.\n");
        }
    }
    else
    {
        printf("(ARRAY_COMP) ERROR: ARRANJOS COM TAMANHOS DIFERENTES\n");
    }
}

ref_array_INT array_soma(ref_array_INT copia)
{
    int x = 0;
    int tamanho = 0;
    ref_array_INT arranjo1;
    ref_array_INT arranjo2;
    arranjo1 = array_fscanf("DADOS1.txt");
    arranjo2 = array_fscanf("DADOS2.txt");
    if (arranjo1->tamanho == arranjo2->tamanho)
    {
        printf("\nPrimeiro Arranjo: ");
        array_print(arranjo1);
        printf("\nSegundo Arranjo: ");
        array_print(arranjo2);
        printf("\nSoma dos dois arranjos: ");
        tamanho = arranjo1->tamanho;
        copia = array_newscan(tamanho, copia);
        for (x = 0; x < tamanho; x++)
        {
            copia->data[x] = arranjo1->data[x] + arranjo2->data[x];
        }
    }
    else
    {
        printf("(ARRAY_COMP) ERROR: ARRANJOS COM TAMANHOS DIFERENTES\n");
    }
    return (copia);
}

void array_teste_crescente(ref_array_INT copia)
{
    int tamanho = 0;
    int contador = 0;
    copia = array_fscanf("DADOS1.txt");
    bool OK = true;
    tamanho - copia->tamanho;
    for (int x = 0; x < tamanho; x++)
    {
        do
        {
            if (copia->data[x] < copia->data[x + 1])
            {
                contador = contador + 1;
            }
            x++;
        } while (OK);
    }
    if (contador == tamanho)
    {
        printf("\nO arranjo esta em ordem crescente\n");
    }
    else
    {
        printf("\nO arranjo nao esta em ordem crescente\n");
    }
}

ref_M_INTS m_INTS_fprintf(ref_M_INTS copia)
{
    FILE *arquivo = fopen("matriz.txt", "wt");
    if (copia && copia->data)
    {
        fprintf(arquivo, "%i\n", copia->rows);
        fprintf(arquivo, "%i\n", copia->columns);
        for (copia->x = 0; copia->x < copia->rows; copia->x++)
        {
            for (copia->y = 0; copia->y < copia->columns; copia->y++)
            {
                fprintf(arquivo, "%i ", copia->data[copia->x][copia->y]);
            }
            fprintf(arquivo, "\n");
        }
    }
    fclose(arquivo);
}

ref_M_INTS m_INTSnewprinc(int ref rows, int ref columns)
{
    ref_M_INTS copia;
    bool OK = true;
    int linhas = IO_readint("\nEntre com o numero de linhas: ");
    int colunas = IO_readint("\nAgora com o numero de colunas: ");
    if (linhas > 0 && colunas > 0)
    {
        copia = (ref_M_INTS)malloc(1 * sizeof(m_INTS));
    }
    else
    {
        printf("\n(m_INTS_new) ERRO: NUMERO INVALIDO DE LINHAS E COLUNAS");
    }
    if (copia)
    {
        copia->x = 0;
        copia->y = 0;
        copia->rows = linhas;
        copia->columns = colunas;
        copia->data = (int **)malloc(linhas * sizeof(int *));

        for (copia->x = 0; copia->x < linhas; copia->x++)
        {
            copia->data[copia->x] = (int *)malloc(colunas * sizeof(int));
            OK = OK && (copia->data[copia->x]);
        }
        if (OK)
        {
            (*(rows)) = linhas;
            (*(columns)) = colunas;
            return (copia);
        }
        else
        {
            printf("\n(m_INTS_new) ERRO: PROBLEMA NA ALOCACAO DE DADOS");
        }
    }
}

ref_M_INTS m_INTS_newsecun(int linhas, int colunas)
{
    ref_M_INTS copia;
    bool OK = true;
    if (linhas > 0 && colunas > 0)
    {
        copia = (ref_M_INTS)malloc(1 * sizeof(m_INTS));
    }
    else
    {
        printf("\n(m_INTS_new) ERRO: NUMERO INVALIDO DE LINHAS E COLUNAS");
    }
    if (copia)
    {
        copia->x = 0;
        copia->y = 0;
        copia->rows = linhas;
        copia->columns = colunas;
        copia->data = (int **)malloc(linhas * sizeof(int *));

        for (copia->x = 0; copia->x < linhas; copia->x++)
        {
            copia->data[copia->x] = (int *)malloc(colunas * sizeof(int));
            OK = OK && (copia->data[copia->x]);
        }
        if (OK)
        {
            return (copia);
        }
        else
        {
            printf("\n(m_INTS_new) ERRO: PROBLEMA NA ALOCACAO DE DADOS");
        }
    }
}

ref_M_INTS m_INTS_print(ref_M_INTS copia)
{
    if (copia && copia->data)
    {
        for (copia->x = 0; copia->x < copia->rows; copia->x++)
        {
            for (copia->y = 0; copia->y < copia->columns; copia->y++)
            {
                printf("%d ", copia->data[copia->x][copia->y]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

ref_M_INTS m_INTS_inic(ref_M_INTS copia)
{
    if (copia && copia->data)
    {
        for (copia->x = 0; copia->x < copia->rows; copia->x++)
        {
            for (copia->y = 0; copia->y < copia->columns; copia->y++)
            {
                printf("\n[%d][%d] = ", copia->x + 1, copia->y + 1);
                copia->data[copia->x][copia->y] = IO_readint("");
            }
        }
        printf("\n");
    }
    return (copia);
}

ref_M_INTS m_INTS_newscan(int linhas, int colunas)
{
    ref_M_INTS copia;
    bool OK = true;
    copia = (ref_M_INTS)malloc(1 * sizeof(m_INTS));
    if (linhas > 0 && colunas > 0)
    {
        copia->x = 0;
        copia->y = 0;
        copia->rows = linhas;
        copia->columns = colunas;
        copia->data = (int **)malloc(linhas * sizeof(int *));

        for (copia->x = 0; copia->x < linhas; copia->x = copia->x + 1)
        {
            copia->data[copia->x] = (int *)malloc(colunas * sizeof(int));
            OK = OK && (copia->data[copia->x]);
        }
        if (!OK)
        {
            printf("\n(m_INTS_new_scan) ERRO: PROBLEMA NA ALOCACAO DE DADOS");
        }
    }
    else
    {
        printf("\n(m_INTS_new_scan) ERRO: NUMERO INVALIDO DE LINHAS E COLUNAS");
    }
    return (copia);
}

ref_M_INTS m_INTS_fscanf(chars filename)
{
    int linhas = 0;
    int colunas = 0;
    FILE *arquivo = fopen(filename, "r");
    fscanf(arquivo, "%d", &linhas);
    fscanf(arquivo, "%d", &colunas);
    ref_M_INTS copia;
    copia = m_INTS_newscan(linhas, colunas);
    if (copia && copia->data)
    {
        if (copia->columns > 0 && copia->rows > 0)
        {
            for (copia->x = 0; copia->x < copia->rows; copia->x = copia->x + 1)
            {
                for (copia->y = 0; copia->y < copia->columns; copia->y = copia->y + 1)
                {
                    fscanf(arquivo, "%d", &copia->data[copia->x][copia->y]);
                }
            }
        }
        else
        {
            printf("(INTS_fscanf) ERRO: VALORES INVALIDOS NO ARQUIVO.\n");
        }
    }
    fclose(arquivo);
    return (copia);
}

ref_M_INTS m_INTS_transpos(ref_M_INTS matriz1, ref_M_INTS matriz2)
{
    int x = 0;
    int y = 0;

    int tamanho1 = matriz1->rows;
    int tamanho2 = matriz1->columns;
    for (x = 0; x < tamanho1; x++)
    {
        for (y = 0; y < tamanho2; y++)
        {
            matriz2->data[x][y] = matriz1->data[y][x];
        }
    }

    return (matriz2);
}

void m_INTS_testezero(ref_M_INTS matriz)
{
    bool OK = true;
    int x = 0;
    int y = 0;
    int tamanho1 = matriz->rows;
    int tamanho2 = matriz->columns;
    for (x = 0; x < tamanho1; x++)
    {
        for (y = 0; y < tamanho2; y++)
        {
            OK = OK && matriz->data[x][y] == 0;
        }
    }
    if (OK)
    {
        printf("\nTodos os valores da matriz sao zeros.\n");
    }
    else
    {
        printf("\nNem todos os valores da matriz sao zeros.\n");
    }
}

void m_INTS_duplaigual(ref_M_INTS matriz, ref_M_INTS matriz2)
{
    bool OK = true;
    int x = 0;
    int y = 0;
    if (matriz->rows == matriz2->rows && matriz->columns == matriz2->columns)
    {
        int tamanho1 = matriz->rows;
        int tamanho2 = matriz->columns;
        for (x = 0; x < tamanho1; x++)
        {
            for (y = 0; y < tamanho2; y++)
            {
                OK = OK && matriz->data[x][y] == matriz2->data[x][y];
            }
        }
        if (OK)
        {
            printf("\nAs matrizes sao iguais\n");
        }
        else
        {
            printf("\nAs matriz tem o mesmo tamanho porem nao sao iguais.\n");
        }
    }
    else
    {
        printf("As duas matrizes nao tem o mesmo tamanho.");
    }
}

ref_M_INTS m_INTS_somamatrizes(ref_M_INTS matriz, ref_M_INTS matriz2, ref_M_INTS matriz3)
{
    bool OK = true;
    int x = 0;
    int y = 0;
    if (matriz->rows == matriz2->rows && matriz->columns == matriz2->columns)
    {
        int tamanho1 = matriz->rows;
        int tamanho2 = matriz->columns;
        for (x = 0; x < tamanho1; x++)
        {
            for (y = 0; y < tamanho2; y++)
            {
                matriz3->data[x][y] = matriz->data[x][y] + matriz2->data[x][y];
            }
        }
        printf("Soma das Matrizes: \n");
    }
    else
    {
        printf("As duas matrizes nao tem o mesmo tamanho.");
    }
    return (matriz3);
}

ref_M_INTS m_INTS_produtomatrizes(ref_M_INTS matriz, ref_M_INTS matriz2, ref_M_INTS matriz3)
{
    bool OK = true;
    int x = 0;
    int y = 0;
    int i = 0;
    int soma = 0;
    int tamanho1 = matriz->rows;
    int tamanho2 = matriz2->columns;
    if (tamanho1 == tamanho2)
    {
        for (i = 0; i < tamanho1; i++)
        {
            for (x = 0; x < tamanho1; x++)
            {
                for (y = 0; y < tamanho2; y++)
                {
                    matriz3->data[i][x] = matriz3->data[i][x] + (matriz->data[x][y] * matriz2->data[y][x]);
                }
            }
        }
        printf("Produto das matrizes: \n");
    }
    else
    {
        printf("ERRO: TAMANHO INVALIDO DAS MATRIZES.");
    }
    return (matriz3);
}

int main(int argc, char *argv[])
{
    int x = 0;
    ref_array_INT array;
    ref_M_INTS matriz;
    ref_M_INTS matriz2;
    ref_M_INTS matriz3;
    int rows = 0;
    int columns = 0;
    ref_array_INT arraysoma;
    do
    {
        printf("\n");
        printf("0 - Parar\n");
        printf("1 - Gerador de arranjo aleatorio por intervalo(EXEMPLO1011)\n");
        printf("2 - Mostrar arranjo.\n");
        printf("3 - Procurar certo valor inteiro em um arranjo(EXEMPLO1012)\n");
        printf("4 - Comparar arranjos (EXEMPLO1013)\n");
        printf("5 - Somar arranjos (EXEMPLO1014)\n");
        printf("6 - Dizer se arranjo esta em ordem crescente (EXEMPLO1015)\n");
        printf("7 - Criar matriz\n");
        printf("8 - Mostrar matriz\n");
        printf("9 - Gravar matriz em arquivo\n");
        printf("10 - Ler matriz de arquivo\n");
        printf("11 - Obter transposta de matriz (EXEMPLO1016)\n");
        printf("12 - Testar se valores da matriz sao todos iguais a zero (EXEMPLO1017)\n");
        printf("13 - Ver se duas matrizes sao iguais\n");
        printf("14 - Somar duas matrizes\n");
        printf("15 - Tirar o produto de duas matrizes (EXEMPLO1020)\n");
        x = IO_readint("Entre com sua opcao\n");
        switch (x)
        {
        case 1:
            array = array_new();
            array = array_rand(array);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 2:
            array_print(array);
            IO_pause("Apertar ENTER para terminar");
            break;

        case 3:
            array = array_procura(array);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 4:
            array_comp();
            IO_pause("Apertar ENTER para terminar");
            break;
        case 5:
            arraysoma = array_soma(arraysoma);
            array_print(arraysoma);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 6:
            array_teste_crescente(array);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 7:
            matriz = m_INTSnewprinc(&rows, &columns);
            matriz = m_INTS_inic(matriz);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 8:
            m_INTS_print(matriz);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 9:
            m_INTS_fprintf(matriz);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 10:
            matriz = m_INTS_fscanf("matriz.txt");
            IO_pause("Apertar ENTER para terminar");
            break;
        case 11:
            matriz = m_INTS_fscanf("matriz.txt");
            matriz2 = m_INTS_fscanf("matriz.txt");
            printf("Matriz inicial\n");
            m_INTS_print(matriz);
            matriz2 = m_INTS_transpos(matriz, matriz2);
            printf("Matriz Transposta\n");
            m_INTS_print(matriz2);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 12:
            matriz = m_INTS_fscanf("matriz.txt");
            m_INTS_testezero(matriz);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 13:
            matriz = m_INTS_fscanf("matriz.txt");
            matriz2 = m_INTS_fscanf("matriz2.txt");
            m_INTS_duplaigual(matriz, matriz2);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 14:
            matriz = m_INTS_fscanf("matriz.txt");
            printf("Matriz 1: \n");
            m_INTS_print(matriz);
            matriz2 = m_INTS_fscanf("matriz2.txt");
            printf("Matriz 2: \n");
            m_INTS_print(matriz2);
            matriz3 = m_INTS_fscanf("matriz.txt");
            matriz3 = m_INTS_somamatrizes(matriz, matriz2, matriz3);
            m_INTS_print(matriz3);
            IO_pause("Apertar ENTER para terminar");
            break;
        case 15:
            matriz = m_INTS_fscanf("matriz.txt");
            printf("Matriz 1: \n");
            m_INTS_print(matriz);
            matriz2 = m_INTS_fscanf("matriz2.txt");
            printf("Matriz 2: \n");
            m_INTS_print(matriz2);
            matriz3 = m_INTS_newsecun(matriz->rows, matriz2->columns);
            matriz3 = m_INTS_produtomatrizes(matriz, matriz2, matriz3);
            m_INTS_print(matriz3);
            IO_pause("Apertar ENTER para terminar");
            break;
        }
    } while (x != 0);
    IO_pause("Apertar ENTER para terminar");
    return (0);
}
