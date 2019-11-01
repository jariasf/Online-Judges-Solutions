/*******************************************
 ***Problema: Longest Substring with At Most Two Distinct Characters
 ***ID: 928
 ***Juez: LintCode
 ***Tipo: Sliding Window - Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        unordered_map<int, int> hash;
        int n = s.size(), k = 2, result = 0, total = 0;
        for( int i = 0, left = 0 ; i < n ; ++i ){
            while( hash.size() > k ){
                hash[ s[left]]--;
                total--;
                if( hash[ s[left]] == 0 ){
                    hash.erase(s[left]);
                }
                left++;
            }
            result = max(result, total);
            total++;
            hash[ s[i]]++;
        }
        if( hash.size() <= k ) result = max(result, total);
        return result;
    }
};
