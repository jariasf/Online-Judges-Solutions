/*****************************************
 ***Problema: Dromicpalin Substrings
 ***ID: 12718
 ***Juez: UVA
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 26
#define MAXN 1005
int cnt[ MAX ];
char s[ MAXN ];
bool isDromicPalin(int len){
    int odd = 0;
    for( int i = 0 ; i < MAX ; ++i ){
        if( len & 1 ){
           if( cnt[ i ] & 1 )
                odd++;
           if( odd > 1 )
            return false;
        }else{
            if( cnt[ i ] & 1 )
                return false;
        }
    }

    return 1;
}

int main(){
    int t , len , ans;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t && scanf("%s" , s ) ; ++q ){
        len = strlen( s );
        ans = 0;
        for( int i = 0 ; i < len ; ++i ){
            memset( cnt , 0 , sizeof( cnt ) );
            for( int j = i, k = 1 ; j < len ; ++j , ++k ){
                cnt[ s[ j ] - 'a' ]++;
                ans += isDromicPalin( k );
            }
        }
        printf("Case %d: %d\n" , q , ans );
    }
    return 0;
}
