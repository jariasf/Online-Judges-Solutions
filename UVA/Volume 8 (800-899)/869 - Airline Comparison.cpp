/*****************************************
 ***Problema: Airline Comparison
 ***ID: 869
 ***Juez: UVA
 ***Tipo: Floyd Warshall Transitive Closure
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#include <iostream>
#define MAX 26

int ady[ MAX ][ MAX ] , ady2[ MAX ][ MAX ];

void Init(){
    for( int i = 0 ; i < MAX ; ++i ){
        for( int j = 0 ; j < MAX ; ++j ){
             ady[ i ][ j ] = ady2[ i ][ j ] =  0;
        }
    }
}

void TransitiveClosure(){

    for( int k = 0 ; k < MAX ; ++k ){
        for( int i = 0 ; i < MAX ; ++i ){
            for( int j = 0 ; j < MAX ; ++j ){
                 ady[ i ][ j ] |= ady[ i ][ k ] & ady[ k ][ j ];
                 ady2[ i ][ j ] |= ady2[ i ][ k ] & ady2[ k ][ j ];
            }
        }
    }
}

int main(){
    int t ,E;
    char u , v;
    scanf("%d" ,&t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        scanf("%d" ,&E );
        Init();
        while( E-- ){
            scanf("\n%c %c", &u , &v );
            u = toupper( u ) ; v = toupper( v );
            ady[ u - 'A' ][ v - 'A' ] = ady[ v - 'A' ][ u - 'A' ] = 1;
        }
        scanf("%d" ,&E );
        while( E-- ){
            scanf("\n%c %c", &u , &v );
            u = toupper( u ); v = toupper( v );
            ady2[ u - 'A' ][ v - 'A' ] = ady2[ v - 'A' ][ u - 'A' ] = 1;
        }
        TransitiveClosure();
        int i , j;
        for( i = 0 ; i < MAX ; ++i ){
            for( j = 0 ; j < MAX ; ++j ){
                 if( ady[ i ][ j ] != ady2[ i ][ j ] ) break;

            }
            if( j < MAX )break;
        }
        if( i < MAX )printf("NO\n");
        else printf("YES\n");

    }

    return 0;
}
