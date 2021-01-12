/*******************************************
 ***Problema: Longest Substring Without Repeating Characters
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen;
        int maxi = 0;
        for( int i = 0 ; i < s.length() ; ++i ){
            int sz = 0;
            seen = vector<bool>(256,0);
            for( int j = i ; j < s.length(); ++j ){
                if( seen[s[j]] ) break;
                sz++;
                if( sz > maxi ){
                    maxi = sz;
                }
                seen[ s[j] ] = 1;
            }
        }
        return maxi;
    }
};
