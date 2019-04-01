/*****************************************
 ***Problema: Guardian of Decency
 ***ID: 12083
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

int girl[ MAXL ] , n;
int matchings(){
    memset( matchR , -1 , sizeof( matchR ) );
    memset( matchL , -1 , sizeof( matchL ) );
    int ans = 0 , i;
    for( i = 0 ; i < n ; ++i ){
        memset( seen , 0 , sizeof( seen ) );
        if( bpm( girl[ i ] ) ) ans++;
    }
    return ans;
}

struct Data{
    int h;
    char sex;
    string music , sport;
    Data( ){}
}a[ MAXL ];

int main(){
    int t , i , j;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &L ) ){
        for( i = 0 ; i < L && cin>>a[ i ].h>>a[ i ].sex>>a[ i ].music>>a[ i ].sport; ++i );
        n = 0;
        for( i = 0 ; i < L ; ++i ){
            if( a[ i ].sex == 'F' ) girl[ n++ ] = i;
            for( j = 0 ; j < L ; ++j ){
                if( i != j && abs( a[ i ].h - a[ j ].h ) <= 40 && a[ i ].sex != a[ j ].sex &&
                   a[ i ].music == a[ j ].music && a[ i ].sport != a[ j ].sport ){
                    ady[ i ].push_back( j + L );
                }
            }
        }
        printf("%d\n" , L - matchings() );
        for( i = 0 ; i < L ; ++i ) ady[ i ].clear();
    }
    return 0;
}
