#include <iostream>
#include <fstream>
#include "io.hpp"
#include <iomanip>

using namespace std;
template <typename T>

class Array
{
private:
    T optional;
    int length;
    T *data;

public:
    Array(int n, T initial)
    {
        optional = initial;
        length = 0;
        data = nullptr;
        if (n > 0)
        {
            length = n;
            data = new T[length];
        }
    }
    void free()
    {
        if (data != nullptr)
        {
            delete (data);
            data = nullptr;
        }
    }
    void set(int position, T value)
    {
        if (0 <= position && position < length)
        {
            data[position] = value;
        }
    }
    T get(int position)
    {
        T value = optional;
        if (0 <= position && position < length)
        {
            value = data[position];
        }
        return (value);
    }
    void print()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : "
                 << setw(9) << data[x]
                 << endl;
        }
        cout << endl;
    }

    void read()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : ";
            cin >> data[x];
        }
        cout << endl;
    }

    void fprint(string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << length << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            afile << data[x] << endl;
        }
        afile.close();
    }

    void fread(string fileName)
    {
        ifstream afile;
        int n = 0;
        afile.open(fileName);
        afile >> n;
        if (n <= 0)
        {
            cout << "\nERROR: Invalid length.\n"
                 << endl;
        }
        else
        {

            length = n;

            data = new T[n];

            for (int x = 0; x < length; x = x + 1)
            {
                afile >> data[x];
            }
        }
        afile.close();
    }

    Array()
    {

        length = 0;

        data = nullptr;
    }

    Array(int length, int other[])
    {
        if (length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {

            this->length = length;

            data = new T[this->length];

            for (int x = 0; x < this->length; x = x + 1)
            {
                data[x] = other[x];
            }
        }
    }

    Array(const Array &other)
    {
        if (other.length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {

            length = other.length;

            data = new T[other.length];

            for (int x = 0; x < length; x = x + 1)
            {
                data[x] = other.data[x];
            }
        }
    }

    Array &operator=(const Array<T> other)
    {
        if (other.length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            this->length = other.length;
            this->data = new T[other.length];
            for (int x = 0; x < this->length; x = x + 1)
            {
                data[x] = other.data[x];
            }
        }
        return (*this);
    }

    bool operator==(const Array<T> other)
    {
        bool result = false;
        int x = 0;
        if (other.length == 0 || length != other.length)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            x = 0;
            result = true;
            while (x < this->length && result)
            {
                result = result && (data[x] == other.data[x]);
                x = x + 1;
            }
        }
        return (result);
    }

    Array &operator+(const Array<T> other)
    {
        static Array<T> result(other);
        if (other.length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            for (int x = 0; x < this->length; x = x + 1)
            {
                result.data[x] = result.data[x] + this->data[x];
            }
        }
        return (result);
    }

    const int getLength()
    {
        return (length);
    }
    T &operator[](const int position)
    {
        static T value = optional;
        if (position < 0 || length <= position)
        {
            cout << endl
                 << "\nERROR: Invalid position.\n"
                 << endl;
        }
        else
        {
            value = data[position];
        }
        return (value);
    }

    T achamaior()
    {
        T maior = data[0];
        int x = 1;
        while (x < length)
        {
            if (data[x] > maior)
            {
                maior = data[x];
            }
            x++;
        }
        return maior;
    }

    T achamenor()
    {
        T menor = data[0];
        int x = 1;
        while (x < length)
        {
            if (data[x] < menor)
            {
                menor = data[x];
            }
            x++;
        }
        return menor;
    }

    T somar()
    {
        T soma = 0;
        int x = 0;
        while (x < length)
        {
            soma += data[x];
            x++;
        }
        return soma;
    }

    T media()
    {
        if (length != 0)
        {
            return somar() / length;
        }
        else
        {
            return 0;
        }
    }

    bool igualZero()
    {
        bool zero = true;
        int x = 0;
        while (zero && x < length)
        {
            if (data[x] != 0)
            {
                zero = false;
            }
            x++;
        }
        return zero;
    }

    bool emOrdem()
    {
        bool emOrdem = true;
        int x = 1;
        while (emOrdem && x < length)
        {
            if (data[x] > data[x - 1])
            {
                emOrdem = false;
            }
            x++;
        }
        return emOrdem;
    }

    bool achavalor(T x, int posicao, int fim)
    {
        bool achar = false;
        while (achar == false && posicao <= fim)
        {
            if (data[posicao] == x)
            {
                achar = true;
            }
            posicao++;
        }
        return achar;
    }

    Array<T> escalar(int constante)
    {
        Array<T> resultado(length, 0);
        int x = 0;
        while (x < length)
        {
            resultado.data[x] = data[x] * constante;
            x++;
        }
        return resultado;
    }

    void swap(int x, int y)
    {
        int z = data[x];
        data[x] = data[y];
        data[y] = z;
    }

    void ordem()
    {
        int x = 0;
        int y = 0;
        int z = 0;
        while (x < length - 1)
        {
            z = x;
            y = x + 1;
            while (y < length)
            {
                if (data[y] > data[z])
                {
                    z = y;
                }
                y++;
            }
            if (z != x)
            {
                swap(x, z);
            }
            x++;
        }
    }
};

void funcao11(int tamanho)
{
    int menor = 0;
    cout << "\nDigite o menor valor: ";
    cin >> menor;
    int maior = 0;
    cout << "\nDigite o maior valor: ";
    cin >> maior;
    Array<int> *array = new Array<int>(tamanho, 0);

    srand(time(NULL));
    int y = 0;

    while (y < tamanho)
    {
        array->set(y, menor + rand() % (maior - menor));

        y = y + 1;
    }
    array->fprint("Exemplo1111.txt");

    array->free();
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
    int x;
    cout << "\nDigite o tamanho do vetor: ";
    cin >> x;
    funcao11(x);
    getchar();
    pause("\nAperte Enter para terminar");
}

void method12()
{
    int x;
    int z = 0;
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    z = array->achamaior();
    cout << "\nO maior valor do arranjo eh: " << z;
    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method13()
{
    int x;
    int z = 0;
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    z = array->achamenor();
    cout << "\nO menor valor do arranjo eh: " << z;
    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method14()
{
    int x;
    int z = 0;
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    z = array->somar();
    cout << "\nA soma dos valores do arranjo eh: " << z;
    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method15()
{
    int x;
    int z = 0;
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    z = array->media();
    cout << "\nA media dos valores do arranjo eh: " << z;
    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method16()
{
    int x;
    bool z = 0;
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    z = array->igualZero();
    if (z)
    {
        cout << "\nTodos valores do arranjo sao iguais a 0";
    }
    else
    {
        cout << "\nNem todos valores do arranjo sao iguais a 0";
    }
    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method17()
{
    int x;
    bool z = 0;
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    z = array->emOrdem();
    if (z)
    {
        cout << "\nTodos valores estao emOrdems em ordem decrescente";
    }
    else
    {
        cout << "\nNem todos valores estao emOrdems em ordem decrescente";
    }
    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method18()
{
    int x;
    int z = 0;
    bool achar;
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    int a = 0;
    cout << "\nQual valor voce deseja procurar: ";
    cin >> a;
    cout << "\nDigite a posicao que voce deseja comecar a busca: ";
    cin >> z;
    cout << "\nDigite a posicao que voce deseja encerrar a busca: ";
    cin >> x;
    achar = array->achavalor(a, z, x);
    if (achar)
    {
        cout << "\nO valor foi encontrado";
    }
    else
    {
        cout << "\nO valor nao foi encontrado";
    }

    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method19()
{
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    int a = 0;
    cout << "\nDigite a constante a ser utilizada: ";
    cin >> a;
    Array<int> resultado = array->escalar(a);
    resultado.print();
    array->free();
    resultado.free();
    getchar();
    pause("\nAperte Enter para terminar");
}

void method20()
{
    Array<int> *array = new Array<int>();
    array->fread("ED11.txt");
    array->ordem();
    array->print();
    array->free();
    getchar();
    pause("\nAperte Enter para terminar");
}

/**
 * Funcao principal
 * @return codigo de encerramento
 */
int main()
{

    int option = 0;
    IO_println("--------------------------------------------");
    IO_id("\nEXEMPLO1120 - v0.0");
    IO_println("--------------------------------------------");
    do
    {

        IO_println("");
        option = IO_readint("\nEscolha uma opcao de 11 a 20: ");
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
