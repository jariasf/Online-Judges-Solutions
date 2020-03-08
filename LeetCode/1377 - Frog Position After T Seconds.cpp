/*******************************************
 ***Problem: Frog Position After T Seconds
 ***ID: 1377
 ***Judge: LeetCode
 ***Type: DFS
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > adj;
    int steps;
    double res;
    bool isLeaf;
    bool solve(int u, int target, int p=-1, double prob=1.0, int d=0){
        double n_children = adj[u].size();
        if( u != 1 )
            n_children--;
        
        if( u == target ){
            steps = d;
            res = prob;
            if( n_children == 0 ){
                isLeaf = true;
            }
            return true;
        }
        
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            if( v != p ){
                if(solve(v, target, u, prob * 1/n_children, d + 1)) return true;
            }
        }
        return false;
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        adj = vector<vector<int> >(n + 1);
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        res = 0.;
        steps = t + 1;
        isLeaf = false;
        solve(1, target);
        if( !isLeaf && steps < t ){
            res = 0.;
        }
        if( steps > t  ) res = 0;
        return res;
    }
};
