/*****************************************
 ***Problema: A Change in Thermal Unit
 ***ID: 11984
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int t , C , d , q;
    scanf("%d" , &t );
    for( q = 1 ; q <= t ; ++q ){
        scanf("%d %d" , &C , &d );
        printf("Case %d: %.2lf\n" , q , C + 5*d/9.0 );
    }
    return 0;
}
