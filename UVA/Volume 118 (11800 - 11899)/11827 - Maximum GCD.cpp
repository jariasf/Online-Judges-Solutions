/*****************************************
 ***Problema: Maximum GCD
 ***ID: 11827
 ***Juez: UVA
 ***Tipo: Number Theory, GCD
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

int gcd(int a , int b){
   return  (b == 0 )? a:gcd( b , a % b );
}

int main(){

    int t, ans, x , a[ 105 ], len , g;
    char s[ 100005 ];
    scanf("%d\n" , &t );
    while( t-- ){

        len = 0;
        gets( s );
        int l = strlen( s );
        s[ l++ ] = ' ';
        s[ l ] = '\0';
        stringstream ss( s );
        while( ss>> x ){
            a[ len++ ] = x;
        }

        ans = 1;
        for( int i = 0 ; i < len ; ++i ){
            for( int j = i + 1 ; j < len ; ++j ){
                g = gcd( a[ i ] , a[ j ] );
                if( ans < g ) ans = g;
            }
        }
        printf("%d\n" , ans);
    }

    return 0;
}
