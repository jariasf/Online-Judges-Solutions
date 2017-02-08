/*****************************************
 ***Problema: Bridge Hands
 ***ID: 555
 ***Juez: UVA
 ***Tipo: Ad hoc , Game - cards
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
char aux[ 13 ] = { '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K' , 'A' };
bool cmp( string s1 , string s2 ){
    if( s1[ 0 ] == s2[ 0 ] ){
        for( int i = 12 ; i >= 0 ; --i ){
            if( s1[ 1 ] == aux[ i ] ) return 0;
            if( s2[ 1 ] == aux[ i ] ) return 1;
        }
    }
    if( s1[ 0 ] == 'H' ) return 0;
    if( s2[ 0 ] == 'H' ) return 1;
    if( s1[ 0 ] == 'S' ) return 0;
    if( s2[ 0 ] == 'S' ) return 1;
    if( s1[ 0 ] == 'D' ) return 0;
    if( s2[ 0 ] == 'D' ) return 1;
    if( s1[ 0 ] == 'C' ) return 0;
    if( s2[ 0 ] == 'C' ) return 1;
}

int main(){
    char dealer;
    char s[ 55 ];
    string deck, aux;
    int idx;
    vector<string> ady[ 4 ];
    char d[ 4 ] = {'S' , 'W' , 'N' , 'E' };
    while( scanf(" %c" , &dealer ) && dealer !='#' ){

        if( dealer == 'N' ) idx = 3;
        else if( dealer == 'E' ) idx = 0;
        else if( dealer == 'S' ) idx = 1;
        else if( dealer == 'W' ) idx = 2;
        deck = "";
        scanf("%s" , &s );
        deck += s;
        scanf("%s" , &s );
        deck += s;

        for( int i = 0 ; i < deck.length() ; i += 2 ){
            aux = deck[ i ];
            aux += deck[ i + 1 ];
            ady[ idx ].push_back( aux );
            idx = ( idx + 1 ) % 4;
        }

        for( int i = 0 ; i < 4 ; ++i ){
            printf("%c:" , d[ i ] );
            sort( ady[ i ].begin() , ady[ i ].end() , cmp  );
            for( int j = 0 ; j < 13 ; ++j ){
                printf(" %s" , ady[ i ][ j ].c_str() );
            }
            ady[ i ].clear();
            printf("\n");
        }
    }
    return 0;
}
