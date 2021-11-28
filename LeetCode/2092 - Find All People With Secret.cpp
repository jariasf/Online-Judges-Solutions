/*******************************************
 ***Problema: Find All People With Secret
 ***ID: 2092
 ***Juez: LeetCode
 ***Tipo: Sorting + Union Find | BFS
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
    
    void update(int idx){
        uf[idx] = idx;
    }
};

class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<int> > hash;
        UnionFind uf = UnionFind(n);
        uf.Union(0, firstPerson);
        for( int i = 0 ; i < meetings.size(); ++i ){
            vector<int> v = meetings[i];
            hash[v[2]].push_back(i);
        }
        
        for(auto it:hash ){
            vector<int> t = it.second;
            for( int i = 0 ; i < t.size(); ++i ){
                vector<int> v = meetings[t[i]];
                uf.Union(v[0], v[1]);
            }
            
            for( int i = 0 ; i < t.size(); ++i ){
                vector<int> v = meetings[t[i]];
                if( uf.Find(v[0]) != uf.Find(0) && uf.Find(v[1]) != uf.Find(0) ){
                    uf.update(v[0]);
                    uf.update(v[1]);
                }
            }
        }

        vector<int> res;
        for( int i = 0 ; i < n ; ++i ){
            if( uf.Find(i) == uf.Find(0) )
                res.push_back(i);
        }
        return res;
    }
};
