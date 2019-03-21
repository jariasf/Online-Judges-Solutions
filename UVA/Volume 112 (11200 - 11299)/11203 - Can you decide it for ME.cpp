/*****************************************
 ***Problema: Can you decide it for ME?
 ***ID: 11203
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
#define MAX 55
char s[ MAX ];
bool valid(){
    int i;
    for( i = 0 ; s[ i ] ; ++i )
        if( s[ i ] != '?' && s[ i ] != 'M' && s[ i ] != 'E' ) return false;
    return true;
}
int main(){
    int t, i , x , y , z , m , e;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s" , &s ) ){
        if( !valid() ){ puts("no-theorem"); continue; }
        x = y = z = m = e = 0;
        for( i = 0 ; s[ i ] ; ++i ){ if( s[ i ] == 'M' ) m++; if( s[ i ] == 'E' ) e++; }
        for( i = 0 ; s[ i ] && s[ i ] != 'M' ; ++i ) x++;
        for( i = i + 1 ; s[ i ] && s[ i ] != 'E' ; ++i ) y++;
        for( i = i + 1 ; s[ i ] ; ++i ) z++;
        if( y > 0 && x > 0 && z > 1 && z == x + y && m == 1 && e == 1 )puts("theorem");
        else puts("no-theorem");
    }
    return 0;
}
