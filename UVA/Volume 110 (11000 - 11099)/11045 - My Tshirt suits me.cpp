/*************************************************
 ***Problema: My T-shirt suits me
 ***ID: 11045
 ***Juez: UVA
 ***Tipo: Graph Theory, Maximum Bipartite Matching
 ***Autor: Jhosimar George Arias Figueroa
 *************************************************/

#include <stdio.h>
#include <cstring>
#define M 35
#define N 8

bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int shirt[ 6 ] , MM;

bool bpm( int u )
{
    for( int v = 0; v < 6; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;

        if( shirt[ v ] > 0 ){
            matchL[ u ] = v;
            shirt[ v ]--;
            return true;
        }

        for( int k = 0 ; k < MM ; ++k ){

            if( matchL[ k ] == v  && bpm( k ) )
            {
                matchL[ u ] = v;
                return true;
            }
        }
    }
    return false;
}

int getId( char *s ){
    if( strcmp( s , "L" ) == 0 )return 0;
    if( strcmp( s , "S" ) == 0 )return 1;
    if( strcmp( s , "XL" ) == 0 )return 2;
    if( strcmp( s , "XXL" ) == 0 )return 3;
    if( strcmp( s , "XS" ) == 0 )return 4;
    if( strcmp( s , "M" ) == 0 )return 5;
}

int main(){
    int t , NN ;
    scanf("%d" ,&t );
    char s1[ 4 ] , s2[ 4 ];
    while( t-- ){

        scanf("%d %d" , &NN , &MM );

        for( int i = 0 ; i < MM ; ++i ){
            scanf("%s %s" , &s1 , &s2 );

            graph[ i ][ getId( s1 ) ] = graph[ i ][ getId( s2 ) ] = 1;
        }

        for( int i = 0 ; i < 6 ; ++i ){
            shirt[ i ] = NN/6;
        }

        memset( matchL, 0xff , sizeof( matchL ) );

        ///HALLAMOS MATCHING
        int i;
        for( i = 0; i < MM; i++ )
        {
            memset( seen, 0, sizeof( seen ) );
            if( !bpm( i ) )break;
        }

        if( i < MM )puts("NO");
        else puts("YES");
        memset( graph , 0 , sizeof( graph ) );

    }

    return 0;
}
