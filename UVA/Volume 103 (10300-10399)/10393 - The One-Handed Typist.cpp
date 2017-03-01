/*****************************************
 ***Problema: The One-Handed Typist
 ***ID: 10393
 ***Juez: UVA
 ***Tipo: Ad hoc Strings
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
#define MAX 55
#define MAXN 1005
int f , n , del[ 15 ] , valid[ MAXN ];
char s[ MAXN ][ MAX ];
char table[ 11 ][ 7 ] = { "qaz" , "wsx" , "edc" , "rfvtgb" , "space" ,
                          "space" , "yhnujm" , "ik," , "ol." , "p;/"};
bool possible( char c){
    int i , j;
    for( i = 0 ; i < 10 ; ++i ){
        if( del[ i ] ) continue;
        for( j = 0 ; table[ i ][ j ] ; ++j )
            if( table[ i ][ j ] == c ) return true;
    }
    return false;
}

int main(){
    int i , x , j , maxi , len ;
    while( scanf("%d %d" , &f , &n ) != EOF ){
        memset( del , 0 , sizeof( del ) );
        for( i = 0 ; i < f && scanf("%d" , &x ) ; ++i ) del[ x - 1 ] = 1;
        maxi = 0;
        for( i = 0 ; i < n && scanf("%s" , &s[ i ] ) ; ++i ){
            valid[ i ] = 0;
            for( j = 0 ; s[ i ][ j ] ; ++j )
                if( !possible( s[ i ][ j ] ) ){ j = -1; break;}

            if( j != -1 ){
                maxi = max( maxi , j );
                valid[ i ] = 1;
            }
        }
        set< string > ss;
        for( i = 0 ; i < n ; ++i ){
            if( strlen( s[ i ] ) == maxi && valid[ i ] ) ss.insert( s[ i ] );
        }
        printf("%d\n" , ss.size() );
        for( set< string > :: iterator it = ss.begin() ; it != ss.end() ; ++it ) 
			printf("%s\n" , (*it).c_str());
    }

    return 0;
}
