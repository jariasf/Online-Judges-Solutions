/*******************************************
 ***Problema: Reverse String
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for( int i = 0 ; i < n/2 ; ++i )
            swap(s[i], s[n - 1 - i]);
    }
};
