/*****************************************
 ***Problema: Da Vinci Code
 ***ID: 11385
 ***Juez: UVA
 ***Tipo: Fibonacci Numbers + String
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
#define MAXF 46
#define MAX 105
int fib[ MAXF ] , a[ MAX ];
char s[ MAX ] , ans[ MAX ];
bool isLetter(char c){return c>='A' && c<='Z';}
int main(){
    map< int , int > mp;
    int t , n , i , k , maxi;
    fib[ 1 ] = 1;
    fib[ 2 ] = 2;
    mp[ 2 ] = 2;
    mp[ 1 ] = 1;
    for( i = 3 ; i < MAXF ; ++i ){
        fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
        mp[ fib[ i ] ] = i;
    }

    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        for( i = 0 ; i < n && scanf("%d" , &a[ i ] ) ; ++i );
        for( i = 0 ;i < MAXF ; ++i ) ans[ i ] = ' ';
        gets( s );
        gets( s );
        maxi = 0;
        for( i = 0 , k = 0 ; s[ i ] && k < n; ++i ){
            if( isLetter( s[ i ] ) ){
                ans[ mp[ a[ k++ ] ] - 1 ] = s[ i ];
                maxi = max( maxi , mp[ a[ k - 1 ] ] );
            }
        }
        ans[ maxi ] = '\0';
        printf("%s\n" , ans );
    }

    return 0;
}
