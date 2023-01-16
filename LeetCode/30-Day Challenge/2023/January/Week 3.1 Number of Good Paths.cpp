/*******************************************
 ***Problema: Number of Good Paths
 ***ID: Week 3.1
 ***Juez: LeetCode
 ***Tipo: Union Find
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int V = edges.size() + 1;
        vector<vector<int> > adj(V+1);
        map<int, vector<int> > hash;

        for(vector<int> e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);            
        }

        for(int i = 0 ; i < vals.size(); ++i){
            hash[vals[i]].push_back(i);
        }

        UnionFind uf(V);
        int res = 0;
        for(auto it:hash){       
            vector<int> idx = it.second;
            for(int i = 0 ; i < idx.size(); ++i ){
                int u = idx[i];
                for(int v: adj[u]){
                    if( vals[u] >= vals[v]){
                        uf.Union(u, v);
                    }
                }
            }
            unordered_map<int, int> cnt;
            for(int i = 0 ; i < idx.size(); ++i){
                cnt[uf.Find(idx[i])]++;
            }

            for(auto it2:cnt){
                int freq = it2.second;
                res += freq * (freq + 1)/2;
            }
        }
        return res;
    }
};
