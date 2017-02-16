/*****************************************
 ***Problema: The Monocycle
 ***ID: 10047
 ***Juez: UVA
 ***Tipo: BFS
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
enum{ GREEN , BLACK , RED , BLUE , WHITE , N , S , W , E };
int h , w;
char ady[ MAX ][ MAX ];

struct Estado{
    int x , y , d , color , dir;
    Estado( int xx , int yy , int dd , int cc , int di ): x( xx ) , y( yy ) , d( dd ) , color( cc ) , dir( di ){}
};

int seen[ MAX ][ MAX ][ 5 ][ 10 ];

bool visto( Estado s ){
    return seen[ s.x ][ s.y ][ s.color ][ s.dir ];
}

void visitado( Estado s ){
    seen[ s.x ][ s.y ][ s.color ][ s.dir ]  = 1;
}

int dx[ 4 ] = { -1 , 1 , 0 , 0 } , dy[ 4 ] = { 0 , 0 ,  -1 , 1 };

void bfs( int xini , int yini ){
    int nx , ny , ans = -1;
    memset( seen , 0 , sizeof( seen ) );
    queue< Estado > Q;
    Q.push( Estado( xini , yini , 0 , GREEN , N ) );
    seen[ xini ][ yini ][ GREEN ][ N ] = 1;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();
        if( ady[ act.x ][ act.y ] == 'T' && act.color == GREEN ){
            ans = act.d;
            break;
        }

        if( act.dir == N || act.dir == S ){
            Estado vec = act;
            vec.d++;
            vec.dir = W;
            if( !visto( vec ) ){
                Q.push( vec );
                visitado( vec );
            }
            vec.dir = E;
            if( !visto( vec ) ){
                Q.push( vec );
                visitado( vec );
            }
        }
        else if( act.dir == W || act.dir == E ){
            Estado vec = act;
            vec.dir = N;
            vec.d++;
            if( !visto( vec ) ){
                Q.push( vec );
                visitado( vec );
            }

            vec.dir = S;
            if( !visto( vec ) ){
                Q.push( vec );
                visitado( vec );
            }
        }

        nx = act.x + dx[ act.dir - N ];
        ny = act.y + dy[ act.dir - N ];

        if( nx >= 0 && nx < h && ny >= 0 && ny < w && ady[ nx ][ ny ] != '#' ){
            Estado vec( nx , ny , act.d + 1 , ( act.color + 1 ) % ( WHITE + 1 ) , act.dir );
            if( !visto( vec ) ){
                Q.push( vec );
                visitado( vec );
            }
        }

    }
    if( ans == -1 ) puts("destination not reachable");
    else printf("minimum time = %d sec\n" , ans );
}

int main(){
    int xini , yini , i , j, q = 0 ;
    while( scanf("%d %d" , &h , &w ) , h | w ){
        for( i = 0 ; i < h && scanf("%s" , &ady[ i ] ) ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                if( ady[ i ][ j ] == 'S' ){ xini = i; yini = j; }
            }
        }
        if( q )printf("\n");
        printf("Case #%d\n" , ++q );
        bfs( xini , yini );
    }

    return 0;
}
