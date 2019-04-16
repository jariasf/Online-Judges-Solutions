/*****************************************
 ***Problema: Emoogle Balance
 ***ID: 12279
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    int i ,n , x , ans , q = 1;
    while( scanf("%d" , &n ) , n ){
        ans = 0;
        for( i = 0 ; i < n && scanf("%d" , &x ) ; ++i ){
            if( x > 0 ) ans++;
            else ans--;
        }
        printf("Case %d: %d\n" , q++ , ans );
    }
    return 0;
}
