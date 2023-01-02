/*******************************************
 ***Problema: Word Pattern
 ***ID: Week 1.1
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mapping;
        unordered_map<string, char> mapping2;
        stringstream ss(s);
        for(char c:pattern){
            if(ss>>s){
                if( mapping.count(c) ){
                    if(mapping[c] != s) return false;
                }else{
                    if(mapping2.count(s)) return false;
                    mapping2[s] = c;
                    mapping[c] = s;
                }
            }else
                return false;
        }
        return !(ss>>s);
    }
};
