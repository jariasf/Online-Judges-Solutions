/*******************************************
 ***Problema: Minimum Cost to Cut a Stick
 ***ID: 1547
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define INF 1<<30
#define MAX 105
int dp[MAX][MAX];

class Solution {
public:
    vector<int> v;
    int solve(int left, int right){
        if( right - left == 2 ) return 0;
        if( dp[left][right] != -1 ) return dp[left][right];   
        int res = INF;
        for( int i = left + 1; i < right - 1 ; ++i ){
            res = min( res, v[right - 1] - v[left] + solve(left, i + 1) + solve(i, right) );
        }
        return dp[left][right] = res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        v = cuts;
        memset(dp, -1, sizeof(dp));
        return solve(0, cuts.size());
    }
};
