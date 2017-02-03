/*****************************************
 ***Problema: Trip Routing
 ***ID: 186
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Warshall
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
#define MAX 300
#define INF 9999999
int ady[ MAX ][ MAX ] , costos[ MAX ][ MAX];

int V;
int path[ MAX ][ MAX ];

void Init(){
    for(int i = 0 ; i < MAX ; ++i){
         for(int j = 0 ; j < MAX; ++j){
                 ady[ i ][ j ] = INF;
         }
        ady[ i ][ i ] = 0;
    }
}

void InitPath(){
    for(int i = 0 ; i < MAX ; ++i ){
         for(int j = 0 ; j < MAX ; ++j ){
                if( ady[ i ][ j ] == INF || ady[ i ][ j ] == 0 ){ path[ i ][ j ] = 0; }
                else path[ i ][ j ] = i;
         }
    }
}

void floyd(){
    for( int k = 0 ; k < V ; ++k ){
        for( int i = 0 ; i < V ; ++i ){
             for( int j = 0 ; j < V ; ++j ){
                    int t = ady[ i ][ k ] + ady[ k ][ j ];
                    if( t < ady[ i ][ j ] ){
                       ady[ i ][ j ] = t;
                       path[ i ][ j ] = path[ k ][ j ];
                    }
             }
        }
    }
}

vector<int> print;

void ruta( int x , int y ){
    if( x == INF || y == INF )return;
    if( x == y )print.push_back( x );
    else{
       ruta( x , path[ x ][ y ] );
       print.push_back( y );
    }
    return;
}

int toInt( string s ){ stringstream ss( s ); int n ; ss>>n; return n;}

int main(){
    char line[ MAX ] , u[ 30 ] , v [ 30 ] , route[ 15 ];
    int w;
    map<string ,int > mp;
    map< int, string > mp2;
    string rutas[ MAX ][ MAX ];
    V = 0;
    string uu ,vv , rr , pp;
    Init();
    while( gets( line ) ){
        int len = strlen( line );
        if( len == 0 )break;
        uu =""; vv="";rr=""; pp="";

        int i = 0;
        for( ; i < len ; ++i ){
            if( line[ i ] == ',' )break;
            uu += line[ i ];
        }
        i++;
        for( ; i < len ; ++i ){
            if( line[ i ] == ',' )break;
            vv += line[ i ];
        }

        strcat( route , "" );
        i++;
        for( ; i < len ; ++i ){
            if( line[ i ] == ',' )break;
            rr += line[ i ];
        }
        i++;
        for( ; i < len ; ++i )pp += line[ i ];

        if( mp.find( uu ) == mp.end() ){
            mp2[ V ] = uu;
            mp[ uu ] = V++;
        }
        if( mp.find( vv ) == mp.end() ){
            mp2[ V ] = vv;
            mp[ vv ] = V++;
        }
        if( ady[ mp[ uu ] ][ mp[ vv ] ] < toInt( pp ) )continue;

        ady[ mp[ uu ] ][ mp[ vv ] ] = ady[ mp[ vv ] ][ mp[ uu ] ] = toInt( pp );
        costos[ mp[ uu ] ][ mp[ vv ] ] = costos[ mp[ vv ] ][ mp[ uu ] ] = toInt( pp );

        rutas[ mp[ uu ] ][ mp[ vv ] ] = rutas[ mp[ vv ] ][ mp[ uu ] ] =rr ;

    }
    InitPath();
    floyd();

    while( gets( line ) ){
        int len = strlen( line );
        uu = "";
        vv = "";
        int i = 0;
        for(  ; i < len ; ++i ){
            if( line[ i ] == ',' )break;
            uu += line[ i ];
        }
        i++;
        for( ; i < len ; ++i )vv += line[ i ];

        printf("\n\n");

        printf("From                 To                   Route      Miles\n");
        printf("-------------------- -------------------- ---------- -----\n");
        print.clear();
        ruta( mp[ uu ] , mp[ vv ] );

        for( i = 0 ; i < print.size() - 1; ++i ){
            printf("%-20s %-20s %-10s %5d\n" , mp2[ print[ i ] ].c_str() , mp2[ print[ i + 1 ] ].c_str() ,
                rutas[ print[ i ] ][ print[ i + 1 ] ].c_str() , costos[ print[ i ]  ][  print[ i + 1 ]  ]);
        }
        printf("                                                     -----\n");
        printf("                                          Total      %5d\n" , ady[ mp[ uu ] ][ mp[ vv ] ]);
    }
    return 0;
}
