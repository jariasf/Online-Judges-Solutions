/*****************************************
 ***Problema: Abstract Names
 ***ID: 11713
 ***Juez: UVA
 ***Tipo: Manipulacion de Strings
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
char s1[ MAX ], s2[ MAX ];
int l1;
bool isVowel( char c ){
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u' )return true;
    return false;
}

bool solve(){
    bool v1 , v2;
    for( int i = 0 ; i < l1 ; ++i ){
        v1 = isVowel( s1[ i ] ) , v2 = isVowel( s2[ i ] );
        if( ( !v1 && v2 ) || ( !v2 && v1 ) || (!v1 && !v2 && s1[ i ] != s2[ i ] ) ) return false;
    }
    return true;
}

int main(){

    int t, l2;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%s %s" , &s1 , &s2 );
        l1 = strlen( s1 ); l2 = strlen( s2 );
        if( l1 != l2 ){
            printf("No\n");
            continue;
        }
        if( solve( ) )printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
