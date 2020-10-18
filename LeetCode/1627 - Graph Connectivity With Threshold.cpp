/*******************************************
 ***Problema: Graph Connectivity With Threshold
 ***ID: 1627
 ***Juez: LeetCode
 ***Tipo: Union Find | DFS
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

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n);
        for( int i = threshold + 1 ; i <= n ; ++i ){
            for( int k = 1 ; k * i <= n ; ++k ){
                if( i != k * i )
                    uf.Union(i - 1, k*i - 1);
            }
        }
        vector<bool> res(queries.size());        
        for( int i = 0 ; i < queries.size(); ++i ){
            int u = queries[i][0], v = queries[i][1];
            if( uf.sameComponent(u - 1, v - 1) ) 
                res[i] = true;
        }
        return res;
    }
};

