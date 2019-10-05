/*******************************************
 ***Problema: Sum of Distances in Tree
 ***ID: 834
 ***Juez: LeetCode
 ***Tipo: DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > adj;
    vector<int> count, result;
    int V;
    int totalDistance(int u, int p, int dist){
        int total = dist;
        count[u] = 1;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            if( v != p ){
                total += totalDistance(v, u, dist + 1);
                count[u] += count[v];    
            }
        }
        return total;
    } 
    
    void sumOfDistances(int u, int p, int total_dist){
        result[u] = total_dist;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            if( v != p ){
                sumOfDistances(v, u, total_dist - count[v] + V - count[v] );
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
        adj = vector<vector<int> >(N);
        for( int i = 0 ; i < edges.size(); ++i ){
            adj[ edges[i][0]].push_back( edges[i][1]);
            adj[ edges[i][1]].push_back( edges[i][0]);
        }
        count = vector<int>(N);
        int total = totalDistance(0, 0, 0);
        V = N;
        result = vector<int>(N);
        sumOfDistances(0, 0, total);
        return result;
    }
};
