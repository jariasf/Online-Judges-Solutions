/*****************************************
 ***Problema: Square Sums
 ***ID: 11470
 ***Juez: UVA
 ***Tipo: DFS
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

int n;
#define MAX 12
bool seen[ MAX ][ MAX ];
int ady[ MAX ][ MAX ];
int sum, lon, len1 , len2 , len3 , len4;
bool b;
void dfs( int x , int y , int len ){
    if( x < 0 ||y < 0 || x >= n || y >= n ||seen[ x ][ y ] )return;
    seen[ x ][ y ] = 1;
    sum += ady[ x ][ y ];
    if( len1 == 0 )dfs( x , y + 1 , len + 1 );len1 = 1;
    if( len2 == 0 )dfs( x + 1 , y , len + 1 );len2 = 1;
    if( len3 == 0 )dfs( x , y - 1 , len + 1 );len3 = 1;
    if( len4 == 0 )dfs( x - 1 , y , len + 1 );len4 = 1;
}

int main(){
    int q = 1;
    while( scanf("%d" , &n ) && n ){
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n ; ++j )
                scanf("%d" , &ady[ i ][ j ] );

        printf("Case %d:" , q++ );
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 0 ; i < n ; ++i ){
            sum = 0;
            if( seen[ i ][ i ] )break;
            len1 = len2 = len3 = len4 = 0;
            dfs( i, i , 1 );
            printf(" %d" , sum );
        }
        putchar('\n');
    }

    return 0;
}
