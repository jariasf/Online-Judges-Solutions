/*****************************************
 ***Problema: Heavy Cargo
 ***ID: 544
 ***Juez: UVA
 ***Tipo: Floyd Warshall, Maxmin
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 205
#define INF 9999999
int ady[ MAX ][ MAX ];

void Init( int V ){

    for( int i = 0 ; i < V ; ++i ){
        for( int j = 0 ; j < V ; ++j ){
            ady[ i ][ j ] = -1;
        }
        ady[ i ][ i ] = 0;
    }

}

void Floyd( int V ){

    for( int k = 0 ; k < V ; ++k ){
        for( int i = 0 ; i < V ; ++i ){
             for( int j = 0 ; j < V ; ++j ){
                  ady[ i ][ j ] = ady[ j ][ i ] = max( ady[ i ][ j ] , min( ady[ i ][ k ] , ady[ k ][ j ] ) );
             }
        }
    }
}

char cities[ MAX ][ 40 ];
int numcities;
int get_Id( char *s ){

    for( int i = 0 ; i < numcities ; ++i ){
        if( strcmp( s , cities[ i ] ) == 0 ) return i;
    }
    strcpy( cities[ numcities ] ,s );
    return numcities++;
}

int main(){
    char u[ 40 ] , v [ 40 ];
    int w, uu, vv , q = 1 ,V ,E;
    while( scanf("%d %d", &V ,&E ) && V|E ){
        Init( V );
        numcities = 0;
        while( E-- ){
            scanf("%s %s %d" , &u , &v , &w );
            uu = get_Id( u ); vv = get_Id( v );
            ady[ uu ][ vv ] = ady[ vv ][ uu ] = w;
        }
        Floyd( V );
        scanf("%s %s" ,&u ,&v );

        printf("Scenario #%d\n%d tons\n\n" ,q++ , ady[ get_Id( u ) ][ get_Id( v ) ]);
        memset( ady , 0 ,sizeof( ady ) );
    }

    return 0;
}
