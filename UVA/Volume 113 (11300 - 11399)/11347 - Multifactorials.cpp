/*****************************************
 ***Problema: Multifactorials
 ***ID: 11347
 ***Juez: UVA
 ***Tipo: Prime Factorization
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
#define MAX 30
const long long LIMIT = 1000000000000000000LL;
char s[ MAX ];
map< int , int > f;
void getF( int n ){
    for( int i = 2 ; i * i <= n ; ++i ){
        while( n % i == 0 ){
            n /= i;
            f[ i ]++;
        }
    }
    if( n > 1 ) f[ n ]++;
}

int main(){
    int t , q , num , k , i;
    long long ans;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%s" , s ) ; ++q ){
        num = 0;
        for( i = 0 ; s[ i ] ; ++i ){
            if( s[ i ] >= '0' && s[ i ] <= '9' ) num = num * 10 + s[ i ] - '0';
            else break;
        }
        k = 0;
        for( ; s[ i ] ; ++i ) k++;
        int end = k;
        if( num % k != 0 ) end = num % k;
        f.clear();
        for( i = end ; i <= num ; i += k ) getF( i );
        map< int , int > :: iterator it;
        ans = 1;
        for( it = f.begin() ; it != f.end() ; ++it ){
            ans *= ( it -> second + 1 );
            if( ans > LIMIT ) break;
        }
        printf("Case %d: ", q );
        if( ans > LIMIT ) puts("Infinity");
        else printf("%lld\n" , ans );

    }

    return 0;
}
