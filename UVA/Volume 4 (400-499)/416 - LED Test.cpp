/*****************************************
 ***Problema: LED Test
 ***ID: 416
 ***Juez: UVA
 ***Tipo: Backtracking
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
#define MAX 12
char led[ MAX ][ 9 ] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY",
                        "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN",
                        "YYYYYYY", "YYYYNYY" };
int n;
string s[ MAX ];
bool possible[ 15 ][ 15 ];
bool match;

void solve( int len , int value , int badMask ){

    if( len == n ){
        match = true;
        return;
    }

    if( possible[ len ][ value ] ){

        for( int i = 0 ; i < 7 ; ++i ){
            if( s[len][i] == 'Y' && (badMask & ( 1<<i) ) )
                return;
        }

        int mask = badMask;
        for( int i = 0 ; i < 7 ; ++i ){
            if( s[ len ][ i ] == 'N' && led[ value ][ i ] == 'Y' ){
                mask |= 1<<i;
            }
        }
        solve( len + 1 , value - 1 , mask );
    }
}

int main(){

    while( scanf("%d" , &n ) , n ){
        memset( possible , 0 , sizeof( possible ) );
        for( int i = 0 ; i < n && cin>>s[i]; ++i ){
            for( int j = 0 ; j < 10 ; ++j ){
                int k = 0;
                for( ; k < 7 ; ++k ){
                    if( s[ i ][ k ] == 'Y' && led[ j ][ k ] == 'N')break;
                }
                if( k == 7 ) {
                    possible[i][j] = true;
                }
            }
        }
        match = false;
        for( int j = 9 ; j >= n - 1 && !match; --j ){
            solve( 0 , j , 0 );
        }
        if( match )
            puts("MATCH");
        else
            puts("MISMATCH");
    }

    return 0;
}
