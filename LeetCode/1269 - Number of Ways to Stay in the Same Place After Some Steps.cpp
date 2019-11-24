/*******************************************
 ***Problema: Number of Ways to Stay in the Same Place After Some Steps 
 ***ID: 1269
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    LL MOD = 1e9 + 7;
    #define MAX 502
    LL dp[MAX][MAX];
    int L;
    LL solve(int pos, int steps){
        
        if( steps == 0 ){
            return pos == 0;
        }
        
        if( dp[pos][steps] != -1 ) return dp[pos][steps] % MOD;
        
        LL res = 0;
        if( pos + 1 < L ){
            res += solve( pos + 1, steps - 1 );
            res %= MOD;
        }
        if( pos - 1 >= 0 ){
            res += solve( pos - 1, steps - 1 );
            res %= MOD;
        }
        
        res += solve( pos, steps - 1 );
        res %= MOD;
        
        return dp[pos][steps] = res;
        
    }
    
    
    int numWays(int steps, int arrLen) {
        L = arrLen;
        memset(dp, -1, sizeof(dp));
        return solve(0, steps);
    }
};
