/*******************************************
 ***Problema: Minimum Time to Collect All Apples in a Tree
 ***ID: Week 2.4
 ***Juez: LeetCode
 ***Tipo: DFS | BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> has_apple;
    int dfs(int u, int parent){
        int tot = 0;
        for(int v: adj[u]){
            if(v != parent){                
                int child_has_apple = dfs(v, u);
                if( child_has_apple || has_apple[v])
                    tot += child_has_apple + 2;
            }
        }
        return tot;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj = vector<vector<int> >(n+1);
        has_apple = hasApple;
        int E = edges.size();
        for(int i = 0 ; i < E; ++i){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0, -1);
    }
};
