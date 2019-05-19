/*******************************************
 ***Problema: Remove All Adjacent Duplicates In String
 ***ID: 1047
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> S;
        for( int i = 0 ; i < n ; ++i ){
            char cur = s[i];
            if( !S.empty()  ){
                char top = S.top();
                if( top == cur ){
                    S.pop();
                }else
                    S.push(cur);
            }else
                S.push(cur);
        }

        string res = "";
        while( !S.empty() ){
            res += S.top(); S.pop();
        }
        reverse(res.begin(), res.end() );
        return res;

    }
};
