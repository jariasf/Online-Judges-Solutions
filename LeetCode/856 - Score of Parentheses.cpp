/*******************************************
 ***Problema: Score of Parentheses
 ***ID: 856
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    int scoreOfParentheses(string s) {
        int result = 0;
        vector<int> S;
        for( int i = 0 ; i < s.size() ; ++i ){
            if( s[i] == '('){
                S.push_back(0);
            }else{
                if( S.size() > 0 ){
                    int cur = S[S.size() - 1];
                    S.pop_back();
                    int value = 2 * cur;
                    if( cur == 0 )
                        value = 1;
                    
                    if( S.size() > 0 ){
                        S[ S.size() - 1 ] += value;
                    }else if( S.size() == 0 ) result += value;
                }
            }
        }
        return result;
    }
};
