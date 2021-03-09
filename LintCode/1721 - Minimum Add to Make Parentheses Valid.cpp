/*******************************************
 ***Problema: Minimum Add to Make Parentheses Valid
 ***ID: 1721
 ***Juez: LintCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param S: the given string
     * @return: the minimum number of parentheses we must add
     */
    int minAddToMakeValid(string &S) {
        int n = S.size(), open = 0, result = 0;
        for(char c: S){
            if( c == '(') open++;
            else{
                if( open > 0 ) open--;
                else result++;
            }
        }
        return result + open;
    }
};
