/*******************************************
 ***Problema: Repeated Substring Pattern
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Prefix Table
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 0, j = -1; 
        int n = s.size();
        vector<int> b(n + 1, 0);
        b[ 0 ] = -1;
        while( i < n ){
            while( j >= 0 && s[ i ] != s[ j ] ) j = b[ j ];
            i++; j++;
            b[ i ] = j;
        }
        return b[n] > 0 && n % (n - b[n]) == 0;
    }
};
