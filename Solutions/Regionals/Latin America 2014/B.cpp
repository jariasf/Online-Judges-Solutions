/*****************************************
 ***Problema: Black and white stones
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 5005
char s[ MAX ];

int main(){
    int A , B, len , b , w;
    long long ans;
    while( scanf("%d %d" , &A , &B ) != EOF ){
        scanf("%s" , s );
        len = strlen( s );
        ans = 0;
        for( int i = len - 1 ; i >= 0 ; --i ){
            if( s[ i ] == 'B' ){
                int index = -1;
                for( int j = 0 ; j < i ; ++j ){
                    if( s[j] == 'W' ){
                        index = j;
                        break;
                    }
                }
                if( index != -1 ){
                    long long dif = ( A - B ) * (long long)( i - index );
                    if( dif > A ){
                        ans += A;
                    }else{
                        ans += dif;
                    }
                    swap( s[ index ] , s[ i ] );
                }
            }
        }
        printf("%lld\n" , ans );
    }
    return 0;
}
