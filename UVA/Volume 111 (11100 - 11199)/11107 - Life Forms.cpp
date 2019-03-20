/*****************************************
 ***Problema: Life Forms
 ***ID: 11107
 ***Juez: UVA
 ***Tipo: Strings, suffix array
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
#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXN = 100005;//1 << 20;

int N, delta;
char S[MAXN],s[MAXN];
int SA[MAXN];
int rank[MAXN];
int tmp[MAXN];
int LCP[MAXN];

bool comp( const int& i, const int& j ) {
	if ( rank[i] != rank[j] )
		return rank[i] < rank[j];
	if ( i + delta < N && j + delta < N )
		return rank[i + delta] < rank[j + delta];
	return i > j;
}

int main() {


    int n;
    bool b=false;
    while(scanf("%d",&n) && n){
        if(b)putchar('\n');
        b=true;
        strcpy(S,"");
        while(n--){
            scanf( "%s", &s );
            strcat(S,s);
            strcat( S , "$" );
        }
        N = strlen( S );
        REP( i, N ) {
            SA[i] = i;
            rank[i] = S[i];
        }

        for ( delta = 1; delta == 1 || tmp[N - 1] != N - 1; delta *= 2 ) {
            sort( SA, SA + N, comp );
            REP( i, N - 1 ) tmp[i + 1] = tmp[i] + comp( SA[i], SA[i + 1] );
            REP( i, N ) rank[ SA[i] ] = tmp[i];
        }

        for ( int i = 0, k = 0; i < N; i++ ) {
            if ( rank[i] == N - 1 )
                continue;
            for ( int j = SA[ rank[i] + 1 ]; S[i + k] == S[j + k]; k++ );
            LCP[ rank[i] ] = k;
            if ( k > 0 ) k--;
        }

        int max=0;

        for(int i = 0 ; i < N ; i++){
            if(LCP[i-1]>max)max=LCP[i-1];
        }

        vector<string> v;

        for(int i = 0 ; i < N; i++){
            if(max!=0 && LCP[i-1] == max){
               v.push_back(string(S+SA[i]).substr(0,max));
            }
        }
        if(v.size()==0){
           putchar('?');
        }
        else {
           sort(v.begin(),v.end());
           for(int i = 0 ; i < v.size(); i++){
              printf("%s\n",v[i].c_str());
           }
        }

        REP( i, N )
              printf( "%3d %s\n", LCP[i-1], S + SA[i] );
    }
	return 0;
}

