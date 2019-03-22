/*****************************************
 ***Problema: Number Theory for Newbies
 ***ID: 11371
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 15
int digit[ MAX ] , sz , aux[ MAX ];
void getDigits(long long n ){
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

bool cmp( int a , int b ){
    return a > b;
}

long long ten[] = { 1 , 10 ,100 , 1000 , 10000 , 100000 , 1000000,
                    10000000, 100000000, 1000000000LL , 10000000000LL };
int main(){
    long long num, maxi , mini;
    int i , len , del;
    while( scanf("%lld" , &num ) != EOF ){
        getDigits( num );
        memcpy( aux , digit , sizeof( digit ) );
        maxi = mini = 0;
        sort( digit , digit + sz , cmp );
        del = -1;
        for( i = 0 ; i < sz ; ++i ){
            maxi += ten[ sz - i - 1 ] * digit[ i ];
        }
        sort( aux , aux + sz );
        len = sz - 1;
        for( i = 0 ; i < sz ; ++i ){
            if( aux[ i ] != 0 ){
                mini += ten[ len ] * aux[ i ];
                del = i;
                break;
            }
        }

        for( i = 0 ; i < sz ; ++i ){
            if( del == i ) continue;
            mini += ten[ len - 1  ] * aux[ i ];
            len--;
        }
        printf("%lld - %lld = %lld = 9 * %lld\n" , maxi , mini , maxi - mini , ( maxi - mini ) /9 );
    }

    return 0;
}
