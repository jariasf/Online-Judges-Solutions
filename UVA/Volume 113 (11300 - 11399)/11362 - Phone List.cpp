/*****************************************
 ***Problema: Phone List
 ***ID: 11362
 ***Juez: UVA
 ***Tipo: Sorting, Strings
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int t, n;
    scanf( "%d" ,&t );
    string s;
    bool b;
    while ( t -- ){
        vector<string> v;
        scanf( "%d" , &n );

        for( int i = 0 ; i < n ; ++i){
            cin>>s;
            v.push_back( s );
        }

        sort(v.begin() , v.end());
        b = false;
        for(int i = 0 ; i < n - 1 ; ++i){
            if( v[ i+1 ].length() >= v[i].length() && v[ i+1 ].substr( 0 , v[i].length() ) == v[i] ){
               b = true;
               break;
            }
        }
        if( b )printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
