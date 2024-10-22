#include <iostream>
#include <limits>
#include <string>
#include "io.hpp"

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
}

#include "myarray.hpp"
using namespace std;

void method01()
{

    Array<int> int_array(5, 0);
    int_array.set(0, 1);
    int_array.set(1, 2);
    int_array.set(2, 3);
    int_array.set(3, 4);
    int_array.set(4, 5);

    cout << "\nEXEMPLO1101 - Method01 - v0.0\n"
         << endl;

    int_array.print();

    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method02()
{

    Array<int> int_array(5, 0);

    cout << endl
         << "EXEMPLO1110 - Method02 - v0.0" << endl;

    int_array.read();

    int_array.print();

    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method03()
{

    Array<int> int_array(5, 0);

    cout << endl
         << "EXEMPLO1110 - Method03 - v0.0" << endl;

    int_array.read();

    int_array.fprint("INT_ARRAY1.TXT");

    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method04()
{

    Array<int> int_array(5, 0);

    cout << endl
         << "EXEMPLO1110 - Method04 - v0.0" << endl;

    int_array.fread("INT_ARRAY1.TXT");

    int_array.print();

    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method05()
{

    int other[] = {1, 2, 3, 4, 5};
    Array<int> int_array(5, other);

    cout << endl
         << "EXEMPLO1110 - Method05 - v0.0" << endl;

    cout << "\nCopia\n"
         << endl;
    int_array.print();

    int_array.free();

    pause("Apertar ENTER para continuar");
}

void method06()
{

    Array<int> int_array1(1, 0);

    cout << endl
         << "EXEMPLO1110 - Method06 - v0.0" << endl;

    int_array1.fread("INT_ARRAY1.TXT");

    cout << "\nOriginal\n"
         << endl;
    int_array1.print();

    Array<int> int_array2(int_array1);

    cout << "\nCopia\n"
         << endl;
    int_array2.print();

    int_array1.free();
    int_array2.free();

    pause("Apertar ENTER para continuar");
}

void method07()
{

    Array<int> int_array1(1, 0);
    Array<int> int_array2(1, 0);

    cout << endl
         << "EXEMPLO1110 - Method07 - v0.0" << endl;

    int_array1.fread("INT_ARRAY1.TXT");

    cout << "\nOriginal\n"
         << endl;
    int_array1.print();

    int_array2 = int_array1;

    cout << "\nCopia\n"
         << endl;
    int_array2.print();

    int_array1.free();
    int_array2.free();

    pause("Apertar ENTER para continuar");
}

void method08()
{

    int other[] = {1, 2, 3};
    Array<int> int_array1(3, other);
    Array<int> int_array2(3, other);
    int x;

    cout << endl
         << "EXEMPLO1110 - Method08 - v0.0" << endl;

    cout << endl;
    cout << "Array_1";
    int_array1.print();

    cout << "Array_2";
    int_array2.print();

    cout << "Igualdade = " << (int_array1 == int_array2) << endl;

    int_array2.set(0, (-1));

    cout << endl;
    cout << "Array_1" << endl;
    int_array1.print();

    cout << "Array_2" << endl;
    int_array2.print();

    cout << "Igualdade = " << (int_array1 == int_array2) << endl;

    int_array1.free();
    int_array2.free();

    pause("Apertar ENTER para continuar");
}

void method09()
{

    Array<int> int_array1(1, 0);
    Array<int> int_array2(1, 0);
    Array<int> int_array3(1, 0);

    cout << endl
         << "EXEMPLO1110 - Method09 - v0.0" << endl;

    int_array1.fread("INT_ARRAY1.TXT");

    int_array2 = int_array1;

    int_array3 = int_array2 + int_array1;

    cout << endl;
    cout << "Original" << endl;
    int_array1.print();

    cout << "Copia" << endl;
    int_array2.print();

    cout << "Soma" << endl;
    int_array3.print();

    int_array1.free();
    int_array2.free();
    int_array3.free();

    pause("Apertar ENTER para continuar");
}

void method10()
{

    int other[] = {1, 2, 3, 4, 5};
    Array<int> int_array(5, other);
    int x;

    cout << endl
         << "EXEMPLO1110 - Method10 - v0.0" << endl;

    cout << "\nAcesso externo" << endl;
    for (x = 0; x < int_array.getLength(); x = x + 1)
    {
        cout << endl
             << setw(3) << x << " : " << int_array[x];
    }
    cout << endl
         << "\nFora dos limites:";
    cout << endl
         << "[-1]: " << int_array.get(-1) << endl;
    cout << endl
         << "[" << int_array.getLength() << "]: "
         << int_array[int_array.getLength()] << endl;

    int_array.free();

    pause("Apertar ENTER para continuar");
}

int main(int argc, char **argv)
{

    int x = 0;

    do
    {

        cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;

        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - " << endl;
        cout << " 2 - " << endl;
        cout << " 3 - " << endl;
        cout << " 4 - " << endl;
        cout << " 5 - " << endl;
        cout << " 6 - " << endl;
        cout << " 7 - " << endl;
        cout << " 8 - " << endl;
        cout << " 9 - " << endl;
        cout << "10 - " << endl;

        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;

        switch (x)
        {
        case 0:
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
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        }
    } while (x != 0);

    pause("Apertar ENTER para terminar");
    return (0);
}
