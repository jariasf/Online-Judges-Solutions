/*******************************************
 ***Problema: Sentence Similarity 
 ***ID: 856
 ***Juez: LintCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param words1: a list of string
     * @param words2: a list of string
     * @param pairs: a list of string pairs
     * @return: return a boolean, denote whether two sentences are similar or not
     */
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        
        if( words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string> > hash;
        
        for( int i = 0 ; i < pairs.size(); ++i ){
            hash[ pairs[i][0] ].insert(pairs[i][1]);
            hash[ pairs[i][1] ].insert(pairs[i][0]);
        }
        
        int n = words2.size();
        for( int i = 0 ; i < n ; ++i ){
            string word1 = words1[i], word2 = words2[i];
            if( word1 != word2 && hash[word1].find(word2) == hash[word1].end() ){
                return false;
            }
        }
        return true;
        
    }
};
