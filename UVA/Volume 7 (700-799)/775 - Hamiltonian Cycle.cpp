/*****************************************
 ***Problema: Hamiltonian Cycle
 ***ID: 775
 ***Juez: ICPC - Ores Theorem
 ***Tipo: DFS
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
//http://en.wikipedia.org/wiki/Ore%27s_theorem
#define MAX 300
int V;
char s[ MAX ];
vector< int > ady[ MAX ];
int seen[ MAX ] , ini = 0;
int path[ MAX ];
bool end;
void solve( int x , int parent , int len ){
    path[ len ] = x;
    int i , v;
    for( i = 0 ; i < ady[ x ].size() ; ++i ){
        v = ady[ x ][ i ];
        if( !seen[ v ] ){
            seen[ v ] = 1;
            solve( v , x , len + 1 );
            if( end ) return;
            seen[ v ] = 0;
        }
        else if( v != parent && v == ini && len == V ){
            for( int j = 1 ; j <= len ; ++j ) printf("%d " , path[ j ] + 1 );
            puts("1");
            end = true;
            return;
        }
    }
}

int main(){
    int i , u , v;
    while( scanf("%d" , &V ) != EOF ){
        gets( s );
        while( gets( s ) , s[ 0 ] != '%' ){
            stringstream ss( s );
            ss>>u>>v;
            u--; v--;
            ady[ u ].push_back( v );
            ady[ v ].push_back( u );
        }
        end = false;
        seen[ 0 ] = 1;
        solve( 0 , -1 , 1 );
        for( i = 0 ; i <= V ; ++i ) ady[ i ].clear() , seen[ i ] = 0;
    }

    return 0;
}
