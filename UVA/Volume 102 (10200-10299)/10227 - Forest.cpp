/*****************************************
 ***Problema: Forest
 ***ID: 10227
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
#define MAX 105
vector<int> ady[ MAX ];

int main(){

    int t , p , q, x , y, ans;
    scanf("%d" , &q );
    char line[256];
    bool visit[ MAX ][ MAX ];
    int aux[ MAX ], cnt[ MAX ], seen[ MAX ];
    for( int qq = 0 ; qq < q ; ++qq ){
        if( qq )printf("\n");
        scanf("%d %d" , &p , &t );
        memset( visit , 0 , sizeof( visit ) );
        gets( line );
        while( gets( line ) ){
            int l = strlen( line );
            if( l == 0 )break;
            sscanf( line , "%d %d" , &x , &y );
            if( !visit[ x ][ y ] )ady[ x ].push_back( y );
            visit[ x ][ y ] = 1;
        }
        ans = 0;
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 1 ; i <= p ; ++i ){
            if( seen[ i ] != 0 || ady[ i ].size() == 0 ) continue;
            memset( cnt , 0 , sizeof( cnt ) );
            for( int j = 0 ; j < ady[ i ].size() ; ++j ) cnt[ ady[ i ][ j ] ]++;
            seen[ i ] = i;
            for( int j = i + 1 ; j <= p ; ++j ){
                if( seen[ j ] != 0 || ady[ j].size() == 0 ) continue;
                memset( aux , 0 , sizeof( aux ) );
                for( int k = 0 ; k < ady[ j ].size() ; ++k ) aux[ ady[ j ][ k ] ]++;
                int k = 0;
                for( ; k < MAX ; ++k ){
                    if( cnt[ k ] != aux[ k ] ){
                        break;
                    }
                }
                if( k == MAX ){
                    seen[ j ] = i;
                }
            }
        }
        set<int> s;
        for( int i = 1 ; i <= p ; ++i ){
            s.insert( seen[ i ] );
        }
        printf("%d\n" , s.size() );
        for( int i = 0 ; i < MAX ; ++i ) ady[ i ].clear();
    }
    return 0;
}

