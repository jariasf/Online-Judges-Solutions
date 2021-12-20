/*******************************************
 ***Problema: Minimum Operations to Make the Array K-Increasing
 ***ID: 2111
 ***Juez: LeetCode
 ***Tipo: DP - LIS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int LIS(vector<int>& nums) {
		vector<int> res;
		for(int i = 0; i < nums.size(); ++i){
		    auto it = std::upper_bound(res.begin(), res.end(), nums[i]);
		    if( it == res.end() ) res.push_back(nums[i]);
		    else
                *it = nums[i];
		}
		return res.size();
	}    
    
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int res = 0;
        vector<bool> visited(n, false);
        for( int i = 0 ; i < n ; ++i ){
            if( visited[i]) continue;
            vector<int> nums;
            int j = i;
            while(j < n){
                visited[j] = true;
                nums.push_back(arr[j]);
                j += k;
            }
            res += nums.size() - LIS(nums);
        }
        return res;
    }
};
