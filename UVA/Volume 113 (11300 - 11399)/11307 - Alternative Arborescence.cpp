/*****************************************
 ***Problema: Alternative Arborescence
 ***ID: 11307
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
#define INF 1<<30
int V, degree[ MAX ] , outdegree[ MAX ];
char line[ 1000005 ];
vector< int > ady[ MAX ];

int dp[ MAX ][ 10 ];

int solve( int cur , int color ){

    if( outdegree[ cur ] == 0 ) return 0;
    if( dp[ cur ][ color ] != -1 ) return dp[ cur ][ color ];
    int ans = 0 , mini , i , v , y;

    for( v = 0 ; v < ady[ cur ].size() ; ++v ){
        y = ady[ cur ][ v ];
        mini = INF;
        for( i = 1 ; i <= 7 ; ++i ){
            if( i == color ) continue;
            mini = min( mini , i + solve( y , i ) );
        }
        ans += mini;
    }
    return dp[ cur ][ color ] = ans;
}

int main(){
    int i , u , v ,j , ans;
    string s;
    while( scanf("%d" , &V ) , V ){
        getchar();
        memset( degree , 0 , sizeof( degree ) );
        memset( outdegree , 0 , sizeof( outdegree ) );
        for( i = 0 ; i < V && gets( line ) ; ++i ){
            stringstream ss( line );
            ss>>line;
            sscanf( line , "%d:" , &u );
            while( ss>>v ){
                ady[ u ].push_back( v );
                degree[ v ]++;
                outdegree[ u ]++;
            }
        }

        for( i = 0 ; i < V ; ++i )
            if( !degree[ i ] ) break;

        ans = INF;
        memset( dp , -1 , sizeof( dp ) );

        for( j = 1 ; j <= 7 ; ++j )
            ans = min( ans , j + solve( i , j ) );

        printf("%d\n" , ans );
        for( i = 0 ; i < V ; ++i ) ady[ i ].clear();
    }

    return 0;
}
