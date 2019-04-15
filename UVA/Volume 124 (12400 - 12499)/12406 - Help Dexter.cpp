/*****************************************
 ***Problema: Help Dexter
 ***ID: 12406
 ***Juez: UVA
 ***Tipo: Bitwise - Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 18
vector< long long > val[ MAX ];
void gen( long long x , int len ){
    if( len > 17 ) return;
    val[ len ].push_back( x );
    gen( x * 10 + 1 , len + 1 );
    gen( x * 10 + 2 , len + 1 );
}

int main(){

    gen( 0 , 0 );
    int Q , t , p , q , i;
    long long mini , maxi;
    scanf("%d" , &t );
    for( Q = 1 ; Q <= t && scanf("%d %d" , &p , &q ) ; ++Q ){
        mini = 1LL<<61; maxi = -1;
        for( i = 0 ; i < val[ p ].size() ; ++i ){
            if( val[ p ][ i ] % ( 1<<q ) == 0 ){
                mini = min( mini , val[ p ][ i ] );
                maxi = max( maxi , val[ p ][ i ] );
            }
        }
        printf("Case %d: " , Q );
        if( mini == 1LL<<61 ) puts("impossible");
        else{
            if( mini == maxi ) printf("%lld\n" , mini );
            else printf("%lld %lld\n" , mini , maxi );
        }
    }

    return 0;
}

int main(){
    int t , Q , i , j , p , q;
    long long mini , maxi , num;
    scanf("%d" , &t );
    for( Q = 1 ; Q <= t && scanf("%d %d" , &p , &q ) ; ++Q ){
        mini = 1LL<<61; maxi = -1;
        for( i = 0 ; i < 1<<p ; ++i ){
            num = 0;
            for( j = 0 ; j < p ; ++j ){
                if( i & ( 1<<j ) ) num = num * 10 + 2;
                else num = num * 10 + 1;
            }
            if( num % ( 1<<q ) == 0 ){
                mini = std::min( mini , num );
                maxi = std::max( maxi , num );
            }
        }
        printf("Case %d: " , Q );
        if( mini == 1LL<<61 ) puts("impossible");
        else{
            if( mini == maxi ) printf("%lld\n" , mini );
            else printf("%lld %lld\n" , mini , maxi );
        }
    }
    return 0;
}
