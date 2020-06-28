/*******************************************
 ***Problema: Check If Array Pairs Are Divisible by k
 ***ID: 1497
 ***Juez: LeetCode
 ***Tipo: Hashing + Remainder
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> hash;
        for( int i = 0 ; i < n ; ++i ){
            hash[ (arr[i] % k + k ) % k ]++;
        }
        
        for( auto it:hash ){
            if( it.first == 0 ){
                if( it.second & 1 ) return false;
            }else
                if( hash[ k - it.first ]!=it.second) return false;
        }
        return true;
    }
};
