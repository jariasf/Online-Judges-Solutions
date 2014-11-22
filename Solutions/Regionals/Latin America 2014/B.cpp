/*****************************************
 ***Problema: Black and white stones
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
#define MAX 5005
char s[ MAX ];

int main(){
    int len , b;
    long long ans, A, B;
    while( scanf("%lld %lld" , &A , &B ) != EOF ){
        scanf("%s" , s );
        len = strlen( s );
        ans = b = 0;
        vector<int> w;

        for( int i = 0 ; i < len ; ++i ){
            if( s[i] == 'W' )
                w.push_back(i);
            else
                b++;
        }

        for( int i = len - 1 , k = 0 ; i >= b ; --i ){
            if( s[ i ] == 'B' ){
                ans += min( ( A - B ) * ( i - w[k++] ) , A );
            }
        }
        printf("%lld\n" , ans );
    }
    return 0;
}
