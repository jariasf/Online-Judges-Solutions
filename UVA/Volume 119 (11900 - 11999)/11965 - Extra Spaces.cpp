/*****************************************
 ***Problema: Extra Spaces
 ***ID: 11965
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

int main(){
    int t, n;
    string s, resp;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        if( q - 1 )cout<<endl;
        cin>>n;
        cout<<"Case "<<q<<":"<<endl;
        getline( cin , s );
        bool b;
        for( int i = 0 ; i < n ; ++i ){
            b = false;
            getline( cin , s );
            if( s[ s.length() - 1 ] == ' ' || s[ s.length() - 1 ] == '\t' )b = true;
            if( s[ 0 ] == ' ' || s[ 0 ] == '\t') resp = " ";
            else resp = "";
            s += " ";
            stringstream ss( s );
            while( ss>>s ){
                resp += s + " ";
            }
            cout<<resp.substr( 0 , resp.length() - 1 );
            if( b )cout<<" ";
            cout<<endl;
        }
    }
    return 0;
}
