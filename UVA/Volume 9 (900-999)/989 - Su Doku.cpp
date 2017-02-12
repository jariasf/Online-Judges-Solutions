/*****************************************
 ***Problema: Su Doku
 ***ID: 989
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 10
int ady[ MAX ][ MAX ];

int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };
bool used[ MAX ][ MAX ];
int sq3[ 5 ] = { 2 , 5 , 8 }, sq2[ 5 ] = { 1 , 3 };
bool seen[ MAX ][ MAX ];
bool finish;
int N;
void solve( int x , int y ){
    if( x == N && y == 0 ){
        for( int i = 0 ; i < N ; ++i ){
            printf("%d" , ady[ i ][ 0 ] );
            for( int j = 1 ; j < N ; ++j ){
                printf(" %d" , ady[ i ][ j ]);
            }
            printf("\n");
        }
        finish = true;
        return;
    }

    if( finish ) return;
    if( used[ x ][ y ] ){
        if( y + 1 < N ){ solve( x , y + 1 ); if( finish ) return;}
        else solve( x + 1 , 0 );
        return;
    }

    if( seen[ x ][ y ] )return;
    int possible[ 15 ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 };
    //en direcciones
    for( int i = 0 ; i < 4 ; ++i ){
        int k = 0;
        while( 1 ){
            k++;
            int nx = dx[ i ] * k + x, ny = dy[ i ] * k + y;
            if( nx >= 0 && ny >= 0 && nx < N && ny < N ){
                possible[ ady[ nx ][ ny ] ] = 0;
            }
            else break;
        }
    }
    //en cuadrado
    int cuadrado = -1, xx = 0 , yy = 0, iniX = 0, iniY = 0;
    if( N == 9 ){
        for( int i = 0 ; i < 3 ; ++i ){
            int j = 0;
            for(  ; j < 3 ; ++j ){
                cuadrado++;
                if( x <= sq3[ i ] && y <= sq3[ j ] ){
                    xx = sq3[ i ];
                    yy = sq3[ j ];
                    break;
                }
            }
            if( j != 3 )break;
        }

        iniX = 0; iniY = ( cuadrado * 3 ) % 9;
        if( cuadrado <= 2 )iniX = 0;
        else if( cuadrado <= 5 ) iniX = 3;
        else if( cuadrado <= 8 ) iniX = 6;
    }
    else{
        for( int i = 0 ; i < 2 ; ++i ){
            int j = 0;
            for( ; j < 2 ; ++j ){
                cuadrado++;
                if( x <= sq2[ i ] && y <= sq2[ j ] ){
                    xx = sq2[ i ];
                    yy = sq2[ j ];
                    break;
                }
            }
            if( j != 2 )break;
        }
        iniX = 0; iniY = ( cuadrado * 2 ) % 4;
        if( cuadrado <= 1 )iniX = 0;
        else if( cuadrado <= 3 ) iniX = 2;
    }

    for( int i = iniX ; i <= xx ; ++i ){
        for( int j = iniY ; j <= yy ; ++j ){
            if( ady[ i ][ j ] != 0 ) possible[ ady[ i ][ j ] ] = 0;
        }
    }

    for( int i = 1 ; i <= N ; ++i ){
        if( possible[ i ] ){
            ady[ x ][ y ] = i;
            seen[ x ][ y ] = 1;
            if( y + 1 < N ){ solve( x , y + 1 ); if( finish ) return; }
            else solve( x + 1 , 0 );
            if( finish ) return;
            seen[ x ][ y ] = 0;
            ady[ x ][ y ] = 0;
        }
    }
    if( finish ) return;
}

int main(){
    bool first = false;
    while( scanf("%d" , &N ) == 1 ){
        N *= N;
        if( first ) printf("\n");
        first = true;

        for( int i = 0 ; i < N ; ++i )
        {
            for( int j = 0 ; j < N ; ++j ){
                scanf("%d" , &ady[ i ][ j ] );
                used[ i ][ j ] = 0;
                seen[ i ][ j ] = 0;
                if( ady[ i ][ j ] != 0 ) { used[ i ][ j ] = 1; seen[ i ][ j ] = 1;}
            }
        }
        finish = false;
        solve( 0 , 0 );
        if( !finish )printf("NO SOLUTION\n");
    }

    return 0;
}
