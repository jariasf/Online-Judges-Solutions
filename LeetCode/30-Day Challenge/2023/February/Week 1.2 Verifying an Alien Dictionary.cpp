/*******************************************
 ***Problema: Verifying an Alien Dictionary
 ***ID: Week 1.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isSmaller(string &s1, string &s2, vector<int>& indices){
        int n = min(s1.size(), s2.size());
        for(int i = 0; i < n ; ++i){
            if( s1[i] != s2[i])
                return indices[s1[i]-'a'] < indices[s2[i]-'a'];
        }
        return s1.size() <= s2.size();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> indices(26);
        for(int i = 0 ; i < 26 ; ++i) indices[order[i]-'a'] = i;
        
        for(int i = 1 ; i < words.size(); ++i){
            if( !isSmaller(words[i - 1], words[i], indices)) 
                return false;
        }
        return true;
    }
};
