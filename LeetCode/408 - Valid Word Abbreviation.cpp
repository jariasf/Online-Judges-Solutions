/*******************************************
 ***Problema: Valid Word Abbreviation
 ***ID: 408
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        int i = 0, j = 0;
        while(i < abbr.size() && j < word.size() ){
            int val = 0;
            if( abbr[i] == '0') return false;
            while(i < abbr.size() && isdigit(abbr[i]) ){
                val = val * 10 + (abbr[i] - '0');
                i++;
            }
            if( val > 0 ){
                j += val;
            }else if( abbr[i++] != word[j++] )
                return false;
        }
        return i == abbr.size() && j == word.size();
    }
};
