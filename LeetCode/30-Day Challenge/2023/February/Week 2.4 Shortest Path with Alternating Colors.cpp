/*******************************************
 ***Problema: Shortest Path with Alternating Colors
 ***ID: Week 2.4
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    #define RED 0
    #define BLUE 1
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pii>> adj(n);
        for(vector<int> &e:redEdges){
            adj[e[0]].push_back(mp(e[1], RED));
        }

        for(vector<int> &e:blueEdges){
            adj[e[0]].push_back(mp(e[1], BLUE));
        }

        vector<int> res(n, -1);
        queue<vector<int>> Q;
        vector<vector<bool> > seen(n, vector<bool>(2,0));
        Q.push({0,2,0});
        seen[0][RED] = seen[0][BLUE] = 1;
        res[0] = 0;
        while(!Q.empty()){
            vector<int> cur = Q.front(); Q.pop();
            int u = cur[0], prev_color = cur[1], d = cur[2];
            for(pii p: adj[u]){
                int v = p.first, color = p.second;
                if(color != prev_color && !seen[v][color]){
                    seen[v][color] = 1;
                    Q.push({v, color, d + 1});
                    if( res[v] == -1 ) res[v] = d + 1;
                }
            }
        }
        return res;
    }
};
