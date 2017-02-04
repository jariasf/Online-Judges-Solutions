/*****************************************
 ***Problema: Correct Move
 ***ID: 255
 ***Juez: UVA
 ***Tipo: Ad hoc
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

int table[ 64 ][ 64 ];
int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };
int w = 8;
int main(){

    int k , q , Q, xk , yk , xq , yq , x , y;
    bool stop;
    while( scanf("%d %d %d" , &k ,&q , &Q ) != EOF ){
        if(  k == q ){
            puts("Illegal state");
            continue;
        }
        stop = true;
        yq = q % w;
        xq = ( q - yq ) / w;

        yk = k % w;
        xk = ( k - yk ) / w;

        memset( table , 0 , sizeof( table ) );
        for( int i = 0 ; i < 4 ; ++i ){

            int nx = xk + dx[ i ], ny = yk + dy[ i ];

            if( nx >= 0 && ny >= 0 && nx < w && ny < w ){
                table[ nx ][ ny ] = 'K';
            }
        }

        for( int i = 0 ; i < 4 ; ++i ){
            int c = 1;
            while( 1 ){
                int nx = xq + c * dx[ i ], ny = yq + c * dy[ i ];
                if( nx == xk && ny == yk )break;
                if( nx >= 0 && ny >= 0 && nx < w && ny < w ){
                    if( table[ nx ][ ny ] == 'K'){
                        table[ nx ][ ny ] = 'A'; //not allowed
                    }
                    else table[ nx ][ ny ] = 'Q';
                }
                else break;
                c++;
            }
        }

        y = Q % w;
        x = ( Q - y ) / w;
        table[ xk ][ yk ] = 0;
        table[ xq ][ yq ] = 0;

        if( table[ x ][ y ] == 'K' || !table[ x ][ y ] ) puts("Illegal move");
        else if( table[ x ][ y ] == 'A' )puts("Move not allowed");
        else if( ( k == 0 && Q == 9) || ( k == 7 && Q == 14) ||
        ( k == 56 && Q == 49 ) || (k  == 63 && Q == 54)) printf("Stop\n");
        else   printf("Continue\n");
    }

    return 0;
}
