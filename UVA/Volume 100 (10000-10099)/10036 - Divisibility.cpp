/*****************************************
 ***Problema: Divisibility
 ***ID: 100036
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

#define MAX 10005
int dp[ MAX ][ 105 ][ 2 ] , a[ MAX ]; //posicion , suma % k , signo
int k, n;

int solve( int pos , int sum ){
    if( pos == n ){
        if( sum ) return 0;
        else return 1;
    }
    if( sum < 0 ){ if( dp[ pos ][ sum ][ 0 ] != -1 ) return dp[ pos ][ sum ][ 0 ];}
    else{
        if( dp[ pos ][ sum ][ 1 ] != -1 ) { return dp[ pos ][ sum ][ 1 ]; }
    }
    int ans = ( solve( pos + 1 , ( sum % k + a[ pos ] % k ) % k ) | solve( pos + 1 , ( sum % k - a[ pos ] % k ) ) % k );
    if( sum < 0 ) return dp[ pos ][ sum ][ 0 ] = ans;
    return dp[ pos ][ sum ][ 1 ] = ans;
}

int main(){
    int t;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &n , &k );
        memset( dp , -1 , sizeof( dp ) );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &a[ i ] );
            a[ i ] %= k;
        }
        if( solve( 1 , a[ 0 ] % k ) > 0 ) puts("Divisible");
        else puts("Not divisible");
    }
    return 0;
}

/*

7
4 7
17 5 -21 15
4 5
17 5 -21 15
10 30
9 -97 3 5 -1 0 11 -46 19 17
10 97
9 -97 3 5 -1 0 11 -46 19 17
12 16
-11 7 -73 40 5 -2 66 21 -64 16 16 16
5 15
-1 -2 -3 -4 -5
5 9
-5 -4 2 -2 0
*/
