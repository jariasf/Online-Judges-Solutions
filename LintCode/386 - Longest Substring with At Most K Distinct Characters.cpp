/*******************************************
 ***Problema: Longest Substring with At Most K Distinct Characters
 ***ID: 386
 ***Juez: LintCode
 ***Tipo: Sliding Window - Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        unordered_map<int, int> hash;
        int n = s.size(), result = 0, total = 0;
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
