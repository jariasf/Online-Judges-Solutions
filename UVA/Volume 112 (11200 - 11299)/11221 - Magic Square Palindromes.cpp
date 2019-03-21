/*****************************************
 ***Problema: Magic square palindromes
 ***ID: 11221
 ***Juez: UVA
 ***Tipo: String manipulation
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

    int t , l;
    char line[ 10005 ];
    scanf("%d" , &t );
    string s , r , aux;
    gets( line );
    for( int q = 1 ; q <= t ; ++q ){

        gets( line );
        s = "";
        r = "";
        l = strlen( line );
        for( int i = 0 ; i < l ; ++i ){
            if( 'a' <= line[ i ] && line[ i ] <= 'z' ){
                s+= line[ i ];
                aux = "";
                aux += line[ i ];
                r = aux + r;
            }
        }
        l = s.length();
        printf("Case #%d:\n" , q );
        if( s != r ){
            printf("No magic :(\n");
            continue;
        }
        double sq = sqrt( l );
        int i = (int) sq;
        if( i != sq || i * i != l ){
            printf("No magic :(\n");
            continue;
        }
        int j;
        for( j = 0 ; j < l ; j += (i + 1)){
            for( int k = j + 1 , w = j + i , cnt = 0 ; cnt < i ; ++k , w += i , cnt++ ){
                if( s[ k ] != s[ w ] ){
                    j = l;
                    break;
                }
            }
        }
        if( j != l ) printf("%d\n" , i);
        else printf("No magic :(\n");
    }

    return 0;
}
