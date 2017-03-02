/*****************************************
 ***Problema: Divisibility of Factors
 ***ID: 10484
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

map< long long , int > getFactors( long long n , bool factorial ){
    long long i;
    map< long long , int > f;
    if( !factorial ){
        for( i = 2 ; i * i <= n ; ++i ){
            while( n % i == 0 ){
                n /= i;
                f[ i ]++;
            }
        }
        if( n > 1 ) f[ n ]++;
    }
    else{
        long long aux = n;
        int j;
        for( j = 2 ; j <= aux ; ++j ){
            n = j;
            for( i = 2 ; i * i <= n ; ++i ){
                while( n % i == 0 ){
                    n /= i;
                    f[ i ]++;
                }
            }
            if( n > 1 ) f[ n ]++;
        }
    }
    return f;
}

int main(){
    int n;
    long long d , ans;
    map< long long , int > fN , fD;
    map< long long , int > :: iterator it;
    bool possible;
    while( scanf("%d %lld" , &n , &d ) , n + d > 0 ){
        fN = getFactors( n , true );
        fD = getFactors( d , false );
        possible = true;
        for( it = fD.begin() ; it != fD.end() ; ++it ){
            if( fN[ it -> first ] < it -> second ){ possible = false; break; }
            fN[ it -> first ] -= it -> second;
        }
        if( !possible ) puts("0");
        else{
            ans = 1;
            for( it = fN.begin() ; it != fN.end() ; ++it ) ans *= ( it -> second + 1 );
            printf("%lld\n" , ans );
        }
    }

    return 0;
}
