/*****************************************
 ***Problema: Spreading the News
 ***ID: 924
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS
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

#define MAX 2505

vector<int> ady[ MAX ];
int V;

struct Estado{
    int x;
    int d;
    Estado( int xx ,int dd):x(xx) , d(dd){}
};
bool seen[ MAX ];
int maxi , day , boom[ MAX ];

void bfs(int x ){
    memset( seen , 0 , sizeof( seen ) );
    memset( boom , 0 , sizeof( boom ) );
    queue< Estado > Q;
    Q.push( Estado( x , 0 ) );
    maxi = -1; day = -1;

    int cnt;
    seen[ x ] = 1;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();

        boom[ act.d ]++;
        if( act.d > 0 && boom[ act.d ] > maxi ){
            maxi = boom[ act.d ];
            day = act.d;
        }

        for( int i = 0 ; i < ady[ act.x ].size(); ++i  ){
            int v = ady[ act.x ][ i ];
            if( !seen[ v ] ){
                seen[ v ] = true;
                Q.push( Estado( v , act.d + 1) );
            }
        }
    }
}

int main(){
    int source , k, v;
    scanf("%d" , &V);
    for( int i = 0 ; i < V ; ++i )ady[ i ].clear();
    for( int u = 0 ; u < V ; ++u ){
		scanf("%d", &k);
        while( k-- ){
            scanf("%d" ,&v );
            ady[ u ].push_back( v );
        }
    }
    
	scanf("%d",&k);
    while( k-- ){
		scanf("%d",&source);
        if( ady[ source ].size() == 0 ){
            printf("0\n");
            continue;
        }
        bfs( source );
        printf("%d %d\n", maxi , day );
    }
    return 0;
}
