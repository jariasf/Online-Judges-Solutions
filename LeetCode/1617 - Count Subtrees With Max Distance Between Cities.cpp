/*******************************************
 ***Problema: Count Subtrees With Max Distance Between Cities
 ***ID: 1617
 ***Juez: LeetCode
 ***Tipo: Brute Force - Bitmasks + DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 20
int adj[MAX][MAX];
class Solution {
public:
    bool isValid(vector<int> &nodes){
        int n = nodes.size(), cnt  = 0;
        for( int j = 0 ; j < n ; ++j ){
            for( int k = 0 ; k < n ; ++k ){
                if( adj[nodes[j]][nodes[k]])
                    cnt++;
            }
        }
        return cnt == 2*(n - 1);
    }

    vector<bool> seen;
    
    int maxDist(int u, int p, int n){
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( seen[i] && adj[u][i] && i != p )
                res = max( res, 1 + maxDist(i, u, n));
        }
        return res;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        memset(adj, 0 , sizeof(adj));
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0] - 1, v = edges[i][1] - 1;
            adj[u][v] = adj[v][u] = 1;
        }
        
        vector<int> res(n - 1);
        for( int i = 1 ; i < (1<<n) ; ++i ){
            vector<int> nodes;
            seen = vector<bool>(n);
            for( int j = 0 ; j < n ; ++j ){
                if( i & (1<<j ) ){
                    nodes.push_back(j);
                    seen[j] = 1;
                }
            }
           
            if( nodes.size() > 1 && isValid(nodes)){
                int t = 0;                  
                for( int k = 0 ; k < nodes.size(); ++k ){
                    t = max( t, maxDist(nodes[k], -1, n));
                }
                res[t - 1]++;
            }
        }
        return res;
    }
};
