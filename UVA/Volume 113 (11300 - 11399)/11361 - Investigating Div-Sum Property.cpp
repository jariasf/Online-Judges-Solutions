/*****************************************
 ***Problema: Investigating Div-Sum Property
 ***ID: 11361
 ***Juez: UVA
 ***Tipo: DP
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
#define MAX 10
int digit[ MAX ] , sz;
void getDigits( long long n ){
    sz = 0;
    int digitInv[ MAX ] , i , j;
    while( n > 0 ){
        digitInv[ sz++ ] = n % 10;
        n /= 10;
    }
    for( i = sz - 1 , j = 0 ; i >= 0 ; --i , ++j ){
        digit[ j ] = digitInv[ i ];
    }
}

long long dp[ MAX ][ 2 ][ 85 ][ 85 ] , A , B , MOD;
long long solve( int len , int flag , int sum , int num  ){
    if( len == sz ){
        if( sum == 0 && num == 0 ) return 1;
        return 0;
    }
    if( dp[ len ][ flag ][ sum ][ num ] != -1 ) return dp[ len ][ flag ][ sum ][ num ];
    int maxDigit = digit[ len ] , i , aux;
    if( flag ) maxDigit = 9;
    long long ans = 0;
    for( i = 0 ; i <= maxDigit ; ++i ){
        ans += solve( len + 1 , flag | ( ( i < digit[ len ] )?1:0 ) , ( sum % MOD + i % MOD ) % MOD , ( ( num * 10 ) % MOD + i % MOD ) % MOD ) ;
    }
    return dp[ len ][ flag ][ sum ][ num ] = ans;
}
int main(){

    int t;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%lld %lld %lld" , &A , &B , &MOD ) ){
        if( MOD > 85 ){
            puts("0");
            continue;
        }
        memset( dp , -1 , sizeof( dp ) );
        getDigits( B );
        long long ans = solve( 0 , 0 , 0 , 0 );
        memset( dp , -1 , sizeof( dp ) );
        getDigits( A - 1 );
        ans -= solve( 0 , 0 ,0 , 0 );
        printf("%lld\n" , ans );
    }

    return 0;
}
