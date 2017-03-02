/*****************************************
 ***Problema: Help the Leaders
 ***ID: 10475
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Tiempo: 0.032
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

bool isLowerCase(char c){return c>='a' && c<='z';}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}
int n , sz;
string name[ 25 ];
bool cmp( string s1 , string s2 ){
    int l1 = s1.length() , l2 = s2.length();
    return l1 > l2 || ( l1 == l2 && s1 < s2 );
}
bool visto[ 25 ][ 25 ];
bool seen[ 25 ];
int ans[ 25 ];
void solve( int len , int last ){

    if( len == sz ){
        for( int i = 0 ; i < len ; ++i ){
            for( int j = i + 1 ; j < len ; ++j ){
                if( visto[ ans[ i ] ][ ans[ j ] ] || visto[ ans[ j ] ][ ans[ i ] ] )return;
            }
        }
        for( int i = 0 ; i < sz ; ++i ){
            if( i ) printf(" ");
            printf("%s" , name[ ans[ i ] ].c_str() );
        }
        printf("\n");
        return;
    }
    for( int i = last ; i < n ; ++i ){
        if( !seen[ i ] ){
            seen[ i ] = 1;
            ans[ len ] = i;
            solve( len + 1 , i );
            seen[ i ] = 0;
        }
    }
}


int main(){
    int t , p;
    char s1[ 25 ][ 25 ], s2[ 25 ][ 25 ] , s[ 25 ];
    scanf("%d" , &t );
    for( int q = 1 ;  q <= t ; ++q ){
        scanf("%d %d %d" , &n , &p , &sz );
        for( int i = 0 ; i < n ; ++i ) {
            scanf("%s" , &s );
            name[ i ] = "";
            for( int j = 0 ; s[ j ] ; ++j ) name[ i ]+= toUpperCase( s[ j ] );
        }
        for( int i = 0 ; i < p ; ++i ){
            scanf("%s %s" , &s1[ i ] , &s2[ i ] );
            for( int j = 0 ; j < s1[ i ][ j ] ; ++j ) s1[ i ][ j ] = toUpperCase( s1[ i ][ j ] );
            for( int j = 0 ; j < s2[ i ][ j ] ; ++j ) s2[ i ][ j ] = toUpperCase( s2[ i ][ j ]);
        }
        sort( name , name + n , cmp );
        memset( visto , 0 , sizeof( visto ) ) ;
        memset( seen , 0 , sizeof( seen ) );
        int idx1 = 0 , idx2 = 0;
        for( int i = 0 ; i < p ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( name[ j ] == string( s1[ i ] )){
                    idx1 = j;
                    break;
                }
            }
            for( int j = 0 ; j < n ; ++j ){
                if( name[ j ] == string( s2[ i ] ) ){
                    idx2 = j;
                    break;
                }
            }
            visto[ idx1 ][ idx2 ] = visto[ idx2 ][ idx1 ] = 1; //para prohibiciones
        }
        printf("Set %d:\n" , q );
        solve( 0 , 0 );
        printf("\n");
    }

    return 0;
}
