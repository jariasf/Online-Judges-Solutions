/*******************************************
 ***Problema: All Paths From Source to Target
 ***ID: Week4.3
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > res;
    void dfs(vector<vector<int> > &adj, int u, vector<int> cur){
        cur.push_back(u);
        if( u == adj.size() - 1 ){
            res.push_back(cur);
            return;
        }
        for(int v: adj[u])
            dfs(adj, v, cur);
        cur.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        vector<int> cur;
        dfs(graph, 0, cur);
        return res;
    }
};
