// dependências
#include <iostream>
#include <fstream>
#include "io.hpp"
#include <iomanip>

//---------------------------------------------------------------//
// programas :)

using namespace std;

/**
 * Classe para tratar erro.
 */

class Erro
{

private:
    int erro;

protected:
    // ------------------------------------------- metodos para acesso restrito
    /**
    * Metodo para estabelecer novo codigo de erro.
    @param codigo de erro a ser guardado
    */
    void setErro(int codigo)
    {
        erro = codigo;
    } // end setErro ( )
    /**
     * definicoes publicas.
     */
public:
    /**
     * Destrutor.
     */
    ~Erro()
    {
    }
    /**
     * Construtor padrao.
     */
    Erro()
    {
        // atribuir valor inicial
        erro = 0;
    } // fim construtor padrao
    // ------------------------------------------- metodos para acesso
    /**
    * Funcao para obter o codigo de erro.
    @return codigo de erro guardado
    */
    int getErro()
    {
        return (erro);
    } // end getErro ( )
};    // fim da classe Erro

/*
 Contato.hpp - v0.0. - __ / __ / _____
 Author: ______________________
*/
// ----------------------------------------------- definicoes globais

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

// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar contatos, derivada da classe Erro.
 */
class Contato : public Erro
{
    /**
     * atributos privados.
     */
private:
    string nome;
    string fone;
    string fone2;
    int numberfone;

    // Exemplo1313

    void testFone()
    {
        int x = 0;
        while (x < fone.length())
        {
            if (!isdigit(fone[x]) && fone[x] != '-')
            {
                setErro(2);
            }
            x++;
        }
    }
    /**
     * definicoes publicas.
     */
public:
    /**
     * Destrutor.
     */
    ~Contato()
    {
    }
    /**
     * Construtor padrao.
     */

    // ----------------------------------- metodos para acesso
    /**
     * Metodo para atribuir nome.
     * @param nome a ser atribuido
     */
    void setNome(std::string nome)
    {
        this->nome = nome;
    } // fim setNome ( )
    /**
     * Metodo para atribuir telefone.
     * @param fone a ser atribuido
     */

    void setFone(std::string fone)
    {

        if (this->fone == "")
        {
            this->fone = fone;
            numberfone++;
        }
        else
        {
            this->fone = fone;
        }
        testFone();

    } // fim setFone ( )
    void setFone2(std::string fone2)
    {
        if (this->fone2 == "")
        {
            this->fone2 = fone2;
            numberfone++;
        }
        else
        {
            this->fone2 = fone2;
        }
    }
    /**
     * Funcao para obter nome.
     * @return nome armazenado
     */
    std::string getNome()
    {
        return (this->nome);
    } // fim getNome ( )
    /**
     * Funcao para obter fone.
     * @return fone armazenado
     */
    std::string getFone()
    {
        return (this->fone);
    } // fim getFone ( )
    std::string getFone2()
    {
        return (this->fone2);
    } // fim getFone2 ( )
    int getFoneNum()
    {
        return (this->numberfone);
    } // fim getFone2 ( )
    /**
     * Funcao para obter dados de uma pessoa.
     * @return dados de uma pessoa
     */
    std::string toString()
    {
        return ("{ " + getNome() + ", " + getFone() + ", " + getFone2() + " }");
    }
    /**
     * Construtor alternativo.
     * @param nome_inicial a ser atribuido
     * @param fone_inicial a ser atribuido
     */
    Contato(std::string nome_inicial, std::string fone_inicial, std::string fone2_inicial)
    {
        // atribuir valores iniciais
        nome = nome_inicial;
        fone = fone_inicial;
        fone2 = fone2_inicial;
        if (fone != "" && fone2 != "")
        {
            numberfone = 2;
        }
        else if (fone == "" || fone2 == "")
        {
            numberfone = 1;
        }
        else
        {
            numberfone = 0;
        }
    } // fim construtor alternativo

    /**
     * Construtor padrao.
     */
    Contato()
    {
        setErro(0); // nenhum erro, ainda
        // atribuir valores iniciais vazios
        nome = "";
        fone = "";
        fone2 = "";
        numberfone = 0;
    } // fim construtor padrao

    /**
     * indicar a existencia de erro.
     */
    bool hasErro()
    {
        return (getErro() != 0);
    } // end hasErro ( )

    /**
     * Construtor alternativo baseado em copia.
     */
    Contato(Contato const &another)
    {
        // atribuir valores iniciais por copia
        setErro(0);                      // copiar erro
        setNome(another.nome);           // copiar nome
        setFone(another.fone);           // copiar fone
        setFone2(another.fone2);         // copiar fone2
        numberfone = another.numberfone; // copiar numberfone
    }                                    // fim construtor alternativo

    // Exemplo1311

    void readNome()
    {
        string nome;
        do
        {
            cout << "\nDigite o nome do contato: ";
            cin >> nome;
            setNome(nome);
            if (hasErro())
            {
                cout << "\nNome invalido";
            }

        } while (hasErro());
    }

    // Exemplo1312

    void readFone()
    {
        string fone;
        do
        {
            cout << "\nDigite o telefone do contato: ";
            cin >> fone;
            setFone(fone);
            if (hasErro())
            {
                cout << "\nTelefone invalido";
            }

        } while (hasErro());
    }

    // Exemplo1314

    void readFile(string nomearquivo)
    {
        ifstream arquivo(nomearquivo);
        string nome;
        string fone;
        arquivo >> nome;
        arquivo >> fone;
        setNome(nome);
        setFone(fone);
        arquivo.close();
    }

    // Exemplo1315

    void savearquivo(string nomearquivo)
    {
        ofstream arquivo(nomearquivo);
        arquivo << nome << endl;
        arquivo << fone << endl;
        arquivo.close();
    }

    // Exemplo1318

    void readFone2()
    {
        string fone2;
        do
        {
            cout << "\nDigite o segundo telefone: ";
            cin >> fone2;
            setFone2(fone2);
            if (hasErro())
            {
                cout << "\nTelefone invalido";
            }

        } while (hasErro());
    }

    // Exemplo1319

    void attFone2(string newfone2)
    {
        if (this->fone2 == "")
        {
            setErro(3);
        }
        else
        {
            setFone2(newfone2);
        }
    }

    // Exemplo1320

    void rmvFone2()
    {
        if (this->fone2 == "")
        {
            setErro(3);
        }
        else
        {
            setFone2("");
        }
    }

};                             // fim da classe Contato
using ref_Contato = Contato *; // similar a typedef Contato* ref_Contato;

//--------------------------METHODS----------------------------//
void method11()
{
    ref_Contato contato = new Contato();
    contato->readNome();
    cout << "\nNome do contato e: " << contato->getNome();
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method12()
{
    ref_Contato contato = new Contato();
    contato->readFone();
    cout << "\nO telefone do contato e: " << contato->getFone();
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method13()
{
    ref_Contato contato = new Contato();
    string fone;
    cout << "\nDigite um numero de telefone: ";
    cin >> fone;
    contato->setFone(fone);
    if (!contato->hasErro())
    {
        cout << "\nO numero e valido";
    }
    else
    {
        cout << "\nO numero e invalido";
    }
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method14()
{
    ref_Contato contato = new Contato();
    contato->readFile("Exe1314.txt");
    cout << endl
         << contato->toString();
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method15()
{
    ref_Contato contato = new Contato();
    contato->readNome();
    contato->readFone();
    contato->savearquivo("Exe1315.txt");
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method16()
{
    ref_Contato contato = new Contato();
    contato->readNome();
    contato->readFone();
    cout << "\nDigite o segundo telefone do contato: ";
    string fone2;
    cin >> fone2;
    contato->setFone2(fone2);
    cout << endl
         << contato->toString();
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method17()
{
    ref_Contato contato = new Contato();
    contato->readNome();
    contato->readFone();
    int x;
    cout << "\nDigite 0 se voce nao quiser adicionar um novo telefone ou 1 se deseja adicionar: ";
    cin >> x;
    if (x == 1)
    {
        cout << "\nDigite o segundo telefone do contato: ";
        string fone2;
        cin >> fone2;
        contato->setFone2(fone2);
    }
    cout << endl
         << contato->toString();
    cout << endl
         << contato->getFoneNum() << " Numeros registrados no contato";
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method18()
{
    ref_Contato contato = new Contato();
    contato->readNome();
    contato->readFone();
    int x;
    cout << "\nDigite 0 se voce nao quiser adicionar um novo telefone ou 1 se deseja adicionar: ";
    cin >> x;
    if (x == 1)
    {
        contato->readFone2();
    }
    cout << endl
         << contato->toString();
    cout << endl
         << contato->getFoneNum() << " Numeros registrados no contato";
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method19()
{
    ref_Contato contato = new Contato();
    contato->readNome();
    contato->readFone();
    contato->readFone2();
    cout << endl
         << contato->toString();
    cout << "\nDigite um novo numero para um novo telefone: ";
    string x;
    cin >> x;
    contato->attFone2(x);
    cout << endl
         << contato->toString() << endl;
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

void method20()
{
    ref_Contato contato = new Contato();
    contato->readNome();
    contato->readFone();
    contato->readFone2();
    cout << endl
         << contato->toString();
    contato->rmvFone2();
    cout << endl
         << contato->toString();
    getchar();
    IO_pause("\nAperte ENTER para continuar");
}

//---------------------------MAIN--------------------------------//
int main()
{
    int option = 0;
    IO_println("--------------------------------------------");
    IO_id("\nEXEMPLO1320 - v0.0");
    IO_println("--------------------------------------------");
    do
    {
        IO_println("");
        option = IO_readint("\nEscolha uma opcao de 11 a 20, referente ao exercicio: ");
        switch (option)
        {
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
            break;
        }
    } while (option != 0);
    IO_pause("Apertar ENTER para continuar");
}