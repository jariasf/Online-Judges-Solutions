/*******************************************
 ***Problema: Longest Path With Different Adjacent Characters
 ***ID: Week 2.6
 ***Juez: LeetCode
 ***Tipo: DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > adj;
    string s;
    int dfs(int u, int &res){
        int tot = 0, max1 = 0, max2 = 0;
        for(int v: adj[u]){
            int cnt_child = dfs(v, res);
            if( s[v] != s[u]){
                if( cnt_child > max1 ){
                    max2 = max1;                    
                    max1 = cnt_child;
                }else if( cnt_child > max2){
                    max2 = cnt_child;
                }
            }
        }
        res = max(res, max1 + max2 + 1);
        return max1 + 1;
    }

    int longestPath(vector<int>& parent, string _s) {
        int V = parent.size();
        s = _s;
        adj = vector<vector<int> >(V);
        for(int i = 1 ; i < V ; ++i)
            adj[parent[i]].push_back(i);
        int res = 1;
        dfs(0, res);
        return res;
    }
};
