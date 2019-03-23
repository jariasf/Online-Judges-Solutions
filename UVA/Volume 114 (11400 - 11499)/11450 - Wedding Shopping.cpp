/*****************************************
 ***Problema: Wedding Shopping
 ***ID: 11450
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
#define MAX 25
//Top - Down
int k[ MAX ];
int g[ MAX ][ MAX ];
int dp[ 205 ][ MAX ];
int c , m;
int solve( int money , int G ){
    if( money < 0 ) return -1<<30;
    if( G == c ) return m - money;
    if( dp[ money ][ G ] != -1 ) return dp[ money ][ G ];
    int maxi = -1<<30;
    for( int i = 0 ; i < k[ G ] ; ++i )
    {
        maxi = max( maxi , solve( money - g[ G ][ i ] , G + 1 ) );
    }
    return dp[ money ][ G ] = maxi;
}

int main(){
    int t ,ans;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &m , &c );
        for( int i = 0 ; i < c ; ++i ){
            scanf("%d" , &k[ i ] );
            for( int j = 0 ; j < k[ i ] ; ++j ) scanf("%d" , &g[ i ][ j ] );
        }
        memset( dp , -1 , sizeof( dp ) );
        ans = solve( m , 0 );
        if( ans < 0 ) puts("no solution");
        else printf("%d\n" , ans );
    }

    return 0;
}
