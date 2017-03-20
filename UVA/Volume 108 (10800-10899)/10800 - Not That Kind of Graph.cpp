/*****************************************
 ***Problema: Not That Kind of Graph
 ***ID: 10800
 ***Juez: UVA
 ***Tipo: String Output
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
#define MAX 200
#define R 0
#define F 1
#define C 2
char c[] = { '/' , '\\' , '_' };
int dx[] = { -1 , 1 , 0 };
int dy[] = {  1 , 1 , 1 };
char s[ MAX ] , ady[ MAX ][ MAX ];

int main(){
    int t , q , x , y , maxX , maxY , i , idx , j , k , minX;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%s" , &s ) ; ++q ){

        for( i = 0 ; i < MAX ; ++i )
            for( j = 0 ; j < MAX ; ++j )
                ady[ i ][ j ] = ' ';

        x = MAX/2 - 2; y = 2; minX = x; maxY = 1; maxX = x;

        for( i = 0 ; s[ i ] ; ++i ){
            if( s[ i ] == 'R' ) idx = R;
            else if( s[ i ] == 'F' ) idx = F;
            else idx = C;
            if( idx == F ) ady[ x + 1 ][ y ] = c[ idx ];
            else ady[ x ][ y ] = c[ idx ];
            x += dx[ idx ]; y += dy[ idx ];
            maxX = max( maxX , x );
            minX = min( minX , x );
            maxY = max( maxY , y );
        }
        maxX++;
        printf("Case #%d:\n" , q );

        string str;
        for( i = minX ; i <= maxX ; ++i ){
            str = "";
            for( j = 0 ; j < maxY ; ++j){
                if( j == 0 ){
                    if( i < maxX ) str += "|";
                    else str += "+";
                }
                else{
                    if( i == maxX  ) str +="-";
                    else str += ady[ i ][ j ];
                }
            }
            if( i == maxX  ) str += "-";

            //Remove last espaces
            for( j = str.size() - 1 ; j >= 0 ; --j )
               if( str[ j ] != ' ') break;

            if( str[ j ] == '|' ) continue;
            for( k = 0 ; k <= j ; ++k ) printf("%c" , str[ k ] );
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
