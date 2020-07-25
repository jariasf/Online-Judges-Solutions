/*******************************************
 ***Problema: Single Number III
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Bitmasks | Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// O(1) memory
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        for( int i = 1 ; i < n ; ++i ) x ^= nums[i];
        
        int last_bit = x & -x;
        int a = x, b;
        for( int i = 0 ; i < n ; ++i )
            if( nums[i] & last_bit )
                a ^= nums[i];
        
        b = x ^ a;
        return {a, b};
    }
};


// O(n) memory
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> hash;
        for( int i = 0 ; i < n ; ++i ){
            if( hash.find( nums[i] ) != hash.end() )
                hash.erase(nums[i]);
            else
                hash.insert(nums[i]);
        }
        
        vector<int> res;
        for( auto it: hash )
            res.push_back(it);
        
        return res;
    }
};
