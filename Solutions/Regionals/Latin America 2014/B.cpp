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
    int A , B, len , b;
    long long ans;
    while( scanf("%d %d" , &A , &B ) != EOF ){
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
                int index = w[k++];
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
