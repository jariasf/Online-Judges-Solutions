/*****************************************
 ***Problema: S-tree
 ***ID: 712
 ***Juez: UVA
 ***Tipo: Tree, Tree traversal
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAXN 2000

#define MAX 2001
char tree[ MAX ], leafs[ MAX ];
int depth , pos;

void buildTree( int dp , int nodo ){

    if( dp == depth ){
        tree[ nodo * 2 + 1 ] = leafs[ pos++ ];
        tree[ nodo * 2 + 2 ] = leafs[ pos++ ];
    }
    else{
        //hijo izq
        tree[ nodo * 2 + 1 ] = '0';
        buildTree( dp + 1 , nodo * 2 + 1 );
        //hijo der
        tree[ nodo * 2 + 2  ] = '0';
        buildTree( dp + 1 , nodo * 2 + 2 );
    }
}

char dfs( int nodo , char *s ){

    int l = strlen( s );
    for( int i = 0 ; i < l ; ++i ){
        if( s[ i ] == '0' ){
            nodo = 2 * nodo + 1;
        }
        else nodo = 2 * nodo + 2 ;
    }
    return tree[ nodo ];
}

int main(){

    char s[ MAX ];
    int Q, q = 1;
    while( scanf("%d" ,&depth ) && depth ){

        for( int i = 0 ; i < depth ; ++i )scanf("%s", &s );
        scanf("%s" , &leafs );
        tree[ 0 ] = '0';
        pos = 0;
        buildTree( 1 , 0 );

        printf("S-Tree #%d:\n" , q++ );
        scanf("%d" , &Q );
        while( Q-- ){

            scanf("%s" , &s );
            printf("%c" , dfs( 0 , s ) );
        }
        printf("\n\n");
    }
    return 0;
}
