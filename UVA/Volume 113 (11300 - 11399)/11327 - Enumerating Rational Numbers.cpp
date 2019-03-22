/*****************************************
 ***Problema: Enumerating Rational Numbers
 ***ID: 11327
 ***Juez: UVA
 ***Tipo: Euler Totient
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
#define MAX 200005
#define NMAX 447 //sqrt(MAX)
int phi[MAX + 2];
long long sum[ MAX ];
void euler()
{
    memset(phi, 0, sizeof(phi));
    for (int i = 2; i <= NMAX; i++) {
        if (phi[i] != 0) continue;
        for (int j = i*i; j <= MAX; j += i)
            phi[j] = i;
    }

    phi[0] = 0;
    phi[1] = 1;
    sum[ 0 ] = 1;
    sum[ 1 ] = 2;
    for (int i = 2; i <= MAX; i++) {
        if (phi[i] == 0) { phi[i] = i-1; sum[ i ] = sum[ i - 1 ] + phi[ i ]; continue; }
        int d = phi[i], f1 = i, f2 = 1;
        while ((f1 % d) == 0) { f1 /= d; f2 *= d; }

        if (f1 > 1)
            phi[i] = phi[f1] * phi[f2];
        else
            phi[i] = (i / d) * (d - 1); //totient function ejemplo 4 = 2^2 = 4 * (1-1/2) = 4/2*(2-1)
        sum[ i ] = sum[ i - 1 ] + phi[ i ];
    }
}
long long gcd( long long a , long long b ){
    if( b == 0 )return a;
    return gcd( b , a % b );
}

int main(){
    euler();
    int i;
    long long n , left , right , mid , ans , falta;
    while( scanf("%lld" , &n ) , n ){
        if( n == 1 ){ puts("0/1"); continue; }
        left = 0; right = MAX;
        while( left < right ){
            mid = ( left + right )>>1LL;
            if( sum[ mid ] >= n ) right = mid;
            else left = mid + 1;
        }
        falta = n - sum[ right - 1 ];

        //Imprimimos el primo relativo en la posicion
        for( i = 1 ; i <= right && falta > 0 ; ++i ){
            if( gcd( right , i ) == 1 ){ falta--;}
        }
        printf("%d/%d\n" , i - 1 , right );
    }

    return 0;
}
