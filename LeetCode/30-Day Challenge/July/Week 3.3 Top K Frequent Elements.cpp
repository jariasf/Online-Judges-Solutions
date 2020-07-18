/*******************************************
 ***Problema: Top K Frequent Elements
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Hashing | Partial Sort
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        vector<vector<int> > v(n + 1);
        for( int i = 0 ; i < n ; ++i )
            hash[ nums[i] ]++;
        
        int sz = 0;
        for( auto it: hash ){
            sz = max(sz, it.second);
            v[it.second].push_back(it.first);
        }
        
        vector<int> res(k);
        for( int i = 0, j = 0 ; i < k ; ++i ){
            while( j == v[sz].size() ){
                sz--;
                j = 0;
            }
            res[i] = v[sz][j++];
        }
        return res;
    }
};
