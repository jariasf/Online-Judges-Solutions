/******************************************************
 ***Problema: All Walks of length n from the first node
 ***ID: 677
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************************/

#include <stdio.h>
#include <cstring>
#define MAX 16
int ady[ MAX ][ MAX ];
bool seen[ MAX ];
int n, sz;
int ans[ MAX ];
bool found;
void dfs( int len , int x ){
    ans[ len ] = x;
    if( len == sz ){
        printf("(");
        for( int i = 0 ; i <= sz ; ++i ){
            if( i ) printf(",");
            printf("%d" , ans[ i ] );
        }
        printf(")\n");
        found = true;
        return;
    }
    seen[ x ] = 1;

    for( int i = 1 ; i <= n ; ++i ){
        if( ady[ x ][ i ] && !seen[ i ] ){
            dfs( len + 1 , i );
        }
    }
    seen[ x ] = 0;
}

int main(){
    int x;
    int b = 0;
    while( scanf("%d %d" , &n , &sz  ) != EOF ){
        for( int i = 1 ; i <= n ; ++i )
            for( int j = 1 ; j <= n ; ++j )
                scanf("%d", &ady[ i ][ j ] );

        found = false;
        memset( seen , 0 , sizeof( seen ) );
        if( b != 0 )printf("\n");
        dfs( 0 , 1 );
        if(!found )printf("no walk of length %d\n" , sz );
        memset( ady , 0 , sizeof( ady ) );
        scanf("%d" , &b );
    }

    return 0;
}
