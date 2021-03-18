/*******************************************
 ***Problema: Longest Substring with At Least K Repeating Characters
 ***ID: 1261
 ***Juez: LintCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: return an integer
     */
    int longestWithNUniqueCharacters(string &s, int n, int k){
        vector<int> hash(26);
        int unique = 0, greater_than_k = 0, longest = 0;
        for( int right = 0, left = 0; right < s.size(); ++right ){
            hash[s[right] - 'a']++;
            if( hash[s[right] - 'a'] == 1) unique++;
            if( hash[s[right] - 'a'] == k) greater_than_k++;

            while( unique > n ){
                hash[s[left] - 'a']--;
                if( hash[s[left] - 'a'] == 0 ) unique--;
                if( hash[s[left] - 'a'] == k - 1 ) greater_than_k--;
                left++;
            }
            if( unique == n && greater_than_k == unique ){
                longest = max(longest, right - left + 1);
            }
        }
        return longest;
    }

    int longestSubstring(string &s, int k) {
        int maximum = 0;
        for( int i = 1 ; i <= 26 ; ++i ){
            maximum = max(maximum, longestWithNUniqueCharacters(s, i, k));
        }
        return maximum;
    }
};
