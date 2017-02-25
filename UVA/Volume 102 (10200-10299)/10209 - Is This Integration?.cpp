/*****************************************
 ***Problema: Is This Integration ?
 ***ID: 10209
 ***Juez: UVA
 ***Tipo: Geometry, sectors, angles
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>

#define EPS 1e-9
const long double PI = 2 * acos(.0);
int main(){
    double r;
    while( scanf("%lf" , &r ) != EOF ){
        double z = r * r * ( 1 - PI/6.0 - sqrt( 3.0 )/4.0 );
        double y = r * r * ( 1 - PI/4.0 ) - 2 * z;
        double x = r * r - 4 * z - 4 * y;
        printf("%.3lf %.3lf %.3lf\n" , x , 4 * y , 4 * z );
    }

    return 0;
}
