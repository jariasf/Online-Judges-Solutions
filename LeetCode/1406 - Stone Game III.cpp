/*******************************************
 ***Problem: Stone Game III
 ***ID: 1406
 ***Judge: LeetCode
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> values;
    vector<int> dp;
    int n;
    int solve(int pos){
        if( pos == n ){
            return 0;
        }
        if( dp[pos]!= -1) return dp[pos];
        
        int res = INT_MIN, sum = 0;
        for( int i = 0 ; i < 3 && pos + i < n ; ++i ){
            sum += values[pos + i];
            res = max( res, sum - solve(pos + i + 1));
        }
        return dp[pos] = res;
    }
    
    string stoneGameIII(vector<int>& _values) {
        n = _values.size();
        values = _values;
        dp = vector<int>(n + 5, -1);
        int res = solve(0);
        if( res > 0 ) return "Alice";
        else if( res < 0 ) return "Bob";
        return "Tie";
    }
};
