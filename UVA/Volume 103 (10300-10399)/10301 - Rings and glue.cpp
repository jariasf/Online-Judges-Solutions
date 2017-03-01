/*****************************************
 ***Problema: Rings and Glue
 ***ID: 10301
 ***Juez: UVA
 ***Tipo: Geometry + Union Find
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
#define MAX 105
int uf[ MAX ];
int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}
void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}
double dist( int x1 , int y1 , int x2 , int y2 ){
	return sqrt( ( x1 - x2 )*( x1 - x2 ) + ( y1 - y2 ) *( y1 - y2 ) );
}
bool CircleIntersection( int x1 , int y1 , int x2 , int y2, double r1, double r2){

    double d = dist( x1 , y1 , x2 , y2 );
    if( d < r1 - r2 ) return false;
    else if( d < r2 - r1 ) return false;
    else if(  d > (r1 + r2) ) return false;
    return true;
}
int main(){
    double x[ MAX ] , y[ MAX ], r[ MAX ];
    int cnt[ MAX ];
    int n, maxi;
    while( scanf("%d" , &n ) , n != -1 ){
        for( int i = 0 ; i < n ; ++i ){
            uf[ i ] = i;
            cnt[ i ] = 0;
            scanf("%lf %lf %lf" , &x[ i ]  ,&y[ i ] , &r[ i ] );
        }

        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                if( CircleIntersection( x[ i ] , y[ i ] , x[ j ] , y[ j ] , r[ i ] , r[ j ] ) ){
                    Union( i , j );
                }
            }
        }
        maxi = 0;
        for( int i = 0 ; i < n ; ++i ) cnt[ Find( i ) ]++;
        for( int i = 0 ; i < n ; ++i ) maxi = ( maxi < cnt[ i ] )?cnt[ i ]: maxi;
        if( maxi == 1 )printf("The largest component contains %d ring.\n" , maxi );
        else printf("The largest component contains %d rings.\n" , maxi );

    }

    return 0;
}
