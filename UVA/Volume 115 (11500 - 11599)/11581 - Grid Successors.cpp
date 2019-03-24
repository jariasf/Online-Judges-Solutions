/*****************************************
 ***Problema: Grid Successors
 ***ID: 11581
 ***Juez: UVA
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>


int ady[ 3 ][ 3 ] , ant[ 3 ][ 3 ];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };

int main(){

    int t , ans;
    char s[ 5 ];
    scanf("%d" , &t );
    while( t-- ){
        for( int i = 0 ; i < 3 ; ++i ){
            scanf("%s" , s );
            for( int j = 0 ; j < 3 ; ++j ){
                ady[ i ][ j ] = s[ j ] - '0';
            }
        }
        ans = -1;
        int ceros , sum;
        while( 1 ){

            for( int i = 0 ; i < 3 ; ++i )
                for( int j = 0 ; j < 3 ; ++j ){
                    ceros += ady[ i ][ j ];
                    ant[ i ][ j ] = ady[ i ][ j ];
                }
            if( ceros == 0 ){
                break;
            }
            ceros = 0;
            for( int i = 0 ; i < 3 ; ++i ){
                for( int j =  0 ; j < 3 ; ++j ){
                    sum = 0;
                    for( int k = 0 ; k < 4 ; ++k ){
                        int nx = i + dx[ k ] , ny = j + dy[ k ];
                        if( nx >= 0 && nx < 3 && ny >= 0 &&  ny < 3 ){
                            sum += ant[ nx ][ ny ];
                        }
                    }
                    ady[ i ][ j ] = ( sum % 2 );
                }
            }
            ans++;
        }
        printf("%d\n" , ans );
    }
    return 0;
}
