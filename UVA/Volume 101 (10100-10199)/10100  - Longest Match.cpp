/*****************************************
 ***Problema: Longest Match
 ***ID: 10100
 ***Juez: UVA
 ***Tipo: LCS
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
#define MAXN 1005
char line[ MAXN ];
int A[ MAXN ] , B[ MAXN ] , lenA , lenB , dp[ MAXN ][ MAXN ];
map< string , int > mp;
bool isLetter( char c ){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
int MAX( int a , int b , int c ){ return max( a , max( b , c ) ); }
int LCS(){
    memset( dp , 0 , sizeof( dp ) );
    int i , j;
    for( i = 1 ; i <= lenA ; ++i )
        for( j = 1 ; j <= lenB ; ++j )
            dp[ i ][ j ] = MAX( dp[ i - 1 ][ j ] , dp[ i ][ j - 1 ] , dp[ i - 1 ][ j - 1 ] + ( A[ i - 1 ] == B[ j - 1 ] ) );
    return dp[ lenA ][ lenB ];
}

int main(){
    map< string , int > :: iterator it;
    int i , blank , q = 1 , len;
    while( gets( line ) ){
        mp.clear();
        blank = len = 0;
        for( i = 0 ; line[ i ] ; ++i ) if( !isLetter( line[ i ] ) && !isdigit( line[ i ] ) ) line[ i ] = ' ';
        if( strlen( line ) == 0 ) blank = 1;
        else{
            stringstream ss( line );
            lenA = 0;
            while( ss>>line ){
                if( !mp.count( line ) ){ mp[ line ] = len++; A[ lenA ] = len - 1; }
                else A[ lenA ] = mp[ line ];
                lenA++;
            }
        }
        gets( line );
        for( i = 0 ; line[ i ] ; ++i ) if( !isLetter( line[ i ] ) && !isdigit( line[ i ] ) ) line[ i ] = ' ';
        if( strlen( line ) == 0 ) blank = 1;
        else{
            lenB = 0;
            stringstream ss( line );
            while( ss>>line ){
                if( !mp.count( line ) ){ mp[ line ] = len++; B[ lenB ] = len - 1; }
                else B[ lenB ] = mp[ line ];
                lenB++;
            }
        }
        printf("%2d. " , q++ );
        if( blank )puts("Blank!");
        else printf("Length of longest match: %d\n" , LCS() );
    }

    return 0;
}
