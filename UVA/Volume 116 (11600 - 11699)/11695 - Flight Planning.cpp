/*****************************************
 ***Problema: Flight Planning
 ***ID: 11695
 ***Juez: UVA
 ***Tipo: Diameter and Center of a Tree
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
/**
Hallamos el diametro del arbol y obtenemos el path, sobre ese path x fuerza bruta elimino una arista y veo los
centros de los 2 subarboles que se forman al eliminar una arista. Como el centro puede ser 2 vertices o 1, pruebo con
cada posible siempre y cuando difiera de los vertices eliminados.
**/
#define MAX 2505
#define INF 1<<30
#define pii pair< int , int >
#define mp make_pair
#define diameter first
#define vertex second
vector< int > ady[ MAX ];
int V , seen[ MAX ] , prev[ MAX ], dist[ MAX ];
bool del[ MAX ][ MAX ];
pii diameterTree( int inicial ){
    int i , u , v , final , diameter;
    for( i = 1 ; i <= V ; ++i ) dist[ i ] = INF ,seen[ i ] = 0;
    queue< int > Q;
    Q.push( inicial );
    seen[ inicial ] = 1;
    prev[ inicial ] = -1;
    dist[ inicial ] = 0;
    Q.push( inicial );
    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        for( i = 0 ; i < ady[ u ].size() ; ++i ){
            v = ady[ u ][ i ];
            if( !del[ u ][ v ] && dist[ v ] > dist[ u ] + 1 ){
                dist[ v ] = dist[ u ] + 1;
                prev[ v ] = u;
                seen[ v ] = 1;
                Q.push( v );
            }
        }
    }
    diameter = -1;
    for( i = 1 ; i <= V ; ++i ){
        if( seen[ i ] && diameter < dist[ i ] ){
            diameter = dist[ i ];
            final = i;
        }
    }
    return mp( diameter , final );
}

int path2[ MAX ] , len2;
int path[ MAX ] , len;

int getCenter( int i , int j ){
    return j - i + 1;
}

int main(){
    pii diam;
    int t , i , u , v , diameter , dmax, pos1 , pos2 , c11 , c12 , c21 , c22 , d1 , d2 , mini , xdel , ydel , xnovo , ynovo;
    int tmp;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &V ) == 1 ){
        for( i = 0 ; i < V - 1 && scanf("%d %d" , &u , &v ); ++i ){
            ady[ u ].push_back( v );
            ady[ v ].push_back( u );
        }

        diam = diameterTree( diameterTree( 1 ).vertex );
        len = 0;
        u = diam.vertex;
        do{
            path[ len++ ] = u;
            u = prev[ u ];
        }while( u != -1 );
        mini = 1<<30;
        for( i = 1 ; i< len ; ++i ){

            del[ path[ i - 1 ] ][ path[ i ] ] = del[ path[ i ] ][ path[ i - 1 ] ] = 1;
            c11 = c12 = c22 = c21 = -1;

            //obtengo centro de cada subarbol
            diam = diameterTree( diameterTree( path[ i ] ).vertex );
            len2 = 0;
            u = diam.vertex;
            do{
                path2[ len2++ ] = u;
                u = prev[ u ];
            }while( u != -1 );

            if( len2 & 1 ){
                c11 = path2[ len2/2 ];
            }
            else{
                c11 = path2[ len2/2 ];
                c12 = path2[ len2/2 - 1 ];
            }
            diam = diameterTree( diameterTree( path[ i - 1 ] ).vertex );
            len2 = 0;
            u = diam.vertex;
            do{
                path2[ len2++ ] = u;
                u = prev[ u ];
            }while( u != -1 );

            if( len2 & 1 ){
                c21 = path2[ len2/2 ];
            }
            else{
                c21 = path2[ len2/2 ];
                c22 = path2[ len2/2 - 1 ];
            }

            if( c11 != -1 ){
                if( c21 != -1 ){
                    if( ( c11 == path[ i - 1 ] && c21 == path[ i ] ) || ( c11 == path[ i ] && c21 == path[ i - 1 ] ) )continue;
                    ady[ c11 ].push_back( c21 );
                    ady[ c21 ].push_back( c11 );
                    diameter = diameterTree( diameterTree( 1 ).vertex ).diameter;
                    ady[ c11 ].pop_back( );
                    ady[ c21 ].pop_back( );
                    if( diameter < mini ){
                        mini = diameter;
                        xdel = path[ i - 1 ];
                        ydel = path[ i ];
                        xnovo = c11;
                        ynovo = c21;
                    }
                }
                if( c22 != -1 ){
                    if( ( c11 == path[ i - 1 ] && c22 == path[ i ] ) || ( c11 == path[ i ] && c22 == path[ i - 1 ] ) )continue;
                    ady[ c11 ].push_back( c22 );
                    ady[ c22 ].push_back( c11 );
                    diameter = diameterTree( diameterTree( 1 ).vertex ).diameter;
                    ady[ c11 ].pop_back( );
                    ady[ c22 ].pop_back( );
                    if( diameter < mini ){
                        mini = diameter;
                        xdel = path[ i - 1 ];
                        ydel = path[ i ];
                        xnovo = c11;
                        ynovo = c22;
                    }
                }
            }

            if( c12 != -1 ){
                if( c21 != -1 ){
                    if( ( c12 == path[ i - 1 ] && c21 == path[ i ] ) || ( c12 == path[ i ] && c21 == path[ i - 1 ] ) )continue;
                    ady[ c12 ].push_back( c21 );
                    ady[ c21 ].push_back( c12 );
                    diameter = diameterTree( diameterTree( 1 ).vertex ).diameter;
                    ady[ c12 ].pop_back( );
                    ady[ c21 ].pop_back( );
                    if( diameter < mini ){
                        mini = diameter;
                        xdel = path[ i - 1 ];
                        ydel = path[ i ];
                        xnovo = c12;
                        ynovo = c21;
                    }
                }
                if( c22 != -1 ){
                    if( ( c12 == path[ i - 1 ] && c22 == path[ i ] ) || ( c12 == path[ i ] && c22 == path[ i - 1 ] ) )continue;
                    ady[ c12 ].push_back( c22 );
                    ady[ c22 ].push_back( c12 );
                    diameter = diameterTree( diameterTree( 1 ).vertex ).diameter;
                    ady[ c12 ].pop_back( );
                    ady[ c22 ].pop_back( );
                    if( diameter < mini ){
                        mini = diameter;
                        xdel = path[ i - 1 ];
                        ydel = path[ i ];
                        xnovo = c12;
                        ynovo = c22;
                    }
                }
            }
            del[ path[ i - 1 ] ][ path[ i ] ] = del[ path[ i ] ][ path[ i - 1 ] ] = 0;
        }
        printf("%d\n%d %d\n%d %d\n" , mini , xdel , ydel , xnovo , ynovo );
        for( i = 0 ; i <= V ; ++i ) ady[ i ].clear();
    }
    return 0;
}
