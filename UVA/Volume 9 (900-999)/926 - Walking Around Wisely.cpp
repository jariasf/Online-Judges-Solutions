/*****************************************
 ***Problema: Walking Around Wisely
 ***ID: 926
 ***Juez: UVA
 ***Tipo: Counting Path DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 35
enum{ Q , N , S , W , E};
struct Connected{
    int N , S , W ,E;
}ady[ MAX ][ MAX ];

int n , xini , yini , xfin , yfin;
unsigned long long dp[ MAX ][ MAX ];
int dx[] = { 0 , 1 };
int dy[] = { 1 , 0 };
void solve(){
    int i , j , ans ,ny , nx , k;
    memset( dp , 0 , sizeof( dp ) );
    dp[ xini - 1 ][ yini - 1 ] = 1;
    for( i = xini - 1 ; i < xfin ; ++i ){
        for( j = yini - 1 ; j < yfin ; ++j ){
            for( k = 0 ; k < 2 ; ++k ){
                nx = dx[ k ] + i; ny = dy[ k ] + j;
                if( nx >= 0 && ny >= 0 && nx < xfin && ny < yfin ){
                    //izq - der
                    if( k == 0 && ady[ i ][ j ].E == 1 || ady[ nx ][ ny ].W == 1 ) continue;
                    //arrib - abajo
                    else if( ady[ i ][ j ].S == 1 || ady[ nx ][ ny ].N == 1 ) continue;
                    dp[ nx ][ ny ] += dp[ i ][ j ];
                }
            }
        }
    }
    printf("%llu\n" , dp[ xfin - 1  ][ yfin - 1 ] );
}
int main(){
    char c;
    int t  ,x , y , q ;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d%d %d%d %d" , &n , &xini , &yini , &xfin , &yfin , &q );
        memset( ady , 0 , sizeof( ady ) );
        while( q-- ){
            scanf("%d %d %c" , &x , &y , &c );
            switch( c ){
                case 'S':
                    ady[ x - 1 ][ y - 1 ].W = 1;
                break;
                case 'N':
                    ady[ x - 1 ][ y - 1 ].E = 1;
                break;
                case 'W':
                    ady[ x - 1 ][ y - 1 ].N = 1;
                break;
                case 'E':
                    ady[ x - 1 ][ y - 1 ].S = 1;
                break;
            }
        }
        solve();
    }
    return 0;
}
