/*******************************************
 ***Problema: Largest Component Size by Common Factor
 ***ID: Week5.2
 ***Juez: LeetCode
 ***Tipo: Union Find + Prime Factorization
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class UnionFind{
public:
    vector<int> uf, cc;
    int max_cc;
    UnionFind(int n){
        cc = vector<int>(n, 1);
        uf = vector<int>(n);
        max_cc = 1;
        for( int i = 0 ; i < n ; ++i )
            uf[i] = i;
    }    
    
    int Find(int x){
        if( x == uf[x] ) return x;
        return uf[x] = Find(uf[x]);
    }
    
    void Union(int x, int y){
        int xRoot = Find(x), yRoot = Find(y);
        if( xRoot != yRoot ){
            cc[yRoot] += cc[xRoot];
            uf[xRoot] = yRoot;
            max_cc = max(max_cc, cc[yRoot]);
        }
    }
    
    int maxComponent(){
        return max_cc;
    }
};

class Solution {
public:
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        
        UnionFind uf(n);
        unordered_map<int, int> last;
        
        for( int i = 0 ; i < n ; ++i ){
            int x = A[i];
            for( int j = 2 ; j * j <= x ; ++j ){
                if( x % j == 0 ){
                    if( last.find(j) != last.end() )
                        uf.Union(i, last[j]);    
                    
                    last[j] = i;
                }

                while(x % j == 0){
                    x /= j;
                }
            }
            if( x > 1 ){
                if( last.find(x) != last.end() )
                    uf.Union(i, last[x]);    
                
                last[x] = i;
            }
        }
        
        return uf.maxComponent();
    }
};
