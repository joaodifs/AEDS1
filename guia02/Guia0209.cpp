/*
 Guia_0202 - v0.0. - __ / __ / _____
 Author: _____________________
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0209 ./Guia0209.cpp
 No Windows: g++ -o Guia0209.exe Guia0209.cpp
 Para executar em uma janela de comandos (terminal):

 No Linux : ./Guia0209
 No Windows: Guia0209
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp" // para entradas e sa�das
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar paredes no mundo
 world->set ( 4, 4, VWALL );
 world->set ( 4, 4, HWALL );
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
 * execute - Metodo para executar um comando.
 * @param action - comando a ser executado
 */
 void execute( int option )
 {
 // executar a opcao de comando
 switch ( option )
 {
 case 0: // n�o fazer nada
 break;
 case 1: // virar para a esquerda
 if ( leftIsClear ( ) )
 {
 turnLeft( );
 } // end if
 break;
 case 2: // virar para o sul
 while ( ! facingSouth( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 3: // virar para a direita
 if ( rightIsClear ( ) )
 {
 turnRight( );
 } // end if
 break;
 case 4: // virar para o oeste
 while ( ! facingWest( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 5: // mover
 if ( frontIsClear ( ) )
 {
 move( );
 } // end if
 break;
 case 6: // virar para o leste
 while ( ! facingEast( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 7: // pegar marcador
 if ( nextToABeeper( ) )
 {
 pickBeeper( );
 } // end if
 break;
 case 8: // virar para o norte
 while ( ! facingNorth( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 9: // colocar marcador
 if ( beepersInBag( ) )
 {
 putBeeper( );
 } // end if
 break;
 default:// nenhuma das alternativas anteriores
 // comando invalido
 show_Error ( "ERROR: Invalid command." );
 } // end switch
 } // end execute( )
/**
 * moveI - Metodo para mover o robot interativamente.
 * Lista de comandos disponiveis:
 * 0 - turnOff
 * 1 - turnLeft 2 - to South
 * 3 - turnRight 4 - to West
 * 5 - move 6 - to East
 * 7 - pickBeeper 8 - to North
 * 9 - putBeeper
 */
 void moveI( )
 {
 // definir dados
 int action;
 // repetir (com testes no fim)
 // enquanto opcao diferente de zero
 do
 {
 // ler opcao
 action = IO_readint ( "Command? " );
 // executar acao dependente da opcao
 execute ( action );
 }
 while ( action != 0 );
 } // end moveI( )
 /**
 * dictionary - Metodo para traduzir um comando.
 * @param action - comando a ser traduzido
 */
 chars dictionary( int action )
 {
 // definir dado
 static char word [80];
 strcpy ( word, "" ); // palavra vazia
 // identificar comando
 switch ( action )
 {
 case 1: // virar para a esquerda
 strcpy ( word, "turnLeft( ); " );
 break;
 case 2: // virar para o sul
 strcpy ( word, "faceSouth( ); " );
 break;
 case 3: // virar para a direita
 strcpy ( word, "turnRight( ); " );
 break;
 case 4: // virar para o oeste
 strcpy ( word, "faceWest( ); " );
 break;
 case 5: // mover
 strcpy ( word, "move( ); " );
 break;
 case 6: // virar para o leste
 strcpy ( word, "faceEast( ); " );
 break;
 case 7: // pegar marcador
 strcpy ( word, "pickBeeper( );" );
 break;
 case 8: // virar para o norte
 strcpy ( word, "faceNorth( ); " );
 break;
 case 9: // colocar marcador
 strcpy ( word, "putBeeper( ); " );
 break;
 } // end switch
 // retornar palavra equivalente
 return ( &(word[0]) );
 } // end dictionary( )
 /**
 recordActions - Metodo para mover o robot interativamente
 e guardar a descricao da tarefa em arquivo.
 @param fileName - nome do arquivo
*/
void recordActions ( const char *fileName )
{
 // definir dados
 int action;
 // definir arquivo onde gravar comandos
 std::ofstream archive ( fileName );
 // repetir enquanto o comando
 // for diferente de zero
 do
 {
 // ler opcao
 action = IO_readint ( "Command? " );
 // testar se opcao valida
 if ( 0 <= action && action <= 9 )
 {
 // executar comando
 execute ( action );
 // guardar o comando em arquivo
 archive << action << "\n";
 } // end if
 }
 while ( action != 0 );
 // fechar o arquivo
 // INDISPENSAVEL para a gravacao
 archive.close ( );
} // end recordActions ( )
/**
 translateActions - Metodo para receber comandos de arquivo e traduzi-los.
 @param fileName - nome do arquivo
*/
void translateActions ( const char *fileName )
{
// definir dados
 int action;
// definir arquivo de onde ler dados
 std::ifstream archive ( fileName );
// repetir enquanto houver dados
 archive >> action; // tentar ler a primeira linha
 while ( ! archive.eof( ) ) // testar se nao encontrado o fim
 {
 // tentar traduzir um comando
 IO_print ( dictionary ( action ) );
 getchar ( );
 // guardar mais um comando
 execute ( action );
 // tentar ler a proxima linha
 archive >> action ; // tentar ler a proxima linha
 } // end for
// fechar o arquivo
// RECOMENDAVEL para a leitura
 archive.close ( );
} // end translateActions ( )

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
 decorateWorld ( "Guia0209.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0209.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 2 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, NORTH, 0, "Karel" );
// executar e gravar acoes
robot->recordActions ( "Tarefa0209.txt" );
robot-> translateActions ( "Tarefa0209.txt" );
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )
// ---------------------------------------------- testes
//
// Versao Teste
// 0.1 01. ( OK ) teste inicial
// 0.2 01. ( OK ) teste da repeticao para virar 'a direita
// 0.3 01. ( OK ) teste da repeticao para percorrer um quadrado
