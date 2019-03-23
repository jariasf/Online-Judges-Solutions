/*****************************************
 ***Problema: Dig the Holes
 ***ID: 11412
 ***Juez: UVA
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
char c[ 7 ] = { 'R' , 'G' , 'B' , 'Y' , 'O' , 'V' };
vector<string> v;
int seen[ 30 ][ 30 ][ 30 ][ 30 ] = { 0 };
void cal(){
    int a[ 7 ] = { 0 , 1 , 2 , 3 , 4 , 5};
    string s;
    do{
        if( seen[ c[ a[ 0 ] ] - 'A' ][ c[ a[ 1 ] ] - 'A' ][ c[ a[ 2 ] ] - 'A' ][ c[ a[ 3 ] ] - 'A' ] )continue;
        s = "";
        for( int i = 0 ; i < 4 ; ++i ) s += c[ a[ i ] ];
        seen[ c[ a[ 0 ] ] - 'A' ][ c[ a[ 1 ] ] - 'A' ][ c[ a[ 2 ] ] - 'A' ][ c[ a[ 3 ] ] - 'A' ] = 1;
        v.push_back( s );
    }while( next_permutation( a , a + 6 ) );
}

int t, n1[ 3 ], n2[ 3 ] , n;
char s[ 3 ][ 5 ];

bool valid( string ss , int idx ){
    int seen[ 27 ] = { 0 }, eq = 0 , a[ 27 ] = { 0 } , b[ 27 ] = { 0 };
    for( int i = 0 ; i < 4 ; ++i ){
        if( ss[ i ] == s[ idx ][ i ] ) eq++;
        else{ a[ ss[ i ] - 'A' ]++; b[ s[ idx ][ i ] - 'A' ]++; }
    }
    if( eq != n1[ idx ] ) return false;
    eq = 0;
    for( int i = 0 ; i < 26 ; ++i ){
        if( a[ i ] && b[ i ] )eq += min( a[ i ] , b[ i ] );
    }
    if( eq == n2[ idx ] )return true;
    return false;
}

int main(){
    scanf("%d" , &t );
    cal();
    int i;
    n = v.size();
    while( t-- ){
        scanf("%s %d %d" , &s[ 0 ] , &n1[ 0 ] , &n2[ 0 ] );
        scanf("%s %d %d" , &s[ 1 ] , &n1[ 1 ] , &n2[ 1 ] );
        for( i = 0 ; i < n ; ++i ){
            if( valid( v[ i ] , 0 ) && valid( v[ i ] , 1 ) ){ break;}
        }
        if( i == n )puts("Cheat");
        else puts("Possible");
    }
    return 0;
}
