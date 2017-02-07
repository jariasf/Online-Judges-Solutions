/*****************************************
 ***Problema: Bank (Not Quite O.C.R.)
 ***ID: 433
 ***Juez: UVA
 ***Tipo: Ad hoc, Brute Force
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
char led[ 10 ][ 9 ] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY",
                        "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN",
                        "YYYYYYY", "YYYYNYY" };

char s1[ 305 ], s2[ 305 ] , s3[ 305 ];
bool possible[ 15 ][ 15 ];
int dif[ 15 ][ 15 ], real[ 15 ];
void toInt(){
    int l = strlen( s1 );

    for( int i = l ; i <= 27 ; ++i ) s1[ i ] = ' ';
    l = strlen( s2 );
    for( int j = l ; j <= 27 ; ++j ) s2[ j ] = ' ';
    l = strlen( s3 );
    for( int i = l ; i <= 27 ; ++i ) s3[ i ] = ' ';
    memset( possible , 0 , sizeof( possible ) );
    memset( real , -1 , sizeof( real ) );
    memset( dif , 0 , sizeof( dif ) );
    for( int i = 0 , k = 0 ; i  < 27 ; i += 3 ){
        for( int j = 0 ; j < 10 ; ++j ){
            if( ( led[ j ][ 0 ] == 'N' && ( s1[ i + 1 ] == '_' )  ) ||
                ( led[ j ][ 1 ] == 'N' && ( s2[ i + 2 ] == '|' ) ) ||
                ( led[ j ][ 2 ] == 'N' && ( s3[ i + 2 ] == '|' ) ) ||
                ( led[ j ][ 3 ] == 'N' && ( s3[ i + 1 ] == '_' ) ) ||
                ( led[ j ][ 4 ] == 'N' && ( s3[ i ] == '|' ) ) ||
                ( led[ j ][ 5 ] == 'N' && ( s2[ i ] == '|' ) ) ||
                ( led[ j ][ 6 ] == 'N' && ( s2[ i + 1 ] == '_') ) ){
                    possible[ k ][ j ] = 0;
            }
            else {
                if( led[ j ][ 0 ] == 'Y' && s1[ i + 1 ] != '_' ) { dif[ k ][ j ]++;}
                if( led[ j ][ 1 ] == 'Y' && s2[ i + 2 ] != '|' ) dif[ k ][ j ]++;
                if( led[ j ][ 2 ] == 'Y' && s3[ i + 2 ] != '|' ) dif[ k ][ j ]++;
                if( led[ j ][ 3 ] == 'Y' && s3[ i + 1 ] != '_' ) dif[ k ][ j ]++;
                if( led[ j ][ 4 ] == 'Y' && s3[ i ] != '|' ) dif[ k ][ j ]++;
                if( led[ j ][ 5 ] == 'Y' && s2[ i ] != '|' ) dif[ k ][ j ]++;
                if( led[ j ][ 6 ] == 'Y' && s2[ i + 1 ] != '_' ) dif[ k ][ j ]++;
                if( dif[ k ][ j ] == 0 ) real[ k ] = j;
                possible[ k ][ j ] = 1;
            }
        }
        k++;
    }
}

int a[ 10 ], len;
bool check(){
    long long ans = 0 ;
    for( int i = 8 , j = 1 ; i >= 0 ; --i , ++j ) ans += a[ i ] * j;
    if( ans % 11 == 0 ) return true;
    return false;
}
int main(){
    int t ,ans , cnt, resp[ 10 ];
    scanf("%d" , &t );
    getchar();

    while( t-- ){

        gets( s1 ); gets( s2 ); gets( s3 );
        toInt();
        bool b = true;
        //caso 1: si el inicial no posee malos, entonces puedo revisar de golpe y dar respuesta
        for( int i = 0 ; i < 9 ; ++i ){
            if( real[ i ] == -1 ){
                b= false;
                break;
            }
            a[ i ] = real[ i ];
        }
        if( b && check() ){
            for( int i = 0 ; i < 9 ; ++i ) printf("%d" , a[ i ] );
            printf("\n");
            continue;
        }

        cnt = 0;
        ans = -1;

        for( int i = 0 ; i < 9 ; ++i ){
            len = 0;

            b = true;
            for( int j = 0 ; j < i ; ++j ) {
                if( real[ j ] == -1 ){ b = false; break;}
                a[ len++ ] = real[ j ];
            }
            if( !b )break;
            //caso 2: solo puedo tener uno malo de todos
            for( int j = 0 ; j < 10 ; ++j ){
                if( possible[ i ][ j ] ){
                    a[ len ] = j;
                    for( int k = i + 1 , q = len + 1 ; k < 9 ; ++k , q++ ){
                        if( real[ k ] == -1 ){ b = false; break;}
                        a[ q ] = real[ k ];
                    }
                    if( !b ) break;
                    else if( check() ){
                        cnt++;
                        if( cnt > 1 ){
                            i = 9;
                            break;
                        }

                    for( int q = 0 ; q < 9 ; ++q ) resp[ q ] = a[ q ];
                       break;
                    }
                }

            }
        }
        if( cnt > 1 ) puts("ambiguous");
        else if( cnt == 1 ){
            for( int i = 0 ; i < 9 ; ++i ) printf("%d" , resp[ i ] );
            printf("\n");
        }
        else puts("failure");
    }
    return 0;
}
