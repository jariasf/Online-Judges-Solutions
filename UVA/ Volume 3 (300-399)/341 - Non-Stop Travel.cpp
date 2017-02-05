/*****************************************
 ***Problema: Packets
 ***ID: 341
 ***Juez: UVA
 ***Tipo: Graph theory, Shortest paths, SSSP.
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
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
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 15
#define INF (1<<20)
#define pii pair< int, int >
#define pb push_back

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};


int D[MAX];
bool F[MAX];
int parent[MAX];
int main() {
    int i, u, v, w, sz, nodes, edges, starting,fin,cont=1;

    // creamos grafo
    while(scanf("%d", &nodes) && nodes){

        priority_queue< pii, vector< pii >, comp > Q;
        vector< pii > G[MAX];

        for(i=1;i<=nodes;i++){
            scanf("%d",&edges);
            while(edges--){
                scanf("%d %d",&v,&w);

                G[i].pb(pii(v,w));
            }
        }
        scanf("%d %d", &starting,&fin);

        // iniciamos grafo
        for(i=1; i<=nodes; i++) {D[i] = INF;parent[i]=-1;F[i]=0;}
        D[starting] = 0;
        Q.push(pii(starting, 0));

        // dijkstra
        while(!Q.empty()) {
            u = Q.top().first;
            Q.pop();
            if(F[u]) continue;
            sz = G[u].size();
            for(i=0; i<sz; i++) {
                v = G[u][i].first;
                w = G[u][i].second;
                if(!F[v] && D[u]+w < D[v]) {
                    D[v] = D[u] + w;
                    parent[v]=u; // ruta mas corta
                    Q.push(pii(v, D[v]));
                }
            }
            F[u] = 1; // visitado u
        }



        printf("Case %d: Path =",cont++);
        int ruta[100],tam=0;

        int end=fin;
        ruta[tam++]=fin;
        while(parent[end]!=-1){
            ruta[tam++]=parent[end];
            end=parent[end];
        }

        for(i=tam-1;i>=0;i--){
            printf(" %d",ruta[i]);
        }
        printf("; %d second delay\n",D[fin]);

    }

    return 0;
}
