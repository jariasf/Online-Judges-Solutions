/*****************************************
 ***Problema: How Many Knights
 ***ID: 696
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n , m, ans, aux;
    while( scanf("%d %d" , &m , &n) , m | n ){
        if( m > 2 && n > 2 ) ans = ( ( m * n ) + 1 ) /2 ;
        else if( m == 1 || n == 1 ) ans = m * n;
        else if( m == 2 ){
            aux = n - 3;
            if( aux < 0 ) aux = 0;
            else aux = ( aux / 4 ) + 1;
            ans = 2 * ( n - ( n/4 ) - aux );
        }
        else if( n == 2 ){
            aux = m - 3;
            if( aux < 0 ) aux = 0;
            else aux = ( aux / 4 ) + 1;
            ans = 2 * ( m - ( m/4 ) - aux );
        }
        printf("%d knights may be placed on a %d row %d column board.\n" ,  ans, m , n  );

    }

    return 0;
}
