/*******************************************
 ***Problema: Tree Diameter
 ***ID: 1245
 ***Juez: LeetCode
 ***Tipo: BFS|DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<vector<int> > adj;
    int V;
    pair<int,int> bfs(int u){
        queue<pii> Q;
        Q.push(mp(u, 0));
        vector<int> seen(V);
        seen[u] = 1;
        int maxi = -1;
        pii result;
        while( !Q.empty() ){
            pii p = Q.front(); Q.pop();
            u = p.first; 
            int d = p.second;
            if( d > maxi ){
                maxi = d;
                result = mp(u, maxi);
            }
            for( int i = 0 ; i < adj[u].size(); ++i ){
                int v = adj[u][i];
                if( !seen[v] ){
                    seen[v] = 1;
                    Q.push(mp(v, d + 1));
                }
                
            }
        }
        return result;
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        V = edges.size() + 1;
        adj = vector<vector<int> >(V);
        
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        pii p = bfs(0);
        pii res = bfs(p.first);
        return res.second;
    }
};
