/*******************************************
 ***Problema: Two City Scheduling
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Greedy | Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Greedy
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), total = 0;
        vector<int> v(n);
        for( int i = 0 ; i < n ; ++i ){
            total += costs[i][0];
            v[i] = costs[i][1] - costs[i][0];
        }
        sort(v.begin(), v.end());
        n /= 2;
        for( int i = 0 ; i < n ; ++i ) 
            total += v[i];
        return total;
    }
};

// Dynamic Programming
class Solution {
public:
    vector<vector<int> > v;
    vector<vector<int> > dp;
    int solve(int pos, int cnt){
        int n = v.size();
        if( cnt * 2 > n ) return 1<<30;
        if( pos == n ){
            if( cnt * 2 == n ){
                return 0;         
            }
            return 1<<30;
        }

        if( dp[pos][cnt] != -1 ) return dp[pos][cnt];
        
        return dp[pos][cnt] = min( v[pos][0] + solve(pos + 1, cnt + 1) , v[pos][1] + solve(pos + 1, cnt));
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        v = costs;
        dp = vector<vector<int> >(v.size() + 5, vector<int>(v.size()/2 + 5, -1)); 
        return solve(0, 0);
    }
};
