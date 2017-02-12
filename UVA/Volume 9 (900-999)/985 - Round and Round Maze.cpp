/*****************************************
 ***Problema: Round and Round Maze
 ***ID: 985
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <stack>
using namespace std;

#define MAX 505

int xfin , yfin, F, C;
bool ady[ MAX ][ MAX ][ 4 ], visited[ MAX ][ MAX ][ 4 ];

///N, E, S, O
int dx[ 4 ] = {-1 , 0 , 1 , 0 };
int dy[ 4 ] = { 0 , 1 , 0 , -1 };
struct Estado{
    int x;
    int y;

    Estado( int xx ,int yy ): x( xx ), y( yy ){}
    Estado(){}
}Q[ MAX*MAX*4];

int bfs(){

    int start, size, x, y;
    start = size = 0;
    Q[ size++ ] = Estado( 0 , 0 );

    memset( visited, 0 , sizeof( visited ) );
    visited[ 0 ][ 0 ][ 0 ] = 1;
    for( int k = 0 ; size!= 0 ; ++k ){
        for( int  j = size - 1; j >= 0 ; --j ){
             x = Q[ start ].x;
             y = Q[ start ].y;
             start++;
             size--;

             if( x == xfin && y == yfin ){
                 return k;
             }

             for( int i = 0 ; i < 4 ; ++i ){
                 if( ady[ x ][ y ][ i ] == false) continue;
                 int nx = x + dx[ (i + k ) % 4 ];
                 int ny = y + dy[ (i + k ) % 4 ];
                 if( nx >= 0 && nx < F && ny >= 0 && ny < C && !visited[ nx ][ ny ][ k%4 ]  ){
                     Q[start + size ] = Estado( nx, ny );
                     size++;
                     visited[ nx ][ ny ][ k%4 ] = 1;
                 }
             }
        }
    }
    return -1;
}

int main(){
    char s[ 5 ];
    int l;

    while( scanf( "%d %d", &F,&C ) != EOF ){

        xfin = F - 1;
        yfin = C - 1;

        for( int i = 0 ; i < F ; ++i ){
           for( int j = 0 ; j < C ; ++j ){
               ///exit
               if( i == xfin  && j == yfin )continue;

               scanf("%s", s );
               l = strlen( s );

               for( int q = 0 ; q < 4 ; ++q ) ady[ i ][ j ][ q ] = 0;

               for( int q = 0 ; q < l ; ++q ){
                   if( s[ q ] == 'N' ) ady[ i ][ j ][ 0 ] = 1;
                   if( s[ q ] == 'E' ) ady[ i ][ j ][ 1 ] = 1;
                   if( s[ q ] == 'S' ) ady[ i ][ j ][ 2 ] = 1;
                   if( s[ q ] == 'W' ) ady[ i ][ j ][ 3 ] = 1;
               }
           }
        }
        int resp = bfs();
        if( resp != -1 )printf("%d\n", resp );
        else printf("no path to exit\n");

    }
    return 0;
}

