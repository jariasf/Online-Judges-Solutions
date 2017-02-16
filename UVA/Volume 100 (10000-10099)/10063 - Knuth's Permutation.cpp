/*****************************************
 ***Problema: Knuth's Permutation
 ***ID: 10063
 ***Juez: UVA
 ***Tipo: Next_permutation
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 12
char s[ MAX ];
int len;

void solve( int l , string str ){
    if( l == len ){
        printf("%s\n" , str.c_str() );
        return;
    }
    int i;
    string left , right , aux;
    for( i = 0 ; i <= l ; ++i ){
        left = str.substr( 0 , i );
        right = str.substr( i );
        aux = ""; aux += s[ l ];
        solve( l + 1 , left + aux + right );
    }

}

int main(){
    int i , q = 0;
    while( scanf("%s" , s ) != EOF ){
        if( q ) printf("\n");
        q = 1;
        len = strlen( s );
        string aux = ""; aux += s[ 0 ];
        solve( 1 , aux );
    }
    return 0;
}
