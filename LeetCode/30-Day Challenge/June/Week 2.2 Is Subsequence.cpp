/*******************************************
 ***Problema: Is Subsequence
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while( i < s.size() && j < t.size() ){
            if( s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};
