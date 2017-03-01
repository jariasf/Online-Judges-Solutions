/*****************************************
 ***Problema: Maze Traversal
 ***ID: 10377
 ***Juez: UVA
 ***Tipo: Simulation
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
#define MAX 65
char ady[ MAX ][ MAX ];
int f , c;

//N W S E
int dx[ 4 ] = { -1 ,  0 , 1 , 0 };
int dy[ 4 ] = {  0 , -1 , 0 , 1 };
char commands[ 105 ];
void simulate( int x , int y , int dir ){
    int nx , ny , i;
    char command;
    while( gets( commands ) ){
        for( i = 0 ; commands[ i ] ; ++i ){
            command = commands[ i ];
            if( command == 'R' ) dir = ( dir - 1 + 4 ) % 4;
            else if( command == 'L') dir = ( dir + 1 ) % 4;
            else if( command == 'F' ){
                nx = x + dx[ dir ]; ny = y + dy[ dir ];
                if( nx >= 0 && nx < f && ny >= 0 && ny < c && ady[ nx ][ ny ] != '*' ){
                    x = nx;
                    y = ny;
                }
            }
            else if( command == 'Q' ) break;
        }
        if( command == 'Q') break;
    }
    printf("%d %d %c\n" , x + 1 , y + 1 , ( dir == 0 )?'N': ( dir == 1 )?'W': ( dir == 2 )?'S':'E' );
}

int main(){
    int t , x , y;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &f , &c );
        gets( ady[ 0 ] );
        for( int i = 0 ; i < f ; ++i ){
            gets( ady[ i ] );
        }

        scanf("%d %d" , &x , &y );
        gets( commands );
        simulate( x - 1 , y - 1 , 0 );

        if( t > 0 ) printf("\n");
    }

    return 0;
}
