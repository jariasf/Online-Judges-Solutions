/*******************************************
 ***Problema: Fermat Point Of Graphs
 ***ID: 1400
 ***Juez: LintCode
 ***Tipo: DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param x: The end points set of edges
     * @param y: The end points set of edges
     * @param d: The length of edges
     * @return: Return the index of the fermat point
     */
    
    #define pii pair<int,int>
    #define mp make_pair
    typedef long long LL;
    vector<int> children;
    vector<vector<pii> > adj;
    vector<LL> dist;
        
    void dfs(int u, int p, LL sum){
        dist[0] += sum;
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i].first, w = adj[u][i].second;
            if(v != p){
                dfs(v, u, sum + w);
                children[u] += children[v] + 1;
            }
        }
    }

    void get_distance(int u , int p){
        for( int i = 0 ; i < adj[u].size(); ++i ){
            int v = adj[u][i].first;
            LL w = adj[u][i].second;
            if(v != p){
                dist[v] = dist[u] + w * (children[0] - 2*children[v] - 1);
                get_distance(v, u);
            }
        }
    }
    
    int getFermatPoint(vector<int> &x, vector<int> &y, vector<int> &d) {
        int V = x.size() + 1;
        adj = vector<vector<pii>>(V);
        children = vector<int>(V, 0);
        for( int i = 0 ; i < x.size(); ++i ){
            adj[x[i]-1].push_back(mp(y[i]-1, d[i]));
            adj[y[i]-1].push_back(mp(x[i]-1, d[i]));
        }

        dist = vector<LL>(V, 0);
        dfs(0, 0, 0);
        get_distance(0, 0);
        
        LL minimum = dist[0];
        int vertex = 1;
        for( int i = 0 ; i < V ; ++i ){
            if( minimum > dist[i] ){
                minimum = dist[i];
                vertex = i + 1;
            }
        }
        return vertex;
    }
    /*
    [1,3,4,4,4]
    [2,2,2,5,6]
    [3,1,10,2,3]
    */
};
