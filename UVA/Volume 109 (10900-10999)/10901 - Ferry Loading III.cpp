/*****************************************
 ***Problema: Ferry Loading III
 ***ID: 10901
 ***Juez: UVA
 ***Tipo: Simulation, queue
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
#define MAX 10005
#define LEFT 0
#define RIGHT 1
struct Data{
    int idx , val, dir;
    Data( int i , int v , int d ): idx( i ) , val( v ), dir( d ){}
    Data(){}
};

int main(){

    int C, x,time, a[ MAX ] , pos, n , t, m;
    char s[ 8 ];
    scanf("%d" , &C );
    for( int q = 0 ; q < C ; ++q ){
        if( q )printf("\n");
        memset( a , 0 , sizeof( a ) );
        deque<Data> Q;
        scanf("%d %d %d" , &n , &t , &m );
        pos = LEFT;
        time = 0;
        for( int i = 0 ; i < m ; ++i ){
            scanf("%d %s" , &x , &s );
            if( !strcmp( s , "right" ) ){
                Q.push_back( Data( i , x , RIGHT ) );
            }
            else Q.push_back( Data( i , x , LEFT ) );
        }
        int acu = 0;
        Data last;

        while( !Q.empty() ){
            deque<Data> copy = Q;
            Data act = Q.front();
            if( act.val > time ) time += ( act.val - time );
            Data next;
            vector<int> idx;
            vector<int> borrar;
            int value = 1;
            for( int i = 0 , j = 0 ; j < n && !copy.empty() ; ++i ){
                next = copy.front(); copy.pop_front();
                if( next.dir == pos && next.val <= time ){
                    idx.push_back( next.idx );
                    borrar.push_back( i );
                    j++;
                }
                if( next.dir == pos && next.val > time )break;
            }
            int del = 0;
            for( int i = 0 ; i < borrar.size(); ++i ){
                Q.erase( Q.begin() + borrar[ i ] - del );
                del++;
            }
            //regreso
            time += t;
            for( int i = 0 ; i < idx.size() ; ++i ){
                a[ idx[ i ] ] = time;
            }
            pos = !pos;
        }
        for( int i = 0 ; i < m ; ++i ){
            printf("%d\n" , a[ i ] );
        }
    }
    return 0;
}
