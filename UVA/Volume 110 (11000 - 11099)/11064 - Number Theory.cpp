/*****************************************
 ***Problema: Number Theory
 ***ID: 11064
 ***Juez: UVA
 ***Tipo: Euler Totient - Num Divisors
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

long long countRelativelyPrime( long long n ) {
	long long sum = n, i;
	for( i = 2 ; i * i <= n ; ++i ) {
		if( n % i == 0 ) {
			sum -= sum/i;
		}
		while( n % i == 0 ) n /= i;
	}
	if( n > 1 ) sum -= sum/n;
	return sum;
}

long long numDivisors( long long n ){
    long long i , ans = 1 , cnt;
    for( i = 2 ; i * i <= n ; ++i ){
        cnt = 0;
        while( n % i == 0 ){
            n /= i;
            cnt++;
        }
        ans *= ( cnt + 1 );
    }
    if( n > 1 ) ans *= 2;
    return ans - 1;
}

int main(){
    long long n;
    while( scanf("%lld" , &n ) != EOF ){
        printf("%lld\n" , n - countRelativelyPrime( n ) - numDivisors( n ) );
    }
    return 0;
}
