/*******************************************
 ***Problema: Two City Scheduling
 ***ID: 1029
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int n;
    vector<vector<int> > v;
    unordered_map<int, int> dp[101];
    int solve(int pos, int nA){
        if(nA*2 > n ) return 1<<30;
        if(pos == n){
            if( nA == 0 ) return 0;
            return 1<<30;
        }

        if( dp[pos].find(nA) != dp[pos].end() ) return dp[pos][nA];
        int res = 0;
        res = min( v[pos][0] + solve(pos + 1, nA + 1), v[pos][1] + solve(pos + 1, nA - 1) );
        return dp[pos][nA] = res;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size();
        v = costs;
        for( int i = 0 ; i <= n;  ++i ){
            dp[i].clear();
        }
        return solve(0, 0);
    }
};
