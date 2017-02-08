/*****************************************
 ***Problema: Tree Recovery
 ***ID: 536
 ***Juez: UVA
 ***Tipo: Recursion
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>
#define MAX 30
int x;

void solve( char *s1 , char *s2 , int l ){

    if( l < 1 )return;
    if( l == 1 ){
       putchar( s1[ 0 ] );
       return;
    }
    int i;
    for( i = 0 ; i < l ; ++i ){
        if( s1[ 0 ] == s2 [ i ] ){ break;}
    }
    solve( s1 + 1 , s2 , i);
    solve( s1 + 1 + i , s2 + i + 1 , l - i - 1);
    putchar( s1 [ 0 ] );
}

int main(){
    char s1[ MAX ], s2[ MAX ];
    int l1, l2 ;
    while( scanf("%s %s", s1 , s2 ) != EOF ){
        l1 = strlen( s1 );
        solve( s1 , s2 , l1);
        putchar('\n');
    }

    return 0;
}
