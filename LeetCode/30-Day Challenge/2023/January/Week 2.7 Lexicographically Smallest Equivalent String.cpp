/*******************************************
 ***Problema: Lexicographically Smallest Equivalent String
 ***ID: Week 2.7
 ***Juez: LeetCode
 ***Tipo: Union Find
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
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
            int xRoot = Find(x), yRoot = Find(y);
            if( xRoot < yRoot) uf[yRoot] = xRoot;
            else uf[xRoot] = uf[yRoot];
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        for(int i = 0 ; i < s1.size() ; ++i){
            int u = s1[i]-'a', v = s2[i]-'a';
            uf.Union(u, v);    
        }        
        string res = "";
        for(char c:baseStr){
            res += (char)(uf.Find(c-'a') + 'a');
        }
        return res;
    }
};
