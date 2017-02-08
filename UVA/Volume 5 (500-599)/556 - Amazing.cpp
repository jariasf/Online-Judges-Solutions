/*****************************************
 ***Problema: Amazing
 ***ID: 556
 ***Juez: UVA
 ***Tipo: Simulation
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
#define MAX 305
#define E 0
#define N 1
#define W 2
#define S 3
//izquierda , arriba , derecha , abajo
int dx[ 4 ] = { 0 , -1 ,  0 , 1 };
int dy[ 4 ] = { 1 ,  0 , -1 , 0 };

int main(){
    int h , w , x , y , dir , nx , ny , lx , ly;
    char ady[ MAX ][ MAX ];
    int seen[ MAX ][ MAX ];
    int ans[ 5 ];
    bool out , enter;
    while( scanf("%d %d" , &h , &w ) , h | w ){

        for( int i = 0 ; i < h ; ++i ) scanf("%s" , ady[ i ] );

        x = h - 1; y = 0; dir = E;
        memset( seen , 0 , sizeof( seen  ) );
        out = false;
        while( 1 ){
            nx = dx[ dir ] + x; ny = dy[ dir ] + y;
            //extremos
            if( ny == w  ){
                if( x + dx[ S ] < h && ady[ x + dx[ S ] ] [ y ] == '0' ) dir = S;
                else if( x + dx[ N ] < h && ady[ x + dx[ N ] ] [ y ] == '0' ) dir = N;
                else dir = W;
                out = true;
            }
            else if( ny == -1 ){
                if( x + dx[ N ] >= 0 && ady[ x + dx[ N ] ] [ y ] == '0' ) dir = N;
                else if( x + dx[ S ] >= 0 && ady[ x + dx[ S ] ] [ y ] == '0' ) dir = S;
                else dir = E;
                out = true; }
            else if( nx == -1 ){
                if( y + dy[ E ] < w && ady[ x ][ y + dy[ E ] ] =='0' ) dir = E;
                else if( y + dy[ W ] < w && ady[ x ][ y + dy[ W ] ] =='0' )  dir = W;
                else dir = S;
                out = true;
            }
            else if( nx == h  ){
                if( y + dy[ W ] >= 0 && ady[ x ][ y + dy[ W ] ] =='0' ) dir = W;
                else if( y + dy[ E ] < w && ady[ x ][ y + dy[ E ] ] == '0' ) dir = E;
                else dir = N;
                out = true;
            }

            //cuando choco a pared
            else if( ady[ nx ][ ny ] == '1' ){
                out = false;
                if( dir == W ){
                    //caso
                    //000
                    //001
                    //100
                    if( x + dx[ N ] >= 0 && ady[ x + dx[ N ] ][ y ] == '0') dir = N;
                    else dir = S;
                }else if( dir == S ){ // si choco abajo con pared tengo 2 opciones
                    if( y + dy[ W ] >= 0 && ady[ x ][ y + dy[ W ] ] == '0') dir = W;
                    else dir = E;
                }
                else if( dir == N ){
                    if( y + dy[ E ] < w && ady[ x ][ y + dy[ E ] ] == '0' ) dir = E;
                    else dir = W;
                }
                else if( dir == E ){
                    if( x + dx[ S ] < h && ady[ x + dx[ S ] ][ y ] == '0') dir = S;
                    else dir = N;
                }
            }
            //si tengo espacio pa reccorer en otra direccion
            else if( x + dx[ N ] != lx && x + dx[ N ] >= 0 && ady[ x + dx[ N ] ][ y ] == '0' && dir == W && !out ){ dir = N;}
            else if( y + dy[ W ] != ly && y + dy[ W ] >= 0 && ady[ x ] [ y + dy[ W ] ] == '0' && dir == S && !out ) dir = W; //si bajo y hay espacio en el oeste
            else if( y + dy[ E ] != ly && y + dy[ E ] < w && ady[ x ][ y+ dy[ E ] ] =='0' && dir == N && !out )dir = E;
            else if( x + dx[ S ] != lx && x + dx[ S ] < h && ady[ x + dx[ S ] ][ y ] == '0' && dir == E && !out ) dir = S;
            //11Y
            //1 Y  tengo q ir al oeste y no abajo
            //11
            else{
                lx = x;
                ly = y;
                x = nx;
                y = ny;
                seen[ x ][ y ]++;
                out = false;
                if( x == h - 1 && y == 0 )break;
            }
        }

        memset( ans , 0 , sizeof( ans ) );
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( ady[ i ][ j ] == '0')ans[ seen[ i ][ j ] ]++;
            }
        }
        printf("%3d%3d%3d%3d%3d\n" , ans[ 0 ] , ans[ 1 ] , ans[ 2 ] , ans[ 3 ] , ans[ 4 ] );

    }
    return 0;
}
/*
TEST CASES
6 6
001010
010010
000010
000000
011010
011000
7 6
001000
000001
011010
000000
011010
011000
011000
4 4
0000
0000
0000
0000
5 4
0000
0001
1010
0000
0010
6 7
0010100
0010100
0000001
0100100
0100100
0100100
*/
