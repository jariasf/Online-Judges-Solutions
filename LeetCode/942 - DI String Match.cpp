/*******************************************
 ***Problema: DI String Match
 ***ID: 942
 ***Juez: LeetCode
 ***Tipo: Ad hoc, Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        stack<int> S;
        vector<int> res(n + 1);
        int j = 0;
        for( int i = 0 ; i < n ; ++i ){
            S.push(i);
            if( s[i] == 'I' ){
                while( !S.empty() ){
                    res[j++] = S.top();
                    S.pop();
                }
            }
        }
        S.push(n);
        while( !S.empty() ){
            res[j++] = S.top();
            S.pop();
        }
        return res;
    }
};
