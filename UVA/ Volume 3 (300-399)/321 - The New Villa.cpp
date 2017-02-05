/*****************************************
 ***Problema: The New Villa
 ***ID: 321
 ***Juez: UVA
 ***Tipo: BFS + Bitmasks
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
#define MAX 15
vector< int > Switch[ MAX ] , ady[ MAX ];
int V;

struct Previo{
    int x , mask , id;
    string command;
    Previo( int xx , int m , string c , int i ): x( xx ) , mask( m ) , command( c ) , id( i ){}
    Previo(){}
}prev[ MAX ][ 1<<11 ];
bool seen[ MAX ][ 1<<11 ];  //cuarto en el que estoy y las luces encendidas hasta el momento

struct Estado{
    int x , d , mask;
    Estado( int xx , int dd , int m ): x( xx ) , d( dd ), mask( m ){}
};

void print( int x , int mask ){
    if( prev[ x ][ mask ].x == -1 ){
        return;
    }
    print( prev[ x ][ mask ].x , prev[ x ][ mask ].mask );
    printf("- %s %d.\n" , prev[ x ][ mask ].command.c_str() , prev[ x ][ mask ].id );
}

void bfs(){

    queue< Estado > Q;
    Q.push( Estado( 0 , 0 , 1 ) );
    int v, ans = 1<<30;
    prev[ 0 ][ 1 ] = Previo( -1 , -1 , "" , -1 );
    memset( seen , 0 ,sizeof( seen ) );
    seen[ 0 ][ 1 ] = 1;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();
        if( act.x == V - 1 && act.mask == 1<<( V - 1 ) ){   //si estoy en el cuarto final con las demas luces apagadas
            ans = act.d;
            break;
        }
        int mask = act.mask;
        //presiono switch en el room actual
        for( int i = 0 ; i < Switch[ act.x ].size() ; ++i ){
            v = Switch[ act.x ][ i ];
            if( v == act.x ) continue;
            mask = act.mask;
            if( mask & 1<<v ){ //si esta encendido el cuarto actual, lo apago
                mask = mask & ( ~( 1<<v ) );
                if( !seen[ act.x ][ mask ] ){
                    Q.push( Estado( act.x , act.d + 1 , mask ) );
                    seen[ act.x ][ mask ] = 1;
                    prev[ act.x ][ mask ] = Previo( act.x , act.mask , "Switch off light in room" , v + 1 );
                }
            }
            else{
                mask |= 1<<v; //sino lo enciendo
                if( !seen[ act.x ][ mask ] ){
                    Q.push( Estado( act.x , act.d + 1 , mask ) );
                    seen[ act.x ][ mask ] = 1;
                    prev[ act.x ][ mask ] = Previo( act.x , act.mask , "Switch on light in room" , v + 1 );
                }
            }
        }

        //me muevo a otro room siempre y cuando este la luz encendida
        for( int i = 0 ; i < ady[ act.x ].size() ; ++i ){
            v = ady[ act.x ][ i ];
            if( ( act.mask & 1<<v ) && !seen[ v ][ act.mask ] ){
                Q.push( Estado( v , act.d + 1 , act.mask ) );
                seen[ v  ][ act.mask ] = 1;
                prev[ v ][ act.mask ] = Previo( act.x , act.mask , "Move to room" , v + 1 );
            }
        }
    }
    if( ans == 1<<30 ){
        puts("The problem cannot be solved.");
    }
    else{
        printf("The problem can be solved in %d steps:\n" , ans );
        print( V - 1 , 1<<( V - 1 ) ); //imprimo recursivamente
    }
}

int main(){
    int u , v , E , S , q = 1;
    while( scanf("%d %d %d" , &V , &E , &S ) , V | E | S ){

        for( int i = 0 ; i <= V ; ++i ){
            ady[ i ].clear();
            Switch[ i ].clear();
        }
        while( E-- ){
            scanf("%d %d" , &u , &v );
            u--; v--;
            ady[ u ].push_back( v );
            ady[ v ].push_back( u );
        }

        while( S-- )
        {
            scanf("%d %d" , &u , &v );
            u--;v--;
            Switch[ u ].push_back( v );
        }
        printf("Villa #%d\n" , q++ );
        bfs();
        printf("\n");
    }
    return 0;
}
