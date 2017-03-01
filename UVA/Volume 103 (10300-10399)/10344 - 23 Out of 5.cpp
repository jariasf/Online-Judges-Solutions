/*****************************************
 ***Problema: 23 Out of 5
 ***ID: 10344
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

bool seen[ 6 ];
int a[ 6 ];
bool finish;

void solve( int len , int sum  ){

    if( finish ) return;
    if( len == 5 ){
        if( sum == 23 ){ finish = true; return;}
        return;
    }

    for( int i = 0 ; i < 5 ; ++i ){
        if( !seen[ i ] ){
            seen[ i ] = 1;
            solve( len + 1 , sum + a[ i ] );
            solve( len + 1 , sum * a[ i ] );
            solve( len + 1 , sum - a[ i ] );
            seen[ i ] = 0;
        }
    }
}

int main(){
    while(scanf("%d %d %d %d %d" , &a[0], &a[1], &a[2], &a[3], &a[4]), a[0]|a[1]|a[2]|a[3]|a[4] ){
        finish = false;
        for( int i = 0 ; i < 5 ; ++i ){
            memset( seen , 0 , sizeof( seen ) );
            seen[ i ] = 1;
            solve( 1 , a[ i ] );
            if( finish ) break;
        }
        if( finish ) puts("Possible");
        else puts("Impossible");
    }

    return 0;
}
