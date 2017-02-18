/*****************************************
 ***Problema: Count the faces
 ***ID: 10178
 ***Juez: UVA
 ***Tipo: Graph Theory, Euler Formula
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 70
int uf[ MAX ];
int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}
void Union( int x , int y ){
    uf[ Find( x ) ] =  Find( y );
}

char cities[ MAX ][ 2 ];
int numcities;
int get_Id( char *s ){

    for( int i = 0 ; i < numcities ; ++i ){
        if( strcmp( s , cities[ i ] ) == 0 ) return i;
    }
    strcpy( cities[ numcities ] ,s );
    return numcities++;
}

int main(){
    int V , E , components;
    char u[ 2 ] , v[ 2 ];
    while( scanf("%d %d" , & V , &E ) != EOF ){

        components = 0;
        numcities = 0;
        for( int i = 0 ; i < V ; ++i ) uf[ i ] = i;
        for( int i = 0 ; i < E ; ++i ){
            scanf("%s %s" , &u , &v );
            int x = get_Id( u ), y = get_Id( v );
            Union( x , y );
        }

        for( int i = 0 ; i < V ; ++i ){
            if( Find( i ) == i ){
                components++;
            }
        }
        printf("%d\n" , 1 + E - V + components );
    }

    return 0;
}
