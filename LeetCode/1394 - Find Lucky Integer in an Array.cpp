/*******************************************
 ***Problem: Find Lucky Integer in an Array
 ***ID: 1394
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> hash;
        for( int i = 0 ; i < n ; ++i ){
            hash[arr[i]]++;
        }
        
        int maxi = -1;
        for( auto it:hash ){
            if( it.first == it.second ){
                maxi = max(maxi, it.first);
            }
        }
        return maxi;
    }
};
