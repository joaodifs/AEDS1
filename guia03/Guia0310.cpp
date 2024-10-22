/*
 Guia0310 - v0.5. - __ / __ / _____
 Author: __________________________
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0310 ./Guia0310.cpp
 No Windows: g++ -o Guia0310.exe Guia0310.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0310
 No Windows: Guia0310
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
     mapWorld Metodo para o robot explorar o mundo
     e fazer um mapa.
     @param map - arranjo bidimensional ( matriz )
     onde guardar o mapa
    */
    void mapWorld ( int map [ ][WIDTH] )
    {
// definir dados locais
        int avenue = 0,
            street = 0;
        int beepers = 0;
        char message [80];
// obter o tamanho do mundo
        if ( world != nullptr )
        {
// informar o tamanho do mundo
            message [0] = '\0';
            sprintf ( message, "World is %dx%d", world->avenues( ), world->streets( ) );
            show_Text ( message );
// percorrer o mundo procurando beepers
            for ( street=1; street<=world->streets( ); street=street+1 )
            {
                for ( avenue=1; avenue<=world->avenues( ); avenue=avenue+1 )
                {
// limpar posicao no mapa
                    map [ street-1 ][ avenue-1 ] = 0;
// se proximo a um marcador
                    if ( nextToABeeper( ) )
                    {
// informar marcador nesta posicao
                        message [0] = '\0';
                        sprintf ( message, "Beeper at (%d,%d)", avenue, street );
                        show_Text ( message );
// marcar posicao no mapa
                        map [ street-1 ][ avenue-1 ] = 1;
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

    /**
    readMap - Metodo para ler um mapa em arquivo.
    @param fileName - nome do arquivo com o mapa
    */
    void readMap ( const char * fileName )
    {
// definir dados
        int avenue = 0,
            street = 0;
        int avenues = 0,
            streets = 0;
        int x = 0,
            y = 0,
            z = 0;
        std::ifstream archive ( fileName );
// reservar area para guardar o maior mapa possivel
        char map [ HEIGHT ][ WIDTH ];
// obter o tamanho do mundo
        archive >> avenues;
        archive >> streets;
// testar configuracao do mapa
        if ( ( 0 < avenues && avenues <= world->width ) &&
                ( 0 < streets && streets <= world->height ) )
        {
// percorrer o mundo procurando marcadores
            for ( y=0; y<streets; y=y+1 )
            {
                for ( x=0; x<avenues; x=x+1 )
                {
                    map [ y ][ x ] = '.';
                } // end for
            } // end for
// repetir enquanto houver dados
            archive >> avenue; // tentar ler a primeira linha
            while ( ! archive.eof( ) ) // testar se nao encontrado o fim
            {
// contar mais um comando
                archive >> street;
                archive >> z ;
// testar se informacoes validas
                if ( (1 <= avenue && avenue <= world->width ) &&
                        (1 <= street && street <= world->height ) &&
                        (z == 1) )
                {
                    map [ street-1 ][ avenue-1 ] = 'X';
                } // end if
                archive >> avenue; // tentar ler a proxima linha
            } // end while
// fechar o arquivo
// RECOMENDAVEL para a leitura
            archive.close ( );
// mostrar o mapa
            showMap ( avenues, streets, map );
        } // end if
    } // end readMap ( )

    /**
     saveMap - Metodo para guardar um mapa em arquivo.
     @param filename - nome do arquivo onde guardar o mapa
     @param map - arranjo bidimensional (matriz) com o mapa
    */
    void saveMap ( const char * fileName, int map [ ][WIDTH] )
    {
// definir dados locais
        int avenue = 0,
            street = 0;
// abrir arquivo para gravacao
        std::ofstream archive ( fileName );
// testar se ha' informacao
        if ( world != nullptr )
        {
// guardar o tamanho do mundo
            archive << world->avenues( ) << "\n";
            archive << world->streets( ) << "\n";
// percorrer o mundo procurando beepers
            for ( street=1; street<=world->streets( ); street=street+1 )
            {
                for ( avenue=1; avenue<=world->avenues( ); avenue=avenue+1 )
                {
// guardar informacao no arquivo
                    if ( map [ street-1 ][ avenue-1 ] == 1 )
                    {
                        archive << avenue << std::endl;
                        archive << street << std::endl;
                        archive << map [street-1][avenue-1] << std::endl;
                    } // end if
                } // end for
            } // end for
// fechar arquivo
            archive.close ( );
        } // end if
    } // end saveMap ( )

    /**
    showMap - Metodo para ler um mapa em arquivo.
    @param avenues - largura do mapa
    @param streets - altura do mapa
    @param map - arranjo bidimensional (matriz) com o mapa
    */
    void showMap ( int avenues, int streets, char map [ ][WIDTH] )
    {
// definir dados
        int x = 0,
            y = 0;
// percorrer o mundo procurando marcadores
        clrscr ( );
        std::cout << " Mapa de marcadores\n\n";
        std::cout << " ";
        for ( x=0; x<streets; x=x+1 )
        {
            std::cout << (x+1);
        } // end for
        std::cout << std::endl;
        for ( y=0; y<streets; y=y+1 )
        {
            std::cout << (y+1);
            for ( x=0; x<avenues; x=x+1 )
            {
                std::cout << map [ y ][ x ];
            } // end for
            std::cout << std::endl;
        } // end for
        IO_pause ( " Apertar ENTER para continuar." );
    } // end showMap ( )

}; // end class MyRobot


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
    decorateWorld ( "Guia0310.txt" );
    world->show ( );
// preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0310.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 0 ); // definir velocidade padrao
// criar robo
    MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 0, "Karel" );

    // definir armazenador para o mapa
    int map [HEIGHT][WIDTH]; // altura x largura

    // executar tarefas
    robot->mapWorld ( map );
    robot->saveMap ( "Mapa0310.txt", map );
    robot->readMap ( "Mapa0310.txt" );

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
 0.1 08. ( OK ) criando um mapa do mundo
 0.1 09. ( OK ) salvando o mapa
 0.1 10. ( OK ) mostrar o mapa

*/
