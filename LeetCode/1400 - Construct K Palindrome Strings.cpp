/*******************************************
 ***Problem: Construct K Palindrome Strings
 ***ID: 1400
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n) return false;
        if(k == n) return true;
        vector<int> hash(27);
        
        for( int i = 0 ; i < n ; ++i ) hash[ s[i] - 'a']++;
        
        int odd, even;
        odd = even = 0;
        for( int i = 0 ; i < 26 ; ++i ){
            if( hash[i] > 0 ){
                if( hash[i] & 1 ) odd++;
                else even++;
            }
        }
        
        if( odd > k ) return false;
        return true;
    }
};
