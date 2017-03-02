/*****************************************
 ***Problema: Injured Queen Problem
 ***ID: 10401
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>
#define MAX 20
int n;
char s[ MAX ];
long long dp[ MAX ][ MAX ];
int ady[ MAX ][ MAX ] , row[ MAX ] , col[ MAX ], seen[ MAX ][ MAX ] , aux[ MAX ][ MAX ];
int kx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int ky[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1 };
int dx[ 2 ] = { -2 , 2 };
int dy[ 2 ] = { 1 };

void solve(){
    memset( dp , 0 , sizeof( dp ) );
    int i , j , nx , ny , x;
    if( col[ 0 ] >= 0 ) dp[ col[ 0 ] ][ 0 ] = 1;
    for( j = 0 ; j < n - 1 ; ++j ){
        if( col[ j ] >= 0 ){
            //si no hay pieza en la columna siguiente
            if( col[ j + 1 ] == -1 ){
                for( i = 0 ; i < n ; ++i ){
                    if( !seen[ i ][ j + 1 ] ) dp[ i ][ j + 1 ] += dp[ col[ j ] ][ j ];
                }
            }
            //si hay cuento todo a esa pieza
            else{
                dp[ col[ j + 1 ] ][ j + 1 ] = dp[ col[ j ] ][ j ];
            }
        }
        else{
            if( j == 0 ){
                //la segunda columna puede tener una pieza
                for( i = 0 ; i < n ; ++i ){
                    if( !seen[ i ][ j ] ) dp[ i ][ j ] = 1;
                }
            }

            //pruebo en cada fila de esta columna con una pieza y voy contando
            for( x = 0 ; x < n ; ++x ){
                if( seen[ x ][ j ] ) continue;
                memcpy( aux , seen , sizeof( seen ) );
                aux[ x ][ j ] = 1;
                for( i = 0 ; i < 8 ; ++i ){
                    nx = kx[ i ] + x; ny = ky[ i ] + j;
                    if( nx >= 0 && ny >= 0 && nx < n && ny < n ){
                        aux[ nx ][ ny ] = 1;
                    }
                }
                //si no hay pieza en la columna siguiente
                if( col[ j + 1 ] == -1 ){
                    for( i = 0 ; i < n ; ++i ){
                        if( !aux[ i ][ j + 1 ] ) dp[ i ][ j + 1 ] += dp[ x ][ j ];
                    }
                }
                //si hay cuento todo a esa pieza
                else{
                    dp[ col[ j + 1 ] ][ j + 1 ] += dp[ x ][ j ];
                }
            }
        }
    }

    long long ans = 0;
    //cuento los posibles finales
    if( col[ n - 1 ] == -1 ){
        for( i = 0 ; i < n ; ++i ){
            ans += dp[ i ][ n - 1 ];
        }
    }
    //sino solo cuento finales en la pieza ingresada
    else ans += dp[ col[ n - 1 ] ][ n - 1 ];
    printf("%lld\n" , ans );
}

int correct(){
    int i , nx , ny , j;
    for( i = 0 ; i < n - 1 ; ++i ){
        if( col[ i ] >= 0 && col[ i + 1 ] >= 0 ){
            for( j = 0 ; j < 8 ; ++j ){
                nx = kx[ j ] + col[ i ]; ny = ky[ j ] + i;
                if( nx >= 0 && ny >= 0 && nx < n && ny < n ){
                    if( nx == col[ i + 1 ] && ny == i + 1 ) return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    int i , j , nx , ny;
    while( scanf("%s" , &s ) != EOF ){
        memset( seen , 0 , sizeof( seen ) );
        memset( col , -1 , sizeof( col ) );

        n = strlen( s );
        if( n == 1 ){
            printf("1\n" );
            continue;
        }
        for( i = 0 ; s[ i ] ; ++i )
        {
            if( s[ i ] != '?' ){
                if( s[ i ] >= '0' && s[ i ] <= '9'){
                    seen[ s[ i ] - '0' - 1 ][ i ] = 1;
                    for( j = 0 ; j < 8 ; ++j ){
                        nx = kx[ j ] + s[ i ] - '0' - 1; ny = ky[ j ]+ i;
                        if( nx >= 0 && ny >= 0 && nx < n && ny < n ){
                            seen[ nx ][ ny ] = 1;
                        }
                    }
                    col[ i ] = s[ i ] - '0' - 1;
                }else{
                    seen[ s[ i ] - 'A' + 9 ][ i ] = 1;
                    col[ i ] = s[ i ] - 'A' + 9;
                    for( j = 0 ; j < 8 ; ++j ){
                        nx = kx[ j ] + s[ i ] - 'A' + 9; ny = ky[ j ]+ i;
                        if( nx >= 0 && ny >= 0 && nx < n && ny < n ){
                            seen[ nx ][ ny ] = 1;
                        }
                    }
                }
            }
        }
        if( correct() ) solve();
        else printf("0\n");
    }

    return 0;
}

/*

1?4??3
6???4???
???A???B????E??
???A???BC???E??
???A???B??4?E?F
??
?
1??
??2
??????????????A
??????????????F
??????????????1*/
