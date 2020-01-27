/*******************************************
 ***Problema: Minimum Difficulty of a Job Schedule
 ***ID: 1335
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define INF 1<<30
    vector<int> v;
    vector<vector<int> > dp;
    int solve(int pos, int d){
        int n = v.size();
        if( pos == n ){
            if( d == 0 ){
                return 0;
            }
            return INF;
        }
        if( d < 0 ) return INF;
        
        if( dp[pos][d] != -1 ) return dp[pos][d];
        int res = INF, maxi = 0;
        for( int i = pos ; i < n ; ++i ){
            maxi = max(maxi, v[i]);
            res = min(res, maxi + solve(i + 1, d - 1));
        }
        return dp[pos][d] = res;
    }
    
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if( n < d ) return -1;
        v = job;
        dp = vector<vector<int> >(n + 5, vector<int>(d + 5, -1));
        int res = solve(0, d);
        if( res >= INF ) return -1;
        return res;
    }
};
