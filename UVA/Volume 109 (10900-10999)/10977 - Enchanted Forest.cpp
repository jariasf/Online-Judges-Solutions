/*****************************************
 ***Problema: Enchanted Forest
 ***ID: 10977
 ***Juez: UVA
 ***Tipo: Graph Theory , BFS
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
#define MAX 205
int R , C , JJ;
int ady[ MAX ][ MAX ];

struct Jigly{
    int x , y , L;
    Jigly( int xx , int yy , int LL ): x( xx ) , y( yy ) , L( LL ){}
    Jigly(){}
}J[ MAX ];

struct Estado{
    int x , y , d;
    Estado( int xx , int yy , int dd ): x( xx ) , y( yy ) , d( dd ){}
};
bool seen[ MAX ][ MAX ];

int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };

double dist( int x , int y , int x1 , int y1 ){
    return sqrt( ( x - x1 ) * ( x - x1 ) + ( y - y1 ) * ( y - y1 ) ) ;
}

bool possible( int x , int y ){

    for( int i = 0 ; i < JJ ; ++i ){
        if( dist( x , y , J[ i ].x , J[ i ].y ) <= J[ i ].L ) return false;
    }
    return true;
}

int bfs(){
    queue<Estado> Q;
    memset( seen , 0 , sizeof( seen ) );

    Q.push( Estado( 0 , 0 , 0 ) );
    seen[ 0 ][ 0 ] = 1;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();

        if( act.x == R - 1 && act.y == C - 1 ){
            return act.d;
        }

        for( int i = 0 ; i < 4 ; ++i ){
            int nx = act.x + dx[ i ], ny = act.y + dy[ i ];
            if( nx >= 0 & ny >= 0 && nx < R && ny < C && ady[ nx ][ ny ] == 0 && !seen[ nx ][ ny ] && possible( nx , ny )){
                seen[ nx ][ ny ] = 1;
                Q.push( Estado( nx , ny , act.d + 1 ) );
            }
        }
    }
    return -1;
}


int main(){
    int x , y , d , l;
    while( scanf("%d %d" , &R , &C ) , R|C ){
        scanf("%d" , &d );
        memset( ady , 0 , sizeof( ady ) );

        while( d-- ){
            scanf("%d %d" , &x , &y );
            ady[ x - 1 ][ y - 1 ] = 1;
        }
        scanf("%d" , &JJ );
        for( int i = 0 ; i < JJ ; ++i ){
            scanf("%d %d %d" , &x , &y , &l );
            J[ i ] = Jigly( x - 1 , y - 1 , l );
        }

        d = bfs();
        if( d == - 1 )printf("Impossible.\n");
        else printf("%d\n" , d );
    }

    return 0;
}
