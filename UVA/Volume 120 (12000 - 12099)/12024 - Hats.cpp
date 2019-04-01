/*****************************************
 ***Problema: Hats
 ***ID: 12024
 ***Juez: UVA
 ***Tipo: Dynamic Programming
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 13
int fact[ MAX ] , n , dp[ MAX ][ 1<<MAX ];
int solve( int act , int mask ){
    if( act == n ) return 1;
    if( dp[ act ][ mask ] != -1 ) return dp[ act ][ mask ];
    int i , ans = 0;
    for( i = 0 ; i < n ; ++i ){
        if( !( mask & 1<<i ) && i != act ){
            ans += solve( act + 1 , mask | 1<<i );
        }
    }
    return dp[ act ][ mask ] = ans;
}

int main(){
    int i , t;
    fact[ 0 ] = 1;
    for( i = 1 ; i < MAX ; ++i ) fact[ i ] = i * fact[ i - 1 ];
    scanf("%d" , &t );

    while( t-- > 0 && scanf("%d" , &n ) ){
        memset( dp , -1 , sizeof( dp ) );
        printf("%d/%d\n" , solve( 0 , 0 ) , fact[ n ] );
    }

    return 0;
}
