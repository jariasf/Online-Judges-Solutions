/*****************************************
 ***Problema: Geometry Paradox
 ***ID: 10573
 ***Juez: UVA
 ***Tipo: Geometry
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <sstream>
#include <cmath>
using namespace std;
#define MAX 105
const double PI = 2 * acos(.0);

char s[ MAX ];
int main(){
    int q;
    scanf("%d" , &q );
    gets( s );
    double r1 , r2 , t , area , r;
    while( q-- && gets( s ) ){
        stringstream ss( s );
        ss>>r1;
        if( !(ss>>r2) ){
            t = r1;
            area = PI * ( t * t / 8.0 );
        }
        else{
            r = r1 + r2;
            area = PI * r * r - ( PI * r1 * r1 + PI * r2 * r2 );
        }
        printf("%.4lf\n" , area );
    }
    return 0;
}
