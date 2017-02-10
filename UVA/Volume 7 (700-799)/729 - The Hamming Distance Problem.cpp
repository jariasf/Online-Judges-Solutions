/*****************************************
 ***Problema: The Hamming Distance Problem
 ***ID: 729
 ***Juez: UVA
 ***Tipo: Backtracking, brute force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int sz, n;
int bitcount( int n ){
    int cnt = 0;
    while( n ){
        n = n & ( n - 1 );
        cnt++;
    }
    return cnt;
}

void print( int x ){
    int bits[ 32 ] = { 0 };
    for( int i = 0 ; i < 32 ; ++i ) if( x & 1<<i ) bits[ i ] = 1;
    for( int i = n - 1 ; i >= 0 ; --i ) printf("%d" , bits[ i ] );
    printf("\n");
}

int main(){
    int t;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &n , &sz );
        for( int i = 1 ; i < 1<<n ; ++i )
            if( bitcount( i ) == sz ) print( i );
        if( t ) printf("\n");
    }
    return 0;
}
