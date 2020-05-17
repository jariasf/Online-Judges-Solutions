/*******************************************
 ***Problema: Find All Anagrams in a String
 ***ID: Week3.3
 ***Juez: LeetCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), total = p.size();
        vector<int> res;
        vector<int> hash(26);
        
        for( int i = 0 ; i < total; ++i ) hash[p[i] - 'a']++;
        for( int i = 0, left = 0 ; i < n ; ++i ){
            hash[ s[i] - 'a' ]--;
            total--;
            while( hash[s[i] - 'a'] < 0 ){
                total++;
                hash[ s[left++] - 'a']++;
            }
            if( total == 0 )
                res.push_back(left);
        }
        
        return res;
    }
};
