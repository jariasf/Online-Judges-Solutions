/*******************************************
 ***Problema: Shortest Path Visiting All Nodes
 ***ID: 1422
 ***Juez: LintCode
 ***Tipo: BFS + Bitmasks
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param graph: the graph
     * @return: the shortest path for all nodes
     */
     
    struct State{
        int u, mask, d;
        State(int _u, int _mask, int _d): u(_u), mask(_mask), d(_d){}
        State(){}
    };
     
    int shortestPathLength(vector<vector<int>> &graph) {
        int V = graph.size();
        queue<State> Q;
        vector<vector<int> > seen(V, vector<int>((1<<V) + 1, false));
        for( int i = 0 ; i < V; ++i ){
            Q.push(State(i, 1<<i, 0));
            seen[i][1<<i] = true;
        }
        
        while(!Q.empty() ){
            State s = Q.front(); Q.pop();
            int u = s.u, d = s.d, mask = s.mask;
            if( mask == (1<<V) - 1) return d;
            for( int i = 0 ; i < graph[u].size(); ++i ){
                int v = graph[u][i];
                int next_mask = (1<<v | mask);
                if( !seen[v][next_mask]){
                    seen[v][next_mask] = true;
                    Q.push(State(v, next_mask, d + 1));
                }
            }
        }
        return 0;
    }
};
