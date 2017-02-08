/*****************************************
 ***Problema: Dividing Coins
 ***ID: 562
 ***Juez: UVA
 ***Tipo: DP, Sumsets
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

int main(){
    int t, n;
    scanf("%d" , &t );
    int a[ 105 ], sum, dp[ 25005 ] , m;
    while( t-- ){
        sum = 0;
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &a[ i ] );
            sum += a[ i ];
        }
        m = sum/2;
        memset( dp , 0 , sizeof( dp ) );

        dp[ 0 ] = 1;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = m ; j >= a[ i ] ; --j ){
                 if( !dp[ j ] ){
                     dp[ j ] = dp[ j - a[ i ] ] ;
                 }
            }
        }
        ///basta encontrar el maximo valor para una mitad para saber
        ///el resto simplemente a la suma total le restamos el valor
        ///de la maxima mitad
        int i = m;
        for( ; i >= 1 ; --i ){
            if( dp[ i ] ){
                 break;
            }
        }
        printf("%d\n" , ( sum - i * 2 ) );

    }

    return 0;
}
