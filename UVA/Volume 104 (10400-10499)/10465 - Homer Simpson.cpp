/*****************************************
 ***Problema: Homer Simpson
 ***ID: 10465
 ***Juez: UVA
 ***Tipo: DP
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
int dp[ MAX ], seen[ MAX ];
int n , m , t;

int solve( int sum , int cont ){

    if( sum < 0 ) return -1;

    if( dp[ sum ] != -1 ) return dp[ sum ];
    int maxi = 0;

    if( sum - n < 0 ){
        if( sum - m < 0 ){
            maxi = cont;
        }
        else{
            maxi = max( solve( sum - m , cont + 1 ) , cont ) ;
        }
    }
    else {
        if( sum - m < 0 ){
            maxi = max( solve( sum - n , cont + 1 ) , cont );
        }
        else{
            maxi = max( solve( sum - m , cont + 1 ) , solve( sum - n , cont + 1 ) );
        }
    }

    return dp[ sum ] = maxi;
}

int main(){

    while( scanf("%d %d %d" , &n , &m , &t ) != EOF ){
        memset( dp , 0 , sizeof( dp ) );

        memset( seen , 0 , sizeof( seen ) );
        seen[ t ] = 1;
        for( int i = t ; i >= 0 ; --i ){

            if( seen[ i ] ){
                if( i - n >= 0 ){
                    dp[ i - n ] = max( dp[ i - n ] , dp[ i ] + 1 );
                    seen[ i - n ] = 1;
                }

                if( i - m >= 0 ){
                    dp[ i - m ] = max( dp[ i - m ] , dp[ i ] + 1 );
                    seen[ i - m ] = 1;
                }
            }

        }
        int i = 0;
        for( ; i <= t ; ++i ) if( seen[ i ] ) break;
        if( i == 0 ) printf("%d\n" , dp[ i ] );
        else printf("%d %d\n" , dp[ i ] , i );
    }
    return 0;
}
