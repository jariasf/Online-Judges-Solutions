/*****************************************
 ***Problema: Counting Cells in a Blob
 ***ID: 871
 ***Juez: UVA
 ***Tipo: Graph, Flood Fill
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
#define MAX 26
int ady[ MAX ][ MAX ];
int seen[ MAX ][ MAX ];
int h , w, cnt;
int dx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int dy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1};
void dfs( int x , int y ){
    seen[ x ][ y ] = 1;
    cnt++;
    for(int i  =0 ; i < 8 ; ++i ){
        int nx = dx[ i ] + x, ny = dy[ i ] + y;
        if( nx >= 0 && ny >= 0 && nx < h && ny < w && !seen[ nx ][ ny ] && ady[ nx ][ ny ] == 1 ){

            dfs( nx , ny );
        }
    }

}
int main(){
    int t, maxi;
    scanf("%d" , &t );
    char s[ MAX ];
    gets( s );
    gets( s );
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        h = 0;
        maxi = 0;
        while( gets( s ) ){
            int l = strlen( s );
            if( l == 0 )break;
            w = l;
            for( int i = 0 ; i < w ; ++i ){
                if( s[ i ] == '1' )ady[ h ][ i ] = 1;
                else ady[ h ][ i ] = 0;
            }
            h++;
        }
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( ady[ i ][ j ] == 1 && ! seen[ i ][ j ] ){
                    cnt = 0;
                    dfs( i , j );

                    if( cnt > maxi )maxi = cnt;
                }
            }
        }
        printf("%d\n" , maxi );

    }

    return 0;
}
