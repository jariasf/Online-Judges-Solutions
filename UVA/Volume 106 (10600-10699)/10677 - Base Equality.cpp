/*****************************************
 ***Problema: Base Equality
 ***ID: 10677
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
int pot( int a , int b ){
    int r = 1;
    for( int i = 1 ; i <= b ; ++i ) r *= a;
    return r;
}
///convierte de base "base" a base 10
int toBase10( string s , int base ){
    int resp = 0, dig;
    for( int i = s.length() - 1 , j = 0 ; i >= 0 ; --i, ++j ){
        if( '0' <= s[ i ] && s[ i ] <= '9' ) dig = s[ i ] - '0';
        else dig = ( s[ i ] - 'A' ) + 10;

        resp += dig * pot( base , j );
    }
    return resp;
}
string toStr(int n){string s;ostringstream buffer;buffer<<n;s=buffer.str();return s;}
int toInt(string str){int n;istringstream buffer(str);buffer>>n;return n;}
string toBaseN( int n , int base ){
    string s = "" , dig;
    while( n > 0 ){
        dig = "";
        if( n % base > 9 ) dig += (char)( ( n % base - 10 ) + 'A');
        else dig +=( char ) ( ( n % base ) + '0' );
        s = dig + s;
        n /= base;
    }
    return s;
}

int main(){
    int t , b1 , i , b2 , r1 , r2, n1 , n2;
    string s;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d %d %d" , &b1  ,&b2 , &r1 , &r2 );
        for( i = r2 - 1 ; i > r1 ; --i ){
            n2 = toBase10( toBaseN( i , b1 ) , b2 );
            if( n2 % i == 0 ){
                printf("%d\n" , i );
                break;
            }
        }
        if( i == r1 )puts("Non-existent.");
    }

    return 0;
}
