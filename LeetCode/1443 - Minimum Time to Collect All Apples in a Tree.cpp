/*******************************************
 ***Problem: Minimum Time to Collect All Apples in a Tree
 ***ID: 1443
 ***Judge: LeetCode
 ***Type: DFS
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Traversing Once
class Solution {
public:
    int res;
    vector<vector<int> > adj;
    vector<bool> hasApple;
    bool dfs(int u, int parent){
        bool apple = hasApple[u];
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            if( v != parent ){
                apple |= dfs(v, u);
            }
        }
        if( apple && u ) res += 2;
        return apple;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& _hasApple) {
        
        adj = vector<vector<int> >(n);
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        hasApple = _hasApple;
        res = 0;
        dfs(0, -1);
        
        return res;
    }
};



// Traversing Twice
class Solution {
public:
    vector<int> depth;
    vector<vector<int> > adj;
    void calc_depth(int root, int d, int p){
        depth[root] = d;
        for( int i = 0 ; i < adj[root].size(); ++i ){
            int v = adj[root][i];
            if( v != p )
                calc_depth(v, d + 1, root);                
        }
    }
    
    int cnt;
    vector<bool> seen;
    void dfs(int u){
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            if( depth[v] < depth[u]){
                cnt++;
                if( seen[v] )
                    return;
                
                seen[v] = 1;
                dfs(v);
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj = vector<vector<int> >(n);
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth = vector<int>(n, 0);
        calc_depth(0, 0, -1);
        seen = vector<bool>(n);
        int res = 0;    
        for( int i = 0 ; i < hasApple.size(); ++i ){
            if( hasApple[i] && !seen[i]){
                cnt = 0;
                seen[i] = 1;
                dfs(i);
                res += cnt * 2;
            }
        }
        return res;
    }
};
