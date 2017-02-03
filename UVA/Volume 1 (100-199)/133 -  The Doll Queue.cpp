/*****************************************
 ***Problema: The Dole Queue
 ***ID: 133
 ***Juez: UVA
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

bool circle[ 24 ];

int main(){
    int k , n , m , next_left , next_right , l , r, q , len;
    while( scanf("%d %d %d" , &n , &k , &m ) ,  k| m | n ){
        memset( circle , 0 , sizeof( circle ) );
        r = 0; l = n - 1;
        k--;
        m--;
        q = 0;
        len = n;
        while( len ){

            for( int j = k % len ; ; r++  ){
                if( r == n ) r = 0;
                if( !circle[ r ] && j-- <= 0 )break;
            }

            for( int j = m % len ; ; l-- ){
                if( l == -1 ) l = n - 1;
                if( !circle[ l ] && j-- <= 0  )break;
            }

            circle[ r ] = circle[ l ] = 1;

            if( q++ )printf(",");
            if( r == l ){
                printf("%3d" , r + 1 );
                len--;
            }
            else{
                printf("%3d%3d" , r + 1 , l + 1 );
                len -= 2;
            }

        }
        printf("\n");
    }
    return 0;
}
