/*****************************************
 ***Problema: Knights in FEN
 ***ID: 10422
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, MAP
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

int dx[ 8 ]={ -2 , -2 , -1 , -1 ,  1 , 1 ,  2 , 2 };
int dy[ 8 ]={ -1 ,  1 , -2 ,  2 , -2 , 2 , -1 , 1 };

struct Nodo{
    char ady[ 5 ][ 5 ];
    int d;
};

bool ok( char str[ ]){
    if( strcmp( str , "111110111100 110000100000") == 0 ) return true;
    return false;
}
char a[ 5 ][ 6 ] , ini[ 26 ];

int bfs( ){

    queue< Nodo> Q;
    Nodo nodo;

    for( int i = 0 ; i < 5 ; ++i ){
        for( int j = 0 ; j < 5 ; ++j ){
            nodo.ady[ i ][ j ] = a[ i ][ j ];
        }
    }

    nodo.d = 0;
    Q.push( nodo );
    map<string, bool > seen;
    seen[ ini ] = true;
    while( !Q.empty() ){
        Nodo act = Q.front(); Q.pop();

        for( int i = 0 ; i < 5 ; ++i ){
            int j = 0;
            for( ; j < 5 ; ++j ){

                if( act.ady[ i ][ j ] == ' '){

                    for( int k = 0 ; k < 8 ; ++k ){
                        int nx = i + dx[ k ];
                        int ny = j + dy[ k ];
                        if( nx >= 0 && nx < 5 && ny >= 0 && ny < 5  ){
                            Nodo vec;

                            for( int q = 0; q < 5 ; ++q ){
                                for( int k = 0 ; k < 5 ; ++k ){
                                    a[ q ][ k ] = act.ady[ q ][ k ];
                                }
                            }

                            a[ i ][ j ] = a[ nx ][ ny ];
                            a[ nx ][ ny ] = ' ';

                            int idx = 0;
                            for( int q = 0; q < 5 ; ++q ){
                                for( int k = 0 ; k < 5 ; ++k ){
                                    ini[ idx++ ] = a[ q ][ k ];
                                    vec.ady[ q ][ k ] = a[ q ][ k ];
                                }
                            }
                            ini[ idx ] = '\0';
                            if( !seen[ ini ] ){
                                seen[ ini ] = true;
                                vec.d = act.d + 1;

                                if( ok( ini ) ){
                                    return vec.d;
                                }

                                if( vec.d > 10 )return -1;
                                Q.push( vec );
                            }
                        }
                    }
                    break;
                }
            }
            if( j != 5 )break;
        }
    }
    return -1;

}

int main(){

    int t , idx;
    scanf("%d" ,&t );
    getchar();

    while( t-- ){
        idx = 0;
        for( int i = 0 ; i < 5 ; ++i ){
            gets( a[ i ] );

            for( int j = 0 ; j < 5 ; ++j ){
                ini[ idx++ ] = a[ i ][ j ];
            }
        }
        ini[ idx ] = '\0';
        if( ok( ini ) ) {printf("Solvable in 0 move(s).\n"); continue;}
        int resp = bfs( );
        if( resp == -1 )printf("Unsolvable in less than 11 move(s).\n");
        else printf("Solvable in %d move(s).\n" , resp );
    }

    return 0;
}
