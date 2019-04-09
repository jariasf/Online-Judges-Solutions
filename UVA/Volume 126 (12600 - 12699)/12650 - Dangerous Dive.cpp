/*****************************************
 ***Problema: Dangerous Dive
 ***ID: 12650
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 1004
bool returned[ MAX ];
int main(){
    int n , r , x;
    while( scanf("%d %d" , &n , &r ) != EOF ){

        if( n == r ){
            while( r-- > 0 && scanf("%d" , &x ));
            puts("*");
            continue;
        }
        memset( returned , 0 ,sizeof( returned ) );
        while( r-- > 0 && scanf("%d" , &x ) ){
            returned[ x ] = true;
        }

        for( int i = 1 ; i <= n ; ++i ){
            if( !returned[ i ] ){
                printf("%d " , i );
            }
        }
        printf("\n");
    }

    return 0;
}
