/*******************************************
 ***Problema: Find K-th Smallest Pair Distance
 ***ID: 719
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countSmaller(vector<int> &nums, int tot){
        int total = 0;
        for( int i = 0, j = 0 ; i < nums.size(); ++i ){
            while( nums[i] - nums[j] > tot ){
                j++;
            }
            total += i - j;
        }
        return total;
    } 
     
    int smallestDistancePair(vector<int> &nums, int k) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n - 1] - nums[0] + 1;
        while(left < right ){
            int mid = (left + right)/2;
            int cnt = countSmaller(nums, mid);
            if( cnt < k ){
                left = mid + 1;
            }else
                right = mid;
        }
        
        return left;
    }
};
