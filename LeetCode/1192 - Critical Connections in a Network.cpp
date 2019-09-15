/*******************************************
 ***Problema: Critical Connections in a Network
 ***ID: 1192
 ***Juez: LeetCode
 ***Tipo: Graph Theory, Bridges
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    #define MAXN 100001
    //N vertices, M aristas
    int N, counter, seen[MAXN], low[MAXN];
    vector<int> adj[MAXN], stk;
    vector<vector<int> > res;
    void dfs(int x, int parent){
        int kids = 0, art = 0;

        low[x] = seen[x] = ++counter;
        stk.push_back(x);

        for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); ++it) {
            int y = *it;
            if (y == parent) continue;

            if (seen[y] == 0) {
                dfs(y, x);
                low[x] = min(low[x], low[y]);
                if (low[y] == seen[y]) {
                    vector<int> v = {x,y};
                    res.push_back(v);
                }
            } else {
                low[x] = min(low[x], seen[y]);
            }
        }
    }
 
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        res.clear();
        for( int i = 0 ;i < MAXN ; ++i ) adj[i].clear();
        for( int i = 0 ; i < connections.size(); ++i ){
            adj[connections[i][0]].push_back( connections[i][1]);
            adj[connections[i][1]].push_back( connections[i][0]);
        }
        memset(seen, 0, sizeof(seen));
        counter = 0;
        stk.clear();
        for (int x = 0; x < n; x++)
            if (seen[x] == 0) dfs(x, -1);
        return res;
    }
};
