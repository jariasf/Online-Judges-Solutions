/*****************************************
 ***Problema: Burrows Wheeler Decoder
 ***ID: 741
 ***Juez: UVA
 ***Tipo: Sorting
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

void concat( string s , vector< string> &v){
    int i , sz = v.size();
    for( i = 0 ; i < sz; ++i ){
        v[ i ] = s[ i ] + v[ i ];
    }
}

void print( vector< string > v ){
    for( int i = 0 ; i < v.size() ; ++i ) cout<<v[ i ]<<endl;

}

int main(){
    string s , aux;
    int n , len , q = 0;
    while( cin>>s>>n , n){
        if( q ) printf("\n");
        q = 1;
        aux = s;
        len = s.length();
        vector< string > v( len , "");
        concat( s , v );
        while( len-- ){
            sort( v.begin() , v.end() );
            concat( aux , v );
        }
        sort( v.begin() , v.end() );
        cout<<v[ n - 1 ].substr( 0 , v.size())<<endl;
    }
    return 0;
}
