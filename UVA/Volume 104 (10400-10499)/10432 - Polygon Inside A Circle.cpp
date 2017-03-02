/*****************************************
 ***Problema: Polygon Inside A Circle
 ***ID: 10432
 ***Juez: UVA
 ***Tipo: Geometry
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>

using namespace std;
const long double PI = 2 * acos(.0);
//Convert angle from degrees to radians
long double Deg_to_Rad( double angle ){
    return angle * PI/180.0;
}
int main(){

    long double radius, n;
    while( scanf("%Lf %Lf", &radius , &n ) != EOF ){
        long double angle = 360.0/n;
        long double chord = sqrt( 2.0 * radius * radius * ( 1.0 - cos( Deg_to_Rad( angle ) ) ));
        long double p = (radius + radius + chord)/2.0;
        long double areaTriangle = sqrt( p * ( p - radius ) * ( p - radius ) * ( p - chord ) );
        printf("%.3Lf\n" , n * areaTriangle );
    }

    return 0;
}
