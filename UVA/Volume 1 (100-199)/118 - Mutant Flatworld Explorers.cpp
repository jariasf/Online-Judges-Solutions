/*****************************************
 ***Problema: Mutant Flatworld Explorers
 ***ID: 118
 ***Juez: UVA
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 55
int h , w;
int ady[ MAX ][ MAX ];
char s[ 105 ];

#define N 0
#define W 1
#define S 2
#define E 3
char d[4] = { 'N' , 'W' , 'S' , 'E' };
int dx[4] = { 0 , -1 , 0  , 1 };
int dy[4] = { 1 ,  0 , -1 , 0 };

void simulate( int x , int y , char dir ){

    for( int i = 0 ; s[ i ] ; ++i ){
        if( s[ i ] == 'F' ){
            int nx = dx[ dir ] + x, ny = dy[ dir ] + y;
            if( nx >= 0 && nx <= h && ny >= 0 && ny <= w ){
                x = nx;
                y = ny;
            }
            else{
                if( ady[ x ][ y ] ){
                    continue;
                }
                else{
                    printf("%d %d %c LOST\n" , x , y , d[ dir ] );
                    ady[ x ][ y ] = 1;
                    return;
                }
            }
        }
        else if( s[ i ] == 'L' ){
            dir = (dir + 1) % 4;
        }
        else {
            dir = ( 4 + dir - 1 ) % 4;
        }
    }
    printf("%d %d %c\n" , x , y , d[ dir ] );
}

int main(){
    int x , y;
    char c;
    scanf("%d %d" , &h , &w );
    memset( ady , 0 , sizeof( ady ) );
    while( scanf("%d %d %c" , &x , &y , &c ) != EOF ){
        gets( s );
        gets( s );
        simulate( x , y , ( c=='N')?0:( c == 'S')?2:( c == 'E')?3:1 );
    }
    return 0;
}
