/*****************************************
 ***Problema: Safebreaker
 ***ID: 296
 ***Juez: UVA
 ***Tipo: Brute Force
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
string toStr(int n){string s;ostringstream buffer;buffer<<n;s=buffer.str();return s;}
string Str( int n ){
    string s = toStr( n );
    for( int i = s.length() ; i < 4 ; ++i ) s = "0" + s;
    return s;
}

#define MAX 15
int main(){
    int t, n, valid[ MAX ] , change[ MAX ], cnt, eq , c , j, aux[ MAX ], aux2[ MAX ];
    scanf("%d" , &t );
    char num[ 15 ][ 5 ];
    string ans;
    vector<string> v;
    for( int i = 0 ; i < 10000 ; ++i ) v.push_back( Str( i ) );
    memset( aux , 0 , sizeof( aux ) );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ) scanf("%s %d/%d" , &num[ i ] , &valid[ i ] , &change[ i ] );
        cnt = 0;
        for( int i = 0 ; i < 10000 ; ++i ){
            j = 0;
            for( ; j < n ; ++j ){
                eq = 0;
                memset( aux , 0 , sizeof( aux ) );
                memset( aux2 , 0 , sizeof( aux2 ) );
                for( int k = 0 ; k < 4 ; ++k ){
                    if( v[ i ][ k ] == num[ j ][ k ] ) eq++;
                    else { aux2[ num[ j ][ k ] - '0' ]++; aux[ v[ i ][ k ] - '0' ]++;}
                }
                if( eq != valid[ j ] ) break;
                eq = 0;
                for( int k = 0 ; k < 10 ; ++k ){
                    if( aux2[ k ] && aux[ k ] ) eq += min( aux[ k ] , aux2[ k ] );
                }
                if( eq != change[ j ] ){ break; }
            if( j == n ){ cnt++; ans = v[ i ];}
            if( cnt > 1 )break;
        }
        if( cnt == 2 ) puts("indeterminate");
        else if( cnt ) printf("%s\n" , ans.c_str() );
        else puts("impossible");
    }
    return 0;
}
