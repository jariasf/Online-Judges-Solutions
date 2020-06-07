/*******************************************
 ***Problema: Paint House III
 ***ID: 1473
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define INF 1<<30
    vector<vector<int> > C;
    vector<int> v;
    int n , m;
    vector<vector<vector<int> > >dp;
    int solve(int pos, int last_color, int target){
        if( target < 0 ) return INF;
        if( pos == m ){
            if( target == 0 )
                return 0;
            return INF;
        }
        
        if( dp[pos][last_color][target] != -1 ) 
            return dp[pos][last_color][target];
        
        int res = INF;
        if( v[pos] == 0 ){
            for( int i = 1 ; i <= n ; ++i )
                res = min( res, C[pos][i - 1] + solve(pos + 1, i, target - (i != last_color)));
        }else
            res = min( res, solve(pos + 1, v[pos], target - (v[pos] != last_color)));

        return dp[pos][last_color][target] = res;
    }
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int _m, int _n, int target) {
        C = cost;
        v = houses;
        n = _n; m = _m;
        dp = vector<vector<vector<int> > >(m + 5, vector<vector<int> >(n + 5, vector<int>(target + 5, -1)) );
        int res = solve(0, 0, target);
        if( res >= INF ) return -1;
        return res;
    }
};
