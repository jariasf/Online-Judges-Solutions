/************************************************
 ***Problema: Pre in and post
 ***ID: 10701
 ***Juez: UVA
 ***Tipo: Graph Theory, Tree Traversal, recursion
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************/

#include <stdio.h>
#define MAX 55

void Solve( char *pre , char *in, int l){
    if( l < 1) return;
    if( l == 1 ){
       putchar( pre[ 0 ] );
       return;
    }
    int i;
    for( i = 0 ; i < l ; ++i ){
       if( pre[ 0 ] == in[ i ] )break;
    }
    Solve( pre + 1 , in , i );
    Solve( pre + i + 1 , in + i + 1 , l - i - 1);
    putchar( pre[ 0 ] );
}

int main(){
    int t , l;
    scanf("%d", &t );
    char pre[ MAX ], in [ MAX ];
    while( t-- ){
        scanf("%d %s %s", &l , pre, in);
        Solve( pre, in , l );
        putchar('\n');
    }
    return 0;
}
