/*******************************************
 ***Problema: Excel Sheet Column Number
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(char c:s )
            res = res * 26 + (c - 'A' + 1);
        return res;
    }
};
