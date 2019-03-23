/*****************************************
 ***Problema: Snakes and Ladders
 ***ID: 11459
 ***Juez: UVA
 ***Tipo: Simulation
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

    int t , sl , dice , p , u , v , j;
    scanf("%d", &t );
    int a[ 105 ], pos[ 1005 ];
    bool finish;
    while( t-- ){
        scanf("%d %d %d" , &p , &sl ,&dice);
        for( int i = 0 ; i < 104 ; ++i ) a[ i ] = i;
        memset( pos , 0 , sizeof( pos ));
        while( sl-- ){
            scanf("%d %d" , &u  ,&v );
            a[ u ] = v;
        }
        finish = false;
        j = -1;
        while( dice-- ){
            scanf("%d" , &v );
            j = ( j + 1 ) % 10;
            if( finish ){
                continue;
            }
            if( !pos[ j + 1 ] ) pos[ j + 1 ] = 1;
            pos[ j + 1 ] += v;
            pos[ j + 1 ] = a[ pos[ j + 1 ] ];
            if( pos[ j + 1 ] >= 100 ){
                finish = true;
                pos[ j + 1 ] = 100;
            }
        }
        for( int i = 1 ; i <= p ; ++i ){
            if( pos[ i ]) printf("Position of player %d is %d.\n" , i , pos[ i ]  );
            else printf("Position of player %d is 1.\n" , i );
        }
    }
    return 0;
}
