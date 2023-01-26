/*******************************************
 ***Problema: Cheapest Flights Within K Stops
 ***ID: Week 4.5
 ***Juez: LeetCode
 ***Tipo: BFS | Dijkstra
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/


// BFS – O(V + E*k)

class Solution {
public:
    #define INF 1<<30
    #define pii pair<int, int>
    #define mp make_pair
    struct State{
        int dest, dist, steps;
        State(int _dest, int _dist, int _steps){
            dest = _dest;
            dist = _dist;
            steps = _steps;
        }
        
        State(){}
    };
    
    struct comp{
        bool operator()(State &s1, State &s2){
            return s1.dist > s2.dist;
        }
    };

    int bfs(vector<vector<pii>> &adj, int V, int source, int dest, int k){
        vector<int> dist(V, INF);
        queue<pii> Q;
        Q.push(mp(source, 0));
        dist[source] = 0;
        while(!Q.empty()){
            int sz = Q.size();
            
            for( int i = 0 ; i < sz ; ++i ){
                pii cur = Q.front(); Q.pop();
                int u = cur.first, d = cur.second;      
                for( pii next: adj[u]){
                    int v = next.first, w= next.second;
                    if( d + w < dist[v] ){
                        dist[v] = d + w;
                        Q.push(mp(v, dist[v]));
                    }
                }
            }
            k--;
            if( k == 0 ) break;
        }
        if( dist[dest] == INF )
          return -1;
        return dist[dest];
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii> > adj(n);
        for( vector<int> e: flights){
            adj[e[0]].push_back(mp(e[1], e[2]));
        }
        return bfs(adj, n, src, dst, k + 1); 
    }
};


// Dijkstra – O(V + E*k*log(E*k))

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    #define INF 1<<30
    struct State{
        int node, dist, steps;
        State(int _node, int _dist, int _steps){
            node = _node;
            dist = _dist;
            steps = _steps;
        }
    };

    struct cmp{
        bool operator()(State &s1, State &s2){
            return (s1.dist > s2.dist) || (s1.dist == s2.dist && s1.steps > s2.steps);
        }
    };

    int dijkstra(vector<vector<pii> > &adj, int src, int dst, int k){
        int n = adj.size();
        priority_queue<State, vector<State>, cmp > Q;
        Q.push(State(src, 0, 0));
        vector<vector<int> > dist(n, vector<int>(k + 5, INF));
        dist[src][0] = 0;

        while(!Q.empty()){
            State cur = Q.top(); Q.pop();
            int u = cur.node, d = cur.dist, steps = cur.steps;
            if(u == dst) return d;
            for(pii p: adj[u]){
                int v = p.first, w = p.second;
                if( steps + 1 <= k && dist[u][steps] + w < dist[v][steps + 1]){
                    dist[v][steps + 1] = dist[u][steps] + w;
                    Q.push(State(v, dist[v][steps + 1], steps + 1));
                }
            }
        } 
        return -1;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii> > adj(n);
        for(vector<int> v:flights){
            adj[v[0]].push_back(mp(v[1], v[2]));        
        }
        return dijkstra(adj, src, dst, k + 1);
    }
};
