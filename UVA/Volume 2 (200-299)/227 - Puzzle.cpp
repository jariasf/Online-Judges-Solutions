/*****************************************
 ***Problema: Puzzle
 ***ID: 227
 ***Juez: UVA
 ***Tipo: Ad hoc , simulation
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

//down , up , right , left
int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };

int main(){
    char ady[ 5 ][ 5 ];
    char s[ 505 ] , ss[ 105 ];
    bool illegal;
    char C;
    int x , y , len , nx , ny , q = 0;
    while( gets( ady[ 0 ] ) && ady[ 0 ][ 0 ] != 'Z' ){
        if( q ){
            gets( ady[ 0 ] );
            if( ady[ 0 ][ 0 ] == 'Z')break;
            printf("\n");
        }

        for( int i = 1 ; i < 5 ; ++i ) gets( ady[ i ] );
        s[ 0 ] = '\0';
        while( scanf("%s" , &ss ) ){
            strcat( s , ss );
            if( ss[ strlen( ss ) - 1 ] == '0')break;
        }

        len = strlen( s );
        for( int i = 0 ; i < 5 ; ++i ){
            for( int j = 0 ; j < 5 ; ++ j ){
                if( ady[ i ][ j ] == ' '){
                    x = i; y = j;
                    i = 5;
                    break;
                }
            }
        }
        illegal = false;
        for( int i = 0 ; i < len ; ++i ){
            if( s[ i ] == '0' )break;
            if( s[ i ] == 'A'){
                nx = dx[ 1 ] + x; ny = dy[ 1 ] + y;
                if( nx >= 0 && ny >= 0 && nx < 5 && ny < 5 ){
                    char tmp = ady[ nx ][ ny ];
                    ady[ nx ][ ny ] = ady[ x ][ y ];
                    ady[ x ][ y ] = tmp;
                    x = nx; y = ny;
                }
                else{
                    illegal = true;
                    break;
                }
            }
            else if( s[ i ] == 'B'){
                nx = dx[ 0 ] + x; ny = dy[ 0 ] + y;
                if( nx >= 0 && ny >= 0 && nx < 5 && ny < 5 ){
                    char tmp = ady[ nx ][ ny ];
                    ady[ nx ][ ny ] = ady[ x ][ y ];
                    ady[ x ][ y ] = tmp;
                    x = nx; y = ny;
                }
                else{
                    illegal = true;
                    break;
                }
            }
            else if( s[ i ] == 'L'){
                nx = dx[ 3 ] + x; ny = dy[ 3 ] + y;
                if( nx >= 0 && ny >= 0 && nx < 5 && ny < 5 ){
                    char tmp = ady[ nx ][ ny ];
                    ady[ nx ][ ny ] = ady[ x ][ y ];
                    ady[ x ][ y ] = tmp;
                    x = nx; y = ny;
                }
                else{
                    illegal = true;
                    break;
                }
            }
            else if( s[ i ] == 'R'){
                nx = dx[ 2 ] + x; ny = dy[ 2 ] + y;
                if( nx >= 0 && ny >= 0 && nx < 5 && ny < 5 ){
                    char tmp = ady[ nx ][ ny ];
                    ady[ nx ][ ny ] = ady[ x ][ y ];
                    ady[ x ][ y ] = tmp;
                    x = nx; y = ny;
                }
                else{
                    illegal = true;
                    break;
                }
            }
        }
        printf("Puzzle #%d:\n" , ++q );
        if( illegal )puts("This puzzle has no final configuration.");
        else{

            for( int i = 0 ; i < 5 ; ++i ){
                for( int j = 0 ; j < 5 ; ++j ){
                    if( j == 0 )printf("%c" , ady[ i ][ j ] );
                    else printf(" %c" , ady[ i ][ j ] );
                }
                printf("\n");
            }
        }
    }

    return 0;
}
