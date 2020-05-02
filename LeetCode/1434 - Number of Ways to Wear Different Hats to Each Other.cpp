/*******************************************
 ***Problem: Number of Ways to Wear Different Hats to Each Other
 ***ID: 1434
 ***Judge: LeetCode
 ***Type: DP + Bitmasks
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

//O(n*40*2^n)
class Solution {
public:
    typedef int LL;
    int MOD = 1e9+7;
    vector<vector<int> > v;
    vector<vector<LL> > dp;
    int n;
    
    LL solve(int mask, int last){
        if( last == 40 )
            return mask == ((1 << n) - 1);
        
        if( dp[mask][last] != -1 ) return dp[mask][last];
        LL res = solve( mask, last + 1) % MOD;
        for( int i = 0 ; i < v[last].size(); ++i ){
            if( !(mask & (1<<v[last][i])) ){
                res = res + solve( mask | (1<<v[last][i]), last + 1 );
            }
            res %= MOD;
        }
        return dp[mask][last] = res;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        v = vector<vector<int> >(45);
        for( int i = 0 ; i < n; ++i ){
            for( int j = 0 ; j < hats[i].size(); ++j ){
                v[hats[i][j] - 1].push_back(i);
            }
        }        
        dp = vector<vector<LL> > (1<<n + 1, vector<LL>(50, -1));
        return solve(0, 0);
    }
};


//O(n*40*40*2^n)
class Solution {
public:
    typedef long long LL;
    int MOD = 1e9+7;
    vector<vector<int> > v;
    int n;
    
    int bitcount(int n){
        int ones = 0;
        while(n > 0){
            ones++;
            n = n & (n - 1);
        }
        return ones;
    }
    
    vector<vector<LL> > dp;
    LL solve(int mask, int last){
        
        if( bitcount(mask) == n ){
            return 1;
        }
        if( dp[mask][last] != -1 ) return dp[mask][last];
        
        LL res = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( !(mask & (1<<i)) ){
                for( int j = 0 ; j < v[i].size(); ++j ){
                    if( last < v[i][j] ){
                        res = res + solve(mask | (1<<i), v[i][j] ) % MOD;
                        res %= MOD;
                    }
                }
            }
        }
        return dp[mask][last] = res;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        v = hats;
        dp = vector<vector<LL> > (1<<(n + 1), vector<LL>(50, -1));
        return solve(0, 0);
    }
};
