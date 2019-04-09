/*****************************************
 ***Problema: Football
 ***ID: 12673
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 100005
int a[ MAX ];

bool cmp( int n1 , int n2 ){
    return n1 > n2;
}

int main(){
    int n , g , ans , gain , lost , draw, win ,i;

    while( scanf("%d%d" , &n , &g ) != EOF ){
        for( i = 0 ; i < n && scanf("%d %d" , &gain , &lost ) ; ++i )
            a[ i ] = gain - lost;
        sort( a , a + n , cmp );
        ans = 0;
        for( i = 0 ; i < n ; ++i ){
            if( a[ i ] > 0 )
                ans += 3;
            else if( a[ i ] == 0 ){
                if( g > 0 ){
                    ans += 3;
                    g--;
                }
                else{
                    ans++;
                }
            }
            else{
                draw = a[ i ] * -1;
                win = draw + 1;
                if( g >= win ){
                    ans += 3;
                    g -= win;
                }
                else if( g >= draw ){
                    ans++;
                    g -= draw;
                }
                else break;
            }
        }
        printf("%d\n" , ans );
    }

    return 0;
}
