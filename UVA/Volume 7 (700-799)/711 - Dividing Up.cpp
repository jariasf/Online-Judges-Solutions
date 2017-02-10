/*****************************************
 ***Problema: Dividing
 ***ID: 711
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
bool dp[120000/2+1];
int main(){
    int a[ 7 ], sum , q = 1 ,  j;
    while( 1 ){
        scanf("%d %d %d %d %d %d", &a[ 1 ] , &a[ 2 ], &a[ 3 ] , &a[ 4 ], &a[ 5 ] , &a[ 6 ] );
        sum = 0;
        memset( dp , 0 , sizeof( dp ) );
        for( int i = 1 ; i < 7 ; ++i ) sum += ( a[ i ] * i );
        if( sum == 0 )break;
        printf("Collection #%d:\n" , q++ );
        if( sum & 1 ) printf("Can't be divided.\n\n");
        else{
            sum /= 2;

            for( int i = 0 ; i < 7 ; ++i ){
                dp[ i ] = 0;
            }
            dp[ 0 ] = 1;

            for( int k = 1 ; k < 7 ; ++k ){

                for( j = 1 ; j * 2 - 1 <= a[ k ] ; j <<=1 )
                    for( int i = sum ; i >= j * k ; --i ) dp[ i ] |= dp[ i - j * k ];

                j = a[ k ] - ( j - 1 );
                if( j > 0 ){
                    for( int i = sum ; i >= j * k ; --i ){
                        dp[ i ] |= dp[ i - j * k ];
                    }
                }
            }

            if( dp[ sum ] == 1 ) printf("Can be divided.\n\n");
            else printf("Can't be divided.\n\n");
        }

    }

    return 0;
}
