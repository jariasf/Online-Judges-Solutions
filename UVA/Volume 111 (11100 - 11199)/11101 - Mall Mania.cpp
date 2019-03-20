/*****************************************
 ***Problema: Mall Mania
 ***ID: 11101
 ***Juez: UVA
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX 2001
int ady[ MAX ][ MAX ] , h , w , n;

struct Estado{
    int x , y , d;
    Estado( int xx , int yy , int dd ): x( xx ) , y( yy ) , d( dd ){}
};

int dx[ 4 ] = { 0 , 0 , 1 , -1 };
int dy[ 4 ] = { 1 , -1 , 0 , 0 };

queue< Estado > Q;
void bfs(){
    int i , nx , ny , j;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();
        if( ady[ act.x ][ act.y ] == 2 ){
            printf("%d\n" , act.d );
            break;
        }
        for( i = 0 ; i < 4 ; ++i ){
            nx = dx[ i ] + act.x;
            ny = dy[ i ] + act.y;
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && ady[ nx ][ ny ] != 1 ){
                if( ady[ nx ][ ny ] == 2 ){
                    printf("%d\n" , act.d + 1 );
                    break;
                }
                Q.push( Estado( nx , ny , act.d + 1 ) );
                ady[ nx ][ ny ] = 1;
            }
        }
        if( i != 4 ) break;
    }
}

int main(){

    int  x , y , i , j , m;
    h = w = 2000;
    while( scanf("%d" , &n ) , n ){
        while( !Q.empty() ) Q.pop();
        for( i = 0 ; i < n && scanf("%d %d" , &x , &y ); ++i ){
            Q.push( Estado( x , y , 0 ) );
        }
        scanf("%d" , &m );
        for( i = 0 ; i < m && scanf("%d %d" , &x , &y ); ++i ){
            ady[ x ][ y ] = 2;
        }
        bfs();
        memset( ady , 0 , sizeof( ady  ) );
    }

    return 0;
}
