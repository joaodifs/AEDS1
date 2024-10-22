#include <iostream>
#include <fstream>
#include "io.hpp"
#include <iomanip>

using namespace std;
template <typename T>

class Matrix
{
private:
    T optional;
    int rows;
    int columns;
    T **data;

public:
    Matrix()
    {

        this->rows = 0;
        this->columns = 0;

        data = nullptr;
    }
    Matrix(int rows, int columns, T initial)
    {

        bool OK = true;

        this->optional = initial;
        this->rows = rows;
        this->columns = columns;

        data = new T *[rows];
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
                OK = OK && (data[x] != nullptr);
            }
            if (!OK)
            {
                data = nullptr;
            }
        }
    }
    ~Matrix()
    {
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                delete (data[x]);
            }
            delete (data);
            data = nullptr;
        }
    }
    void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        }
    }
    T get(int row, int column)
    {
        T value = optional;
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data[row][column];
        }
        return (value);
    }

    void print()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << data[x][y] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void read()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << setw(2) << x << ", "
                     << setw(2) << y << " : ";
                cin >> data[x][y];
            }
        }
        cout << endl;
    }

    void fprint(string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << rows << endl;
        afile << columns << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                afile << data[x][y] << endl;
            }
        }
        afile.close();
    }

    void fread(string fileName)
    {
        ifstream afile;
        int m = 0;
        int n = 0;
        afile.open(fileName);
        afile >> m;
        afile >> n;
        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n"
                 << endl;
        }
        else
        {

            rows = m;
            columns = n;

            data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
            }

            for (int x = 0; x < rows; x = x + 1)
            {
                for (int y = 0; y < columns; y = y + 1)
                {
                    afile >> data[x][y];
                }
            }
        }
        afile.close();
    }

    Matrix &operator=(const Matrix<T> other)
    {
        if (other.rows == 0 || other.columns == 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            this->rows = other.rows;
            this->columns = other.columns;
            this->data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                this->data[x] = new T[columns];
            }
            for (int x = 0; x < this->rows; x = x + 1)
            {
                for (int y = 0; y < this->columns; y = y + 1)
                {
                    data[x][y] = other.data[x][y];
                }
            }
        }
        return (*this);
    }

    bool isZeros()
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (rows > 0 && columns > 0)
        {
            result = true;
            while (x < rows && result)
            {
                y = 0;
                while (y < columns && result)
                {
                    result = result && (data[x][y] == 0);
                    y = y + 1;
                }
                x = x + 1;
            }
        }
        return (result);
    }

    bool operator!=(const Matrix<T> other)
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            x = 0;
            while (x < rows && !result)
            {
                y = 0;
                while (y < columns && !result)
                {
                    result = (data[x][y] != other.data[x][y]);
                    y = y + 1;
                }
                x = x + 1;
            }
        }
        return (result);
    }

    Matrix &operator-(const Matrix<T> other)
    {
        static Matrix<T> result(1, 1, 0);
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            result.data = new T *[result.rows];
            for (int x = 0; x < result.rows; x = x + 1)
            {
                result.data[x] = new T[result.columns];
            }
            for (int x = 0; x < result.rows; x = x + 1)
            {
                for (int y = 0; y < result.columns; y = y + 1)
                {
                    result.data[x][y] = data[x][y] - other.data[x][y];
                }
            }
        }
        return (result);
    }

    Matrix &operator*(const Matrix<T> other)
    {
        static Matrix<T> result(1, 1, 0);
        int x = 0;
        int y = 0;
        int z = 0;
        int sum = 0;
        if (rows <= 0 || columns == 0 ||
            other.rows <= 0 || other.columns == 0 ||
            columns != other.rows)
        {
            cout << endl
                 << "ERROR: Invalid data." << endl;
            result.data[0][0] = 0;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            result.data = new T *[result.rows];
            for (int x = 0; x < result.rows; x = x + 1)
            {
                result.data[x] = new T[result.columns];
            }
            for (x = 0; x < result.rows; x = x + 1)
            {
                for (y = 0; y < result.columns; y = y + 1)
                {
                    sum = 0;
                    for (z = 0; z < columns; z = z + 1)
                    {
                        sum = sum + data[x][z] * other.data[z][y];
                    }
                    result.data[x][y] = sum;
                }
            }
        }
        return (result);
    }

    const int getRows()
    {
        return (rows);
    }
    const int getColumns()
    {
        return (columns);
    }

    Matrix<T> escalar(int constante)
    {
        Matrix<T> resultado(rows, columns, 0);
        int x = 0;
        int y = 0;
        while (x < rows)
        {
            y = 0;
            while (y < columns)
            {
                resultado.data[x][y] = data[x][y] * constante;
                y++;
            }

            x++;
        }
        return resultado;
    }

    bool identidade()
    {
        bool resultado = true;
        int x = 0;
        int y = 0;
        while (resultado && x < rows)
        {
            y = 0;
            while (resultado && y < columns)
            {
                if ((x == y && data[x][y] != 1) || (x != y && data[x][y] != 0))
                {
                    resultado = false;
                }
            }
        }
        return resultado;
    }

    bool operator==(const Matrix<T> matriz2)
    {
        bool resultado = true;
        if (rows != matriz2.rows || columns != matriz2.columns)
        {
            resultado = false;
        }
        for (int x = 0; resultado && x < rows; x++)
        {
            for (int y = 0; resultado && y < columns; y++)
            {
                resultado = data[x][y] == matriz2.data[x][y];
            }
        }
        return resultado;
    }

    Matrix<T> operator+(const Matrix<T> matriz2)
    {
        Matrix<T> resultado(rows, columns, 0);
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < columns; y++)
            {
                resultado.data[x][y] = data[x][y] + matriz2.data[x][y];
            }
        }
        return resultado;
    }

    void somarlinhas(int linha1, int linha2, int constante)
    {
        int x = 0;
        while (x < columns)
        {
            data[linha1][x] += data[linha2][x] * constante;
            x++;
        }
    }

    void somarcolunas(int coluna1, int coluna2, int constante)
    {
        int x = 0;
        while (x < rows)
        {
            data[x][coluna1] += data[x][coluna2] * constante;
            x++;
        }
    }

    int procurarlinhas(int procurar)
    {
        int x = 0;
        int y;
        while (x < rows)
        {
            y = 0;
            while (y < columns)
            {
                if (data[x][y] == procurar)
                {
                    return x;
                }
                y++;
            }
            x++;
        }
        return -1;
    }

    int achaColuna(int procurar)
    {
        int x = 0;
        int y;
        while (x < rows)
        {
            y = 0;
            while (y < columns)
            {
                if (data[x][y] == procurar)
                {
                    return y;
                }
                y++;
            }
            x++;
        }
        return -1;
    }

    void transpor()
    {
        int x = 0;
        int y = 0;
        cout << endl;
        while (x < columns)
        {
            y = 0;
            while (y < rows)
            {
                cout << data[y][x] << " ";
                y++;
            }
            cout << endl;
            x++;
        }
    }
};

void funcao11(int linhas, int colunas)
{
    int menor = 0;
    cout << "\nDigite o menor valor: ";
    cin >> menor;
    int maior = 0;
    cout << "\nDigite o maior valor: ";
    cin >> maior;
    Matrix<int> *matriz = new Matrix<int>(linhas, colunas, 0);

    srand(time(NULL));
    int x = 0;
    int y = 0;
    while (x < linhas)
    {
        y = 0;
        while (y < colunas)
        {
            matriz->set(x, y, menor + rand() % (maior - menor));
            y++;
        }
        x++;
    }
    matriz->fprint("Exemplo1211.txt");
}

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )

void method11()
{
    int x, y;
    cout << "\nDigite o numero de linhas: ";
    cin >> x;
    cout << "\nDigite o numero de colunas: ";
    cin >> y;
    funcao11(x, y);
    getchar();
    pause("\nAperte Enter para terminar");
}

void method12()
{
    Matrix<int> *matriz = new Matrix<int>();
    matriz->fread("ED12.txt");
    int a = 0;
    cout << "\nDigite a constante a ser utilizada: ";
    cin >> a;
    Matrix<int> resultado = matriz->escalar(a);
    resultado.print();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method13()
{
    Matrix<int> *matriz = new Matrix<int>();
    matriz->fread("ED12.txt");
    bool resultado = matriz->identidade();
    if (resultado)
    {
        cout << "\nA matriz eh identidade";
    }
    else
    {
        cout << "\nA matriz nao eh identidade";
    }
    getchar();
    pause("\nAperte Enter para terminar");
}

void method14()
{
    Matrix<int> *matriz = new Matrix<int>();
    Matrix<int> *matriz2 = new Matrix<int>();
    matriz->fread("ED12.txt");
    matriz2->fread("ED12.txt");
    bool resultado = *matriz == *matriz2;
    if (resultado)
    {
        cout << "\nAs 2 matrizes sao iguais";
    }
    else
    {
        cout << "\nAs 2 matrizes sao diferentes";
    }
    getchar();
    pause("\nAperte Enter para terminar");
}

void method15()
{
    Matrix<int> *matriz = new Matrix<int>();
    Matrix<int> *matriz2 = new Matrix<int>();
    matriz->fread("ED12.txt");
    matriz2->fread("ED12.txt");
    Matrix<int> resultado = *matriz + *matriz2;
    resultado.print();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method16()
{
    Matrix<int> *matriz = new Matrix<int>();
    matriz->fread("ED12.txt");
    int a = 0;
    int b = 0;
    int c = 0;
    cout << "\nDigite a constante a ser utilizada: ";
    cin >> a;
    cout << "\nDigite as linhas que irao ser somadas: ";
    cin >> b;
    cin >> c;
    matriz->somarlinhas(b, c, a);
    matriz->print();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method17()
{
    Matrix<int> *matriz = new Matrix<int>();
    matriz->fread("ED12.txt");
    int a = 0;
    int b = 0;
    int c = 0;
    cout << "\nDigite a constante a ser utilizada: ";
    cin >> a;
    cout << "\nDigite as colunas que irao ser somadas: ";
    cin >> b;
    cin >> c;
    matriz->somarcolunas(b, c, a);
    matriz->print();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method18()
{
    Matrix<int> *matriz = new Matrix<int>();
    matriz->fread("ED12.txt");
    int x;
    cout << "\nDigite um numero para ser procurado: ";
    cin >> x;
    int resultado = matriz->procurarlinhas(x);
    if (resultado != -1)
    {
        cout << "\nO valor foi encontrado na linha: " << resultado;
    }
    else
    {
        cout << "\nO valor nao foi encontrado em nenhuma linha";
    }
    getchar();
    pause("\nAperte Enter para terminar");
}

void method19()
{
    Matrix<int> *matriz = new Matrix<int>();
    matriz->fread("ED12.txt");
    int x;
    cout << "\nDigite um numero para ser procurado: ";
    cin >> x;
    int resultado = matriz->achaColuna(x);
    if (resultado != -1)
    {
        cout << "\nO valor foi encontrado na coluna: " << resultado;
    }
    else
    {
        cout << "\nO valor nao foi encontrado em nenhuma coluna";
    }
    getchar();
    pause("\nAperte Enter para terminar");
}

void method20()
{
    Matrix<int> *matriz = new Matrix<int>();
    matriz->fread("ED12.txt");
    matriz->transpor();
    getchar();
    pause("\nAperte Enter para terminar");
}

int main()
{

    int option = 0;
    do
    {
        IO_println("");
        option = IO_readint("\nDigite um numero de 11 a 20: ");
        switch (option)
        {
        case 0:

            break;
        case 11:
            method11();
            break;
        case 12:
            method12();
            break;
        case 13:
            method13();
            break;
        case 14:
            method14();
            break;
        case 15:
            method15();
            break;
        case 16:
            method16();
            break;
        case 17:
            method17();
            break;
        case 18:
            method18();
            break;
        case 19:
            method19();
            break;
        case 20:
            method20();
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        }
    } while (option != 0);

    pause("Aperte ENTER para terminar");
    return (0);
}
