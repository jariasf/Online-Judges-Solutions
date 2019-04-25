/*******************************************
 ***Problema: Remove Outermost Parentheses
 ***ID: 1021
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int open = 0;
        stack<char> S;
        string result = "";
        string aux = "";
        bool first = true;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == '('){
                S.push(s[i]);
                if( !first ) 
                  aux += "(";
                first = false;
            }
            else{
                if( !S.empty() ){
                    S.pop();
                    if( !S.empty() )
                        aux += ")";
                }
                if( S.empty() ){
                    result += aux;
                    aux = "";
                    first = true;
                }
            }
        }
        return result;
    }
};
