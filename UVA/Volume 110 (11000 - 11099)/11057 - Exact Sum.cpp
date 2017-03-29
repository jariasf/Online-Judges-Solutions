/*****************************************
 ***Problema: Exact Sum
 ***ID: 11057
 ***Juez: UVA
 ***Tipo: Search
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 10005
#define MAXN 2000005
int a[ MAX ], seen[ MAXN ];

int main(){
    int n , s , l , u , diff, L , U;
    while( scanf("%d" , &n ) == 1 ){
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 0 ; i < n ; ++i ) { scanf("%d" , &a[ i ] ); seen[ a[ i ] ]++; }
        scanf("%d" , &s );
        diff = 1<<30;
        for( int i = 0 ; i < n ; ++i ){
            if( a[ i ] <= s && seen[ s - a[ i ] ] ){
                l = a[ i ];
                u = s - a[ i ];
                if( l == u && seen[ u ] == 1 ) continue;
                if( l > u ) swap( l , u );
                if( diff > u - l ){
                    diff = u - l;
                    L = l;
                    U = u;
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n" , L , U );
    }

    return 0;
}
