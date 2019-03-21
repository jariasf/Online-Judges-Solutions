/*****************************************
 ***Problema: Counting Stars
 ***ID: 11244
 ***Juez: UVA
 ***Tipo: Flood Fill
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
int h , w;
#define MAX 105
bool seen[ MAX ][ MAX ];
char ady[ MAX ][ MAX ];
int cont;

void dfs( int x , int y ){
    if( x < 0 || x >= h || y < 0 || y >= w ||seen[ x ][ y ] ||ady[ x ][ y ] == 46 )return;
    seen[ x ][ y ] = true;
    cont++;
    dfs( x + 1 , y );
    dfs( x - 1 , y );
    dfs( x , y + 1 );
    dfs( x , y - 1 );
    dfs( x + 1 , y + 1 );
    dfs( x - 1 , y - 1 );
    dfs( x + 1 , y - 1 );
    dfs( x - 1 , y + 1 );
}

int main(){
    int ans;
    while( scanf("%d %d" , &h , &w ) && h|w ){
        ans = 0;
        for( int i = 0 ; i < h ; ++i )scanf("%s" , ady[ i ] );
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( !seen[ i ][ j ] && ady[ i ][ j ] == '*' ){
                    cont = 0;
                    dfs( i , j );
                    if( cont == 1 )ans++;
                }
            }
        }
        printf("%d\n" , ans );
    }

    return 0;
}
