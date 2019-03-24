/*****************************************
 ***Problema: Letter Frequency
 ***ID: 11577
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
#define MAX 300
char s[ MAX ];
int cnt[ 27 ];
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}

int main(){
    int t , i , maxi;
    scanf("%d" , &t );
    getchar();
    while( t-- > 0 && gets( s ) ){
        memset( cnt , 0 ,sizeof( cnt ) );
        for( i = 0 ; s[ i ] ; ++i ) if( isLetter( s[ i ] ) ) s[ i ] = tolower( s[ i ] );
        for( i = 0 ; s[ i ] ; ++i )
            if( s[ i ] >= 'a' && s[ i ] <= 'z' ) cnt[ s[ i ] - 'a' ]++;
        maxi = 0;
        for( i = 0 ; i < 26 ; ++i ) maxi = max( maxi , cnt[ i ] );

        for( i = 0 ; i < 26 ; ++i ){
            if( cnt[ i ] == maxi ) printf("%c" , i + 'a' );
        }
        printf("\n");
    }

    return 0;
}
