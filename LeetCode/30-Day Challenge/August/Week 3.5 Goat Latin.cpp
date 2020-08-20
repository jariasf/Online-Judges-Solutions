/*******************************************
 ***Problema: Goat Latin
 ***ID: Week3.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    bool isVowel(char c){
        string s = "aeiouAEIOU";
        return s.find(c) != string::npos;
    }
    
    string toGoatLatin(string s) {
        stringstream ss(s);
        string res = "", a = "a";
        while(ss>>s){
            if(!isVowel(s[0])){
                res += s.substr(1) + string(1, s[0]);
            }else
                res += s;
            res +="ma" + a + " ";
            a += "a";
        }
        return res.substr(0, res.size() - 1);
    }
};
