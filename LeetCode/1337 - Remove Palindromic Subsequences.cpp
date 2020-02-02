/*******************************************
 ***Problema: Remove Palindromic Subsequences
 ***ID: 1332
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int removePalindromeSub(string s) {
        if( s.size() == 0 ) return 0;
        string T = s;
        reverse(T.begin(), T.end());
        if( T == s ) return 1;
        return 2;
    }
};
