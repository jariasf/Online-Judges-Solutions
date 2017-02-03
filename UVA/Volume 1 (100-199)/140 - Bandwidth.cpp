/*****************************************
 ***Problema: Bandwidth
 ***ID: 140
 ***Juez: UVA
 ***Tipo: Backtracking
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
#define MAX 27
vector<int> ady[ MAX ];
bool seen[ MAX ], visited[ MAX ], connected[ MAX ][ MAX ];
int pos[ MAX ];
int len, mini;
string resp;

void dfs( int x , string s ){
    if( s.length() == len ){
        for( int i = 0 ; i < s.length() ; ++i ){
            pos[ s[ i ] - 'A' ] = i + 1;
        }
        int maxi = 0;
        for( int i = 0 ; i < MAX ; ++i ){
            if( visited[ i ] ){
                for( int j = 0 ; j < ady[ i ].size() ; ++j ){
                    if( !connected[ i ][ ady[ i ][ j ] ] ) continue;
                    int aux = abs( pos[ ady[ i ][ j ] ] -pos[ i ] );
                    if( maxi < aux ){
                        maxi = aux;
                    }
                }
            }
        }
        if( mini > maxi ){
            resp = s;
            mini = maxi;
        }
    }
    seen[ x ] = 1;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( !seen[ ady[ x ][ i ] ] ){
            dfs( ady[ x ][ i ] , s + (char)(ady[ x ][ i ]+'A') );
        }
    }
    seen[ x ] = 0;
}

int main(){
    char line[ 105 ];
    string s;
    while( gets( line ), line[ 0 ] != '#' ){
        s = "";
        memset( visited , 0 , sizeof( visited ) );
        memset( connected , 0 , sizeof( connected) ) ;
        for( int i = 0 ; line[ i ] ; ++i ){
            if( line[ i ] == ';' ){
                for( int j = 2 ; j < s.length() ; ++j ){

                    connected[ s[ 0 ] - 'A' ][ s[ j ] - 'A' ] = 1;
                    connected[ s[ j ] - 'A' ][ s[ 0 ] - 'A' ] = 1;
                    visited[ s[ j ] - 'A' ] = 1;
                }
                visited[ s[ 0 ] - 'A' ] = 1;
                s = "";
            }
            else s+= line[ i ];
        }
        for( int j = 2 ; j < s.length() ; ++j ){
            connected[ s[ 0 ] - 'A' ][ s[ j ] - 'A' ] = 1;
            connected[ s[ j ] - 'A' ][ s[ 0 ] - 'A' ] = 1;
            visited[ s[ j ] - 'A' ] = 1;
        }
        visited[ s[ 0 ] - 'A' ] = 1;

        for( int i = 0 ; i < MAX ; ++i ){
            if( !visited[ i ] ) continue;
            for( int j =  i + 1 ; j < MAX ; ++j ){
                if( !visited[ j ] ) continue;
                ady[ i ].push_back( j );
                ady[ j ].push_back( i );
            }
        }

        len = 0;
        string ini;
        int ini_;
        for( int i = 0 ; i < MAX ; ++i ){
            if( visited[ i ] ){
                len++;

            }
        }
        mini = 1000;
        for( int i = 0 ; i < MAX ; ++i ){
            ini = "";ini += (char)( i + 'A' );
            if( visited[ i ]){
                memset( seen , 0 , sizeof( seen ) );
                dfs( i , ini  );
            }
        }

        for( int i = 0 ; i < len ; ++i )
            printf("%c " , resp[ i ] );
        printf("-> %d\n" , mini );

        for( int i = 0 ; i < MAX ; ++i )ady[ i ].clear();
    }
    return 0;
}
