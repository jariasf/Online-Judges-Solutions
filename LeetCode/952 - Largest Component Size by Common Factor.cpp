/****************************************************
 ***Problema: Largest Component Size by Common Factor
 ***ID: 952
 ***Juez: LeetCode
 ***Tipo: Union Find
 ***Autor: Jhosimar George Arias Figueroa
 ***************************************************/

class Solution {
public:
    #define MAX 200005
    #define AUX 100000
    int uf[ MAX ];
    int Find( int x ){
        return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
    }
    void Union( int x , int y ){
        uf[ Find( x ) ] = Find( y );
    }
    
    void makeSet(int V){
        for( int i = 0 ; i <= V;  ++i ) uf[i] = i;
    }
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        makeSet(MAX - 1);
        
        for( int i = 0 ; i < n ; ++i ){
            int x = A[i];
            for( int j = 2 ; j * j <= x ; ++j ){
                if( x % j == 0 ){
                    Union(j, i+AUX);
                    while( x % j == 0 ){
                        x /= j;
                    }
                }
            }
            if( x > 1){
                Union(x,i+ AUX);
            }
        }
        
        int maxi = 0;
        unordered_map<int, int> hash;
        for( int i = 0 ; i < n ; ++i ){
            hash[Find(i + AUX)]++;
        }
        
        for( auto it : hash ){
            maxi = max( maxi, it.second);
        }
        return maxi;
    }
};
