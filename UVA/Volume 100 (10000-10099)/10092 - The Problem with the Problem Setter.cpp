/*************************************************
 ***Problema: The Problem with the Problem Setter
 ***ID: 10092
 ***Juez: UVA
 ***Tipo: Graph Theory, Maximum Bipartite Matching
 ***Autor: Jhosimar George Arias Figueroa
 *************************************************/

#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;
#define M 30
#define N 1005

bool graph[ N ][ M ];
bool seen[ M ];
int matchL[ N ], matchR[ M ];
int n, m;

bool bpm( int u ){
    for( int v = 1; v <= m; v++ ){
		if( graph[u][v] ){
        	if( seen[v] ) continue;
        	seen[v] = true;

        	if( matchR[ v ] > 0 ){
            	matchL[ u ] = v;
            	matchR[ v ]--;
            	return true;
        	}

    	    for( int k = 1 ; k <= n ; ++k ){
	            if( matchL[ k ] == v && bpm( k ) ){
   	                matchL[ u ] = v;
                    return true;
                }
            }
        }
	}
    return false;
}

int main(){
    int k , cat, ncat;
    while( scanf("%d %d" , &m , &n ) && m|n ){

        ncat = 0;
        for( int i = 1 ; i <= m ; ++i ){
            scanf("%d" , &matchR[ i ] );
            ncat += matchR[ i ];
        }

        for( int i = 1 ; i <= n ; ++i ){
            scanf("%d" , &k );
            while( k-- ){
                scanf("%d" , &cat );
                graph[ i ][ cat ] = 1;
            }
        }

        memset( matchL, -1 , sizeof( matchL ) );

        int i, cnt = 0;

        for( i = 1; i <= n; ++i ){
            memset( seen, 0, sizeof( seen ) );
            if( bpm( i ) ) cnt++;
        }

        if( cnt != ncat )printf("0\n");
        else{
            printf("1\n");
            vector< int > v[ M ];

            for( int i = 1 ; i <= n ; ++i ){
                if( matchL[ i ] != -1 ){
                    v[ matchL[ i ] ].push_back( i );
                }
            }

            for( int i = 1 ; i <= m; ++i ){

                for( int j = 0 ; j < v[ i ].size() ; ++j ){
                     if( j != 0 )printf(" ");
                     printf("%d" , v[ i ][ j ] );
                }
                printf("\n");
            }

        }
        memset( graph , 0 , sizeof( graph ) );
    }
    return 0;
}
