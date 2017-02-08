/*****************************************
 ***Problema: Sum It Up
 ***ID: 574
 ***Juez: UVA
 ***Tipo: Bitwise, Sumsets
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

bool f( vector<int> v1, vector<int> v2 ){
    int l = min( v1.size() , v2.size() );
    for( int i = 0 ; i < l ; ++i ){
        if( v1[ i ] == v2[ i ])continue;
        else return v1[ i ] > v2[ i ];
    }

}

int main(){
    int t, n, sum;
    while( scanf("%d %d", &t, &n ) && t|n ){
        int a[ n ];
        for( int i  = 0 ; i < n ; ++i ) scanf("%d", &a[ i ]);
        set< vector<int> > v;
        for( int i = 0 ; i < (1<<n); ++i){
           sum = 0;
           vector<int> vv;
           for( int j = 0 ; j < n ;++j ){
              if( i & 1<<j ){
                 sum+=a[ j ];
                 vv.push_back( a[ j ]);
              }
           }
           if( sum == t ){
              sort( vv.rbegin() , vv.rend());
              v.insert( vv );
           }
        }
        set< vector<int> > ::iterator it;


        printf("Sums of %d:\n", t );
        if( v.size() == 0 )printf("NONE\n");
        else{

            vector< vector<int> > sumas;

            for( it = v.begin() ; it != v.end(); ++it ){
              sumas.push_back( *it);
            }
            sort( sumas.begin() , sumas.end() , f );
            for( int i = 0 ; i < sumas.size(); ++i ){
               printf("%d", sumas[ i ][ 0 ]);
               for( int j = 1 ; j < sumas[ i ].size(); ++j ){
                  printf("+%d", sumas[ i ][ j ]);
               }
               printf("\n");
            }
        }

    }

    return 0;
}
