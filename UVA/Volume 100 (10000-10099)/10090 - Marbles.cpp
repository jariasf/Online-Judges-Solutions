/*****************************************
 ***Problema: Marbles
 ***ID: 10090
 ***Juez: UVA
 ***Tipo: diophantine equation
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

long long c1 , c2;

/*
  Algoritmo Extendido de Euclides
  ax + by = gcd( a , b ) --- |x| + |y| es minimo
  Retorna el gcd( a , b)
*/

long long extended_euclid( long long a , long long b , long long &x , long long &y ){
    if( b == 0 ){ x = 1; y = 0; return a; }
    long long d = extended_euclid( b , a % b , y , x );
    y -= a/b * x;
    return d;
}

//a%b
long long mod( long long a , long long b ){
    return ( (a % b) + b ) % b;
}

//Calcula una solucion para x e y tal que ax + by = c -> x , y >=0
bool linear_diophantine( long long a , long long b , long long c , long long &x , long long &y ){
    long long d = extended_euclid( a , b , x , y );
    if( c % d ) return false;
    long long x1 = x * c/d , y1 = y * c/d , A = a/d , B = b/d , k;
    x = mod( x1 , B );
    k = ( c - a * x )/b;
    long long mini = 1LL<<62 , X = -1 , Y;
    if( k >= 0 && c1 * x + k * c2 < mini ){
        mini = c1 * x + k * c2;
        X = x; Y = k;
    }
    y = mod( y1 , A );
    k = ( c - b * y )/a;
    if( k >= 0 && c1 * k + y * c2 < mini ){
        X = k; Y = y;
    }
    x = X; y = Y;
    return (x >= 0);
}

int main(){
    long long a , c , b , x , y;
    while( scanf("%lld" , &c ) , c ){
        scanf("%lld %lld %lld %lld" , &c1 , &a , &c2 , &b );
        if( linear_diophantine( a , b , c , x , y ) )printf("%lld %lld\n" , x , y );
        else puts("failed");
    }
    return 0;
}
