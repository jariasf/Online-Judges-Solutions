/*******************************************
 ***Problema: Remove Max Number of Edges to Keep Graph Fully Traversable
 ***ID: 1579
 ***Juez: LeetCode
 ***Tipo: Union Find
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class UnionFind{
public:
    vector<int> uf;
    int cc;
    UnionFind(int n){
        uf = vector<int>(n);
        cc = n;
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
            cc--;
        }
    }
    
    bool sameComponent(int x, int y){
        return Find(x) == Find(y);
    }
    
    int num_components(){
        return cc;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        UnionFind uf2(n);        
        int tot = 0;
        for( int i = 0 ; i < edges.size(); ++i ){
            edges[i][1]--; edges[i][2]--;
            if( edges[i][0] == 3 ){
                if( !uf.sameComponent( edges[i][1], edges[i][2]) ){
                    uf.Union( edges[i][1], edges[i][2]);
                    uf2.Union( edges[i][1], edges[i][2]);                    
                    tot++;
                }
            }
        }
        
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][1], v = edges[i][2];
            if( edges[i][0] == 1){
                if( !uf.sameComponent( u, v) ){
                    uf.Union(u, v);
                    tot++;
                } 
            }else if( edges[i][0] == 2 ){
                if( !uf2.sameComponent( u, v) ){
                    uf2.Union(u, v);
                    tot++;
                }
            }
        }
        
        if( uf.num_components() != 1 || uf2.num_components() != 1 ) return -1;
        return edges.size() - tot;
    }
};
