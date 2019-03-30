/*****************************************
 ***Problema: Throught the Desert
 ***ID: 11935
 ***Juez: UVA
 ***Tipo: Binary Search The Asnwer
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 55
int x[ MAX ] , n[ MAX ] , len;
char s[ MAX ][ MAX ] , cad[ MAX ];

bool correct( double f ){
    int leak = 0;
    double fuel  = f , cons = n[ 0 ];
    for( int i = 1 ; i < len ; ++i ){
        fuel -= ( x[ i ] - x[ i - 1 ] ) * leak;
        fuel -= ( x[ i ] - x[ i - 1 ] ) * cons / 100.0;
        if( fuel < 0.0 ) return false;
        if( s[ i ][ 0 ] == 'F' ){
            cons = n[ i ];
        }
        else if( s[ i ][ 0 ] == 'G'){
            if( s[ i ][ 1 ] == 'a' && fuel >= 0  )fuel = f;
        }
        else if( s[ i ][ 0 ] == 'M' ){
            leak = 0;
        }
        else if( s[ i ][ 0 ] == 'L' ){
            leak++;
        }
    }
    if( fuel < 0.0 ) return false;
    return true;
}


int main(){

    double left , right , mid , ans;
    while( scanf("%d %s %s %d" , &x[ 0 ] , &s[ 0 ] , &cad , &n[ 0 ] ) , n[ 0 ]  ){
        len = 1;
        while( scanf("%d %s" , &x[ len ] , &s[ len ] ) ){
            if( s[ len ][ 0 ] == 'F' ){
                scanf("%s %d" , &cad , &n[ len ] );
            }
            if( s[ len ][ 0 ] == 'G' ){
                if( s[ len ][ 1 ] == 'a' ) scanf("%s" , &cad );
                else{
                    len++;
                    break;
                }
            }
            len++;
        }
        left = 0; right = 10000;
        ans = 0;
        for( int i = 0 ; i < 50 ; ++i ){
            mid = ( left + right )/2.0;
            if( correct( mid ) ){
                ans = mid;
                right = mid;
            }
            else left = mid;
        }
        printf("%.3lf\n" , ans );
    }
    return 0;
}
