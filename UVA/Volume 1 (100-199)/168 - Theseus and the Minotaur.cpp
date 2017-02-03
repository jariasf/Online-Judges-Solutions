/*****************************************
 ***Problema: Theseus and the Minotaur
 ***ID: 168
 ***Juez: UVA
 ***Tipo: DFS
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

char s[ 260 ];
#define MAX 30
char t , m;
int k;
vector< int > ady[ MAX ];
bool light[ MAX ];
void dfs( int source , int len , int minotaur  ){
    if( len != 0 && len % k == 0 ){
        if( !light[ source ] ) printf("%c " , source + 'A' );
        light[ source ] = 1;
    }
    bool enter = false;
    int j , v;
    for( j = 0 ; j < ady[ minotaur ].size() ; ++j ){
        v = ady[ minotaur ][ j ];
        if( !light[ v ] && v != source && v != minotaur ){
            enter = true;
            dfs( minotaur , len + 1 , v );
            break;
        }
    }
    if( !enter ){
        printf("/%c\n" , minotaur + 'A' );
        return;
    }
}

int main(){
    int len , i , j , cnt;
    while( scanf("%s" , &s ) , s[ 0 ] != '#'){
        len = strlen( s );
        for( i = 0 ; i < len ; ++i ) if( s[ i ] == ';' || s[ i ] == '.' ) s[ i ] = ' ';
        scanf(" %c %c %d" , &m , &t ,&k );
        stringstream ss( s );
        while( ss>>s ){
            for( i = 2 ; s[ i ] ; ++i ){
                ady[ s[ 0 ] - 'A' ].push_back( s[ i ] - 'A' );
            }
        }
        memset( light , 0 , sizeof( light ) );
        dfs( t - 'A' , 0 , m - 'A' );
        for( i = 0 ; i < MAX ; ++i ) ady[ i ].clear();
    }
    return 0;
}
