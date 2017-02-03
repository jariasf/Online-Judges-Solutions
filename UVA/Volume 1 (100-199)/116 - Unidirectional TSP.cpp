/*****************************************
 ***Problema: Unidirectional TSP
 ***ID: 116
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int a[ 21 ][ 105 ], dp[ 21 ][ 105 ];

struct Estado{
    int x, y;
    Estado( int xx , int yy ):x( xx ) , y( yy ){}
    Estado(){}
}prev[ 21 ][ 105 ];

int main(){
    int h , w, idx_d , idx_u;
    while( scanf("%d %d" , &h,  &w ) == 2 ){

        for( int i = 1 ; i <= h ; ++i ){
            for( int j = 1 ; j <= w ; ++j ){
                scanf( "%d" , &a[ i ][ j ] );
                dp[ i ][ j ] = 1<<30;
            }
        }

        for( int k = 0 ; k <= h ; ++k ) {
            dp[ k ][ w ] = a[ k ][ w ];
            prev[ k ][ 0 ] = Estado( -1 , - 1 );
        }

        for( int j = w - 1 ; j >= 1; --j ){
            for( int i = 1 ; i <= h ; ++i ){
                idx_d = i + 1;
                if( i == h ){
                    idx_d = 1;
                }
                idx_u = i - 1;
                if( i == 1 ){
                    idx_u = h;
                }

                dp[ i ][ j ] = dp[ idx_d ][ j + 1 ] + a[ i ][ j ];
                prev[ i ][ j ] = Estado( idx_d , j + 1 );

                if( dp[ i ][ j ] > dp[ i ][ j + 1 ] + a[ i ][ j ] ){
                    dp[ i ][ j ] = dp[ i ][ j + 1 ] + a[ i ][ j ];
                    prev[ i ][ j ] = Estado( i , j + 1 );
                }
                else if( dp[ i ][ j ] == dp[ i ][ j + 1 ] + a[ i ][ j ] ){
                    if( prev[ i ][ j ].x > i )
                        prev[ i ][ j ] = Estado( i , j + 1 );
                }

                if( dp[ i ][ j ] > dp[ idx_u ][ j + 1 ] + a[ i ][ j ] ){
                    dp[ i ][ j ] = dp[ idx_u ][ j + 1 ] + a[ i ][ j ];
                    prev[ i ][ j ] = Estado( idx_u , j + 1 );
                }
                else if( dp[ i ][ j ] == dp[ idx_u ][ j + 1 ] + a[ i ][ j ] ){
                    if( prev[ i ][ j ].x > idx_u )
                        prev[ i ][ j ] = Estado( idx_u , j + 1 );
                }
            }
        }


        int min = 1<<30, x = 0 ;
        for( int i = 1 ; i <= h ; ++i ){
            if( min > dp[ i ][ 1 ] ){
                x = i;
                min = dp[ i ][ 1 ];
            }
        }

        int resp[ 105 ], len = 0;

        for( int i = 0 ; i < w ; ++i ){
            resp[ i ] = x;
            x = prev[ x ][ i + 1 ].x;
        }

        printf("%d" , resp[ 0 ] );
        for( int i = 1 ; i < w ; ++i ) printf(" %d" , resp[ i ] );
        printf("\n%d\n" , min );

    }

    return 0;
}
