/*******************************************
 ***Problema: Detect Capital
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool detectCapitalUse(string word){ 
        bool upper = true, lower = true;
        for(char c:word ){
            upper &= isupper(c) > 0;
            lower &= islower(c) > 0;
        }
        if( upper || lower ) return true;
        if( isupper(word[0]) ){
            for( int i = 1 ; i < word.size() ; ++i ){
                if( isupper(word[i])) return false;
            }
            return true;
        }
        return false;
    }
};
