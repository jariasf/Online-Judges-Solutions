/*************************************************
 ***Problema: The dog Task
 ***ID: 670
 ***Juez: UVA
 ***Tipo: Graph Theory, Maximum bipartite matching
 ***Autor: Jhosimar George Arias Figueroa
 *************************************************/

#include <stdio.h>
#include <cmath>
#include <cstring>
#define MAX 105
int bob[ MAX ][ 2 ], dog[ MAX ][ 2 ];
#define M 105
#define N 105

bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int b,d;

bool bpm( int u )
{
    for( int v = 0; v < d; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;
        if( matchR[v] < 0 || bpm( matchR[v] ) )
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

double dist( int x , int y , int x1 , int y1 ){
    return sqrt( (x - x1) * ( x - x1 ) + ( y - y1 ) * ( y - y1 ) );
}

int main(){

    int t , g;
    double len , da , db;
    scanf( "%d" ,&t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        scanf("%d %d" , &b , &d );
        for( int i = 0 ; i < b ; ++i ){
            scanf("%d %d" , &bob[ i ][ 0 ] , &bob[ i ][ 1 ] );
        }
        for( int i = 0 ; i < d ; ++i ){
            scanf("%d %d" , &dog[ i ][ 0 ] , &dog[ i ][ 1 ] );
        }

        for( int i = 0 ; i < b - 1 ; ++i ){
            for( int j = 0 ; j < d ; ++j ){
                len = dist( bob[ i ][ 0 ] , bob[ i ][ 1 ] , bob[ i + 1 ][ 0 ] , bob[ i + 1 ][ 1 ] );
                da = dist( bob[ i ][ 0 ] , bob[ i ][ 1 ] , dog[ j ][ 0 ] , dog[ j ][ 1 ] );
                db = dist( bob[ i + 1 ][ 0 ] , bob[ i + 1 ][ 1 ] , dog[ j ][ 0 ] , dog[ j ][ 1 ] );
                if( da + db < 2 * len ) {
                    graph[ i ][ j ] = 1;
                }
            }
        }

        memset( matchL, -1, sizeof( matchL ) );
        memset( matchR, -1, sizeof( matchR ) );
        int cnt = 0;

        for( int i = 0; i < b; i++ )
        {
            memset( seen, 0, sizeof( seen ) );
            if( bpm( i ) ) cnt++;
        }

        printf("%d\n" , cnt + b );

        for( int i = 0 ; i < b ; ++i ){
            if( i > 0 )printf(" ");
            printf("%d %d" , bob[ i ][ 0 ] , bob[ i ][ 1 ]);
            if( matchL[ i ] != -1 )printf(" %d %d" , dog[ matchL[ i ] ][ 0 ] , dog[ matchL[ i ] ][ 1 ] );
        }
        printf("\n");
        memset( graph , 0 , sizeof( graph ) );
    }


    return 0;
}
