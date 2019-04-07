/*****************************************
 ***Problema: 10:6:2
 ***ID: 10578
 ***Juez: UVA
 ***Tipo: Geometry
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>
const double PI = 2 * acos( .0 );
int main(){
    int t ;
    double radio , width , l , area_circle;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%lf" , &l ) ){
        radio = l/5.0;
        width = 6.0 * l/10.0;
        area_circle = PI * radio * radio;
        printf("%.2lf %.2lf\n" , area_circle , l * width - area_circle );
    }
    return 0;
}
