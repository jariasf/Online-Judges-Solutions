/*****************************************
 ***Problema: The Super Powers
 ***ID: 11752
 ***Juez: UVA
 ***Tipo: Primes
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
#define MAX 65550
int prime[ MAX ] , len;
long long p[ MAX ];
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
    for( int i = 2 ; i <= MAX ; ++i ) if( prime[ i ] ) p[ len++ ] = i;
}

unsigned long long pot( unsigned long long a, unsigned long long b){
	if(!b)
		return 1;
	if(b&1)
		return a*pot(a*a,b>>1); 
	else return pot(a*a,b>>1);
}

int main(){
    sieve();
    set< unsigned long long > ans;
    int i , j , sz = 0;
    for( i = 2 ; i < MAX ; ++i ){
        for( j = 4 ; j <= 63; ++j ){
            if( !prime[ j ] ){
                if( j * log( i ) < 64 * log( 2 ) ) ans.insert( pot(i , j ) );
                else break;
            }
        }
    }
    printf("1\n");
    for( set< unsigned long long > :: iterator it = ans.begin() ; it != ans.end() ; ++it ) printf("%llu\n" , *it );
    return 0;
}
