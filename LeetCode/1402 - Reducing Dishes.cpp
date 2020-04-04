/*******************************************
 ***Problem: Reducing Dishes
 ***ID: 1402
 ***Judge: LeetCode
 ***Type: Greedy | DP
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Greedy
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int res = 0, sum = 0, suffix = 0;
        for( int i = n - 1 ; i >= 0 ; --i ){
            sum += satisfaction[i];
            suffix += sum;
            res = max(res, suffix);
        }
        return res;
    }
};

// DP
class Solution {
public:
    int n;
    vector<int> v;
    vector<vector<int> > dp;
    int solve(int pos, int t){
        if( pos == n )
            return 0;
        if( dp[pos][t] != -1 ) return dp[pos][t];
        return dp[pos][t] = max( solve(pos + 1, t), v[pos] * t + solve(pos + 1, t + 1));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        v = satisfaction;
        dp = vector<vector<int> >(n + 1, vector<int>(n + 1, -1));
        return solve(0, 1);
    }
};
