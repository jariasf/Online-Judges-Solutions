/*****************************************
 ***Problema: Decode the tape
 ***ID: 10878
 ***Juez: UVA
 ***Tipo: Strings
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
#define MAX 30
char s[ MAX ];
int main(){
    int len , i , c;
    while( gets( s ) ){
        if( s[ 0 ] == '_' ) continue;
        len = strlen( s );
        c = 0;
        for( i = len - 2 ; i > 0 ; --i ){
            if( s[ i ] == 'o' ) c |= 1<<( len - i - 2  );
            else if( s[ i ] == '.' ) len--;
        }
        putchar( c );
    }
    return 0;
}
