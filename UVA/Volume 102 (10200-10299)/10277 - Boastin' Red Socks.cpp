/*****************************************
 ***Problema:  Boastin' Red Socks
 ***ID: 10277
 ***Juez: UVA
 ***Tipo: Probability + Binary Search
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

//probabilidad condicional
long long num( long long R ){
    return R * ( R - 1 );
}
long long denom( long long R , long long A ){
    return ( R + A ) * ( R + A - 1 );
}
long long gcd( long long a , long long b ){
    if( b == 0 )return a;
    return gcd( b , a % b );
}

int main(){
    int i;
    long long p , q , left , right , mid , A , R , n , d , gc;
    while( scanf("%lld %lld" , &p , &q ) , q | p ){
        if( p == q ){ puts("2 0"); continue; }
        if( p == 0 ){ puts("0 2"); continue; }
        gc = gcd( p , q );
        p /= gc; q /= gc;
        R = A = -1;
        for( i = 2 ; i <= 50000 ; ++i ){
            left = 1; right = i;
            A = -1;
            while( left < right ){
                mid = ( left + right )>>1;
                n = num( i - mid ); d = denom( i - mid , mid );
                if( n * q == p * d ){
                    A = mid;
                    R = i - mid;
                }
                if( n * q <= p * d ){
                    right = mid;
                }
                else left = mid + 1;
            }
            if( A != -1 ) break;
        }
        if( A == -1 ) puts("impossible");
        else printf("%lld %lld\n" , R , A );
    }

    return 0;
}
