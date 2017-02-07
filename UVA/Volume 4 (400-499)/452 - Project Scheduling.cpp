/*****************************************
 ***Problema: Project Scheduling
 ***ID: 452
 ***Juez: UVA
 ***Tipo: Topological Sort
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
#define MAX 30
char s[ MAX ];
int ady[ MAX ][ MAX ], w[ MAX ], degree[ MAX ], used[ MAX ];

int bfs(){
    int dist[ MAX ];
    memset( dist , 0 , sizeof( dist ) );
    int ans = 0;
    queue< int > Q;
    for( int i = 0 ; i < MAX ; ++i ){
        dist[ i ] = w[ i ];
        if( used[ i ] && degree[ i ] == 0 ){
            Q.push( i );
        }
    }
    while( !Q.empty() ){
        int act = Q.front(); Q.pop();
        for( int i = 0 ; i < 28 ; ++i ){
            if( ady[ act ][ i ] ){
                degree[ i ]--;
                dist[ i ] = max( dist[ i ] , w[ i ] + dist[ act ] ); //longest path DP
                if( degree[ i ] == 0 )Q.push( i );
            }
        }
    }
    for( int j = 0 ; j < MAX ; ++j ){
        if( !used[ j ] ) continue;
        ans = max( ans , dist[ j ] );
    }
    return ans;
}

int main(){
    char c;
    int val , t;
    scanf("%d" , &t );
    gets( s );
    gets( s );
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        memset( ady , 0 , sizeof( ady ) );
        memset( w , 0 , sizeof( w ) );
        memset( degree , 0 , sizeof( degree ) );

        memset( used , 0 , sizeof( used ) );
        while( gets( s ) ){
            if( strlen( s ) == 0 ) break;
            stringstream ss( s );
            ss>>c>>val;
            w[ c - 'A' ] = val;
            used[ c - 'A' ] = 1;
            if( ss>>s ){
                for( int i = 0 ; s[ i ] ; ++i ){
                    degree[ c - 'A' ]++;
                    ady[ s[ i ] - 'A' ][ c - 'A' ] = 1;
                    used[ s[ i ] - 'A' ] = 1;
                }
            }
        }
        printf("%d\n" , bfs() );
    }
    return 0;
}

/*
1

A 2
C 3
B 5 AC
D 10 B
H 13 GF
E 11 B
G 12
F 2 DE
I 10
J 20 I
*/
