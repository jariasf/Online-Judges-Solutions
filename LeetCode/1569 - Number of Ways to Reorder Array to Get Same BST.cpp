/*******************************************
 ***Problema: Number of Ways to Reorder Array to Get Same BST
 ***ID: 1569
 ***Juez: LeetCode
 ***Tipo: Recursion + Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 1005
    typedef long long LL;
    int MOD = 1e9+7;
    LL dp[ MAX ][ MAX ];
    void binomial( long N , long K ){
        for (int k = 1; k <= K; ++k) dp[ 0 ][ k ] = 0;
        for (int n = 0; n <= N; ++n) dp[ n ][ 0 ] = 1;
        for ( int n = 1; n <= N; ++n ){
           for ( int k = 1; k <= K; ++k ){
              dp[ n ][ k ] = (dp[ n - 1 ][ k - 1 ] + dp[ n - 1 ][ k ]) % MOD;
           }
        }
    }    
    
    LL solve(vector<int> &tree){
        int n = tree.size();
        if( n <= 2 ) return 1;
        vector<int> left, right;
        for( int i = 1; i < n ; ++i ){
            if( tree[i] < tree[0] ){
                left.push_back(tree[i]);
            }else
                right.push_back(tree[i]);
        }
        return solve(left) * solve(right) % MOD * dp[n - 1][left.size()] % MOD;
    }
    
    int numOfWays(vector<int>& nums) {
        binomial( nums.size(), nums.size() );
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
