/*****************************************
 ***Problema: Argentina
 ***ID: 11804
 ***Juez: UVA
 ***Tipo: Brute Force
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

struct Estado{
    char s[ 30 ];
    int a, d;

};

bool f( Estado e1 , Estado e2 ){
    int c =  strcmp( e1.s , e2.s );
    if( c > 0 )return false;
    return true;
}

int main(){
    int t;
    char s[ 30 ];
    scanf("%d" , &t );
    int a[ 10 ], d[ 10 ], index[ 5 ];
    char attack[ 5 ][ 30 ] , def[ 5 ][ 30 ];
    for( int q = 1 ; q <= t ; ++q ){
        vector< Estado > vv;
        for( int i = 0 ; i < 10 ; ++i ){
            Estado e;
            scanf("%s %d %d" , &e.s , &e.a , &e.d );
            vv.push_back( e );
        }

        sort( vv.begin() , vv.end() , f );

        int maxa = 0 , maxd = 0;
        for( int i = 0 ; i < 10 ; ++i ){
            for( int j = i + 1 ; j < 10 ; ++j ){
                for( int k = j + 1 ; k < 10 ; ++k ){
                    for( int v = k + 1 ; v < 10 ; ++v ){
                        for( int w = v + 1 ; w < 10 ; ++w ){

                             int sum = vv[ i ].a + vv[ j ].a + vv[ k ].a + vv[ v ].a + vv[ w ].a;
                             if( sum > maxa ){
                                 maxa = sum;
                                 strcpy( attack[ 0 ] , vv[ i ].s );
                                 strcpy( attack[ 1 ] , vv[ j ].s );
                                 strcpy( attack[ 2 ] , vv[ k ].s );
                                 strcpy( attack[ 3 ] , vv[ v ].s );
                                 strcpy( attack[ 4 ] , vv[ w ].s );
                                 index[ 0 ] = i;
                                 index[ 1 ] = j;
                                 index[ 2 ] = k;
                                 index[ 3 ] = v;
                                 index[ 4 ] = w;
                                 for( int m = 0, idx = 0 ; m < 10 ; ++m ){
                                     if( m != index[ 0 ] && m != index[ 1 ] && m != index[ 2 ] && m != index[ 3 ] && m != index[ 4 ] ) strcpy( def[ idx++ ] , vv[ m ].s );
                                 }

                             }

                             if( sum == maxa ){

                                 ///vemos defensa de nuevos
                                 int sum_new = 0;
                                 for( int m = 0 ; m < 10 ; ++m ){
                                     if( m != i && m != j && m != k && m != v && m != w ) sum_new += vv[ m ].d;
                                 }
                                 ///vemos defensa de actuales
                                 int sum2 = 0;
                                 for( int m = 0 ; m < 10 ; ++m ){
                                     if( m != index[ 0 ] && m != index[ 1 ] && m != index[ 2 ] && m != index[ 3 ] && m != index[ 4 ] ) sum2 += vv[ m ].d;
                                 }

                                 ///si defensa mayor actualizo atacantes con defesores
                                 if( sum2 < sum_new ){

                                     strcpy( attack[ 0 ] , vv[ i ].s );
                                     strcpy( attack[ 1 ] , vv[ j ].s );
                                     strcpy( attack[ 2 ] , vv[ k ].s );
                                     strcpy( attack[ 3 ] , vv[ v ].s );
                                     strcpy( attack[ 4 ] , vv[ w ].s );
                                     index[ 0 ] = i;
                                     index[ 1 ] = j;
                                     index[ 2 ] = k;
                                     index[ 3 ] = v;
                                     index[ 4 ] = w;

                                     for( int m = 0, idx = 0 ; m < 10 ; ++m ){
                                        if( m != i && m != j && m != k && m != v && m != w )strcpy( def[ idx++ ] , vv[ m ].s );
                                     }
                                 }

                             }
                        }
                    }
                }
            }
        }

        printf("Case %d:\n" , q );
        printf("(%s" , attack[ 0 ] );
        for( int i = 1 ; i < 5 ; ++i ){
             printf(", %s" , attack[ i ] );
        }
        printf(")\n");

        printf("(%s" , def[ 0 ] );
        for( int i = 1 ; i < 5 ; ++i ){
             printf(", %s" , def[ i ] );
        }
        printf(")\n");

    }

    return 0;
}
