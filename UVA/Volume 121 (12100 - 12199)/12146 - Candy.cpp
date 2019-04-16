/*****************************************
 ***Problema: Candy
 ***ID: 12146
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
#define MAX 100005
int h , w , dp[ MAX ][ 2 ] , a[ MAX ];

int main(){

    int i , j;
    while( scanf("%d %d" , &h , &w ) , w | h ){
        int ady[ h + 2 ][ w + 2 ];
        for( int i = 1 ;i <= h ; ++i )
            for( int j = 1 ; j <= w && scanf("%d" , &ady[ i ][ j ] ) ; ++j );

        for( int i = 1 ; i <= h ; ++i ){
                dp[ j ][ 0 ] = dp[ j ][ 1 ] = 0;
            for( int j = 1 ; j <= w ; ++j ){
                dp[ j ][ 0 ] = max( dp[ j - 1 ][ 1 ] , dp[ j - 1 ][ 0 ] );
                dp[ j ][ 1 ] = dp[ j - 1 ][ 0 ] + ady[ i ][ j ];
            }
            a[ i ] = max( dp[ w ][ 0 ] , dp[ w ][ 1 ] );
        }

        dp[ j ][ 0 ] = dp[ j ][ 1 ] = 0;
        for( int j = 1 ; j <= h ; ++j ){
            dp[ j ][ 0 ] = max( dp[ j - 1 ][ 1 ] , dp[ j - 1 ][ 0 ] );
            dp[ j ][ 1 ] = dp[ j - 1 ][ 0 ] + a[ j ];
        }
        printf("%d\n" , max( dp[ h ][ 0 ] , dp[ h ][ 1 ] ) );
    }

    return 0;
}
