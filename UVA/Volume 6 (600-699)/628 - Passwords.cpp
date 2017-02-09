/*****************************************
 ***Problema: Passwords
 ***ID: 628
 ***Juez: UVA
 ***Tipo: Recursion
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


char rule[ 370 ];
int ceros, final;
string toString( int n ){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}

int getFin( ){
    if( ceros == 0 )return 0;
    if( ceros == 1 )return 9;
    if( ceros == 2 )return 99;
    if( ceros == 3 )return 999;
    if( ceros == 4 )return 9999;
    if( ceros == 5 )return 99999;
    if( ceros == 6 )return 999999;
    if( ceros == 7 )return 9999999;
    if( ceros == 8 )return 99999999;
    return 999999999;
}

int main(){
    int n , m;
    char s[ 205 ][ 400 ];
    while( scanf( "%d" , &n ) == 1 ){
        for( int i = 0 ; i < n ; ++i ){
            scanf("%s" , &s[ i ] );
        }
        scanf("%d" , &m );
        printf("--\n");
        while( m-- ){
            scanf("%s" , &rule );

            int len = strlen( rule );
            ceros = 0;
            for( int j = 0 ; j < len ; ++j ) if( rule[ j ] == '0' )ceros++;
            final = getFin( );

            for( int q = 0 ; q < n ; ++q ){
                 string number = "0";
                 int num = 0;
                 while( final >= num ){
                        int len = number.length();
                        int l = strlen( rule );
                        string resp = "";

                        for( int i = 0 , j = ceros  ; i < l ; ++i ){
                            if( rule[ i ] == '#' ){
                                resp += s[ q ];
                            }
                            else if( rule[ i ] == '0'){
                                if( j <= len ){
                                    resp += number[ len - j ];
                                }
                                else resp +="0";
                                j--;
                            }
                        }
                        printf("%s\n" , resp.c_str() );
                        num++;
                        number = toString( num );
                 }
            }
        }
    }

    return 0;
}
