/*****************************************
 ***Problema: Lotto
 ***ID: 441
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <vector>

using namespace std;
#define MAX 13
int k;
int a[ MAX ];
int seen[ MAX ];
vector<int> ady[ MAX ];

void dfs( int u , int len ){

    seen[ u ] = 1;
    if( len == 6 ){
        bool b = false;
        for( int i = 0 ; i < k ; ++i ){
            if( seen[ i ] ){
                if( b )printf(" ");
                printf("%d" , a[ i ] );
                b = true;
            }
        }
        printf("\n");
        return;
    }

    for( int v = 0 ; v < ady[ u ].size() ; ++v ){
        int w = ady[ u ][ v ];
        if( !seen[ w ] ){
            dfs( w , len + 1 );
            seen[ w ] = 0;
        }
    }
}

int main(){
    bool b = false;
    while( scanf("%d" , &k ) && k ){
        if( b )putchar('\n');
        b = true;
        for( int i = 0 ; i < k ; ++i ){
            scanf("%d" , &a[ i ] );
            seen[ i ] = 0;
        }

        for( int i = 0 ; i < k ; ++i ){
            for( int j = i + 1 ; j < k ; ++j ){
                ady[ i ].push_back( j );
            }
        }

        for( int i = 0 ; i < k ; ++i ){
            memset( seen , 0 , sizeof( seen ) );
            dfs( i , 1 );
        }
        for( int i = 0 ; i < k ; ++i )ady[ i ].clear();
    }
    return 0;
}
