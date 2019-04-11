/*****************************************
 ***Problema: Black and white stones
 ***ID: 12855
 ***Juez: UVA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 5005
char s[ MAX ];
long long min( long long a , long long b ){
    if( a < b )
        return a;
    return b;
}


int main(){
    int A , B, len , b , w;
    long long ans;
    while( scanf("%d %d" , &A , &B ) != EOF ){
        scanf("%s" , s );
        len = strlen( s );
        ans = 0;
        b = 0;
        vector<int> white;
        for( int i = 0 ; i < len ; ++i ){
            b += ( s[i] == 'B');
            if( s[i] == 'W' )
                white.push_back(i);
        }

        for( int i = len - 1 , k = 0 ; i >= b ; --i ){
            if( s[ i ] == 'B' ){
                int index = white[k++];
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
