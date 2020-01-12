/*******************************************
 ***Problema: Number of Operations to Make Network Connected
 ***ID: 1319
 ***Juez: LeetCode
 ***Tipo: Union Find
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class UnionFind{
public:
    vector<int> uf;
    int components;
    UnionFind(int n){
        uf = vector<int>(n);
        for( int i = 0 ; i < n ; ++i )
            uf[i] = i;
        components = n;
    }    
    
    int Find(int x){
        if( x == uf[x] ) return x;
        return uf[x] = Find(uf[x]);
    }
    
    void Union(int x, int y){
        uf[Find(x)] = Find(y);
        components--;
    }
    
    bool sameComponent(int x, int y){
        return Find(x) == Find(y);
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int res = 0;
        int rep = 0;
        for( int i = 0 ; i < connections.size(); ++i ){
            vector<int> e = connections[i];
            int x = e[0], y = e[1];
            if( uf.sameComponent(x, y) ){
                rep++;
            }else{
                uf.Union(x, y);
            }
        }
        
        int comp = uf.components;
        if( rep >= comp - 1 ){
            res = comp - 1;
        }else{
            res = -1;
        }
        return res;
    }
};
