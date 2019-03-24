/*****************************************
 ***Problema: Demanding Dilemma
 ***ID: 11550
 ***Juez: UVA
 ***Tipo: Graph Theory, incident matrix
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){

    int t , n , m, x;
    int ady[ 10 ][ 30 ], node[ 10 ][ 30 ];
    int edges[ 30 ];
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &n , &m );
        memset( edges , 0 , sizeof( edges ) );

        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
                scanf("%d" , &ady[ i ][ j ] );
                if( ady[ i ][ j ] ) edges[ j ]++;
            }
        }
        int i = 0;
        for( ; i < m ; ++i ) { if( edges[ i ] != 2 )break; }
        if( i != m )puts( "No");
        else{
            memset( node , 0 , sizeof( node ));
            int j = 0;
            for( ; j < m ; ++j ){
                int i = 0;
                int val[ 2 ], len = 0;
                for(  ; i < n ; ++i ){
                    if( ady[ i ][ j ] ){
                        val[ len++ ] = i;
                    }
                }
                if( node[ val[ 0 ] ][ val[ 1 ] ] ) break;
                node[ val[ 0 ] ][ val[ 1 ] ] = 1;
            }
            if( j == m )puts("Yes");
            else puts("No");
        }

    }

    return 0;
}
