/*******************************************
 ***Problema: Redundant Connection II
 ***ID: 1087
 ***Juez: LintCode
 ***Tipo: DFS|Union Find - Cycle Detection
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Union Find
class Solution {
public:
    
    vector<int> uf;
    int Find(int x){
        if( uf[x] == x ) return x;
        return uf[x] = Find(uf[x]);
    }
    
    void Union(int x, int y){
        uf[y] = Find(x);
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int V = edges.size();
        uf = vector<int>(V + 1);
        vector<int> parent(V + 1, -1);
        for( int i = 1 ; i <= V ; ++i ) uf[i] = i;
        int first, second, last;
        first = second = last= -1;
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            if( parent[v] != -1 ){
                first = parent[v];
                second = i;
            }else{
                parent[v] = i;
                //if cycle
                if( Find(u) == v )
                    last = i;
                Union(u, v);
            }
        }
        if( last == -1 ) return edges[second];
        else if( second == -1 ) return edges[last];        
        return edges[first];
    }
};


// DFS
class Solution {
public:
    vector<vector<pair<int,int> > > adj;
    vector<bool> visited;
    stack<pair<int,int> > S;
    vector<pair<int,int> > cycle;
    
    bool detectCycle(int u){
        visited[u] = 1;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i].first;
            if( visited[v] ){
                pair<int,int> cycle_node = adj[u][i];
                cycle.push_back(cycle_node);
                while( !S.empty() ){
                    cycle_node = S.top(); S.pop();
                    if(cycle_node.first == v ) break;
                    cycle.push_back(cycle_node);
                }
                return true;
            }else{
                S.push(adj[u][i]);
                if( detectCycle(v) ) return true;
            }
        }
        return false;
    }
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        
        int V = edges.size();
        vector<int> indegree(V + 5);
        adj = vector<vector<pair<int,int> > >(V + 5);
        
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            indegree[v]++;
            adj[u].push_back(make_pair(v, i));
        }
        
        int prob_node = -1;
        for( int i = 1 ; i <= V ; ++i ){
            if( indegree[i] == 2 ){
                prob_node = i;
                break;
            }
        }
        
        visited = vector<bool>(V + 5);
        vector<int> remove_edge;     
        while( !S.empty() ) S.pop();
        cycle.clear();
        
        if( prob_node != -1 ){
            bool isCycle = detectCycle(prob_node);
            if( !isCycle ){
                for( int i = edges.size() - 1 ; i >= 0 ; --i ){
                    if( edges[i][1] == prob_node )
                        return edges[i];
                }
            }else{
                pair<int,int> last_node_cycle = cycle[0];
                remove_edge = edges[last_node_cycle.second];
            }
        }else{
            for( int i = 1 ; i <= V; ++i ){
                if( !visited[i] ){
                    if( detectCycle(i) ){
                        int maximum = 0;
                        for( int j = 0 ; j < cycle.size(); ++j ){
                            pair<int,int> node_cycle = cycle[j];
                            if( node_cycle.second > maximum ){
                                maximum = node_cycle.second;
                            }
                        }
                        remove_edge = edges[maximum];
                    }
                }
            }
        }
        return remove_edge;
    }
};
