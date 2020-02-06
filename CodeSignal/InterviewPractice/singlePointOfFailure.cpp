/*******************************************
 ***Problema: Single Point Of Failure
 ***Juez: CodeSignal
 ***Tipo: DFS - Bridge Detection
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

int dfsNum;
int bridges;
vector<int> low, seen;

void dfs(vector<vector<int> > &adj, int u, int p=-1){
    low[u] = seen[u] = dfsNum++;
    int V = adj.size();
    for( int v = 0 ; v < V ; ++v ){
        if( adj[u][v] && v != p ){
            if( seen[v] == -1 ){
                dfs(adj, v, u);
                low[u] = min( low[u], low[v] );
                if( low[v] == seen[v]) bridges++;
            }else{
                low[u] = min( low[u], seen[v] );
            }
        }
    }
}

int singlePointOfFailure(std::vector<std::vector<int>> connections) {
	int V = connections.size();
    dfsNum = 0;
    low = vector<int>(V, -1);
    seen = vector<int>(V, -1);
    bridges = 0;
    dfs(connections, 0);
    return bridges;
}

