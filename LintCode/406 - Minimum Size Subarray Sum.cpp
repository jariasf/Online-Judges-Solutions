/*******************************************
 ***Problema: Minimum Size Subarray Sum
 ***ID: 406
 ***Juez: LintCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    //O(n) 
    int minimumSize(vector<int> &nums, int s) {
        int n = nums.size();
        int sum = 0;
        int left = 0, minimum = 1<<30;
        for(int right= 0 ; right < n ; ++right ){
            sum += nums[right];
            while( sum >= s ){
                minimum = min( minimum, right - left + 1 );
                sum -= nums[left];    
                left++;
            }
        }
        if( minimum == 1<<30 ) return -1;
        return minimum;
    }

    //O(nlogn)
    int minimumSize(vector<int> &nums, int s) {
        int n = nums.size();
        vector<int> sums(n + 1);
        for( int i = 1 ; i <= n ; ++i )
            sums[i] = sums[i - 1] + nums[i - 1];

        int minimum = INT_MAX;
        for( int i = 1 ; i <= n ; ++i ){
            int lookfor = sums[i] - s;
            int up = upper_bound(sums.begin(), sums.end(), lookfor) - sums.begin();
            if( up - 1 >= 0 && up <= n ){
                minimum = min(minimum, i - up + 1 );
            }
        }
        if( minimum == INT_MAX ) return -1;
        return minimum;
    }              
};
