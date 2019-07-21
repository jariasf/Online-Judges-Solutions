/*******************************************
 ***Problema: Shortest Path with Alternating Colors
 ***ID: 5132
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair
#define RED 0 
#define BLUE 1
#define NONE 2
#define INF 1<<30
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int> > seen(n, vector<int>(3, 0));
        vector<vector<int> > d(n, vector<int>(3, INF));
        vector<vector<pii> > adj(n);
        vector<int> dist(n, INF);
        for( int i = 0 ; i < red_edges.size(); ++i )
            adj[ red_edges[i][0]].push_back( mp(red_edges[i][1], RED) );
        
        for( int i = 0 ; i < blue_edges.size(); ++i )
            adj[ blue_edges[i][0]].push_back( mp(blue_edges[i][1], BLUE) );
        
        queue< pii > Q;
        Q.push( mp(0,2));
        seen[0][NONE] = 1;
        dist[0] = 0;
        d[0][NONE] = 0;
        while( !Q.empty() ){
            pii p = Q.front(); Q.pop();
            int u = p.first, last_color = p.second;
            for( int i = 0 ; i < adj[u].size(); ++i ){
                int v = adj[u][i].first, color = adj[u][i].second;
                if( last_color != color && !seen[v][color] ){
                    d[v][color] = min( d[v][color], d[u][last_color] + 1);
                    Q.push( mp(v, color ) );
                    seen[v][color] = 1;
                }
            }
        }
        
        for( int i = 0 ; i< n ; ++i ){
            dist[i] = min( d[i][RED], min(d[i][BLUE], d[i][NONE]));
            if( dist[i] == INF ) dist[i] = -1;
        }
        return dist;
    }
};
