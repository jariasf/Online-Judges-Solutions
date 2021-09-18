/*******************************************
 ***Problema: Maximum Earnings From Taxi
 ***ID: 2008
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 100005
typedef long long LL;
LL dp[MAX];
class Solution {
public:
    vector<vector<int> > v;
    LL solve(int pos){
        int n = v.size();
        if( pos == n )
            return 0;
        if(dp[pos] != -1) return dp[pos];
        LL res = solve(pos + 1);
        int left = pos + 1, right = n;
        while( left < right ){
            int mid = (left + right)/2;
            if( v[mid][0] < v[pos][1]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        res = max(res, v[pos][1] - v[pos][0] + v[pos][2] + solve(right));
        return dp[pos] = res;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        v = rides;
        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};
