/*******************************************
 ***Problem: Minimum Value to Get Positive Step by Step Sum
 ***ID: 1413
 ***Judge: LeetCode
 ***Type: Greedy
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Greedy
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int start = 0, sum = 0;
        for( int i = 0; i < n; ++i ){
            sum += nums[i];
            if( sum <= 0 ){
                start += -sum + 1;
                sum = 1;
            }
        }
        return max(start, 1);
    }
};


// Brute Force
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        for( int i = 1 ; ; ++i ){
            int x = i, j = 0;
            for(; j < n ; ++j ){
                if( x + nums[j] < 1 ) break;
                x += nums[j];
            }
            if( j == n ) return i;
        }
    }
};
