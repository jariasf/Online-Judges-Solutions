/*****************************************
 ***Problema: Jollybee Tournament
 ***ID: 1241
 ***Juez: UVA
 ***Tipo: Ad hoc, recursion, simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
int a[ 1<<11 ];

int main(){

    int n , x, m ,t;
    scanf("%d" , &t );
    while( t-- ){

        scanf("%d %d" , &n , &m );
        memset( a , 0 , sizeof( a ) );
        while( m-- ){
            scanf("%d" , &x );
            a[ x ] = 1;
        }
        int ans = 0 , len = 1;
        n = 1<<n;
        while( n > 1 ){
            len = 0;
            for( int i = 1 ; i <= n ; i += 2 ){
                if( a[ i ] && a[ i + 1 ] ){
                    a[ ++len ] = 1;
                }
                else if( !a[ i ] && !a[ i + 1 ]){
                    a[ ++len ] = 0;
                }
                else{
                    a[ ++len ] = 0;
                    ans++;
                }
            }
            n = len;
        }
        printf("%d\n" , ans);
    }

    return 0;
}
