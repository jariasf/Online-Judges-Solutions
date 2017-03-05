/*****************************************
 ***Problema: Work Reduction
 ***ID: 10670
 ***Juez: UVA
 ***Tipo: Greedy
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
    int t ,N , M , k ,A, B , n , l , j;
    char s[ 50 ];
    long long resp;
    string cad;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d %d %d" , &N ,&M ,&k );
        vector<pair<long long , string> > v;
        gets( s );
        for( int i = 0 ; i < k ; ++i ){
            gets( s );
            l = strlen( s );
            cad = "";
            for( j = 0 ; j < l ; ++j ){
                if( s[ j ] == ':' || s[ j ] ==',')cad += " ";
                else cad += s[ j ];
            }
            cad += " ";

            stringstream ss( cad );
            ss>>cad>>A>>B;
            resp = 0;
            n = N;

            while( n > M ){
                int half = n/2;
                if( half < M ){
                    resp += ( n - M )* A;
                    n = M;
                }
                else{
                    if( B <= ( n - half ) * A ){
                        resp += B;
                    }
                    else resp += ( n - half ) * A;
                    n = half;
                }
            }
            v.push_back( make_pair( resp , string( cad ) ) );
        }

        sort( v.begin() , v.end() );
        printf("Case %d\n" , q );
        for( int i = 0 ; i < k ; ++i ){
            printf("%s %lld\n" , v[ i ].second.c_str() , v[ i ].first );
        }

    }

    return 0;
}
