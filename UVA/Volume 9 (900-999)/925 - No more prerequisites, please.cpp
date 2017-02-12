/********************************************
 ***Problema: No more prerequisites, please!
 ***ID: 925
 ***Juez: UVA
 ***Tipo: Graph Theory, Transitive Closure
 ***Autor: Jhosimar George Arias Figueroa
 ********************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>

#define MAX 130
int ady[ MAX ][ MAX ] , V;
char cities[ MAX ][ 30 ];

int get_Id( char *s ){

    for( int i = 0 ; i < V ; ++i ){
         if( strcmp( cities[ i ] , s ) == 0 )return i;
    }
}

void Init(){
    for( int i = 0 ; i < MAX ; ++i ){
        for( int j = 0 ; j < MAX ; ++j ){
             ady[ i ][ j ] =  0;
        }
    }
}

void TransitiveClosure(){

    for( int k = 0 ; k < MAX ; ++k ){
        for( int i = 0 ; i < MAX ; ++i ){
            for( int j = 0 ; j < MAX ; ++j ){
                 ady[ i ][ j ] |= ady[ i ][ k ] & ady[ k ][ j ];
            }
        }
    }
}

int f( const void * v1 , const  void *v2){
    return strcmp( ( char *)v1 , (char *)v2 );
}

int main(){
    int t , E , k, uu ,vv;
    char u[ 30 ] , v[ 30 ];
    scanf("%d" ,&t );
    while( t-- ){

        scanf("%d" , &V );

        for( int i = 0 ; i < V ; ++i ){
            scanf("%s" , &cities[ i ] );
        }

        qsort( cities , V , sizeof( cities[ 0 ] ) , f );
        Init();
        scanf("%d" , &E );
        while( E-- ){
            scanf("%s %d" , &u , &k );
            uu = get_Id( u );
            while( k-- ){
                scanf("%s" ,&v );
                vv = get_Id( v );
                ady[ vv ][ uu ] = 1;
            }
        }

        TransitiveClosure();

        int possible[ MAX ], idx, cont;
        bool print[ MAX ];
        for( int i = 0 ; i < V ; ++i ){
             idx = 0;

             for( int j = 0 ; j < V ; ++j ){

                ///posibles prerequisitos
                if( ady[ j ][ i ] == 1 ){
                    print[ idx ] = 1;
                    possible[ idx++ ] = j;
                }
             }

             for( int j = 0 ; j < idx ; ++j ){
                for( int k = 0 ; k < idx ; ++k ){
                     if( ady[ possible[ j ] ][ possible[ k ] ] )print[ j ] = 0;
                }
             }


             if( idx != 0 ){
                 cont  = 0;
                 for( int j = 0 ; j < idx ; ++j )if( print[ j ] )cont++;
                 printf("%s %d" , cities[ i ] , cont );
                 for( int j = 0 ; j < idx ; ++j ){
                     if( !print[ j ] )continue;
                     printf(" %s" , cities[ possible[ j ] ] );
                 }
                 printf("\n");
             }
        }

    }

    return 0;
}
