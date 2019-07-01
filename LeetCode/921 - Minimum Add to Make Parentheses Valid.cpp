/*******************************************
 ***Problema: Minimum Add to Make Parentheses Valid
 ***ID: 921
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int result = 0;
        stack<char> S;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == '('){
                S.push(s[i]);
            }else{
                if( S.empty() ){
                    result++;
                }else{
                    S.pop();
                }
            }
        }
        result += S.size();
        return result;
    }
};
