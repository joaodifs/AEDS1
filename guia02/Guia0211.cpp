/*
 Guia0211 - v0.0. - __ / __ / _____
 Author: ____________________
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0211 ./Guia0211.cpp
 No Windows: g++ -o Guia0211.exe Guia0211.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0211
 No Windows: Guia0211
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
 world->set ( 3, 1, HWALL ); // horizontal
 world->set ( 4, 2, HWALL );
 world->set ( 5, 3, HWALL );
 world->set ( 6, 3, HWALL );
  world->set ( 7, 2, HWALL );
 world->set ( 8, 1, HWALL );
world->set ( 2, 1, VWALL ); // vertical
world->set ( 3, 2, VWALL );
world->set ( 4, 3, VWALL );
world->set ( 8, 1, VWALL );
world->set ( 7, 2, VWALL );
world->set ( 6, 3, VWALL );

// colocar um marcador no mundo
 world->set ( 9, 1, BEEPER );
 world->set ( 9, 1, BEEPER );
 world->set ( 9, 1, BEEPER );
 world->set ( 8, 2, BEEPER );
 world->set ( 8, 2, BEEPER );
 world->set ( 7, 3, BEEPER );
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
void pickBeepers(int beepers)
 {
  int beeper = 0;
 for ( beeper = 1; beeper <= beepers; beeper = beeper + 1 )
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
void StepUpRight( )
{
    turnLeft( );
    move( );
    turnRight( );
    move( );
}
void StepUpLeft ( )
{
    turnRight( );
    move( );
    turnLeft( );
    move( );
}
void StepDownRight( )
{
    move( );
    turnRight( );
    move( );
    turnLeft( );
}
void StepDownLeft( )
{
    move( );
    turnLeft( );
    move( );
    turnRight( );
}
 void doTask( )
 {
move( );
StepUpRight( );
StepUpRight( );
StepUpRight( );
move( );
StepDownRight( );
pickBeeper( );
StepDownRight( );
pickBeepers(2);
StepDownRight( );
pickBeepers(3);
turnLeft( );
turnLeft( );
StepUpLeft( );
StepUpLeft( );
StepUpLeft( );
move( );
StepDownLeft( );
putBeeper( );
StepDownLeft( );
putBeepers(2);
StepDownLeft( );
putBeepers(3);
move( );

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
 decorateWorld ( "Guia0211.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0211.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 2 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 3, "Karel" );
// executar tarefa
 robot->doTask ( );
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )
