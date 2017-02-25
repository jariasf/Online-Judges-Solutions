/*****************************************
 ***Problema: Stack 'em Up
 ***ID: 10205
 ***Juez: UVA
 ***Tipo: Ad hoc - Game, simulation
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
string d[ 4 ] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string aux[ 13 ] = {"2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "10" , "Jack" , "Queen" , "King" , "Ace"};

int main(){
    int t, shuffles, pos, shuffle[ 105 ][ 53 ];
    scanf("%d" , &t );
    vector<string> deck[ 105 ];


    for( int i = 0;  i < 4 ; ++i ){
        for( int j = 0 ; j < 13 ; ++j ){
            deck[ 0 ].push_back( aux[ j ] + " of " + d[ i ] );
        }
    }

    char kk[ 5 ];
    int k;
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        scanf("%d" , &shuffles );

        for( int sh = 0 ; sh < shuffles ; ++sh ){
            deck[ sh + 1 ] = vector<string>( 53 );
            for( int i = 0 ; i < 52 ; ++i ){
                scanf("%d" , &shuffle[ sh + 1 ][ i ] );
            }
        }
        gets( kk );
        int sh = 0;
        while( gets( kk ) ){
            if( strlen( kk ) == 0 )break;
            k = atoi( kk );
            for( int i = 0 ; i < 52 ; ++i )
                deck[ sh + 1 ][ i ] = deck[ sh ][ shuffle[ k ][ i ] - 1 ];

            sh++;
        }

        for( int i = 0 ; i < 52 ; ++i )
            printf("%s\n" , deck[ sh ][ i ].c_str() );
    }
    return 0;
}
