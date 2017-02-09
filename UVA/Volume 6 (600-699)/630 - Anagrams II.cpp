/*****************************************
 ***Problema: Anagrams II
 ***ID: 630
 ***Juez: UVA
 ***Tipo: Strings
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

int main(){
    int t , l , n;
    char dictionary[ 1005 ][ 22 ];
    int values[ 1005 ][ 26 ] , v[ 26 ];
    char s[ 22 ];
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        memset( values , 0 , sizeof( values ) );
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%s" , &dictionary[ i ] );
            l = strlen( dictionary[ i ] );
            for( int j = 0 ; j < l ; ++j ){
                values[ i ][ dictionary[ i ][ j ] - 'a' ]++;
            }
        }

        while( scanf("%s" , s ) , s[ 0 ] != 'E' ){
            memset( v , 0 , sizeof( v ) );
            l = strlen( s );
            for( int i = 0 ; i < l ; ++i ){
                v[ s[ i ] - 'a' ]++;
            }

            printf("Anagrams for: %s\n" , s );
            int cnt = 0;
            for( int i = 0 ; i < n ; ++i ){
                int j;
                for( j = 0 ; j < 26 ; ++j ){
                    if( values[ i ][ j ] != v[ j ] ){
                        break;
                    }
                }
                if( j == 26 ){
                    cnt++;
                    printf("%3d) %s\n" , cnt , dictionary[ i ] );
                }
            }
            if( !cnt )printf("No anagrams for: %s\n" , s );

        }
    }

    return 0;
}
