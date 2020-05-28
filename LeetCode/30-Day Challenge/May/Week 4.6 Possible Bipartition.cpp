/*******************************************
 ***Problema: Possible Bipartition
 ***ID: Week4.6
 ***Juez: LeetCode
 ***Tipo: BFS (Bipartite Graph Check)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    bool bfs(int u, vector<int> &color, vector<vector<int> > &adj ){
        queue<int> Q;
        Q.push(u);
        color[u] = 1;
        while( !Q.empty() ){
            u = Q.front(); Q.pop();
            for( int i = 0 ; i < adj[u].size(); ++i ){
                int v = adj[u][i];
                if( color[v] == -1 ){
                    color[v] = 1 - color[u];
                    Q.push(v);
                }else if( color[v] == color[u] ) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int> > adj = vector<vector<int> >(N);
        int sz = dislikes.size();
        for( int i = 0 ; i < sz ; ++i ){
            int u = dislikes[i][0] - 1, v = dislikes[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(N, -1);
        
        for( int i = 0 ; i< N ; ++i ){
            if( color[i] == -1 )
                if(!bfs(i, color, adj)) return false;
        }
        return true;
    }
};
