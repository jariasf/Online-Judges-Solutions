/*****************************************
 ***Problema: Building designing
 ***ID: 11039
 ***Juez: UVA
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>

#define MAX 500005
struct Building{
    int value , color;
    Building(){}
    Building( int v , int c ): value( v ) , color( c ){}
}a[ MAX ];

bool cmp( Building b1 , Building b2 ){
    return b1.value < b2.value;
}

int main(){
    int t, x , n , cnt;
    scanf("%d" , &t );

    while( t-- ){
        scanf("%d" , &n );

        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &x);
            if( x < 0 ) a[ i ] = Building( -x , 'R');
            else a[ i ] = Building( x , 'A');
        }

        std::sort( a , a + n , cmp );
        int color = a[ 0 ].color;
        cnt = 1;
        for( int i = 1 ; i < n ; ++i ){
            if( a[ i ].color != color ){
                cnt++;
            }
            color = a[ i ].color;
        }
        printf("%d\n" , cnt );
    }
    return 0;
}
