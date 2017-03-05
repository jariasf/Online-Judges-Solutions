/*****************************************
 ***Problema: Luggage
 ***ID: 10664
 ***Juez: UVA
 ***Tipo: DP + bitmasks || just DP
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
#define MAXN 105
char s[ MAXN ];
int a[ MAX ], n, val;
int dp[ ( 1<<20 ) + 10 ];
bool solve( int sum , int mask , int len ){
    if( len >= n || sum > val ) return false;
    if( sum == val ){
        return true;
    }
    if( dp[ mask ] != -1 ) return dp[ mask ];
    bool b = false;
    for( int i = 0 ; i < n ; ++i ){
        if( !( mask & 1<<i ) ){
            b |= solve( sum + a[ i ] , mask | 1<<i , len + 1 );
        }
    }
    return dp[ mask ] = b;
}

int main(){
    int t , suma;
    scanf("%d" , &t );
    getchar();
    while( t-- ){
        gets( s );
        stringstream ss( s );
        n = 0;
        suma = 0;
        while( ss>>a[ n ] ){
            suma += a[ n ];
            n++;
        }
        val = suma/2;
        memset( dp , -1 , sizeof( dp ) );
        if( !( suma & 1 ) && solve( a[ 0 ] , 1 , 1 ) ) puts("YES");
        else puts("NO");
    }

    return 0;
}
