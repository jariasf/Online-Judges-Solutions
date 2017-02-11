/*****************************************
 ***Problema: Numerical maze
 ***ID: 868
 ***Juez: UVA
 ***Tipo: Backtracking | DFS
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
#define MAX 55
int h , w , ady[ MAX ][ MAX ];

struct Node{
    int x , y , val;
    Node( int xx , int yy , int v ): x( xx ) , y( yy ) , val( v ){}
};

//bool seen[ MAX ][ MAX ];
int dx[] = { 1 , 0 , -1 , 0 };
int dy[] = { 0 , 1 ,  0 , -1 };

bool bfs( int xini , int yini ){
    queue<Node> Q;
    //memset( seen , 0  ,sizeof( seen ) );
    Q.push( Node( xini , yini , 1 ) );
    int ymini = MAX;
    while( !Q.empty() ){
        Node act = Q.front(); Q.pop();
        if( act.x == h - 1 ){
            ymini = min( act.y , ymini );
            continue;
        }
        //if( seen[ act.x ][ act.y ] ) continue;
        for( int i = 0 ; i < 4  ; ++i ){
            int nx = dx[ i ] + act.x, ny = dy[ i ] + act.y;
            if( nx >= 0 && nx < h && ny >= 0 && ny < w ){
                if( ady[ act.x ][ act.y ] == act.val ){
                   if( ady[ nx ][ ny ] == 1 ){
                        Q.push( Node( nx , ny , act.val + 1 ) );
                   }
                }
                else if( ady[ act.x ][ act.y ] < act.val ){
                    if( ady[ nx ][ ny ] == ady[ act.x ][ act.y ] + 1 ){
                        Q.push( Node( nx , ny , act.val ) );
                    }
                }
            }
        }
    }
    if( ymini != MAX ){ printf("%d %d\n%d %d\n" , xini + 1 , yini + 1 , h , ymini + 1 ); return true;}
    return false;
}

int main(){
    int t;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q ) putchar('\n');
        scanf("%d %d" , &h ,&w );

        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                scanf("%d" , &ady[ i ][ j ] );
            }
        }

        for( int i = 0 ; i < w ; ++i ){
            if( ady[ 0 ][ i ] == 1 && bfs( 0 , i )){
                break;
            }
        }
    }

    return 0;
}
