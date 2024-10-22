/*
 Guia0110 - v0.0. - __ / __ / _____
 Author: ____________________
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0110 ./Guia0110.cpp
 No Windows: g++ -o Guia0110.exe Guia0110.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0110
 No Windows: Guia0110
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
world->set ( 3, 5, HWALL ); // horizontal
  world->set ( 4, 5, HWALL );
   world->set ( 5, 5, HWALL );


 world->set ( 2, 3, VWALL ); // vertical
  world->set ( 2, 4, VWALL );
   world->set ( 2, 5, VWALL );
 world->set ( 5, 3, VWALL );
  world->set ( 5, 4, VWALL );


// colocar um marcador no mundo
 world->set ( 4, 3, BEEPER );
  world->set ( 4, 3, BEEPER );
   world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
     world->set ( 4, 3, BEEPER );
      world->set ( 4, 3, BEEPER );

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

 void moveLN( int steps )
 {

    turnLeft( );
 int step = 0;
 for ( step = 1; step <= steps; step = step + 1 )
 {
 move( );
 }
 }

  void moveRN( int steps )
 {
    turnRight( );
 int step = 0;
 for ( step = 1; step <= steps; step = step + 1 )
 {
 move( );
 }
 }
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
 void doTask( )
 {
moveN(5);
moveLN(4);
moveLN(2);
moveLN(2);
pickBeepers(6);
turnLeft( );
moveLN(2);
moveRN(2);
moveRN(2);
putBeepers(3);
turnLeft( );
moveLN(3);
moveLN(3);
putBeepers(2);
moveN(1);
moveLN(3);
putBeeper( );
moveN(2);
moveRN(1);
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
 decorateWorld ( "Guia0110.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0110.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 3 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
 robot->doTask ( );
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )
// ---------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 0.1 ( OK ) teste inicial
 0.2 0.1 ( OK ) teste da tarefa
 0.3 0.1 ( OK ) teste da tarefa parcial
 0.4 0.1 ( OK ) teste do apanhar marcador
 0.5 0.1 ( OK ) teste do colocar marcador
0.6 01. ( OK ) teste da repeticao do movimento
0.7 01. ( OK ) teste com marcador na posicao (4,4)
02. ( OK ) teste sem marcador na posicao (4,4)
 0.8 01. ( OK ) teste com a quantidade de marcadores
 0.9 01. ( OK ) teste com outra forma de repeticao
 1.0 01. ( ) teste com outra forma de repeticao
 01. ( ) teste com outra forma de alternativa
*/

