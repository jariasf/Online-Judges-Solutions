/*****************************************
 ***Problema: LCM
 ***ID: 10680
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

#define MAX 1000005
int prime[ MAX ] , p[ MAX ] , len;
void sieve(){
    memset( prime , 1 , sizeof( prime ) );
    prime[ 0 ] = 0;
    prime[ 1 ] = 0;

    for(int i = 2 ; i * i <= MAX ; ++i ){
        if( prime[ i ] ){
            for(int k = 2 ; k * i <= MAX ; ++k){
                prime[ k * i ] = 0;
            }
        }
    }
    len = 0;
    for( int i = 2 ; i < MAX ; ++i ) if( prime[ i ] ) p[ len++ ] = i;
}


int main(){
    sieve();
    int n , ceros , dos , cinco, aux , i;
    while( scanf("%d" , &n ) , n ){
        dos = 0;
        aux = n;
        while( aux > 1 ){
            dos++;
            aux /= 2;
        }
        cinco = 0;
        aux = n;
        while( aux > 4 ){
            cinco++;
            aux /= 5;
        }
        //ceros al final de lcm
        ceros = min( dos , cinco ) + 1;
        long long val = 1 , primo;
        for( i = 0 ; i < ceros ; ++i ) val *= 10;
        int ans = 1 , cnt;
        for( i = 0 ; i < len ; ++i ){
            if( p[ i ] > n ) break;
            primo = 1;
            //primos con potencia mas alta
            while( primo * p[ i ] <= n  ){
                primo *= p[ i ];
            }
            ans = (ans % val * primo % val ) % val;
        }
        while( ans > 0 && ans % 10 == 0 ) ans /= 10;
        printf("%d\n" , ans );
    }
    return 0;
}
