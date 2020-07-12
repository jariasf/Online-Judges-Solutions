/*******************************************
 ***Problema: Subsets
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    void solve(vector<vector<int>> &res, vector<int> &nums, vector<int> current, int pos){
        if( pos == nums.size() ){
            res.push_back(current);
            return;
        }
        current.push_back(nums[pos]);
        solve(res, nums, current, pos + 1);
        current.pop_back();
        solve(res, nums, current, pos + 1);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int> current;
        solve(res, nums, current, 0 );
        return res;
    }
};
