/*****************************************
 ***Problema: Andy's First Dictionary
 ***ID:  10815
 ***Juez: UVA
 ***Tipo: Ad hoc, String
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
    string s, str;
    vector<string> v;
    map<string , bool> mp;
    while( getline( cin , s ) ){
         str="";
         for( int i = 0 ; i < s.length(); ++i ){
             if( isalpha( s [ i ]) ) str+=tolower( s[ i ] );
             else str+=" ";
         }
         str+=" ";
         stringstream ss(str);
         while( ss>>s ){
             if( !mp[ s ]) v.push_back(s);
             mp[ s ] = true;
         }
    }

    sort(v.begin() , v.end() );
    for( int i = 0 ; i < v.size(); ++i ){
        cout<<v[i]<<endl;
    }
    return 0;
}
