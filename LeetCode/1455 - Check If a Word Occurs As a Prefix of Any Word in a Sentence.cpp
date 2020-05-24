/*******************************************
 ***Problema: Check If a Word Occurs As a Prefix of Any Word in a Sentence
 ***ID: 1455
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        stringstream ss(s);
        int idx = 0;
        while(ss>>s){
            idx++;
            if( w.size() > s.size() ) continue;
            for( int i = 0, j = 0 ; i < s.size(); ++i ){
                if( s[i] == w[j] ){
                    j++;
                    if( j == w.size() ){
                        return idx;
                    }
                }else{
                    break;
                }
            }
        }
        return -1;
    }
};
