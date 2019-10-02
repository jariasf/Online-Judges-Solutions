/*******************************************
 ***Problema: Sentence Similarity II
 ***ID: 855
 ***Juez: LintCode
 ***Tipo: DFS|Union-Find + Hashing
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
    /**
     * @param words1: 
     * @param words2: 
     * @param pairs: 
     * @return: Whether sentences are similary or not?
     */
    unordered_map<string, int> hash;
    int id;
    void mapString(vector<string> &v){
        for( int i = 0 ; i < v.size(); ++i ){
            if( hash.find(v[i]) == hash.end() ){
                hash[v[i]] = id++;
            }
        }
    } 
     
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        if( words1.size() != words2.size() ) return false;
        hash.clear(); id = 0;
        mapString(words1);
        mapString(words2);
        UnionFind uf = UnionFind(id);

        for( int i = 0 ; i < pairs.size(); ++i ){
            int u = hash[pairs[i][0]], v = hash[pairs[i][1]];
            uf.Union(u, v);
        }
        
        for( int i = 0 ; i < words1.size(); ++i ){
            int u = hash[words1[i]], v = hash[words2[i]];
            if( !uf.sameComponent(u, v))
                return false;
        }
        return true;
    }
};
