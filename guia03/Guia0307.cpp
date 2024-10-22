/*
 Guia0307 - v0.5. - __ / __ / _____
 Author: __________________________
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0307 ./Guia0307.cpp
 No Windows: g++ -o Guia0307.exe Guia0307.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0307
 No Windows: Guia0307
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar paredes no mundo
// world->set ( 4, 4, VWALL );
// world->set ( 4, 4, HWALL );
// colocar um marcador no mundo
    world->set ( 4, 4, BEEPER );
// salvar a configuracao atual do mundo
    world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
public:
    /**
    turnRight - Procedimento para virar 'a direita.
    */
    void turnRight ( )
    {
// definir dado local
        int step = 0;
// testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
// o agente que executar esse metodo
// devera' virar tres vezes 'a esquerda
            for ( step = 1; step <= 3; step = step + 1 )
            {
                turnLeft( );
            } // end for
        } // end if
    } // end turnRight ( )
    /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
    void moveN( int steps )
    {
// definir dado local
        int step = 0;
// testar se a quantidade de passos e' maior que zero
        for ( step = steps; step > 0; step = step - 1 )
        {
// dar um passo
            move( );
        } // end if
    } // end moveN( )

/**
 mapWorld - Metodo para o robot explorar o mundo.
*/
void mapWorld ( )
{
// definir dados locais
 int avenue = 0,
 street = 0;
 int beepers = 0;
 char message [80];
// obter o tamanho do mundo, se existir
 if ( world != nullptr )
 {
 // informar o tamanho do mundo
 message [0] = '\0';
 sprintf ( message, "World is %dx%d", world->avenues( ), world->streets( ) );
 show_Text ( message );
 // percorrer o mundo procurando marcadores
 for ( street=1; street<=world->streets( ); street=street+1 )
 {
 for ( avenue=1; avenue<=world->avenues( ); avenue=avenue+1 )
 {
 // se proximo a um marcador
 if ( nextToABeeper( ) )
 {
 // informar marcador nessa posicao
 message [0] = '\0';
 sprintf ( message, "Beeper at (%d,%d)", avenue, street );
 show_Text ( message );
 // encontrado mais um marcador
 beepers = beepers + 1;
 } // end if
 // mover para a proxima posicao
 if ( avenue < world->avenues( ) )
 {
 move( );
 } // end if
 } // end for
 turnLeft ( );
 turnLeft ( );
 moveN ( world->avenues( )-1 );
 if ( street < world->streets( ) )
 {
 turnRight ( );
 move ( );
 turnRight ( );
 } // end if
 } // end for
 } // end if
} // end mapWorld( )

}; // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// declarar as variáveis
int quantidade=0;
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
    world->create ( "" ); // criar o mundo
    decorateWorld ( "Guia0307.txt" );
    world->show ( );
// preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0307.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 0 ); // definir velocidade padrao
// criar robo
    MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 0, "Karel" );
    // executar tarefa
    robot->mapWorld ( );

// encerrar operacoes no ambiente
    world->close ( );
// encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
 0.1 02. ( OK ) "countcommands" retornando valor
 0.1 03. ( OK ) procedimento para ler os comandos
 0.1 04. ( OK ) adicionando os comandos
 0.1 05. ( OK ) executando pelo doTask
 0.1 06. ( OK ) mostrando tamanho do mundo
 0.1 07. ( OK ) método para explorar mundo

*/
