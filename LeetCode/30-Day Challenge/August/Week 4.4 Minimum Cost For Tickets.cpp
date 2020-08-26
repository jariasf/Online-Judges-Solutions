/*******************************************
 ***Problema: Minimum Cost For Tickets
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> days, costs, dp;
    int solve(int day, int last){
        if( day > last )
            return 0;
        if( dp[day] != -1 ) return dp[day];
        int res = INT_MAX;
        if( days[day] != 0 ){
            res = costs[0] + solve(day + 1, last);
            res = min(res, min(costs[1] + solve(day + 7, last), costs[2] + solve(day + 30, last)));
        }else
            res = min(res, solve(day + 1, last));
        
        return dp[day] = res;
    }
    
    int mincostTickets(vector<int>& _days, vector<int>& _costs) {
        costs = _costs;
        days = vector<int>(366);
        dp = vector<int>(366, -1);
        for( int i = 0 ; i < _days.size(); ++i )
            days[_days[i]] = 1;
        return solve(_days[0], _days[_days.size() - 1]);
    }
};
