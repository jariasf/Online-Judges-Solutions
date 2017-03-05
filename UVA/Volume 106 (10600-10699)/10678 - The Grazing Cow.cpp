/*****************************************
 ***Problema: The Grazing Cow
 ***ID: 10678
 ***Juez: UVA
 ***Tipo: Area Ellipsis
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>
const double PI = 2 * acos( .0 );
int main(){
    int t;
    scanf("%d" , &t );
    double D , L;
    while( t-- > 0 && scanf("%lf %lf" , &D , &L ) ){
        printf("%.3lf\n" , PI * L/2.0 * sqrt( (L * L/4.0 ) - (D * D /4.0) ) );
    }
    return 0;
}
