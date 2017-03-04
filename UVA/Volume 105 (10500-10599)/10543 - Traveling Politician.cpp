/*****************************************
 ***Problema: Traveling Politician
 ***ID: 10543
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
#define MAX 55
#define INF 1<<30
int V, k;
vector< int > ady[ MAX ];
int dp[ MAX ][ 25 ];
int solve( int city , int speech  ){
    if( speech > 20 ) return INF;
    if( city == V - 1 ){
        if( speech >= k ) return 0;
    }
    if( dp[ city ][ speech ] != -1 ) return dp[ city ][ speech ];
    int ans = INF , i , y;
    for( i = 0 ; i < ady[ city ].size() ; ++i ){
        y = ady[ city ][ i ];
        ans = min( ans , 1 + solve( y , speech + 1 ) );
    }
    return dp[ city ][ speech ] = ans;
}

int main(){
    int E , u , v , i , ans;
    while( scanf("%d %d %d" , &V , &E , &k ) , V | E | k ){
        while( E-- ){
            scanf("%d %d" , &u , &v );
            if( u != v ) ady[ u ].push_back( v );
        }
        memset( dp , -1 , sizeof( dp ) );
        ans = solve( 0 , 1  ) + 1;
        if( ans > 20 || ans < k ) puts("LOSER");
        else printf("%d\n" , ans );
        for( i = 0 ; i < V ; ++i ) ady[ i ].clear();
    }

    return 0;
}
