// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_
// dependencias
#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
// outras dependencias
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
#include "Erro.hpp"
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
    Contato()
    {
        // atribuir valores iniciais vazios
        nome = "";
        fone = "";
    } // fim construtor padrao

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
        this->fone = fone;
    } // fim setFone ( )
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

    /**
     * Funcao para obter dados de uma pessoa.
     * @return dados de uma pessoa
     */
    std::string toString()
    {
        return ("{ " + getNome() + ", " + getFone() + " }");
    } // fim toString ( )

    /**
     * Construtor alternativo.
     * @param nome_inicial a ser atribuido
     * @param fone_inicial a ser atribuido
     */
    Contato(std::string nome_inicial, std::string fone_inicial)
    {
        // atribuir valores iniciais
        nome = nome_inicial;
        fone = fone_inicial;
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
    } // fim construtor padrao

    /**
     * Metodo para atribuir nome.
     * @param nome a ser atribuido
     */
    void setNome(std::string nome)
    {
        if (nome.empty())
            setErro(1); // nome invalido
        else
            this->nome = nome;
    } // fim setNome ( )
    /**
     * Metodo para atribuir telefone.
     * @param fone a ser atribuido
     */
    void setFone(std::string fone)
    {
        if (fone.empty())
            setErro(2); // fone invalido
        else
            this->fone = fone;
    } // fim setFone ( )
    /**
     * Construtor alternativo.
     * @param nome_inicial a ser atribuido
     * @param fone_inicial a ser atribuido
     */
    Contato(std::string nome_inicial, std::string fone_inicial)
    {
        setErro(0); // nenhum erro, ainda
        // atribuir valores iniciais
        setNome(nome_inicial); // nome = nome_inicial;
        setFone(fone_inicial); // fone = fone_inicial;
    }                          // fim construtor alternativo

    /**
     * Construtor alternativo baseado em copia.
     */
    Contato(Contato const &another)
    {
        // atribuir valores iniciais por copia
        setErro(0);            // copiar erro
        setNome(another.nome); // copiar nome
        setFone(another.fone); // copiar fone
    }                          // fim construtor alternativo

};                             // fim da classe Contato
using ref_Contato = Contato *; // similar a typedef Contato* ref_Contato;
#endif