/*******************************************
 ***Problema: Largest Substring Between Two Equal Characters
 ***ID: 1624
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), res = -1;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                if( s[i] == s[j] ){
                    res = max(res, j - i - 1);
                }
            }
        }
        return res;
    }
};
