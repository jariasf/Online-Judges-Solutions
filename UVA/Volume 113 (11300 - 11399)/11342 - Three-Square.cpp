/*****************************************
 ***Problema: Three-Square
 ***ID: 11342
 ***Juez: UVA
 ***Tipo: Meet in the meedle
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
#define MAX 305

int main(){
    int t , k;

    scanf("%d\n" , &t );
    bool posible;
    int v[ MAX ], len, max_idx, aa , bb ,cc ;
    while( t-- ){
        len = 0;
        max_idx = -1;
        scanf("%d" , &k );

        for( int i = 0 ; i * i <= k ; ++i ){ v[ len ++ ] = k - i * i ; }
        sort( v , v + len );

        posible = false;
        for( int a = 0 ; a * a <= k ; ++a ){
            for( int b = a ; b * b <= k ; ++b ){
                int idx = ( int )(upper_bound( v , v + len , a * a + b * b ) - v ) - 1;
                if( idx < 0 )continue;
                int c = sqrt( k - v[ idx ] );
                if( c > a && c >=  b  && ( a * a  + b * b == v[ idx ] ) ){
                    aa = a; bb = b ; cc = c;
                    posible = true;
                    break;
                }
            }
            if( posible )break;
        }

        if( !posible ) printf( "-1\n");
        else printf("%d %d %d\n" , aa , bb , cc );
    }
    return 0;
}
