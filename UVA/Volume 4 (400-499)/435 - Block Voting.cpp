/*****************************************
 ***Problema: Block Voting
 ***ID: 435
 ***Juez: UVA
 ***Tipo: Brute force
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

    int t , n, a[ 25 ], mid , sum, ans[ 25 ];
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        sum = 0;
        for( int i = 0 ; i < n ; ++i ){ scanf("%d" , &a[ i ] ); sum += a[ i ]; }
        mid = sum/2;

        memset( ans , 0 , sizeof( ans ) );
        for( int i = 1 ; i < 1<<n ; ++i ){
            sum = 0;
            for( int j = 0 ; j < n ; ++j ){
                if( ( 1<<j ) & i ){
                    sum += a[ j ];
                }
            }
            if( sum > mid ){
                for( int j = 0 ; j < n ; ++j ){
                    if( ( 1<<j ) & i ){
                        if( sum - a[ j ] <= mid ) ans[ j ]++;
                    }
                }
            }
        }
        for( int i = 0 ; i < n ; ++i ){
            printf("party %d has power index %d\n" , i + 1 , ans[ i ] );
        }
        printf("\n");
    }

    return 0;
}
