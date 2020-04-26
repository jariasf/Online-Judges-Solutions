/*******************************************
 ***Problem: Diagonal Traverse II
 ***ID: 1424
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int h = nums.size();
        unordered_map<int, vector<int> > hash;
        int max_w = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < nums[i].size() ; ++j){
                hash[i + j].push_back( nums[i][j]);
            }
            max_w = max(max_w, i + (int)nums[i].size());
        }
        
        vector<int> v;
        for( int i = 0 ; i < max_w ; ++i ){
            vector<int> tmp = hash[i];
            for( int j = tmp.size() - 1 ; j >= 0 ; --j ){
                v.push_back(tmp[j]);
            }
        }
        return v;
    }
};
