/*****************************************
 ***Problema: Frequent values
 ***ID: 11235
 ***Juez: UVA
 ***Tipo: Segment Tree Range Maximum Query
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

#define N 100001

int tree[N * 4]; //se necesita menos de N * 4 nodos para representar una lista de numeros de tamaño N, pero este numero es

int n; //numero de elementos en el input

void update( int pos , int by , int left = 0 , int right = n - 1, int node = 0 ){
    if( left == right ){
        tree[ node ] = by;
        return;
    }
    int mid = ( left + right )/2;
    if( pos > mid ){
        update( pos , by , mid + 1 , right , 2 * node + 2 );
    }
    else{
        update( pos , by , left , mid , 2 * node + 1 );
    }
    tree[ node ] = max( tree[ node ] , by );
}
//range maximum query
int rmq( int from , int to , int left = 0 , int right = n - 1, int node = 0 ){
    if( left >= from && right <= to ){
        return tree[ node ];
    }
    int mid = ( left + right )/2, res = 0;
    if( from <= mid ){
        res = max( res , rmq( from , to , left , mid , node * 2 + 1 ) );
    }
    if( to > mid ){
        res = max( res, rmq( from , to , mid + 1 , right , 2 * node + 2 ) );
    }
    return res;
}


int init(){
	for(int i = 0; i < 4 * n; i++) tree[ i ] = 0;
}

int main(){
    int Q , a[ N ], s[ N ], v[ N ] , x , y;
    while( scanf("%d" , &n ) , n ){
        scanf("%d" , &Q );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &a[ i ] );
            s[ i ] = 0;
        }
        int l = 0;

        a[ n ] = 1<<30;
        for( int i = 1 ; i <= n ; ++i ){
            if( a[ i ] != a[ i - 1 ] ) s[ l++ ]++;
            else s[ l ]++;
        }
        init();
        l = 0;
        v[ 0 ] = s[ 0 ];
        int ini = 0;
        vector< pair<int , int > > aux , interval;
        for( int i = 1; i <= n ; ++i ){
            if( a[ i ] != a[ i - 1 ] ){
                l++;
                aux.push_back( make_pair( ini , i - 1 ) );
                ini = i;
            }
            v[ i ] = s[ l ];
        }
        l = 0;
        interval.push_back( aux[ 0 ] );
        for( int i = 1; i <= n ; ++i ){
            if( a[ i ] != a[ i - 1 ] ){
                l++;
            }
            interval.push_back( aux[ l ]);
        }
        for( int i = 0 ; i < n ; ++i ){
            update( i , v[ i ] );
        }
        int ans = 0, left , right;
        while( Q-- ){
            scanf("%d %d" , &x , &y );
            x--; y--;
            if( x == y ){
                puts("1");
                continue;
            }
            ans = 0;
            if( a[ x ] == a[ y ] ){
                ans = y - x + 1;
            }
            else{
                int f = interval[ x ].first , s = interval[ x ].second;
                left = s + 1;
                ans = max( ans , s + 1 - x );
                f = interval[ y ].first , s = interval[ y ].second;
                right = f - 1;
                ans = max( ans , abs( f - 1 - y ) );
                if( left <= right ) ans = max( ans , rmq( left , right ) );
            }
            printf("%d\n" , ans );
        }
    }

    return 0;
}
