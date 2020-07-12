/*******************************************
 ***Problema: Path with Maximum Probability
 ***ID: 1514
 ***Juez: LeetCode
 ***Tipo: Dijkstra
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define Node pair<int, double>
    #define mp make_pair
    #define INF 1<<30
    
    struct cmp {
        bool operator() ( const Node &a , const Node &b ) {
            return a.second > b.second;
        }
    };
    
    vector<vector<Node>> adj;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        adj.clear();
        adj = vector<vector<Node> >(n);
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back(mp(v, -p));
            adj[v].push_back(mp(u, -p));
        }
        priority_queue< Node , vector<Node> , cmp > Q;

        vector<double> dist(n, (INF));   
        vector<bool> seen(n, 0);
        
        Q.push( Node( start , -1 ) );
        dist[ start ] = -1;
        while( !Q.empty() ){
            int u = Q.top().first;
            Q.pop();
            if( seen[ u ] ) continue;
            seen[ u ] = true;
            for( int i = 0 ; i < adj[ u ].size() ; ++i ){
                double w = adj[ u ][ i ].second;
                int v = adj[ u ][ i ].first;
                if( !seen[ v ] && -dist[ u ] * w < dist[v] ){
                    dist[ v ] = dist[ u ] * w;
                    dist[v] *= -1.0;
                    Q.push( Node( v , dist[ v ] ) );
                }
            }
        }        
        if( dist[end] == INF ) return 0;
        return -dist[end];
    }
};
