/*****************************************
 ***Problema: Hajj-e-Akbar
 ***ID: 12577
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
char s[ 6 ];
int main(){
    int q = 1;
    while( scanf("%s" , s ) , s[ 0 ] != '*' ){
        printf("Case %d: " , q++ );
        if( s[ 0 ] == 'H' ) puts("Hajj-e-Akbar");
        else puts("Hajj-e-Asghar");
    }
    return 0;
}
