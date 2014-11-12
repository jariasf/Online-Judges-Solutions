/*****************************************
 ***Problema: Counting substhreengs
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 1000005
#define MOD 3
char s[ MAX ];
long long cnt[ MOD ];

long long getCount(){
    long long resp = 0;
    for( int i = 0 ; i < MOD ; ++i )
        resp += ( ( cnt[ i ] * ( cnt[ i ] - 1 ) )/2 );
    resp += cnt[ 0 ];
    return resp;
}

int main(){
    int i, len, sum;
    long long ans;
    while( scanf("%s" , s ) != EOF ){
        len = strlen( s );
        ans = sum = 0;
        memset( cnt , 0 , sizeof(cnt ) );
        for( int i = 0 ; i < len ; ++i ){
            //Sumas parciales sobre digitos
            if( s[i] >= '0' && s[i] <= '9' ){
                sum = ( sum % MOD + (s[i] - '0') % MOD ) % MOD;
                cnt[sum]++;
            }else{
                ans += getCount();
                memset( cnt , 0 , sizeof( cnt ) );
                sum = 0;
            }
        }
        ans += getCount();
        printf("%lld\n" , ans );
    }
    return 0;
}
