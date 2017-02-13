/*****************************************
 ***Problema: Machine Schedule
 ***ID: 1194
 ***Juez: UVA
 ***Tipo: BPM - Min Vertex Cover
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
#define MAXL 105
#define MAXR 105
int seen[ MAXL ], matchL[ MAXL ] , matchR[ MAXR ];
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
int L;
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
    int n , m ,k , A , B , i;
    while( scanf("%d" , &n ) , n ){
        scanf("%d %d" , &m , &L );
        for( i = 0 ; i < L && scanf("%d %d %d" , &k , &A , &B); ++i ){
            if( !A || !B ) continue;
            ady[ A ].push_back( B );
        }
        L = n;
        printf( "%d\n" , matchings() );
        for( i = 0 ; i <= n ; ++i ) ady[ i ].clear();
    }

    return 0;
}
