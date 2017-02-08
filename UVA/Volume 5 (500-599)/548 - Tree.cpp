/*****************************************
 ***Problema: Tree
 ***ID: 548
 ***Juez: UVA
 ***Tipo: Tree Traversal
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 100005
char s[ MAX ];
int in[ MAX ] , pos[ MAX ];
int mini , min_vertex;
void solve( int l_i , int len_in , int l_p , int len_pos , int sum ){
    if( len_pos <= 0 ) return;
    int root = pos[ len_pos - 1 ] , i;
    //si es hoja
    if( l_i + 1 == len_in ){
        if( sum + in[ l_i ] < mini ){
            mini = sum + in[ l_i ];
            min_vertex = in[ l_i ];
        }
        else if( sum + in[ l_i ] == mini ){
            min_vertex = min( min_vertex , in[ l_i ] );
        }
        return;
    }

    for( i = l_i ; i < len_in ; ++i ){
        if( in[ i ] == root ){
            break;
        }
    }

    if( i == len_in ) return;
    solve( l_i , i , l_p , l_p + i - l_i , sum + root );
    solve( i + 1 , len_in , len_pos - ( len_in - i ) , len_pos - 1 , sum + root );
}

int main(){
    int len_in , len_pos;
    int len , i , j;
    while( gets( s ) ){
        len_in = len_pos = 0;
        stringstream ss( s );
        while( ss>>in[ len_in ] )len_in++;
        gets( s );
        stringstream ss2( s );
        while( ss2>>pos[ len_pos ] )len_pos++;
        mini = min_vertex = 1<<30;
        solve( 0 , len_in , 0 , len_pos , 0 );
        printf("%d\n" , min_vertex );
    }
    return 0;
}
