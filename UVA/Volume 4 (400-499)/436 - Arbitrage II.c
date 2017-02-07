/*****************************************
 ***Problema: Arbirage II
 ***ID: 436
 ***Juez: UVA
 ***Tipo: Floyd Warshall
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 35
#define EPS 1e-7
int V;
double ady[ MAX ][ MAX ];
char s[ 105 ];

void init(){
    int i , j;
    for( i = 0 ; i < V ; ++i ){
        for( j = 0 ; j < V ; ++j ){
            ady[ i ][ j ] = ( i == j )? 1.0 : -1.0;
        }
    }
}

void floyd(){
    int i , k , j;
    for( k = 0 ; k < V ; ++k ){
        for( i = 0 ; i < V ; ++i ){
            if( ady[ i ][ k ] == -1.0 ) continue;
            for( j = 0 ; j < V ; ++j ){
                if( ady[ k ][ j ] == -1.0 ) continue;
                if( ady[ i ][ k ] * ady[ k ][ j ] > ady[ i ][ j ] ) ady[ i ][ j ] = ady[ i ][ k ] * ady[ k ][ j ];
            }
        }
    }
}

char names[ MAX ][ 105 ];
int num;
int getId(){
    int i;
    for( i = 0 ; i < num ; ++i ){
        if( strcmp( names[ i ] , s ) == 0 ) return i;
    }
    strcpy( names[ num ] , s );
    return num++;
}

int main(){
    int E , u , v , q = 1 , i;
    double w;
    while( scanf("%d", &V ) , V ){
        num = 0;
        for( i = 0 ; i < V && scanf("%s" , s ) == 1 ; ++i );
        init();
        scanf("%d" , &E );
        while( E-- ){
            scanf("%s" , s );
            u = getId();
            scanf("%lf" , &w );
            scanf("%s" , s );
            v = getId();
            ady[ u ][ v ] = w;
        }

        floyd();
        for( i = 0 ; i < V ; ++i )
            if( ady[ i ][ i ] > 1.0 + EPS ) break;

        printf("Case %d: " , q++ );
        if( i == V ) puts("No");
        else puts("Yes");
    }
    return 0;
}
