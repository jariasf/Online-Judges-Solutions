/*****************************************
 ***Problema: Biorhythms
 ***ID: 756
 ***Juez: UVA
 ***Tipo: Chinese Remainder Theorem
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

int extended_euclid( int a , int b , int &x , int &y ){
    if( b == 0 ){ x = 1; y = 0; return a; }
    int d = extended_euclid( b , a % b , y , x );
    y -= a/b * x;
    return d;
}


int mod( int a , int b ){
    return ( (a % b) + b ) % b;
}

#define pii pair< int , int >
#define mp make_pair
pii chinese_remainder_theorem( int a , int n1 , int b , int n2 ){
    int x , y , d;
    d = extended_euclid( n1 , n2 , x , y );
    if( a % d != b % d ) return mp( 0 , -1 );
    return mp( mod( a * y * n2 + b * x * n1  , n1 * n2  )/d , ( n1 * n2 )/d );
}

//Consideramos mas de 2 ecuaciones
pii chinese_remainder_theorem( vector< int > A , vector< int > N ){
    int i , sz = A.size();
    pii ans = mp( A[ 0 ] , N[ 0 ] );
    for( i = 1 ; i < sz ; ++i ){
        ans = chinese_remainder_theorem( ans.first , ans.second , A[ i ] , N[ i ] );
        if( ans.second == -1 ) break;
    }
    return ans;
}

int A[ 3 ] , N[ 3 ] = { 23 , 28 , 33 };
int main(){
    int day , q = 1 , resp;
    while( scanf("%d %d %d %d" , &A[ 0 ] , &A[ 1 ] , &A[ 2 ] , &day ) != EOF ){
        if( A[ 0 ] == -1 && A[ 1 ] == -1 && A[ 2 ] == -1 )break;
        pii ans = chinese_remainder_theorem( vector< int >( A , A + 3 ) , vector< int >( N , N + 3 ) );
        resp = mod( ans.first - day , 21252 );
        if( resp == 0 ) resp = 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n" , q++ , resp );
    }

    return 0;
}
