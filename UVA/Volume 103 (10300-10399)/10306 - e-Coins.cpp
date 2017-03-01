/*****************************************
 ***Problema: e-Coins
 ***ID: 10306
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
#define MAX 45
#define MAXN 305
pair< int , int > a[ MAX ];
int dp[ MAXN ][ MAXN ];

int main(){
    int t , m ,s , x , y;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &m , &s );
        for( int i = 0 ; i < m ; ++i ){
            scanf("%d %d" , &x , &y );
            a[ i ] = make_pair( x, y );
        }
        sort( a , a + m );
        for( int i = 0 ; i <= s ; ++i )
            for( int j = 0 ; j <= s ; ++j ) dp[ i ][ j ] = 1<<20;
        dp[ 0 ][ 0 ] = 0;
        for( int i = 0 ; i < m ; ++i )
        {
            for( int j = a[ i ].first ; j <= s ; ++j ){
                for( int k = a[ i ].second ; k <= s ; ++k ){
                    dp[ j ][ k ] = min(dp[ j - a[ i ].first ][ k - a[ i ].second ] + 1, dp[ j ][ k ]);
                }
            }
        }
        int ans = 1<<20;
        for( int i = 0 ; i <= s ; ++i ){
            for( int j = 0 ; j <= s ; ++j ){
                if( i * i + j * j == s * s ){
                    ans = min( ans , dp[ i ][ j ] );
                }
            }
        }
        if( ans == 1<<20 ) puts("not possible");
        else printf("%d\n" , ans );
    }
    return 0;
}
