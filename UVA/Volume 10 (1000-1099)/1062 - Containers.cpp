/*****************************************
 ***Problema: Containers
 ***ID: 1062
 ***Juez: UVA
 ***Tipo: Stack
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
#define MAX 1005

int solve( string s ){
    int n = s.length();
    vector<char> v;
    for( int i = 0 ; i < n ; ++i ){
        bool found = false;
        for( int j = 0 ; j < v.size() && !found ; ++j ){
            if( s[i] <= v[j] ){
                v[j] = s[i];
                found = true;
                break;
            }
        }
        if( !found )
            v.push_back( s[i] );
    }
    return v.size();
}

int main(){
    string s;
    int t = 1;
    while( cin>>s && s[0] != 'e' ){
        printf("Case %d: %d\n" , t++ , solve( s ) );
    }

    return 0;
}
