/*******************************************
 ***Problema: Reverse Substrings Between Each Pair of Parentheses
 ***ID: 1190
 ***Juez: LeetCode
 ***Tipo: Simulation + Stack | Recursion
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> S;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == '(') S.push(i);
            else if(s[i] == ')'){
                reverse(s.begin() + S.top(), s.begin() + i + 1);
                S.pop();
            }
        }
        string res = "";
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] >= 'a' && s[i] <= 'z') res += s[i];
        }
        return res;
    }
};
