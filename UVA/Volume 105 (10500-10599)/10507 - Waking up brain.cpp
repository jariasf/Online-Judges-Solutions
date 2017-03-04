/*****************************************
 ***Problema: Waking up brain
 ***ID: 10507
 ***Juez: UVA
 ***Tipo: Ad hoc
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
int num;
char mp[ 30 ];
int getId( char c ){
    for( int i = 0 ; i < num ; ++i ){
        if( c == mp[ i ] )return i;
    }
    mp[ num ] = c;
    return num++;
}
vector<int> ady[ 30 ];

int main(){
    char line[ 256 ];
    int n , m , x , y, ans, cnt;
    char c1 , c2;
    bool seen[ 30 ];
    vector<int> greedy[ 5 ];
    while( scanf("%d" , &n ) == 1 ){
        for( int i = 0 ; i < 30 ; ++i ) ady[ i ].clear();
        scanf("%d %s" , &m , &line );

        num = 0;
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 0 ; line[ i ] ; ++i ){
            seen[ getId( line[ i ] ) ] = 1;
        }
        if( m == 0 ){
            if( num != n ){
                puts("THIS BRAIN NEVER WAKES UP");
                continue;
            }
            else{
                puts("WAKE UP IN, 0, YEARS");
                continue;
            }

        }
        while( m-- ){
            scanf("%s" , line );
            x = getId( line[ 0 ] ); y = getId( line[ 1 ] );
            ady[ x ].push_back( y );
            ady[ y ].push_back( x );
        }

        for( int i = 0 ; i < num ; ++i ){
            if( seen[ i ] )continue;
            cnt = 0;
            for( int j = 0 ; j < ady[ i ].size() ; ++j ){
                if( seen[ ady[ i ][ j ] ] ) cnt++;
            }
            if( cnt > 3 ) cnt = 3;
            greedy[ cnt ].push_back( i );
        }

        ans = 0;
        if( greedy[ 3 ].size() == 0 || num != n){
            puts("THIS BRAIN NEVER WAKES UP");
            continue;
        }
        for( int i = 3 ; ;){
            if( greedy[ i ].size() == 0 )break;
            for( int j = 0 ; j < greedy[ i ].size() ; ++j ){
                seen[ greedy[ i ][ j ] ] = 1;
            }
            ans++;
            for( int j = 0 ; j < 4 ; ++j ) greedy[ j ].clear();
            for( int k = 0 ; k < num ; ++k ){
                if( seen[ k ] )continue;
                cnt = 0;
                for( int j = 0 ; j < ady[ k ].size() ; ++j ){
                    if( seen[ ady[ k ][ j ] ] ) cnt++;
                }
                if( cnt > 3 ) cnt = 3;
                greedy[ cnt ].push_back( k );
            }
        }
        int i = 0;
        for( ; i < num ; ++i )if( !seen[ i ] )break;
        if( i == num )printf("WAKE UP IN, %d, YEARS\n" , ans );
        else puts("THIS BRAIN NEVER WAKES UP");
    }

    return 0;
}
