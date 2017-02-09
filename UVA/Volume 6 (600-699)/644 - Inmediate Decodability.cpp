/*****************************************
 ***Problema: Inmediate Decodability
 ***ID: 644
 ***Juez: UVA
 ***Tipo: Ad hoc
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
char code[ 10 ][ 15 ];
int len;

bool isPrefix( char *s1 , char *s2 ){
    int l1 = strlen( s1 ) , l2 = strlen( s2 ), lon = min( l1 , l2 );
    for( int i = 0 ; i < lon ; ++i ){
        if( s1[ i ] != s2[ i ] )return false;
    }
    return true;
}

bool Solve(){
    for( int i = 0 ; i < len ; ++i ){
        for( int j = 0 ; j < len ; ++j ){
            if( i == j )continue;
            if( isPrefix( code[ i ] , code[ j ] ) ){
                return false;
            }
        }
    }
    return true;
}

int main(){

    len = 0;
    int q = 1;
    while( scanf("%s" , code[ len ] ) != EOF ){
        while( 1 ){
            if( code[ len ][ 0 ] == '9' )break;
            scanf("%s" , code[ ++len ] );
        }
        printf("Set %d " , q++ );

        if( Solve() ){
            printf("is immediately decodable\n");
        }
        else printf("is not immediately decodable\n");

        len = 0;
    }

    return 0;
}
