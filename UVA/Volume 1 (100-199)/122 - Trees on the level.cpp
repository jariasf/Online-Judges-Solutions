/*****************************************
 ***Problema: Trees on the level
 ***ID: 122
 ***Juez: UVA
 ***Tipo: Ad hoc, Trees traversal
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
#define MAX 80005
int tree[ MAX ];
int values[ MAX ];
bool visited[ MAX ];
bool tree_real[ MAX ];

int Int( string s ){
    stringstream ss(s);
    int n;
    ss>>n;
    return n;
}

int main(){
    string s;
    int nodos = 0;
    memset( tree, 0 , sizeof( tree ) );
    tree_real[ 0 ] = true;

    while( getline( cin , s) ){
        s+=" ";
        stringstream ss( s );
        bool b = false;

        while( ss>>s ){
            if(s == "()"){b = true;break;}
            int it = s.find( "," );
            int nodo = Int( s.substr( 1 , it ) );
            string ruta = s.substr( it + 1 );
            ruta = ruta.substr(0, ruta.length() - 1 );
            int x = 0;
            for( int i = 0 ; i < ruta.length() ; ++i ){
                if( ruta[ i ] == 'L' )
                    x = 2 * x + 1;
                else
                    x = 2 * x + 2;

                tree_real[ x ] = true;
            }
            tree[ x ]++;
            values[ x ] = nodo;
            visited[ x ] = true;
            nodos = std::max( nodos , x );
        }
        if( b ){
           int i = 0;
           for( ; i <= nodos ; ++i ){
                if( tree_real[ i ] && !visited[ i ] || visited[ i ] && tree[ i ] != 1 ){
                   cout<<"not complete"<<endl;
                   break;
                }
           }
           if( i == nodos + 1){

              cout<<values[ 0 ];
              for( i = 1 ; i <= nodos ; ++i ){
                  if( values[ i ] )
                    cout<<" "<<values[ i ];
              }
              cout<<endl;
           }
           nodos = 0;
           memset( tree , 0 , sizeof( tree ) );
           memset( values, 0 , sizeof(  values ) );
           memset( visited, 0 , sizeof( visited ) );
           memset( tree_real , 0 , sizeof( tree_real ) );
           tree_real[ 0 ] = true;
        }
    }

    return 0;
}
