/*****************************************
 ***Problema: How old are you?
 ***ID: 11219
 ***Juez: UVA
 ***Tipo: Ad hoc - Time
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
int cd , cm , cy , bd , bm , by;

bool invalid(){
    if( cy < by )return true;
    if( cy == by && cm < bm )return true;
    if( cy == by && cm == bm && cd < bd )return true;
    return false;
}

int check(){
    int anios = cy - by;

    if( cm < bm ){
        anios--;
    }
    else if( cm == bm ){
        if( cd < bd ) anios--;
    }

    return anios;
}

int main(){

    int t;
    char s[ 15 ], b[ 15 ];
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%s %s" , &s , &b );
        printf("Case #%d: ", q);

        cd = (s[ 0 ]- '0') * 10 + ( s[ 1 ] - '0' );
        cm = (s[ 3 ]- '0') * 10 + ( s[ 4 ] - '0' );
		cy = (s[ 6 ]- '0') * 1000 + ( s[ 7 ] - '0' ) * 100 + ( s[ 8 ] - '0' ) * 10+ ( s[ 9 ] - '0' );
        bd = (b[ 0 ]- '0') * 10 + ( b[ 1 ] - '0' );
        bm = (b[ 3 ]- '0') * 10 + ( b[ 4 ] - '0' );
		by = (b[ 6 ]- '0') * 1000 + ( b[ 7 ] - '0' ) * 100 + ( b[ 8 ] - '0' ) * 10+ ( b[ 9 ] - '0' );

        if( invalid() ) puts("Invalid birth date");
        else{
            int anios = check();

            if( anios > 130 ) puts("Check birth date");
            else printf("%d\n" , anios );
        }
    }
    return 0;
}
