/*******************************************
 ***Problema: Count Vowel Substrings of a String
 ***ID: 2062
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int isVowel(char c){
        string s = "aeiou";
        return s.find(c);
    }
    
    int countVowelSubstrings(string s) {
        int n = s.size(), res = 0;
        for( int i = 0 ; i < n ; ++i ){
            int mask = 0;
            for( int j = i ; j < n ; ++j ){
                int pos = isVowel(s[j]);
                if( pos != -1 ){
                    mask |= 1<<pos;
                }else break;
                if( mask == 31 ) res++;
            }
        }
        return res;
    }
};
