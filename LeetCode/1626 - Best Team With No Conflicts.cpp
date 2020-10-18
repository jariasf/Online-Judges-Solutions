/*******************************************
 ***Problema: Best Team With No Conflicts
 ***ID: 1626
 ***Juez: LeetCode
 ***Tipo: Dynamic Programing - LIS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pii> v;
        int n = ages.size();
        for( int i = 0 ; i < n; ++i )
            v.push_back(mp(ages[i], scores[i]));
        sort(v.begin(), v.end());
        vector<int> dp(n + 1);
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            dp[i] = v[i].second;
            for( int j = 0 ; j < i ; ++j ){
                if( v[j].second <= v[i].second ){
                    dp[i] = max( dp[i], v[i].second + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
