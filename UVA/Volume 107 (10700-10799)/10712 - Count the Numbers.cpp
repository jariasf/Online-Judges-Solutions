/*****************************************
 ***Problema: Count the Numbers
 ***ID: 10712
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
#define MAX 11
int digit[ MAX ] , sz , sz2;
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

char D[ 4 ];
long long dp[ MAX ][ 2 ][ 3 ][ 2 ][ 2 ];
map< long long , bool > seen;
long long solve( int len , int flag , int len2 , bool correct , string s , bool cero , long long num  ){
    if( len == sz ){
        if( correct && !seen[ num ] ){
            seen[ num ] = 1;
            return 1;
        }
        return 0;
    }
    if( dp[ len ][ flag ][ len2 ][ correct ][ cero ] != -1 ) 
		return dp[ len ][ flag ][ len2 ][ correct ][ cero ];
    int maxDigit = digit[ len ] , i , aux;
    if( flag ) maxDigit = 9;
    long long ans = 0;
    for( i = 0 ; i <= maxDigit ; ++i ){
        bool new_cero = cero;
        if( cero ){
            if( i > 0 )
                new_cero = false;
        }
        bool aux = correct;
        if( len2 == sz2  ){
            ans += solve( len + 1 , flag | ( ( i < digit[ len ] )?1:0 ) , len2 , true,
						 s + " " + (char)(i + '0' ) , new_cero , num * 10 + i ) ;
        }
        else if( len2 < sz2 && D[ len2 ] - '0' == i && !new_cero){
            if( len2 + 1 == sz2 )
                aux = true;
            else{
                ans += solve( len + 1 , flag | ( ( i < digit[ len ] )?1:0 ) , 0 , false, 
							s  + " " + (char)( i + '0' ) , new_cero , num * 10 + i ) ;
            }
            ans += solve( len + 1 , flag | ( ( i < digit[ len ] )?1:0 ) , len2 + 1 , aux, 
						s + " " + D[ len2 ] , new_cero , num * 10 + i) ;
        }
        else ans += solve( len + 1 , flag | ( ( i < digit[ len ] )?1:0 ) , 0 , false, 
							s  + " " + (char)(i + '0' ) , new_cero , num * 10 + i ) ;
    }
    return dp[ len ][ flag ][ len2 ][ correct ][ cero ] = ans;
}

int main(){
    int A , B;
    long long ans;
    while( scanf("%d %d %s" , &A , &B , D ) , A > -1 ){
        sz2 = strlen( D );
        getDigits( B );
        memset( dp , -1 , sizeof( dp ) );
        seen.clear();
        ans = solve( 0 , 0 , 0 , 0 , " " , 1 , 0 );
        if( A == 0 && D[ 0 ] == '0' ) ans++;
        getDigits( A  - 1 );
        memset( dp , -1, sizeof( dp ) );
        seen.clear();
        ans -= solve( 0 , 0 , 0 , 0 , " " , 1 , 0 );
        printf("%lld\n" , ans );
    }

    return 0;
}
