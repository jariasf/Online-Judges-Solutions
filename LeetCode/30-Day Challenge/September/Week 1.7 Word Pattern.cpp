/*******************************************
 ***Problema: Word Pattern
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> hash;
        unordered_map<string, int> hash_inv;
        stringstream ss(str);
        int i = 0;
        for(; i < pattern.size() && ss>>str; ++i ){
            if( hash[pattern[i]] != hash_inv[str]) return false;
            hash[pattern[i]] = hash_inv[str]= i + 1;
        }
        return (i == pattern.size() && !(ss>>str));
    }
};
