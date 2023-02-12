/*******************************************
 ***Problema: Minimum Fuel Cost to Report to the Capital
 ***ID: Week 2.5
 ***Juez: LeetCode
 ***Tipo: DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int dfs(vector<vector<int> > &adj, int u, int p, LL &tot, int &seats){
        int nodes_cnt = 1;
        for(int v: adj[u]){
            if(v != p){
                nodes_cnt += dfs(adj, v, u, tot, seats);
            }
        }
        if(u > 0)
            tot += (nodes_cnt + seats - 1)/seats;
            //tot += nodes_cnt/seats + (nodes_cnt % seats > 0?1:0);
        return nodes_cnt;
    }

    LL minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int V = roads.size() + 1;
        vector<vector<int>> adj(V);
        for(vector<int> e:roads){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        LL tot = 0;
        dfs(adj, 0, -1, tot, seats);
        return tot;
    }
};
