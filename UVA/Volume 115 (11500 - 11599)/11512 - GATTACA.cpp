/*****************************************
 ***Problema: GATTACA
 ***ID: 11512
 ***Juez: UVA
 ***Tipo: Strings, Suffix Array
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXN = 1010;

int N, delta;
char S[MAXN];
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

    int t;
    scanf("%d",&t);
    while( t-- ){

        scanf( "%s", &S );
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

        int max= 0, cont = 0;
        string s="";
        for(int i = 0 ; i <N ; i++){
            if(LCP[i-1] > max) { max = LCP[i-1]; s=string(S+SA[i]).substr(0,max);}
        }

        for(int i = 0 ; i < N ; i++){
            if(max!=0 && s.length()>0 && string(S+SA[i]).substr(0,max)==s){
               cont++;
            }
        }
        if(cont == 0)printf("No repetitions found!\n");
        else printf("%s %d\n",s.c_str(),cont);
    }
	return 0;
}
