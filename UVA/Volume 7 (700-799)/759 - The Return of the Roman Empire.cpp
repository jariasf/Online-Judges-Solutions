/********************************************
 ***Problema: The Return of the Roman Empire
 ***ID: 759
 ***Juez: UVA
 ***Tipo: Roman Cnoversion
 ***Autor: Jhosimar George Arias Figueroa
 ********************************************/

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

int romanToDecimal( const char *s ) {
    static int val[ 256 ] = { -1 };
    if ( val[ 0 ] < 0) {
        int a[] = { 1 , 5 , 10 , 50 , 100 , 500 , 1000 };
        for (int i = 0; i < 256; ++i ) val[ i ] = 0;
        for (int i = 0; i < 7; ++i ) val[ "IVXLCDM"[ i ] ] = a[ i ];
    }

    int res = 0;
    for ( ; *s ; ++s ) {
        res += val[ *s ];
        for ( const char *t = s + 1 ; *t ; ++t ) {
            if ( val[ *t ] > val[ *s ] ) {
                res -= 2 * val[ *s ];
                break;
            }
        }
    }
    return res;
}

#define MAX 104
char s[ MAX ];

string decimal2roman( int input)
{
    const string roman[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int decimal[13] =  {1000,  900, 500,  400, 100,   90,  50,   40,  10,   9,    5,    4,   1};
    string romanvalue = "";
    for(int i = 0 ; i < 13 ; ++i )
    {
        while( input >= decimal[ i ] )
        {
            input -= decimal[ i ];
            romanvalue += roman[ i ];
        }
    }
    return romanvalue;
}

bool valid(){
    string roman= "IVXLCDM";
    for( int i = 0 ; s[ i ] ; ++i ){
        if( roman.find( s[ i ] ) == -1 ) return false;
    }
    return true;
}

int main(){
    int res;
    while( gets( s ) ){
        if( valid() ){
            res = romanToDecimal( s );
            if( res < 4000 && strcmp( decimal2roman( res ).c_str() , s ) == 0 ){
                printf("%d\n" , res );
            }
            else puts("This is not a valid number");
        }
        else puts("This is not a valid number");
    }

    return 0;
}
