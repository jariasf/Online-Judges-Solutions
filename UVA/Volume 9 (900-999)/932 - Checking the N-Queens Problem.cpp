/*******************************************
 ***Problema: Checking the N-Queens Problem
 ***ID: 932
 ***Juez: UVA
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define MAX 35
#define pii pair<int ,int>
#define mp make_pair
#define x first
#define y second
int n;
char ady[ MAX ][ MAX ];
int dx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int dy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1};

int abs( int x ){ return ( x < 0 )? -x: x; }
vector< pii > Q;
bool valid( vector< pii > v ){
    int len = v.size() , x1 , y1 , x2 , y2;
    for( int i = 0 ; i < len ; ++i ){
        x1 = v[ i ].x; y1 = v[ i ].y;
        for( int j = i + 1 ; j < len ; ++j ){
            x2 = v[ j ].x; y2 = v[ j ].y;
            if( abs( x1 - x2 ) == abs( y1 - y2 ) || x1 == x2 || y1 == y2 ) return false;
        }
    }
    return true;
}

bool solve( ){
    int len = Q.size() , x1 , y1 , x2 , y2 ,nx , ny;
    vector<pii> v, aux;
    for( int i = 0 ; i < len ; ++i ){
        x1 = Q[ i ].x; y1 = Q[ i ].y;
        v.clear();
        for( int j = 0 ; j < len ; ++j ) if( i != j ) v.push_back( Q[ j ] );
        int k = -1;
        for( int k = 0 ; k < 8 ; ++k ){
            int c = 0;
            while( 1 ){
                c++;
                nx = dx[ k ] * c + x1; ny = dy[ k ] * c + y1;
                if( nx >= 0 && nx < n && ny >= 0 && ny < n ){
                    aux = v;
                    aux.push_back( pii( nx , ny ) );
                    if( valid( aux ) ){
                        ady[ x1 ][ y1 ] = '0';
                        ady[ nx ][ ny ] = 'X';
                        return true;
                    }
                }else break;
            }
        }
    }
    return false;
}

int main(){
    bool first = true;
    while( scanf("%d" , &n ) == 1 ){
        if( !first ) putchar('\n');
        first = false;
        Q.clear();
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                scanf(" %c" , &ady[ i ][ j ] );
                if( ady[ i ][ j ] == 'X' ){
                    Q.push_back( pii( i , j ) );
                }
            }
        }

        if( valid( Q ) ) puts("YES");
        else{
            puts("NO");
            if( solve() ){
                puts("YES");
                for( int i = 0 ; i < n ; ++i )
                {
                    for( int j = 0 ; j < n ; ++j )
                        printf("%c" , ady[ i ][ j ] );
                    printf("\n");
                }
            }
            else puts("NO");
        }
    }
    return 0;
}
