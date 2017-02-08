/*****************************************
 ***Problema: Compromise
 ***ID: 531
 ***Juez: UVA
 ***Tipo: LCS print path
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
#define MATCH 0
#define INSERT 1
#define DELETE 2
map< string , int > mp;
string v[ MAXN ];
char line[ MAXN ];
int A[ MAXN ] , B[ MAXN ] , lenA , lenB , dp[ MAXN ][ MAXN ] , prev[ MAXN ][ MAXN ];
int MAX( int a , int b , int c ){ return max( a , max( b , c ) ); }

void LCS(){
    int i , j;
    memset( prev , -1 , sizeof( prev ) );
    for( i = 1 ; i <= lenA ; ++i ){
        for( j = 1 ; j <= lenB ; ++j ){
            if( A[ i - 1 ] == B [ j - 1 ] ){
                dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] + 1;
                prev[ i ][ j ] = MATCH;
            }
            else if( dp[ i - 1 ][ j ] > dp[ i ][ j - 1 ] ){
                dp[ i ][ j ] = dp[ i - 1 ][ j ];
                prev[ i ][ j ] = DELETE;
            }
            else{
                dp[ i ][ j ] = dp[ i ][ j - 1 ];
                prev[ i ][ j ] = INSERT;
            }
        }
    }
}

bool first;
void printLCS( int i , int j ){
    if( prev[ i ][ j ] == -1 ) return;
    if( prev[ i ][ j ] == INSERT ){
        printLCS( i , j - 1 );
    }
    if( prev[ i ][ j ] == DELETE ){
        printLCS( i - 1 , j );
    }
    if( prev[ i ][ j ] == MATCH ){
        printLCS( i - 1 , j - 1 );
        if( !first ) printf(" ");
        first = false;
        printf("%s" , v[ A[ i - 1 ] ].c_str() );
    }
}

void solve(){
    LCS();
    first = true;
    printLCS( lenA , lenB );
    printf("\n");
}

int main(){
    int len;
    while( scanf("%s" , &line ) != EOF ){
        len = lenA = lenB =0;
        mp.clear();
        if( line[ 0 ] != '#' ){
            do{
                if( !mp.count( line ) ){
                    A[ lenA ] = len;
                    v[ len ] = line;
                    mp[ line ] = len++;
                }
                else A[ lenA ] = mp[ line ];
                lenA++;
            }while( scanf("%s" , &line ) , line[ 0 ] != '#' );
        }
        scanf("%s" , &line );

        if( line[ 0 ] != '#' ){
            do{
                if( !mp.count( line ) ){
                    B[ lenB ] = len;
                    v[ len ] = line;
                    mp[ line ] = len++;
                }
                else B[ lenB ] = mp[ line ];
                lenB++;
            }while( scanf("%s" , &line ) , line[ 0 ] != '#' );
        }
        solve();
    }
}
