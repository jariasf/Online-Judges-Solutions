/*****************************************
 ***Problema: Satellites
 ***ID: 10221
 ***Juez: UVA
 ***Tipo: Geometry
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>

#define MAX 4
#define EPS 1e-9
const double PI = 2 * acos(.0);

char s[ MAX ];

double Deg_to_Rad( double angle ){
    return angle * PI/180.0;
}

int main(){
    double radius , angle;
    while( scanf("%lf %lf %s" , &radius , &angle , s ) != EOF ){
        radius += 6440;
        if( s[ 0 ] == 'm' )
            angle *= 1/60.0;
        if( angle > 180 )
            angle = 360.0 - angle;
        printf("%.6lf %.6lf\n" , radius * PI * 2.0 * angle/360.0 , 
								sqrt( 2 * radius * radius  * ( 1 - cos( Deg_to_Rad(angle) ) ) ) );
    }

    return 0;
}
