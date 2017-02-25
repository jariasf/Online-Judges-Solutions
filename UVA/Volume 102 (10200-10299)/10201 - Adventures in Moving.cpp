/*****************************************
 ***Problema: Adventures in Moving
 ***ID: 10201
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
#define MAX 105
#define MAXD 10005
#define INF 1<<30
int _end , n , dist[ MAX ] , cost[ MAX ];
long long dp[ MAX ][ 205 ];
long long solve( int cur , int gas ){
    if( gas < 0  ) return INF;

    if( dist[ cur ] == _end ){
        if( dist[ cur ] + gas - _end >= 100 ) return 0;
        return INF;
    }
    int i;

    if( dp[ cur ][ gas ] != -1 ) return dp[ cur ][ gas ];
    long long ans = INF , costo;
    int j, novoGas , k;
    for( i = cur + 1 ; i < n ; ++i ){
        //si es posible llegar
        novoGas = dist[ i ] - dist[ cur ] - gas;
        for( j = gas , k = 0 ; j <= 200 ; ++j , ++k ){
            costo = k * cost[ cur ];
            if( j + dist[ cur ] >= dist[ i ] )
                ans = min( ans , costo + solve( i , j - ( dist[ i ] - dist[ cur ] ) ) );
        }
    }
    return dp[ cur ][ gas ] = ans;
}

char line[ 105 ];
int main(){
    int t , mini , i , q;
    scanf("%d" , &t );
    long long ans;
    bool correct;
    for( q = 0 ; q < t ; ++q ){
        if( q ) printf("\n");
        while( gets( line ) != NULL && sscanf( line , "%d", &_end ) != 1);
        n = 0;
        correct = false;
        mini = 1<<30;
        while( gets( line ) ){
            if( strlen( line ) == 0 ) break;
            sscanf( line , "%d %d" , &dist[ n ] , &cost[ n ] );
            if( dist[ n ] > _end ){
                dist[ n + 1 ] = _end;
                cost[ n + 1 ] = INF;
                swap( dist[ n ] , dist[ n + 1 ] );
                swap( cost[ n ] , cost[ n + 1 ] );
                n++;
            }
            n++;
        }
        if( dist[ n - 1 ] <= _end ){
            dist[ n ] = _end;
            cost[ n++ ] = INF;
        }
        
		memset( dp , -1 , sizeof( dp ) );
        ans = INF;
        for( i = 0 ; i < n - 1 ; ++i )
            if( dist[ i ] <= 100 ) ans = min( ans , solve( i , 100 - dist[ i ] ) );

        if( ans == INF )puts("Impossible");
        else printf("%lld\n" , ans );
    }

    return 0;
}
