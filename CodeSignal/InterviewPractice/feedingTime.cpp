/*******************************************
 ***Problema: Feeding Time
 ***Juez: CodeSignal
 ***Tipo: Graph Coloring - Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

vector<vector<int> > adj;
void create_graph(vector<vector<string> > &classes){
    int n = classes.size();
    adj = vector<vector<int> >(n);
    unordered_set<string> hash;
    for( int i = 0 ; i < n; ++i ){
        hash.clear();
        for( int j = 0 ; j < classes[i].size(); ++j )
            hash.insert(classes[i][j]);
        
        for( int j = i + 1 ; j < n ; ++j ){
            bool exists = false;
            for( int k = 0 ; k < classes[j].size(); ++k ){
                if( hash.find( classes[j][k] ) != hash.end() ){
                    exists = true;
                    break;
                }
            }
            if( exists ){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

#define INF 1<<30
vector<int> color;

bool correctColor(int u, int colorID ){
    for( int i = 0 ; i < adj[u].size(); ++i ){
        int v = adj[u][i];
        if( color[v] == colorID ) return false;
    }
    return true;
}

int dfs(int maxColor, int num_nodes, int V){
    if( num_nodes == V ){
        return maxColor;
    }
    int minimum = INF;
    int i = num_nodes;
    if( color[i] == -1 ){
        for( int j = 1 ; j <= 5 ; ++j ){
            if( !correctColor(i, j) ) continue;
            color[i] = j;
            int res = dfs(max(maxColor, j), num_nodes + 1, V);
            minimum = min( minimum, res );
            color[i] = -1;
        }
    }
    return minimum;
}

int graph_coloring(int V){
    color = vector<int>(V, -1);
    seen = vector<int>(V, 0);
    int minimum = dfs(-1, 0, V);
    if( minimum == INF ) minimum = -1;
    return minimum;
}

int feedingTime(std::vector<std::vector<std::string>> classes) {
    create_graph(classes);
    return graph_coloring(classes.size());
}
