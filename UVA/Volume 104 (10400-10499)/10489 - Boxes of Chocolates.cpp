/*****************************************
 ***Problema: Boxes of Chocolates
 ***ID: 10489
 ***Juez: UVA
 ***Tipo: Ad hoc, modulo
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int t, N , B, K, resp, a, p;
    scanf( "%d" ,&t );
    while( t-- ){
        scanf( "%d %d" ,&N , &B );
        resp = 0;
        while( B-- ){
            scanf( "%d" ,&K );
            p = 1;
            while( K-- ){
                scanf( "%d" ,&a );
                p = ( p % N * a % N )% N;
            }
            resp = (resp % N + p % N ) % N;
        }
        printf("%d\n",resp);
    }

    return 0;
}
