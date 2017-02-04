/*****************************************
 ***Problema: Othello
 ***ID: 220
 ***Juez: UVA
 ***Tipo: Ad hoc - Simulation
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
#include <assert.h>
using namespace std;
int n = 8;
char ady[ 9 ][ 9 ];
int dx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int dy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1};
char player;

bool possible( int x , int y ){
    char oponent = ( player == 'B')?'W':'B';
    if( ady[ x ][ y ] != '-' )return 0;
    int nx , ny;
    for( int i = 0 ; i < 8 ; ++i ){
        int k = 1, cnt = 0;
        while( 1 ){
            nx = k * dx[ i ] + x; ny = k * dy[ i ] + y;
            if( nx >= 0 && ny >= 0 && nx < n && ny < n && ady[ nx ][ ny ] == oponent ){
                cnt++;
            }
            else break;
            k++;
        }
        if( cnt > 0 && ady[ nx ][ ny ] == player ) return 1;
    }
    return 0;
}

struct Point{
    int x , y;
    Point(){}
    Point( int xx , int yy ) :x( xx ) , y( yy ) {}
}points[ 105 ];

void change( int x , int y  ){

    char oponent = ( player == 'B')?'W':'B';
    if( !possible( x ,  y ) ) return;

    ady[ x ][ y ] = player;
    int nx , ny;
    for( int i = 0 ; i < 8 ; ++i ){
        int k = 1, cnt = 0;
        while( 1 ){
            nx = k * dx[ i ] + x; ny = k * dy[ i ] + y;
            if( nx >= 0 && ny >= 0 && nx < n && ny < n && ady[ nx ][ ny ] == oponent ){
                points[ cnt++ ] = Point( nx , ny );
            }
            else break;
            k++;
        }
        if( cnt > 0 && ady[ nx ][ ny ] == player ){
            for( int i = 0 ; i < cnt ; ++i ){
                ady[ points[ i ].x ][ points[ i ].y ] = player;
            }
        }
    }
    int b = 0 , w = 0;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            if( ady[ i ][ j ] == 'B')b++;
            else if( ady[ i ][ j ] =='W')w++;
        }
    }
    printf("Black - %2d White - %2d\n" , b , w );
}

int main(){
    int t;
    char Q[ 5 ];
    bool first;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q){
        if( q )printf("\n");
        for( int i = 0 ; i < 8 ; ++i )
            for( int j = 0 ; j < n ; ++j ) scanf( " %c" , &ady[ i ][ j ] );

        scanf(" %c" , &player );
        while( scanf("%s" , &Q ), Q[ 0 ] != 'Q' ){
            if( Q[ 0 ] == 'L'){
                first = true;
                for( int i = 0 ; i < n ; ++i ){
                    for( int j = 0 ; j < n ; ++j ){
                        if( possible( i , j ) ){
                            if( !first )printf(" ");
                            printf("(%d,%d)" , i + 1 , j + 1 );
                            first = false;
                        }
                    }
                }
                if( !first )printf("\n");
                else puts("No legal move.");
            }
            else if( Q[ 0 ] == 'M'){
                int x = ( Q[ 1 ] - '0' ) - 1 , y = ( Q[ 2 ] - '0') - 1;
                if( !possible( x , y ) ) player = ( player == 'B') ? 'W' : 'B';
                change( x  , y  );
                player = ( player == 'B')?'W':'B';
            }

        }
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                printf("%c" , ady[ i ][ j ] );
            }
            printf("\n");
        }

    }
    return 0;
}
