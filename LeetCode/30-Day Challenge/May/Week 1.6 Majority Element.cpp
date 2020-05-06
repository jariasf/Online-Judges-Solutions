/*******************************************
 ***Problema: First Unique Character in a String
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Hashing | Boyer-Moore Voting Algorithm
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, candidate = 0;
        for( auto x: nums ){
            if( cnt == 0 )
                candidate = x;
            
            cnt += (x == candidate?1:-1);
        }
        return candidate;
    }
};

// Hashing
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        int mid = nums.size()/2;
        for( auto x: nums){
            hash[x]++;
            if( hash[x] > mid ) 
                return x;
        }
        return -1;
    }
};
