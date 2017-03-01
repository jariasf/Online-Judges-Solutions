/*****************************************
 ***Problema: Liftless EME
 ***ID: 10350
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
#define MAX 2005
char s[ 15 ];
int m , n;
int getId( int x , int y ){ return x * m + y; }
struct Edge{
    int v , w;
    Edge( int vv , int ww ): v( vv ) , w( ww ){}
};
vector< Edge > ady[ MAX ];
int dist[ MAX ];
#define INF 1<<30
int bfs(){
    queue< int > Q;
    int i , u , v , w;
    for( i = 0 ; i < m * n ; ++i ) dist[ i ] = INF;
    for( i = 0 ; i < m ; ++i ){
        Q.push( i );
        dist[ i ] = 0;
    }


    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        for( i = 0 ; i < ady[ u ].size() ; ++i ){
            v = ady[ u ][ i ].v;
            w = ady[ u ][ i ].w;
            if( dist[ v ] > dist[ u ] + w ){
                dist[ v ] = dist[ u ] + w;
                Q.push( v );
            }
        }
    }
    int ans = INF;
    for( i = 0 ; i < m ; ++i ){
        ans = min( ans , dist[ getId( n - 1 , i ) ] );
    }
    return ans;
}

int main(){
    int ans  , i , t , hole , j , k;
    while( scanf("%s" , &s ) != EOF ){
        scanf("%d %d" , &n , &m );
        ans = 2 * ( n - 1 );
        for( i = 0 ; i < n - 1 ; ++i ){
            for( j = 0 ; j < m ; ++j , ++hole ){
                for( k = 0 ; k < m && scanf("%d" , &t ) ; ++k ){
                    ady[ getId( i , j ) ].push_back( Edge( getId( i + 1 , k ) , t ) );
                }
            }
        }
        printf("%s\n%d\n" , s , ans + bfs() );
        for( i = 0 ; i < n * m ; ++i ) ady[ i ].clear();
    }

    return 0;
}
