/*****************************************
 ***Problema: Battleships
 ***ID: 11953
 ***Juez: UVA
 ***Tipo: Graph Theory , Flood Fill
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

int N, resp;
#define MAX 105
char ady[ MAX ][ MAX ];
bool seen[ MAX ][ MAX ];
void dfs( int x , int y ){
    if( x < 0 || x >= N || y < 0 || y >= N ||ady[ x ][ y ] == '.' || seen[ x ][ y ])return;
    seen[ x ][ y ] = true;
    dfs( x + 1 , y );
    dfs( x - 1 , y );
    dfs( x , y - 1 );
    dfs( x , y + 1 );
}

int main(){

    int t;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &N );

        for( int i = 0 ; i < N ; ++i ){
             scanf("%s" , &ady[ i ] );
        }
        resp = 0;
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 0 ; i < N ; ++i ){
            for( int j = 0 ; j < N ; ++j ){
                if( !seen[ i ][ j ] && ady[ i ][ j ] == 'x'){
                    dfs( i , j );
                    resp++;
                }
            }
        }

        printf("Case %d: %d\n" , q , resp );
    }

    return 0;
}
