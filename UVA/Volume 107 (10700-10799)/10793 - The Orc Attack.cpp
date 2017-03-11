/*****************************************
 ***Problema: The Orc Attack
 ***ID: 10793
 ***Juez: UVA
 ***Tipo: Floyd Warshall
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
#define INF 1<<30
int V, ady[ MAX ][ MAX ];
void init(){
    int i , j;
    for( i = 0 ; i < V ; ++i ){
        for( j = 0 ; j < V ; ++j ){
            ady[ i ][ j ] = ( i == j )?0:INF;
        }
    }
}

void floyd(){
    int i , j , k;
    for( k = 0 ; k < V ; ++k ){
        for( i = 0 ; i < V ; ++i ){
            if( ady[ i ][ k ] == INF ) continue;
            for( j = 0 ; j < V ; ++j ){
                if( ady[ k ][ j ] == INF || ady[ i ][ j ] < ady[ i ][ k ] + ady[ k ][ j ] ) continue;
                ady[ i ][ j ] = ady[ i ][ k ] + ady[ k ][ j ];
            }
        }
    }
}

int main(){
    int t , u , v, w , E , q , i , j , ans , maxi;
    scanf("%d" , &t );
    for( q = 1 ; q <= t ; ++q ){
        scanf("%d %d" , &V , &E );
        init();
        while( E-- ){
            scanf("%d %d %d" , &u , &v , &w );
            ady[ u - 1 ][ v - 1 ] = ady[ v - 1 ][ u - 1 ] = min( ady[ u - 1 ][ v - 1 ] , w );
        }
        floyd();
        ans = 1<<30;
        for( i = 0 ; i < V ; ++i ){

            for( j = 1 ; j < 5 ; ++j ){
                if( ady[ j ][ i ] != ady[ j - 1 ][ i ] ) break;
            }
            if( j == 5 ){
                maxi = 0;
                for( j = 0 ; j < V ; ++j ){
                    maxi = ( ady[ i ][ j ] > maxi )? maxi = ady[ i ][ j ] :maxi;
                }
                ans = ( ans > maxi )? maxi:ans;
            }
        }
        printf("Map %d: %d\n" , q , ( ans == 1<<30 )?-1: ans );
    }

    return 0;
}

/*
3
7 11
1 7 2
2 7 2
3 7 2
5 7 2
6 7 1
1 6 1
2 6 1
3 6 1
4 6 1
5 6 1
7 6 1
6 1
1 2 3
10 17
7 1 12
7 2 12
7 9 35
7 8 2
7 5 12
1 9 20
2 3 7
2 8 10
3 8 10
9 5 20
9 5 31
9 10 40
9 6 16
9 8 10
8 4 10
4 6 4
6 10 35
*/
