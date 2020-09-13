/*******************************************
 ***Problema: Min Cost to Connect All Points
 ***ID: 1584
 ***Juez: LeetCode
 ***Tipo: MST - Kruskal
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class UnionFind{
public:
    vector<int> uf;
    UnionFind(int n){
        uf = vector<int>(n);
        for( int i = 0 ; i < n ; ++i )
            uf[i] = i;
    }    
    
    int Find(int x){
        if( x == uf[x] ) return x;
        return uf[x] = Find(uf[x]);
    }
    
    void Union(int x, int y){
        uf[Find(x)] = Find(y);
    }
    
    bool sameComponent(int x, int y){
        return Find(x) == Find(y);
    }
};

struct Edge{
    int u, v, w;
    Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
    bool operator<( const Edge &a ) const{
        return w < a.w;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> adj;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back(Edge(i, j, d));
            }
        }
        
        sort(adj.begin(), adj.end());
        int res = 0;
        UnionFind uf(n);
        for( int i = 0 ; i< adj.size(); ++i ){
            int u = adj[i].u, v = adj[i].v, w = adj[i].w;
            if( !uf.sameComponent(u, v) ){
                uf.Union(u, v);
                res += w;
            }
        }
        return res;
    }
};
