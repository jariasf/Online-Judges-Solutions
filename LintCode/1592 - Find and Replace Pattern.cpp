/*******************************************
 ***Problema: Find and Replace Pattern
 ***ID: 1592
 ***Juez: LintCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param words: word list
     * @param pattern: pattern string
     * @return: list of matching words
     */
    vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
        int n = words.size();
        vector<int> wtp, ptw;
        vector<string> output;
        for( int i = 0 ; i < n ; ++i ){
            string current = words[i];
            wtp = vector<int>(260, -1);
            ptw = vector<int>(260, -1);
            int j = 0;
            for( ; j < current.size() ; ++j ){
                if( ptw[pattern[j] ] == -1 && wtp[current[j]] == -1 ){
                    ptw[pattern[j] ] = current[j];
                    wtp[current[j] ] = pattern[j];
                }else if( ptw[pattern[j]] != current[j] ) 
                    break;
            }
            if( j == current.size() ) output.push_back(current);
            
        }
        
        return output;
    }
};
