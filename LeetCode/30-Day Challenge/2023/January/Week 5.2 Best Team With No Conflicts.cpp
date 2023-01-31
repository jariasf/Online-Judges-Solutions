/*******************************************
 ***Problema: Best Team With No Conflicts
 ***ID: Week 5.2
 ***Juez: LeetCode
 ***Tipo: Sorting + DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int> > v(n);
        for(int i = 0 ; i < n ; ++i){
            v[i] = {ages[i], scores[i]};
        }
        sort(v.begin(), v.end());
        vector<int> dp(n);
        int maxi = 0 ;
        for(int i = 0 ; i < n ; ++i){
            dp[i] = v[i][1];
            for(int j = 0 ; j < i ; ++j){
                if( v[i][1] >= v[j][1]){
                    dp[i] = max(dp[i], v[i][1] + dp[j]);
                }
            }
            if( dp[i] > maxi) maxi = dp[i];
        }
        return maxi;
    }
};
