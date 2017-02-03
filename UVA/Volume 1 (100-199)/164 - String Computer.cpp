/*****************************************
 ***Problema: String Computer
 ***ID: 164
 ***Juez: UVA
 ***Tipo: Edit Distance - Impresion
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

#define MAX 50
#define INSERT 0
#define DELETE 1
#define CHANGE 3
#define MATCH 4
char A[ MAX ], B[ MAX ];
int lenA , lenB , dp[ MAX ][ MAX ] , prev[ MAX ][ MAX ], k;

void editDistance(){
    lenA = strlen( A );
    lenB = strlen( B );
    int i , j;

    for( i = 0 ; i <= lenA ; ++i ){
        dp[ i ][ 0 ] = i;
        prev[ i ][ 0 ] = DELETE;
    }
    for( i = 0 ; i <= lenB ; ++i ){
        dp[ 0 ][ i ] = i;
        prev[ 0 ][ i ] = INSERT;
    }

    for( i = 1 ; i <= lenA ; ++i ){
        for( j = 1 ; j <= lenB ; ++j ){
            if( A[ i - 1 ] == B[ j - 1 ] ){
                dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ];
                prev[ i ][ j ] = MATCH;
            }
            else if( dp[ i - 1 ][ j ] > dp[ i ][ j - 1 ] && dp[ i - 1 ][ j - 1 ] > dp[ i ][ j - 1 ] ){
                dp[ i ][ j ] = dp[ i ][ j - 1 ] + 1;
                prev[ i ][ j ] = INSERT;
            }
            else if( dp[ i - 1 ][ j ] > dp[ i - 1 ][ j - 1 ]){
                dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] + 1;
                prev[ i ][ j ] = CHANGE;
            }
            else{
                dp[ i ][ j ] = dp[ i - 1 ][ j ] + 1;
                prev[ i ][ j ] = DELETE;
            }
        }
    }
}

void printEditDistance( int i , int j ){
    if( !i && !j ) return;
    if( prev[ i ][ j ] == MATCH ){
        printEditDistance( i - 1 , j - 1 );
        return;
    }
    if( prev[ i ][ j ] == INSERT ){
        printEditDistance( i , j - 1 );
        printf("I%c%02d" , B[ j - 1 ] , j );
        k--;
    }
    if( prev[ i ][ j ] == DELETE ){
        printEditDistance( i - 1 , j );
        printf("D%c%02d" , A[ i - 1 ] , i - k );
        k++;
    }
    if( prev[ i ][ j ] == CHANGE ){
        printEditDistance( i - 1 , j - 1 );
        printf("C%c%02d" , B[ j - 1 ] , j );
    }
}

int main(){
    while( scanf("%s" , &A ) , A[ 0 ] != '#' ){
        scanf("%s" , &B );
        editDistance();
        k = 0;
        printEditDistance( lenA , lenB );
        printf("E\n");
    }
    return 0;
}
