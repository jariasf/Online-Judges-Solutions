/*******************************************
 ***Problema: Maximum Nesting Depth of Two Valid Parentheses Strings
 ***ID: 1111
 ***Juez: LeetCode
 ***Tipo: Parenthesis Count - Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        int cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( seq[i] == '('){
                cnt++;
                res[i] = cnt % 2;
            }else{
                res[i] = cnt % 2;
                cnt--;
            }     
        }
        return res;
    }
};
