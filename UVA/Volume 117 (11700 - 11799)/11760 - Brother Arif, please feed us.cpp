/*****************************************
 ***Problema: Brother Arif, please feed us
 ***ID: 11760
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 10005
int dx[ ] = { 0 , 0 , 1 , -1 , 0 };
int dy[ ] = {1 , -1 , 0 , 0 , 0};
int h , w , p;
int main(){
    int x , y , q = 1;
    int persons[ 2005 ][ 2 ];
    while( scanf("%d %d %d" , &h , &w , &p ) , h | w | p ){

        for( int i = 0 ; i < p ; ++i ){
            scanf("%d %d" , &persons[ i ][ 0 ] , &persons[ i ][ 1 ] );
        }
        bool seen[ 5 ] = { 0 };
        scanf("%d %d" , &x , &y );
        bool b = false;
        for( int i = 0 ; i < p ; ++i ){
            int cnt = 1;
            for( int j = 0 ; j < 5 ; ++j ){
                int nx = x + dx[ j ], ny = y + dy[ j ];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w ){

                    if( persons[ i ][ 0 ] == nx || persons[ i ][ 1 ] == ny ){
                        seen[ j ] = 1;
                    }
                    if( !seen[ j ] ) cnt = 0;
                }
            }

            if( cnt == 1 ) break;
        }
        for( int j = 0 ; j < 5 ; ++j ){
            int nx = x + dx[ j ], ny = y + dy[ j ];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w ){
                if( !seen[ j ] ){ b = true; break;}
            }
        }
        printf("Case %d: " , q++ );
        if( b ) puts("Escaped again! More 2D grid problems!");
        else puts("Party time! Let's find a restaurant!");

    }

    return 0;
}
