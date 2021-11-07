/*******************************************
 ***Problema: Maximum Path Quality of a Graph
 ***ID: 2065
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    #define MAX 1005
    vector<pii> adj[MAX];
    vector<int> vals;
    vector<bool> visited;
    
    int solve(int u, int maxTime){
        if( maxTime < 0 ) return -(1<<30);
        int res = -(1<<30);
        if( u == 0)
            res = 0;
        
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i].first, w = adj[u][i].second;
            if( visited[v] ){
                res = max(res, solve(v, maxTime - w ));
            }else{
                visited[v] = true;
                res = max(res, vals[v] + solve(v, maxTime - w ));
                visited[v] = false;
            }
        }
        return res;
    }    
    
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vals = values;
        visited = vector<bool>(values.size());
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if( w > maxTime ) continue;
            adj[u].push_back(mp(v, w));
            adj[v].push_back(mp(u, w));
        }
        visited[0] = true;
        return vals[0] + solve(0, maxTime);
    }
};
