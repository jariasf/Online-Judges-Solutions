/*******************************************
 ***Problema: Maximum Nesting Depth of the Parentheses
 ***ID: 1614
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxDepth(string s) {
        int res = 0, open = 0;
        for( int i = 0 ; i < s.size(); ++i ){
            res = max(open ,res);
            if( s[i] == '(') 
				open++;
            else if(s[i] == ')')
                open--;
        }
        return res;
    }
};
