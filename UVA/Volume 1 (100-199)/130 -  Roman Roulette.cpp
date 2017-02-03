/*****************************************
 ***Problema: Roman Roulette
 ***ID: 130
 ***Juez: UVA
 ***Tipo: Simulation, Josephus
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 105

int main( ){
    int n , k , next , kill , k_next , nn;
    while( scanf("%d %d" , &n , &k ) , n|k ){
        if( n == 1 ){
            printf("1\n");
            continue;
        }
        nn = n;
        vector<int> Circle;
        for( int i = 0 ; i < n ; ++i )
            Circle.push_back( i );

        k--;
        for( int i = 0 ;  ; ){

            kill = ( i + k ) % n;
            Circle.erase( Circle.begin() + kill );
            n = Circle.size();
            k_next = ( kill + k ) % n;
            Circle.insert( Circle.begin() + kill , Circle[ k_next ] );

            if( k_next >= kill ) k_next++;
            Circle.erase( Circle.begin() + k_next );
            n = Circle.size();
            if( n == 1 )break;

            if( k_next >= kill ){
                i = ( kill + 1 ) % n;
            }
            else{
                i = kill % n;
            }
        }

        printf("%d\n" , ( ( nn  - Circle[ 0 ] ) % nn ) + 1 );
    }

    return 0;
}
