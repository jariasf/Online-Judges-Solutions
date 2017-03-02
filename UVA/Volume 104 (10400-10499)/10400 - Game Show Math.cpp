/*****************************************
 ***Problema: Game Show Math
 ***ID: 10400
 ***Juez: UVA
 ***Tipo: DP
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
int n, a[ MAX ] , dp[ 32005 ][ MAX ][ 2 ] , res;
bool end;
bool solve( int sum , int K , string s ){
    if( end ) return 1;
    if( K == n ){
        if( sum == res ) {
            printf("%d" , a[ 0 ] );
            for( int i = 1 ; i < n ; ++i ){
                printf("%c%d", s[ i - 1 ] , a[ i ] );
            }
            printf("=%d\n" , res );
            end = 1;
            return 1;
        }
        return 0;
    }
    if( sum < 0 ){
        if( dp[ -sum ][ K ][ 0 ] != -1 ) return dp[ -sum ][ K ][ 0 ];
    }
    else if( dp[ sum ][ K ][ 1 ] != -1 ) return dp[ sum ][ K ][ 1 ];

    bool ans = 0;
    if( sum - a[ K ] >= -32000 && sum - a[ K ] <= 32000 ){
        ans |= solve( sum - a[ K ] , K + 1 , s + "-" );
    }
    if( sum + a[ K ] >= -32000 && sum + a[ K ] <= 32000 ){
        ans |= solve( sum + a[ K ] , K + 1 , s + "+" );
    }
    if( sum * a[ K ] >= -32000 && sum * a[ K ] <= 32000 ){
        ans |= solve( sum * a[ K ] , K + 1 , s + "*" );
    }
    if( sum % a[ K ] == 0 && sum/a[ K ] >= -32000 && sum/a[ K ] <= 32000 ){
        ans |= solve( sum / a[ K ] , K + 1 , s + "/" );
    }
    if( sum < 0 ) return dp[ -sum ][ K ][ 0 ] = ans;
    return dp[ sum ][ K ][ 1 ] = ans;
}

int main(){
    int t ;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n; ++i ) scanf("%d" , &a[ i ] );
        scanf("%d" , &res );
        memset( dp , -1 , sizeof( dp ) );
        end = false;
        if( !solve( a[ 0 ] , 1 , "" ) ) puts("NO EXPRESSION");
    }
    return 0;
}
