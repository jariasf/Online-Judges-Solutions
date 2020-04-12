/*******************************************
 ***Problem: Number of Ways to Paint N × 3 Grid
 ***ID: 1411
 ***Judge: LeetCode
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int MOD = 1e9 + 7;
    int N;
    vector<vector<vector<vector<int> > > > dp;
    LL solve(int pos, int a, int b, int c){
        if( pos == N ){
            return 1;
        }
        if( pos > 0 && dp[pos][a][b][c] != -1 ) return dp[pos][a][b][c];
        LL res = 0;
        for( int i = 0 ; i < 3 ; ++i ){
            if( i == a ) continue;
            for( int j = 0 ; j < 3 ; ++j ){
                if( j == b || j == i ) continue;
                for( int k = 0 ; k < 3 ; ++k ){
                    if( k == c || k == j ) continue;
                    res = (res% MOD + solve(pos + 1, i, j, k) % MOD) % MOD;
                }
            }
        }
        if( pos > 0 ) dp[pos][a][b][c] = res;
        return res;
    }
    
    int numOfWays(int n) {
        N = n;
        dp = vector<vector<vector<vector<int> > > > (N + 1, vector<vector<vector<int> > >(3, vector<vector<int> >(3, vector<int>(3, -1))) );
        return solve(0, -1, -1, -1) % MOD;
    }
};
