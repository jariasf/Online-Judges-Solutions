/*****************************************
 ***Problema: Conformity
 ***ID: 11286
 ***Juez: UVA
 ***Tipo: Data Structure, Map
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


    int n ,cnt;
    map<string , int >::iterator it;
    char s1[ 4 ] , s2[ 4 ] , s3[ 4 ], s4[ 4 ], s5[ 4 ];
    while( scanf("%d" , &n) , n ){
        map<string , int > mp;

        while( n-- ){
            vector<string> v;
            scanf("%s %s %s %s %s" , s1 , s2 , s3 , s4 , s5 );
            v.push_back( s1 );
            v.push_back( s2 );
            v.push_back( s3 );
            v.push_back( s4 );
            v.push_back( s5 );
            sort( v.begin() , v.end() );
            mp[ v[ 0 ] + v[ 1 ] + v[ 2 ] + v[ 3 ] + v[ 4 ] ]++;
        }
        int maxi = 0;
        for( it = mp.begin() ; it != mp.end() ; ++it ){
            if( (*it).second > maxi ){
                maxi = ( *it ).second;
            }
        }
        cnt = 0;
        for( it = mp.begin() ; it != mp.end() ; ++it ){
            if( (*it).second == maxi ){
                cnt+= ( *it ).second;
            }
        }
        printf("%d\n" , cnt );
    }


    return 0;
}
