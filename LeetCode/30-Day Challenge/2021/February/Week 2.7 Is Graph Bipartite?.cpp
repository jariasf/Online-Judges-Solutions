/*******************************************
 ***Problema: Is Graph Bipartite?
 ***ID: Week2.7
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V+1, -1);
        for( int k = 0 ; k < V ; ++k ){
            if( color[k] != -1 ) continue;
            queue<int> Q;
            color[k] = 1;
            Q.push(k);
            while( !Q.empty() ){
                int u = Q.front(); Q.pop();
                for( int i = 0 ; i < graph[u].size(); ++i ){
                    int v = graph[u][i];
                    if( color[v] == -1 ){
                        color[v] = 1 - color[u];
                        Q.push(v);
                    }else if( color[v] == color[u] ){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
