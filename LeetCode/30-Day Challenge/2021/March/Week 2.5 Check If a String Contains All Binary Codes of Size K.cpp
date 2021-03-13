/*******************************************
 ***Problema: Check If a String Contains All Binary Codes of Size K
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Bitmasks + hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if( k > n ) return false;
        int val = 0;
        for( int i = 0, j = k - 1 ; i < k ; ++i, --j ){
            if( s[i] == '1')
                val |= 1<<j;
        }
        
        vector<int> seen(1<<k);
        seen[val] = 1;
        for( int i = k ; i < n ; ++i ){
            val = val << 1;
            if( val & (1<<k ) ){
                val = val ^ ( 1<<k);
            }
            if( s[i] == '1'){
                val |= 1;
            }
            seen[val] = 1;
        }

        for( int val: seen){
            if( val == 0 ) return false;
        }
        return true;
    }
};
