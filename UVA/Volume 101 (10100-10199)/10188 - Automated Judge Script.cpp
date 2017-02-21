/*****************************************
 ***Problema: Automated Judge Script
 ***ID: 10188
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
    char judge[ 101 ][ 122 ] , team[ 101 ][ 122 ];
    int n1 , n2 , state , q = 1 , l1 , l2;
    string d1 , d2;
    while( scanf("%d" , &n1 ) , n1 ){
        getchar();
        for( int i = 0 ; i < n1 ; ++i ) gets( judge[ i ] );
        scanf("%d" , &n2 );
        getchar();
        for( int i = 0 ; i < n2 ; ++i ) gets( team[ i ] );
        state = 1;
        d1 = d2 = "";
        for( int i = 0 ; i < n1 ; ++i ){
            l1 = strlen( judge[ i ] );
            for( int j = 0 ; j < l1 ; ++j ){
                if( '0' <=judge[ i ][ j ] && judge[ i ][ j ] <= '9')d1 += judge[ i ][ j ];
            }
        }

        for( int i = 0 ; i < n2 ; ++i ){
            l2 = strlen( team[ i ] );
            for( int j = 0 ; j < l2 ; ++j ){
                if( '0' <=team[ i ][ j ] && team[ i ][ j ] <= '9') d2 += team[ i ][ j ];
            }
        }

        if( d1 != d2 ) state = 3;
        if(state == 1 ){
            if( n1 != n2 ){
                state = 2;
                goto finish;
            }

            for( int i = 0 ; i < n1 ; ++i ){

                l2 = strlen( team[ i ] );
                l1 = strlen( judge[ i ] );
                if( l1 != l2 ){
                    state = 2;
                    break;
                }
                for( int j = 0 ; j < l1 ; ++j ){
                    if( team[ i ][ j ] != judge[ i ][ j ] ){
                        state = 2;
                        break;
                    }
                }
                if( state == 2 )break;
            }
        }
        finish:
        printf("Run #%d: " , q++ );
        if( state == 1 ) puts("Accepted");
        else if( state == 2 ) puts("Presentation Error");
        else puts("Wrong Answer");
    }

    return 0;
}
