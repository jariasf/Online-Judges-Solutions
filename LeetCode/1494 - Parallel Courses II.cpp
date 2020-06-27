/*******************************************
 ***Problema: Parallel Courses II
 ***ID: 1494
 ***Juez: LeetCode
 ***Tipo: Greedy | DP + Bitmasks
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    vector<vector<int> > adj;
    vector<int> indegree;
    
    #define pii pair<int, int>
    #define mp make_pair
    vector<int> sizes;
    
    void dfs(int u){
        sizes[u] = 1;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i];
            dfs(v);
            sizes[u] += sizes[v];
        }
    }
    
    int topological(int n, int k){
        priority_queue<pii> Q;
        sizes = vector<int>(n);
        for( int i = 0 ; i < n ; ++i ){
            if( indegree[i] == 0 ){
                dfs(i);
                Q.push(mp(sizes[i], i));
            }
        }
        int res = 0;
        while( !Q.empty() ){
            res++;
            vector<int> next;
            for( int i = 0, sz = Q.size() ; i < sz && i < k ; ++i ){
                pii cur = Q.top(); Q.pop();
                for( int j = 0 ; j < adj[cur.second].size(); ++j ){
                    int v = adj[cur.second][j];
                    if( --indegree[v] == 0 ){
                        next.push_back(v);
                    }
                }
            }
            for( auto v: next){
                Q.push(mp(sizes[v], v));
            }            
        }
        return res;
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        adj = vector<vector<int> >(n);
        indegree = vector<int>(n);
        for( int i = 0 ; i < dependencies.size(); ++i ){
            adj[ dependencies[i][0] - 1 ].push_back(dependencies[i][1] - 1);
            indegree[dependencies[i][1] - 1]++;
        }
        return topological(n, k);
    }
};
