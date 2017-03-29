/*****************************************
 ***Problema:  Little Red Riding Hood
 ***ID: 11067
 ***Juez: UVA
 ***Tipo: Counting Paths DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 105
int w,  h , prohibited[ MAX ][ MAX ];
long long dp[ MAX ][ MAX ];
int dx[ 2 ] = { 0 , 1 };
int dy[ 2 ] = { 1 , 0 };
void solve(){
    int i , j , k , nx , ny;
    memset( dp , 0LL , sizeof( dp ) );
    dp[ 0 ][ 0 ] = 1;
    for( i = 0 ; i < h ; ++i ){
        for( j = 0 ; j < w ; ++j ){
            if( prohibited[ i ][ j ] ) continue;
            for( k = 0 ; k < 2 ; ++k ){
                nx = dx[ k ] + i; ny = dy[ k ] + j;
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && !prohibited[ nx ][ ny ] ){
                    dp[ nx ][ ny ] += dp[ i ][ j ];
                }
            }
        }
    }
    if( dp[ h - 1 ][ w - 1 ] == 1 ) 
		puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
    else if( dp[ h - 1 ][ w - 1 ] > 1 ) 
		printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n" , dp[ h - 1 ][ w - 1 ] );
    else puts("There is no path.");
}

int main(){
    int n , u , v;
    while( scanf("%d %d" , &h , &w ) , w | h ){
        scanf("%d" , &n );
        w++; h++;
        memset( prohibited , 0 , sizeof( prohibited ) );
        while( n-- ){
            scanf("%d %d" , &u , &v );
            prohibited[ u ][ v ] = 1;
        }
        solve();
    }
    return 0;
}
