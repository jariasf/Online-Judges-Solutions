/*****************************************
 ***Problema: Watering Grass
 ***ID: 10382
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX 10055
#define EPS 1e-6
struct Interval{
    double ini , fin;
    Interval( double i , double f ): ini( i ) , fin( f ){}
    Interval(){}

    bool operator < ( const Interval t1 ) const{
        return ini < t1.ini;
    }
}a[ MAX ];

double getDx( double R , double W ){
    return sqrt( R * R - ( W * W / 4.0 ) );
}

int main(){
    int n , w , h, x , r , ans , len;
    double dx ,lastRight, newRight;
    while( scanf("%d %d %d" , &n , &h , &w ) == 3 ){
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d %d" , &x , &r );
            if( r * 2 < w ){
                a[ i ].ini = a[ i ].fin = 0;
                continue;
            }
            dx = getDx( (double)r , (double)w );
            a[ i ].ini = x - dx;
            a[ i ].fin = x + dx;
        }
        sort( a , a + n );
        ans = 0;
        lastRight = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ){
            newRight = 0;
            while( j < n && a[ j ].ini <= lastRight ){
                if( a[ j ].fin > newRight ){
                    newRight = a[ j ].fin;
                }
                ++j;
            }
            lastRight = newRight;
            ans++;
            if( j == i || lastRight + EPS > h ) break;
        }
        if( lastRight + EPS > h ) printf("%d\n" , ans );
        else printf("-1\n");
    }
    return 0;
}
