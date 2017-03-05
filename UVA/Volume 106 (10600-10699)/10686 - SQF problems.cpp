/*****************************************
 ***Problema: SQF Problems
 ***ID: 10686
 ***Juez: UVA
 ***Tipo: Data Structure, Map
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

#define MAX 21
int main(){
    int t , n , m , c, cont[ MAX ], need[ MAX ];
    scanf("%d" , &t );
    char s[ 205 ];
    map<int, string> parse
    map<string , bool > seen; //descripcion -> 0|1
    map<string , set<int> > into;
    while( t-- ){
        seen.clear();
        parse.clear();
        into.clear();
        memset( cont , 0 , sizeof( cont ) );
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%s %d %d" , &s , &m  ,&c );
            need[ i ] = c;
            parse[ i ] = s;
            while( m-- ){
                scanf("%s" , &s );
                into[ s ].insert( i );
            }
        }
        gets( s );
        while( gets( s ) ){
            int l = strlen( s );
            if( l == 0 )break;
            s[ l++ ] = ' ';
            s[ l ] = '\0';
            for( int i = 0 ; i < l ; ++i ){
                if( !isalpha( s[ i ] ) ){
                    s[ i ] = ' ';
                }
            }
            char *p = strtok( s , " ");
            while( p != NULL ){
                if( !seen[ p ] ){
                    vector<int> pos( into[ p ].begin() , into[ p ].end() );
                    for( int i = 0 ; i < pos.size() ; ++i ){
                        cont[ pos[ i ] ]++;
                    }
                    seen[ p ] = 1;
                }
                p = strtok( NULL , " " );
            }
        }
        bool first = true;
        for( int i = 0 ; i < n ; ++i ){
            if( cont[ i ] >= need[ i ] ){
                if( !first )printf(",");
                printf("%s" , parse[ i ].c_str() );
                first = false;
            }
        }
        if( first )printf("SQF Problem.");
        printf("\n");
    }
    return 0;
}

