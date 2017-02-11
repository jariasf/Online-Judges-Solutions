/*****************************************
 ***Problema: Deciding victory in Go
 ***ID: 852
 ***Juez: UVA
 ***Tipo: Graph Theory, Flood Fill
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
#define MAX 130
char ady[ MAX ][ MAX ];
int blanco, negro, cnt;

void dfs( int x , int y ){
    if( x < 0 || y < 0 || x >= 9 || y >= 9 || ady[ x ][ y ] == '#') return;
    if( ady[ x ][ y ] == 'O' ){ blanco++; return;}
    else if( ady[ x ][ y ] == 'X'){ negro++; return; }
    ady[ x ][ y ] = '#';
    cnt++;
    dfs( x + 1 , y );
    dfs( x - 1 , y );
    dfs( x , y + 1 );
    dfs( x , y - 1 );

}

int main(){
    int t, B , N;
    scanf("%d" , &t );

    while( t-- ){
        for( int i = 0 ; i < 9 ; ++i )scanf( "%s" , ady[ i ] );
        B = N = 0;
        for( int i = 0 ; i < 9 ; ++i ){
            for( int j = 0 ; j < 9 ; ++j ){
                if( ady[ i ][ j ] == '.'){
                    blanco = negro = 0; cnt = 0;
                    dfs( i , j );
                    if( blanco == 0 && negro > 0  ) N += cnt;
                    else if( negro == 0 && blanco > 0 ) B += cnt;
                }
                else if( ady[ i ][ j ] == 'O') B++;
                else if( ady[ i ][ j ] == 'X') N++;
            }
        }
        printf("Black %d White %d\n" , N , B );
    }
    return 0;
}
