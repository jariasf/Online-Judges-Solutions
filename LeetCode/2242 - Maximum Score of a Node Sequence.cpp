/*******************************************
 ***Problema: Maximum Score of a Node Sequence
 ***ID: 2242
 ***Juez: LeetCode
 ***Tipo: Graphs - Edge Lists
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<vector<int>> > adj(n);
        for(vector<int> e: edges ){
            int u = e[0], v = e[1];
            adj[u].push_back({scores[v], v});
            adj[v].push_back({scores[u], u});
        }
        
        for( int i = 0 ; i < n ; ++i ){
            sort(adj[i].rbegin(), adj[i].rend());
        }
        
        int res = -1;
        for( vector<int> e: edges ){
            int u = e[0], v = e[1];
            int sz_u = min(3, (int)adj[u].size()), sz_v = min(3, (int)adj[v].size());
            for( int i = 0 ; i < sz_u; ++i ){
                int next_u = adj[u][i][1];
                for( int j = 0 ; j < sz_v ; ++j ){
                    int next_v = adj[v][j][1];
                   if( next_u != v && next_u != next_v && next_v != u ){
                       res = max(res, adj[u][i][0] + adj[v][j][0] + scores[u] + scores[v] );
                   } 
                }
            }
        }
        return res;
    }
};
