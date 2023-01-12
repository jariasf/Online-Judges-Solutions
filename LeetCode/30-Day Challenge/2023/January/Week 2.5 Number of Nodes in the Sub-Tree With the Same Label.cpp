/*******************************************
 ***Problema: Number of Nodes in the Sub-Tree With the Same Label
 ***ID: Week 2.5
 ***Juez: LeetCode
 ***Tipo: DFS | BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Solution 1: Saving information at each node (frequency array)
// Complexity: O(V + E)
class Solution {
public:
    vector<vector<int> > adj;
    string labels;
    vector<int> res;
    vector<int> dfs(int u, int p){
        vector<int> hash(26);
        hash[labels[u] - 'a']++;
        for(int v: adj[u]){
            if( v != p){
                vector<int> cnt = dfs(v, u);
                for(int i = 0 ; i < 26 ; ++i){
                    hash[i] += cnt[i];
                }
            }
        }
        res[u] = hash[labels[u] - 'a'];
        return hash;
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string _labels) {
        labels = _labels;
        adj = vector<vector<int> >(n+1);
        for(vector<int> e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        } 
        res = vector<int>(n);
        dfs(0,0);
        return res;
    }
};



// Solution 2: Saving global information, using traversal similar to postorder
// Complexity: O(V + E)
class Solution {
public:
    vector<vector<int> > adj;
    string labels;
    vector<int> res, cnt;
    void postorder(int u, int p){  
        int prev = cnt[labels[u]-'a'];     
        for(int v: adj[u]){
            if( v != p) postorder(v, u);
        }
        cnt[labels[u]-'a']++;
        res[u] = cnt[labels[u]-'a'] - prev;
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string _labels) {
        labels = _labels;
        adj = vector<vector<int> >(n+1);
        for(vector<int> e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        } 
        res = vector<int>(n);
        cnt = vector<int>(26);
        postorder(0,0);
        return res;
    }
};
