/*****************************************
 ***Problema: Counting ones
 ***ID: 12670
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 64
int digit[ MAX ] , sz;
void getDigits( long long n ){
    sz = 0;
    int digitInv[ MAX ] , i , j;
    while( n > 0 ){
        digitInv[ sz++ ] = n % 2;
        n /= 2;
    }

    for( i = sz - 1 , j = 0 ; i >= 0 ; --i , ++j ){
        digit[ j ] = digitInv[ i ];
    }
}

long long dp[ MAX ][ 2 ][ MAX ];
long long solve( int len , int flag , int ones ){
    if( len == sz ){
        return ones;
    }
    if( dp[ len ][ flag ][ ones ] != -1 ) return dp[ len ][ flag ][ ones ];
    int maxDigit = digit[ len ] , i , aux;
    if( flag ) maxDigit = 1;
    long long ans = 0;
    for( i = 0 ; i <= maxDigit ; ++i ){
        ans += solve( len + 1 , flag | ( ( i < digit[ len ] )?1:0 ) , ones + i );
    }
    dp[ len ][flag ][ ones ] = ans;
    return ans;
}

int main(){
    long long A , B , ans;
    while( scanf("%lld %lld" , &A , &B ) != EOF ){
        getDigits(B);
        memset( dp , -1 , sizeof(dp) );
        ans = solve( 0 , 0  , 0);
        getDigits(A - 1);
        memset( dp , -1 , sizeof(dp) );
        ans -= solve( 0 , 0 , 0);
        printf("%lld\n" ,  ans );
    }
    return 0;
}
