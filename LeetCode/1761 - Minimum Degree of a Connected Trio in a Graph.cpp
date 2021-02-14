/*******************************************
 ***Problema: Minimum Degree of a Connected Trio in a Graph
 ***ID: 1761
 ***Juez: LeetCode
 ***Tipo: Brute Force + Graph Degree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 405
int adj[MAX][MAX];
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 5);
        memset(adj, 0 , sizeof(adj));
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0] - 1, v = edges[i][1] - 1;
            adj[u][v] = adj[v][u] = 1;
            degree[v]++;
            degree[u]++;
        }
        
        int res = INT_MAX;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ;j  < n ; ++j ){
                if( !adj[i][j] ) continue;
                for( int k = j + 1 ; k < n ; ++k ){
                    if( adj[i][j] && adj[j][k] && adj[i][k] ){
                        res = min(res, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }
        if( res == INT_MAX) return -1;
        return res;
    }
};
