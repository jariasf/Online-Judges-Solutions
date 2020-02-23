/*******************************************
 ***Problem: Validate Binary Tree Nodes
 ***ID: 1361
 ***Judge: LeetCode
 ***Type: Hashing | DFS
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Visited array
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& L, vector<int>& R) {
        vector<bool> used(n + 1);
        for( int i = 0 ; i < n ; ++i ){
            if( L[i] != -1 ){
                if( used[L[i]]) return false;
                used[L[i]] = 1;
            }
            if( R[i] != -1 ){
                if( used[R[i]]) return false;
                used[R[i]] = 1;
            }            
        }
        if( used[0] ) return false;
        
        for( int i = 1 ; i < n ; ++i ){
            if( !used[i] ) return false;
        }
        return true;
    }
};


// Cycle detection with DFS
class Solution {
public:

    vector<vector<int> > adj;
    vector<bool> seen;
    
    bool cycle(int u){
        
        if( adj[u].size() > 2 ) return true;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            if( !seen[v] ){
                seen[v] = 1;
                if( cycle(v) ) return true;
            }else
                return true;
        }
        return false;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        adj = vector<vector<int> >(n + 1, vector<int>());
        
        for( int i = 0 ; i < n ; ++i ){
            int u = leftChild[i], v = rightChild[i];
            if( u != -1 )
                adj[i].push_back(u);
            if( v != -1 )
                adj[i].push_back(v);
        }
        
        seen = vector<bool>(n + 1, false);
        int cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( !seen[i] ){
                if( cnt == 1 ) return false;
                seen[i] = 1;
                if( cycle(i) ) return false;
                cnt++;
            }
        }
        return true;
    }

};
