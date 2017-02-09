/*****************************************
 ***Problema: Chutes and Ladders
 ***ID: 647
 ***Juez: UVA
 ***Tipo: Ad hoc
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

int main(){
    int dice[ 1005 ] , a[ 105 ], pos[ 7 ] , turn[ 7 ];
    int loss[ 105 ];
    int len = 0 , players , u , v , win;
    while( scanf("%d" , &dice[ len ] ) , dice[ len ]){ len++; }
    while( scanf("%d" , &players ) , players ){

        memset( a , 0 , sizeof( a ) );

        for( int i = 0 ; i < 7 ; ++i ){ pos[ i ] = 0; turn[ i ] = 1; }//turn 1 si tiene un turno 2 si tiene 2, 0 si no tiene

        while( scanf("%d %d" , &u , &v  ) , u | v ){ a[ u ] = v; }
        memset( loss , 0 , sizeof( loss ) );
        while( scanf("%d" ,  &u ) , u ){ if( u < 0 )loss[ -u ] = -1; else loss[ u ] = 1; }
        win = 0;
        for( int i = 0 , p = 0; i < len ; ++i ){
            if( !turn[ p ] ){ turn[ p ] = 1; p = ( p + 1 ) % players; } // si no tiene turno continua el otro jugador
            if( pos[ p ] >= 95 && ( dice[ i ] + pos[ p ] ) != 100 ){ p = ( p + 1 ) % players; continue;}
            pos[ p ] += dice[ i ];
            if( a[ pos[ p ] ] ) pos[ p ] = a[ pos[ p ] ];
            else{
                if( loss[ pos[ p ] ] < 0 ) turn[ p ] = 0;
                else if( loss[ pos[ p ] ] )turn[ p ] = 2;
            }
            if( pos[ p ] == 100 ){ win = p + 1; break;}
            if( turn[ p ] != 2 ) p = ( p + 1 ) % players;
            else turn[ p ] = 1;

        }
        printf("%d\n" , win );

    }

    return 0;
}
