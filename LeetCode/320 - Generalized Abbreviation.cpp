/*******************************************
 ***Problema: Generalized Abbreviation
 ***ID: 320
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        int n = word.size();
        vector<string> res;
        for( int i = 0 ; i < (1<<n) ; ++i ){
            string cur = "";
            int cnt = 0;
            for( int j = 0 ; j < n ; ++j ){
                if( i & (1<<j) ){
                    if( cnt > 0 ) cur += to_string(cnt);
                    cnt = 0;
                    cur += word[j];
                }else{
                    cnt++;
                }
            }
            if( cnt > 0 ) cur += to_string(cnt);
            res.push_back(cur);
        }
        return res;
    }
};
