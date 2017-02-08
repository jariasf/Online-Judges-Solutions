/*****************************************
 ***Problema: Team Queue
 ***ID: 540
 ***Juez: UVA
 ***Tipo: Queue
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
#define MAX 200005
#define MTEAM 1000005

int team[ MTEAM ];
int pos[ 10005 ];
int head, sz, n;
int ini;

struct Queue{
    int top, sz , a[ 1005 ];
}Q[ 1005 ];

int lista[ 1005 ]; // tengo un arreglo de colas, cada vez q se elimine una cola, crearemos una nueva, no eliminaremos

void init(){
    head = sz = 0;
    for( int i = 0 ; i < n ; ++i ) Q[ i ].top = Q[ i ].sz = 0;
}

void Push( int x ){
    int idx = pos[ team[ x ] ];
    if( Q[ idx ].top == Q[ idx ].sz ){//si vacio
        Q[ idx ].a[ 0 ] = x;  //creo nueva cola dentro de indice dado
        Q[ idx ].sz++;
        lista[ sz++ ] = idx;
    }
    else {
        Q[ idx ].a[ Q[ idx ].sz++ ] = x; //si existe elemento aumento tamano de la iesima cola
    }
}

int Pop(){

    int ini = lista[ head ]; //la 1era cola
    int x = Q[ ini ].a[ Q[ ini ].top++ ];
    if( Q[ ini ].top == Q[ ini ].sz ){
        head++;
        pos[ team[ x ] ] = -1; //hallo nueva posicion de cola en lista
    }
    return x;
}

int main(){

    int t, x , len, q = 1;
    char s[ 20 ];
    while( scanf("%d" , &n ) , n ){
        memset( pos , -1 , sizeof( pos ) );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &t );
            for( int j = 0 ; j < t ; ++j ){
                scanf("%d" , &x );
                team[ x ] = i;
            }
        }
        init();
        printf("Scenario #%d\n" , q++ );
        len = 0;
        while( scanf("%s" , &s ) && strcmp( s , "STOP") ){

            if( !strcmp( s , "ENQUEUE")){
                scanf("%d" , &x );
                if( pos[ team[ x ] ] == -1 ){
                    pos[ team[ x ] ] = len++;
                }
                Push( x );
            }
            else{
                printf("%d\n" , Pop() );

            }
        }
        printf("\n");
    }
    return 0;
}
