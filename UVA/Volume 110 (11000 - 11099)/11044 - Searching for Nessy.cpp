/*****************************************
 ***Problema: Searching for Nessy
 ***ID: 11044
 ***Juez: UVA
 ***Tipo: Ad hoc, Simple Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <math.h>
int main(){
    int t , n , m ;
    scanf( "%d" , &t );
    while( t-- ){
        scanf( "%d %d" , &n , &m );
        printf("%d\n", (int)ceil((n - 2)/3.0) * (int)ceil((m - 2)/3.0));
    }

    return 0;
}
