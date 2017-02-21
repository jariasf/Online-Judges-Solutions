/*****************************************
 ***Problema: Meeting Prof. Miguel
 ***ID: 10171
 ***Juez: UVA
 ***Tipo: Floyd Warshall, Shortest Path
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 26
#define INF 9999999
int ady[ MAX ][ MAX ];
char who[ MAX ][ MAX ];
int young[ MAX ][ MAX ];
void Init(){
    for( int i = 0 ; i < MAX ; ++i ){
        for( int j = 0 ; j < MAX ; ++j ){
            ady[ i ][ j ] = INF;
            young[ i ][ j ] = INF;
        }
        ady[ i ][ i ] = 0;
        young[ i ][ i ] = 0;
    }
}

void FloydYoung(  ){
    for( int k = 0 ; k < MAX ; ++k ){
        for( int i = 0 ; i < MAX ; ++i ){
            for( int j = 0 ; j < MAX ; ++j ){
                int t = young[ i ][ k ] + young[ k ][ j ];
                if( young[ i ][ j ] > t ){
                    young[ i ][ j ] = t;
                }
            }
        }
    }
}

void FloydOld( ){

    for( int k = 0 ; k < MAX ; ++k ){
        for( int i = 0 ; i < MAX ; ++i ){
            for( int j = 0 ; j < MAX ; ++j ){
                int t = ady[ i ][ k ] + ady[ k ][ j ];
                if( ady[ i ][ j ] > t ){
                    ady[ i ][ j ] = t;
                }
            }
        }
    }
}


int main(){
    int E , d;
    char road, dir, u , v;
    while( scanf("%d" ,&E) && E ){

        Init();
        while( E-- ){
            scanf("\n%c %c %c %c %d" , &road , &dir , &u , &v , &d );

            if( road == 'Y' ){
                if( d < young[ u - 'A' ][ v - 'A' ] )
                    young[ u - 'A' ][ v - 'A' ] = d;
                if( dir == 'B' ){
                    if( d < young[ v -'A' ][ u-'A' ] )
                        young[ v -'A' ][ u-'A' ] = d;
                }
            }
            else{
                if( d < ady[ u - 'A' ][ v - 'A' ] )
                    ady[ u - 'A' ][ v - 'A' ] = d;
                if( dir == 'B' ){
                    if( d < ady[ v-'A' ][ u-'A' ] )
                        ady[ v-'A' ][ u-'A' ] = d;
                }
            }
        }
        FloydYoung();
        FloydOld();
        scanf("\n%c %c" , &u , &v );
        int min = INF;
        for( int i = 0 ; i < MAX ;++i ){
            int sum = ady[ v -'A' ] [ i ] + young[ u - 'A' ][ i ];
            if( min > sum) min = sum;
        }

        if( min == INF )printf("You will never meet.\n");
        else{
            printf("%d",min);
            for( int i = 0 ; i < MAX ; ++i){
                 if( ady[ v -'A' ] [ i ] + young[ u - 'A' ][ i ] == min ){
                     printf(" %c" , i + 'A');
                 }
            }
            printf("\n");
        }
    }
    return 0;
}
