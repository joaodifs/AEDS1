/*
 Guia0213 - v0.0. - __ / __ / _____
 Author: ____________________
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0213 ./Guia0213.cpp
 No Windows: g++ -o Guia0213.exe Guia0213.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0213
 No Windows: Guia0213
*/
// lista de dependencias
#include "karel.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar paredes no mundo
    world->set ( 3, 2, HWALL ); // horizontal
    world->set ( 4, 2, HWALL );
    world->set ( 5, 2, HWALL );
    world->set ( 3, 8, HWALL );
    world->set ( 5, 8, HWALL );

    world->set ( 2, 3, VWALL ); // vertical
    world->set ( 2, 4, VWALL );
    world->set ( 2, 5, VWALL );
    world->set ( 2, 6, VWALL );
    world->set ( 2, 7, VWALL );
    world->set ( 2, 8, VWALL );
    world->set ( 5, 3, VWALL );
    world->set ( 5, 4, VWALL );
    world->set ( 5, 5, VWALL );
    world->set ( 5, 6, VWALL );
    world->set ( 5, 7, VWALL );
    world->set ( 5, 8, VWALL );
    world->set ( 3, 3, VWALL ); // vertical
    world->set ( 3, 4, VWALL );
    world->set ( 3, 5, VWALL );
    world->set ( 3, 6, VWALL );
    world->set ( 3, 7, VWALL );
    world->set ( 4, 3, VWALL );
    world->set ( 4, 4, VWALL );
    world->set ( 4, 5, VWALL );
    world->set ( 4, 6, VWALL );
    world->set ( 4, 7, VWALL );


// colocar um marcador no mundo
    world->set ( 3, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
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

    void pickBeepers( )
    {
        while ( nextToABeeper( ) )
        {
            pickBeeper( );
        }
    }
    void putBeepers(int beepers)
    {
        int beeper = 0;
        for ( beeper = 1; beeper <= beepers; beeper = beeper + 1 )
        {
            putBeeper( );
        }
    }
    /**
    turnRight - Procedimento (acao) para virar 'a direita.
    */
    void turnRight ( )
    {
// testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
// o agente que executar esse metodo
// devera' virar tres vezes 'a esquerda
            turnLeft ( );
            turnLeft ( );
            turnLeft ( );
        } // end if
    } // end turnRight ( )
    void goLeft( )
    {
        turnLeft( );
        turnLeft( );
        moveN(5);
        turnLeft( );
        move( );
        turnLeft( );
        moveN(5);
        pickBeepers( );

    }
    /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
    void moveN( int steps )
    {
// definir dado local
        int step = 0;
// repetir contando e testando ate' atingir a quantidade de passos
        for ( step = 1; step <= steps; step = step + 1 ) // outra forma de repetir
        {
// dar um passo por vez
            move( );
        } // end if
    } // end moveN( )
void putBeepers( )
{
if (areYouHere(9,1))
{
    while (beepersInBag( ))
    {
        putBeeper( );
    }
}
}
    void doTask( )
    {
        moveN(8);
        turnRight( );
        moveN(3);
        turnRight( );
        move( );
        turnLeft( );
        move( );
        turnRight( );
        moveN(5);
        pickBeepers( );
        goLeft( );
        goLeft( );
        turnLeft( );
        turnLeft( );
        moveN(5);
        turnRight( );
        move( );
        turnLeft( );
        move( );
        turnRight( );
        moveN(5);
        turnRight( );
        moveN(8);
        putBeepers( );
        turnRight( );
        moveN(8);
        turnLeft( );
        turnLeft( );



// encerrar
        turnOff ( );
    } // end doTask( )
}; // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
    world->create ( "" ); // criar o mundo
    decorateWorld ( "Guia0213.txt" );
    world->show ( );
// preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0213.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 1 ); // definir velocidade padrao
// criar robo
    MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, NORTH, 0, "Karel" );
// executar tarefa
    robot->doTask ( );
// encerrar operacoes no ambiente
    world->close ( );
// encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )
