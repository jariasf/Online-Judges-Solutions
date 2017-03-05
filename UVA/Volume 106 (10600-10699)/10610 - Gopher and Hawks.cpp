/*****************************************
 ***Problema: Gopher and Hawks
 ***ID: 10610
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, Shortest Path
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
#define mp make_pair
#define f first
#define s second
#define MAXN 10005
#define MAX 10005
vector<int> ady[ MAX ];
int Vs,T;
double xfin , yfin;

struct Estado{
    int x, d;
    Estado( int xx ,int dd):x(xx) , d(dd){}
};

int bfs(){
    bool seen[ MAX ];
    memset( seen , 0 , sizeof( seen ) );
    queue<Estado> Q;
    Q.push( Estado( 0 , 0 ) );

    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();

        if( act.x == 1 ){
            return act.d;
        }

        for( int i = 0 ; i < ady[ act.x ].size(); ++i ){
            int w = ady[ act.x ][ i ];
            if( !seen[ w ] ){
                seen[ w ] = true;
                Q.push( Estado( w , act.d + 1 ) );
            }
        }
    }
    return -1;

}

int main(){
    char s[ MAXN ];
    double x , y;
    while( scanf("%d %d", &Vs ,&T ) && Vs|T ){
        vector< pair<double , double> > v;
        scanf("%lf %lf", &x ,&y );
        v.push_back( mp( x , y ) );
        scanf("%lf %lf", &xfin ,&yfin );
        v.push_back( mp( xfin , yfin ) );
        gets( s );
        while( gets( s ) && strlen(s) > 0 ){
            sscanf(s , "%lf %lf", &x , &y);
            v.push_back( mp( x , y ) );
        }

        for( int i = 0 ; i < v.size(); ++i ){
            for( int j = i + 1; j < v.size(); ++j ){

                double dist = ( v[ i ].f - v[ j ].f )*( v[ i ].f - v[ j ].f ) + ( v[ i ].s - v[ j ].s )*( v[ i ].s - v[ j ].s );
                dist = sqrt( dist );

                if( dist <= T* 60.0 * Vs ){
                    ady[ i ].push_back( j );
                    ady[ j ].push_back( i );
                }

            }
        }
        T = bfs();
        if( T == -1 )printf("No.\n");
        else printf("Yes, visiting %d other holes.\n" , T - 1);
        for( int i = 0 ; i < MAX ; ++i )ady[ i ].clear();
    }

    return 0;
}
