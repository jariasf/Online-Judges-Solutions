/*******************************************
 ***Problema: Sentence Screen Fitting
 ***ID: 889
 ***Juez: LintCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param sentence: a list of string
     * @param rows: an integer
     * @param cols: an integer
     * @return: return an integer, denote times the given sentence can be fitted on the screen
     */
    int wordsTyping(vector<string> &sentence, int rows, int cols) {
        vector<bool> chars;
        for( int i = 0 ; i < sentence.size(); ++i ){
            for( int j = 0 ; j < sentence[i].size() ; ++j )
                chars.push_back(true);
            chars.push_back(false); //append empty space
        }
        
        int start = 0, n = chars.size();
        while(rows--){
            start += cols;
            if( !chars[ start % n ]) start++;
            else{
                while( chars[ (start - 1 + n) % n ]){
                    start--;
                }
            }
        }
        return start / n;
    }
};
