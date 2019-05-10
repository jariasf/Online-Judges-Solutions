/*******************************************
 ***Problema: Number of Squareful Arrays
 ***ID: 996
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    unordered_set<int> hash;
    
    void gen(){
        hash.clear();
        for( LL i = 0 ; i * i <= 2000000000LL ; ++i){
            hash.insert(i * i);
        }
    }
    
    int bitcount( int n ){
        int cnt = 0;
        while( n ){
            n = n & ( n - 1 );
            cnt++;
        }
        return cnt;
    }
    
    vector<vector<int> > dp;
    vector<int> v;
    int solve(int mask, int pos){
        int n = v.size();
        if( bitcount(mask) == n ) return 1;
        
        if( dp[mask][pos] != -1 ) return dp[mask][pos];
        
        int result = 0;
        int last = -1;
        for( int i = 0 ; i < n; ++i ){
            if( !(mask & (1<<i) )  && hash.find(v[pos] + v[i]) != hash.end() && (last == -1 || v[i] != v[last]) ){
                result += solve( mask | (1<<i), i);
                last = i;
            }
        }
        
        return dp[mask][pos] = result;
        
    }
 
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int result = 0;
        int n = A.size();
        v = A;
        dp = vector<vector<int> >(1<<n + 5, vector<int>(n + 5, -1) );
        gen();
        for( int i = 0 ; i < n; ++i ){
            if( i > 0 ){
                if( A[i] != A[i - 1])
                    result += solve(1<<i , i);
            }else{
                result += solve(1<<i, i);
            }
        }
        return result;
    }
};
