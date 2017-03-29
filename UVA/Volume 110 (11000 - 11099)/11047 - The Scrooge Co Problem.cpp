/*****************************************
 ***Problema: The Scrooge Co Problem
 ***ID: 11047
 ***Juez: UVA
 ***Tipo: Floyd Warshall
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 105
#define INF 1<<30
int ady[ MAX ][ MAX ], path[ MAX ][ MAX ], V;

void initPath(){
    int i , j;
    for( i = 0 ; i < V ; ++i )
        for( j = 0 ; j < V ; ++j ){
            if( ady[ i ][ j ] == INF || ady[ i ][ j ] == 0 ) path[ i ][ j ] = 0;
            else path[ i ][ j ] = i;
        }
}

void floyd(){
    int i , j , k;
    for( k = 0 ; k < V ; ++k ){
        for( i = 0 ; i < V ; ++i ){
            if( ady[ i ][ k ] == INF ) continue;
            for( j = 0 ; j < V ; ++j ){
                if( ady[ k ][ j ] != INF && ady[ i ][ k ] + ady[ k ][ j ] < ady[ i ][ j ] ){
                    ady[ i ][ j ] = ady[ i ][ k ] + ady[ k ][ j ];
                    path[ i ][ j ] = path[ k ][ j ];
                }
            }
        }
    }
}

char cities[ MAX ][ 35 ];
int numcities;
int get_Id( char *s ){
    int i;
    for( i = 0 ; i < numcities ; ++i ){
        if( strcmp( s , cities[ i ] ) == 0 ) return i;
    }
    strcpy( cities[ numcities ] ,s );
    return numcities++;
}

char *getString( int id ){
    int i;
    for( i = 0 ; i < numcities ; ++i ){
        if( id == i ) return cities[ i ];
    }
}

char s[ 35 ] , s1[ 35 ] , s2[ 35 ];
void print( int x , int y ){
    if( x == INF || y == INF ) return;
    if( y == x ) { printf("%s" , getString( x ) ); }
    else{
        print( x , path[ x ][ y ] );
        printf(" %s" , getString( y ) );
    }
    return;
}

int main(){
    int t , i , x , j , u , v;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &V );
        numcities = 0;
        for( i = 0 ; i < V && scanf("%s" , &s ) == 1 ; ++i ){ get_Id( s ); }

        for( i = 0 ; i < V ; ++i ){
            for( j = 0 ; j < V && scanf("%d" , &ady[ i ][ j ] ) == 1 ; ++j ){
                if( ady[ i ][ j ] == -1 ) ady[ i ][ j ] = INF;
            }
        }
        initPath();
        floyd();

        scanf("%d" , &x );
        while( x-- ){
            scanf("%s %s %s" , s , s1 , s2 );
            u = get_Id( s1 ); v = get_Id( s2 );
            if( ady[ u ][ v ] == INF ) printf("Sorry Mr %s you can not go from %s to %s\n" , s , s1 , s2 );
            else{
                printf("Mr %s to go from %s to %s, you will receive %d euros\n" , s , s1 , s2 , ady[ u ][ v ] );
                printf("Path:");
                if( u == v ) printf("%s %s" , s1 , s2 );
                else print( u , v );
                printf("\n");
            }
        }
    }

    return 0;
}
