/*****************************************
 ***Problema: Ferry Loading
 ***ID: 10440
 ***Juez: UVA
 ***Tipo: Greedy
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
    int t , q , n ,m , k, total;
    int viajes , x , aux , paso , j , l;
    scanf("%d" , &q );
    while( q-- ){

        scanf("%d %d %d" , &n ,&t ,&m );

        l = m%n; k = m/n;
        total = 0; viajes = k;

        if( l ){
            viajes++;
            for( int i = 0 ; i < l ; ++i ){
                scanf("%d" , &x );
                total =  x + 2 *t;
            }
        }

        for( int i = 0 ; i < k ; ++i ){
            for( int j  = 0 ; j < n ; ++j )
                scanf("%d" , &x );
            if( x <= total ) total += 2*t;
            else total = x + 2 * t;
        }

        printf("%d %d\n" , total - t , viajes );

    }

    return 0;
}
