/*****************************************
 ***Problema: Save Setu
 ***ID: 12403
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 6
char s[ MAX ];
int main(){

    int t , n , sum = 0;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s" , s ) ){
        if( s[ 0 ] == 'd' ){
            scanf("%d" , &n );
            sum += n;
        }
        else printf("%d\n" , sum );
    }

    return 0;
}
