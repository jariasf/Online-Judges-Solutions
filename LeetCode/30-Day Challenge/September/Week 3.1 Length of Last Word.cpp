/*******************************************
 ***Problema: Length of Last Word
 ***ID: Week3.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        while( n > 0 && s[n - 1] == ' ') n--;
        int res = n;
        while( res > 0 && s[res - 1] != ' ' ) res--;
        return n - res;
    }
};
