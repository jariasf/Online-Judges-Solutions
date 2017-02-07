/*****************************************
 ***Problema: Simply Subsets
 ***ID: 496
 ***Juez: UVA
 ***Tipo: Ad hoc
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

int main(){

    int len_a , len_b , minl , x , p , n;
    string s;
    set<int> AA, BB;
    set<int> :: iterator it2;
    vector<int> A , B;
    vector<int> :: iterator it;
    while( getline( cin , s ) ){
        len_a = len_b = 0;
        stringstream ss( s + " ");

        while( ss>>x ){
            AA.insert( x );
        }

        getline( cin , s );
        stringstream ss2( s + " ");
        while( ss2>>x ){
            BB.insert( x );
        }

        for( it2 = AA.begin() ; it2 != AA.end() ; ++it2 ){
            A.push_back( *it2 );
        }
        for( it2 = BB.begin() ; it2 != BB.end() ; ++it2 ){
            B.push_back( *it2 );
        }
        vector<int> C( A.size() + B.size() );
        it = set_intersection( A.begin() , A.end() , B.begin() , B.end() , C.begin() );
        int intersection = ( int )( it - C.begin() );
        if( intersection == 0 ) puts("A and B are disjoint");
        else if( intersection == A.size() ){
            if( intersection == B.size() ) puts("A equals B");
            else if( B.size() > intersection ) puts( "A is a proper subset of B");
        }
        else if( intersection == B.size() ){
            if( A.size() > intersection )puts("B is a proper subset of A");
        }
        else puts("I'm confused!");
        A.clear();
        B.clear();
        AA.clear();
        BB.clear();
    }
    return 0;
}
