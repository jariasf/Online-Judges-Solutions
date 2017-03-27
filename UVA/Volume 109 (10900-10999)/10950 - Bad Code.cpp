/*****************************************
 ***Problema: Bad Code
 ***ID: 10950
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
#define MAXN 10005
#define MAX 30
int n , sz;

struct Data{
    char c;
    int val;
    Data( char cc , int vv ) : c( cc ) , val( vv ){}
    Data(){}
    bool operator < ( Data d2 ) const{
        return c < d2.c;
    }
}a[ MAX ];

char s[ MAXN ];
int ans;
void solve( int len , string str ){
    if( ans >= 100 ) return;
    if( len == sz ){
        printf("%s\n" , str.c_str() );
        ans++;
        return;
    }
    int i , j;
    for( i = 0 ; i < n ; ++i ){
        int d1 = a[ i ].val , d2 = -1;
        if( d1 > 9 ){
            d1 = a[ i ].val / 10;
            d2 = a[ i ].val % 10;
        }

        if( s[ len ] == d1 + '0' ){
            if( d2 != -1 ){
                if( len + 1 < sz && s[ len + 1 ] == d2 + '0' )
                    solve( len + 2 , str + a[ i ].c );
            }
            else solve( len + 1 , str + a[ i ].c );
        }

        if( s[ len ] == '0' ){
            if( len + 1 < sz && s[ len + 1 ] == d1 + '0' ){
                if( d2 != -1 ){
                    if( len + 2 < sz && s[ len + 2 ] == d2 + '0' )
                        solve( len + 3 , str + a[ i ].c );
                }
                else solve( len + 2 , str + a[ i ].c );
            }
        }
    }
}



int main(){
    int i , q = 1;
    while( scanf("%d" , &n ) , n ){
        for( i = 0 ; i < n && scanf(" %c %d" , &a[ i ].c , &a[ i ].val ) ; ++i );
        scanf("%s" , s );
        sz = strlen( s );
        sort( a , a + n );
        printf("Case #%d\n" , q++ );
        ans = 0;
        solve( 0 , "" );
        printf("\n");
    }

    return 0;
}
