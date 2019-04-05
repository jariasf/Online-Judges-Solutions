/*****************************************
 ***Problema: Words
 ***ID: 12491
 ***Juez: UVA
 ***Tipo: Automatas de estados finitos
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 25
char s[ 2 ][ MAX ][ 45 ];
int n1 , n2;
bool seen[ MAX ][ 45 ][ 2 ];
bool dfs( int len , int pos , int actual ){

    int i , l1 , l2 , mini , j , sz = ( actual == 0 ? n2 : n1);
    bool b = false;
    for( i = 0 ; i < sz ; ++i ){
        l2 = strlen( s[ actual ^ 1 ][ i ] );
        l1 = strlen( s[ actual ][ len ] );
        mini = min( l2 , l1 - pos );
        for( j = 0 ; j < mini ; ++j )
            if( s[ actual ][ len ][ j + pos ] != s[ actual ^ 1 ][ i ][ j ] ) break;
        //se relaciona
        if( j == mini ){
            if( j == l1 - pos && j == l2 ) return true;
            if( l1 - pos < l2 ){
                if( !seen[ i ][ j ][ actual ^ 1 ] ){
                    seen[ i ][ j ][ actual ^ 1 ] = 1;
                    b |= dfs( i , j , actual ^ 1 );
                }
            }
            else{
                if( !seen[ len ][ pos + j ][ actual ] ){
                    seen[ len ][ pos + j ][ actual ] = 1;
                    b |= dfs( len , pos + j , actual );
                }
            }
        }
    }
    return b;
}


int main(){
    int i;
    while( scanf("%d %d" , &n1 , &n2 ) != EOF ){
        for( i = 0 ; i < n1 && scanf("%s" , &s[ 0 ][ i ] ) ; ++i );
        for( i = 0 ; i < n2 && scanf("%s" , &s[ 1 ][ i ] ) ; ++i );
        memset( seen , 0 , sizeof( seen ) );
        for( i = 0 ; i < n1 ; ++i ) if( dfs( i , 0 , 0 ) ) break;
        if( i == n1 ) puts("N");
        else puts("S");
    }
    return 0;
}
