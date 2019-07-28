/*******************************************
 ***Problema: Stone Game II
 ***ID: 1140
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming, Max-Min
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define INF 1<<30
    vector<int> v;
    int dp[105][105][2];
    int solve(int pos, int M, bool alex){
        if( pos == v.size() )
            return 0;
        if( dp[pos][M][alex] != -1 ) return dp[pos][M][alex];
        int result = (alex?0:INF);
        int sum = 0;
        int _M = 0;
        for( int i = pos, j = 1 ; i < v.size() && j <= 2 * M ; ++i, ++j ){
            sum += v[i];
            _M = max(M, j);
            if( alex ){
                result = max( result, sum + solve( i + 1, _M, !alex));
            }else{
                result = min( result, solve( i + 1, _M, !alex));
            }
        }
        return dp[pos][M][alex] = result;
    }
    
    int stoneGameII(vector<int>& piles) {
        v = piles;
        memset(dp, -1, sizeof(dp));
        return solve(0,1,true);
    }
};
