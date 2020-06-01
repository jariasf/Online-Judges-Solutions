/*******************************************
 ***Problema: Reorder Routes to Make All Paths Lead to the City Zero
 ***ID: 1466
 ***Juez: LeetCode
 ***Tipo: BFS|DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// DFS
class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    vector<vector<pii> > adj;
    
    int dfs(int u, int p){
        int res = 0;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i].first;
            if( v != p ){
                res += adj[u][i].second + dfs(v, u);      
            }
        }
        return res;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        adj = vector<vector<pii> >(n);
        for( int i = 0 ; i < connections.size(); ++i ){
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(mp(v, 1));
            adj[v].push_back(mp(u, 0));
        }
        
        return dfs(0, -1);
        
    }
};

// BFS
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int> > adj(n);
        vector<unordered_set<int> > hash(n);
        for( int i = 0 ; i < connections.size(); ++i ){
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            hash[v].insert(u);
        }
        
        vector<bool> seen(n);
        queue<int> Q;
        Q.push(0);
        seen[0] = 1;
        int res = 0;
        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            for( int i = 0 ; i < adj[u].size(); ++i ){
                int v = adj[u][i];
                if( !seen[v] ){
                    if( hash[u].find(v) == hash[u].end() )
                        res++;
                    Q.push(v);
                    seen[v] = 1;
                }
            }
        }
        return res;
        
    }
};
