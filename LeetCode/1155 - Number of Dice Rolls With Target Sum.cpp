/*******************************************
 ***Problema: Number of Dice Rolls With Target Sum
 ***ID: 1155
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MOD 1000000007
    typedef long long LL;
    int D, F, T;
    LL dp[31][1005];
    LL solve(int d, int t){
        if( t > T ) return 0;
        if( d == D ){
            if( t == T ) return 1;
            return 0;
        }
        if( dp[d][t] != -1 ) return dp[d][t];
        LL res = 0;
        for( int i = 1 ; i <= F; ++i ){
            res = (res + solve(d + 1, t + i)) % MOD;
        }
        return dp[d][t] = res;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        D = d;
        F = f;
        T = target;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};
