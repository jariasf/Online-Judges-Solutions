/*****************************************
 ***Problema: Getting Gold
 ***ID: 11561
 ***Juez: UVA
 ***Tipo: DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 55
char ady[ MAX ][ MAX ];
int w , h;
int dx[ 4 ] = { 0 , 0 , 1 , -1 };
int dy[ 4 ] = { 1 , -1 , 0 , 0 };
int possible( int x , int y ){
    int nx, ny , i;
    for( i = 0 ; i < 4 ; ++i ){
        nx = x + dx[ i ]; ny = y + dy[ i ];
        if( nx >= 0 && nx < h && ny >= 0 && ny < w && ady[ nx ][ ny ] != '#' ){
            if( ady[ nx ][ ny ] == 'T' ) return 0;
        }
    }
    return 1;
}

int ans;
void solve( int x , int y ){
    if( x < 0 || y < 0 || x >= h || y >= w || ady[ x ][ y ] == '#' ) return;
    if( ady[ x ][ y ] == 'G' ) ans++;
    ady[ x ][ y ] ='#';
    if( !possible( x , y ) ) return;
    solve( x + 1 , y );
    solve( x - 1 , y );
    solve( x , y + 1 );
    solve( x , y - 1 );
    return;
}

int main(){
    int x , y, i , j;
    while( scanf("%d %d" , &w , &h ) != EOF ){
        for( i = 0 ; i < h ; ++i ){
            for( j = 0 ; j < w && scanf(" %c" , &ady[ i ][ j ] ) == 1 ; ++j ){
                if( ady[ i ][ j ] == 'P'){
                    x = i;
                    y = j;
                }
            }
        }
        ans = 0;
        solve( x , y );
        printf("%d\n" , ans );
    }
    return 0;
}
