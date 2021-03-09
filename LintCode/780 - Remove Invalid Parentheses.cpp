/*******************************************
 ***Problema: Remove Invalid Parentheses
 ***ID: 780
 ***Juez: LintCode
 ***Tipo: Recursion
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    pair<int, int> minimumInvalidParenthesis(string &s){
        int left = 0, right = 0;
        for(char c: s ){
            if( c == '(') left++;
            else if( c == ')' ){
                if( left > 0 ) left--;
                else right++;
            }
        }
        return make_pair(left, right);
    }

    void generate(vector<string> &result, string current, int open, int left, int right, int pos, string &s){    
        if( pos == s.size() ){
            if( open == 0 && left == 0 && right == 0 )
                result.push_back(current);
            return;
        }

        if( s[pos] == '('){
            if( pos == 0 || s[pos] != s[pos - 1] ){ //avoid duplicates
                int i = pos, cnt = 0;
                while( i < s.size() && s[pos] == s[i] && left - cnt >= 0 && pos + cnt <= s.size() ){
                    cnt++;
                    i++;
                    generate(result, current, open, left - cnt, right, pos + cnt, s);
                }
            }
            
            generate(result, current + "(", open + 1, left, right, pos + 1, s);
        }else if( s[pos] == ')'){

            if( pos == 0 || s[pos] != s[pos - 1] ){ //avoid duplicates
                int i = pos, cnt = 0;
                while( i < s.size() && s[pos] == s[i] && right - cnt >= 0 && pos + cnt <= s.size() ){
                    cnt++;
                    i++;
                    generate(result, current, open, left, right - cnt, pos + cnt, s);
                }
            }

            if( open > 0 )
                generate(result, current + ")", open - 1, left, right, pos + 1 , s);          
        }else
            generate(result, current + s[pos], open, left, right, pos + 1, s);
    }

    vector<string> removeInvalidParentheses(string &s) {
        pair<int, int> invalid = minimumInvalidParenthesis(s);
        vector<string> result;
        generate(result, "", 0, invalid.first, invalid.second, 0, s);
        return result;
    }
};
