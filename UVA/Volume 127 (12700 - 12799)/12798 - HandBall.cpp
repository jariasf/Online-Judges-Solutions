/*****************************************
 ***Problema: HandBall
 ***ID: 12798
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n ,m, ans , x;
    while( scanf("%d %d" , &n , &m ) , n | m ){
        ans = 0;
        for( int i = 0 ; i < n ; ++i ){
            bool b = true;
            for( int j = 0 ; j < m && scanf("%d" , &x) ; ++j ){
                b &= ( x > 0 ? 1 : 0);
            }
            ans += b;
        }
        printf("%d\n" , ans );
    }
    return 0;
}
