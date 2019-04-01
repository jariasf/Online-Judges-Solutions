/*****************************************
 ***Problema: Switch Bulbs
 ***ID: 12135
 ***Juez: UVA
 ***Tipo: BFS
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
#define MAXS 45
#define MAX 1<<16
#define INF 1<<30
int dist[ MAX ];
bool seen[ MAX ];
vector< int > sw[ MAXS ];
int n , m;

void bfs(){
    int i , j , y , act , aux;
    for( i = 0 ; i < 1<<n ; ++i ){
        dist[ i ] = INF;
        seen[ i ] = 0;
    }

    queue< int > Q;
    Q.push( 0 );
    seen[ 0 ] = 1;
    dist[ 0 ] = 0;
    while( !Q.empty() ){
        act = Q.front(); Q.pop();
        for( i = 0 ; i < m ; ++i ){
            aux = act;
            for( j = 0 ; j < sw[ i ].size() ; ++j ){
                y = sw[ i ][ j ];
                aux ^= 1<<y;
            }
            if( !seen[ aux ] && dist[ act ] + 1 < dist[ aux ] ){
                dist[ aux ] = dist[ act ] + 1;
                seen[ aux  ] = 1;
                Q.push( aux );
            }
        }
    }
}
char s[ 18 ];
int main(){

    int t , q , i , k , u , num , Q ;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d"  ,&n , &m ) == 2 ; ++q ){

        for( i = 0 ; i < m && scanf("%d" , &k ) == 1 ; ++i ){
            while( k-- ){
                scanf("%d" , &u );
                sw[ i ].push_back( u );
            }
        }
        printf("Case %d:\n" , q );

        bfs();
        scanf("%d" , &Q );
        while( Q-- ){
            scanf("%s" , &s );
            num = 0;
            for( i = 0 ; s[ i ] ; ++i ){
                if( s[ i ] == '1' ) num |= 1<<( n - i - 1 );
            }
            if( dist[ num ] == INF )puts("-1");
            else printf("%d\n" , dist[ num ] );

        }
        printf("\n");

        for( i = 0 ; i <= m ; ++i ) sw[ i ].clear();
    }

    return 0;
}
