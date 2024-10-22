#include "io.hpp"
#include "mymatrix.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>

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

void method01()
{

    Matrix<int> int_matrix(2, 2, 0);
    int_matrix.set(0, 0, 1);
    int_matrix.set(0, 1, 2);
    int_matrix.set(1, 0, 3);
    int_matrix.set(1, 1, 4);

    cout << "\nEXEMPLO1210 - Method01 - v0.0\n"
         << endl;

    int_matrix.print();

    pause("Apertar ENTER para continuar");
}

void method02()
{

    Matrix<int> matrix(2, 2, 0);

    cout << endl
         << "EXEMPLO1210 - Method02 - v0.0" << endl;

    matrix.read();

    matrix.print();

    pause("Apertar ENTER para continuar");
}

void method03()
{

    Matrix<int> matrix(2, 2, 0);

    cout << endl
         << "EXEMPLO1210 - Method03 - v0.0" << endl;

    matrix.read();

    matrix.print();

    matrix.fprint("MATRIX1.TXT");

    pause("Apertar ENTER para continuar");
}

void method04()
{

    Matrix<int> matrix(1, 1, 0);

    cout << endl
         << "EXEMPLO1210 - Method04 - v0.0" << endl;

    matrix.fread("MATRIX1.TXT");

    matrix.print();

    pause("Apertar ENTER para continuar");
}

void method05()
{

    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);

    cout << endl
         << "EXEMPLO1210 - Method05 - v0.0" << endl;

    int_matrix1.fread("MATRIX1.TXT");

    cout << "\nOriginal\n"
         << endl;
    int_matrix1.print();

    int_matrix2 = int_matrix1;

    cout << "\nCopia\n"
         << endl;
    int_matrix2.print();

    pause("Apertar ENTER para continuar");
}

void method06()
{

    Matrix<int> int_matrix(2, 2, 0);
    int_matrix.set(0, 0, 0);
    int_matrix.set(0, 1, 0);
    int_matrix.set(1, 0, 0);
    int_matrix.set(1, 1, 0);

    cout << endl
         << "EXEMPLO1210 - Method06 - v0.0" << endl;

    int_matrix.print();

    cout << "Zeros = " << int_matrix.isZeros() << endl;

    int_matrix.fread("MATRIX1.TXT");

    int_matrix.print();

    cout << "Zeros = " << int_matrix.isZeros() << endl;

    pause("Apertar ENTER para continuar");
}

void method07()
{

    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);

    cout << endl
         << "EXEMPLO1210 - Method07 - v0.0" << endl;

    int_matrix1.fread("MATRIX1.TXT");

    cout << "\nMatrix_1\n";
    int_matrix1.print();

    int_matrix2 = int_matrix1;

    cout << "\nMatrix_2\n";
    int_matrix2.print();

    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;

    int_matrix2.set(0, 0, (-1));

    cout << "\nMatrix_1\n";
    int_matrix1.print();

    cout << "\nMatrix_2\n";
    int_matrix2.print();

    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;

    pause("Apertar ENTER para continuar");
}

void method08()
{

    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);
    Matrix<int> int_matrix3(1, 1, 0);

    cout << endl
         << "EXEMPLO1210 - Method08 - v0.0" << endl;

    int_matrix1.fread("MATRIX1.TXT");

    cout << "\nMatrix_1\n";
    int_matrix1.print();

    int_matrix2 = int_matrix1;

    cout << "\nMatrix_2\n";
    int_matrix2.print();

    int_matrix3 = int_matrix1 - int_matrix2;

    cout << "\nMatrix_3\n";
    int_matrix3.print();

    pause("Apertar ENTER para continuar");
}

void method10()
{

    Matrix<int> int_matrix(3, 3, 0);
    int x = 0;
    int y = 0;

    cout << endl
         << "EXEMPLO1210 - Method10 - v0.0" << endl;

    int_matrix.fread("MATRIX1.TXT");

    cout << "\nMatrix\n";
    int_matrix.print();

    for (int x = 0; x < int_matrix.getRows(); x = x + 1)
    {
        for (int y = 0; y < int_matrix.getColumns(); y = y + 1)
        {
            int_matrix.set(x, y, int_matrix.get(x, y) * (-1));
        }
    }

    cout << "\nMatrix\n";
    int_matrix.print();

    pause("Apertar ENTER para continuar");
}

void method09()
{

    Matrix<int> int_matrix1(2, 2, 0);
    int_matrix1.set(0, 0, 1);
    int_matrix1.set(0, 1, 0);
    int_matrix1.set(1, 0, 0);
    int_matrix1.set(1, 1, 1);
    Matrix<int> int_matrix2(1, 1, 0);
    Matrix<int> int_matrix3(1, 1, 0);

    cout << endl
         << "EXEMPLO1210 - Method09 - v0.0" << endl;

    int_matrix2.fread("MATRIX1.TXT");

    cout << "\nMatrix_1\n";
    int_matrix1.print();

    cout << "\nMatrix_2\n";
    int_matrix2.print();

    int_matrix3 = int_matrix1 * int_matrix2;

    cout << "\nMatrix_3\n";
    int_matrix3.print();

    pause("Apertar ENTER para continuar");
}

int main()
{
    int option = 0;
    do
    {
        IO_println("Escolha uma opcao de 1 a 10: ");
        scanf("%d", &option);
        switch (option)
        {
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
            break;
        }
    } while (option != 0);
    IO_pause("Apertar ENTER para continuar");
}
