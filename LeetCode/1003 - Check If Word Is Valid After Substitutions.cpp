/*******************************************************
 ***Problema: Check If Word Is Valid After Substitutions
 ***ID: 1003
 ***Juez: LeetCode
 ***Tipo: Data Structures, Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************************/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> S;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == 'c' ){
                if( S.empty() || S.size() < 2 ) return false;
                char b = S.top(); S.pop();
                char a = S.top(); S.pop();
                if( b != 'b' || a != 'a' ) return false;
            }else{
                S.push(s[i]);
            }
        }
        return S.empty();
    }
};
