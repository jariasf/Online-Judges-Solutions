/*****************************************
 ***Problema: Free Spots
 ***ID: 10703
 ***Juez: UVA
 ***Tipo: Ad hoc, simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int w , h , n , cont , x1 , y1 , x2 , y2 , tmpx , tmpy;
    while( scanf( "%d %d %d" , &w , &h , &n ) && (w+h+n)){
        int ady [ w + 1 ][ h + 1 ];
        memset(ady , 0 ,sizeof(ady) );
        while( n-- ){
            scanf( "%d %d %d %d" , &x1 , &y1 , &x2 , &y2 );
            if( x1 > x2 && y1<=y2){
                   tmpx = x1;
                   x1 = x2;
                   x2 = tmpx;

            }
            else if( x1 >= x2 && y1 > y2 ){
                   tmpx = x1;
                   x1 = x2;
                   x2 = tmpx;
                   tmpy = y1;
                   y1 = y2;
                   y2 = tmpy;
            }

            if( x1 <= x2 && y1 > y2){
               tmpy = y1;
               y1 = y2;
               y2 = tmpy;
            }

            for( int i = x1 ; i <= x2 ; ++i ){
               if( i > w)break;
               for ( int j = y1 ; j <= y2 ; ++j ){
                   if( j > h)break;
                   ady [ i ][ j ] = 1;

               }
            }
        }

        cont = 0;
        for( int i = 1 ; i <= w ; ++i){
           for( int j = 1; j <= h ; ++j){
               if( ady [ i ][ j ] == 0 )cont++;
           }
        }
        if ( cont == 0 )printf("There is no empty spots.\n");
        else if( cont == 1 )printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n", cont );
    }
    return 0;
}
