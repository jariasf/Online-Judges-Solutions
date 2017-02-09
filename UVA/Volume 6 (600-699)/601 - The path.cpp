/*****************************************
 ***Problema: The Path
 ***ID: 601
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS 0/1
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
#define MAX 81
char ady[ MAX ][ MAX ];
int n;
bool seen[ MAX ][ MAX ];
int dist[ MAX ][ MAX ];

struct Estado{
    int x ,y;
    Estado( int xx , int yy  ): x( xx ) , y( yy ){}
};

int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };

void bfs( int x , int y , char c ){
    memset( dist , -1 , sizeof( dist ) );
    deque<Estado> Q;
    Q.push_front( Estado( x , y ) );
    dist[ x ][ y ] = 0;
    while( !Q.empty() ){
        Estado act =Q.front(); Q.pop_front();
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = act.x + dx[ i ];
            int ny = act.y + dy[ i ];
            if( nx >= 0 && nx < n && ny >= 0 && ny < n  && dist[ nx ][ ny ] == -1 ){
                if( ady[ nx ][ ny ] == 'U' ){
                    Q.push_back( Estado( nx , ny ) );
                    dist[ nx ][ ny ] = dist[ act.x ][ act.y ] + 1;
                }
                else if( ady[ nx ][ ny ] == c){
                    Q.push_front( Estado( nx , ny ) );
                    dist[ nx ][ ny ] = dist[ act.x ][ act.y ];
                }
            }
        }
    }
}

int main(){
    int resp;
    bool winner;
    while( scanf("%d" , &n ) && n ){

        for( int i = 0 ; i < n ; ++i ){
            scanf("%s" , &ady[ i ] );
        }

        if( n == 1 && strcmp( ady[ 0 ] , "U") == 0 ){
            printf("White can win in one move.\n");
            continue;
        }

        winner = false;
        for( int i = 0 ; i < n ; ++i ){
            if( ady[ i ][ 0 ] != 'W' )continue;
            bfs( i , 0 , 'W' );

            ///revisamos si se llego al final
            for( int j = 0 ; j < n ; ++j ){
                if( dist[ j ][ n - 1 ] == 0 ){
                    printf("White has a winning path.\n");
                    winner = true;
                    break;
                }
            }

            if( winner )break;

            for( int j = 0 ; j < n ; ++j ){
                if( dist[ j ][ n - 1 ] == 1 ){
                    printf("White can win in one move.\n");
                    winner = true;
                    break;
                }

            }
            if( winner )break;
        }
        if( winner ) continue;

        for( int i = 0 ; i < n ; ++i ){
            if( ady[ 0 ][ i ] != 'B' )continue;
            bfs( 0 , i , 'B' );

            ///revisamos si se llego al final
            for( int j = 0 ; j < n ; ++j ){
                if( dist[ n - 1 ][ j ] == 0 ){
                    printf("Black has a winning path.\n");
                    winner = true;
                    break;
                }
            }

            if( winner )break;

            for( int j = 0 ; j < n ; ++j ){
                if( dist[ n - 1 ][ j ] == 1 ){
                    printf("Black can win in one move.\n");
                    winner = true;
                    break;
                }
            }
            if( winner )break;
        }
        if( !winner ) printf("There is no winning path.\n");
    }
}


/**
TEST CASES

5
WBWUU
BBWUU
BWBBB
BBUWB
WWWWB

5
WBWUU
BBWUU
BWBBB
BBUWB
WWUWB

4
BUUUU
BUUUU
WBUUU
BUUUU


5
WBWUU
BBWUU
BWBBB

BBUWB
WWUWU

**/

