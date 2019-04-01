/*****************************************
 ***Problema: Mobile Casanova
 ***ID: 12085
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

    int n, num , ant_n , q = 1 , f_n;
    char s[ 15 ], ant_s[ 15 ] , fs[ 15 ];
    while( scanf("%d" , &n), n ){
        ant_n = -1;
        bool first = true;
        printf("Case %d:\n" , q++ );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%s" , &s );
            stringstream ss( s );
            ss>>num;
            if( first ){
                ant_n = num;
                strcpy( ant_s , s );
                strcpy( fs , s );
                first = false;
                continue;
            }

            if( num - ant_n > 1 ){
                int len = strlen( fs );
                int i = 0;
                for(; i < len ; ++i ){
                    if( fs[ i ] != ant_s[ i ] )break;
                }
                if( i == len ) printf("%s\n" , fs );
                else printf("%s-%s\n" , fs , ant_s + i );
                if( i + 1 == n )continue;
                ant_n = num;
                strcpy( ant_s , s );
                strcpy( fs , s );
            }
            if( i + 1 == n )continue;
            strcpy( ant_s , s );
            ant_n = num;
        }
        int len = strlen( fs );
        int i = 0;
        for(; i < len ; ++i ){
            if( fs[ i ] != s[ i ] )break;
        }
        if( i == len ) printf("%s\n" , fs );
        else printf("%s-%s\n" , fs , s + i );
        putchar('\n');
    }
    return 0;
}
