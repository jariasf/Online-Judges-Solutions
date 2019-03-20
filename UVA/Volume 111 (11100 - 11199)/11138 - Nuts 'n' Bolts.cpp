/*****************************************
 ***Problema: Nuts 'n' Bolts
 ***ID: 11138
 ***Juez: UVA
 ***Tipo: Bipartite Matching
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


#define MAXL 505
#define MAXR 1005
int seen[ MAXL ], matchL[ MAXL ] , matchR[ MAXR ] , L;
vector< int > ady[ MAXL ];
int bpm( int left ){
    if( seen[ left ] ) return 0;
    seen[ left ] = 1;
    int right , i;
    for( i = 0 ; i < ady[ left ].size() ; ++i ){
        right = ady[ left ][ i ];
        if( matchR[ right ] == -1 || bpm( matchR[ right ] ) ){
            matchR[ right ] = left;
            matchL[ left ] = right;
            return 1;
        }
    }
    return 0;
}

int matchings(){
    memset( matchR , -1 , sizeof( matchR ) );
    memset( matchL , -1 , sizeof( matchL ) );
    int ans = 0 , i;
    for( i = 0 ; i < L ; ++i ){
        memset( seen , 0 , sizeof( seen ) );
        if( bpm( i ) ) ans++;
    }
    return ans;
}
int main(){

    int t , q , i , j , x  , m;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d" , &L , &m ) ; ++q ){
        for( i = 0 ; i < L ; ++i ){
            for( j = 0 ; j < m && scanf("%d" , &x ) ; ++j ){
                if( x ) ady[ i ].push_back( j + L );
            }
        }

        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n" , q , matchings() );

        for( i = 0 ; i < L ; ++i ) ady[ i ].clear();
    }

    return 0;
}
