/*******************************************
 ***Problema: Divide Array in Sets of K Consecutive Numbers
 ***ID: 1296
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if( n % k != 0 ) return false;
        sort( nums.begin(), nums.end() );
        unordered_map<int,int> hash;
        for( int i = 0 ; i < n ; ++i )
            hash[nums[i]]++;
        
        for( int i = 0 ; i < n ; ++i ){
            if( hash[nums[i]] == 0 ) continue;
            int cur = nums[i], j = 0;
            for( ; j < k ; ++j ){
                if( hash[cur] == 0 ) break;
                hash[cur]--;
                cur++;
            }
            if( j != k ) return false;
        }
        return true;
    }
};
