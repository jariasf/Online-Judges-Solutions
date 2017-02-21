/*****************************************
 ***Problema: Robot Motion
 ***ID: 10116
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <cstdio>
#include <cstring>
#define MAX 605
char tabla[ MAX ][ MAX ];
int dist[ MAX ][ MAX ];

int main(){

    int f , c ,  x , y , dist_ant;

    while( scanf("%d %d %d" , &f , &c , &y ) , f | c | y ){
        memset( dist , 0 , sizeof( dist ) );
        for( int i = 0 ; i < f ; ++i ) scanf("%s" , &tabla[ i ] );
        x = 0;
        dist_ant = 0;
        y--;
        while( 1 ){
            if( dist[ x ][ y ] ){
                printf("%d step(s) before a loop of %d step(s)\n" , dist[ x ][ y ] - 1 , dist_ant - dist[ x ][ y ] + 1 );
                break;
            }
            //si exceo
            if( x < 0 || y < 0 || x >= f || y >= c ){
                printf("%d step(s) to exit\n" , dist_ant );
                break;
            }
            dist[ x ][ y ] = dist_ant + 1;
            dist_ant = dist[ x ][ y ];
            if( tabla[ x ][ y ] == 'N' ) x--;
            else if( tabla[ x ][ y ] == 'S' ) x++;
            else if( tabla[ x ][ y ] == 'E' ) y++;
            else y--;
        }
    }
    return 0;
}
