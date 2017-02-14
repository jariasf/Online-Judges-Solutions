/*****************************************
 ***Problema: MODEX
 ***ID: 1230
 ***Juez: UVA
 ***Tipo: BigMod
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

long long f( long long x , long long MOD ){
    return x % MOD * x % MOD;
}

long long bigmod( long long a , long long b , long long MOD ){
    if( b == 1 ) return a;
    if( b % 2 == 0 ){
        return f( bigmod( a , b/2 , MOD ) , MOD ) % MOD;
    }
    return a % MOD * bigmod( a , b - 1 , MOD ) % MOD;
}

int main(){
    int t;
    long long  x , y, MOD;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%lld %lld %lld" , &x , &y , &MOD );
        printf("%lld\n" , bigmod( x  , y , MOD ) );
    }
    scanf("%d" , &t );
    return 0;
}
