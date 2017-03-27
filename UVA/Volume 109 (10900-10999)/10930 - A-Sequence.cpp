/*****************************************
 ***Problema: A-Sequence
 ***ID: 10930
 ***Juez: UVA
 ***Tipo: Ad hoc
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
#define MAX 35
int a[ MAX ] , seen[ 1005 ];
bool b;
int dp[ MAX ][ 1005 ];
int possible( int len , int s ){
    if( s < 0 ) return 1;
    if( len == -1 ){
        if( s == 0 ) return 0;
        return 1;
    }
    if( dp[ len ][ s ] != -1 ) return dp[ len ][ s ];
    bool b = possible( len - 1 , s - a[ len ] ) & possible( len - 1 , s );
    return dp[ len ][ s] =b;
}

int main(){
    int q = 1 , i , n ;
    while( scanf("%d" , &n ) != EOF ){
        printf("Case #%d:" , q++ );
        for( i = 0 ; i < n && scanf("%d" , &a[ i ] ) ; ++i ) printf(" %d" , a[ i ] );
        printf("\n");
        b = 1;
        memset( dp , -1 , sizeof( dp ) );
        for( i = 1 ; i < n ; ++i ){
            if( a[ i - 1 ] > a[ i ] || !possible( i - 1 , a[ i ] ) ){
                b = 0; break;
            }
        }
        if( b ) puts("This is an A-sequence.");
        else puts("This is not an A-sequence.");
    }
    return 0;
}
