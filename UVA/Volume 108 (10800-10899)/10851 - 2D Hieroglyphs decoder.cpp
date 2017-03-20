/*****************************************
 ***Problema: 2D Hieroglyphs decoder
 ***ID: 10851
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
#define MAX 100
#define ASCII 122
char ady[ MAX ][ MAX ];
int main(){
    int t , i , M , k  , j , c;
    scanf("%d" , &t );
    while( t-- > 0 ){
        for( i = 0 ; i < 10 && scanf("%s" , ady[ i ] ) ; ++i );
        M = strlen( ady[ 0 ]) ;

        for( j = 1 ; j < M - 1 ; ++j ){
            for( i = 8 , c = 0  ; i > 0 ; --i ){
                if( ady[ i ][ j ] == '/') c <<=1;
                else c = ( c<<1 ) | 1;
            }
            putchar( c );
        }
        printf("\n");
    }
    return 0;
}
