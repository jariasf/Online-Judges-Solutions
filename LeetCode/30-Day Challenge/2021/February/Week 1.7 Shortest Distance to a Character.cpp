/*******************************************
 ***Problema: Shortest Distance to a Character
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), pos = -n;
        vector<int> res(n);        
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == c )
                pos = i;
            res[i] = i - pos;
        }
        for( int i = n - 1 ; i >= 0 ; --i ){
            if( s[i] == c )
                pos = i;
            res[i] = min(res[i], abs(pos - i));
        }
        return res;
    }
};
