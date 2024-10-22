#include <iostream>
#include <fstream>
#include "io.hpp"
#include <iomanip>

using namespace std;

class mystring
{
private:
    string data;

public:
    mystring()
    {
        data = "";
    }
    mystring(string s)
    {
        data = s;
    }
    void setdata(string s)
    {
        data = s;
    }
    string getdata()
    {
        return data;
    }

    int getint()
    {
        bool number = true;
        int x = 0;
        while (x < data.length() && number)
        {
            if (data.at(x) < '0' || data.at(x) > '9')
            {
                number = false;
            }
            x++;
        }
        if (!number)
        {
            return -1;
        }
        else
        {
            int numero = 0;
            x = 0;
            while (x < data.length())
            {
                int digito = 0;
                switch (data.at(x))
                {
                case '1':
                    digito = 1;
                    break;
                case '2':
                    digito = 2;
                    break;
                case '3':
                    digito = 3;
                    break;
                case '4':
                    digito = 4;
                    break;
                case '5':
                    digito = 5;
                    break;
                case '6':
                    digito = 6;
                    break;
                case '7':
                    digito = 7;
                    break;
                case '8':
                    digito = 8;
                    break;
                case '9':
                    digito = 9;
                    break;
                }
                numero += digito * pow(10, data.length() - 1 - x);
                x++;
            }
            return numero;
        }
    }

    double getdouble()
    {
        bool number = true;
        int ponto = 0;
        int x = 0;
        int posiponto = data.length();
        while (x < data.length())
        {
            if (data.at(x) == '.')
            {
                ponto++;
                posiponto = x;
            }
            if (ponto > 1 || ((data.at(x) < '0' || data.at(x) > '9') && data.at(x) != '.'))
            {
                number = false;
            }
            x++;
        }
        if (!number)
        {
            return 0.0;
        }
        else
        {
            double numero = 0;
            x = 0;
            int digito = 0;
            while (x < data.length())
            {
                if (x != posiponto)
                {
                    switch (data.at(x))
                    {
                    case '1':
                        digito = 1;
                        break;
                    case '2':
                        digito = 2;
                        break;
                    case '3':
                        digito = 3;
                        break;
                    case '4':
                        digito = 4;
                        break;
                    case '5':
                        digito = 5;
                        break;
                    case '6':
                        digito = 6;
                        break;
                    case '7':
                        digito = 7;
                        break;
                    case '8':
                        digito = 8;
                        break;
                    case '9':
                        digito = 9;
                        break;
                    }
                    numero += (x < posiponto) ? digito * pow(10, posiponto - 1 - x) : digito * pow(10, posiponto - x);
                }
                x++;
            }
            return numero;
        }
    }

    bool getbool()
    {
        if (data == "true" || data == "T" || data == "1")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool counts(string texto)
    {
        bool resposta = false;
        int x = 0;
        int contar = 0;
        while (x < data.length() && !resposta)
        {
            if (data.at(x) == texto.at(contar))
            {
                contar++;
                if (contar == texto.length())
                {
                    resposta = true;
                }
            }
            else
            {
                contar = (data.at(x) == texto.at(0)) ? 1 : 0;
            }
            x++;
        }
        return resposta;
    }

    string toupcase()
    {
        string up = "";
        int x = 0;
        while (x < data.length())
        {
            if (data[x] >= 'a' && data[x] <= 'z')
            {
                up += data[x] - 32;
            }
            else
            {
                up += data[x];
            }
            x++;
        }
        return up;
    }

    string tolowcase()
    {
        string low = "";
        int x = 0;
        while (x < data.length())
        {
            if (data[x] >= 'A' && data[x] <= 'Z')
            {
                low += data[x] + 32;
            }
            else
            {
                low += data[x];
            }
            x++;
        }
        return low;
    }

    string replace(char original, char novo)
    {
        string sub = "";
        int x = 0;
        while (x < data.length())
        {
            if (data[x] == original)
            {
                sub += novo;
            }
            else
            {
                sub += data[x];
            }
            x++;
        }
        return sub;
    }

    int split(string sequencia[])
    {
        string palavra = "";
        int x = 0;
        int y = 0;
        while (x < data.length())
        {
            if (data[x] == ' ')
            {
                sequencia[y] = palavra;
                palavra = "";
                y++;
            }
            else
            {
                palavra += data[x];
            }
            x++;
        }
        sequencia[y] = palavra;
        y++;
        return y;
    }

    string encrypt()
    {
        int x = 0;
        string crypt = "";
        while (x < data.length())
        {
            if ((data[x] >= 'a' && data[x] <= 'z') || (data[x] >= 'A' && data[x] <= 'Z'))
            {
                switch (data[x])
                {
                case 'X':
                    crypt += 'A';
                    break;
                case 'Y':
                    crypt += 'B';
                    break;
                case 'Z':
                    crypt += 'C';
                    break;
                case 'x':
                    crypt += 'a';
                    break;
                case 'y':
                    crypt += 'b';
                    break;
                case 'z':
                    crypt += 'c';
                    break;

                default:
                    crypt += data[x] + 3;
                    break;
                }
            }
            else
            {
                crypt += data[x];
            }
            x++;
        }
        return crypt;
    }

    string decrypt()
    {
        int x = 0;
        string decrypt = "";
        while (x < data.length())
        {
            if ((data[x] >= 'a' && data[x] <= 'z') || (data[x] >= 'A' && data[x] <= 'Z'))
            {
                switch (data[x])
                {
                case 'A':
                    decrypt += 'x';
                    break;
                case 'B':
                    decrypt += 'Y';
                    break;
                case 'C':
                    decrypt += 'Z';
                    break;
                case 'a':
                    decrypt += 'x';
                    break;
                case 'b':
                    decrypt += 'y';
                    break;
                case 'z':
                    decrypt += 'z';
                    break;

                default:
                    decrypt += data[x] - 3;
                    break;
                }
            }
            else
            {
                decrypt += data[x];
            }
            x++;
        }
        return decrypt;
    }
};

void method11()
{
    string x;
    cout << "\nDigite um numero inteiro: ";
    cin >> x;
    mystring s(x);
    int n = s.getint();
    if (n != -1)
    {
        cout << "\nO valor digitado e: " << n;
    }
    else
    {
        cout << "\nO valor digitado e invalido";
    }
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method12()
{
    string x;
    cout << "\nDigite um numero real: ";
    cin >> x;
    mystring s(x);
    double n = s.getdouble();
    if (n != 0.0)
    {
        cout << "\nO valor digitado e: " << n;
    }
    else
    {
        cout << "\nO valor digitado e invalido";
    }
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method13()
{
    string x;
    cout << "\nDigite um valor logico: ";
    cin >> x;
    mystring s(x);
    bool n = s.getbool();
    if (n)
    {
        cout << "\nO valor logico digitado e verdadeiro";
    }
    else
    {
        cout << "\nO valor digitado e invalido ou falso";
    }
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method14()
{
    string x = "";
    string aux;
    cout << "\nDigite uma sequencia de caracteres(termine com um . separado da ultima palavra): ";
    do
    {
        cin >> aux;
        if (aux != ".")
        {
            x += aux + " ";
        }
    } while (aux != ".");
    mystring s(x);
    cout << "\nDigite outra sequencia de caracteres: ";
    cin >> x;
    bool n = s.counts(x);
    if (n)
    {
        cout << "\nA segunda sequencia esta dentro da primeira";
    }
    else
    {
        cout << "\nA segunda sequencia nao esta dentro da primeira";
    }
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method15()
{
    string x;
    cout << "\nDigite uma sequencia de caracteres minusculas: ";
    cin >> x;
    mystring s(x);
    string n = s.toupcase();
    cout << endl
         << n;
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method16()
{
    string x;
    cout << "\nDigite uma sequencia de caracteres maiusculas: ";
    cin >> x;
    mystring s(x);
    string n = s.tolowcase();
    cout << endl
         << n;
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method17()
{
    char y;
    char z;
    string x;
    cout << "\nDigite uma sequencia de caracteres: ";
    cin >> x;
    mystring s(x);
    cout << "\nQuais caracteres voce deseja trocar: ";
    cin >> y;
    cin >> z;
    string n = s.replace(y, z);
    cout << endl
         << n;
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method18()
{
    string vetor[100];
    string x = "";
    string aux;
    int i = 0;
    cout << "\nDigite uma sequencia de caracteres(termine com um . separado da ultima palavra): ";
    do
    {
        cin >> aux;
        if (aux != ".")
        {
            x += aux + " ";
        }
    } while (aux != ".");
    mystring s(x);
    int n = s.split(vetor);
    while(n > i)
    {
      cout << vetor[i] << " ";
      i++;
    }
    cout << "\nA sequencia digitada tem " << n - 1 << " palavras";
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method19()
{
    string vetor[100];
    string x;
    cout << "\nDigite uma sequencia de caracteres: ";
    cin >> x;
    mystring s(x);
    string n = s.encrypt();
    cout << "\nA sequencia de caracteres se transformou em:" << n;
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method20()
{
    string vetor[100];
    string x;
    cout << "\nDigite uma sequencia de caracteres: ";
    cin >> x;
    mystring s(x);
    string n = s.decrypt();
    cout << "\nA sequencia de caracteres se transformou em:" << n;
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

/**
 * Funcao principal
 * @return codigo de encerramento
 */
int main()
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        IO_println("\nED14 - Programa");

        // ler do teclado
        IO_println("\nOpcoes:");
        IO_println("\nDigite 0 - parar");
        IO_println("Digite 1 - Exemplo1411");
        IO_println("Digite 2 - Exemplo1412");
        IO_println("Digite 3 - Exemplo1413");
        IO_println("Digite 4 - Exemplo1414");
        IO_println("Digite 5 - Exemplo1415");
        IO_println("Digite 6 - Exemplo1416");
        IO_println("Digite 7 - Exemplo1417");
        IO_println("Digite 8 - Exemplo1418");
        IO_println("Digite 9 - Exemplo1419");
        IO_println("Digite 10 - Exemplo1420\n");

        x = IO_readint("Escolha a opcao que deseja: ");

        // testar valor
        switch (x)
        {
        case 0:
            //   method00();
            break;
        case 1:
            method11();
            break;
        case 2:
            method12();
            break;
        case 3:
            method13();
            break;
        case 4:
            method14();
            break;
        case 5:
            method15();
            break;
        case 6:
            method16();
            break;
        case 7:
            method17();
            break;
        case 8:
            method18();
            break;
        case 9:
            method19();
            break;
        case 10:
            method20();
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        } // end switch
    } while (x != 0);

    // encerrar
    IO_pause("Aperte ENTER para terminar");
    return (0);
}
