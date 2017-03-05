/*****************************************
 ***Problema: Play with Floor and Ceil
 ***ID: 10673
 ***Juez: UVA
 ***Tipo: Extended Euclid Algorithm
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

long long extended_euclid( long long a , long long b ,long long &x , long long &y ){
    if( b == 0 ){ x = 1; y = 0; return a; }
    int d = extended_euclid( b , a % b , y , x );
    y -= a/b *x;
    return d;
}

int main(){
    int t;
    scanf("%d" , &t );
    long long x , k ,a , b , y , p ,q;
    while( t-- > 0 && scanf("%lld %lld" , &x , &k ) ){
        a = ( long long )floor( x/(double)k );
        b = ( long long )ceil( x/(double)k );
        x /= extended_euclid( a , b , p , q );
        printf("%lld %lld\n" , p * x , q * x );
    }

    return 0;
}
