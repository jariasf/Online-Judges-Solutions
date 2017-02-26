/*****************************************
 ***Problema: The Kissing Circles
 ***ID: 10283
 ***Juez: UVA
 ***Tipo: Geometry, Circles
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>
const double PI = 2 * acos(.0);
//Convert angle from degrees to radians
double Deg_to_Rad( double angle ){
    return angle * PI/180.0;
}

int main(){
    double R , N , angle , r , I , E , l , angle_mini_circle;
    while( scanf("%lf %lf" , &R , &N ) != EOF ){
        if( N == 1 ){
            r = R; I = E = 0;
        }
        else{
            angle = 360/N;
            r = R * sin( Deg_to_Rad(angle/2.0) )/( 1.0 + sin(Deg_to_Rad(angle/2.0)) );
            l = sqrt( ( R - r ) * ( R - r ) - r * r);
            angle_mini_circle = 90.0 - angle/2.0;
            double area_sector = PI * r * r * angle_mini_circle/360.0;
            double area_triangle = r * l/2.0;
            I = 2.0 * N * ( area_triangle - area_sector );
            E = PI * R * R  - N * PI * r * r - I;
        }
        printf("%.10lf %.10lf %.10lf\n" , r , I , E );
    }
    return 0;
}
