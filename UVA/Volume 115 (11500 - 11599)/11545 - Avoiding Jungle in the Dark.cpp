/*****************************************
 ***Problema: Avoiding Jungle in the Dark
 ***ID: 11545
 ***Juez: UVA
 ***Tipo: DP | BFS
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
#define MAX 1005
#define INF 1<<30
#define dormido 1
#define despierto 0
int dp[ MAX ][ 25 ][ 18 ];
bool AM( int hora ){
    if( ( hora >= 18 && hora <= 24 ) || ( hora >= 0 && hora < 6 ) ) return false;
    return true;
}
bool seen[ MAX ][ 25 ][ 16 ][ 2 ];
char s[ MAX ];
int n;

struct Data{
    int pos , hora , steps, d;
    Data( int p , int h , int s , int dist  ): pos( p ) , hora( h ) , steps( s ) ,d( dist ){}
};
int bfs(){

    queue< Data > Q;
    Q.push( Data( 0 , 6 , 0 , 0 ) );
    seen[ 0 ][ 6 ][ 0 ][ despierto ] = 1;
    int hora, steps , pos;
    while( !Q.empty() ){
        Data act = Q.front(); Q.pop();
        pos = act.pos;
        hora = act.hora;
        steps = act.steps;
        if( !AM( hora ) && s[ pos ] == '*' ) continue;
        if( pos == n - 1 ) return act.d;
        if( pos + 1 == n ) continue;
        if( AM( hora ) ){
            if( steps + 1 <= 16 ){
                if( !seen[ pos + 1 ][ ( hora + 1 ) % 24 ][ steps + 1 ][ despierto ] )
                {
                    seen[ pos + 1 ][ ( hora + 1 ) % 24 ][ steps + 1 ][ despierto ] = 1;
                    Q.push( Data( pos + 1 , ( hora + 1 ) % 24 , steps + 1 , act.d + 1 ) );
                }
            }
            else if( !seen[ pos ][ ( hora + 8 ) % 24 ][ 0 ][ dormido ] ){
                    Q.push( Data( pos , ( hora + 8 ) % 24 , 0 , act.d + 8 ) );
                    seen[ pos ][ ( hora + 8 ) % 24 ][ 0 ][ dormido ] = 1;
            }
        }
        else{
            if( s[ pos + 1 ] != '*' ){
                if( steps + 1 <= 16 ){
                    if( !seen[ pos + 1 ][ ( hora + 1 ) % 24 ][ steps + 1 ][ despierto ] ){
                        Q.push( Data( pos + 1 , ( hora + 1 ) % 24 , steps + 1 , act.d + 1 ) );
                        seen[ pos + 1 ][ ( hora + 1 ) % 24 ][ steps + 1 ][ despierto ] = 1;
                    }
                }
                else if( !seen[ pos ][ ( hora + 8 ) % 24 ][ 0 ][ dormido ] ){
                    Q.push( Data( pos , ( hora + 8 ) % 24 , 0 , act.d + 8 ) );
                    seen[ pos ][ ( hora + 8 ) % 24 ][ 0 ][ dormido ] = 1;
                }
            }
        }

        if( !seen[ pos ][ ( hora + 8 ) % 24 ][ 0 ][ dormido ] ){
            Q.push( Data( pos , ( hora + 8 ) % 24  , 0 , act.d + 8 ) );
            seen[ pos ][ ( hora + 8 ) % 24 ][ 0 ][ dormido ] = 1;
        }
    }

    return -1;
}


int main(){
    int t , q , ans;
    scanf("%d" , &t );

    for( q = 1 ; q <= t && scanf("%s" , &s ) == 1 ; ++q  ){
        n = strlen( s );
        memset( seen , 0 , sizeof( seen ) );
        printf("Case #%d: %d\n" , q , bfs() );
    }

    return 0;
}
