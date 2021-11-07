/*******************************************
 ***Problema: Vowels of All Substrings
 ***ID: 2063
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    bool isVowel(char c){
        string s = "aeiou";
        return s.find(c) != -1;
    }    
    
    LL countVowels(string s) {
        LL res = 0;
        int n = s.size();
        for( int i = 0 ; i < n ; ++i ){
            if( isVowel(s[i])){
                res += (LL)(i + 1) * (LL)(n - i);
            }
        }
        return res;
    }
};
