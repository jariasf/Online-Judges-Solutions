/*****************************************
 ***Problema: Brownie Points I
 ***ID: 10865
 ***Juez: UVA
 ***Tipo: Ad hoc, Geometry
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define EPS 1e-9
struct Point{
   Point(int x1,int y1){
       x=x1;
       y=y1;
   }
   Point(){

   }
   int x;
   int y;
}v[ 200005 ];

int main(){
    int n, Stan, Ollie;
    int x,y , len;
    while ( scanf("%d", &n) && n ){
        len = 0;
        for( int i = 0 ; i < n ; ++i ){
            Point p;
            scanf("%d %d",&p.x, &p.y);
            v[ len++ ] = p;
        }

        x = v[ n/2 ].x;
        y = v[ n/2 ].y;
        Stan = 0; Ollie = 0;
        for( int i = 0 ; i < len; ++i ){
            if( ( v[ i ].x > x && v[ i ].y > y ) || ( v[ i ].x < x && v[ i ].y < y ) ){
                Stan++;
            }
            else if( ( v[ i ].x > x && v[ i ].y < y ) || ( v[ i ].x < x && v[ i ].y >y ) ){
                Ollie++;
            }
        }
        printf("%d %d\n", Stan, Ollie);
    }
    return 0;
}
