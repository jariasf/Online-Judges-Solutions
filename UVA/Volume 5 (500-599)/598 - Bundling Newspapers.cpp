/*****************************************
 ***Problema: Bundling Newspapers
 ***ID: 598
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 105
char name[ MAX ][ 35 ];
int n;
bool seen[ MAX ];
int ans[ MAX ];
void solve( int len , int last , int sz ){
    if( len == sz ){
        for( int i = 0 ; i < sz ; ++i ){
            if( i ) printf(", ");
            printf("%s" , name[ ans[ i ] ] );
        }
        printf("\n");
        return ;
    }

    for( int i = last ; i < n ; ++i ){
        if( seen[ i ] )continue;
        seen[ i ] = 1;
        ans[ len ] = i;
        solve( len + 1 , i , sz );
        seen[ i ] = 0;
    }
}

int main(){
    int t , a , b , l ;
    char s[ MAX ] , *p;
    for ( scanf( "%d", &t ); t-- > 0 && scanf(" %[^\n]\n", s ) == 1 ; ) {

        if( s[ 0 ] == '*' ){
            a = 1;
            b = 0;
        }
        else if( sscanf( s , "%d %d", &a , &b ) == 1 ) {
            b = a;
        }
        for ( n = 0 ; gets( name[ n ] ) && name[ n ][ 0 ] != '\0'; n++ );
        if( b == 0 ) b = n;
        for( ; a <= b ; ++a ){
            printf("Size %d\n" , a );
            memset( seen , 0 , sizeof( seen  ) );
            solve( 0 , 0 , a );
            printf("\n");
        }
        if( t != 0 ) printf("\n");
    }
    return 0;
}
