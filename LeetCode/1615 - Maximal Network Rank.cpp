/*******************************************
 ***Problema: Maximal Network Rank
 ***ID: 1615
 ***Juez: LeetCode
 ***Tipo: Graph Degrees
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int> > adj(n + 1, vector<int>(n + 1, 0));
        vector<int> degree(n + 1);
        for( int i = 0 ; i < roads.size(); ++i ){
            adj[roads[i][0]][roads[i][1]] = 1;
            adj[roads[i][1]][roads[i][0]] = 1;            
            degree[ roads[i][0] ]++;
            degree[ roads[i][1] ]++;
        }
        int res =0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( i == j ) continue;
                res = max( degree[i] + degree[j] - adj[i][j], res );
            }
        }
        return res;
    }
};
