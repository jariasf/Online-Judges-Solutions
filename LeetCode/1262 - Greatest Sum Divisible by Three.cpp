/*******************************************
 ***Problema: Greatest Sum Divisible by Three
 ***ID: 1262
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 100005
    typedef long long LL;
    LL dp[MAX][4];
    vector<int> v;
    LL solve(int pos, int div){
        if( pos == v.size() ){
            if( div % 3 == 0 ) return 0;
            return -(1LL<<50);
        }
        if( dp[pos][div] != -1 ) return dp[pos][div];
        dp[pos][div] = max( solve(pos + 1, div), v[pos] + solve(pos + 1, (div + v[pos]) % 3 ));
        return dp[pos][div];
    }
    
    int maxSumDivThree(vector<int>& nums) {
        v = nums;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};
