/*****************************************
 ***Problema: The Coco-Cola Store
 ***ID: 11877
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n, cnt;
    while( scanf("%d" , &n ) && n ){
        cnt = 0;
        while( n > 0 ){
            n -= 2;
            if( n < 0 )break;
            cnt++;
        }
        printf("%d\n" , cnt );

    }

    return 0;
}
