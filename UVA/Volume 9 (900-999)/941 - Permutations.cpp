/*****************************************
 ***Problema: Permutations
 ***ID: 941
 ***Juez: UVA
 ***Tipo: Math
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
#define MAX 25
char s[ MAX ];
long long n, fact[ MAX ] ,sum;
int del[ 300 ];

int main(){
    int t , i , j , len;
    fact[ 0 ] = 1;
    for( i = 1 ; i < 21 ; ++i ) fact[ i ] = i * fact[ i - 1 ];
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s %lld" , &s , &n ) ){
        len = strlen( s );
        sort( s , s + len );
        memset( del , 0 , sizeof( del ) );
        string str;
        for( i = 0 ; s[ i ] ; ++i ){
            sum = 0;
            str = "";
            for( j = 0 ; s[ j ] ; ++j ) if( !del[ s[ j ] ] ) str += s[ j ];
            for( j = i ; j < s[ j ] ; ++j )
            {
                if( sum + fact[ len - 1 ] > n ){
                    n -= sum;
                    del[ str[ j - i ] ] = 1;

                    printf("%c" , str[ j - i ] );
                    len--;
                    break;
                }
                sum += fact[ len - 1 ];
            }
        }
        printf("\n");
    }


    return 0;
}
