/*****************************************
 ***Problema: Polly the Polynomial
 ***ID: 498
 ***Juez: UVA
 ***Tipo: Math
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
#define MAX 10005
int c[ MAX ] , x[ MAX ] , len , len_x;
char s[ MAX ];

long long pot( int a , int b ){
    long long r = 1;
    for( int i = 1 ; i <= b ; ++i ) r *= a;
    return r;
}
long long evaluate( int idx ){
    long long s = 0;
    int i;
    for( i = 0 ; i < len ; ++i ){
        s += c[ i ] * pot( x[ idx ] , len - i - 1 );
    }
    return s;
}

int main(){
    int i;
    while( gets( s ) ){
        stringstream ss( s );
        len = 0;
        while( ss>>c[ len++ ] );
        len--;
        gets( s );
        len_x = 0;
        ss.str( std::string() );
        ss.clear();
        ss<<s;
        while( ss>>x[ len_x++ ] );
        len_x--;

        for( i = 0 ; i < len_x ; ++i ){
            if( i ) printf(" ");
            printf("%lld" , evaluate( i ) );
        }
        printf("\n");
    }

    return 0;
}
