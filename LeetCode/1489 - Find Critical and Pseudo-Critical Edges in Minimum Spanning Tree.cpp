/*******************************************
 ***Problema: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 ***ID: 1489
 ***Juez: LeetCode
 ***Tipo: MST - Kruskal
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class UnionFind{
public:
    vector<int> uf;
    int components;
    UnionFind(int n){
        uf = vector<int>(n);
        components = n;
        for( int i = 0 ; i < n ; ++i )
            uf[i] = i;
    }    
    
    int Find(int x){
        if( x == uf[x] ) return x;
        return uf[x] = Find(uf[x]);
    }
    
    void Union(int x, int y){
        if( !sameComponent(x, y)){
            uf[Find(x)] = Find(y);
            components--;
        }
    }
    
    bool sameComponent(int x, int y){
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    
    struct Edge{
        int u, v, w, id;
        Edge(int _u, int _v, int _w, int _id){
            u = _u;
            v = _v;
            w = _w;
            id = _id;
        }
        Edge(){
            
        }
        bool operator<(Edge &e) const { 
            return w < e.w; 
        }
    };
    
    int mst(int n, vector<Edge> &edges, int del_idx=-1, bool del=false){
        UnionFind uf(n);
        int tot = 0 ;
        if(del_idx != -1 && !del){
            uf.Union(edges[del_idx].u, edges[del_idx].v);
            tot += edges[del_idx].w;
        }

        for( int i = 0 ; i < edges.size(); ++i ){
            if( i == del_idx ) continue;
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if( !uf.sameComponent(u, v) ){
                uf.Union(u, v);
                tot += w;
            }
        }
        if( uf.components == 1 )
            return tot;
        return 1<<30;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> v;
        for( int i = 0 ; i < edges.size(); ++i )
            v.push_back( Edge(edges[i][0], edges[i][1], edges[i][2], i));
        sort( v.begin(), v.end() );  
        vector<vector<int> > res(2);
        int cost = mst(n, v);
        for( int i = 0 ; i < v.size(); ++i ){
            int cost_del = mst(n, v, i, true);
            if( cost_del > cost ){
                res[0].push_back(v[i].id);
            }else{
                int cost_insert = mst(n, v, i, false);
                if( cost_insert == cost ){
                    res[1].push_back(v[i].id);
                }
            }
        }
        
        return res;
    }
};
