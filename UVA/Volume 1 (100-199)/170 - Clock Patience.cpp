/*****************************************
 ***Problema: Clock Patience
 ***ID: 170
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

char rank[ 14 ] = { ' ','A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
char suit[ 4 ] = { 'S' , 'H' , 'D' , 'C' };
queue<string> deck[ 14 ];
int main(){
    int pos, ans;
    char s[ 3 ];
    string act;
    while( scanf("%s" , &s ) , s[ 0 ] != '#' ){

        deck[ 13 ].push( s );
        pos = 12;
        for( int i = 0 ; i < 51 ; ++i ){
            scanf("%s" , s );
            deck[ pos-- ].push( s );
            if( pos == 0 ) pos = 13;
        }
        int current = 13;
        ans = 0;
        while( 1 ){
            if( deck[ current ].empty() )break;
            act = deck[ current ].front();
            deck[ current ].pop();
            for( int i = 1 ; i < 14 ; ++i ){
                if( act[ 0 ] == rank[ i ] ){
                    current = i;
                    break;
                }
            }
            ans++;
        }
        printf("%.2d,%s\n" , ans , act.c_str() );

        for( int i = 0 ; i < 14 ; ++i ){

            while( !deck[ i ].empty() ){
                deck[ i ].pop();
            }
        }
    }
    return 0;
}
