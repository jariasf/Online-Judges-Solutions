/*****************************************
 ***Problema: Fix the Pond
 ***ID: 12529
 ***Juez: UVA
 ***Tipo: Flood Fill
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 805

struct Cell{
    int right , left , up , down;
    Cell(){}
    Cell( int r , int l , int u , int d ) : right( r ) , left( l ) , down( d ) , up( u ) {}
}table[ MAX ][ MAX ];

char ady[ MAX ][ MAX ] ;
int h , w , seen[ MAX ][ MAX ];
int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };

#define pii pair< int , int >
#define mp make_pair
void flood( int x , int y ){
    queue< pii > Q;
    Q.push( mp( x , y ) );
    seen[ x ][ y ] = 1;
    while( !Q.empty() ){
        pii act = Q.front(); Q.pop();
        x = act.first; y =  act.second;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = dx[ i ] + x , ny = dy[ i ] + y;
            if( nx < 0 || ny < 0 || nx >= h || ny >= w || seen[ nx ][ ny ] ) continue;
            if( i == 0 && table[ x ][ y ].down == 0 ){
                Q.push( mp( nx , ny ) );
                seen[ nx ][ ny ] = 1;
            }
            else if( i == 1 && table[ x ][ y ].up == 0 ){
                Q.push( mp( nx , ny ) );
                seen[ nx ][ ny ] = 1;
            }
            else if( i == 2 && table[ x ][ y ].right == 0 ){
                Q.push( mp( nx , ny ) );
                seen[ nx ][ ny ] = 1;
            }
            else if( i == 3 && table[ x ][ y ].left == 0 ){
                Q.push( mp( nx , ny ) );
                seen[ nx ][ ny ] = 1;
            }
        }
    }
}

int main(){
    int n , i , j , k ,a , b , ans;
    while( scanf("%d" , &n ) != EOF ){
        for( i = 0 ; i < 2 * n - 1 && scanf("%s" , ady[ i ] ); ++i );
        h = 2 * n;
        w = 2 * n + 1;
        for( i = 0 ; i < h ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                table[ i ][ j ] = Cell( 0 , 0 , 0 ,0 );
                seen[ i ][ j ] = 0;
            }
        }

        for( i = 0 , a = 1 ; i < 2 * n - 1 ; ++i , ++a ){
            b = 1;
            if( a % 2 == 0 ) b = 2;
            for( j = 0 ; j < n ; ++j , b += 2 ){
                if( ady[ i ][ j ] == 'H' ){
                    table[ a - 1 ][ b - 1 ].down = 1;
                    table[ a - 1 ][ b ].down = 1;
                    table[ a ][ b - 1 ].up = 1;
                    table[ a ][ b ].up = 1;
                }
                else{
                    table[ a - 1 ][ b - 1 ].right = 1;
                    table[ a ][ b - 1 ].right = 1;
                    table[ a - 1 ][ b  ].left = 1;
                    table[ a ][ b ].left = 1;
                }
            }
        }

        ans = 0;
        for( i = 0 ; i < h ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                if( !seen[ i ][ j ] ){
                    flood( i , j );
                    ans++;
                }
            }
        }
        printf("%d\n" , ans - 1 );
    }

    return 0;
}
