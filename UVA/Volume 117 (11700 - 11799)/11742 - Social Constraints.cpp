/*****************************************
 ***Problema: Social Constraints
 ***ID: 11742
 ***Juez: UVA
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 22
int abs( int x ){ return( x < 0 )?-x:x;}
int a[ MAX ], b[ MAX ] , c[ MAX ] , p[ 9 ];
int n , m;

bool valid(){
    for( int i = 0 ; i < m ; ++i ){
        if( c[ i ] < 0 ){
            if( abs( p[ a[ i ] ] - p[ b[ i ] ] ) < -c[ i ] ) return false;
        }
        else{
            if( abs( p[ a[ i ] ] - p[ b[ i ] ] ) > c[ i ] ) return false;
        }
    }
    return true;
}

int main(){
    int ans = 0;
    while( scanf("%d %d"  ,&n , &m ) , n | m ){
        for( int i = 0 ; i < m ; ++i ) scanf("%d %d %d" , &a[ i ] , &b[ i ] , &c[ i ] );
        for( int i = 0 ; i < n ; ++i ) p[ i ] = i;
        ans = 0;
        do{
            if( valid() ) ans++;
        }while( next_permutation( p , p + n ) );
        printf("%d\n" , ans );
    }

    return 0;
}
