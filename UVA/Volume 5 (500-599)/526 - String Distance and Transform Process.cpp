/**************************************************
 ***Problema: String Distance and Transform Process
 ***ID: 526
 ***Juez: UVA
 ***Tipo: Edit Distance - Print The Path
 ***Autor: Jhosimar George Arias Figueroa
 **************************************************/

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

#define MAX 90
#define INSERT 0
#define DELETE 1
#define CHANGE 2
#define MATCH 3
char A[ MAX ], B[ MAX ];
int lenA , lenB , dp[ MAX ][ MAX ] , prev[ MAX ][ MAX ];

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
int len, k;
void printEditDistance( int i , int j ){
    if( !i && !j ) return;
    if( prev[ i ][ j ] == MATCH ){
        printEditDistance( i - 1 , j - 1 );
        return;
    }
    if( prev[ i ][ j ] == INSERT ){
        printEditDistance( i , j - 1 );
        printf("%d Insert %d,%c\n" , len++ , j , B[ j - 1 ] );
        k--;
    }
    if( prev[ i ][ j ] == DELETE ){
        printEditDistance( i - 1 , j );
        printf("%d Delete %d\n" , len++ , i - k );
        k++;
    }
    if( prev[ i ][ j ] == CHANGE ){
        printEditDistance( i - 1 , j - 1 );
        printf("%d Replace %d,%c\n" , len++ , j ,  B[ j - 1 ] );
    }
}

int main(){
    bool b = false;
    while( gets( A ) ){
        gets( B );
        if( b ) printf("\n");
        b = true;
        editDistance();
        printf("%d\n" , dp[ lenA ][ lenB ] );
        len = 1;
        k = 0;
        printEditDistance( lenA , lenB );
    }
    return 0;
}
