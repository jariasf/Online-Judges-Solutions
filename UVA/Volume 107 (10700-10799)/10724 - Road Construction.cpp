/*****************************************
 ***Problema: Road Construction
 ***ID: 10724
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Warshall
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
#define MAX 100
#define INF 1LL<<60
#define EPS 1e-8
double ady[MAX][MAX];
int a[ MAX ][ MAX ];
double x[ MAX ], y[ MAX ];
double getDist(int i , int j ){
    return sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j] ) );
}

int V, E;
void Init(){
    for(int i = 0 ; i < V ; ++i ){
        for(int j = 0 ; j < V ; ++j ){
            ady[ i ][ j ] = INF;
        }
        ady[ i ][ i ] = 0;
    }
}

void floyd(){
    for(int k = 0 ; k < V ; ++k ){
        for(int i = 0 ; i < V ; ++i ){
             for(int j = 0 ; j < V ; ++j ){
                double t = ady[ i ][ k ] + ady[ k ][ j ];
                if( t + EPS < ady[ i ][ j ] ){
                    ady[ i ][ j ] = t;
                }
             }
        }
    }
}

int main(){

    int E, u , v;

    while( scanf("%d %d" , &V , &E ) , V| E ){
        for( int i = 0 ; i < V && scanf("%lf %lf" , &x[i] , &y[i]); ++i );
        Init();
        memset( a , 0 , sizeof(a) );
        for( int i = 0 ; i < E && scanf("%d %d" , &u , &v ); ++i ){
            u--; v--;
            a[u][v] = a[v][u] = 1;
            ady[u][v] = ady[v][u] = getDist(u , v);
        }
        floyd();
        double ans = 0.0;
        double maxi = -1.0, mini = 1LL<<60;
        for( int i = 0 ; i < V ; ++i ){
            for( int j = 0 ; j < V ; ++j ){
                if( i == j || a[i][j] ) continue;
                double d = getDist(i,j);
                double cost = 0.0;

                for( int ii = 0 ; ii < V  ; ++ii ){
                    for( int jj = 0 ; jj < V ; ++jj ){
                        if( ii == jj ) continue;
                        if( (ady[ii][i] + d + ady[j][jj]) + EPS <= ady[ii][jj] ){
                            cost += (ady[ii][jj] - (ady[ii][i] + d + ady[j][jj]));
                        }
                    }
                }
                //cout<<i<<" "<<j<<" -- "<<cost<<" "<<d<<endl;
                if( cost > 0 ){
                    if( cost > maxi + EPS  ){
                        maxi = cost;
                        u = i; v = j;
                        mini = d;
                    }else if( cost == maxi ){
                        if( d + EPS < mini ){
                            mini = d;
                            u = i; v = j;
                        }
                    }
                }
            }
        }
        if( maxi < 0) puts("No road required");
        else{
            printf("%d %d\n", u + 1 , v + 1 );
        }
    }

    return 0;
}
