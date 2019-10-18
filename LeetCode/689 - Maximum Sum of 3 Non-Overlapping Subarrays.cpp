/*******************************************************
 ***Problema: Maximum Sum of 3 Non-Overlapping Subarrays
 ***ID: 689
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************************/

// Solution can generalize to N subarrays
class Solution {
public:
    #define MAX_N 3
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int sz = nums.size();
        vector<vector<int> > dp(sz + 5, vector<int>(MAX_N + 1, 0));
        vector<int> prefix_sums(sz + 5);
        
        for( int i = 0 ; i < sz; ++i ){
            prefix_sums[i + 1] = prefix_sums[i] + nums[i];
        }
        
        vector<vector<pair<int, int> > > prev(sz + 5, vector<pair<int,int> >(MAX_N + 2, make_pair(-1, -1)));
        int init = 1;
        for( int j = 1 ; j <= MAX_N ; ++j ){
            for( int i = init; i + k - 1 <= sz; ++i ){
                int current_sum = prefix_sums[i + k - 1] - prefix_sums[i - 1];
                if( i - k > 0 ){
                    dp[i][j] = dp[i - k][j - 1] + current_sum;
                    prev[i][j] = make_pair(i - k, j - 1);
                }else{
                    dp[i][j] = current_sum;
                }
                  
                if( dp[i][j] <= dp[i - 1][j] ){
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j] = make_pair(i - 1, j);
                }
            }     
            init += k;
        }

        vector<int> result;
        int start = sz - k + 1, id = MAX_N;
        while(start > 0 && id > 0){
            int i = prev[start][id].first, j = prev[start][id].second;
            if( j != id ){
                result.push_back(start - 1);
            }
            start = i; id = j;
        }
        
        reverse( result.begin(), result.end() );
        return result;
    }
};
