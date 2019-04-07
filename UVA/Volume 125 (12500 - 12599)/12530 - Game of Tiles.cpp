/*****************************************
 ***Problema: Game of Tiles
 ***ID: 12530
 ***Juez: UVA
 ***Tipo: Bipartite Matching
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;
#define MAX 55
int w , h;
char table[ MAX ][ MAX ];

#define MAXL 5005
#define MAXR 10005
int seen[ MAXL ], matchL[ MAXL ] , matchR[ MAXR ] , L , R;
bool visto[ MAXL ];
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
    L = h * w;
    while( change ){
        change = false;
        memset( seen , 0 , sizeof( seen ) );
        for( i = 0; i < L ; ++i ){
            if( matchL[ i ] == -1 && visto[ i ] ) change |= bpm( i );
        }
    }
    int ret = 0;
    for( i = 0 ; i < L ; ++i )
        if( matchL[ i ] != -1 && visto[ i ] ) ++ret;
    return ret;
}

int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };
int getId( int x , int y ){ return x * w + y; }
int main(){
    int i , j , k , nx , ny , p;
    while( scanf("%d %d" , &h , &w ) != EOF ){
        for( i = 0 ; i < h && scanf("%s" , table[ i ] ); ++i );
        memset( visto , 0 , sizeof( visto ) );
        p = 0;
        for( i = 0 ; i < h ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                if( table[ i ][ j ] == '.' ){
                    p++;
                    visto[ getId( i, j ) ] = 1;
                    for( k = 0 ; k < 4 ; ++k ){
                        nx = dx[ k ] + i;
                        ny = dy[ k ] + j;
                        if( nx >= 0 && ny >= 0 && nx < h && ny < w && table[ nx ][ ny ] == '.' ){
                            ady[ getId( i , j ) ].push_back( getId( nx , ny ) + h * w );
                        }
                    }
                }
            }
        }
        if( hopcroft_karp() == p ) puts("2");
        else puts("1");
        for( i = 0 ; i <= 2 * h * w  ; ++i ) ady[ i ].clear();
    }
    return 0;
}
