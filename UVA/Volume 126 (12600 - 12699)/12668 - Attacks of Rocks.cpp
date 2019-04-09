/*****************************************
 ***Problema: Attacks of Rocks
 ***ID: 12668
 ***Juez: UVA - ICPC
 ***Tipo: Max Flow
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
#define MAX 105
int n;
char grid[ MAX ][ MAX ];

#define MAXL 10005
#define MAXR 10005
int seen[ MAXL ], matchL[ MAXL ] , matchR[ MAXR ] , L , R;
vector< int > ady[ MAXL ];
int bpm( int left ){
    if( seen[ left ] ) return 0;
    seen[ left ] = 1;
    int right , i;
    for( i = 0 ; i < ady[ left ].size() ; ++i ){
        right = ady[ left ][ i ];
        if( matchR[ right ] == -1 || bpm( matchR[ right ] ) ){
            matchR[ right ] = left;
            matchL[ left ] = right;
            return 1;
        }
    }
    return 0;
}

int hopcroft_karp(){
    bool change = true;
    memset( matchR , -1 , sizeof( matchR ) );
    memset( matchL , -1 , sizeof( matchL ) );
    int i;
    while( change ){
        change = false;
        memset( seen , 0 , sizeof( seen ) );
        for( i = 0; i < L ; ++i ){
            if( matchL[ i ] == -1 ) change |= bpm( i );
        }
    }
    int ret = 0;
    for( i = 0 ; i < L ; ++i )
        if( matchL[ i ] != -1 ) ++ret;
    return ret;
}

int row[ MAX ][ MAX ] , col[ MAX ][ MAX ];
int main(){
    char c;
    while( scanf("%d" , &n ) != EOF ){
        for( int i = 0 ; i < n && scanf("%s" , grid[ i ] ) ; ++i );

        int rows , cols;
        rows = cols = 0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( grid[ i ][ j ] == '.' ){
                    row[ i ][ j ] = rows;
                    while( j < n && grid[ i ][ j ] == '.' ){
                        row[ i ][ j ] = rows;
                        j++;
                    }
                    rows++;
                }
            }
        }

        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( grid[ j ][ i ] == '.' ){
                    col[ j ][ i ] = cols;
                    while( j < n && grid[ j ][ i ] == '.' ){
                        col[ j ][ i ] = cols;
                        j++;
                    }
                    cols++;
                }
            }
        }

        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( grid[ i ][ j ] == '.' ){
                    ady[ row[ i ][ j ] ].push_back( col[ i ][ j ] );
                }
            }
        }

        L = rows; R = cols;
        printf("%d\n" , hopcroft_karp() );

        for( int i = 0 ; i <= L ; ++i )
            ady[ i ].clear();
    }
    return 0;
}
