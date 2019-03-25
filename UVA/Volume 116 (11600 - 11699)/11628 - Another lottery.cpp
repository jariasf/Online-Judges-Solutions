/*****************************************
 ***Problema: Another lottery
 ***ID: 11628
 ***Juez: UVA
 ***Tipo: Probability
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

long long gcd( long long a , long long b ){
    if( b == 0 )return a;
    return gcd( b , a % b );
}

long long ady[ 10005 ][ 31 ];
int main(){

    int n , m , i , j;
    long long sum , gc;
    while( scanf("%d %d" , &n , &m ) , n | m ){
        sum = 0;
        for( i = 0 ; i < n ; ++i )
            for( j = 0 ; j < m && scanf("%lld" , &ady[ i ][ j ] ) ; ++j ) if( j == m - 1 ) sum += ady[ i ][ j ];

        for( i = 0 ; i < n ; ++i ){
            if( !ady[ i ][ m - 1 ] ){ puts("0 / 1"); continue; }
            gc = gcd( sum , ady[ i ][ m - 1 ] );
            printf("%lld / %lld\n" , ady[ i ][ m - 1 ]/gc , sum/gc );
        }
    }

    return 0;
}
