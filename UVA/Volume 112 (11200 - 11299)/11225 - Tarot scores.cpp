/*****************************************
 ***Problema: Tarot scores
 ***ID: 11225
 ***Juez: UVA
 ***Tipo: Ad hoc - Game
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
    char s[ 105 ];
    int t, n,oudler;
    int points;
    string v, vv;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        scanf("%d" , &n );
        oudler = 0;
        gets( s );
        points = n/2;
        for( int i = 0 ; i < n ; ++i ){
            gets( s );
            stringstream ss( string( s ) + " ");
            ss>>vv;
            if( vv != "fool" ){
                ss>>v>>v;
                if( v == "trumps" && ( vv == "one" || vv =="twenty-one" )){points += 4; oudler++; }
                else if( vv == "king") points += 4;
                else if( vv == "queen" ) points += 3;
                else if( vv == "knight") points += 2;
                else if( vv == "jack" ) points += 1;
            }
            else{
                oudler++;
                points += 4;
            }
        }
        if( oudler == 3 ) oudler = 36;
        else if( oudler == 2 ) oudler = 41;
        else if( oudler == 1 ) oudler = 51;
        else if( oudler == 0 )oudler = 56;
        printf("Hand #%d\n" , q + 1 );
        if( points < oudler ) printf("Game lost by %d point(s).\n" , oudler - points );
        else printf("Game won by %d point(s).\n" , points - oudler );
    }

    return 0;
}
