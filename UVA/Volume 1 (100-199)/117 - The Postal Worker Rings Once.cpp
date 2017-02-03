/*****************************************
 ***Problema: The Postal Worker Rings Once
 ***ID: 117
 ***Juez: UVA
 ***Tipo: Chinese Postman Problem - Euler Tour
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
#define MAXV 27
#define INF 1<<30

struct Edge{
    int v , w;
    int id;
    Edge( int vv , int ww ): v( vv  ) , w(ww){}
    Edge( int vv , int ww , int i ): v( vv  ) , w(ww) , id( i ){}
    Edge(){}
};

char s[ MAX ];
int degree[ MAXV ];
vector< Edge > ady[ MAXV ];
int dist[ MAX ] , prev[ MAX ], seen[ MAX ];

void spfa( int source ){
    int u , v , w , i;
    for( i = 0 ; i < MAXV ; ++i ){
        seen[ i ] = 0;
        dist[ i ] = INF;
    }
    queue< int > Q;
    dist[ source ] = 0;
    Q.push( source );
    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        seen[ u ] = 0;
        for( i = 0 ; i < ady[ u ].size() ; ++i ){
            v = ady[ u ][ i ].v;
            w = ady[ u ][ i ].w;
            if( dist[ v ] > dist[ u ] + w ){
                dist[ v ] = dist[ u ] + w;
                prev[ v ] = u;
                if( !seen[ v ] ){
                    seen[ v ] = 1;
                    Q.push( v );
                }
            }
        }
    }
}

int main(){
    long long ans;
    int len , source , sink , i;
    while( scanf("%s" , &s ) == 1 ){
        ans = 0;
        len = strlen( s );
        if( s[ 0 ] == s[ len - 1 ] ) continue;
        memset( degree , 0 , sizeof( degree ) ) ;
        ady[ s[ 0 ] - 'a' ].push_back( Edge( s[ len - 1 ] - 'a' , len ) );
        ady[ s[ len - 1 ] - 'a' ].push_back( Edge( s[ 0 ] - 'a' , len ) );
        degree[ s[ 0 ] - 'a' ]++;
        degree[ s[ len - 1 ] - 'a' ]++;
        ans += len;

        while( scanf("%s" , &s ) == 1 ){
            len = strlen( s );
            if( s[ 0 ] == s[ len - 1 ] ) break;
            ady[ s[ 0 ] - 'a' ].push_back( Edge( s[ len - 1 ] - 'a' , len ) );
            ady[ s[ len - 1 ] - 'a' ].push_back( Edge( s[ 0 ] - 'a' , len ) );
            degree[ s[ 0 ] - 'a' ]++;
            degree[ s[ len - 1 ] - 'a' ]++;
            ans += len;
        }

        source = sink = -1;
        for( i = 0 ; i < MAXV ; ++i ){
            if( degree[ i ] & 1 ){
                if( source == -1 ) source = i;
                else sink = i;
            }
        }
        spfa( source );
        ans += dist[ sink ];
        printf("%lld\n" , ans );
        for( i = 0 ; i < MAXV ; ++i ) ady[ i ].clear();
    }

    return 0;
}
