/*******************************************
 ***Problema: Graph Distances
 ***Juez: CodeSignal
 ***Tipo: Dijkstra
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define INF 1<<30
#define pii pair<int,int>
#define mp make_pair

struct comp{
    bool operator()(pii &p1, pii &p2){
        return p1.second > p2.second;
    }
};

std::vector<int> graphDistances(std::vector<std::vector<int>> g, int s) {
    int V = g.size();
    vector<int> dist(V, INF);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, comp > Q;
    Q.push(mp(s, 0));

    while( !Q.empty() ){
        pii p = Q.top(); Q.pop();
        int cur = p.first;
        for( int i = 0 ; i < V; ++i ){
            if( g[cur][i] >= 0 ){
                if( dist[i] > dist[cur] + g[cur][i] ){
                    dist[i] = dist[cur] + g[cur][i];
                    Q.push(mp(i, dist[i]));
                }
            }
        }
    }
    return dist;
}
