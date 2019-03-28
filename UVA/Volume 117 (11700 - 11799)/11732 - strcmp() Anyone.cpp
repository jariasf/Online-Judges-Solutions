/*****************************************
 ***Problema: strcmp() Anyone
 ***ID: 11732
 ***Juez: UVA
 ***Tipo: Longest Common Prefix
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

#define MAXN 10005
char s[ MAXN ];
int LCP[ MAXN ];
int main(){
    int n , q = 1 , i , len , j , mini;
    long long ans;
    while( scanf("%d" , &n ) , n ){
        ans = 0;
        vector< string > v;
        for( i = 0 ; i < n && scanf("%s" , s ) ; ++i ){
            len = strlen( s );
            s[ len++ ] = '.'; s[ len ] = '\0';
            v.push_back( s );
            LCP[ i ] = 0;
        }
        sort( v.begin() , v.end() );

        for( i = 1 ; i < n ; ++i ){
            len = min( v[ i - 1 ].length() , v[ i ].length() );
            for( j = 0 ; j < len ; ++j ){
                LCP[ i ]++;
                if( v[ i - 1 ][ j ] != v[ i ][ j ] ) break;
                LCP[ i ]++;
                if( v[ i - 1 ][ j ] == '.' ) break;
            }
        }

        for( i = 0 ; i < n ; ++i ){
            mini = 1<<30;
            for( j = i + 1 ; j < n ; ++j ){
                mini = min( mini , LCP[ j ] );
                ans += mini;
            }
        }

        printf("Case %d: %lld\n" , q++ , ans );
    }

    return 0;
}

/*
2
tha
that
4
1242AA
AAbd
a
4
1
QWERa
4
QWEWW
QWEWWE
QW
QWEWR
3
QWEWW
QWEWWE
QW
2
QWEWWE
QW
0
*/
