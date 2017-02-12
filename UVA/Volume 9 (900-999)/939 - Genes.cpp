/*****************************************
 ***Problema: Genes
 ***ID: 939
 ***Juez: UVA
 ***Tipo: Data Structure
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
map< string , string > type;
map< string , vector< string > > p;

void solve( string u , string p1 , string p2 ){
    if( type.find( p1 ) == type.end() ){
        solve( p1 , p[ p1 ][ 0 ] , p[ p1 ][ 1 ] );
    }

    if( type.find( p2 ) == type.end() ){
        solve( p2 , p[ p2 ][ 0 ] , p[ p2 ][ 1 ] );
    }

    string type_p1 = type[ p1 ] , type_p2 = type[ p2 ];

    if( type_p1 == "non-existent" && type_p2  == "non-existent" ){
        type[ u ] = type_p1;
    }
    else if( type_p1 == "dominant"){
        if( type_p2 == "recessive" || type_p2 == "dominant" ){
            type[ u ] = "dominant";
        }
        else type[ u ] = "recessive";
    }
    else if( type_p1 == "recessive" ){
        if( type_p2 == "recessive" ){
            type[ u ] = type_p1;
        }
        else if( type_p2 == "dominant" ){
            type[ u ] = "dominant";
        }
        else type[ u ] = "non-existent";
    }
    else if( type_p2 == "dominant"){
        type[ u ] = "recessive";
    }
    else type[ u ] = "non-existent";
}

int main(){
    int t;
    scanf("%d" , &t );
    string u , v;

    while( t-- > 0 && cin>>u>>v ){
        if( v == "dominant" || v == "recessive" || v == "non-existent" ){
            type[ u ] = v;
        }
        else{
            p[ v ].push_back( u );
        }
    }

    for( map< string , vector< string > >:: iterator it = p.begin() ; it != p.end() ; ++it ){
        solve( it -> first , ( it -> second )[ 0 ] , ( it -> second )[ 1 ] );
    }

    for( map< string , string > :: iterator it = type.begin() ; it != type.end() ; ++it ){
        printf("%s %s\n" , (it -> first ).c_str() , ( it ->second ).c_str() );
    }

    return 0;
}
