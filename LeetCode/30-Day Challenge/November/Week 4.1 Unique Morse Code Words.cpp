/*******************************************
 ***Problema: Unique Morse Code Words
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string s[30] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> hash;
        
        for( int i = 0 ; i < words.size() ; ++i ){
            string res = "";
            for( int j = 0 ; j < words[i].size() ; ++j ){
                res += s[ words[i][j] - 'a'];
            }
            hash.insert(res);
        }
        return hash.size();
    }
};
