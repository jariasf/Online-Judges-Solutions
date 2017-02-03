/*****************************************
 ***Problema: Anagram
 ***ID: 195
 ***Juez: UVA
 ***Tipo: Recursion, sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 105

bool seen[ MAX ];
char s[ MAX ];
int l;
char resp[ MAX ];

int cmp(char a , char b)
{
    if( islower( a ) && islower( b ) ) return a < b;
    if( isupper( a ) && isupper( b ) ) return a < b;
    if( islower( a ) && isupper( b ) ) return a < ( b - 'A' + 'a');
    if( isupper( a ) && islower( b ) ) return a <= ( b - 'a' + 'A');
}

void solve( int len ){

    if( len == l ){
        printf("%s\n" , resp );
        return;
    }

    for( int i = 0 ; i < l ; ++i ){
        if( seen[ i ] )continue;
        resp[ len ] = s[ i ];
        seen[ i ] = 1;
        solve( len + 1 );
        seen[ i ] = 0;
        while( i < (l - 1) && s[ i ] == s[ i + 1 ] )i++;
    }
}

int main(){

    int t ;
    scanf( "%d" , &t );

    while( t-- ){

        scanf("%s" , &s );
        l = strlen( s );
        sort( s , s + l , cmp );
        resp[ l ] = '\0';
        memset( seen , 0 , sizeof( seen ) );
        solve( 0 );
    }

    return 0;
}
