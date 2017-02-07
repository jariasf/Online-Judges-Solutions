/*****************************************
 ***Problema: Bridge Hand Evaluator
 ***ID: 462
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


int value[ 256 ], stop[ 256 ];

int main(){
    int tot , t, len;
    char s[ 13 ][ 3 ];

    while( scanf("%s" , &s[ 0 ] ) == 1 ){
        tot = 0;
        t = 12;
        len = 0;
        memset( value , 0 , sizeof( value ) );
        memset( stop , 0 , sizeof( stop ) );
       do{
            if( s[ len ][ 0 ] == 'A') tot += 4;
            else if( s[ len ][ 0 ] == 'K') tot += 3;
            else if( s[ len ][ 0 ] == 'Q') tot += 2;
            else if( s[ len ][ 0 ] == 'J') tot++;
            value[ s[ len ][ 1 ] ]++;
            if( t > 0 )scanf("%s" , &s[ ++len ] );
        }while( t-- );
        for( int i = 0 ; i < 13 ; ++i ){
            if( s[ i ][ 0 ] == 'K' && value[ s[ i ][ 1 ] ] <= 1 ) tot--;
            if( s[ i ][ 0 ] == 'Q' && value[ s[ i ][ 1 ] ] <= 2 ) tot--;
            if( s[ i ][ 0 ] == 'J' && value[ s[ i ][ 1 ] ] <= 3 ) tot--;
            if( s[ i ][ 0 ] == 'A' ) stop[ s[ i ][ 1 ] ] = 1;
            if( s[ i ][ 0 ] == 'K' && value[ s[ i ][ 1 ] ] >= 2 ) stop[ s[ i ][ 1 ] ] = 1;
            if( s[ i ][ 0 ] == 'Q' && value[ s[ i ][ 1 ] ] >= 3 ) stop[ s[ i ][ 1 ] ] = 1;
        }

        int tot2 = tot;
        for( int i = 0 ; i < 4 ; ++ i ){
            if( value[ "SHDC"[ i ] ] == 2 ) tot2++;
            if( value[ "SHDC"[ i ] ] <= 1 ) tot2 += 2;
        }

        int idx = 'S';
        for( int i = 1 ; i < 4 ; ++i ){
            if( value[ "SHDC"[ i ] ] > value[ idx ] ) idx = "SHDC"[ i ];
        }

        if( tot >= 16 && stop[ 'S' ] && stop[ 'H' ] && stop[ 'D' ] && stop[ 'C' ])puts("BID NO-TRUMP");
        else if( tot2 < 14 ) puts("PASS");
        else printf("BID %c\n" , idx );

    }
    return 0;
}
